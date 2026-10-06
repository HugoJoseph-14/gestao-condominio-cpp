#ifndef SERVICO_ELETRICA_H
#define SERVICO_ELETRICA_H

#include "servico.h"

// HERANÇA: ServicoEletrica herda da classe base Servico.
class ServicoEletrica : public Servico {
// MODIFICADOR DE ACESSO (Private): Atributo específico para a especialização elétrica.
private:
    int voltagem;

public:
    ServicoEletrica(std::string desc, double p, int v);
    
    // POLIMORFISMO: Sobrescreve (override) o método virtual da classe mãe.
    void exibirDetalhes() const override;
};

#endif