#include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 #include <locale.h>

int main()
{
    int opcao = 0;
    int quantidade = 0;
    
    
    float valor_total = 0;
    float valor_limpeza = 0;
    float valor_padaria = 0;
    
    
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\tSeja BEM-VINDO ao Mercadinhoshop\n");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    system("pause");
    
    do{
        printf("Selecione a opcao desejada: \n\n");
        printf("01 - Acessar venda de Limpeza\n");
        printf("02 - Acessar venda de Materias\n");
        scanf("%d", &opcao);
    } while( opcao !=5 );
    
    return 0;
}