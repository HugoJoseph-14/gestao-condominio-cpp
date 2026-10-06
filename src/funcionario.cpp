#include <iostream>
#include "../include/funcionario.h"
using namespace std;

Funcionario::Funcionario() {
    especialidade = "Não registrado";
}
Funcionario::Funcionario(string nomeInicial, string documentoInicial, string especialidadeInicial) : Pessoa(nomeInicial, documentoInicial) {
    especialidade = especialidadeInicial;
}
string Funcionario::getEspecialidade() {
    return especialidade;
}
void Funcionario::setEspecialidade(string novoEspecialidade) {
    especialidade = novoEspecialidade;
}
Funcionario::~Funcionario() {
}
void Funcionario::exibirDetalhes() const {
    std::cout << "Nome: " << getNome() << std::endl;
    std::cout << "Documento: " << getDocumento() << std::endl;
    std::cout << "Especialidade: " << especialidade << std::endl;
}