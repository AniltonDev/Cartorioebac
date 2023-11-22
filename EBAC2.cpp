#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi��o
#include <string.h> //biblioteca respon�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio sobre o cpf a ser cadastrado
	scanf("%s", cpf); //%s refere-se a string (salva na variavel cpf)
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo ("w" significa escrever)
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //abre e atualizar informa��o do arquivo
	fprintf(file,","); //salvar altera��o com a virgula
	fclose(file); //fecho o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",nome); //%s refere-se a string (salva na variavel nome)
	
	file = fopen(arquivo, "a"); //abre e atualizar informa��o do arquivo
	fprintf(file,nome); //salvando o conteudo da variavel nome dentro do arquivo
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //abre e atualizar informa��o do arquivo
	fprintf(file,","); //salvar altera��o com a virgula
	fclose(file); //fecho o arquivo
		
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",sobrenome); //%s refere-se a string (salva na variavel sobrenome)
	
	file = fopen(arquivo, "a"); //abre e atualizar informa��o do arquivo
	fprintf(file,sobrenome); //salvando o conteudo da variavel sobrenome dentro do arquivo
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //abre e atualizar informa��o do arquivo
	fprintf(file,","); //salvar altera��o com a virgula
	fclose(file); //fecho o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cargo); //%s refere-se a string (salva na variavel cargo)
	
	file = fopen(arquivo, "a"); //abre e atualizar informa��o do arquivo
	fprintf(file,cargo); //salvando o conteudo da variavel cargo dentro do arquivo
	fclose(file);//fecho o arquivo
		
	system("pause"); //pausa o sistema
	
}

int consulta() //Fun��o responsavel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
	
	char cpf[40]; 
	char conteudo[200];
	
	printf("Digite o CPF  a ser consultado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string (salva na variavel cpf)

	FILE *file; //acessa o arquivo
	file = fopen(cpf, "r"); //abre e l� a informa��o do arquivo
	
	if(file == NULL)
	{
	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");	
	}
	
	while(fgets(conteudo,200, file) != NULL) 
	{
	printf("\nEssas s�o as informa��es do usu�rio: ");
	printf("%s", conteudo); //%s refere-se a string (salva na variavel conteudo)
	printf("\n\n");
	}
	
	system("pause"); //pausa o sistema

}

int deletar() //Fun��o responsavel por deletar os usu�rios do sistema
{
	char cpf[40];
	
	printf("Digitar o CPF do usu�rio a ser deletado: "); //coletando informa��o do usu�rio sobre o cpf a ser deletado
	scanf("%s",cpf); //%s refere-se a string (salva na variavel cpf)
	
	remove(cpf); //acessa a pasta e deleta o arquivo solicitado
	
	FILE *file; //acessa o arquivo
	file = fopen(cpf,"r"); //abre e l� a informa��o do arquivo
	
	if(file == NULL)
	{
	printf("O usu�rio n�o se encontra no sistema!.\n");
	system("pause"); //pausa o sistema	
	}
	
}



int main()//fun��o principal
	{
		
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
		{
	
	system("cls"); //responsavel por limpar a tela
		
	setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
	
		printf("#### Cart�rio da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Resgitrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando as escolhas do usu�rio 
	
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //inicio da sele��o do menu
			{
			case 1:
			registro(); //chamada de fun��es
			break; //Fim da sele��o
			
			case 2:
  		  	consulta(); //chamada de fun��es
 			break; //Fim da sele��o
		
			case 3:
    		deletar(); //chamada de fun��es
    		break; //Fim da sele��o
		
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break; //Fim da sele��o
			
	 		}
		}
	}
