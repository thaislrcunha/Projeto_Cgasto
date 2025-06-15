/* sistema digital de controle financeiro pessoal, 
com funcionalidades evolutivas que permitam registrar, 
organizar, visualizar e analisar receitas e despesas*/

#include <stdio.h>
#include <string.h>

/*-----------------------MENU------------------------



*/

//categoria de gastos: lista criada pelo usuário
typedef struct{
    int cod;
    char nome_cat[50];
} CATEGORIA_GASTOS;

//dados de gastos
typedef struct{
    CATEGORIA_GASTOS cat[100];
    char data[11];
    float valor;
} GASTOS;

//categorias de entrada: lista criada pelo usuário
typedef struct{
    int cod;
    char nome_origem[50];
} CATEGORIA_RECEITA;

//dados de entrada
typedef struct{
    CATEGORIA_RECEITA cat[100];
    char data[11];
    float valor;
} RECEITA;


int main(){

    return 0;
}