#include "Funcionario.h"

Funcionario::Funcionario(int identificacao, char categoria,
                         const std::string &nome, const std::string &cargo,
                         char sexo, int idade, double salario)
    : identificacao(identificacao), categoria(categoria), nome(nome),
      cargo(cargo), sexo(sexo), idade(idade), salario(salario) {}

int Funcionario::getIdentificacao() const { return identificacao; }

char Funcionario::getCategoria() const { return categoria; }

const std::string &Funcionario::getNome() const { return nome; }

const std::string &Funcionario::getCargo() const { return cargo; }

char Funcionario::getSexo() const { return sexo; }

int Funcionario::getIdade() const { return idade; }

double Funcionario::getSalario() const { return salario; }
