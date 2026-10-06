#include "../include/servico_eletrica.h"
#include <iostream>

ServicoEletrica::ServicoEletrica(std::string desc, double p, int v)
    : Servico(desc, p), voltagem(v) {}

void ServicoEletrica::exibirDetalhes() const {
    std::cout << "[Eletrica] " << descricao << " | Preco: R$ " << preco 
              << " | Voltagem: " << voltagem << "V" << std::endl;
}