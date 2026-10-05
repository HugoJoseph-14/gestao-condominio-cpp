#pragma once
#include "registro_acesso.h"
#include <vector>
#include <memory>

// CONCEITO DE CLASSE: A Portaria atua como gerenciadora (composição) dos registros.
class Portaria {
private:
    // POLIMORFISMO + BOAS PRÁTICAS: Vetor de ponteiros da classe base (RegistroAcesso) 
    // que consegue guardar dinamicamente objetos de qualquer classe filha (Entrada ou Saída).
    std::vector<std::unique_ptr<RegistroAcesso>> historicoAcessos;

public:
    Portaria() = default;
    ~Portaria() = default; 

    void registrarAcesso(std::unique_ptr<RegistroAcesso> novoRegistro);
    void listarHistorico() const;
};