#include "../include/servico_hidraulica.h"
#include <iostream>

ServicoHidraulica::ServicoHidraulica(std::string desc, double p, bool material)
    : Servico(desc, p), precisaMaterialEspecial(material) {}

void ServicoHidraulica::exibirDetalhes() const {
    std::cout << "[Hidraulica] " << descricao << " | Preco: R$ " << preco 
              << " | Material Especial: " << (precisaMaterialEspecial ? "Sim" : "Nao") << std::endl;
}