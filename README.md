# projeto_ifood
📌 Descrição

Este projeto é uma simulação simplificada do sistema do iFood, desenvolvida em linguagem C.
O objetivo é representar, de forma didática, o funcionamento básico de um aplicativo de delivery, com menus, login de administrador e gerenciamento de cardápio.

O sistema foi criado para fins acadêmicos, com o intuito de praticar:

Estruturação de funções em C

Manipulação de strings e vetores

Uso de condicionais, laços e menus

Organização modular do código

🧩 Funcionalidades

🔹 Página Inicial
Exibe o menu principal com as opções:

Entregador (em construção)

Para empresas (login de administrador)

Entrar/Cadastrar (em construção)

Restaurantes (em construção)

Mercados (em construção)

🔹 Login do Administrador

Usuário: admin

Senha: 123
Após o login, o administrador acessa a área do restaurante.

🔹 Página do Restaurante (Chicken Friends)

Ver/Alterar Cardápio

Cadastrar novos pratos (máximo de 10)

Listar todos os pratos cadastrados

Ver Entregas

Exibe uma simulação de entregas (sem dados reais)

Sair da Conta

Retorna para a tela inicial

⚙️ Como Executar o Projeto

Abra o código em um compilador C (por exemplo, Code::Blocks, Dev-C++ ou VS Code).

Compile e execute o programa (main.c).

Navegue pelas opções do menu digitando os números correspondentes.

Para acessar o modo administrador:

Usuário: admin
Senha: 123

💡 Estrutura do Código

O programa é dividido em funções principais:

pagina_inicial() → Exibe o menu principal

le_valida_opcao_pagina_inicial() → Lê e valida a opção digitada

login_adm() → Faz o login do administrador

pagina_restaurante() → Mostra o painel do restaurante

pagina_cardapio() → Permite cadastrar e listar pratos

pagina_entregas() → Exibe as entregas simuladas

Além disso, há vetores globais para armazenar os pratos e suas quantidades.

🧠 Aprendizados Envolvidos

Modularização do código em funções

Manipulação de strings com strcpy() e strcmp()

Estruturas de repetição (do...while)

Estruturas condicionais (if, switch)

Entrada e saída de dados no console

👩‍💻 Autora

Luísa Diniz Simon
Projeto desenvolvido como prática acadêmica para aprimorar a lógica de programação e o uso de funções em C.
