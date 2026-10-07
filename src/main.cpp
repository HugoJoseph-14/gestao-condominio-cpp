#include <iostream>
#include <vector>
#include <memory>
#include <limits>
#include "../include/pessoa.h"
#include "../include/hospede.h"
#include "../include/funcionario.h"
#include "../include/servico.h"
#include "../include/servico_eletrica.h"
#include "../include/servico_hidraulica.h"
#include "../include/servico_limpeza.h"
#include "../include/agendamento.h"
#include "../include/registro_acesso.h"
#include "../include/portaria.h"

using namespace std;

// ============================================================
// ARMAZENAMENTO EM MEMORIA DO SISTEMA
// ============================================================
// Usamos vector<unique_ptr<T>> em vez de vector<T> comum.
// Motivo: Agendamento guarda PONTEIROS (const Hospede*, etc.)
// para esses objetos. Se usassemos vector<T> comum, adicionar
// um novo item poderia fazer o vetor "realocar" na memoria,
// movendo todos os objetos e invalidando qualquer ponteiro
// que ja tivesse sido guardado em um Agendamento.
// Com unique_ptr, apenas o ponteiro interno é movido quando o
// vetor realoca — o objeto apontado continua no mesmo lugar.
vector<unique_ptr<Hospede>> hospedes;
vector<unique_ptr<Funcionario>> funcionarios;
vector<unique_ptr<Servico>> servicos;
vector<Agendamento> agendamentos;
Portaria portaria;

// ============================================================
// FUNCOES AUXILIARES DE ENTRADA
// ============================================================

// Limpa o buffer do cin apos uma leitura invalida ou apos usar
// cin >> antes de um getline (senao o getline pode "pular" por
// pegar um caractere de nova linha que sobrou no buffer).
void limparBufferEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Le um numero inteiro do usuario, repetindo a pergunta ate
// receber algo valido (protege contra o usuario digitar texto
// onde era esperado um numero).
int lerInteiro(string mensagem) {
    int valor;
    cout << mensagem;
    while (!(cin >> valor)) {
        cout << "Entrada invalida. Tente novamente: ";
        limparBufferEntrada();
    }
    limparBufferEntrada();
    return valor;
}

// Mesma logica do lerInteiro, mas para numeros com casas decimais
// (usado em preco, duracao, etc.).
double lerDouble(string mensagem) {
    double valor;
    cout << mensagem;
    while (!(cin >> valor)) {
        cout << "Entrada invalida. Tente novamente: ";
        limparBufferEntrada();
    }
    limparBufferEntrada();
    return valor;
}

// Le uma linha inteira de texto (nomes, descricoes, datas).
// Usa getline em vez de cin >> porque cin >> para no primeiro
// espaco, o que quebraria nomes compostos tipo "Maria Silva".
string lerLinha(string mensagem) {
    string valor;
    cout << mensagem;
    getline(cin, valor);
    return valor;
}

// ============================================================
// CADASTROS
// ============================================================

void cadastrarHospede() {
    cout << "\n--- Cadastro de Hospede ---\n";
    string nome = lerLinha("Nome: ");
    string documento = lerLinha("Documento: ");
    int quarto = lerInteiro("Numero do quarto: ");
    string checkin = lerLinha("Data de checkin: ");

    // make_unique cria o objeto e ja devolve embrulhado num unique_ptr,
    // que e entao movido para dentro do vetor.
    hospedes.push_back(make_unique<Hospede>(nome, documento, quarto, checkin));
    cout << "Hospede cadastrado com sucesso!\n";
}

void cadastrarFuncionario() {
    cout << "\n--- Cadastro de Funcionario ---\n";
    string nome = lerLinha("Nome: ");
    string documento = lerLinha("Documento: ");
    string especialidade = lerLinha("Especialidade (eletricista/encanador/faxineiro): ");

    funcionarios.push_back(make_unique<Funcionario>(nome, documento, especialidade));
    cout << "Funcionario cadastrado com sucesso!\n";
}

void cadastrarServico() {
    cout << "\n--- Cadastro de Servico ---\n";
    cout << "1 - Eletrica\n2 - Hidraulica\n3 - Limpeza\n";
    int tipo = lerInteiro("Escolha o tipo: ");

    string descricao = lerLinha("Descricao: ");
    double preco = lerDouble("Preco: ");

    // Dependendo do tipo escolhido, criamos a subclasse correta de
    // Servico. Cada uma tem um atributo extra proprio (voltagem,
    // material especial, duracao), por isso pedimos esse dado so
    // depois de saber qual tipo foi escolhido.
    if (tipo == 1) {
        int voltagem = lerInteiro("Voltagem: ");
        servicos.push_back(make_unique<ServicoEletrica>(descricao, preco, voltagem));
    } else if (tipo == 2) {
        int materialOpcao = lerInteiro("Precisa de material especial? (1-Sim / 0-Nao): ");
        servicos.push_back(make_unique<ServicoHidraulica>(descricao, preco, materialOpcao == 1));
    } else if (tipo == 3) {
        double duracao = lerDouble("Duracao estimada (horas): ");
        servicos.push_back(make_unique<ServicoLimpeza>(descricao, preco, duracao));
    } else {
        cout << "Tipo invalido.\n";
        return;
    }
    cout << "Servico cadastrado com sucesso!\n";
}

