#include "../include/servico.h"
#include <iostream>

Servico::Servico(std::string desc, double p) : descricao(desc), preco(p) {}

Servico::~Servico() {}

std::string Servico::getDescricao() const {
    return descricao;
}

double Servico::getPreco() const {
    return preco;
}

void Servico::exibirDetalhes() const {
    std::cout << "Servico: " << descricao << " | Preco: R$ " << preco << std::endl;
}