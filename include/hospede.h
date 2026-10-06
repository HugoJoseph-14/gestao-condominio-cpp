#pragma once
#include <iostream>
#include "../include/pessoa.h"
#include <string>

class Hospede : public Pessoa {
    private:
        int numeroQuarto;
        std::string dataCheckin;

    public:
        int getNumeroQuarto();
        std::string getDataCheckin();
        void setNumeroQuarto(int novoNumeroQuarto);
        void setDataCheckin(std::string novoDataCheckin);
        void exibirDetalhes() const;

        Hospede();
        Hospede(std::string nomeInicial, std::string documentoInicial, int numeroQuartoInicial, std::string dataCheckinInicial);

        ~Hospede();
};