// ============================================================
// LISTAGENS
// ============================================================
// Cada listagem imprime um indice "[i]" na frente de cada item.
// Esses indices sao usados depois, em criarAgendamento() e nas
// funcoes da portaria, para o usuario escolher "qual hospede",
// "qual funcionario", etc., sem precisar digitar o nome inteiro.

void listarHospedes() {
    cout << "\n--- Hospedes cadastrados ---\n";
    if (hospedes.empty()) {
        cout << "Nenhum hospede cadastrado.\n";
        return;
    }
    for (size_t i = 0; i < hospedes.size(); i++) {
        cout << "[" << i << "] ";
        // exibirDetalhes() e polimorfico: cada classe sabe se
        // exibir do seu proprio jeito.
        hospedes[i]->exibirDetalhes();
    }
}

void listarFuncionarios() {
    cout << "\n--- Funcionarios cadastrados ---\n";
    if (funcionarios.empty()) {
        cout << "Nenhum funcionario cadastrado.\n";
        return;
    }
    for (size_t i = 0; i < funcionarios.size(); i++) {
        cout << "[" << i << "] ";
        funcionarios[i]->exibirDetalhes();
    }
}

void listarServicos() {
    cout << "\n--- Servicos cadastrados ---\n";
    if (servicos.empty()) {
        cout << "Nenhum servico cadastrado.\n";
        return;
    }
    for (size_t i = 0; i < servicos.size(); i++) {
        cout << "[" << i << "] ";
        servicos[i]->exibirDetalhes();
    }
}

void listarAgendamentos() {
    cout << "\n--- Agendamentos ---\n";
    if (agendamentos.empty()) {
        cout << "Nenhum agendamento cadastrado.\n";
        return;
    }
    for (size_t i = 0; i < agendamentos.size(); i++) {
        cout << "[" << i << "]\n";
        agendamentos[i].exibirAgendamento();
    }
}

// ============================================================
// AGENDAMENTO
// ============================================================

void criarAgendamento() {
    // Um agendamento so faz sentido se ja existir pelo menos um
    // hospede, um funcionario e um servico cadastrados — senao
    // nao ha o que escolher.
    if (hospedes.empty() || funcionarios.empty() || servicos.empty()) {
        cout << "\nE preciso ter pelo menos um hospede, um funcionario e um servico cadastrados.\n";
        return;
    }

    listarHospedes();
    int idxHospede = lerInteiro("Escolha o hospede pelo indice: ");
    if (idxHospede < 0 || idxHospede >= (int)hospedes.size()) {
        cout << "Indice invalido.\n";
        return;
    }

    listarFuncionarios();
    int idxFuncionario = lerInteiro("Escolha o funcionario pelo indice: ");
    if (idxFuncionario < 0 || idxFuncionario >= (int)funcionarios.size()) {
        cout << "Indice invalido.\n";
        return;
    }

    listarServicos();
    int idxServico = lerInteiro("Escolha o servico pelo indice: ");
    if (idxServico < 0 || idxServico >= (int)servicos.size()) {
        cout << "Indice invalido.\n";
        return;
    }

    string dataHora = lerLinha("Data/Hora do agendamento: ");

    // .get() devolve o ponteiro "cru" (Hospede*, Funcionario*, Servico*)
    // de dentro do unique_ptr, sem transferir posse do objeto.
    // E exatamente o tipo que o construtor de Agendamento espera.
    agendamentos.push_back(Agendamento(
        hospedes[idxHospede].get(),
        funcionarios[idxFuncionario].get(),
        servicos[idxServico].get(),
        dataHora
    ));

    cout << "Agendamento criado com sucesso!\n";
}

// ============================================================
// PORTARIA
// ============================================================

void registrarEntradaPortaria() {
    if (hospedes.empty() && funcionarios.empty()) {
        cout << "\nE preciso ter pelo menos uma pessoa cadastrada (hospede ou funcionario).\n";
        return;
    }

    cout << "1 - Hospede\n2 - Funcionario\n";
    int tipoPessoa = lerInteiro("Quem esta entrando? ");

    // Pessoa* generico: tanto Hospede* quanto Funcionario* podem
    // ser guardados aqui, porque as duas classes herdam de Pessoa.
    // E exatamente o tipo que RegistroEntrada espera no construtor.
    Pessoa* pessoaSelecionada = nullptr;

    if (tipoPessoa == 1) {
        listarHospedes();
        int idx = lerInteiro("Escolha o hospede pelo indice: ");
        if (idx < 0 || idx >= (int)hospedes.size()) {
            cout << "Indice invalido.\n";
            return;
        }
        pessoaSelecionada = hospedes[idx].get();
    } else if (tipoPessoa == 2) {
        listarFuncionarios();
        int idx = lerInteiro("Escolha o funcionario pelo indice: ");
        if (idx < 0 || idx >= (int)funcionarios.size()) {
            cout << "Indice invalido.\n";
            return;
        }
        pessoaSelecionada = funcionarios[idx].get();
    } else {
        cout << "Opcao invalida.\n";
        return;
    }

    string dataHora = lerLinha("Data/Hora da entrada: ");
    string autorizacaoPor = lerLinha("Autorizado por: ");

    // registrarAcesso espera um unique_ptr<RegistroAcesso>. Como
    // RegistroEntrada herda de RegistroAcesso, um unique_ptr<RegistroEntrada>
    // e aceito automaticamente no lugar (conversao de ponteiro de
    // classe filha para classe base).
    portaria.registrarAcesso(make_unique<RegistroEntrada>(pessoaSelecionada, dataHora, autorizacaoPor));
    cout << "Entrada registrada com sucesso!\n";
}

