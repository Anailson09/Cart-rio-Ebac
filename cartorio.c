#include <stdio.h> // biblioteca de comunica�ao do usuario
#include <stdlib.h> // biblioteca de aloca��o de espa�o em memoria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o 
#include <string.h> // biblioteca responsavel por cuidar das strings

int registro() //fun��o responsavel por cadastrar os usuarios no sistema

{
    // inicio da cria��o das variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o das variaveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informa��o do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file), // fecha o arquivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
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
	
    system("pause"); // pausa a tela para o usuario

 
}

 int consulta() // fun��o repsonsavel pela consulta das informa��es do usuario

{
  setlocale (LC_ALL, "portuguese"); // definindo a linguagem
 
 
 //inicio da cria��a das variaveis/strings
 char cpf[40];
 char conteudo [200];
 
 printf("digite o cpf a ser consultado: ");
 scanf("%s",cpf);
 
 FILE *file;
 file = fopen(cpf,"r");
 
 if(file == NULL)
 
 {
 	printf("n�o foi possivel abrir o arquivo, n�o localizado!\n");
 }
 
 while(fgets(conteudo, 200, file) != NULL)
 
 {
 	printf("\nEssas s�o as informa��es do usuario: ");
 	printf("%s", conteudo);
 	printf("\n\n");
 	
 }

  system("pause");
  
 
}

 int deletar()

{
	 
	 char cpf[40];
	 
	 printf ("digite o cpf do usu�rio a ser deletado: ");
	 scanf ("%s", cpf); 
	 remove(cpf);
	 
	 
	 FILE *file;
	 file = fopen(cpf,"r");
	
	if (file == NULL)

	
{
	printf("O usu�rio n�o se encontra no sistema!\n");
	system("pause");
}


}


	



 int main () 
{
 
  int opcao=0; //definindo variaveis 
  int laco=1;
  
  for(laco=1;laco=1;) 
 { 
 
 
 setlocale (LC_ALL, "portuguese"); //definindo a linguagem 
 
 system("cls"); // responsavel por limpar a tela
 
 printf ("### Cart�rio da EBAC ### \n\n"); //inicio do menu
 printf ("Escolha a op��o desejada do menu:\n\n");
 printf("\t1 - registrar nomes\n");
 printf("\t2 - consultar nomes\n");
 printf("\t3 - deletar nomes\n\n");
 printf("\t4- sair do sistema\n\n");
 printf("opcao: ");//fim do menu
 
 scanf("%d", &opcao); //armazenando a escolha de usuario
 
 system("cls");
    
 switch(opcao)   // inicio da sele��o do menu
 {
 case 1:
 registro();
 break;	
   	
 case 2:
 consulta();
 break;
   	
 case 3:
 deletar();
 break;
   	
   	case 4:
   	printf("obrigado por utilizar o sistema!\n");
    return 0;
    break;
   	
 default:
 printf("essa opcao nao esta disponivel!\n");
 system("pause");
 break;
 } // fim da sele��o
}
   	
   
}

