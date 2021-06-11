#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Desenvolvido por Ícaro Dias dos Santos


/*Para Cadastrar uma data de um usuario, coloque o primeiro valor e dê apenas um /
e coloque o segundo valor, um / e o ano. 
*/
int quant=0, quanton=0;
	char nome = 'n';

typedef struct data{
	
	int dia, mes, ano;
	
}Data;

typedef struct pessoas{
	
	Data dataNasc;
	Data dataAtual;
	char nome[30];
	char sexo;
	char rg[11], cpf[12];
	
	
}Pessoa;

typedef struct no{
	
	Pessoa pessoa;
	struct no *proximo;
	
}No;

void enqueue(No **fila, char nome[30], char rg[11],char cpf[12],int dia,int mes,int ano,int diaA, int mesA, int anoA, char sexo){
	
	int i=0;
	No *aux, *novo = malloc(sizeof(No));
	
	if(novo){
		novo->proximo = NULL;
		
		quanton++;
		for(i=0;i<=29;i++){
		novo->pessoa.nome[i]= nome[i];
		}
		
		for(i=0;i<=11;i++){
		novo->pessoa.rg[i]= rg[i];
		}
		
		for(i=0;i<=12;i++){
		novo->pessoa.cpf[i]= cpf[i];
		}
			novo->pessoa.dataNasc.dia = dia;
			novo->pessoa.dataNasc.mes = mes;
			novo->pessoa.dataNasc.ano = ano;
			
			novo->pessoa.dataAtual.dia = diaA;
			novo->pessoa.dataAtual.mes = mesA;
			novo->pessoa.dataAtual.ano = anoA;
			novo->pessoa.sexo = sexo ; 

		if(*fila==NULL){
			*fila = novo;
		}else{
			aux = *fila;
			while (aux->proximo){
				aux = aux->proximo;
			}
			aux->proximo = novo;
		}	
	}else
		printf("\n\nERRO AO ALOCAR MEMORIA\n\n");
}

No* dequeue (No **fila){
	
	No *remover = NULL;
	
	
	if(*fila){
		quanton--;
		remover = *fila;
		*fila = remover->proximo;
	}else
		printf("\n\n Fila vazia\n\n");
	
	return remover;
	
}

void imprimir(No *fila){
	
	printf("\n\t\t-------- Minha Fila ---------");
	while(fila){
		
		printf("\n\t\t\tNome:%s",fila->pessoa.nome);
		printf("\n\n\t\t\tInformações\n\t\t\tRG: %s\n\t\t\tCPF: %s",fila->pessoa.rg, fila->pessoa.cpf);
		printf("\n\t\t\tData de Nascimento: %i/%i/%i", fila->pessoa.dataNasc.dia, fila->pessoa.dataNasc.mes, fila->pessoa.dataNasc.ano);
		printf("\n\t\t\tData atual: %i/%i/%i", fila->pessoa.dataAtual.dia, fila->pessoa.dataAtual.mes, fila->pessoa.dataAtual.ano);
		printf("\n\t\t\tSexo: %c\n\n", fila->pessoa.sexo);
	
		fila = fila->proximo;
	}	
	printf("\n\t\t-----------------------------");
	
}

void lerarq(No **fila){
	
	
	char rg[11], cpf[12]; 
	int dia, mes, ano, diaA, mesA, anoA;
	char nome[30];
	char sexo;
	
	int i=0, j=0;
	No *aux, *novo= malloc(sizeof(No));
	novo->proximo=NULL;
	
	FILE *arq = fopen("List.txt", "r");
	if(arq){
		aux = *fila;
		
		fscanf(arq, "%i\n", &quant);
		while(i<quant){
			i++;
		fgets(nome, 29, arq);
		fscanf(arq, "%s\n",&rg);
		fscanf(arq, "%s\n",&cpf);
		fscanf(arq, "%i/%i/%i\n", &dia, &mes, &ano);
		fscanf(arq, "%i/%i/%i\n", &diaA, &mesA, &anoA);
		fscanf(arq, "%c\n", &sexo);
		printf("\nDEU CERTO\n");
		enqueue(fila, nome,rg, cpf, dia, mes, ano, diaA, mesA, anoA,sexo);
		
		}
		printf("\n\n\tAquivo Salvo!\n\n");
		fclose(arq);
	}else{
		printf("\n\nERRO\n\n");
	}
}

