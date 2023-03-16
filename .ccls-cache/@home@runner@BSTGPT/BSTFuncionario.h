#ifndef BSTFUNCIONARIO_H
#define BSTFUNCIONARIO_H

#include "Funcionario.h"
#include <functional>
#include <memory>

class BSTFuncionario {
public:
  BSTFuncionario();
  ~BSTFuncionario();

  int contarFuncionariosPorSexo(char sexo) const;
  void exibirFuncionariosPorIdade(int idadeMinima,
                                  void (*imprimir)(const Funcionario &)) const;
  int contarFuncionariosPorCategoria(char categoria) const;
  double calcularGastoSalarios() const;
  void inserir(const Funcionario &funcionario);
  void
  percursoInOrder(std::function<void(const Funcionario &)> processar) const;

private:
  struct No {
    Funcionario funcionario;
    std::unique_ptr<No> esquerda;
    std::unique_ptr<No> direita;

    No(const Funcionario &funcionario);
  };

  std::unique_ptr<No> raiz;

  void inserirNo(std::unique_ptr<No> &no, const Funcionario &funcionario);

  void
  percursoInOrderNo(No *no,
                    std::function<void(const Funcionario &)> processar) const;
};

#endif // BSTFUNCIONARIO_H
