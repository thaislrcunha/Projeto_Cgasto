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
/* Protótipos de orçamento */
void gerenciar_orcamentos(void); //ok
void definir_orcamento(void); //ok
void listar_orcamentos(void); //ok
void remover_orcamento(void); //ok

/*======================== GERENCIAR ORÇAMENTO ========================*/
/*
void gerenciar_orcamentos(void) {
    int op;
    do {
        printf("\n======= GERENCIAR ORÇAMENTOS MENSAIS ========\n");
        printf("1. Definir teto\n");
        printf("2. Listar tetos\n");
        printf("3. Remover teto\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &op);
        getchar();
        switch (op) {
            case 1: 
                definir_orcamento(); 
                break;
            case 2: 
                listar_orcamentos(); 
                break;
            case 3: 
                remover_orcamento(); 
                break;
            case 0: return;
            default: printf("Inválido!\n");
        }
    } while (1);
}

void definir_orcamento(void) {
    printf("\n...... Definir Orçamento ......\n");
    int cod, mes, ano;
    float teto;
    ORCAMENTO *o = &lista_orcamentos[n_orcamentos++];
    
    if (n_orcamentos >= MAX_ORCAMENTOS) { //verificar limite
        printf("Limite de orçamentos atingido.\n");
        return;
    }

    listar_categorias_gasto();

    do {
        printf("Código da categoria: ");
        scanf("%d", &cod);
        getchar();
    } while (cod<1 || cod>n_gastos);
    
    printf("Mês (1–12): ");
    scanf("%d", &mes); 
    getchar();
    printf("Ano (ex.: 2025): ");
    scanf("%d", &ano);
    getchar();

    printf("Teto de despesa (R$): ");
    scanf("%f", &teto);
    getchar();

    //Sobrescrever se existir
    for (int i = 0; i<n_orcamentos; i++) {
        ORCAMENTO *o = &lista_orcamentos[i];
        if (o->cod_cat==cod && o->mes==mes && o->ano==ano) {
            o->teto = teto;
            printf("Teto atualizado!\n");
            return;
        }
    }
    
    o->cod_cat = cod; 
    o->mes = mes; 
    o->ano = ano; 
    o->teto = teto;
    printf("Teto definido.\n");
}

void listar_orcamentos(void) {
    printf("\n...... Listar Orçamento ......\n");
    if (n_orcamentos==0) { //verificar
        printf("Nenhum teto definido.\n"); return;
    }
    printf("\n Mês/Ano  | Cód.Cat | Categoria         | Teto\n");
    printf("----------------------------------------------\n");
    for(int i=0;i<n_orcamentos;i++){
        ORCAMENTO *o=&lista_orcamentos[i];
        printf("%2d/%4d   | %7d  | %-16s | R$ %8.2f\n",o->mes, o->ano, o->cod_cat, cat_lista_gastos[o->cod_cat-1].nome_cat, o->teto);
    }
}

void remover_orcamento(void) {
    int i, mes, ano, cod, id=-1;
    printf("\n...... Listar Orçamento ......\n");
    
    if(n_orcamentos==0){
        printf("Nenhum teto para remover.\n"); 
        return;
    }
    
    printf("Mês: "); 
    scanf("%d",&mes); 
    getchar();

    printf("Ano: "); 
    scanf("%d",&ano); 
    getchar();

    printf("Código da categoria: ");
    scanf("%d",&cod);
    getchar();

    for(i=0;i<n_orcamentos;i++){
        ORCAMENTO *o=&lista_orcamentos[i];
        if(o->mes==mes&&o->ano==ano&&o->cod_cat==cod){
            id=i; 
            break;
        }
    }
    if(id<0){ 
        printf("Não encontrado!\n"); 
        return;
    }
    for(i=id;i<n_orcamentos-1;i++){
        lista_orcamentos[i] = lista_orcamentos[i+1];
    }
    n_orcamentos--;
    printf("Teto removido!\n");
}
*/