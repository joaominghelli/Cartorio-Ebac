#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em mémoria
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsavel pelas strings


int registro()//função responsavel por cadastrar os usuários
{
	setlocale(LC_ALL, "Portuguese");//Definindo o idioma
	//inicio da criação das strings/variaveis
	char arquivo[50];
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
		//final da criação das strings/variaveis

	printf("Você escolheu registrar um usuário!\n\n");//coletando informações do usuario
	printf("Digite o CPF que deseja cadastrar: ");
	scanf("%s", cpf);//%s refere-se as strings
	
	strcpy(arquivo, cpf);//responsavel por copiar os valores das strings
	
	FILE *file;//cria o arquivo 
	file = fopen(arquivo, "w");//a função "w" é a função que escreve 
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
    
    printf("Você escolheu a consulta de usuários!\n\n");
    printf("Digite o CPF que deseja consultar: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
	{
    	printf("Usuário não localizado!\n");
	}

    while(fgets(conteudo,200,file) != NULL)
	{
		printf("\nEssas são as informações do usuário: \n");
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
	
	printf("Digite o CPF do usuário que deseja deletar: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema\n");
		system("pause");
	}
	else
	{
		fclose(file);
		remove(cpf);
		printf("Usuário deletado com sucesso!\n");
		system("pause");
	}
}


int main()
{
	int opcao=0;//Definindo as variáveis
	
	setlocale(LC_ALL, "Portuguese");//Definindo o idioma
	int laco=1;
	char senhadigitada[10]="a";
	printf("### Cartório da EBAC ### \n\n");
	printf("Login de adminitrador!\n\nDigite a senha: ");
	scanf("%s",senhadigitada);	
	
	if(senhadigitada[10]="admin")
	{
		
	
	
	    for(laco=1;laco=1;)
    	{
	
    	    system("cls");//Comando para ocultor as informções de console
	
	        printf("### Cartório da EBAC ### \n\n");//Inicio do menu
	        printf("Escolha a opção desejada no menu: \n\n");
    	    printf("\t1 - Registrar nomes\n");
            printf("\t2 - Consultar nomes\n");
	        printf("\t3 - Deletar nomes\n");
	        printf("\t4 - Sair do sistema\n\n");
	        printf("Opção: ");//Fim do menu
	 
	        scanf("%d", &opcao);//Armazenamtendo de informções de escolhas do usuario
	        system("cls");
	
	        switch(opcao)//Opções de escolha do usuario
	        { 
	    	    case 1:
			    registro();//reponsavel por chamar a função
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
			    printf("Essa opção não está disponivel!\n\n");
	    	    system("pause");
	    	    break;//Fim das escolhas do usuario
	        }
	    } 
    }
    else
        printf("senha incorreta!\n");
}  

