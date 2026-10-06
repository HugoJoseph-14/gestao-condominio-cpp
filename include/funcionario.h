#pragma once
#include <iostream>
#include "../include/pessoa.h"
#include <string>

// HERANÇA: A classe Funcionario herda da classe base Pessoa, reaproveitando a lógica de negócio principal.
class Funcionario : public Pessoa {
    private:
        std::string especialidade;
        
    public:
        std::string getEspecialidade();
        void setEspecialidade(std::string novoEspecialidade);
        
        // POLIMORFISMO / ESPECIALIZAÇÃO: Exibe os detalhes adaptados para a entidade funcionário.
        void exibirDetalhes() const;

        Funcionario();
        Funcionario(std::string nomeInicial, std::string documentoInicial, std::string especialidadeInicial);

        ~Funcionario();
};