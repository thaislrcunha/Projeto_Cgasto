/* Sistema digital de controle financeiro pessoal, 
com funcionalidades evolutivas que permitam registrar, 
organizar, visualizar e analisar receitas e despesas

Autores:    Isabella Rodrigues Mendonça - 202501289
            Júlia Oliveira Almeida - 202402810
            Ana Vitória Silva da Luz Nascimento - 202006547
            Thais Lima Rodrigues da Cunha - 202500849
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CATS 100 //limite de categorias
#define MAX_LANCAMENTOS 1000  // limite de lançamentos
#define MAX_ORCAMENTOS (MAX_CATS * 12) // MAX_ORCAMENTOS deve ser > número de categorias × meses previstos

/* Protótipos das funções */
void exibir_menu(void); //ok
int ler_opcao(void); //ok
void gerenciar_categorias(void); //ok
void inserir_gasto(void); //ok
void inserir_receita(void); //ok
void editar_gasto(void); //ok
void editar_receita(void); //ok
void remover_gasto(void); //ok
void remover_receita(void); //ok
/* Protótipos de categoria de gastos */
void submenu_categorias_gastos(void); //OK
void adicionar_categoria_gasto(void); //OK
void listar_categorias_gasto(void); //OK
void remover_categoria_gasto(void); //OK
/* Protótipos de categoria de receita */
void submenu_categorias_receita(void); //OK
void adicionar_categoria_receita(void); //OK
void listar_categorias_receita(void); //OK
void remover_categoria_receita(void); //OK
/* Protótipos de relatórios */
void menu_relatorios(void); //ok
void relatorio_despesas(void); //ok 
void relatorio_receita(void); //ok

/*======================== MENU ========================*/
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
    printf("6. Remover Gasto\n");
    printf("7. Remover Receita\n");
    printf("8. Relatórios\n");
    printf("0. Sair\n");
    printf("-------------------------------------\n");
    printf("Escolha uma opção: (Escreva apenas o número da opção)\n");
}

int ler_opcao(void) { //Lê a opção escolhida pelo usuário
    int opc;
    scanf("%d", &opc);
    if (opc >= 0 && opc <= 8)
        return opc;
    else  return -1; // Opção inválida
}

/*---------------- estrutura dos dados ----------------*/
typedef struct{ //categoria de gastos: lista criada pelo usuário
    int cod;
    char nome_cat[50];
} CATEGORIA_GASTOS;
typedef struct{ //dados de gastos 
    int cod_cat;
    char data[11];
    float valor;
} GASTOS;
typedef struct{ //categorias de entrada: lista criada pelo usuário
    int cod;
    char nome_origem[50];
} CATEGORIA_RECEITA;
typedef struct{ //dados de entrada
    int cod_cat;
    char data[11];
    float valor;
} RECEITA;
typedef struct { // orçamento mensal por categoria
    int   cod_cat;
    int   mes;
    int   ano;
    float teto;
} ORCAMENTO;


/*Vetores de categorias*/
CATEGORIA_GASTOS  cat_lista_gastos[MAX_CATS];
CATEGORIA_RECEITA cat_lista_receita[MAX_CATS];

/*Contadores de categorias*/
int n_gastos  = 0;
int n_receita = 0;
/* Vetor de lançamentos de gastos e contador */
GASTOS lista_gastos[MAX_LANCAMENTOS];
int n_reg_gastos = 0;
/* Vetor global e contador para receitas */
RECEITA lista_receita[MAX_LANCAMENTOS];
int n_reg_receita = 0;
/* Vetor global e contador para orçamentos */
ORCAMENTO lista_orcamentos[MAX_ORCAMENTOS];
int      n_orcamentos = 0;

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
        getchar(); 

        switch (tipo) {
            case 1:
                submenu_categorias_gastos();
                break;
            case 2:
                submenu_categorias_receita();
                break;
            case 0:
                return;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (1);
}

/*-------------------------- GASTOS  --------------------------*/
void submenu_categorias_gastos(void) { //Menu para categorias de GASTOS
    int opc;
    do{
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
            default: printf("Opção inválida!\n");
        }
    } while (1);
}

