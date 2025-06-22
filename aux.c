/* sistema digital de controle financeiro pessoal, 
com funcionalidades evolutivas que permitam registrar, 
organizar, visualizar e analisar receitas e despesas*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CATS 100

/* Protótipos das funções de cada módulo */
void exibir_menu(void); //ok
int ler_opcao(void);
void gerenciar_categorias(void);
void inserir_gasto(void);
void inserir_receita(void);
void editar_gasto(void);
void editar_receita(void);

/*-----------------------MENU------------------------
/* Exibe as opções disponíveis no sistema */
void exibir_menu(void) {
    printf("=====================================\n");
    printf(" Sistema de Controle Financeiro\n");
    printf("=====================================\n");
    printf("============== MENU =================\n");
    printf("1. Gerenciar Categorias\n");
    printf("2. Inserir Gasto\n");
    printf("3. Inserir Receita\n");
    printf("4. Editar Gasto\n");
    printf("5. Editar Receita\n");
    printf("0. Sair\n");
    printf("-------------------------------------\n");
    printf("Escolha uma opção: (Escreva apenas o número da opção)\n");
}

/* Lê a opção escolhida pelo usuário*/
int ler_opcao(void) {
    int opc;
    scanf("%d", &opc);
    if (opc >= 0 && opc <= 5)
        return opc;
    else  return -1; // Opção inválida
}

/*---------------- estrutura dos dados ----------------*/
typedef struct{ //categoria de gastos: lista criada pelo usuário
    int cod;
    char nome_cat[50];
} CATEGORIA_GASTOS;
typedef struct{ //dados de gastos 
    CATEGORIA_GASTOS cat[100];
    char data[11];
    float valor;
} GASTOS;
typedef struct{ //categorias de entrada: lista criada pelo usuário
    int cod;
    char nome_origem[50];
} CATEGORIA_RECEITA;
typedef struct{ //dados de entrada
    CATEGORIA_RECEITA cat[100];
    char data[11];
    float valor;
} RECEITA;

/* Vetores de categorias */
CATEGORIA_GASTOS  lista_gastos[MAX_CATS];
CATEGORIA_RECEITA lista_receita[MAX_CATS];

/* Contadores de quantas categorias já existem */
int n_gastos  = 0;
int n_receita = 0;

/*======================== CATEGORIAS ========================*/
void gerenciar_categorias(void) { //Gerenciamento de categorias
    int tipo;
    do {
        printf("\n======= GERENCIAR CATEGORIAS ========\n");
        printf("1. Categorias de Gasto\n");
        printf("2. Categorias de Receita\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha o tipo de categoria: ");
        scanf("%d", &tipo);
        getchar();  // descarta '\n'

        switch (tipo) {
            case 1:
                categorias_gastos();
                break;
            case 2:
                categorias_receita();
                break;
            case 0:
                return;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (1);
}

/*-------------------------- GASTOS  --------------------------*/
void submenu_categorias_gastos(void) { //Submenu para categorias de GASTOS
    int opc;
    do {
        printf("\n------- Categorias de Gasto --------\n");
        printf("1. Adicionar\n");
        printf("2. Listar\n");
        printf("3. Remover\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opc);
        getchar();

        switch (opc) {
            case 1: adicionar_categoria_gasto(); break;
            case 2: listar_categorias_gasto();  break;
            case 3: remover_categoria_gasto();  break;
            case 0: return;
            default: printf("Opção inválida.\n");
        }
    } while (1);
}

void adicionar_categoria_gasto(void) {
    CATEGORIA_GASTOS  lista_gastos[MAX_CATS];
    if (n_gastos >= MAX_CATS) { //verificar se há espaço
        printf("Limite de categorias atingido.\n");
        return;
    }

    CATEGORIA_GASTOS *c = &lista_gastos[n_gastos]; //C é um Ponteiro para a próxima posição livre

    c->cod = n_gastos + 1; //pega o campo cod apontada por c

    printf("Nome da nova categoria de gasto: ");
    fgets(c->nome_cat, sizeof(c->nome_cat), stdin);
    c->nome_cat[strcspn(c->nome_cat, "\n")] = '\0';

    /* Atualiza contador */
    n_gastos++;

    printf("Categoria adicionada com código %d.\n", c->cod);
}

/*------------------------- RECEITA  -------------------------*/
void submenu_categorias_receita(void) { //Submenu para categorias de receita
    int opc;
    do {
        printf("\n-- Categorias de Receita --\n");
        printf("1. Adicionar\n");
        printf("2. Listar\n");
        printf("3. Remover\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opc);
        getchar();

        switch (opc) {
            case 1: adicionar_categoria_receita(); break;
            case 2: listar_categorias_receita();  break;
            case 3: remover_categoria_receita();  break;
            case 0: return;
            default: printf("Opção inválida.\n");
        }
    } while (1);
}

void adicionar_categoria_receita(void) {
    CATEGORIA_RECEITA lista_receita[MAX_CATS];
    if (n_receita >= MAX_CATS) {
        printf("Limite de categorias atingido.\n");
        return;
    }
    CATEGORIA_RECEITA *c = &lista_receita[n_receita];
    c->cod = n_receita + 1;
    printf("Nome da nova categoria de receita: ");
    fgets(c->nome_origem, sizeof(c->nome_origem), stdin);
    c->nome_origem[strcspn(c->nome_origem, "\n")] = '\0';
    n_receita++;
    printf("Categoria de receita adicionada com código %d.\n", c->cod);
}









void inserir_gasto(void) {
    // lógica para inserir um novo gasto
    printf(">> Módulo de inserção de gasto\n");
}

void inserir_receita(void) {
    // lógica para inserir uma nova receita
    printf(">> Módulo de inserção de receita\n");
}

void editar_gasto(void) {
    // lógica para editar dados de um gasto já cadastrado
    printf(">> Módulo de edição de gasto\n");
}

void editar_receita(void) {
    // lógica para editar dados de uma receita já cadastrada
    printf(">> Módulo de edição de receita\n");
}

/* Implementação do menu principal */
int main(void) {
    int opcao;
    do {
        exibir_menu();
        opcao = ler_opcao();

        switch (opcao) {
            case 1:
                gerenciar_categorias();
                break;
            case 2:
                inserir_gasto();
                break;
            case 3:
                inserir_receita();
                break;
            case 4:
                editar_gasto();
                break;
            case 5:
                editar_receita();
                break;
            case 0:
                printf("\nEncerrando o sistema. Até logo!\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
                break;
        }

        printf("\n"); 
    } while (opcao != 0);

    return 0;
}