void registrarSaidaPortaria() {
    if (hospedes.empty() && funcionarios.empty()) {
        cout << "\nE preciso ter pelo menos uma pessoa cadastrada (hospede ou funcionario).\n";
        return;
    }

    cout << "1 - Hospede\n2 - Funcionario\n";
    int tipoPessoa = lerInteiro("Quem esta saindo? ");

    Pessoa* pessoaSelecionada = nullptr;

    if (tipoPessoa == 1) {
        listarHospedes();
        int idx = lerInteiro("Escolha o hospede pelo indice: ");
        if (idx < 0 || idx >= (int)hospedes.size()) {
            cout << "Indice invalido.\n";
            return;
        }
        pessoaSelecionada = hospedes[idx].get();
    } else if (tipoPessoa == 2) {
        listarFuncionarios();
        int idx = lerInteiro("Escolha o funcionario pelo indice: ");
        if (idx < 0 || idx >= (int)funcionarios.size()) {
            cout << "Indice invalido.\n";
            return;
        }
        pessoaSelecionada = funcionarios[idx].get();
    } else {
        cout << "Opcao invalida.\n";
        return;
    }

    string dataHora = lerLinha("Data/Hora da saida: ");
    string motivo = lerLinha("Motivo da saida: ");

    portaria.registrarAcesso(make_unique<RegistroSaida>(pessoaSelecionada, dataHora, motivo));
    cout << "Saida registrada com sucesso!\n";
}

// ============================================================
// MENUS
// ============================================================
// Cada menu e um loop do-while: mostra as opcoes, le a escolha,
// executa a funcao correspondente, e repete ate o usuario
// escolher "0 - Voltar".

void menuCadastros() {
    int opcao;
    do {
        cout << "\n===== CADASTROS =====\n";
        cout << "1 - Cadastrar Hospede\n";
        cout << "2 - Cadastrar Funcionario\n";
        cout << "3 - Cadastrar Servico\n";
        cout << "4 - Listar Hospedes\n";
        cout << "5 - Listar Funcionarios\n";
        cout << "6 - Listar Servicos\n";
        cout << "0 - Voltar\n";
        opcao = lerInteiro("Escolha uma opcao: ");

        switch (opcao) {
            case 1: cadastrarHospede(); break;
            case 2: cadastrarFuncionario(); break;
            case 3: cadastrarServico(); break;
            case 4: listarHospedes(); break;
            case 5: listarFuncionarios(); break;
            case 6: listarServicos(); break;
            case 0: break;
            default: cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);
}

void menuAgendamentos() {
    int opcao;
    do {
        cout << "\n===== AGENDAMENTOS =====\n";
        cout << "1 - Criar Agendamento\n";
        cout << "2 - Listar Agendamentos\n";
        cout << "0 - Voltar\n";
        opcao = lerInteiro("Escolha uma opcao: ");

        switch (opcao) {
            case 1: criarAgendamento(); break;
            case 2: listarAgendamentos(); break;
            case 0: break;
            default: cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);
}

void menuPortaria() {
    int opcao;
    do {
        cout << "\n===== PORTARIA =====\n";
        cout << "1 - Registrar Entrada\n";
        cout << "2 - Registrar Saida\n";
        cout << "3 - Listar Historico\n";
        cout << "0 - Voltar\n";
        opcao = lerInteiro("Escolha uma opcao: ");

        switch (opcao) {
            case 1: registrarEntradaPortaria(); break;
            case 2: registrarSaidaPortaria(); break;
            case 3: portaria.listarHistorico(); break;
            case 0: break;
            default: cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);
}

// ============================================================
// MENU PRINCIPAL
// ============================================================

int main() {
    int opcao;
    do {
        cout << "\n========================================\n";
        cout << "  SISTEMA DE GERENCIAMENTO PREDIAL\n";
        cout << "========================================\n";
        cout << "1 - Cadastros (Hospedes, Funcionarios, Servicos)\n";
        cout << "2 - Agendamentos\n";
        cout << "3 - Portaria\n";
        cout << "0 - Sair\n";
        opcao = lerInteiro("Escolha uma opcao: ");

        switch (opcao) {
            case 1: menuCadastros(); break;
            case 2: menuAgendamentos(); break;
            case 3: menuPortaria(); break;
            case 0: cout << "Encerrando o sistema...\n"; break;
            default: cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);

    return 0;
}