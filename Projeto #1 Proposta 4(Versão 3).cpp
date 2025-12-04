#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

#define N 5

int pos = 0;
int pos_usuario = 0;
int pos_matricula = 0;
int pos_livro = 0;

using namespace std;

struct Usuario {
    int matricula;
    char nome[100];
    char tipo[100];
};

struct Matricula {
    char curso[100];
};

struct Livro {
    int codigo;
    char titulo[100];
    char autor[100];
    int edicao;
    int matricula_emprestimo;
};

void mostrar_menu() {
    cout << "\n ----- Menu da Biblioteca -----\n";
    cout << "1 - Cadastrar usuario.\n";
    cout << "2 - Cadastrar Curso do Aluno.\n";
    cout << "3 - Cadastrar livro.\n";
    cout << "4 - Listar usuarios.\n";
    cout << "5 - Listar Cursos.\n";
    cout << "6 - Listar livros.\n";
    cout << "7 - Buscar livros por usuario.\n";
    cout << "8 - Relatorio geral.\n";
    cout << "9 - Salvar Informacoes no HD.\n";
    cout << "10 - Carregar Informacoes do HD.\n";
    cout << "11 - Sair.\n";
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

void mostrar_matricula(Matricula vet[]){
    if (pos_matricula == 0) {
        cout << "\nNenhuma curso cadastrado.\n";
        return;
    }
    for(int i = 0; i < pos_matricula; i++) {
        cout << "\n--- Cadastro de um novo curso ---\n";
        cout << "Nome do Curso: " << vet[i].curso << endl;
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

void cadastras_matricula(Matricula *c){
    cout << "Digite o Curso do Aluno: ";
    cin.ignore();
    cin.getline(c->curso,100);
}

void cadastrar_usuario(Usuario *u) {
    cout << "Digite a matricula: ";
    cin >> u->matricula;

    cout << "Digite o nome: ";
    cin.ignore();
    cin.getline(u->nome,100);

    cout << "Tipo (Aluno ou Professor): ";
    cin.getline(u->tipo,100);
}

void cadastrar_livro(Livro *l) {
    cout << "Digite o codigo do livro: ";
    cin >> l->codigo;

    cout << "Digite o titulo do livro: ";
    cin.ignore();
    cin.getline(l->titulo,100);

    cout << "Digite o autor do livro: ";
    cin.getline(l->autor,100);

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

void adicionar_matricula(Matricula vet[], Matricula c){
    if(pos_matricula < N)
        vet[pos_matricula++] = c;
    else
        cout << "Lista cheia. Curso nao adicionado.\n";
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

void salvar_informacoes_usuario(Usuario vet[]){
    fstream arquivoUsuario;

    arquivoUsuario.open("arquivo_usuario.bin", ios::out | ios::binary);

    if(arquivoUsuario.is_open()){
        arquivoUsuario.write((char *) vet, sizeof(Usuario)*N);
        arquivoUsuario.write((char *) &pos_usuario, sizeof(pos_usuario));
        arquivoUsuario.close();
        cout << "Infomacoes salvas.\n";
    }
    else{
        cout << "Falha ao salvar informacoes.\n";
    }
}

void salvar_informacoes_matricula(Matricula vet[]){
    fstream arquivoMatricula;

    arquivoMatricula.open("arquivo_matricula.bin", ios::out | ios::binary);

    if(arquivoMatricula.is_open()){
        arquivoMatricula.write((char *) vet, sizeof(Matricula)*N);
        arquivoMatricula.write((char *) &pos_matricula, sizeof(pos_matricula));
        arquivoMatricula.close();
        cout << "Infomacoes salvas.\n";
    }
    else{
        cout << "Falha ao salvar informacoes.\n";
    }
}

void carregar_matricula(Matricula vet[]){
    fstream arquivoMatricula;

    arquivoMatricula.open("arquivo_matricula.bin", ios::in | ios::binary);

    if(arquivoMatricula.is_open()){
        arquivoMatricula.read((char *) vet, sizeof(Matricula)*N);
        arquivoMatricula.read((char *) &pos_matricula, sizeof(pos_matricula));
        arquivoMatricula.close();
        cout << "Infomacoes carregadas.\n";
    }
    else{
        cout << "Falha ao carregar informacoes.\n";
    }
}

void carregar_usuario(Usuario vet[]){
    fstream arquivoUsuario;

    arquivoUsuario.open("arquivo_usuario.bin", ios::in | ios::binary);

    if(arquivoUsuario.is_open()){
        arquivoUsuario.read((char *) vet, sizeof(Usuario)*N);
        arquivoUsuario.read((char *) &pos_usuario, sizeof(pos_usuario));
        arquivoUsuario.close();
        cout << "Infomacoes carregadas.\n";
    }
    else{
        cout << "Falha ao carregar informacoes.\n";
    }
}

void salvar_informacoes_livro(Livro vet[]){
    fstream arquivoLivro;

    arquivoLivro.open("arquivo_livro.bin", ios::out | ios::binary);

    if(arquivoLivro.is_open()){
        arquivoLivro.write((char *) vet, sizeof(Livro)*N);
        arquivoLivro.write((char *) &pos_livro, sizeof(pos_livro));
        arquivoLivro.close();
        cout << "Infomacoes salvas.\n";
    }
    else{
        cout << "Falha ao salvar informacoes.\n";
    }
}

void carregar_livro(Livro vet[]){
    fstream arquivoLivro;

    arquivoLivro.open("arquivo_livro.bin", ios::in | ios::binary);

    if(arquivoLivro.is_open()){
        arquivoLivro.read((char *) vet, sizeof(Livro)*N);
        arquivoLivro.read((char *) &pos_livro, sizeof(pos_livro));
        arquivoLivro.close();
        cout << "Infomacoes carregadas.\n";
    }
    else{
        cout << "Falha ao carregar informacoes.\n";
    }
}

int main() {
    Usuario este_usuario;
    Usuario vetor_usuario[N];

    Matricula este_matricula;
    Matricula vetor_matricula[N];

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
                cadastras_matricula(&este_matricula);
                adicionar_matricula(vetor_matricula, este_matricula);
                break;
            case 3:
                cadastrar_livro(&este_livro);
                adicionar_livro(vetor_livro, este_livro);
                break;
            case 4:
                mostrar_usuario(vetor_usuario);
                break;
            case 5:
                mostrar_matricula(vetor_matricula);
                break;
            case 6:
                mostrar_livro(vetor_livro);
                break;
            case 7:
                BuscaLivro(vetor_livro);
                break;
            case 8:
                Relatorio(vetor_livro);
                break;
            case 9:
                salvar_informacoes_usuario(vetor_usuario);
                salvar_informacoes_livro(vetor_livro);
                salvar_informacoes_matricula(vetor_matricula);
                cout << "\nInformacoes salvas\n";
                break;
            case 10:
                carregar_usuario(vetor_usuario);
                carregar_livro(vetor_livro);
                carregar_matricula(vetor_matricula);
                break;
            case 11:
                cout << "\nAte Mais!\n";
                break;
            default:
            cout << "\nOpcao invalida, selecione outra opcao\n";
            break;
        }
    } while(opcao != 11);

    return 0;
}
