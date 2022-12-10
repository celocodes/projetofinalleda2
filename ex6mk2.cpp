#include <iostream>
#include <string.h>

/* 
Imagine um colecionador de vinhos que compra vinhos recentes e os guarda em uma adega
para envelhecerem, e que cada ocasião especial abre sempre a sua última aquisição (para poupar os mais antigos). 
Construa um programa que:
	- Permita incluir novos vinhos na adega;
	- Informe qual vinho deve ser aberto sem uma ocasião especial, retirando da adega 
	o vinho adicionado mais antigamente (independentemente de sua safra);
	- Permite criar estruturas para o armazenamento de vinhos para ocasiões especiais;
	- Informe qual vinho deve ser aberto em uma ocasião especial;
	- Relacione as cinco aquisições mais antigas;
	- Relacione as cinco aquisições mais recentes.
As informações básicas que o registro de vinhos deve conter são: nome do produto, país de origem, tipo de uva e safra.

*/

struct Garrafa {
    char nome[60], pais[20], tipouva[20];
	int safra;
    Garrafa * next;
};

struct Adega {
    Garrafa * top;

    int qty;
};

void cadastrarVinho(struct Adega * & adega) {
	if(adega){
		Garrafa * novoVinho = (Garrafa *)calloc(1, sizeof(Garrafa));
	
		printf("\n\nCADASTRO DE VINHO\n");
		
		printf("Digite o nome: ");
		fflush(stdin);
		fgets(novoVinho->nome, 60, stdin);
		novoVinho->nome[(int)strlen(novoVinho->nome) - 1] = 0;

		printf("Digite o país de origem: ");
		fflush(stdin);
		fgets(novoVinho->tipouva, 20, stdin);
		novoVinho->tipouva[(int)strlen(novoVinho->tipouva) - 1] = 0;

		printf("Digite o tipo de uva: ");
		fflush(stdin);
		fgets(novoVinho->pais, 20, stdin);
		novoVinho->pais[(int)strlen(novoVinho->pais) - 1] = 0;
	
		printf("Digite a safra: ");
		scanf("%d", &novoVinho->safra);
	
		scanf("%*[^\n]"); 
		scanf("%*c");
		
		printf("\n\nDados cadastrados:\nNome: %s \nPaís de origem: %s \n", novoVinho->nome, novoVinho->pais);
		printf("Tipo de uva: %s \nSafra: %d", novoVinho->tipouva, novoVinho->safra);
		
        novoVinho->next = adega->top;
        adega->top = novoVinho;

		printf("\nGarrafa adicionada à pilha.");
		adega->qty++;
		
	} else printf("\nNão foi possível adicionar garrafa.");

	
}

int abrirPadrao(struct Adega * & adega){
	if(adega->top) {
		Garrafa * proximo = adega->top->next;
	
		if(adega->qty == 1) {
			printf("\nRetire %s da adega.", adega->top->nome);
	
			adega->top->next = NULL;
			adega->top = NULL;
			
			adega->qty--;
		} 
	  
		if(proximo){
  			if(adega->top == NULL){
				printf("\nStack empty");
			} else{
				while(proximo->next != NULL){
					proximo = proximo->next;
				}
			}
			printf("\nRetire %s da adega.", proximo->nome);
			adega->top = NULL;
		}

		adega->qty--;
		free(proximo);
		}
		return -1;
	}

int abrirEspecial(struct Adega * & adega){
	if(adega->top) {
		Garrafa * proximo = adega->top->next;
	
		if(adega->qty == 1) {
			printf("\nRetire %s da adega especial.", adega->top->nome);
			adega->qty--;
		}
		
		if(proximo){
			printf("\nRetire %s da adega especial.", adega->top->nome);
			
			adega->top->next = proximo->next;
			adega->top = proximo;
	
			adega->qty--;
		}
	
		free(adega->top);
	}
	return -1;
}

void mostrarVinho(struct Adega * & adega) {
  	if(adega->top == NULL){
		printf("\nPilha vazia");
	} else{
		printf("\nMostrando vinhos: \n");
			struct Garrafa * aux = adega->top;
			while(aux != NULL){
				printf("%s, %s, %s, %d \n", aux->nome, aux->pais, aux->tipouva, aux->safra);
				aux = aux->next;
			}
	}
}

void menucadastro() {
	struct Adega * adegaEspecial = (struct Adega *) calloc(1, sizeof(struct Adega));
	adegaEspecial->qty = 0;
	
	int opcao=0, opcaotipo=0;

	while(1) {
		printf("\n\n\nADEGA DO COLECIONADOR\n1 - Cadastrar novo vinho\n");
		printf("2 - Abrir vinho para situação normal\n3 - Abrir vinho para situação especial\n");
		printf("4 - Visualisar vinhos\n5 - Sair\n");
		printf("Escolha o que deseja fazer: ");
		scanf("%d", &opcao);

		if(opcao == 5) {
			printf("\nVocê escolheu sair.");
			break;
		} else if(opcao > 5 || opcao < 1) {
			printf("\nOpção inválida. Tente novamente.");
			continue;
		}

		scanf("%*[^\n]"); 
		scanf("%*c");
		
		switch(opcao) {
		case 1:
			cadastrarVinho(adegaEspecial);
			break;
		case 2:
			abrirPadrao(adegaEspecial);
			break;
		case 3:
			abrirEspecial(adegaEspecial);
			break;
		case 4:
			mostrarVinho(adegaEspecial);
			break;
		}
	}

}


int main() {
	menucadastro();
}