void adicionar_categoria_gasto(void) { //adicionar categoria de gastos
    if(n_gastos >= MAX_CATS) { //verificar se há espaço
        printf("Limite de categorias atingido.\n");
        return;
    }
    printf("\n...... Adicionar Categoria de Gastos ......\n");

    CATEGORIA_GASTOS *c = &cat_lista_gastos[n_gastos]; //C é um Ponteiro para a próxima posição livre
    c->cod = n_gastos + 1; //pega o campo cod apontada por c, cria o novo código

    printf("Nome da nova categoria de gasto: ");
    scanf("%49[^\n]", c->nome_cat);  // lê até o '\n', incluindo espaços
    getchar();  // descarta o '\n' que ficou em stdin

    n_gastos++;

    printf("Categoria adicionada com código %d.\n", c->cod);
}

void listar_categorias_gasto(void) { //listar categoria de gastos
    int i;
    if(n_gastos == 0) {
        printf("\nNenhuma categoria cadastrada!\n");
        return;
    }
    printf("\n...... Listar Categorias ......\n");
    printf("\nCódigo  | Categoria de Gasto\n");
    printf("-----------------------------\n");
    for(i=0; i < n_gastos; i++) {
        printf("%6d  | %s\n", cat_lista_gastos[i].cod, cat_lista_gastos[i].nome_cat);
    }
}

void remover_categoria_gasto(void) { //remover categoria de gastos
    int codigo, id = -1, i;
    printf("\n...... Remover Categoria de Receita ......\n");
    listar_categorias_gasto();  // mostra ao usuário os códigos disponíveis
    printf("\nInforme o CÓDIGO da categoria que deseja remover: ");
    scanf("%d", &codigo);
    getchar();

    for(i=0; i < n_gastos; i++) {
        if (cat_lista_gastos[i].cod == codigo) {
            id = i;
            break;
        }
    }
    if(id<0) {
        printf("Categoria não encontrada.\n");
        return;
    }
    
    for(i = id; i < n_gastos - 1; i++) { //desloca os elementos após retirada
        cat_lista_gastos[i] = cat_lista_gastos[i + 1];
        cat_lista_gastos[i].cod = i + 1;
    }
    n_gastos--;
    printf("Categoria removida!\n");
}

/*------------------------- RECEITA  -------------------------*/
void submenu_categorias_receita(void) { //Menu para categorias de receita
    int opc;
    do {
        printf("\n------ Categorias de Receita -------\n");
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
            default: printf("Opção inválida!\n");
        }
    } while (1);
}

void adicionar_categoria_receita(void) { // adicionar categoria de receita
    if(n_receita >= MAX_CATS) { // verificar se há espaço
        printf("Limite de categorias de receita atingido.\n");
        return;
    }
    printf("\n...... Adicionar Categoria de Receita ......\n");

    CATEGORIA_RECEITA *c = &cat_lista_receita[n_receita]; 
    c->cod = n_receita + 1;                          

    printf("Nome da nova categoria de receita: ");
    scanf(" %49[^\n]", c->nome_origem); 
    getchar();                        

    n_receita++;                        
    printf("Categoria de receita adicionada com código %d.\n", c->cod);
}

void listar_categorias_receita(void) { // listar categorias de receita
    int i;
    if(n_receita == 0) {
        printf("Nenhuma categoria de receita cadastrada.\n");
        return;
    }
    printf("\n...... Listar Categorias de Receita ......\n");
    printf("\nCódigo  | Categoria de Receita\n");
    printf("------------------------------\n");
    for(i=0; i < n_receita; i++) {
        printf("%6d  | %s\n", cat_lista_receita[i].cod, cat_lista_receita[i].nome_origem);
    }
}

