#ifndef SERVICO_HIDRAULICA_H
#define SERVICO_HIDRAULICA_H

#include "servico.h"

// HERANÇA: ServicoHidraulica herda da classe base Servico.
class ServicoHidraulica : public Servico {
private:
    bool precisaMaterialEspecial;

public:
    ServicoHidraulica(std::string desc, double p, bool material);
    
    // POLIMORFISMO: Sobrescreve (override) o método virtual da classe mãe.
    void exibirDetalhes() const override;
};

#endif