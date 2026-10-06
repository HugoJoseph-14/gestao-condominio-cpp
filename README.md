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
