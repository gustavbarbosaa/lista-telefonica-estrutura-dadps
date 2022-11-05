#include <iostream>

using namespace std;

struct Contato{
    string nome, sobrenome, telefone;
    Contato *prox;
};

void addInicio(Contato *&lista, string nomeFunc, string sobrenomeFunc, string telefoneFunc) {
    Contato *contato = new Contato;
    contato->nome = nomeFunc;
    contato->sobrenome = sobrenomeFunc;
    contato->telefone = telefoneFunc;
    contato->prox = lista;

    if (lista == NULL) {
        lista = contato;
        contato->prox = NULL;
    } else {
        contato->prox = lista;
        lista = contato;
    }
}

void addFim(Contato *&lista, string nomeFunc, string sobrenomeFunc, string telefoneFunc){
    Contato *contato = new Contato;
    contato->nome = nomeFunc;
    contato->sobrenome = sobrenomeFunc;
    contato->telefone = telefoneFunc;
    contato->prox = NULL;

    if(lista == NULL) {
        lista = contato;
        contato->prox = NULL;
    } else {
        Contato *perc = lista;
        while (perc->prox != NULL) {
            perc = perc->prox;
        }
        perc->prox = contato;
    }
}

void imprimir(Contato *lista) {
    Contato *aux = lista;

    while (aux != NULL) {
        cout << aux->nome << " "<< aux->sobrenome << endl;
        cout << aux->telefone << endl;
        aux = aux->prox;
    }
}

int main()
{
    Contato *lista;
    lista = NULL;

    string nome, sobrenome, telefone;
    int opcao;

    do {
        cout << "1 - Inserir no inicio" << endl;
        cout << "2 - Inserir no fim" << endl;
        cout << "3 - Imprimir" << endl;
        cout << "4 - Encerrar programa" << endl;
        cin >> opcao;

        switch (opcao) {
        case 1:
            {
            cout << "Insira seu nome: ";
            cin >> nome;
            cout << "Insira seu sobrenome: ";
            cin >> sobrenome;
            cout << "Insira o telefone: ";
            cin >> telefone;
            cout << endl;
            addInicio(lista, nome, sobrenome, telefone);
            break;
            }
        case 2:
            {
            cout << "Insira seu nome: ";
            cin >> nome;
            cout << "Insira seu sobrenome: ";
            cin >> sobrenome;
            cout << "Insira o telefone: ";
            cin >> telefone;
            cout << endl;
            addFim(lista, nome, sobrenome, telefone);
            break;
            }

        case 3:
            {
            imprimir(lista);
            break;
            }
        case 4:
            {
                cout << "Encerrando..." << endl;
                break;
            }
        default:
            {
                cout << "Opção não identificada" << endl;
            }
        }
    } while (opcao != 4);


    return 0;
}
