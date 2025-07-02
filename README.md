# Sistema de Controle Financeiro Pessoal

## Descrição

Este projeto consiste em um sistema digital de controle financeiro pessoal, desenvolvido em linguagem C, com funcionalidades evolutivas que permitem ao usuário registrar, organizar, visualizar e analisar receitas e despesas.

## Funcionalidades Principais

1. **Gerenciamento de Categorias**  
   - Cadastro, listagem e remoção de categorias de gastos e de receitas.  
2. **Lançamentos Financeiros**  
   - Inserção, edição e remoção de gastos.  
   - Inserção, edição e remoção de receitas.  
3. **Relatórios**  
   - Geração de relatórios de despesas e receitas por dia, mês e ano.  
4. **Autenticação de Usuário**  
   - Cadastro de usuários com armazenamento de hash de senha.  
   - Processo de login com tentativas limitadas.  

> **Observação:** os dados de usuários são armazenados no arquivo `usuarios.dat` no diretório de execução.

## Estrutura do Código

- **main.c** — Ponto de entrada e controle de fluxo principal.  
- **usuarios.dat** — Banco de dados binário para persistência de usuários.  
- **Módulos de Funções:**  
  - Menu e entrada de opções  
  - Gerenciamento de categorias (gastos e receitas)  
  - Inserção, edição e remoção de lançamentos  
  - Geração de relatórios financeiros  
  - Autenticação e criptografia simples de senhas  

## Como Utilizar

1. Ao iniciar, carregue o arquivo de usuários (`usuarios.dat`).  
2. Caso não existam usuários, cadastre o primeiro usuário.  
3. Realize o login utilizando nome de usuário e senha.  
4. Navegue pelo menu principal para gerenciar categorias, lançamentos e relatórios.  
5. Para encerrar, selecione a opção **Sair** no menu principal.  
