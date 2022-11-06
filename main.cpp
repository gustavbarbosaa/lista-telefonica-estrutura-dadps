#include <iostream>

using namespace std;

struct Contato
{
    string nome, telefone;
    Contato *prox;
};

void addInicio(Contato *&lista, string nomeFunc, string telefoneFunc)
{
    Contato *contato = new Contato;
    contato->nome = nomeFunc;
    contato->telefone = telefoneFunc;
    contato->prox = lista;

    if (lista == NULL)
    {
        lista = contato;
        contato->prox = NULL;
    }
    else
    {
        contato->prox = lista;
        lista = contato;
    }
}

void addFim(Contato *&lista, string nomeFunc, string telefoneFunc)
{
    Contato *contato = new Contato;
    contato->nome = nomeFunc;
    contato->telefone = telefoneFunc;
    contato->prox = NULL;

    if(lista == NULL)
    {
        lista = contato;
        contato->prox = NULL;
    }
    else
    {
        Contato *perc = lista;
        while (perc->prox != NULL)
        {
            perc = perc->prox;
        }
        perc->prox = contato;
    }
}

int tamanho(Contato *lista)
{
    int cont = 0;
    Contato *perc = lista;
    while(perc != NULL)
    {
        cont++;
        perc = perc->prox;
    }
    return cont;
}

void addPosicao(Contato *&lista, string nomeFunc, string telefoneFunc, string nomeAnt, string numAnt)
{

    Contato *aux, *contato = new Contato;
    contato->nome = nomeFunc;
    contato->telefone = telefoneFunc;
    contato->prox = NULL;

    if(lista == NULL)
    {
        lista = contato;
        contato->prox = NULL;
    }
    else
    {
        aux = lista;
        while(aux->nome != nomeAnt && aux->telefone != numAnt && aux->prox)
        {
            aux = aux->prox;
        }
        contato->prox = aux->prox;
        aux->prox = contato;
    }
}

bool removeInicio(Contato *&lista)
{

    if (lista == NULL)
    {
        return false;
    }

    Contato *aux = lista;
    lista = lista->prox;
    delete aux;
    return true;
}

bool removeFim(Contato *&lista)
{

    if(lista == NULL)
    {
        return false;
    }
    else
    {
        Contato *perc = lista;
        while (perc->prox != NULL)
        {
            perc = perc->prox;
        }
        perc->prox = lista;

        if (perc->prox == NULL)
        {
            Contato *aux = lista;
            lista = lista->prox;
            delete aux;
            return true;
        }
    }
}


void imprimir(Contato *lista)
{
    Contato *aux = lista;

    while (aux != NULL)
    {
        cout << aux->nome << endl;
        cout << aux->telefone << endl;
        cout << "----------------------------------" << endl;
        aux = aux->prox;
    }
}

int main()
{
    Contato *lista;
    lista = NULL;

    string nome, telefone, nomeAnt, telefoneAnt;
    int opcao;

    do
    {
        cout << "1 - Inserir no inicio" << endl;
        cout << "2 - Inserir no fim" << endl;
        cout << "3 - Inserir no meio" << endl;
        cout << "4 - Imprimir" << endl;
        cout << "5 - Deletar inicio" << endl;
        cout << "6 - Deletar fim" << endl;
        cout << "7 - Encerrar programa" << endl;
        cout << "Quantidade de contatos: " << tamanho(lista) << endl;
        cin >> opcao;
        cout << "----------------------------------" << endl;
        switch (opcao)
        {
        case 1:
        {
            cout << "Insira seu nome: ";
            cin >> nome;
            cout << "Insira o telefone: ";
            cin >> telefone;
            cout << "----------------------------------" << endl;
            addInicio(lista, nome, telefone);
            break;
        }
        case 2:
        {
            cout << "Insira seu nome: ";
            cin >> nome;
            cout << "Insira o telefone: ";
            cin >> telefone;
            cout << "----------------------------------" << endl;
            addFim(lista, nome, telefone);
            break;
        }
        case 3:
        {
            imprimir(lista);
            cout << "Insira seu nome: ";
            cin >> nome;
            cout << "Insira o telefone: ";
            cin >> telefone;
            cout << "Agora digite o nome e o telefone de uma pessoa cadastrada na lista." << endl;
            cout << "Nome do contato: ";
            cin >> nomeAnt;
            cout << "Numero do contato: ";
            cin >> telefoneAnt;
            addPosicao(lista, nome, telefone, nomeAnt, telefoneAnt);
            cout << "----------------------------------" << endl;
            break;
        }
        case 4:
        {
            imprimir(lista);
            cout << "----------------------------------" << endl;
            break;
        }
        case 5:
        {
            cout << "Removendo primeiro elemento" << endl;
            bool remove = removeInicio(lista);
            if (remove)
            {
                removeInicio(lista);
            }
            cout << "----------------------------------" << endl;
            break;
        }
        case 6:
        {
            cout << "Removendo ultimo elemento" << endl;
            bool remove = removeFim(lista);
            if (remove)
            {
                removeFim(lista);
            }
            cout << "----------------------------------" << endl;
            break;
        }
        case 7:
        {
            cout << "Encerrando..." << endl;
            cout << "----------------------------------" << endl;
            break;
        }
        default:
        {
            cout << "Opção não identificada" << endl;
            cout << "----------------------------------" << endl;
        }
        }
    }
    while (opcao != 7);


    return 0;
}
