NILTON


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct cadastro { //struct para armazenar usuários e senhas.
    char user[20]; //Variável tipo char que armazena usuários.
    char pass[20]; //
    char login[20];
    char senha[20];
} cadastro;

int main(void)
{
	char *cadastro_login(); 
	char *cadastro_senha();
	char *buscarLivro();
	int logo();	
	
	
    int a,b,c,d,nc;
    int logado;
    int op;
    char login[1][20], senha[1][20];
    struct cadastro logando[3];
	
	logo();
	
    printf("\t\t1 - FAZER CADASTRO\n\n");
    printf("\t\t2 - FAZER LOGIN E CONTINUAR COM SUA RESERVA.\n\n");
    printf("\t\t3 - VOLTAR A PAGINA DE BUSCA.\n\n");
    printf("\t\t4 - SAIR DO SISTEMA.\n\n");
	scanf("%d", &op);
    /*
	inicio de uma estrutura de decisão: CADASTRAR USUÁRIO, 
	LOGAR NO SISTEMA OU VOLTAR A BUSCA DE LIVROS.	
	*/
    
    
    if (op == 1) {
        printf("\nDigite o numero de usuarios que deseja cadastrar.: \n");
        scanf("%d",&nc);
        for (a=0;a<nc;a++){
            memcpy(logando[a].user, cadastro_login(), 50);
            memcpy(logando[a].pass, cadastro_senha(), 50);
        }
    }else if (op == 3){
		exit(0);//buscarLivro(); //Voltar para a pagina de buscac.
    }else if (op == 4){
		exit(0); //Sai do Sistema.
	}
	
	system("cls");
    printf("\n\tLogon\n");
    printf("\n\tLogin: ");	
    scanf(" %s",login[0]);
    printf("\n\tSenha: ");
    scanf(" %s",senha[0]);
	

    for (c=0;c<3;c++)
    {
        if ((strcmp(login[0],logando[c].user)!=0) || (strcmp(senha[0],logando[c].pass)!=0))
        {
            logado = 1; //login e/ou senha incorretos            
        }
        else if(strcmp(login[0],logando[c].user)==0)
        {
            if (strcmp(senha[0],logando[c].pass)==0)
            {
                logado = 2; //logado com sucesso
                break;
            }

        }
    }

    if (logado==1)
    {
        printf("\nLogin e/ou senha incorretos(s)\n");
        system("pause");
        system("cls");
		main();
		
    }
    else if (logado==2)
    {
        printf("\nLogado com sucesso!\nBem-vindo(a) %s\n",login[0]);
    }

    return 0;
}


char *cadastro_login()
{
    struct cadastro usuario[1];

    system("cls");
    printf("\n\tCadastro");
    puts("\n\n\tDigite o login: ");
    printf("\t");
    scanf(" %[^\n]s",usuario[0].user);
    return (usuario[0].user);
}

char *cadastro_senha()
{
    struct cadastro password[1];

    puts("\tDigite a senha: ");
    printf("\t");
    scanf(" %s",password[0].pass);
    system("cls");
    return (password[0].pass);
}

int logo(){
	
	//int data = __DATE__;
	
	//printf("%c", data);
	printf("\n*---------BIBLIOTECA VIRTUAL---------*\n\n\n");
	printf("Seja bem vindo\t\tESCOLHA UMA OPCAO\t\t\t\n");

}

