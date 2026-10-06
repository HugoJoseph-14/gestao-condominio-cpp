#ifndef SERVICO_LIMPEZA_H
#define SERVICO_LIMPEZA_H

#include "servico.h"

// HERANÇA: ServicoLimpeza herda da classe base Servico.
class ServicoLimpeza : public Servico {
private:
    double duracaoHoras;

public:
    ServicoLimpeza(std::string desc, double p, double duracao);
    
    // POLIMORFISMO: Sobrescreve (override) o método virtual da classe mãe.
    void exibirDetalhes() const override;
};

#endif