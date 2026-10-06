#pragma once
#include <iostream>
#include <string>

// CONCEITO DE CLASSE: Classe base que abstrai os dados comuns a todas as entidades físicas do sistema.
class Pessoa {
// MODIFICADOR DE ACESSO (Private): Encapsulamento rigoroso para proteger o estado interno do objeto.
    private:
        std::string nome;
        std::string documento;

// MODIFICADOR DE ACESSO (Public): Interfaces públicas (getters e setters) para aceder aos dados de forma segura.
    public:
        std::string getNome() const;
        std::string getDocumento() const;
        void setNome(std::string nomeNovo);
        void setDocumento(std::string documentoNovo);

        Pessoa();
        Pessoa(std::string nomeInicial, std::string documentoInicial);

        ~Pessoa();
};