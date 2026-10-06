#ifndef SERVICO_H
#define SERVICO_H

#include <string>

class Servico {
protected:
    std::string descricao;
    double preco;

public:
    // Construtor
    Servico(std::string desc, double p);

    // Destrutor virtual para permitir polimorfismo correto
    virtual ~Servico();

    // Getters
    std::string getDescricao() const;
    double getPreco() const;

    // Método virtual para polimorfismo
    virtual void exibirDetalhes() const;
};

#endif // SERVICO_H