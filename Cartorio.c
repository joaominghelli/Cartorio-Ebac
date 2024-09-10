#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em m�moria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h>//biblioteca responsavel pelas strings


int registro()//fun��o responsavel por cadastrar os usu�rios
{
	setlocale(LC_ALL, "Portuguese");//Definindo o idioma
	//inicio da cria��o das strings/variaveis
	char arquivo[50];
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
		//final da cria��o das strings/variaveis

	printf("Voc� escolheu registrar um usu�rio!\n\n");//coletando informa��es do usuario
	printf("Digite o CPF que deseja cadastrar: ");
	scanf("%s", cpf);//%s refere-se as strings
	
	strcpy(arquivo, cpf);//responsavel por copiar os valores das strings
	
	FILE *file;//cria o arquivo 
	file = fopen(arquivo, "w");//a fun��o "w" � a fun��o que escreve 
	fprintf(file,cpf);//salvo a variavel
	fclose(file);//fechar o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo,"a");
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
	
	file = fopen(arquivo,"a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese");//Definindo o idioma
	
	char cpf[50];
    char conteudo[200];
    
    printf("Voc� escolheu a consulta de usu�rios!\n\n");
    printf("Digite o CPF que deseja consultar: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
	{
    	printf("Usu�rio n�o localizado!\n");
	}

    while(fgets(conteudo,200,file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
    fclose(file);
	system("pause");  

}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");//Definindo o idioma
    
	char cpf[50];
	
	printf("Digite o CPF do usu�rio que deseja deletar: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema\n");
		system("pause");
	}
	else
	{
		fclose(file);
		remove(cpf);
		printf("Usu�rio deletado com sucesso!\n");
		system("pause");
	}
}


int main()
{
	int opcao=0;//Definindo as vari�veis
	
	setlocale(LC_ALL, "Portuguese");//Definindo o idioma
	int laco=1;
	char senhadigitada[10]="a";
	printf("### Cart�rio da EBAC ### \n\n");
	printf("Login de adminitrador!\n\nDigite a senha: ");
	scanf("%s",senhadigitada);	
	
	if(senhadigitada[10]="admin")
	{
		
	
	
	    for(laco=1;laco=1;)
    	{
	
    	    system("cls");//Comando para ocultor as inform��es de console
	
	        printf("### Cart�rio da EBAC ### \n\n");//Inicio do menu
	        printf("Escolha a op��o desejada no menu: \n\n");
    	    printf("\t1 - Registrar nomes\n");
            printf("\t2 - Consultar nomes\n");
	        printf("\t3 - Deletar nomes\n");
	        printf("\t4 - Sair do sistema\n\n");
	        printf("Op��o: ");//Fim do menu
	 
	        scanf("%d", &opcao);//Armazenamtendo de inform��es de escolhas do usuario
	        system("cls");
	
	        switch(opcao)//Op��es de escolha do usuario
	        { 
	    	    case 1:
			    registro();//reponsavel por chamar a fun��o
		        break;
		    
		        case 2:
		        consulta();
	    	    break;
	    	
	    	    case 3:
	    	    deletar();
			    break;
			
			    case 4:
			    printf("Obrigado por utilizar o sistema!\n");
				return 0;
			    break;	
			
			    default:
			    printf("Essa op��o n�o est� disponivel!\n\n");
	    	    system("pause");
	    	    break;//Fim das escolhas do usuario
	        }
	    } 
    }
    else
        printf("senha incorreta!\n");
}  

