#include "../include/servico_limpeza.h"
#include <iostream>

// HERANÇA: Repassa descrição e preço para a classe base.
ServicoLimpeza::ServicoLimpeza(std::string desc, double p, double duracao)
    : Servico(desc, p), duracaoHoras(duracao) {}

// POLIMORFISMO: Implementação da versão específica para exibirDetalhes.
void ServicoLimpeza::exibirDetalhes() const {
    std::cout << "[Limpeza] " << descricao << " | Preco: R$ " << preco 
              << " | Duracao Estimada: " << duracaoHoras << "h" << std::endl;
}