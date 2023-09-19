#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
	}
	else
	{
		NO* aux = primeiro;
		if (aux->prox == NULL) {
			if (novo->valor == aux->valor) {
				cout << "Elemento duplicado, repita o processo. \n";
				return;
			}
			aux->prox = novo;
			cout << "Número adicionado a lista ordenada \n";
			return;
		}

		else
	{
		NO* aux = primeiro;
		while (aux->prox != NULL) {
			if (novo->valor == aux->valor) {
				cout << "Elemento duplicado, repita o processo. \n";
				break;
			}
			if (aux == NULL || novo->valor < aux->valor) {
				NO* ant = aux; //guarda o valor do anterior ao novo número
				novo->prox = aux->prox; // novo aponta para o valor maior
				ant->prox = novo; //anterior aponta pro novo número
				cout << "Número adicionado a lista ordenada \n";
				break;
			}
			else {
				aux->prox = novo;
				cout << "Número adicionado a lista ordenada \n";
				break;
			}
			aux = aux->prox;
		} 
	}
}

void excluirElemento()
{
	int excluir;
	cout << "Digite o número que deseja excluir:";
	cin >> excluir;
	NO* aux = primeiro;
	while (aux->prox != NULL) {
		if (aux->prox->valor == excluir)
		{
			NO* ant = aux; // guarda o valor do anterior ao excluir
			aux = aux->prox; // aux se torna o valor do excluir
			ant->prox = aux->prox; // o ponteiro do anterior aponta para o próximo do excluir 
			free(aux); // libera o excluir
			cout << "Número excluído";
			break;
		}
		else{
			cout << "Número não encontrado. \n";
			break;
		}
	}
	if (aux == NULL) {
		cout << "Número não encontrado. \n";
	}
}

void buscarElemento()
{
	int busca;
	cout << "Digite um valor para a busca:";
	cin >> busca;
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == busca)
		{
			cout << "Número encontrado. \n";
			break;
		}
		aux = aux->prox;
	}
	if (aux == NULL) {
		cout << "Número não encontrado. \n";
	}
}


