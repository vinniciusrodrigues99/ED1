#include <iostream>
using namespace std;

struct Funcionario
{
    int prontuario;
    string nome;
    double salario;
    struct Funcionario *prox;
};

Funcionario* init()
{
    return NULL;
}

Funcionario* insert(Funcionario* lista, int p, string n, double sal)
{
    Funcionario* novo = new Funcionario();
    novo->prontuario = p;
    novo->nome = n;
    novo->salario = sal;
    novo->prox = lista;
    return novo;
}

Funcionario* remove(Funcionario* lista, int i)
{
    Funcionario* ant = NULL;
    Funcionario* aux = lista;

    while (aux != NULL && aux->prontuario != i)
    {
        ant = aux;
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        return lista;
    }
    if (ant == NULL)
    {
        lista = aux->prox;
    }
    else
    {
        ant->prox = aux->prox;
    }
    delete(aux);
    return lista;
}

Funcionario* find(Funcionario* lista, int i)
{
    Funcionario* aux = lista;

    while (aux != NULL && aux->prontuario != i)
    {
        aux = aux->prox;
    }
    return aux;
}

void print(Funcionario* lista)
{
    Funcionario* aux = lista;
    double totalsalario=0;

    while (aux != NULL)
    {
        cout << "---------" << endl;
        cout << "Prontuario: " << aux->prontuario << endl;
        cout << "Nome: " << aux->nome << endl;
        cout << "Salario: " << aux->salario << endl;
        totalsalario+=aux->salario;
        aux = aux->prox;
    }
    
    cout << "---------" << endl;
    cout << "Total de salarios: " << totalsalario << endl;
}

int main(int argc, char** argv)
{
    Funcionario *lista;
    lista = init();
    int resp, prontuario;
    string nome;
    double salario;

    do
    {
        do
        {
            cout << endl;
            cout << "MENU" << endl;
            cout << "0. Sair" << endl;
            cout << "1. Incluir" << endl;
            cout << "2. Excluir" << endl;
            cout << "3. Pesquisar" << endl;
            cout << "4. Listar" << endl;
            cout << "Digite a opcao desejada: ";
            cin >> resp;

            if (resp < 0 || resp > 4)
            {
                cout << "Escolha uma opcao valida de 0 a 4" << endl;
            }
        } while (resp < 0 || resp > 4);

        switch(resp)
        {
            case 1:
            Funcionario *existe;
            cout << endl;
            cout << "INCLUIR FUNCIONARIO" << endl;
			
            do
            {
                cout << "Digite o prontuario: ";
                cin >> prontuario;

                existe = find(lista, prontuario);
				break;
                if (existe != NULL)
                {
                    cout << "Prontuario existente. Digite outro." << endl;
                    
                }
                break;
            }
            	
            while (existe!= NULL);

                cout << "Digite o nome: ";
                cin >> nome;
                cout << "Digite o salario: ";
                cin >> salario;

                lista = insert(lista, prontuario, nome, salario);

                cout << "Funcionario registrado com sucesso." << endl;

                break;
            case 2:
                cout << endl;
                cout << "EXCLUIR FUNCIONARIO" << endl;

                cout << "Digite o prontuario: ";
                cin >> prontuario;

                lista = remove(lista, prontuario);

                cout << "Funcionario removido." << endl;
                break;
            case 3:
                cout << endl;
                cout << "PESQUISAR FUNCIONARIO" << endl;

                cout << "Digite o prontuario: ";
                cin >> prontuario;

                Funcionario *procura;
                procura = find(lista, prontuario);

                if(procura!=NULL)
                {
                    cout << "Funcionario existente" << endl;
                    cout << "Prontuario: " << procura->prontuario << endl;
                    cout << "Nome: " << procura->nome << endl;
                    cout << "Salario: " << procura->salario << endl;
                }
                else
                {
                    cout << "Funcionario inexistente" << endl;
                }

                break;
            case 4:
                cout << endl;
                cout << "LISTAGEM DE FUNCIONARIOS" << endl;

                print(lista);
                cout << endl;
                break;
            default:
                break;
        }
    } while (resp!=0);

    return 0;
}