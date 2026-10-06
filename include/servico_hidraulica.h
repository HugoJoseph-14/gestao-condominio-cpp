#ifndef SERVICO_HIDRAULICA_H
#define SERVICO_HIDRAULICA_H

#include "servico.h"

class ServicoHidraulica : public Servico {
private:
    bool precisaMaterialEspecial;

public:
    ServicoHidraulica(std::string desc, double p, bool material);
    void exibirDetalhes() const override;
};

#endif