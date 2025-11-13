#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ---------------- DECLARACOES -----------
void pagina_inicial();
int le_valida_opcao_pagina_inicial();
void login_adm();
void pagina_restaurante();
void pagina_cardapio();
void pagina_entregas();
void pagina_usuario();
void cadastro_celular();
void codigo_whatsapp();
void cadastro_email();
void codigo_email();
void cadastro_final();
void login_usuario();
void usuario_livre();

// === Variaveis globais ===
char nomes_pratos[10][50];
int quantidades[10];
int total_pratos = 0;

// --- Dados do usuário ---
char celular_usuario[20];
char email_usuario[50];
char nome_usuario[50];
char endereco_usuario[100];
char numero_residencial[20];
char complemento_usuario[50];
char senha_usuario[20];
int codigo_whatsapp_enviado = 1234;
int codigo_email_enviado = 5678;
int codigo_digitado;
int usuario_cadastrado = 0; // 0 = não, 1 = sim

// Usuário fixo (para compatibilidade)
char usuario_fixo_nome[] = "Joao";
char usuario_fixo_email[] = "joao@email.com";
char usuario_fixo_senha[] = "1234";

// ------------ MAIN -------------
int main() {
    int opcao;

    do {
        pagina_inicial();
        opcao = le_valida_opcao_pagina_inicial();
        
        switch(opcao){
            case 1:
                printf("Pagina em construcao...\n");
                break;
            
            case 2:
                login_adm();
                break;
            
            case 3:
                pagina_usuario();
                break;
            
            case 4:
                printf("Pagina em construcao...\n");
                break;
            
            case 5:
                printf("Pagina em construcao...\n");
                break;
            
            default:    
                printf("Opcao invalida!\n");
        }
        
        system("pause");

    } while(1);
    
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

    strcpy(usuario_correto, "admin");
    strcpy(senha_correta, "123");

    do {
        system("cls");
        printf("=== LOGIN ADM ===\n");

        printf("\nUsuario: ");
        scanf("%s", usuario);
        printf("Senha: ");
        scanf("%s", senha);

        usuario_ok = strcmp(usuario, usuario_correto);
        senha_ok = strcmp(senha, senha_correta);

        if (usuario_ok == 0 && senha_ok == 0) {
            printf("\nLogin realizado com sucesso!\n");
            pagina_restaurante();
            return;
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

    } while (1);
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
                return;
            default:
                printf("\nOpcao invalida!\n");
                system("pause");
        }

    } while (1);
}

// ----------- PAGINA DO CARDAPIO ------------
void pagina_cardapio() {
    int opcao, i;

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
                printf("\nNome do prato: ");
                scanf(" %[^\n]", nomes_pratos[total_pratos]);

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
                for (i = 0; i < total_pratos; i++) {
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

// ----------- PAGINA USUARIO (ENTRAR / CADASTRAR) ------------
void pagina_usuario() {
    int opcao;

    do {
        system("cls");
        printf("=== USUARIO ===\n");
        printf("1 - Cadastrar novo usuario\n");
        printf("2 - Fazer login (usuario ja cadastrado)\n");
        printf("3 - Entrar como convidado\n");
        printf("4 - Voltar para pagina inicial\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            cadastro_celular();
            return;
        } 
        else if (opcao == 2) {
            login_usuario();
            return;
        } 
        else if (opcao == 3) {
            usuario_livre();
            return;
        } 
        else if (opcao == 4) {
            return;
        } 
        else {
            printf("Opcao invalida!\n");
            system("pause");
        }

    } while (1);
}

// ----------- CADASTRO (CELULAR -> WHATSAPP -> EMAIL -> NOME + DADOS) ------------
void cadastro_celular() {
    system("cls");
    printf("Digite o numero do celular: ");
    scanf("%s", celular_usuario);
    printf("\nCodigo enviado pelo WhatsApp (simulado: 1234)\n");
    codigo_whatsapp();
}

void codigo_whatsapp() {
    int tentativas = 0;

    do {
        printf("\nDigite o codigo recebido: ");
        scanf("%d", &codigo_digitado);

        if (codigo_digitado == codigo_whatsapp_enviado) {
            printf("\nCodigo correto!\n");
            cadastro_email();
            return;
        } else {
            printf("\nCodigo incorreto!\n");
            tentativas++;
        }

    } while (tentativas < 3);

    printf("\nFalha no cadastro. Voltando ao menu anterior...\n");
    system("pause");
}

void cadastro_email() {
    system("cls");
    printf("Digite o email: ");
    scanf("%s", email_usuario);
    printf("\nCodigo enviado ao email (simulado: 5678)\n");
    codigo_email();
}

void codigo_email() {
    int tentativas = 0;

    do {
        printf("\nDigite o codigo recebido: ");
        scanf("%d", &codigo_digitado);

        if (codigo_digitado == codigo_email_enviado) {
            printf("\nCodigo correto!\n");
            cadastro_final();
            return;
        } else {
            printf("\nCodigo incorreto!\n");
            tentativas++;
        }

    } while (tentativas < 3);

    printf("\nFalha no cadastro. Voltando ao menu anterior...\n");
    system("pause");
}

void cadastro_final() {
    char confirma_senha[20];
    int senhas_iguais;

    system("cls");
    printf("Digite o seu nome completo: ");
    scanf(" %[^\n]", nome_usuario);

    printf("Endereco: ");
    scanf(" %[^\n]", endereco_usuario);

    printf("Numero residencial: ");
    scanf(" %[^\n]", numero_residencial);

    printf("Complemento: ");
    scanf(" %[^\n]", complemento_usuario);

    do {
        printf("Senha: ");
        scanf("%s", senha_usuario);

        printf("Confirmar senha: ");
        scanf("%s", confirma_senha);

        senhas_iguais = strcmp(senha_usuario, confirma_senha);

        if (senhas_iguais != 0)
            printf("\nAs senhas nao conferem! Tente novamente.\n");

    } while (senhas_iguais != 0);

    usuario_cadastrado = 1;
    printf("\nCadastro concluido com sucesso!\n");
    printf("Nome: %s\nCelular: %s\nEmail: %s\n", nome_usuario, celular_usuario, email_usuario);
    system("pause");
}

// ----------- LOGIN USUARIO ------------
void login_usuario() {
    char email[50], senha[20];
    int email_ok, senha_ok;

    system("cls");
    printf("Email: ");
    scanf("%s", email);
    printf("Senha: ");
    scanf("%s", senha);

    if (usuario_cadastrado == 1 && strcmp(email, email_usuario) == 0 && strcmp(senha, senha_usuario) == 0) {
        printf("\nBem-vindo, %s!\n", nome_usuario);
    } else if (strcmp(email, usuario_fixo_email) == 0 && strcmp(senha, usuario_fixo_senha) == 0) {
        printf("\nBem-vindo, %s!\n", usuario_fixo_nome);
    } else {
        printf("\nEmail ou senha incorretos!\n");
    }

    system("pause");
}

// ----------- USUARIO LIVRE ------------
void usuario_livre() {
    system("cls");
    printf("Entrando como convidado...\n");
    printf("Bem-vindo ao iFood!\n");
    system("pause");
}
