#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H

#include "hospede.h"
#include "funcionario.h"
#include "servico.h"
#include <string>

class Agendamento {
private:
    const Hospede* hospede;
    const Funcionario* funcionario;
    const Servico* servico;
    std::string dataHora;
    std::string status;

public:
    Agendamento(const Hospede* h, const Funcionario* f, const Servico* s, std::string dh);
    
    void setStatus(std::string novoStatus);
    std::string getStatus() const;

    void exibirAgendamento() const;
};

#endif // AGENDAMENTO_H