#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaÃ§o de memória
#include <locale.h> //bibliotecas de alocação de textos por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //função respónsavel por cadastrar os usuários no sistema
{
	//início criação de variáveis/string
	char arquivo[40];
    char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //% referente o string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores dos strings
	
	FILE *file; //cria o arquivo e o"w"significa escrever
	file = fopen(arquivo,"w"); //cria o arquivo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //abriu o arquivo com a de atualização
	fprintf(file,",");
	fclose(file);
	
	printf("Digite um nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
	system("pause");
	
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese");
    
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o cpf a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("Não foi possível abrir o arquivo, não localizado!.\n");
	}

    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\Essas são as informações do usuário: ");
    	printf("%s", conteudo);
    	printf("\n\n");
	}
    
    system("pause");
    
}

int deleta()
{

    char cpf[40];

    setlocale(LC_ALL,"portuguese");

    printf("Digite o CPF a ser deletado: ");
    scanf("%s",cpf);

    remove(cpf);

    FILE *file;
    file = fopen(cpf, "r"); // Tenta abrir o arquivo para leitura

    if (file == NULL) 

   {

    printf("O usuário não existe!\n");
    system("pause");

   } 
  else 

   {

    fclose(file); // Fecha o arquivo, pois ele existe

    remove(cpf); // Agora você pode remover o arquivo

    printf("Usuário deletado!\n");
    system("pause");

   }
}

int main() 
{
	int opcao=0; //Definindo Variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
		system ("cls"); //Responsável por limpara a tela
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
	    printf("###Cartório da Ebac###\n\n"); //Início do menu
	    printf("Escolha a opcão desejada do menu:\n\n"); 
	    printf("\t1-Registrar nomes\n");
	    printf("\t2-Consultar nomes\n");
	    printf("\t3-Deletar nomes\n\n"); //Final do menu
	    printf("Opção: ");

        scanf("%d", &opcao); //Armazenando a escolha do usuário
   
        system("cls");
        
        switch(opcao) //início da seleção do menu
        {
        	case 1:
        	registro(); //chamada de funções
   		    break;
   		    
   		    case 2:
   		    consulta();
	    	break;
	    	
	    	case 3:
   		    deleta();
	    	break;
	    	
	    	default:
	    	printf("Essa opção não está disponivel!\n");
		    system("pause");
		    break;
		}
   	
    } //fim da seleção
	   
}
