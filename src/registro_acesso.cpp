#include "../include/registro_acesso.h"
#include <iostream>

// RegistroAcesso
RegistroAcesso::RegistroAcesso() : pessoa(nullptr), dataHora("Não registrada") {}

RegistroAcesso::RegistroAcesso(Pessoa* pessoaInicial, const std::string& dataHoraInicial)
    : pessoa(pessoaInicial), dataHora(dataHoraInicial) {}

Pessoa* RegistroAcesso::getPessoa() const { return pessoa; }
std::string RegistroAcesso::getDataHora() const { return dataHora; }
void RegistroAcesso::setPessoa(Pessoa* pessoaNova) { pessoa = pessoaNova; }
void RegistroAcesso::setDataHora(const std::string& dataHoraNova) { dataHora = dataHoraNova; }

// RegistroEntrada
RegistroEntrada::RegistroEntrada() : RegistroAcesso(), autorizacaoPor("Portaria") {}

// HERANÇA: Repassa pessoa e dataHora para o construtor da classe mãe.
RegistroEntrada::RegistroEntrada(Pessoa* pessoaInicial, const std::string& dataHoraInicial, const std::string& autorizacaoInicial)
    : RegistroAcesso(pessoaInicial, dataHoraInicial), autorizacaoPor(autorizacaoInicial) {}

std::string RegistroEntrada::getAutorizacaoPor() const { return autorizacaoPor; }
void RegistroEntrada::setAutorizacaoPor(const std::string& novaAutorizacao) { autorizacaoPor = novaAutorizacao; }

// POLIMORFISMO: Exibição específica para a Entrada.
void RegistroEntrada::exibirRegistro() const {
    std::cout << "[ENTRADA] Data/Hora: " << dataHora << std::endl;
    if (pessoa != nullptr) {
        std::cout << "  Pessoa: " << pessoa->getNome() << " (Doc: " << pessoa->getDocumento() << ")" << std::endl;
    }
    std::cout << "  Autorizado por: " << autorizacaoPor << std::endl;
}

// RegistroSaida
RegistroSaida::RegistroSaida() : RegistroAcesso(), motivoSaida("Não informado") {}

// HERANÇA: Repassa pessoa e dataHora para o construtor da classe mãe.
RegistroSaida::RegistroSaida(Pessoa* pessoaInicial, const std::string& dataHoraInicial, const std::string& motivoInicial)
    : RegistroAcesso(pessoaInicial, dataHoraInicial), motivoSaida(motivoInicial) {}

std::string RegistroSaida::getMotivoSaida() const { return motivoSaida; }
void RegistroSaida::setMotivoSaida(const std::string& novoMotivo) { motivoSaida = novoMotivo; }

// POLIMORFISMO: Exibição específica para a Saída.
void RegistroSaida::exibirRegistro() const {
    std::cout << "[SAIDA] Data/Hora: " << dataHora << std::endl;
    if (pessoa != nullptr) {
        std::cout << "  Pessoa: " << pessoa->getNome() << " (Doc: " << pessoa->getDocumento() << ")" << std::endl;
    }
    std::cout << "  Motivo: " << motivoSaida << std::endl;
}