void remover_categoria_receita(void) { // remover categoria de receita
    int codigo, id = -1, i;
    printf("\n...... Remover Categoria de Receita ......\n");
    listar_categorias_receita();  // mostra ao usuário os códigos disponíveis
    printf("\nInforme o CÓDIGO da categoria que deseja remover: ");
    scanf("%d", &codigo);
    getchar();

    for(i=0; i < n_receita; i++) {
        if(cat_lista_receita[i].cod == codigo) {
            id = i;
            break;
        }
    }
    if(id < 0) {
        printf("Código %d não encontrado. Nenhuma categoria removida.\n", codigo);
        return;
    }

    for(i=id; i < n_receita - 1; i++) {
        cat_lista_receita[i] = cat_lista_receita[i + 1];
        cat_lista_receita[i].cod = i + 1; 
    }
    n_receita--;
    printf("Categoria de receita com CÓDIGO %d removida com sucesso.\n", codigo);
}

/*======================== GERENCIAR DADOS ========================*/
/*-------------------------- GASTOS --------------------------*/
void inserir_gasto(void) {
    int cod_cat, dia, mes, ano, dj, mj, aj;
    char data[11];
    float valor, soma = 0.0f;
    GASTOS *g = &lista_gastos[n_reg_gastos]; // armazenamento

    printf("\n...... Adicionar Gasto ......\n");

    if (n_reg_gastos >= MAX_LANCAMENTOS) { // vê se há espaço
        printf("Limite de lançamentos de gastos atingido.\n");
        return;
    }

    if (n_gastos == 0) { // há catetorias?
        printf("Não há categorias de gasto cadastradas.\n");
        printf("Cadastre pelo menos uma antes de inserir lançamentos.\n");
        return;
    }

    listar_categorias_gasto(); // mostrar lista

    do {
        printf("\nDigite o CÓDIGO da categoria para este gasto: ");
        scanf("%d", &cod_cat);
        getchar();
        if (cod_cat < 1 || cod_cat > n_gastos) {
            printf("Código inválido. Tente novamente.\n");
        }
    } while (cod_cat < 1 || cod_cat > n_gastos);

    printf("Data (dd/mm/aaaa): "); // lê DATA
    scanf("%10s", data);
    getchar();

    printf("Valor (R$): "); //lê VALOR
    scanf("%f", &valor);
    getchar();

    // armazenar
    g->cod_cat = cod_cat;
    strcpy(g->data, data);
    g->valor = valor;
    n_reg_gastos++;

    // feedback
    printf("\nGasto cadastrado com sucesso!\n");
    printf("  Categoria [%d] – %s\n", cod_cat, cat_lista_gastos[cod_cat-1].nome_cat);
    printf("  Data: %s   Valor: R$ %.2f\n", g->data, g->valor);
}

