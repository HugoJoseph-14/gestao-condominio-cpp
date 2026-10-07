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

## Instruções de Uso

### Pré-requisitos

- Compilador C++ (g++, recomendado via [MSYS2](https://www.msys2.org/))
- Suporte a C++17 ou superior

### Compilando o projeto

Na raiz do projeto, rode:

```bash
g++ -std=c++17 -Wall -Wextra -I include src/*.cpp -o src/output/main.exe
```

> No Windows (PowerShell), crie a pasta de saída antes, caso ainda não exista:
> ```powershell
> mkdir src\output
> ```

### Executando

```bash
./src/output/main.exe
```

(No Windows: `.\src\output\main.exe`)

### Navegando pelo sistema

Ao iniciar, o programa exibe um menu principal com três áreas:

1. **Cadastros** — cadastrar e listar Hóspedes, Funcionários e Serviços (Elétrica, Hidráulica, Limpeza)
2. **Agendamentos** — criar e listar agendamentos de serviço, vinculando um hóspede, um funcionário e um serviço já cadastrados
3. **Portaria** — registrar entrada/saída de hóspedes ou funcionários, e consultar o histórico de acessos

Digite o número da opção desejada e pressione Enter. Para voltar a um menu anterior, digite `0`.

**Observação:** é necessário cadastrar pelo menos um Hóspede, um Funcionário e um Serviço antes de criar um Agendamento.
