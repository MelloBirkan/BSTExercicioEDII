#include "BSTFuncionario.h"
#include "Funcionario.h"
#include <iostream>

void imprimirFuncionario(const Funcionario &funcionario) {
  std::cout << "ID: " << funcionario.getIdentificacao() << std::endl;
  std::cout << "Categoria: " << funcionario.getCategoria() << std::endl;
  std::cout << "Nome: " << funcionario.getNome() << std::endl;
  std::cout << "Cargo: " << funcionario.getCargo() << std::endl;
  std::cout << "Sexo: " << funcionario.getSexo() << std::endl;
  std::cout << "Idade: " << funcionario.getIdade() << std::endl;
  std::cout << "Salário: " << funcionario.getSalario() << std::endl;
  std::cout << std::endl;
}

int main() {
  BSTFuncionario bst;

  Funcionario f1(1, 'P', "João Silva", "Gerente", 'M', 35, 4500.00);
  Funcionario f2(2, 'H', "Maria Santos", "Analista", 'F', 30, 3500.00);
  Funcionario f3(3, 'O', "Carlos Pereira", "Desenvolvedor", 'M', 28, 4000.00);
  Funcionario f4(4, 'H', "Luciana Andrade", "Coordenadora", 'F', 38, 6000.00);
  Funcionario f5(5, 'P', "Maurício Gomes", "Analista Financeiro", 'M', 29,
                 3500.00);
  Funcionario f6(6, 'O', "Fernanda Lima", "Designer Gráfico", 'F', 27, 3000.00);
  Funcionario f7(7, 'H', "Ricardo Souza", "Engenheiro de Software", 'M', 33,
                 5500.00);
  Funcionario f8(8, 'P', "Patrícia Oliveira", "Assistente Administrativo", 'F',
                 25, 2000.00);
  Funcionario f9(9, 'O', "André Almeida", "Redator", 'M', 31, 2800.00);
  Funcionario f10(10, 'H', "Cláudia Costa", "Analista de Marketing", 'F', 34,
                  4000.00);

  bst.inserir(f1);
  bst.inserir(f2);
  bst.inserir(f3);
  bst.inserir(f4);
  bst.inserir(f5);
  bst.inserir(f6);
  bst.inserir(f7);
  bst.inserir(f8);
  bst.inserir(f9);
  bst.inserir(f10);

  int opcao;
  do {
    std::cout << "Menu:" << std::endl;
    std::cout << "1 - Listar funcionários em ordem crescente de ID"
              << std::endl;
    std::cout << "2 - Calcular gasto total com salários" << std::endl;
    std::cout << "3 - Contar funcionários por sexo" << std::endl;
    std::cout << "4 - Contar funcionários por categoria" << std::endl;
    std::cout << "5 - Exibir funcionários com idade maior que a informada"
              << std::endl;
    std::cout << "6 - Adicionar funcionário" << std::endl;
    std::cout << "0 - Sair" << std::endl;
    std::cout << "Digite a opção desejada: ";
    std::cin >> opcao;

    switch (opcao) {
    case 1:
      std::cout << "Funcionários em ordem crescente de ID:" << std::endl
                << std::endl;
      bst.percursoInOrder(imprimirFuncionario);
      break;
    case 2: {
      double gastoTotalSalarios = bst.calcularGastoSalarios();
      std::cout << "Gasto total com salários: R$" << gastoTotalSalarios
                << std::endl
                << std::endl;
      break;
    }
    case 3: {
      char sexo;
      std::cout << "Informe o sexo (F - feminino, M - masculino): ";
      std::cin >> sexo;
      int totalFuncionarios = bst.contarFuncionariosPorSexo(sexo);
      std::cout << "Total de funcionários com sexo " << sexo << ": "
                << totalFuncionarios << std::endl
                << std::endl;
      break;
    }
    case 4: {
      char categoria;
      std::cout << "Informe a categoria (P - Presencial, O - Home Office, H - "
                   "Híbrido): ";
      std::cin >> categoria;
      int totalFuncionarios = bst.contarFuncionariosPorCategoria(categoria);
      std::cout << "Total de funcionários na categoria " << categoria << ": "
                << totalFuncionarios << std::endl
                << std::endl;
      break;
    }
    case 5: {
      int idade;
      std::cout << "Informe a idade mínima: ";
      std::cin >> idade;
      std::cout << "Funcionários com idade maior que " << idade << ":"
                << std::endl;
      bst.exibirFuncionariosPorIdade(idade, imprimirFuncionario);
      std::cout << std::endl;
      break;
    }
    case 6: {
      int id, idade;
      char categoria, sexo;
      double salario;
      std::string nome, cargo;

      std::cout << "Informe o ID do funcionário: ";
      std::cin >> id;
      std::cout << "Informe a categoria do funcionário (P - Presencial, O - "
                   "Home Office, H - Híbrido): ";
      std::cin >> categoria;
      std::cout << "Informe o nome do funcionário: ";
      std::cin.ignore(); // Limpar o buffer do teclado
      std::getline(std::cin, nome);
      std::cout << "Informe o cargo do funcionário: ";
      std::getline(std::cin, cargo);
      std::cout
          << "Informe o sexo do funcionário (F - feminino, M - masculino): ";
      std::cin >> sexo;
      std::cout << "Informe a idade do funcionário: ";
      std::cin >> idade;
      std::cout << "Informe o salário do funcionário: ";
      std::cin >> salario;

      Funcionario novoFuncionario(id, categoria, nome, cargo, sexo, idade,
                                  salario);
      bst.inserir(novoFuncionario);

      std::cout << "Funcionário adicionado com sucesso!" << std::endl
                << std::endl;
      break;
    }

    case 0:
      std::cout << "Saindo..." << std::endl;
      break;
    default:
      std::cout << "Opção inválida!" << std::endl << std::endl;
      break;
    }
  } while (opcao != 0);

  return 0;
}
