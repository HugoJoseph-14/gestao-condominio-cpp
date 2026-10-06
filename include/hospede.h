#pragma once
#include <iostream>
#include "../include/pessoa.h"
#include <string>

// HERANÇA: A classe Hospede herda os atributos (nome, documento) e métodos da classe base Pessoa.
class Hospede : public Pessoa {
    private:
        int numeroQuarto;
        std::string dataCheckin;

    public:
        int getNumeroQuarto();
        std::string getDataCheckin();
        void setNumeroQuarto(int novoNumeroQuarto);
        void setDataCheckin(std::string novoDataCheckin);
        
        // POLIMORFISMO / ESPECIALIZAÇÃO: Método específico para exibir os detalhes do hóspede.
        void exibirDetalhes() const;

        Hospede();
        Hospede(std::string nomeInicial, std::string documentoInicial, int numeroQuartoInicial, std::string dataCheckinInicial);

        ~Hospede();
};