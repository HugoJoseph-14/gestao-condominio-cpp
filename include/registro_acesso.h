#pragma once
#include "pessoa.h"
#include <string>

// CONCEITO DE CLASSE: Molde abstrato que define atributos e ações para os registros.
class RegistroAcesso {
// MODIFICADOR DE ACESSO (Protected): Permite que apenas as classes filhas acessem esses atributos.
protected:
    Pessoa* pessoa;
    std::string dataHora;

// MODIFICADOR DE ACESSO (Public): Métodos que qualquer um pode acessar de fora.
public:
    RegistroAcesso();
    RegistroAcesso(Pessoa* pessoaInicial, const std::string& dataHoraInicial);
    virtual ~RegistroAcesso() = default; 

    Pessoa* getPessoa() const;
    std::string getDataHora() const;
    void setPessoa(Pessoa* pessoaNova);
    void setDataHora(const std::string& dataHoraNova);

    // POLIMORFISMO: Método virtual puro (= 0). Obriga as classes filhas a criarem a sua própria versão.
    virtual void exibirRegistro() const = 0; 
};

// HERANÇA: RegistroEntrada herda tudo de RegistroAcesso (reutilização de código).
class RegistroEntrada : public RegistroAcesso {
// MODIFICADOR DE ACESSO (Private): Encapsulamento, escondendo atributos de outras classes.
private:
    std::string autorizacaoPor;

public:
    RegistroEntrada();
    RegistroEntrada(Pessoa* pessoaInicial, const std::string& dataHoraInicial, const std::string& autorizacaoInicial);
    ~RegistroEntrada() override = default;

    std::string getAutorizacaoPor() const;
    void setAutorizacaoPor(const std::string& novaAutorizacao);

    // POLIMORFISMO: Sobrescreve (override) o método da classe mãe para mostrar do seu jeito.
    void exibirRegistro() const override;
};

// HERANÇA: RegistroSaida também herda de RegistroAcesso.
class RegistroSaida : public RegistroAcesso {
private:
    std::string motivoSaida;

public:
    RegistroSaida();
    RegistroSaida(Pessoa* pessoaInicial, const std::string& dataHoraInicial, const std::string& motivoInicial);
    ~RegistroSaida() override = default;

    std::string getMotivoSaida() const;
    void setMotivoSaida(const std::string& novoMotivo);

    // POLIMORFISMO: Versão própria da saída para exibirRegistro.
    void exibirRegistro() const override;
};