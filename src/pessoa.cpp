#include <iostream>
#include "../include/pessoa.h"
using namespace std;

Pessoa::Pessoa() {
    nome = "não registrado";
    documento = "não registrado";
}
Pessoa::Pessoa(string nomeInicial, string documentoInicial) {
    nome = nomeInicial;
    documento = documentoInicial;
}

string Pessoa::getNome() const {
    return nome;
}
string Pessoa::getDocumento() const {
    return documento;
}
void Pessoa::setNome(string nomeNovo) {
    nome = nomeNovo;
}
void Pessoa::setDocumento(string documentoNovo) {
    documento = documentoNovo;
}
Pessoa::~Pessoa() {    
}