// Verifica se o símbolo FUNCIONARIO_H já foi definido, caso contrário, o
// define.
#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

// Inclui a biblioteca de strings do C++ para manipulação de strings.
#include <string>

// Declaração da classe Funcionario.
class Funcionario {
public:
  // Construtor da classe Funcionario com os parâmetros necessários.
  Funcionario(int identificacao, char categoria, const std::string &nome,
              const std::string &cargo, char sexo, int idade, double salario);

  // Métodos get para acessar os atributos privados da classe.
  int getIdentificacao() const;
  char getCategoria() const;
  const std::string &getNome() const;
  const std::string &getCargo() const;
  char getSexo() const;
  int getIdade() const;
  double getSalario() const;

private:
  // Atributos privados da classe Funcionario.
  int identificacao; // Identificação do funcionário.
  char categoria;    // Categoria do funcionário (ex: A, B, C).
  std::string nome;  // Nome do funcionário.
  std::string cargo; // Cargo do funcionário.
  char sexo;         // Sexo do funcionário (ex: M, F).
  int idade;         // Idade do funcionário.
  double salario;    // Salário do funcionário.
};

// Finaliza a verificação da diretiva de pré-processador.
#endif // FUNCIONARIO_H
