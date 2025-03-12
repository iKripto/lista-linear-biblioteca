#include <iostream>
#include <string>
using namespace std;

#define MAX 50  // Número máximo de livros na livraria

// Estrutura para armazenar os dados de um livro
struct Livro {
    int codigo;
    string nome;
    float preco;
};

// Estrutura para representar a lista de livros
struct Estoque {
    Livro livros[MAX];  // Array para armazenar os livros
    int tamanho;        // Quantidade atual de livros no estoque
};

// Função para inicializar o estoque
void inicializarEstoque(Estoque &estoque) {
    estoque.tamanho = 0;
}

// Função para adicionar um livro ao estoque
bool adicionarLivro(Estoque &estoque, int codigo, string nome, float preco) {
    if (estoque.tamanho >= MAX) {
        cout << "Erro: O estoque esta cheio!" << endl;
        return false;
    }

    // Adiciona os dados do livro no array
    estoque.livros[estoque.tamanho].codigo = codigo;
    estoque.livros[estoque.tamanho].nome = nome;
    estoque.livros[estoque.tamanho].preco = preco;
    estoque.tamanho++;

    cout << "Livro adicionado com sucesso!" << endl;
    return true;
}

// Função para listar todos os livros do estoque
void listarLivros(const Estoque &estoque) {
    if (estoque.tamanho == 0) {
        cout << "Nenhum livro cadastrado." << endl;
        return;
    }

    cout << "\nLista de Livros no Estoque:" << endl;
    for (int i = 0; i < estoque.tamanho; i++) {
        cout << "Codigo: " << estoque.livros[i].codigo
             << " | Nome: " << estoque.livros[i].nome
             << " | Preco: " << estoque.livros[i].preco << endl;
    }
}

// Função para buscar um livro pelo código
void buscarLivro(const Estoque &estoque, int codigo) {
    for (int i = 0; i < estoque.tamanho; i++) {
        if (estoque.livros[i].codigo == codigo) {
            cout << "Livro encontrado!" << endl;
            cout << "Codigo: " << estoque.livros[i].codigo
                 << " | Nome: " << estoque.livros[i].nome
                 << " | Preco:  " << estoque.livros[i].preco << endl;
            return;
        }
    }
    cout << "Livro com codigo " << codigo << "Nao encontrado." << endl;
}

// Função para remover um livro do estoque pelo código
bool removerLivro(Estoque &estoque, int codigo) {
    int posicao = -1;

    // Procura o livro no array
    for (int i = 0; i < estoque.tamanho; i++) {
        if (estoque.livros[i].codigo == codigo) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        cout << "Livro com codigo " << codigo << "Nao encontrado." << endl;
        return false;
    }

    // Remove deslocando os elementos seguintes para preencher o espaço
    for (int i = posicao; i < estoque.tamanho - 1; i++) {
        estoque.livros[i] = estoque.livros[i + 1];
    }
    estoque.tamanho--;

    cout << "Livro removido com sucesso!" << endl;
    return true;
}

// Função para exibir o menu
void exibirMenu() {
    cout << "\n===== MENU =====" << endl;
    cout << "1 - Adicionar Livro" << endl;
    cout << "2 - Listar Livros" << endl;
    cout << "3 - Buscar Livro pelo Código" << endl;
    cout << "4 - Remover Livro" << endl;
    cout << "5 - Sair" << endl;
    cout << "Escolha uma opção: ";
}

// Função principal
int main() {
    Estoque estoque;
    inicializarEstoque(estoque);
    
    int opcao, codigo;
    string nome;
    float preco;

    do {
        exibirMenu();
        cin >> opcao;
        cin.ignore();  // Para evitar problemas com getline()

        switch (opcao) {
            case 1:  // Adicionar Livro
                cout << "Digite o codigo do livro: ";
                cin >> codigo;
                cin.ignore();
                cout << "Digite o nome do livro: ";
                getline(cin, nome);
                cout << "Digite o preco do livro: ";
                cin >> preco;
                adicionarLivro(estoque, codigo, nome, preco);
                break;

            case 2:  // Listar Livros
                listarLivros(estoque);
                break;

            case 3:  // Buscar Livro pelo Código
                cout << "Digite o codigo do livro: ";
                cin >> codigo;
                buscarLivro(estoque, codigo);
                break;

            case 4:  // Remover Livro
                cout << "Digite o codigo do livro: ";
                cin >> codigo;
                removerLivro(estoque, codigo);
                break;

            case 5:  // Sair
                cout << "Saindo do programa..." << endl;
                break;

            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }

    } while (opcao != 5);

    return 0;
}
