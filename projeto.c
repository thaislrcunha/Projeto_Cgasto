/* sistema digital de controle financeiro pessoal, 
com funcionalidades evolutivas que permitam registrar, 
organizar, visualizar e analisar receitas e despesas*/

#include <stdio.h>
#include <string.h>

/*-----------------------MENU------------------------



*/

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

/*---------------------------- MENU ----------------------------*/
void MENU(int m){
    printf("MENU: \n");
    printf("1. CATEGORIAS\n");
    printf("2. Inserir GASTO\n");
    printf("3. Inserir RECEITA\n");
    printf("4. Editar GASTO\n");
    printf("5. Editar RECEITA\n");
}

/*------------------------ CATEGORIAS ------------------------*/
void CATEGORIA(int a){
    int tcat;

    printf("Escolha a lista de categorias: \n");
    printf("1. Categoria de gastos\n");
    printf("2. Categoria de receitas\n");
    scanf("%d", tcat);

    //Categoria de gastos
    if(tcat == 1){

    }

    //Categoria de receitas
    if(tcat == 2){

    }
}

int main(){
    
   
    
    return 0;
}