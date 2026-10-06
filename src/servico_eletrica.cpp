#include "../include/servico_eletrica.h"
#include <iostream>

// HERANÇA: Repassa descrição e preço para a classe base.
ServicoEletrica::ServicoEletrica(std::string desc, double p, int v)
    : Servico(desc, p), voltagem(v) {}

// POLIMORFISMO: Implementação da versão específica para exibirDetalhes.
void ServicoEletrica::exibirDetalhes() const {
    std::cout << "[Eletrica] " << descricao << " | Preco: R$ " << preco 
              << " | Voltagem: " << voltagem << "V" << std::endl;
}