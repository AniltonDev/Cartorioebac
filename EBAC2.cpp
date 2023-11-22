#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por regição
#include <string.h> //biblioteca responável por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário sobre o cpf a ser cadastrado
	scanf("%s", cpf); //%s refere-se a string (salva na variavel cpf)
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo ("w" significa escrever)
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //abre e atualizar informação do arquivo
	fprintf(file,","); //salvar alteração com a virgula
	fclose(file); //fecho o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",nome); //%s refere-se a string (salva na variavel nome)
	
	file = fopen(arquivo, "a"); //abre e atualizar informação do arquivo
	fprintf(file,nome); //salvando o conteudo da variavel nome dentro do arquivo
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //abre e atualizar informação do arquivo
	fprintf(file,","); //salvar alteração com a virgula
	fclose(file); //fecho o arquivo
		
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",sobrenome); //%s refere-se a string (salva na variavel sobrenome)
	
	file = fopen(arquivo, "a"); //abre e atualizar informação do arquivo
	fprintf(file,sobrenome); //salvando o conteudo da variavel sobrenome dentro do arquivo
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //abre e atualizar informação do arquivo
	fprintf(file,","); //salvar alteração com a virgula
	fclose(file); //fecho o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",cargo); //%s refere-se a string (salva na variavel cargo)
	
	file = fopen(arquivo, "a"); //abre e atualizar informação do arquivo
	fprintf(file,cargo); //salvando o conteudo da variavel cargo dentro do arquivo
	fclose(file);//fecho o arquivo
		
	system("pause"); //pausa o sistema
	
}

int consulta() //Função responsavel por consultar os usuários no sistema
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
	
	char cpf[40]; 
	char conteudo[200];
	
	printf("Digite o CPF  a ser consultado: "); //coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a string (salva na variavel cpf)

	FILE *file; //acessa o arquivo
	file = fopen(cpf, "r"); //abre e lê a informação do arquivo
	
	if(file == NULL)
	{
	printf("Não foi possivel abrir o arquivo, não localizado!.\n");	
	}
	
	while(fgets(conteudo,200, file) != NULL) 
	{
	printf("\nEssas são as informações do usuário: ");
	printf("%s", conteudo); //%s refere-se a string (salva na variavel conteudo)
	printf("\n\n");
	}
	
	system("pause"); //pausa o sistema

}

int deletar() //Função responsavel por deletar os usuários do sistema
{
	char cpf[40];
	
	printf("Digitar o CPF do usuário a ser deletado: "); //coletando informação do usuário sobre o cpf a ser deletado
	scanf("%s",cpf); //%s refere-se a string (salva na variavel cpf)
	
	remove(cpf); //acessa a pasta e deleta o arquivo solicitado
	
	FILE *file; //acessa o arquivo
	file = fopen(cpf,"r"); //abre e lê a informação do arquivo
	
	if(file == NULL)
	{
	printf("O usuário não se encontra no sistema!.\n");
	system("pause"); //pausa o sistema	
	}
	
}



int main()//função principal
	{
		
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
		{
	
	system("cls"); //responsavel por limpar a tela
		
	setlocale(LC_ALL,"Portuguese"); //Definindo a Linguagem
	
		printf("#### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Resgitrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando as escolhas do usuário 
	
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //inicio da seleção do menu
			{
			case 1:
			registro(); //chamada de funções
			break; //Fim da seleção
			
			case 2:
  		  	consulta(); //chamada de funções
 			break; //Fim da seleção
		
			case 3:
    		deletar(); //chamada de funções
    		break; //Fim da seleção
		
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break; //Fim da seleção
			
	 		}
		}
	}
