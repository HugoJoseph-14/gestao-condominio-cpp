#include <iostream>
#include "../include/hospede.h"
using namespace std;

Hospede::Hospede() {
    numeroQuarto = 0;
    dataCheckin = "Não registrado";
}
Hospede::Hospede(string nomeInicial, string documentoInicial, int numeroQuartoInicial, std::string dataCheckinInicial) : Pessoa(nomeInicial, documentoInicial) {
    numeroQuarto = numeroQuartoInicial;
    dataCheckin = dataCheckinInicial;
}

int Hospede::getNumeroQuarto() {
    return numeroQuarto;
}
string Hospede::getDataCheckin() {
    return dataCheckin;
}
void Hospede::setNumeroQuarto(int novoNumeroQuarto) {
    numeroQuarto = novoNumeroQuarto;
}
void Hospede::setDataCheckin(string novoDataCheckin) {
    dataCheckin = novoDataCheckin;
}
Hospede::~Hospede() {    
}