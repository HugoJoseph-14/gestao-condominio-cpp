#pragma once
#include <iostream>
#include <string>

class Pessoa {
    private:
        std::string nome;
        std::string documento;

    public:
        std::string getNome();
        std::string getDocumento();
        void setNome(std::string nomeNovo);
        void setDocumento(std::string documentoNovo);

        Pessoa();
        Pessoa(std::string nomeInicial, std::string documentoInicial);

        ~Pessoa();
};
