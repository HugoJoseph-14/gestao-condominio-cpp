#include <iostream>
#include <memory>

// Headers de Pessoas
#include "../include/pessoa.h"
#include "../include/hospede.h"
#include "../include/funcionario.h"

// Headers de Servicos
#include "../include/servico.h"
#include "../include/servico_eletrica.h"
#include "../include/servico_hidraulica.h"
#include "../include/servico_limpeza.h"

// Headers de Agendamento e Portaria
#include "../include/agendamento.h"
#include "../include/registro_acesso.h"
#include "../include/portaria.h"

int main() {
    std::cout << "=========================================================\n";
    std::cout << "     SIMULACAO DE GESTAO INTEGRADA DE CONDOMINIO         \n";
    std::cout << "=========================================================\n\n";

    // 1. CADASTRO DE PESSOAS
    std::cout << "[1] Cadastrando Hospedes e Funcionarios..." << std::endl;
    Hospede hospede1("Carlos Silva", "123.456.789-00", 102, "04/10/2026");
    Funcionario func1("Ana Souza", "987.654.321-11", "Eletricista");
    Funcionario func2("Roberto Lima", "555.666.777-88", "Servicos Gerais");

    // 2. CADASTRO DE SERVICOS DO CONDOMINIO (Passando os argumentos esperados)
    std::cout << "\n[2] Preparando Tipos de Servicos..." << std::endl;
    ServicoEletrica servicoEletrico("Reparo no quadro eletrico", 150.0, 220); // desc, preco, voltagem
    ServicoLimpeza servicoLimpeza("Limpeza completa pós-checkout", 120.0, 2.5); // desc, preco, duracao em horas

    // 3. CONTROLE DE PORTARIA (ENTRADAS E SAIDAS)
    std::cout << "\n[3] Registrando Movimentacoes na Portaria..." << std::endl;
    Portaria portaria;
    portaria.registrarAcesso(std::make_unique<RegistroEntrada>(&hospede1, "06/10/2026 08:00", "Recepcao Central"));
    portaria.registrarAcesso(std::make_unique<RegistroEntrada>(&func1, "06/10/2026 08:30", "Entrada Servico"));
    
    // Exibe histórico da portaria
    portaria.listarHistorico();

    // 4. AGENDAMENTO DE SERVICOS (INTEGRACAO DAS CLASSES)
    std::cout << "\n[4] Agendando Servicos para os Moradores..." << std::endl;
    Agendamento agendamento1(&hospede1, &func1, &servicoEletrico, "06/10/2026 10:00");
    
    // Exibe o agendamento no console
    agendamento1.exibirAgendamento();

    // Atualiza status e exibe novamente
    std::cout << "-> Concluindo o serviço agendado...\n";
    agendamento1.setStatus("Concluido");
    agendamento1.exibirAgendamento();

    std::cout << "=========================================================\n";
    std::cout << "             SIMULACAO FINALIZADA COM SUCESSO!           \n";
    std::cout << "=========================================================\n";

    return 0;
}