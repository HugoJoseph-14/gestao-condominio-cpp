# 🏢 Sistema de Gestão de Condomínio em C++

Sistema de gestão integrada de condomínio desenvolvido em **C++17**, contemplando controle de acesso de portaria, cadastro de pessoas (hóspedes e funcionários), agendamento de serviços e especializações de manutenção (elétrica, hidráulica e limpeza).

---

## 📌 Funcionalidades

* **Controle de Portaria & Acesso**: Registro de entradas e saídas de pessoas com histórico e gerenciamento polimórfico.
* **Gestão de Pessoas**: Hierarquia baseada na classe `Pessoa`, especializada em `Hospede` e `Funcionario`.
* **Agendamento de Serviços**: Vinculação entre hóspedes solicitantes, funcionários encarregados, serviços específicos e status de atendimento.
* **Serviços Especializados**: Serviços divididos por categorias (`ServicoEletrica`, `ServicoHidraulica`, `ServicoLimpeza`), aplicando herança e encapsulamento.

---

## 🏗️ Conceitos de POO Aplicados

* **Herança**: `Hospede` e `Funcionario` herdam de `Pessoa`; serviços específicos derivam de `Servico`.
* **Polimorfismo**: Uso de ponteiros inteligentes (`std::unique_ptr`) para manipular instâncias de `RegistroEntrada` e `RegistroSaida` através do tipo genérico `RegistroAcesso`.
* **Const Correctness**: Métodos de consulta (`getters` e exibições) devidamente sinalizados com `const` para garantir a integridade dos dados e compatibilidade com referências/ponteiros constantes.
* **Gestão de Memória**: Uso de smart pointers para prevenção de *memory leaks*.

---

## 📁 Estrutura do Projeto

```text
gestao-condominio-cpp/
├── include/                # Arquivos de cabeçalho (.h)
│   ├── agendamento.h
│   ├── funcionario.h
│   ├── hospede.h
│   ├── pessoa.h
│   ├── portaria.h
│   ├── registro_acesso.h
│   ├── servico.h
│   ├── servico_eletrica.h
│   ├── servico_hidraulica.h
│   └── servico_limpeza.h
├── src/                    # Arquivos de implementação (.cpp)
│   ├── agendamento.cpp
│   ├── funcionario.cpp
│   ├── hospede.cpp
│   ├── main.cpp
│   ├── pessoa.cpp
│   ├── portaria.cpp
│   ├── registro_acesso.cpp
│   ├── servico.cpp
│   ├── servico_eletrica.cpp
│   ├── servico_hidraulica.cpp
│   ├── servico_limpeza.cpp
│   └── output/             # Diretório do executável compilado
├── .gitignore
└── README.md

 ⚙️ Pré-requisitos
Compilador C++: g++ (MinGW / GCC) com suporte a C++14 ou superior.

Terminal: PowerShell / Prompt de Comando ou Terminal do VS Code.

🚀 Como Compilar e Executar (PowerShell)
1. Clonar o repositório
PowerShell
git clone [https://github.com/SEU_USUARIO/gestao-condominio-cpp.git](https://github.com/SEU_USUARIO/gestao-condominio-cpp.git)
cd gestao-condominio-cpp
2. Criar a pasta de saída do compilador
O g++ exige que o diretório de destino do executável exista antes de compilar:

PowerShell
New-Item -ItemType Directory -Path src\output -Force
3. Compilar o projeto
Execute o comando abaixo para compilar todos os fontes da pasta src/ e gerar o executável:

PowerShell
g++ -Wall -Wextra -g3 -I include src\*.cpp -o src\output\main.exe
4. Executar a simulação
PowerShell
.\src\output\main.exe
🧪 Exemplo de Saída Esperada
Ao rodar o programa, a simulação exibirá no terminal:

Registro de Entradas e Saídas na Portaria com listagem de histórico.

Detalhes completos dos Agendamentos vinculando Hóspede, Funcionário e Serviço.

Atualização dinâmica de status do agendamento (ex: de Pendente para Concluido).
