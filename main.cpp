#include <iostream>

using namespace std;

struct Contato
{
    string nome, telefone;
    Contato *prox;
    Contato *ant;
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
    cout << "Contato apagado" << endl;
    return true;
}

bool removeFim(Contato *&lista)
{
    if (lista == NULL)
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
        lista->prox = NULL;
        delete perc;
        cout << "Contato apagado" << endl;
        return true;
    }
}

/*bool removeUsuario(Contato *&lista, string nome, string telefone)
{
    if (lista == NULL)
    {
        return false;
    }
    else
    {
        Contato *aux, *perc = lista;

        while (lista != NULL)
        {
            perc = perc->prox;
            if (perc->nome == nome && perc->telefone == telefone && perc->prox)
            {
                aux->prox = perc;
                aux = aux->prox;
                delete perc;
            }
            lista->prox = aux;
        }

        return true;
    }
}

bool removeRepetidos(Contato *&lista)
{
    if (lista == NULL)
    {
        return false;
    }
    else
    {
        Contato *aux, *perc = lista;
        while (perc->prox != NULL)
        {
            perc = perc->prox;
            if(perc->nome == lista->nome && perc->telefone == lista->telefone)
            {
                aux->prox = perc;
                aux = aux->prox;
                delete perc;
            }
        }
        return true;
    }
}*/

void buscar(Contato *lista, string nome)
{
    if (lista == NULL)
    {
        cout << "Lista vazia" << endl;
    }
    else
    {
        while (lista != NULL) {
            lista = lista->prox;

            if (lista->nome == nome){
                cout << "Nome: " << lista->nome << endl;
                cout << "Telefone: " << lista->telefone << endl;
            }
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
        cout << "Digite um numero correspondente a funcao abaixo" << endl;
        cout << "1 - Inserir no inicio" << endl;
        cout << "2 - Inserir no fim" << endl;
        cout << "3 - Inserir no meio" << endl;
        cout << "4 - Imprimir" << endl;
        cout << "5 - Deletar inicio" << endl;
        cout << "6 - Deletar fim" << endl;
        cout << "7 - Deletar contato especifico" << endl;
        cout << "8 - Deletar repetidos" << endl;
        cout << "9 - Buscar contato" << endl;
        cout << "10 - Encerrar programa" << endl;
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
            removeInicio(lista);
            cout << "----------------------------------" << endl;
            break;
        }
        case 6:
        {
            cout << "Removendo ultimo elemento" << endl;
            removeFim(lista);
            cout << "----------------------------------" << endl;
            break;
        }
        case 7:
        {
            cout << "NÃO FUNCIONAL" << endl;
            /*string nomeCtt, telefoneCtt;
            cout << "Digite o nome do contato que voce quer remover: ";
            cin >> nome;
            cout << "Agora digite o numero do contato: ";
            cin >> telefone;
            removeUsuario(lista, nomeCtt, telefoneCtt);
            cout << "Removendo contato" << endl;*/
            cout << "----------------------------------" << endl;
            break;
        }
        case 8:
        {
            cout << "NÃO FUNCIONAL" << endl;
            /*cout << "Removendo contatos repetidos" << endl;
            removeRepetidos(lista);*/
            cout << "----------------------------------" << endl;
            break;
        }
        case 9:
        {
            string nomeCtt, telefoneCtt;
            cout << "Insira o nome do contato que voce quer: ";
            cin >> nomeCtt;
            buscar(lista, nomeCtt);
            cout << "----------------------------------" << endl;
            break;
        }
        case 10:
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
    while (opcao != 9);


    return 0;
}
