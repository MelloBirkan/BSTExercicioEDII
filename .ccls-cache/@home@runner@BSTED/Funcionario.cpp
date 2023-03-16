// Inclui o arquivo de cabeçalho da classe Funcionario.
#include "Funcionario.h"

// Implementação do construtor da classe Funcionario.
Funcionario::Funcionario(int identificacao, char categoria,
                         const std::string &nome, const std::string &cargo,
                         char sexo, int idade, double salario)
    : identificacao(identificacao), categoria(categoria), nome(nome),
      cargo(cargo), sexo(sexo), idade(idade), salario(salario) {}

// Implementação dos métodos get para acessar os atributos privados da classe.

// Retorna o valor do atributo identificacao.
int Funcionario::getIdentificacao() const { return identificacao; }

// Retorna o valor do atributo categoria.
char Funcionario::getCategoria() const { return categoria; }

// Retorna uma referência constante ao atributo nome.
const std::string &Funcionario::getNome() const { return nome; }

// Retorna uma referência constante ao atributo cargo.
const std::string &Funcionario::getCargo() const { return cargo; }

// Retorna o valor do atributo sexo.
char Funcionario::getSexo() const { return sexo; }

// Retorna o valor do atributo idade.
int Funcionario::getIdade() const { return idade; }

// Retorna o valor do atributo salario.
double Funcionario::getSalario() const { return salario; }
