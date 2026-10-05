#include <iostream>
#include <memory>
#include "../include/pessoa.h"
#include "../include/hospede.h"
#include "../include/funcionario.h"
#include "../include/registro_acesso.h"
#include "../include/portaria.h"

int main() {
    std::cout << "--- SISTEMA DE GERENCIAMENTO DE PORTARIA ---" << std::endl << std::endl;

    // OBJETO: Criando instâncias reais na memória a partir das classes.
    Hospede hospede1("Carlos Silva", "123.456.789-00", 102, "04/10/2026");
    Funcionario func1("Ana Souza", "987.654.321-11", "Eletricista");

    // OBJETO: Instanciando a classe que vai gerir os registros.
    Portaria portaria;

    std::cout << "-> Registrando movimentacoes na portaria...\n" << std::endl;

    // POLIMORFISMO: A Portaria recebe as classes filhas (RegistroEntrada e RegistroSaida) 
    // mas guarda e trata todas elas de forma genérica como RegistroAcesso.
    portaria.registrarAcesso(std::make_unique<RegistroEntrada>(&hospede1, "04/10/2026 14:00", "Recepcao Central"));
    portaria.registrarAcesso(std::make_unique<RegistroEntrada>(&func1, "04/10/2026 14:30", "Supervisao de Manutencao"));
    
    auto saida1 = std::make_unique<RegistroSaida>(&func1, "04/10/2026 18:00", "Fim do Expediente");
    portaria.registrarAcesso(std::move(saida1));

    // Aqui o polimorfismo acontece executando o método certo para cada tipo de registro.
    portaria.listarHistorico();

    return 0;
}