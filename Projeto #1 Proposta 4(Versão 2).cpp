#include <iostream>
#include <string>

#define N 5

int pos = 0;
int pos_usuario = 0;
int pos_livro = 0;

using namespace std;

struct Usuario {
    int matricula;
    string nome;
    string tipo;
};

struct Livro {
    int codigo;
    string titulo;
    string autor;
    int edicao;
    int matricula_emprestimo;
};

void mostrar_menu() {
    cout << "\n ----- Menu da Biblioteca -----\n";
    cout << "1 - Cadastrar usuario.\n";
    cout << "2 - Cadastrar livro.\n";
    cout << "3 - Listar usuarios.\n";
    cout << "4 - Listar livros.\n";
    cout << "5 - Buscar livros por usuario.\n";
    cout << "6 - Relatorio geral.\n";
    cout << "7 - Sair.\n";
    cout << "Digite sua opcao: ";
}

void mostrar_usuario(Usuario vet[]){
    if (pos_usuario == 0) {
        cout << "\nNenhum usuario cadastrado.\n";
        return;
    }
    for(int i = 0; i < pos_usuario; i++) {
        cout << "\n--- Cadastro de um novo usuario ---\n";
        cout << "Numero da matricula: " << vet[i].matricula << endl;
        cout << "Nome: " << vet[i].nome << endl;
        cout << "Tipo (Aluno ou Professor): " << vet[i].tipo << endl;
    }
}

void mostrar_livro(Livro vet[]){
    if (pos_livro == 0) {
        cout << "\nNenhum livro cadastrado.\n";
        return;
    }
    for(int i = 0; i < pos_livro; i++) {
        cout << "\n--- Cadastro de um novo livro ---\n";
        cout << "Codigo do livro: " << vet[i].codigo << endl;
        cout << "Titulo do livro: " << vet[i].titulo << endl;
        cout << "Autor do livro: " << vet[i].autor << endl;
        cout << "Edicao do livro: " << vet[i].edicao << endl;
    }
}

void cadastrar_usuario(Usuario *u) {
    cout << "Digite a matricula: ";
    cin >> u->matricula;

    cout << "Digite o nome: ";
    cin.ignore();
    getline(cin, u->nome);

    cout << "Tipo (Aluno ou Professor): ";
    getline(cin, u->tipo);
}

void cadastrar_livro(Livro *l) {
    cout << "Digite o codigo do livro: ";
    cin >> l->codigo;

    cout << "Digite o titulo do livro: ";
    cin.ignore();
    getline(cin, l->titulo);

    cout << "Digite o autor do livro: ";
    getline(cin, l->autor);

    cout << "Digite a edicao do livro: ";
    cin >> l->edicao;
}

void adicionar_livro(Livro vet[], Livro l){
    if(pos_livro < N)
        vet[pos_livro++] = l;
    else
        cout << "Lista cheia. Livro nao adicionado.\n";
}

void adicionar_usuario(Usuario vet[], Usuario u){
    if(pos_usuario < N)
        vet[pos_usuario++] = u;
    else
        cout << "Lista cheia. Usuario nao adicionado.\n";
}

void BuscaLivro(Livro vet[]){
    int b;
    cout << "Digite a matricula do usuario: ";
    cin >> b;

    for (int i=0; i<pos; i++){
        if(vet[i].matricula_emprestimo == b){
            cout << "Matricula do usuario que esta com o livro: " << vet[i].matricula_emprestimo<< endl;
            cout << "Codigo do livro: " << vet[i].codigo << endl;
            cout << "Titulo: " << vet[i].titulo << endl;
            cout << "Autor: " << vet[i].autor << endl;
            cout << "Edicao: " << vet[i].edicao << endl;
        } else {
            cout << "Digite uma matricula que exista: ";
            cin >> b;
        }
    }
}

void Relatorio(Livro vet[]){
    int cont;
    for (int i=0; i<pos; i++){
        if(vet[i].matricula_emprestimo > 0)
            cont++;
    }
    cout << "Numero totais de livros emprestados: " << cont << endl;
}

int main() {
    Usuario este_usuario;
    Usuario vetor_usuario[N];

    Livro este_livro;
    Livro vetor_livro[N];
    int opcao;

    do {
        mostrar_menu();
        cin >> opcao;

        switch(opcao) {
            case 1:
                cadastrar_usuario(&este_usuario);
                adicionar_usuario(vetor_usuario, este_usuario);
                break;
            case 2:
                cadastrar_livro(&este_livro);
                adicionar_livro(vetor_livro, este_livro);
                break;
            case 3:
                mostrar_usuario(vetor_usuario);
                break;
            case 4:
                mostrar_livro(vetor_livro);
                break;
            case 5:
                BuscaLivro(vetor_livro);
                break;
            case 6:
                Relatorio(vetor_livro);
                break;
            case 7:
                cout << "\nAte Mais!\n";
                break;
            default:
            cout << "\nOpcao invalida, selecione outra opcao\n";
            break;
        }
    } while(opcao != 7);

    return 0;
}