void editar_gasto(void) {
    int id, opc, nova_cat, i;
    char nova_data[11];
    float novo_valor;
    GASTOS *g = &lista_gastos[id - 1];

    printf("\n...... Editar Gasto ......\n");
    
    if (n_reg_gastos == 0) { //verificar se há registros
        printf("\n>> Não há nenhum gasto cadastrado para editar.\n");
        return;
    }

    // listagem dos gastos
    printf("\n::: Lista de Gastos Cadastrados :::\n");
    printf("Id | Cód.Cat | Categoria               | Data       | Valor\n");
    printf("---------------------------------------------------------------\n");
    for (i=0; i < n_reg_gastos; i++) {
        GASTOS *g = &lista_gastos[i];
        printf("%3d | %7d  | %-22s | %10s | R$ %8.2f\n", i + 1, g->cod_cat, cat_lista_gastos[g->cod_cat - 1].nome_cat, g->data, g->valor);
    }
    
    printf("\nDigite o índice (Id) do gasto que deseja editar: ");
    scanf("%d", &id);
    getchar();
    if (id < 1 || id > n_reg_gastos) {
        printf("Índice inválido!\n");
        return;
    }
    
    //Submenu de edição
    do {
        printf("\n::: Editar Gasto [%d] :::\n", id);
        printf("1. Categoria (atual: %d – %s)\n", g->cod_cat, cat_lista_gastos[g->cod_cat - 1].nome_cat);
        printf("2. Data (atual: %s)\n", g->data);
        printf("3. Valor (atual: R$ %.2f)\n", g->valor);
        printf("0. Sair do editor\n");
        printf("Escolha o campo para editar: ");
        scanf("%d", &opc);
        getchar();

        switch (opc) {
            case 1: { //Editar categoria
                listar_categorias_gasto();
                do {
                    printf("Novo CÓDIGO de categoria: ");
                    scanf("%d", &nova_cat);
                    getchar();
                    if (nova_cat < 1 || nova_cat > n_gastos) {
                        printf("Código inválido! Tente novamente.\n");
                    }
                } while (nova_cat < 1 || nova_cat > n_gastos);
                g->cod_cat = nova_cat;
                printf("Categoria atualizada para [%d] – %s\n",
                       g->cod_cat,
                       cat_lista_gastos[g->cod_cat - 1].nome_cat);
                break;
            }
            case 2: { //Editar data
                printf("Nova data (dd/mm/aaaa): ");
                scanf("%10s", nova_data);
                getchar();
                strncpy(g->data, nova_data, sizeof(g->data));
                g->data[10] = '\0';  // segurança
                printf("Data atualizada para %s\n", g->data);
                break;
            }
            case 3: { //Editar valor
                printf("Novo valor (R$): ");
                scanf("%f", &novo_valor);
                getchar();
                g->valor = novo_valor;
                printf("Valor atualizado para R$ %.2f\n", g->valor);
                break;
            }
            case 0:
                printf("Saindo do editor de gastos.\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opc != 0);
}

void remover_gasto(void) {
    int i, indice;

    printf("\n...... Remover Gasto ......\n");
    if (n_reg_gastos == 0) { // há algo para remover?
        printf("\n>> Não há nenhum gasto para remover.\n");
        return;
    }

    //Lista todos os lançamentos com índice
    printf("\n::: Gastos Cadastrados :::\n");
    printf("Id | Cód.Cat | Categoria               | Data       | Valor\n");
    printf("---------------------------------------------------------------\n");
    for (i=0; i < n_reg_gastos; i++) {
        GASTOS *g = &lista_gastos[i];
        printf("%3d | %7d  | %-22s | %10s | R$ %8.2f\n", i+1, g->cod_cat, cat_lista_gastos[g->cod_cat-1].nome_cat, g->data, g->valor);
    }

    printf("\nDigite o índice (1 a %d) do gasto que deseja remover: ", n_reg_gastos);
    scanf("%d", &indice);
    getchar(); 

    if (indice<1 || indice>n_reg_gastos) { //verificar o indice
        printf("Índice inválido! Nenhum gasto removido.\n");
        return;
    }

    // reorganiza a lista
    for (i = indice-1; i < n_reg_gastos-1; i++) {
        lista_gastos[i] = lista_gastos[i+1];
    }
    n_reg_gastos--;

    printf("Gasto de índice %d removido com sucesso!\n", indice);
}

/*-------------------------- RECEITA --------------------------*/
void inserir_receita(void) {
    int cod_cat;
    char data[11];
    float valor;

    printf("\n...... Adicionar Receita ......\n");

    if (n_reg_receita >= MAX_LANCAMENTOS) {
        printf("Limite de lançamentos de receita atingido.\n");
        return;
    }

    if (n_receita == 0) {
        printf("Não há categorias de receita cadastradas.\n");
        printf("Cadastre pelo menos uma antes de inserir lançamentos.\n");
        return;
    }

    listar_categorias_receita();

    do {
        printf("\nDigite o CÓDIGO da categoria para esta receita: ");
        scanf("%d", &cod_cat);
        getchar();  // consome o '\n'
        if (cod_cat < 1 || cod_cat > n_receita) {
            printf("Código inválido. Tente novamente.\n");
        }
    } while (cod_cat < 1 || cod_cat > n_receita);

    printf("Data (dd/mm/aaaa): ");
    scanf("%10s", data);
    getchar();

    printf("Valor (R$): ");
    scanf("%f", &valor);
    getchar();

    RECEITA *r = &lista_receita[n_reg_receita];
    r->cod_cat = cod_cat;
    strcpy(r->data, data);
    r->valor = valor;
    n_reg_receita++;

    printf("\nReceita cadastrada com sucesso!\n");
    printf("  Categoria [%d] – %s\n",
           cod_cat, cat_lista_receita[cod_cat-1].nome_origem);
    printf("  Data: %s   Valor: R$ %.2f\n",
           r->data, r->valor);
}

void editar_receita(void) {
    int i, indice, opc, nova_cat;
    char nova_data[11];
    float novo_valor;
    RECEITA *r;

    if (n_reg_receita == 0) {
        printf("\n>> Não há nenhuma receita cadastrada para editar.\n");
        return;
    }

    printf("\n::: Receitas Cadastradas :::\n");
    printf("Id | Cód.Cat | Categoria de Receita     | Data       | Valor\n");
    printf("---------------------------------------------------------------\n");
    for (i = 0; i < n_reg_receita; i++) {
        r = &lista_receita[i];
        printf("%3d | %7d  | %-22s | %10s | R$ %8.2f\n", i + 1, r->cod_cat, cat_lista_receita[r->cod_cat - 1].nome_origem, r->data, r->valor);
    }

    printf("\nDigite o índice (1 a %d) da receita que deseja editar: ", n_reg_receita);
    scanf("%d", &indice);
    getchar();
    if (indice < 1 || indice > n_reg_receita) {
        printf("Índice inválido!\n");
        return;
    }
    r = &lista_receita[indice-1];

    //Submenu de edição
    do {
        printf("\n::: Editar Receita [%d] :::\n", indice);
        printf("1. Categoria (atual: %d – %s)\n", r->cod_cat, cat_lista_receita[r->cod_cat - 1].nome_origem);
        printf("2. Data      (atual: %s)\n", r->data);
        printf("3. Valor     (atual: R$ %.2f)\n", r->valor);
        printf("0. Sair do editor\n");
        printf("Escolha o campo para editar: ");
        scanf("%d", &opc);
        getchar();

        switch (opc) {
            case 1: //categoria
                listar_categorias_receita();
                do {
                    printf("Novo CÓDIGO de categoria: ");
                    scanf("%d", &nova_cat);
                    getchar();
                    if (nova_cat < 1 || nova_cat > n_receita) {
                        printf("Código inválido. Tente novamente.\n");
                    }
                } while (nova_cat < 1 || nova_cat > n_receita);
                r->cod_cat = nova_cat;
                printf("Categoria atualizada para [%d] – %s\n",
                       r->cod_cat,
                       cat_lista_receita[r->cod_cat - 1].nome_origem);
                break;

            case 2: //data
                printf("Nova data (dd/mm/aaaa): ");
                scanf("%10s", nova_data);
                getchar();
                strncpy(r->data, nova_data, sizeof(r->data));
                r->data[10] = '\0';
                printf("Data atualizada para %s\n", r->data);
                break;

            case 3: //valor
                printf("Novo valor (R$): ");
                scanf("%f", &novo_valor);
                getchar();
                r->valor = novo_valor;
                printf("Valor atualizado para R$ %.2f\n", r->valor);
                break;

            case 0:
                printf("Saindo do editor de receitas.\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opc != 0);
}

void remover_receita(void) {
    int i, indice;

    printf("\n...... Remover Receita ......\n");
    if (n_reg_receita == 0) {
        printf("\n>> Não há nenhuma receita para remover.\n");
        return;
    }

    printf("\n::: Receitas Cadastradas :::\n");
    printf("Id | Cód.Cat | Categoria de Receita     | Data       | Valor\n");
    printf("---------------------------------------------------------------\n");
    for (i = 0; i < n_reg_receita; i++) {
        RECEITA *r = &lista_receita[i];
        printf("%3d | %7d  | %-22s | %10s | R$ %8.2f\n", i+1, r->cod_cat, cat_lista_gastos[r->cod_cat-1].nome_cat, r->data, r->valor);
    }

    printf("\nDigite o índice (1 a %d) da receita que deseja remover: ", n_reg_receita);
    scanf("%d", &indice);
    getchar(); 

    if (indice < 1 || indice > n_reg_receita) { 
        printf("Índice inválido! Nenhuma receita removida.\n");
        return;
    }

    for (i = indice-1; i < n_reg_receita-1; i++) {
        lista_receita[i] = lista_receita[i + 1];
    }
    n_reg_receita--;

    printf("Receita de índice %d removida com sucesso!\n", indice);
}

/*============================= RELATÓRIOS =============================*/
void menu_relatorios(void) {
    int op;
    do {
        printf("\n======= GERENCIAR RELATÓRIOS ========\n");
        printf("1. Relatorio de despesas\n");
        printf("2. Relatorios de receita\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &op);
        getchar();
        switch (op) {
            case 1: 
                relatorio_despesas(); 
                break;
            case 2: 
                relatorio_receita(); 
                break;
            case 0: return;
            default: printf("Inválido!\n");
        }
    } while (1);
}

void relatorio_despesas(void){
    int r, i, cod;
    char data[11], mes_ano[8], ano_reg[5];
    float soma_dia=0, soma_mes=0, soma_ano=0;

    if(n_reg_gastos == 0){
        printf("\nNenhum gasto registrado!\n");
        printf("Insira gastos para o relatório!\n");
        return;
    }

    printf("\n...... Relatório de Gastos ......\n");
    printf("Tipo de relatório: \n");
    printf(" 1. Relatório por dia\n 2. Relatório por mês\n 3. Relatório por ano\n 0. Voltar\n");
    printf("Digite o tipo de relatório desejado: \n");
    scanf("%d", &r);

    switch(r){
        case 0: 
            return;

        case 1: //diário
            printf("Digite a data (dd/mm/aaaa): ");
            scanf("%10s", data);
            getchar();

            printf("\n...... Lista de Gastos Diário ......\n");
            printf("\nCategoria            | Valor R$\n");
            printf("------------------------------\n");
            for (i=0; i < n_reg_gastos; i++) {
               if(strcmp(lista_gastos[i].data, data)==0){
                    printf("");
                    cod = lista_gastos[i].cod_cat;
                    printf("%s | R$ %7.2f\n", cat_lista_gastos[cod-1].nome_cat, lista_gastos[i].valor);
                    soma_dia += lista_gastos[i].valor;
               }
            }
            printf("-----------------------------------\n");
            printf("TOTAL DIÁRIO: R$%.2f", soma_dia);
            break;

        case 2: //mensal
            printf("Digite o mês (mm/aaaa): ");
            scanf("%7s", data);
            getchar();

            printf("\n...... Lista de Gastos do Mês ......\n");
            printf("\nCategoria            | Valor R$\n");
            printf("-------------------------------\n");

            soma_mes = 0;
            for(i=0; i<n_reg_gastos; i++) {
                strncpy(mes_ano, lista_gastos[i].data+3, 7);
                mes_ano[7] = '\0';
                if (strcmp(mes_ano, data) == 0) {
                    cod = lista_gastos[i].cod_cat;
                    printf("%-20s | R$ %7.2f\n", cat_lista_gastos[cod-1].nome_cat, lista_gastos[i].valor);
                    soma_mes += lista_gastos[i].valor;
                }
            }
            printf("---------------------------------\n");
            printf("TOTAL MENSAL: R$ %.2f\n", soma_mes);
            break;

        case 3: //anual
            printf("Digite o ano (aaaa): ");
            scanf("%4s", data);
            getchar();

            printf("\n...... Lista de Gastos do Ano ......\n");
            printf("\nCategoria            | Valor R$\n");
            printf("-----------------------------------\n");

            soma_ano = 0;
            for (i=0; i<n_reg_gastos; i++) {
                strncpy(ano_reg, lista_gastos[i].data + 6, 4);
                ano_reg[4] = '\0';

                if(strcmp(ano_reg, data) == 0) {
                    cod = lista_gastos[i].cod_cat;
                    printf("%-20s | R$ %7.2f\n", cat_lista_gastos[cod-1].nome_cat, lista_gastos[i].valor);
                    soma_ano += lista_gastos[i].valor;
                }
            }
            printf("------------------------------\n");
            printf("TOTAL ANUAL: R$ %.2f\n", soma_ano);
            break;

        default: printf("Opção inválida!\n");
            break;
    }
} 

void relatorio_receita(void){
    int r, i, cod;
    char data[11], mes_ano[8], ano_reg[5];
    float soma_dia = 0, soma_mes = 0, soma_ano = 0;

    if (n_reg_receita==0) {
        printf("\nNenhuma receita registrada!\n");
        printf("Insira receitas para o relatório!\n");
        return;
    }

    printf("\n...... Relatório de Receitas ......\n");
    printf("Tipo de relatório:\n");
    printf(" 1. Relatório por dia\n");
    printf(" 2. Relatório por mês\n");
    printf(" 3. Relatório por ano\n");
    printf(" 0. Voltar\n");
    printf("Digite o tipo de relatório desejado: ");
    scanf("%d", &r);
    getchar();

    switch(r){
        case 0:
            return;

        case 1: //diário
            printf("Digite a data (dd/mm/aaaa): ");
            scanf("%10s", data);
            getchar();

            printf("\n...... Lista de Receitas Diário ......\n");
            printf("\nCategoria de Receita  | Valor R$\n");
            printf("-----------------------------------\n");
            soma_dia = 0;

            for (i=0; i<n_reg_receita; i++) {
                if(strcmp(lista_receita[i].data, data) == 0){
                    cod = lista_receita[i].cod_cat;
                    printf("%-20s | R$ %7.2f\n", cat_lista_receita[cod - 1].nome_origem, lista_receita[i].valor);
                    soma_dia += lista_receita[i].valor;
                }
            }
            printf("-----------------------------------\n");
            printf("TOTAL DIÁRIO: R$ %.2f\n", soma_dia);
            break;

        case 2:  //mensal
            printf("Digite o mês (mm/aaaa): ");
            scanf("%7s", data);
            getchar();

            printf("\n...... Lista de Receitas do Mês ......\n");
            printf("\nCategoria de Receita  | Valor R$\n");
            printf("---------------------------------\n");
            soma_mes = 0;

            for (i=0; i<n_reg_receita; i++) {
                strncpy(mes_ano, lista_receita[i].data + 3, 7);
                mes_ano[7] = '\0';

                if (strcmp(mes_ano, data) == 0) {
                    cod = lista_receita[i].cod_cat;
                    printf("%-20s | R$ %7.2f\n", cat_lista_receita[cod-1].nome_origem, lista_receita[i].valor);
                    soma_mes += lista_receita[i].valor;
                }
            }
            printf("---------------------------------\n");
            printf("TOTAL MENSAL: R$ %.2f\n", soma_mes);
            break;

        case 3: //anual
            printf("Digite o ano (aaaa): ");
            scanf("%4s", data);
            getchar();

            printf("\n...... Lista de Receitas do Ano ......\n");
            printf("\nCategoria de Receita  | Valor R$\n");
            printf("---------------------------------\n");
            soma_ano = 0;

            for (i=0; i < n_reg_receita; i++) {
                strncpy(ano_reg, lista_receita[i].data+6, 4);
                ano_reg[4] = '\0';

                if(strcmp(ano_reg, data) == 0){
                    cod = lista_receita[i].cod_cat;
                    printf("%-20s | R$ %7.2f\n", cat_lista_receita[cod-1].nome_origem, lista_receita[i].valor);
                    soma_ano += lista_receita[i].valor;
                }
            }
            printf("--------------------------------------\n");
            printf("TOTAL ANUAL: R$ %.2f\n", soma_ano);
            break;

        default:
            printf("Opção inválida!\n");
            break;
    }
}


/*======================== PRINCIPAL ========================*/
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
            case 6:
                remover_gasto();
                break;
            case 7:
                remover_receita();
                break;
            case 8:
                menu_relatorios();
                break;
            case 0:
                printf("\nEncerrando o sistema. Até logo!\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }

        printf("\n"); 
    } while (opcao != 0);

    return 0;
}