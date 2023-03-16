#include "BSTFuncionario.h"

BSTFuncionario::BSTFuncionario() : raiz(nullptr) {}

BSTFuncionario::~BSTFuncionario() {}

void BSTFuncionario::inserir(const Funcionario &funcionario) {
    inserirNo(raiz, funcionario);
}


void BSTFuncionario::percursoInOrder(std::function<void(const Funcionario &)> processar) const {
    percursoInOrderNo(raiz.get(), processar);
}




BSTFuncionario::No::No(const Funcionario &funcionario)
    : funcionario(funcionario), esquerda(nullptr), direita(nullptr) {}

void BSTFuncionario::inserirNo(std::unique_ptr<No> &no, const Funcionario &funcionario) {
    if (!no) {
        no = std::make_unique<No>(funcionario);
    } else if (funcionario.getIdentificacao() < no->funcionario.getIdentificacao()) {
        inserirNo(no->esquerda, funcionario);
    } else {
        inserirNo(no->direita, funcionario);
    }
}

// Adicione a palavra-chave 'const' no final da linha
// Modifique a linha abaixo para usar std::function
void BSTFuncionario::percursoInOrderNo(No *no, std::function<void(const Funcionario &)> processar) const {
    if (!no) {
        return;
    }

    percursoInOrderNo(no->esquerda.get(), processar);
    processar(no->funcionario);
    percursoInOrderNo(no->direita.get(), processar);
}

// Adicione essa função após a implementação de percursoInOrderNo
double BSTFuncionario::calcularGastoSalarios() const {
    double totalSalarios = 0.0;
    auto processar = [&totalSalarios](const Funcionario &funcionario) {
        totalSalarios += funcionario.getSalario();
    };
    percursoInOrder(processar);
    return totalSalarios;
}

// Adicione essa função após a implementação de calcularGastoSalarios
int BSTFuncionario::contarFuncionariosPorSexo(char sexo) const {
    int totalFuncionarios = 0;
    percursoInOrder([&totalFuncionarios, sexo](const Funcionario &funcionario) {
        if (funcionario.getSexo() == sexo) {
            totalFuncionarios++;
        }
    });
    return totalFuncionarios;
}

// Adicione essa função após a implementação de contarFuncionariosPorSexo
int BSTFuncionario::contarFuncionariosPorCategoria(char categoria) const {
    int totalFuncionarios = 0;
    percursoInOrder([&totalFuncionarios, categoria](const Funcionario &funcionario) {
        if (funcionario.getCategoria() == categoria) {
            totalFuncionarios++;
        }
    });
    return totalFuncionarios;
}

// Adicione essa função após a implementação de contarFuncionariosPorCategoria
void BSTFuncionario::exibirFuncionariosPorIdade(int idadeMinima, void (*imprimir)(const Funcionario &)) const {
    percursoInOrder([&idadeMinima, imprimir](const Funcionario &funcionario) {
        if (funcionario.getIdade() > idadeMinima) {
            imprimir(funcionario);
        }
    });
}

