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

struct Padrao {
	Garrafa * head;
	Garrafa * tail;
    
    int qty;
};

struct Especial {
    Garrafa * top;

    int qty;
};

void cadastrarPadrao(struct Padrao * & adega) {
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
	
	
		printf("\n\nDados cadastrados:\nNome: %s \nPaís de origem: %s \n", novoVinho->nome, novoVinho->pais);
		printf("Tipo de uva: %s \nSafra: %d", novoVinho->tipouva, novoVinho->safra);
		novoVinho->next = NULL;
		
		if(adega->head == NULL) {
			adega->head = novoVinho;
			adega->tail = novoVinho;
	  	} else {
			adega->tail->next = novoVinho;
			adega->tail = novoVinho;
	  	}

		printf("\nGarrafa adicionada à fila.");
		adega->qty++;
		
	} else printf("\nNão foi possível adicionar garrafa.");

	
}

void cadastrarEspecial(struct Especial * & adega) {
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

int abrirPadrao(struct Padrao * & adega){
  if(adega->head){
		Garrafa * proximo = adega->head->next;

		if(adega->qty == 1) {
			printf("\nRetire %s da adega normal.", adega->head->nome);

			adega->head->next = NULL;
			adega->head = NULL;
			
			adega->qty--;
		} 
	  
		if(proximo){
			printf("\nRetire %s da adega normal.", adega->head->nome);
			
			adega->head->next = proximo->next;
			adega->head = proximo;
			
			adega->qty--;
		}

	  	free(proximo);
	} else("\nNão foi possível abrir nenhum vinho.");
	return -1;
}

int abrirEspecial(struct Especial * & adega){
  	if(adega->top){
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
		free(proximo);
	} else("\nNão foi possível abrir nenhum vinho.");
	return -1;
}

void mostrarPadrao(struct Padrao * & adega) {
  	if(adega->head == NULL){
		printf("\nFila vaiza");
	} else{
		printf("\nMostrando normais: ");
			struct Garrafa * aux = adega->head;
			while(aux != NULL){
				printf("%s ", aux->nome);
				aux = aux->next;
			}
	}
}

void mostrarEspecial(struct Especial * & adega) {
  	if(adega->top == NULL){
		printf("\nPilha vazia");
	} else{
		printf("\nMostrando especiais: ");
			struct Garrafa * aux = adega->top;
			while(aux != NULL){
				printf("%s ", aux->nome);
				aux = aux->next;
			}
	}
}

void menucadastro() {
	struct Padrao * adegaPadrao = (struct Padrao *) calloc(1, sizeof(struct Padrao));
	adegaPadrao->qty = 0;

	struct Especial * adegaEspecial = (struct Especial *) calloc(1, sizeof(struct Especial));
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
			while(1) {
			printf("\n\n\nESCOLHER OCASIÃO\n1 - Cadastrar vinho normal\n2 - Cadastrar vinho especial\n3 - Sair\n");
			printf("Escolha o que deseja fazer: ");
			scanf("%d", &opcaotipo);
	
			if(opcaotipo == 3) {
				printf("\nVocê escolheu sair.");
				break;
			} else if(opcaotipo > 3 || opcaotipo < 1) {
				printf("\nOpção inválida. Tente novamente.");
				continue;
			}
			
			
			scanf("%*[^\n]"); 
			scanf("%*c");

			if(opcaotipo == 1) cadastrarPadrao(adegaPadrao);
			if(opcaotipo == 2) cadastrarEspecial(adegaEspecial);
			}
			
			break;
		case 2:
			abrirPadrao(adegaPadrao);
			break;
		case 3:
			abrirEspecial(adegaEspecial);
			break;
		case 4:
			mostrarPadrao(adegaPadrao);
			mostrarEspecial(adegaEspecial);
			break;
		}
	}

}


int main() {
	menucadastro();
}
