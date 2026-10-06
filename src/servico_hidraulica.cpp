#include "../include/servico_hidraulica.h"
#include <iostream>

// HERANÇA: Repassa descrição e preço para a classe base.
ServicoHidraulica::ServicoHidraulica(std::string desc, double p, bool material)
    : Servico(desc, p), precisaMaterialEspecial(material) {}

// POLIMORFISMO: Implementação da versão específica para exibirDetalhes.
void ServicoHidraulica::exibirDetalhes() const {
    std::cout << "[Hidraulica] " << descricao << " | Preco: R$ " << preco 
              << " | Material Especial: " << (precisaMaterialEspecial ? "Sim" : "Nao") << std::endl;
}