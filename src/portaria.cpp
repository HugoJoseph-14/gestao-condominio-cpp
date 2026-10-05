#include "../include/portaria.h"
#include <iostream>
#include <utility>

void Portaria::registrarAcesso(std::unique_ptr<RegistroAcesso> novoRegistro) {
    if (novoRegistro != nullptr) {
        historicoAcessos.push_back(std::move(novoRegistro));
        std::cout << "Acesso registrado com sucesso!" << std::endl;
    }
}

void Portaria::listarHistorico() const {
    std::cout << "\n=== HISTORICO DE ACESSOS DA PORTARIA ===" << std::endl;
    if (historicoAcessos.empty()) {
        std::cout << "Nenhum registro encontrado." << std::endl;
        return;
    }

    for (const auto& reg : historicoAcessos) {
        // POLIMORFISMO: Chama a versão correta do método (Entrada ou Saída).
        reg->exibirRegistro(); 
        std::cout << "----------------------------------------" << std::endl;
    }
}