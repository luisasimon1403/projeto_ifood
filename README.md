# Sistema de Delivery em Linguagem C --- IFood

Este projeto simula um sistema de delivery inspirado no iFood,
desenvolvido em linguagem C.\
Ele oferece funcionalidades completas para usuário, administrador,
carrinho de compras, pagamentos, gestão de estoque e um QR Code para pagamento via Pix.

## 👥 Integrantes do Grupo

-   Lorena Dalmagro
-   Luana Almeida
-   Luísa Diniz Simon
-   Maria Heloísa Nunes
-   Maria Rosa Brasileiro


## 📚 Bibliotecas Utilizadas

#include \<stdio.h\>\
#include \<stdlib.h\>\
#include \<string.h\>\
#include \<locale.h\>

## 🧩 Principais Funcionalidades e Como Acessá-las

### 1) Tela Inicial

Opções principais: - Entrar/Cadastrar - Restaurantes - Mercados (não
implementado) - Admin - Entregador (não implementado)

### 2) Módulo do Usuário

#### ✔ Cadastro

1.  Cadastro via número de celular\
2.  Código WhatsApp (simulado)\
3.  Cadastro de e-mail\
4.  Código por e-mail (simulado)\
5.  Nome, endereço, telefone e senha

#### ✔ Login

-   Usuário cadastrado\
-   Usuário pré-definido ("João")

#### ✔ Minha Conta

-   Ver informações\
-   Editar dados pessoais\
-   Editar endereço\
-   Editar contato\
-   Alterar senha\
-   Publicidade

### 3) Restaurantes

Restaurante padrão: **Chicken Friends**

### 4) Cardápio e Detalhes dos Produtos

-   Nome, descrição, preço e estoque\
-   Adicionar ao carrinho\
-   Ir ao carrinho

### 5) Carrinho de Compras

-   Listar itens\
-   Remover item\
-   Total automático\
-   Finalizar compra

### 6) Endereço de Entrega

-   Confirmar ou alterar antes do pagamento

### 7) Pagamentos

#### ✔ Cartão

#### ✔ Dinheiro

#### ✔ Pix com QR Code:

  @@@@@@@:..*=*@#:-@:@@@@@@@
  @=**+-@: :=:=  ++@:@-+**=@
  @*@@#-@: @#   -*:=:@-*@@+@
  @@@@@@@: *-*@@* *@:@@@@@@@
     ::  :   @@+..:-@::    :
  +---=#    # +#+   -:#--   
  @#  :+*+@-+--  # +   @#  #
  +    :+@@@*  --    ++   #*
  =         *@*   *@#:    =*
  =*@*   :@ *@+.::   @ @   :
  @@@@@@@ @--::*@*=  @@@@@@@
  @=##+-@:*  +#@@    @=#+#-@
  @*@@#-@: *:=+-:++* @*@#@-@
  @@@@@@@:   @+:=@   @@@@@@@

### 8) Status da Entrega

1.  Pedido recebido\
2.  Em preparação\
3.  Saiu para entrega\
4.  Entregue

### 9) Módulo Administrativo (ADM)

Usuário: admin\
Senha: 123

-   Ver cardápio\
-   Adicionar prato\
-   Editar prato\
-   Excluir prato\
-   Ajustar estoque

## 📦 Considerações Finais

Sistema completo utilizando funções, structs, vetores e menus
interativos.
