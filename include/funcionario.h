#pragma once
#include <iostream>
#include "../include/pessoa.h"
#include <string>

class Funcionario : public Pessoa {
    private:
        std::string especialidade;
    public:
        std::string getEspecialidade();
        void setEspecialidade(std::string novoEspecialidade);
        void exibirDetalhes() const;

        Funcionario();
        Funcionario(std::string nomeInicial, std::string documentoInicial, std::string especialidadeInicial);

        ~Funcionario();
};
