#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar de strings

int registrar() //Função para inserir novo registro
{	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Copiar cpf para arquivo.
	
	FILE *file; //cria um arquivo
	file = fopen(arquivo, "w"); //cria arquivo com nome da variavel arquivo com "w" de write.
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
		
	system("pause");
	
}

int consultar() //Função para consultar os dados de um registro
{
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // recuperar os dados do arquivo que entrará em conteudo, pra mostrar ao usuário
	{
		printf("\nEssas são as informações do usuário:\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	
	
	system("pause");
	
}
int deletar() //Função para deletar um registro
{	
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
	} else {
		remove(cpf);
		printf("Deletado com sucesso!\n");
	}
	
	system("pause");
}

int main()
{
	//Definição das variáveis
	int opcao=0; 
	int i=1;
	
	setlocale(LC_ALL, "Portuguese");
	
    for(i=1;i=1;)
	{
    	system("cls");
		printf("### Cartório da EBAC ###\n\n"); //Inicio menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair\n\n");
		printf("Opção: "); //Fim menu
		
		scanf("%d", &opcao); //Armazena escolha
		system("cls");
		
		switch(opcao) //Inicio da seleção
		{
			case 1:
				registrar();
			break;
			case 2:
				consultar();
			break;
			case 3:
				deletar();
			break;
			case 4:
				printf("Obrigado por utilizar o sistema!");
				return 0;
				break;
			default:
				printf("Essa opção não está disponível!\n");
				system("pause");
			break;
		} //Fim da seleção
		
		printf("Esse Software é de livre uso dos alunos\n");
	
    }
}
