#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H

#include "hospede.h"
#include "funcionario.h"
#include "servico.h"
#include <string>

// CONCEITO DE CLASSE / ASSOCIAÇÃO: A classe Agendamento conecta múltiplas instâncias do sistema de forma estruturada.
class Agendamento {
// MODIFICADOR DE ACESSO (Private): Encapsulamento dos dados da transação.
private:
    // PONTEIROS E REFERÊNCIAS: Utilização de ponteiros constantes para otimizar o uso de memória, evitando a cópia desnecessária dos objetos.
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