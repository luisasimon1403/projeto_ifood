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
void pagina_horario(); // <---- nova função adicionada
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
int codigo_whatsapp_enviado = 1234;
int codigo_email_enviado = 5678;
int codigo_digitado;

// Usuário fixo (login pronto)
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
                login_adm(); // Login do administrador
                break;
            
            case 3:
                pagina_usuario(); // Login/Cadastro do usuário comum
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
        printf("3 - Alterar Horario de Funcionamento\n"); // <--- NOVA OPÇÃO
        printf("4 - Sair da conta\n");
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
                pagina_horario(); // <--- NOVA FUNÇÃO
                break;
            case 4:
                printf("\nSaindo da conta...\n");
                return;
            default:
                printf("\nOpcao invalida!\n");
                system("pause");
        }

    } while (1);
}

// ----------- NOVA FUNÇÃO: HORÁRIO DE FUNCIONAMENTO ------------
void pagina_horario() {
    static char horario_abertura[10] = "08:00";
    static char horario_fechamento[10] = "22:00";
    int opcao;

    do {
        system("cls");
        printf("=== HORARIO DE FUNCIONAMENTO ===\n");
        printf("Horario atual: %s - %s\n", horario_abertura, horario_fechamento);
        printf("\n1 - Alterar horario\n");
        printf("2 - Voltar\n");
        printf("\nEscolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("\nNovo horario de abertura (ex: 09:00): ");
            scanf("%s", horario_abertura);
            printf("Novo horario de fechamento (ex: 21:30): ");
            scanf("%s", horario_fechamento);
            printf("\nHorario atualizado com sucesso!\n");
            system("pause");
        } 
        else if (opcao == 2) {
            return;
        } 
        else {
            printf("Opcao invalida!\n");
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

// ----------- PAGINA USUARIO ------------
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

// ----------- CADASTRO (CELULAR -> WHATSAPP -> EMAIL -> NOME) ------------
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
    system("cls");
    printf("Digite o seu nome completo: ");
    scanf(" %[^\n]", nome_usuario);

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

    email_ok = strcmp(email, usuario_fixo_email);
    senha_ok = strcmp(senha, usuario_fixo_senha);

    if (email_ok == 0 && senha_ok == 0) {
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