void salvar(No *fila){
	
	int i;
	
	FILE *arq = fopen("List.txt", "w");
	if(arq){
		fprintf(arq, "%i\n", quanton);
		
		while(fila){
		fprintf(arq, "%s\n", fila->pessoa.nome);
		fprintf(arq, "%s\n%s\n",fila->pessoa.rg, fila->pessoa.cpf);
		fprintf(arq, "%i/%i/%i\n", fila->pessoa.dataNasc.dia, fila->pessoa.dataNasc.mes, fila->pessoa.dataNasc.ano);
		fprintf(arq, "%i/%i/%i\n", fila->pessoa.dataAtual.dia, fila->pessoa.dataAtual.mes, fila->pessoa.dataAtual.ano);
		fprintf(arq, "%c\n\n", fila->pessoa.sexo);
	
		
		fila = fila->proximo;
	}
		printf("\n\n\tAquivo Salvo!\n\n");
		fclose(arq);
	}else{
		printf("\n\nERRO\n\n");
	}
}

void preencher(No **fila){
	
	char rg[11], cpf[12]; 
	int dia, mes, ano, diaA, mesA, anoA;
	char nome[30];
	char sexo;
	
	system("color f5");
	printf("\n\nDigite o nome do cliente:\n\n\t\t\t>>>");
	scanf("%c");
	scanf("%29[^\n]", &nome);
	
	printf("\n\nDigite a data de nascimento:\n\n\t\t\t>>>");
	scanf("%i/%i/%i",&dia, &mes, &ano);
	
	printf("\n\nDigite a data atual:\n\n\t\t\t>>>");
	scanf("%i/%i/%i",&diaA, &mesA, &anoA);
	
	
	printf("\n\nDigite m para masculino e f para feminino:\n\n\t\t\t>>>");
	scanf(" %c", &sexo);
	scanf("%c");
	
	printf("\n\nDigite seu cpf:\n\n\t\t\t>>>");
	scanf("%12[^\n]", &cpf);
	scanf("%c");
	
	printf("\n\nDigite seu rg:\n\n\t\t\t>>>");
	scanf("%11[^\n]", &rg);
	
	
	system("cls");
	
	enqueue(fila, nome,rg, cpf, dia, mes, ano, diaA, mesA, anoA,sexo);
	
}


int main(void){
	
	setlocale(LC_ALL,"Portuguese");
	
	No *r, *fila = NULL;
	int opcao=0, Opcao;
	
	do{
		system("color 1f");
	 	printf("\n\nDigite uma opcao:");
	 	printf("\n1- Enfilerar:");
	 	printf("\n2- Imprimir:");
	 	printf("\n3- desenfilerar:");
	 	printf("\n4- Salvar:");
	 	printf("\n5- Ler Arquivo:");
	 	printf("\n6- Sair:\n\n\t\t\t>>>");
		scanf("%i", &opcao);
	 	system("cls");
	 	
	 	switch(opcao){
	 		
	 		case 1:
	 			preencher(&fila);
	 			
	 		break;
	 		
	 		case 2:
	 			
				imprimir(fila);	
	 		break;
	 		
	 		case 3:
	 			
				r = dequeue(&fila);
	 		break;
	 		
	 		case 4:
	 			salvar(fila);
	 		break;
	 		
	 		case 5:
	 			lerarq(&fila);
	 		break;
		 }
	}while(opcao!=6);
	
	
	
	
	return 0;
}
