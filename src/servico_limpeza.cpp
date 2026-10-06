#include "../include/servico_limpeza.h"
#include <iostream>

ServicoLimpeza::ServicoLimpeza(std::string desc, double p, double duracao)
    : Servico(desc, p), duracaoHoras(duracao) {}

void ServicoLimpeza::exibirDetalhes() const {
    std::cout << "[Limpeza] " << descricao << " | Preco: R$ " << preco 
              << " | Duracao Estimada: " << duracaoHoras << "h" << std::endl;
}