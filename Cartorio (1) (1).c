#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espaço de mem�ria
#include <locale.h> //bibliotecas de aloca��o de textos por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //fun��o resp�nsavel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/string
	char arquivo[40];
    char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //% referente o string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores dos strings
	
	FILE *file; //cria o arquivo e o"w"significa escrever
	file = fopen(arquivo,"w"); //cria o arquivo
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //abriu o arquivo com a de atualiza��o
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
    	printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
	}

    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\Essas s�o as informa��es do usu�rio: ");
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

    printf("O usu�rio n�o existe!\n");
    system("pause");

   } 
  else 

   {

    fclose(file); // Fecha o arquivo, pois ele existe

    remove(cpf); // Agora voc� pode remover o arquivo

    printf("Usu�rio deletado!\n");
    system("pause");

   }
}

int main() 
{
	int opcao=0; //Definindo Vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
		system ("cls"); //Respons�vel por limpara a tela
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
	    printf("###Cart�rio da Ebac###\n\n"); //In�cio do menu
	    printf("Escolha a opc�o desejada do menu:\n\n"); 
	    printf("\t1-Registrar nomes\n");
	    printf("\t2-Consultar nomes\n");
	    printf("\t3-Deletar nomes\n\n"); //Final do menu
	    printf("Op��o: ");

        scanf("%d", &opcao); //Armazenando a escolha do usu�rio
   
        system("cls");
        
        switch(opcao) //in�cio da sele��o do menu
        {
        	case 1:
        	registro(); //chamada de fun��es
   		    break;
   		    
   		    case 2:
   		    consulta();
	    	break;
	    	
	    	case 3:
   		    deleta();
	    	break;
	    	
	    	default:
	    	printf("Essa op��o n�o est� disponivel!\n");
		    system("pause");
		    break;
		}
   	
    } //fim da sele��o
	   
}
