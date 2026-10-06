#ifndef SERVICO_LIMPEZA_H
#define SERVICO_LIMPEZA_H

#include "servico.h"

class ServicoLimpeza : public Servico {
private:
    double duracaoHoras;

public:
    ServicoLimpeza(std::string desc, double p, double duracao);
    void exibirDetalhes() const override;
};

#endif