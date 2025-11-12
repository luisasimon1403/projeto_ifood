#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//----------------DECLARACOES-----------
void pagina_inicial();
int le_valida_opcao_pagina_inicial();
void login_adm();
void pagina_restaurante();
void pagina_cardapio();
void pagina_entregas();

// === Variaveis globais ===
char nomes_pratos[10][50];
int quantidades[10];
int total_pratos = 0;

//------------MAIN-------------
int main() {
    int opcao;

    do {
        pagina_inicial();
        opcao = le_valida_opcao_pagina_inicial();
        
        switch(opcao){
            case 1:
                printf("Pagina em construcao...\n"); //Pagina do entregador (nao sera desenvolvida)
                break;
            
            case 2:
                login_adm(); // Login do administrador
                break;
            
            case 3:
                printf("Pagina em construcao...\n");// Pagina Entrar/Cadastrar
                break;
            
            case 4:
                printf("Pagina em construcao...\n"); // Restaurantes --> Pagina Entrar/Cadastrar
                break;
            
            case 5:
                printf("Pagina em construcao...\n");// Mercado --> Pagina Entrar/Cadastrar
                break;
            
            default:    
                printf("Opcao invalida!\n");
        }
        
        system("pause");

    } while(1); // repete sempre que voltar da outra pagina
    
    return 0;
}

// ----------- PAGINA INICIAL ------------
void pagina_inicial(){
    system("cls");
    printf("  IFOOD     (1)Entregador      (2)Para empresas        (3)Entrar/Cadastrar  ");
    printf("\n");
    printf("\n");
    printf("\n           Tudo para facilitar o seu dia a dia!");
    printf("\nO que voce precisa esta aqui. Peca e receba onde estiver.");
    printf("\n");
    printf("\n");
    printf("\n");                            
    printf("        (4) Restaurantes");
    printf("              (5) Mercados");
    printf("\n");
    printf("\n");
    printf("\n");
}

int le_valida_opcao_pagina_inicial(){
    int opcao;
    printf("Escolha uma das opcoes (1,2,3,4 ou 5): ");
    scanf("%d",&opcao);
    return opcao;
}

// ----------- LOGIN DO ADM ------------
void login_adm() {
    char usuario[20], senha[20];
    char usuario_correto[20];
    char senha_correta[20];
    int opcao;
    int usuario_ok, senha_ok;

    // Atribui os valores para as strings
    strcpy(usuario_correto, "admin");
    strcpy(senha_correta, "123");

    do {
        system("cls");
        printf("=== LOGIN ADM ===\n");

        printf("\nUsuario: ");
        scanf("%s", usuario);
        printf("Senha: ");
        scanf("%s", senha);

        // Compara o usuario digitado com o usuario definido no sistema
        usuario_ok = strcmp(usuario, usuario_correto);
        senha_ok = strcmp(senha, senha_correta);

        if (usuario_ok == 0 && senha_ok == 0) {
            printf("\nLogin realizado com sucesso!\n");
            pagina_restaurante();  // vai para a próxima página
            return; // volta pra página inicial ao sair do restaurante
        } 
        else {
            printf("\nUsuario ou senha incorretos!\n");
            printf("\nDeseja tentar novamente?\n");
            printf("1 - Sim\n");
            printf("2 - Voltar para a pagina inicial\n");
            printf("Escolha: ");
            scanf("%d", &opcao);

            if (opcao == 2) {
                printf("\nVoltando para a pagina inicial...\n");
                return;
            }
        }

    } while (1); // fica tentando até acertar ou escolher sair
}

// ----------- PAGINA DO RESTAURANTE ------------
void pagina_restaurante() {
    int opcao;

    do {
        system("cls");
        printf("=== PAGINA DO RESTAURANTE - CHICKEN FRIENDS ===\n");
        printf("1 - Ver/Alterar Cardapio\n");
        printf("2 - Ver Entregas\n");
        printf("3 - Sair da conta\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                pagina_cardapio();
                break;
            case 2:
                pagina_entregas();
                break;
            case 3:
                printf("\nSaindo da conta...\n");
                return; //  volta pro login_adm(), que volta pro main()
            default:
                printf("\nOpcao invalida!\n");
                system("pause");
        }

    } while (1);
}

// ----------- PAGINA DO CARDAPIO ------------
void pagina_cardapio() {
    int opcao;

    do {
        system("cls");
        printf("=== CARDAPIO - CHICKEN FRIENDS ===\n");
        printf("1 - Cadastrar prato\n");
        printf("2 - Listar pratos\n");
        printf("3 - Voltar\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (total_pratos < 10) {
                // leitura segura do nome (pula espaços em branco anteriores e limita 49 chars)
                printf("\nNome do prato: ");
                scanf(" %49[^\n]", nomes_pratos[total_pratos]);

                printf("Quantidade disponivel: ");
                scanf("%d", &quantidades[total_pratos]);

                total_pratos++;
                printf("\nPrato cadastrado com sucesso!\n");
            } else {
                printf("\nLimite de pratos atingido!\n");
            }
            system("pause");
        }
        else if (opcao == 2) {
            system("cls");
            printf("\n=== LISTA DE PRATOS ===\n");
            if (total_pratos == 0) {
                printf("Nenhum prato cadastrado ainda.\n");
            } else {
                for (int i = 0; i < total_pratos; i++) {
                    printf("%d - %s (Qtd: %d)\n", i + 1, nomes_pratos[i], quantidades[i]);
                }
            }
            system("pause");
        }
        else if (opcao == 3) {
            printf("\nVoltando ao menu anterior...\n");
            system("pause");
            return;
        }
        else {
            printf("\nOpcao invalida!\n");
            system("pause");
        }

    } while (1);
}


// ----------- PAGINA DE ENTREGAS ------------
void pagina_entregas() {
    system("cls");
    printf("=== ENTREGAS - CHICKEN FRIENDS ===\n");
    printf("\n(Simulacao - Nenhuma entrega no momento)\n\n");
    system("pause");
}
