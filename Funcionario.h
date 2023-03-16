#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

class Funcionario {
public:
    Funcionario(int identificacao, char categoria, const std::string &nome, const std::string &cargo, char sexo, int idade, double salario);

    int getIdentificacao() const;
    char getCategoria() const;
    const std::string &getNome() const;
    const std::string &getCargo() const;
    char getSexo() const;
    int getIdade() const;
    double getSalario() const;

private:
    int identificacao;
    char categoria;
    std::string nome;
    std::string cargo;
    char sexo;
    int idade;
    double salario;
};

#endif // FUNCIONARIO_H
