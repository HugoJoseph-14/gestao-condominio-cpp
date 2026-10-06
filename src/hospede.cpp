#include <iostream>
#include "../include/hospede.h"
using namespace std;

Hospede::Hospede() {
    numeroQuarto = 0;
    dataCheckin = "Não registrado";
}

// HERANÇA: O construtor repassa os parâmetros 'nome' e 'documento' para inicializar a classe base Pessoa.
Hospede::Hospede(string nomeInicial, string documentoInicial, int numeroQuartoInicial, std::string dataCheckinInicial) : Pessoa(nomeInicial, documentoInicial) {
    numeroQuarto = numeroQuartoInicial;
    dataCheckin = dataCheckinInicial;
}

// ENCAPSULAMENTO: Acesso controlado ao estado interno do objeto.
int Hospede::getNumeroQuarto() { return numeroQuarto; }
string Hospede::getDataCheckin() { return dataCheckin; }
void Hospede::setNumeroQuarto(int novoNumeroQuarto) { numeroQuarto = novoNumeroQuarto; }
void Hospede::setDataCheckin(string novoDataCheckin) { dataCheckin = novoDataCheckin; }

Hospede::~Hospede() {}

// POLIMORFISMO / SOBRESCRITA: Define como a classe filha deve exibir os seus próprios dados.
void Hospede::exibirDetalhes() const {
    std::cout << "Nome: " << getNome() << std::endl;
    std::cout << "Documento: " << getDocumento() << std::endl;
    std::cout << "Quarto: " << numeroQuarto << std::endl;
    std::cout << "Check-in: " << dataCheckin << std::endl;
}