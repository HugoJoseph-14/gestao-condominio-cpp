#ifndef SERVICO_ELETRICA_H
#define SERVICO_ELETRICA_H

#include "servico.h"

class ServicoEletrica : public Servico {
private:
    int voltagem;

public:
    ServicoEletrica(std::string desc, double p, int v);
    void exibirDetalhes() const override;
};

#endif