#include <iostream>
#include "../include/funcionario.h"
using namespace std;

Funcionario::Funcionario() {
    especialidade = "Não registrado";
}

// HERANÇA: O construtor repassa os parâmetros 'nome' e 'documento' para inicializar a classe base Pessoa.
Funcionario::Funcionario(string nomeInicial, string documentoInicial, string especialidadeInicial) : Pessoa(nomeInicial, documentoInicial) {
    especialidade = especialidadeInicial;
}

string Funcionario::getEspecialidade() { return especialidade; }
void Funcionario::setEspecialidade(string novoEspecialidade) { especialidade = novoEspecialidade; }

Funcionario::~Funcionario() {}

// POLIMORFISMO / SOBRESCRITA: Define como a classe filha deve exibir os seus próprios dados.
void Funcionario::exibirDetalhes() const {
    std::cout << "Nome: " << getNome() << std::endl;
    std::cout << "Documento: " << getDocumento() << std::endl;
    std::cout << "Especialidade: " << especialidade << std::endl;
}