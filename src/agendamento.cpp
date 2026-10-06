#include "../include/agendamento.h"
#include <iostream>

// CONSTRUTOR / COMPOSIÇÃO: Inicializa os ponteiros para vincular as diferentes instâncias (CRUD em memória).
Agendamento::Agendamento(const Hospede* h, const Funcionario* f, const Servico* s, std::string dh)
    : hospede(h), funcionario(f), servico(s), dataHora(dh), status("Pendente") {}

void Agendamento::setStatus(std::string novoStatus) {
    status = novoStatus;
}

std::string Agendamento::getStatus() const {
    return status;
}

void Agendamento::exibirAgendamento() const {
    std::cout << "=================================" << std::endl;
    std::cout << "     AGENDAMENTO DE SERVICO      " << std::endl;
    std::cout << "=================================" << std::endl;
    std::cout << "Data/Hora: " << dataHora << std::endl;
    std::cout << "Status: " << status << std::endl;
    
    // VERIFICAÇÃO DE PONTEIROS: Evita falhas de segmentação garantindo que a memória está alocada.
    if (hospede != nullptr) {
        std::cout << "\n[Hospede Solicitante]" << std::endl;
        hospede->exibirDetalhes(); // Chamada polimórfica via ponteiro
    }
    
    if (funcionario != nullptr) {
        std::cout << "\n[Funcionario Encarregado]" << std::endl;
        funcionario->exibirDetalhes(); // Chamada polimórfica via ponteiro
    }
    
    if (servico != nullptr) {
        std::cout << "\n[Detalhes do Servico]" << std::endl;
        servico->exibirDetalhes(); // Chamada polimórfica via ponteiro
    }
    std::cout << "=================================\n" << std::endl;
}