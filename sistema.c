#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída. Já vem nos arquivos do compilador em C, nesse caso estou usando o MinGW (via MSYS2) ).
#include <stdlib.h> //Inclui a biblioteca padrão de manupipulação e alocação de memórias (nesse sistema usado para o cls(clean) e system(pause)).

// --- DEFINIMOS AS CONSTANTES. Aqui é onde ficaram os preços no sistema.
// --- LIMPEZA
#define DETERGENTE_IPE 4.99
#define SABAO_PO_1KG 14.00
#define ESPONJA 4.99
#define AMACIANTE_2L 12.50
#define DESINFETANTE_1L 8.90
#define AGUA_SANITARIA_1L 4.50
#define LIMPADOR_MULTIUSO 6.20
#define RODO_MADEIRA 15.00
#define VASSOURA_PELO 18.90
#define PANO_DE_CHAO 5.50
//-- ALIMENTOS
#define ARROZ_5KG 24.90
#define FEIJAO_CARIOCA_1KG 7.50
#define OLEO_DE_SOJA 6.90
#define MACARRAO_ESPAGUETE 4.20
#define CAFE_TORRADO_500G 18.50
#define ACUCAR_REFINADO_1KG 4.80
#define SAL_REFINADO_1KG 2.50
#define FARINHA_DE_TRIGO_1KG 5.30
#define MOLHO_DE_TOMATE 2.99
#define BISCOITO_RECHEADO 3.50
//--- PADARIA
#define PAO_FRANCES_KG 14.90
#define PAO_DE_QUEIJO_100G 4.50
#define BOLO_CENOURA_FATIA 6.00
#define SONHO_DE_CREME 5.50
#define COXINHA_FRANGO 7.00
#define CAFE_EXPRESSO 4.00
#define PAO_DOCE 3.50
#define TORTA_FRANGO_FATIA 8.50
#define POTATO 12.00
#define ENROLADINHO_SALSICHA 6.50

int main(){ // Inicio do Sistema, inicia um main do tipo inteiro.

// --- ESPAÇO PARA DECLAÇÃO DE VARIAVÉL do tipo INTEIRO.
// Declara a variavél inicial em 0 para limpar o lixo do sistema.
    int opcao = 0; //Variavel armazena a escolha do usuario no menu principal e nos sub-menus, usada para direcionar o fluxo do sistema.
    int codigo = 0; //Variavel armazena o codigo do produto selecionado pelo usuario nos sub-menus, usada para identificar o produto escolhido e calcular os subtotais.
    int quantidade = 0; //Variavel armazena a quantidade desejada do produto selecionado pelo usuario, usada para calcular os subtotais e atualizar o total de itens.
    int total_itens = 0; //Variavel acumuladora que armazena o total geral de itens no carrinho geral, atualizada a cada adição de produto para refletir o total de itens em todas as categorias (limpeza + alimentos + padaria).
    int total_itens_limpeza = 0; //Variavel acumuladora que armazena o total de itens no carrinho da categoria limpeza.
    int total_itens_padaria = 0; //Variavel acumuladora que armazena o total de itens no carrinho da categoria padaria.
    int total_itens_alimentos = 0; //Variavel acumuladora que armazena o total de itens no carrinho da categoria alimentos.
    int pag = 0; //Variavel armazena a escolha do usuario no menu de pagamento, usada para direcionar o fluxo do sistema e calcular descontos.
    int verificador = 0; //Variavel usada para armazenar o codigo de retorno da funcao scanf, usada para validar se o input do usuario foi do tipo esperado (inteiro) e para acionar o tratamento de erro em caso de falha de leitura (type mismatch).


// --- ESPAÇO PARA DECLAÇÃO DE VARIAVÉL do tipo FLOAT (Ponto flutuante).
// Declara a variavél inicial em 0 para limpar o lixo do sistema.
// DESCONTOS E VALORES FINAIS.
    float desconto5 = 0; //Variavel usada para armazenar o valor do desconto de 5% aplicado no pagamento, calculado com base no total geral do carrinho e atualizado no menu de pagamento.
    float desconto10 = 0; //Variavel usada para armazenar o valor do desconto de 10% aplicado no pagamento, calculado com base no total geral do carrinho e atualizado no menu de pagamento.
    float desconto18 = 0; //Variavel usada para armazenar o valor do desconto de 18% aplicado no pagamento, calculado com base no total geral do carrinho e atualizado no menu de pagamento.
    float valor_total = 0; //Variavel usada para armazenar o valor total a ser pago após a aplicação de descontos, calculado com base no total geral do carrinho e atualizado no menu de pagamento.
// TOTAIS DE CATEGORIAS E GERAL.   
    float total_limpeza = 0; //Variavel acumuladora que armazena o total geral do carrinho da categoria limpeza, atualizada a cada adição de produto para refletir o total gasto em produtos de limpeza.
    float total_alimentos = 0; //Variavel acumuladora que armazena o total geral do carrinho da categoria alimentos, atualizada a cada adição de produto para refletir o total gasto em produtos de alimentos.
    float total_padaria = 0; //Variavel acumuladora que armazena o total geral do carrinho da categoria padaria, atualizada a cada adição de produto para refletir o total gasto em produtos de padaria.
    float total_geral = 0; //Variavel acumuladora que armazena o total geral do carrinho, atualizada a cada adição de produto para refletir o total gasto em todos os produtos.

// --- ESPAÇO PARA DECLAÇÃO DE VARIAVÉL do tipo CHAR.
// Declara a variavél inicial em 0 para limpar o lixo do sistema.
    char tecla = 0;
    char lixo_de_memoria = 0;

// --- MENSAGEM DE BOAS VINDAS E CONFIRMAÇÃO DE INPUT.

// --- MENSAGEM DE BOAS VINDAS (LOGO ASCII) ---
system("cls || clear");
printf("$$\\       $$\\$$$$$$$$\\ $$$$$$$\\  $$$$$$\\   $$$$$$$\\  $$$$$$$\\  $$$$$$\\ $$\\   $$\\ $$\\   $$\\  $$$$$$\\         $$$$$$\\  $$\\  $$\\  $$$$$$\\  $$$$$$$\\\n");
printf("$$$\\    $$$ |$$  _____|$$  __$$\\ $$  __$$\\ $$  __$$\\ $$  __$$\\ \\_$$  _|$$$\\  $$ |$$ |  $$ |$$  __$$\\       $$  __$$\\ $$ |  $$ |$$  __$$\\ $$  __$$\\\n");
printf("$$$$\\  $$$$ |$$ |      $$ |  $$ |$$ /  \\__|$$ /  $$ |$$ |  $$ |  $$ |  $$$$\\ $$ |$$ |  $$ |$$ /  $$ |      $$ /  \\__|$$ |  $$ |$$ /  $$ |$$ |  $$ |\n");
printf("$$\\$$\\$$ $$ |$$$$$\\    $$$$$$$  |$$ |      $$$$$$$$ |$$ |  $$ |  $$ |  $$ $$\\$$ |$$$$$$$$ |$$ |  $$ |      \\$$$$$$\\  $$$$$$$$ |$$ |  $$ |$$$$$$$  |\n");
printf("$$ \\$$$  $$ |$$  __|   $$  __$$< $$ |      $$  __$$ |$$ |  $$ |  $$ |  $$ \\$$$$ |$$  __$$ |$$ |  $$ |       \\____$$\\ $$  __$$ |$$ |  $$ |$$  ____/ \n");
printf("$$ |\\$  /$$ |$$ |      $$ |  $$ |$$ |  $$\\ $$ |  $$ |$$ |  $$ |  $$ |  $$ |\\$$$ |$$ |  $$ |$$ |  $$ |      $$\\   $$ |$$ |  $$ |$$ |  $$ |$$ |      \n");
printf("$$ | \\_/ $$ |$$$$$$$$\\ $$ |  $$ |\\$$$$$$  |$$ |  $$ |$$$$$$$  |$$$$$$\\ $$ | \\$$ |$$ |  $$ | $$$$$$  |      \\$$$$$$  |$$ |  $$ | $$$$$$  |$$ |      \n");
printf("\\__|     \\__|\\________|\\__|  \\__| \\______/ \\__|  \\__|\\_______/ \\______|\\__|  \\__|\\__|  \\__| \\______/        \\______/ \\__|  \\__| \\______/ \\__|      \n\n");

printf("Por favor, pressione ENTER para iniciar o sistema..."); //Exibe a mensagem e aguarda o input do usuario para prosseguir o sistema.
scanf("%c", &tecla); //A função scanf le o input do usuario e armazena na variavel tecla. O formatador '%c' indica que o input eh um caractere. O sistema aguarda ate que o usuario pressione uma tecla e confirme com Enter, momento em que o programa continua a execucao.
//Antes tinha um system("pause") aqui, mas ele nao permite portabilidade, entao optei por usar o scanf para aguardar o input do usuario, o que eh mais universal e funciona em qualquer terminal, diferente do system("pause") que eh especifico do Windows.




// --- LOOP ou LAÇO DE REPETIÇÃO PRINCIPAL, é aqui onde o user irá dar os inputs principais do sistema.
    do {
        
        system("cls || clear"); // Usado para dar clean no terminal evitando poluição visual. 'cls' eh integrdo ao win enquanto o 'clear' eh integrado ao linux, usando o operador logico '||' para garantir a portabilidade do sistema.
        total_geral = total_alimentos + total_limpeza + total_padaria;
        printf("\n"); //nada de novo no front... só outputs para o userarrombado.
        printf("---------------------------------------------\n"); // Aréa reservada ao carrinho, usando formatadores para output do total e total de itens.
        printf("|      --- STATUS DO CARRINHO GERAL ---     |\n");
        printf("|-------------------------------------------|\n");
        printf("| Total no carrinho: R$%.2f.                |\n", total_geral); // Variavél responsável pelo total de produtos do carrinho da aba alimentos!
        printf("| Total de itens no carrinho: %d un.         |\n", total_itens); // Total de itens total no sistema!
        printf("---------------------------------------------\n");
        printf("=============================================\n");
        printf("|          --- MENU PRINCIPAL ---           |\n");
        printf("=============================================\n");
        printf("|   [ 01 ] Venda de Limpeza                 |\n");
        printf("|   [ 02 ] Venda de Alimentos               |\n");
        printf("|   [ 03 ] Venda da Padaria                 |\n");
        printf("|   [ 04 ] Pagamento                        |\n");
        printf("|   [ 05 ] Sair                             |\n");
        printf("=============================================\n");
        printf(" Escolha uma opcao para continuar: ");

        scanf("%d", &opcao); //Irá ler o input do user e atribuir a var opcao.

            switch (opcao){ //Irá analisar o valor da var e alocar a uma case.

                case 1:
                        printf("Abrindo aba Venda de Limpeza!\n");
                        printf("\nPor favor, pressione ENTER para continuar..."); //Exibe a mensagem e aguarda o input do usuario para prosseguir o sistema.
                        scanf("%c", &tecla); //A função scanf le o input do usuario e armazena na variavel tecla. O formatador '%c' indica que o input eh um caractere. O sistema aguarda ate que o usuario pressione uma tecla e confirme com Enter, momento em que o programa continua a execucao.
                        //Antes tinha um system("pause") aqui, mas ele nao permite portabilidade, entao optei por usar o scanf para aguardar o input do usuario, o que eh mais universal e funciona em qualquer terminal, diferente do system("pause") que eh especifico do Windows.
                    do {
                        system("cls || clear");
                        printf("---------------------------------------------\n"); // Aréa reservada ao carrinho, usando formatadores para output do total e total de itens.
                        printf("|    --- STATUS DO CARRINHO LIMPEZA ---     |\n");
                        printf("|-------------------------------------------|\n");
                        printf("| Total no carrinho: R$%.2f.                |\n", total_limpeza); // Variavél responsável pelo total de produtos do carrinho da aba limpeza!
                        printf("| Total de itens no carrinho: %d un.         |\n", total_itens_limpeza); // Total de itens total no sub-sistema de limpeza!
                        printf("---------------------------------------------\n");
                        printf("=============================================\n");
                        printf("|        --- PRODUTOS DE LIMPEZA ---        |\n"); // Output de listagem de produtos e UI/UX para uma melhor comunicação vísual.
                        printf("=============================================\n");
                        printf("|                                           |\n");
                        printf("|   [101] Detergente Ipe Lava-Louca 500 ml  |\n");
                        printf("|   [102] Sabao em Po 1 Kg                  |\n");
                        printf("|   [103] Esponja Lava-Louca (Un)           |\n");
                        printf("|   [104] Amaciante Confort 2 L             |\n");
                        printf("|   [105] Desinfetante Qboa 1 L             |\n");
                        printf("|   [106] Agua Sanitaria 1 L                |\n");
                        printf("|   [107] Limpador Multiuso 500 ml          |\n");
                        printf("|   [108] Rodo de Madeira (Un)              |\n");
                        printf("|   [109] Vassoura Pelo Sintetico (Un)      |\n");
                        printf("|   [110] Pano de Chao (Un)                 |\n");
                        printf("|                                           |\n");
                        printf("|   [  05 ] Voltar ao Menu Principal        |\n");
                        printf("|                                           |\n");
                        printf("=============================================\n");
                        printf(" Digite o codigo e confirme: "); // Input do ator pra seleção do produto desejado ou dando um FALSO (5) para voltar ao Laço de Repetição.
                        scanf("%d", &codigo);

                        switch(codigo){

                            case 101:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Detergente Ipe Lava-Louca 500 ml |\n"); //Exibe a interface visual com as especificacoes do produto selecionado pelo usuario.
                                printf("| Preco Unidade: R$ %.2f                    |\n", DETERGENTE_IPE); //Exibe o valor unitario formatando a constante float para exibir duas casas decimais.
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); //Solicita o input para a quantidade desejada.
                                quantidade = 0;//Para qualquer repeticao, garente o valor 0 a variavel.
                                //A funcao scanf tenta ler um valor inteiro, usando formatador %d com base decimal 10.
                                verificador = scanf(" %d", &quantidade); //A variavel verificador armazena o codigo de retorno do scanf, retorna 1 para sucesso (valor inteiro), retorna 0 para falha do tipo Type Mismatch.
                                if (verificador == 0) { //Inicio do tratamento de erro, se o verificador for 0, o input foi um char causando falha na leitura e deixando lixo residual no buffer de memoria.
                                    do { //Estrutura de repeticao para realizar a limpeza do buffer de memoria do stdin.
                                        scanf("%c", &lixo_de_memoria); //O scanf le sequencialmente cada bit bruto com formatador %c preso no buffer e o atribui a variavel lixo_de_memoria para limpar.
                                    } while (lixo_de_memoria != '\n'); //A repeticao continua ate encontrar o bit de quebra de linha '\n' ou 00001010 em binario de base 10, indicando que o buffer de memoria esta vazio.
                                }
                                if (quantidade <= 0) { //Avalia se o valor inserido e invalido sendo menor ou igual a zero ou se a variavel manteve o zero inicial apos uma falha de leitura.
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");//Emite o output de erro para instruir o usuario sobre o padrao correto de entrada do sistema.
                                    printf("Por favor, pressione ENTER para continuar..."); //Exibe a mensagem e aguarda o input do usuario para prosseguir o sistema.
                                    scanf("%c", &tecla); //A função scanf le o input do usuario e armazena na variavel tecla. O formatador '%c' indica que o input eh um caractere. O sistema aguarda ate que o usuario pressione uma tecla e confirme com Enter, momento em que o programa continua a execucao.
                                    //Antes tinha um system("pause") aqui, mas ele nao permite portabilidade, entao optei por usar o scanf para aguardar o input do usuario, o que eh mais universal e funciona em qualquer terminal, diferente do system("pause") que eh especifico do Windows.
                                } else {
                                    total_itens_limpeza += quantidade; //Operacao de incremento, atualiza o total de itens da LIMPEZA utilizando uma variavel acomuladora.
                                    total_itens += quantidade;//Operacao de incremento atualiza o total geral de itens do carrinho utilizando uma variavel acomuladora.                                    
                                    total_limpeza += (quantidade * DETERGENTE_IPE);//Operacao de atribuicao aditiva, recupera o estado atual do acumulador e soma ao subtotal do item em quantidade * valor da constante.
                                    printf("\n---------------------------------------------\n"); //Exibe o output de sucesso com o valor da quantidade adicionada, subtotal do item e total atualizado da limpeza formatando os valores float para exibir duas casas decimais.
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); //Exibe a quantidade adicionada ao carrinho.
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * DETERGENTE_IPE); //Exibe o subtotal do item calculando a quantidade multiplicada pelo valor unitario da constante.
                                    printf("| Total atual da Limpeza: R$ %.2f          |\n", total_limpeza);//Exibe o total atualizado da limpeza utilizando a variavel acumuladora total_limpeza formatada para exibir duas casas decimais.                                    
                                    printf("---------------------------------------------\n");
                                    do { //Limpeza do buffer de entrada para evitar que caracteres residuais interfiram no próximo input do usuário.
                                        scanf("%c", &lixo_de_memoria); //A função scanf le o input do usuario e armazena na variavel lixo_de_memoria. O formatador '%c' indica que o input eh um caractere. O sistema aguarda ate que o usuario pressione uma tecla e confirme com Enter, momento em que o programa continua a execucao.
                                    } while (lixo_de_memoria != '\n'); //O loop continua a ler caracteres até encontrar o caractere de nova linha '\n', que indica o final da linha de input. Isso garante que o buffer de entrada esteja limpo para o próximo input do usuario, evitando que caracteres residuais.
                                    printf("Por favor, pressione ENTER para continuar..."); //Exibe a mensagem e aguarda o input do usuario para prosseguir o sistema.                                    
                                    scanf("%c", &tecla); //A função scanf le o input do usuario e armazena na variavel tecla. O formatador '%c' indica que o input eh um caractere. O sistema aguarda ate que o usuario pressione uma tecla e confirme com Enter, momento em que o programa continua a execucao.
                                    //Antes tinha um system("pause") aqui, mas ele nao permite portabilidade, entao optei por usar o scanf para aguardar o input do usuario, o que eh mais universal e funciona em qualquer terminal, diferente do system("pause") que eh especifico do Windows.
                                }
                            break;

/* OBS:
   Os cases subsequentes (102 ao 110), subsequentes de seus menus (Alimento e Padaria) possuem a EXATA MESMA estrutura logica  de tratamento de erro no buffer, validacao de input e calculo de subtotais.
   documentei e comentei muito bem explicado detalhadamente no 'case 101'. Para manter o codigo limpo e aplicar o principio DRY (Don't Repeat Yourself), os proximos cases nao terao comentarios redundantes, 
   variando apenas as constantes de produtos e precos correspondentes.
*/

                            case 102:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Sabao em Po 1Kg                  |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", SABAO_PO_1KG); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_limpeza += quantidade;
                                    total_itens += quantidade;                                   
                                    total_limpeza += (quantidade * SABAO_PO_1KG);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * SABAO_PO_1KG); 
                                    printf("| Total atual da Limpeza: R$ %.2f          |\n", total_limpeza);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 103:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Esponja Lava-Louca (Un)          |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", ESPONJA); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_limpeza += quantidade;
                                    total_itens += quantidade;                                   
                                    total_limpeza += (quantidade * ESPONJA);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * ESPONJA); 
                                    printf("| Total atual da Limpeza: R$ %.2f          |\n", total_limpeza);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 104:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Amaciante Confort 2 L            |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", AMACIANTE_2L); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_limpeza += quantidade;
                                    total_itens += quantidade;                                   
                                    total_limpeza += (quantidade * AMACIANTE_2L);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * AMACIANTE_2L); 
                                    printf("| Total atual da Limpeza: R$ %.2f          |\n", total_limpeza);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 105:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Desinfetante Qboa 1 L            |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", DESINFETANTE_1L); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_limpeza += quantidade;
                                    total_itens += quantidade;                                   
                                    total_limpeza += (quantidade * DESINFETANTE_1L);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * DESINFETANTE_1L); 
                                    printf("| Total atual da Limpeza: R$ %.2f          |\n", total_limpeza);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 106:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Agua Sanitaria 1 L               |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", AGUA_SANITARIA_1L); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_limpeza += quantidade;
                                    total_itens += quantidade;                                   
                                    total_limpeza += (quantidade * AGUA_SANITARIA_1L);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * AGUA_SANITARIA_1L); 
                                    printf("| Total atual da Limpeza: R$ %.2f          |\n", total_limpeza);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 107:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Limpador Multiuso 500 ml         |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", LIMPADOR_MULTIUSO); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_limpeza += quantidade;
                                    total_itens += quantidade;                                   
                                    total_limpeza += (quantidade * LIMPADOR_MULTIUSO);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * LIMPADOR_MULTIUSO); 
                                    printf("| Total atual da Limpeza: R$ %.2f          |\n", total_limpeza);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 108:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Rodo de Madeira (Un)             |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", RODO_MADEIRA); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_limpeza += quantidade;
                                    total_itens += quantidade;                                   
                                    total_limpeza += (quantidade * RODO_MADEIRA);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * RODO_MADEIRA); 
                                    printf("| Total atual da Limpeza: R$ %.2f          |\n", total_limpeza);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 109:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Vassoura Pelo Sintetico (Un)     |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", VASSOURA_PELO); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_limpeza += quantidade;
                                    total_itens += quantidade;                                   
                                    total_limpeza += (quantidade * VASSOURA_PELO);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * VASSOURA_PELO); 
                                    printf("| Total atual da Limpeza: R$ %.2f          |\n", total_limpeza);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 110:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Pano de Chao (Un)                |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", PANO_DE_CHAO); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_limpeza += quantidade;
                                    total_itens += quantidade;                                   
                                    total_limpeza += (quantidade * PANO_DE_CHAO);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * PANO_DE_CHAO); 
                                    printf("| Total atual da Limpeza: R$ %.2f          |\n", total_limpeza);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 5:
                            break;

                            default:
                                printf("\n [ ERRO ] Codigo invalido! Tente novamente.\n");
                                printf("Por favor, pressione ENTER para continuar..."); //Exibe a mensagem e aguarda o input do usuario para prosseguir o sistema.
                                scanf("%c", &tecla); //A função scanf le o input do usuario e armazena na variavel tecla. O formatador '%c' indica que o input eh um caractere. O sistema aguarda ate que o usuario pressione uma tecla e confirme com Enter, momento em que o programa continua a execucao.
                                //Antes tinha um system("pause") aqui, mas ele nao permite portabilidade, entao optei por usar o scanf para aguardar o input do usuario, o que eh mais universal e funciona em qualquer terminal, diferente do system("pause") que eh especifico do Windows.
                            break;
                        }
                    } while(codigo !=5);


                break;

                case 2:
                    printf("Abrindo aba Venda de Alimentos!\n");
                    printf("Por favor, pressione ENTER para continuar..."); 
                    scanf("%c", &tecla); 
                    do {
                        system("cls || clear");
                        printf("-------------------------------------\n"); // Aréa reservada ao carrinho, usando formatadores para output do total e total de itens.
                        printf("| STATUS DO CARRINHO DE ALIMENTOS   |\n");
                        printf("| Total no carrinho: R$%.2f.        |\n", total_alimentos); // Variavél responsável pelo total de produtos do carrinho da aba alimentos!
                        printf("| Total de itens no carrinho: %d un. |\n", total_itens_alimentos); // Total de itens total no sistema!
                        printf("-------------------------------------\n");
                        printf("=============================================\n");
                        printf("         --- ALIMENTOS --- \n"); // Output de listagem de produtos e UI/UX para uma melhor comunicação vísual.
                        printf("=============================================\n");
                        printf("|                                           |\n");
                        printf("|   [101] Arroz Sabor Sul Tipo 1 5 Kg       |\n");
                        printf("|   [102] Feijao Carioca 1 Kg               |\n");
                        printf("|   [103] Oleo de Soja 1 L                  |\n");
                        printf("|   [104] Macarrao Espaguete 500 g          |\n");
                        printf("|   [105] Cafe Torrado 500 g                |\n");
                        printf("|   [106] Acucar Refinado 1 Kg              |\n");
                        printf("|   [107] Sal Refinado 1 Kg                 |\n");
                        printf("|   [108] Farinha de Trigo 1 Kg             |\n");
                        printf("|   [109] Molho de Tomate 250 g             |\n");
                        printf("|   [110] Biscoito Recheado 250 g           |\n");
                        printf("|                                           |\n");
                        printf("|   [  05 ] Voltar ao Menu Principal        |\n");
                        printf("|                                           |\n");
                        printf("=============================================\n");
                        printf(" Digite o codigo e confirme: "); // Input do ator pra seleção do produto desejado ou dando um FALSO (5) para voltar ao Laço de Repetição.
                        scanf("%d", &codigo);

                        switch(codigo){

                            case 101:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto:  Arroz Sabor Sul Tipo 1 5 Kg     |\n"); //Exibe a interface visual com as especificacoes do produto selecionado pelo usuario.
                                printf("| Preco Unidade: R$ %.2f                    |\n", ARROZ_5KG); //Exibe o valor unitario formatando a constante float para exibir duas casas decimais.
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); //Solicita o input para a quantidade desejada.
                                quantidade = 0;//Para qualquer repeticao, garente o valor 0 a variavel.
                                //A funcao scanf tenta ler um valor inteiro, usando formatador %d com base decimal 10.
                                verificador = scanf(" %d", &quantidade); //A variavel verificador armazena o codigo de retorno do scanf, retorna 1 para sucesso (valor inteiro), retorna 0 para falha do tipo Type Mismatch.
                                if (verificador == 0) { //Inicio do tratamento de erro, se o verificador for 0, o input foi um char causando falha na leitura e deixando lixo residual no buffer de memoria.
                                    do { //Estrutura de repeticao para realizar a limpeza do buffer de memoria do stdin.
                                        scanf("%c", &lixo_de_memoria); //O scanf le sequencialmente cada bit bruto com formatador %c preso no buffer e o atribui a variavel lixo_de_memoria para limpar.
                                    } while (lixo_de_memoria != '\n'); //A repeticao continua ate encontrar o bit de quebra de linha '\n' ou 00001010 em binario de base 10, indicando que o buffer de memoria esta vazio.
                                }
                                if (quantidade <= 0) { //Avalia se o valor inserido e invalido sendo menor ou igual a zero ou se a variavel manteve o zero inicial apos uma falha de leitura.
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");//Emite o output de erro para instruir o usuario sobre o padrao correto de entrada do sistema.
                                    printf("Por favor, pressione ENTER para continuar..."); //Exibe a mensagem e aguarda o input do usuario para prosseguir o sistema.
                                    scanf("%c", &tecla); //A função scanf le o input do usuario e armazena na variavel tecla. O formatador '%c' indica que o input eh um caractere. O sistema aguarda ate que o usuario pressione uma tecla e confirme com Enter, momento em que o programa continua a execucao.
                                    //Antes tinha um system("pause") aqui, mas ele nao permite portabilidade, entao optei por usar o scanf para aguardar o input do usuario, o que eh mais universal e funciona em qualquer terminal, diferente do system("pause") que eh especifico do Windows.
                                } else {
                                    total_itens_alimentos += quantidade; //Operacao de incremento, atualiza o total de itens de ALIMENTOS utilizando uma variavel acomuladora.
                                    total_itens += quantidade;//Operacao de incremento atualiza o total geral de itens do carrinho utilizando uma variavel acomuladora.                                    
                                    total_alimentos += (quantidade * ARROZ_5KG);//Operacao de atribuicao aditiva, recupera o estado atual do acumulador e soma ao subtotal do item em quantidade * valor da constante.
                                    printf("\n---------------------------------------------\n"); //Exibe o output de sucesso com o valor da quantidade adicionada, subtotal do item e total atualizado de alimentos formatando os valores float para exibir duas casas decimais.
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); //Exibe a quantidade adicionada ao carrinho.
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * ARROZ_5KG); //Exibe o subtotal do item calculando a quantidade multiplicada pelo valor unitario da constante.
                                    printf("| Total atual dos Alimentos: R$ %.2f          |\n", total_alimentos);//Exibe o total atualizado dos alimentos utilizando a variavel acumuladora total_alimentos formatada para exibir duas casas decimais.                                    
                                    printf("---------------------------------------------\n");
                                    do { //Limpeza do buffer de entrada para evitar que caracteres residuais interfiram no próximo input do usuário.
                                        scanf("%c", &lixo_de_memoria); //A função scanf le o input do usuario e armazena na variavel lixo_de_memoria. O formatador '%c' indica que o input eh um caractere. O sistema aguarda ate que o usuario pressione uma tecla e confirme com Enter, momento em que o programa continua a execucao.
                                    } while (lixo_de_memoria != '\n'); //O loop continua a ler caracteres até encontrar o caractere de nova linha '\n', que indica o final da linha de input. Isso garante que o buffer de entrada esteja limpo para o próximo input do usuario, evitando que caracteres residuais.
                                    printf("Por favor, pressione ENTER para continuar..."); //Exibe a mensagem e aguarda o input do usuario para prosseguir o sistema.                                    
                                    scanf("%c", &tecla); //A função scanf le o input do usuario e armazena na variavel tecla. O formatador '%c' indica que o input eh um caractere. O sistema aguarda ate que o usuario pressione uma tecla e confirme com Enter, momento em que o programa continua a execucao.
                                    //Antes tinha um system("pause") aqui, mas ele nao permite portabilidade, entao optei por usar o scanf para aguardar o input do usuario, o que eh mais universal e funciona em qualquer terminal, diferente do system("pause") que eh especifico do Windows.
                                }
                            break;

                            case 102:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Feijao Carioca 1 Kg              |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", FEIJAO_CARIOCA_1KG); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_alimentos += quantidade;
                                    total_itens += quantidade;                                   
                                    total_alimentos += (quantidade * FEIJAO_CARIOCA_1KG);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * FEIJAO_CARIOCA_1KG); 
                                    printf("| Total atual dos Alimentos: R$ %.2f          |\n", total_alimentos);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 103:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Oleo de Soja 1 L                 |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", OLEO_DE_SOJA); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_alimentos += quantidade;
                                    total_itens += quantidade;                                   
                                    total_alimentos += (quantidade * OLEO_DE_SOJA);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * OLEO_DE_SOJA); 
                                    printf("| Total atual dos Alimentos: R$ %.2f          |\n", total_alimentos);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 104:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Macarrao Espaguete 500 g         |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", MACARRAO_ESPAGUETE); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_alimentos += quantidade;
                                    total_itens += quantidade;                                   
                                    total_alimentos += (quantidade * MACARRAO_ESPAGUETE);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * MACARRAO_ESPAGUETE); 
                                    printf("| Total atual dos Alimentos: R$ %.2f          |\n", total_alimentos);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 105:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Cafe Torrado 500 g               |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", CAFE_TORRADO_500G); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_alimentos += quantidade;
                                    total_itens += quantidade;                                   
                                    total_alimentos += (quantidade * CAFE_TORRADO_500G);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * CAFE_TORRADO_500G); 
                                    printf("| Total atual dos Alimentos: R$ %.2f          |\n", total_alimentos);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 106:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Acucar Refinado 1 Kg             |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", ACUCAR_REFINADO_1KG); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_alimentos += quantidade;
                                    total_itens += quantidade;                                   
                                    total_alimentos += (quantidade * ACUCAR_REFINADO_1KG);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * ACUCAR_REFINADO_1KG); 
                                    printf("| Total atual dos Alimentos: R$ %.2f          |\n", total_alimentos);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 107:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Sal Refinado 1 Kg                |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", SAL_REFINADO_1KG); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_alimentos += quantidade;
                                    total_itens += quantidade;                                   
                                    total_alimentos += (quantidade * SAL_REFINADO_1KG);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * SAL_REFINADO_1KG); 
                                    printf("| Total atual dos Alimentos: R$ %.2f          |\n", total_alimentos);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 108:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Farinha de Trigo 1 Kg            |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", FARINHA_DE_TRIGO_1KG); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_alimentos += quantidade;
                                    total_itens += quantidade;                                   
                                    total_alimentos += (quantidade * FARINHA_DE_TRIGO_1KG);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * FARINHA_DE_TRIGO_1KG); 
                                    printf("| Total atual dos Alimentos: R$ %.2f          |\n", total_alimentos);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 109:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Molho de Tomate 250 g            |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", MOLHO_DE_TOMATE); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_alimentos += quantidade;
                                    total_itens += quantidade;                                   
                                    total_alimentos += (quantidade * MOLHO_DE_TOMATE);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * MOLHO_DE_TOMATE); 
                                    printf("| Total atual da Limpeza: R$ %.2f          |\n", total_alimentos);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 110:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Biscoito Recheado 250 g          |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", BISCOITO_RECHEADO); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_alimentos += quantidade;
                                    total_itens += quantidade;                                   
                                    total_alimentos += (quantidade * BISCOITO_RECHEADO);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * BISCOITO_RECHEADO); 
                                    printf("| Total atual dos Alimentos: R$ %.2f          |\n", total_alimentos);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 5:
                            break;

                            default:
                                printf("\n [ ERRO ] Codigo invalido! Tente novamente.\n");
                                printf("Por favor, pressione ENTER para continuar...");
                                scanf("%c", &tecla);
                            break;

                        }
                    } while(codigo !=5);
                break;

                case 3:
                printf("Abrindo aba Venda da Padaria!\n");
                printf("Por favor, pressione ENTER para continuar...");
                scanf("%c", &tecla); 

                    do {
                        system("cls || clear");
                        printf("-------------------------------------\n"); // Aréa reservada ao carrinho, usando formatadores para output do total e total de itens.
                        printf("| STATUS DO CARRINHO DA PADARIA   |\n");
                        printf("| Total no carrinho: R$%.2f.        |\n", total_padaria); // Variavél responsável pelo total de produtos do carrinho da aba alimentos!
                        printf("| Total de itens no carrinho: %d un. |\n", total_itens_padaria); // Total de itens total no sistema!
                        printf("-------------------------------------\n");
                        printf("=============================================\n");
                        printf("         --- PADARIA --- \n"); // Output de listagem de produtos e UI/UX para uma melhor comunicação vísual.
                        printf("=============================================\n");
                        printf("|                                           |\n");
                        printf("|   [101] Pao Frances (Un)                  |\n");
                        printf("|   [102] Pao de Queijo 100 g               |\n");
                        printf("|   [103] Bolo de Cenoura (Fatia)           |\n");
                        printf("|   [104] Sonho de Creme (Un)               |\n");
                        printf("|   [105] Coxinha de Frango 100 g           |\n");
                        printf("|   [106] Cafe Expresso (Xicara)            |\n");
                        printf("|   [107] Pao Doce (Un)                     |\n");
                        printf("|   [108] Torta de Frango (Fatia)           |\n");
                        printf("|   [109] Pao de Batata (Un)                |\n");
                        printf("|   [110] Enroladinho de Salsicha (Un)      |\n");
                        printf("|                                           |\n");
                        printf("|   [  05 ] Voltar ao Menu Principal        |\n");
                        printf("|                                           |\n");
                        printf("=============================================\n");
                        printf(" Digite o codigo e confirme: "); // Input do ator pra seleção do produto desejado ou dando um FALSO (5) para voltar ao Laço de Repetição.
                        scanf("%d", &codigo);

                        switch(codigo){

                            case 101:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Pao Frances (Un)                 |\n"); //Exibe a interface visual com as especificacoes do produto selecionado pelo usuario.
                                printf("| Preco Unidade: R$ %.2f                    |\n", PAO_FRANCES_KG); //Exibe o valor unitario formatando a constante float para exibir duas casas decimais.
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); //Solicita o input para a quantidade desejada.
                                quantidade = 0;//Para qualquer repeticao, garente o valor 0 a variavel.
                                //A funcao scanf tenta ler um valor inteiro, usando formatador %d com base decimal 10.
                                verificador = scanf(" %d", &quantidade); //A variavel verificador armazena o codigo de retorno do scanf, retorna 1 para sucesso (valor inteiro), retorna 0 para falha do tipo Type Mismatch.
                                if (verificador == 0) { //Inicio do tratamento de erro, se o verificador for 0, o input foi um char causando falha na leitura e deixando lixo residual no buffer de memoria.
                                    do { //Estrutura de repeticao para realizar a limpeza do buffer de memoria do stdin.
                                        scanf("%c", &lixo_de_memoria); //O scanf le sequencialmente cada bit bruto com formatador %c preso no buffer e o atribui a variavel lixo_de_memoria para limpar.
                                    } while (lixo_de_memoria != '\n'); //A repeticao continua ate encontrar o bit de quebra de linha '\n' ou 00001010 em binario de base 10, indicando que o buffer de memoria esta vazio.
                                }
                                if (quantidade <= 0) { //Avalia se o valor inserido e invalido sendo menor ou igual a zero ou se a variavel manteve o zero inicial apos uma falha de leitura.
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");//Emite o output de erro para instruir o usuario sobre o padrao correto de entrada do sistema.
                                    printf("Por favor, pressione ENTER para continuar..."); //Exibe a mensagem e aguarda o input do usuario para prosseguir o sistema.
                                    scanf("%c", &tecla); //A função scanf le o input do usuario e armazena na variavel tecla. O formatador '%c' indica que o input eh um caractere. O sistema aguarda ate que o usuario pressione uma tecla e confirme com Enter, momento em que o programa continua a execucao.
                                    //Antes tinha um system("pause") aqui, mas ele nao permite portabilidade, entao optei por usar o scanf para aguardar o input do usuario, o que eh mais universal e funciona em qualquer terminal, diferente do system("pause") que eh especifico do Windows.
                                } else {
                                    total_itens_padaria += quantidade; //Operacao de incremento, atualiza o total de itens da PADARIA utilizando uma variavel acomuladora.
                                    total_itens += quantidade;//Operacao de incremento atualiza o total geral de itens do carrinho utilizando uma variavel acomuladora.                                    
                                    total_padaria += (quantidade * PAO_FRANCES_KG);//Operacao de atribuicao aditiva, recupera o estado atual do acumulador e soma ao subtotal do item em quantidade * valor da constante.
                                    printf("\n---------------------------------------------\n"); //Exibe o output de sucesso com o valor da quantidade adicionada, subtotal do item e total atualizado da padaria formatando os valores float para exibir duas casas decimais.
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); //Exibe a quantidade adicionada ao carrinho.
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * PAO_FRANCES_KG); //Exibe o subtotal do item calculando a quantidade multiplicada pelo valor unitario da constante.
                                    printf("| Total atual da Padaria: R$ %.2f          |\n", total_padaria);//Exibe o total atualizado da padaria utilizando a variavel acumuladora total_padaria formatada para exibir duas casas decimais.                                    
                                    printf("---------------------------------------------\n");
                                    do { //Limpeza do buffer de entrada para evitar que caracteres residuais interfiram no próximo input do usuário.
                                        scanf("%c", &lixo_de_memoria); //A função scanf le o input do usuario e armazena na variavel lixo_de_memoria. O formatador '%c' indica que o input eh um caractere. O sistema aguarda ate que o usuario pressione uma tecla e confirme com Enter, momento em que o programa continua a execucao.
                                    } while (lixo_de_memoria != '\n'); //O loop continua a ler caracteres até encontrar o caractere de nova linha '\n', que indica o final da linha de input. Isso garante que o buffer de entrada esteja limpo para o próximo input do usuario, evitando que caracteres residuais.
                                    printf("Por favor, pressione ENTER para continuar..."); //Exibe a mensagem e aguarda o input do usuario para prosseguir o sistema.                                    
                                    scanf("%c", &tecla); //A função scanf le o input do usuario e armazena na variavel tecla. O formatador '%c' indica que o input eh um caractere. O sistema aguarda ate que o usuario pressione uma tecla e confirme com Enter, momento em que o programa continua a execucao.
                                    //Antes tinha um system("pause") aqui, mas ele nao permite portabilidade, entao optei por usar o scanf para aguardar o input do usuario, o que eh mais universal e funciona em qualquer terminal, diferente do system("pause") que eh especifico do Windows.
                                }
                            break;

                            case 102:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Pao de Queijo 100 g              |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", PAO_DE_QUEIJO_100G); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_padaria += quantidade;
                                    total_itens += quantidade;                                   
                                    total_padaria += (quantidade * PAO_DE_QUEIJO_100G);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * PAO_DE_QUEIJO_100G); 
                                    printf("| Total atual da Padaria: R$ %.2f          |\n", total_padaria);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 103:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Bolo de Cenoura (Fatia)          |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", BOLO_CENOURA_FATIA); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_padaria += quantidade;
                                    total_itens += quantidade;                                   
                                    total_padaria += (quantidade * BOLO_CENOURA_FATIA);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * BOLO_CENOURA_FATIA); 
                                    printf("| Total atual da Padaria: R$ %.2f          |\n", total_padaria);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 104:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Sonho de Creme (Un)              |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", SONHO_DE_CREME); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_padaria += quantidade;
                                    total_itens += quantidade;                                   
                                    total_padaria += (quantidade * SONHO_DE_CREME);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * SONHO_DE_CREME); 
                                    printf("| Total atual da Padaria: R$ %.2f          |\n", total_padaria);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 105:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Coxinha de Frango 100 g          |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", COXINHA_FRANGO); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_padaria += quantidade;
                                    total_itens += quantidade;                                   
                                    total_padaria += (quantidade * COXINHA_FRANGO);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * COXINHA_FRANGO); 
                                    printf("| Total atual da Padaria: R$ %.2f          |\n", total_padaria);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 106:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Cafe Expresso (Xicara)           |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", CAFE_EXPRESSO); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_padaria += quantidade;
                                    total_itens += quantidade;                                   
                                    total_padaria += (quantidade * CAFE_EXPRESSO);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * CAFE_EXPRESSO); 
                                    printf("| Total atual da Padaria: R$ %.2f          |\n", total_padaria);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 107:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Pao Doce (Un)                    |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", PAO_DOCE); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_padaria += quantidade;
                                    total_itens += quantidade;                                   
                                    total_padaria += (quantidade * PAO_DOCE);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * PAO_DOCE); 
                                    printf("| Total atual da Padaria: R$ %.2f          |\n", total_padaria);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 108:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Torta de Frango (Fatia)          |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", TORTA_FRANGO_FATIA); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_padaria += quantidade;
                                    total_itens += quantidade;                                   
                                    total_padaria += (quantidade * TORTA_FRANGO_FATIA);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * TORTA_FRANGO_FATIA); 
                                    printf("| Total atual da Padaria: R$ %.2f          |\n", total_padaria);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 109:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Pao de Batata (Un)               |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", POTATO); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_padaria += quantidade;
                                    total_itens += quantidade;                                   
                                    total_padaria += (quantidade * POTATO);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * POTATO); 
                                    printf("| Total atual da Padaria: R$ %.2f          |\n", total_padaria);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 110:
                                printf("\n---------------------------------------------\n");
                                printf("| Produto: Enroladinho de Salsicha (Un)     |\n"); 
                                printf("| Preco Unidade: R$ %.2f                    |\n", ENROLADINHO_SALSICHA); 
                                printf("---------------------------------------------\n");
                                printf(" Digite a quantidade desejada: "); 
                                quantidade = 0;
                               
                                verificador = scanf(" %d", &quantidade); 
                                if (verificador == 0) {
                                    do { 
                                        scanf("%c", &lixo_de_memoria);
                                    } while (lixo_de_memoria != '\n');
                                }
                                if (quantidade <= 0) {
                                    system("cls || clear");
                                    printf("\n [ ERRO ] Quantidade invalida! O valor deve ser um inteiro positivo nao nulo!\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla);
                                    
                                } else {
                                    total_itens_padaria += quantidade;
                                    total_itens += quantidade;                                   
                                    total_padaria += (quantidade * ENROLADINHO_SALSICHA);
                                    printf("\n---------------------------------------------\n"); 
                                    printf("| [ SUCESSO ] %d adicionado ao carrinho!     |\n", quantidade); 
                                    printf("| Subtotal do item: R$ %.2f                |\n", quantidade * ENROLADINHO_SALSICHA); 
                                    printf("| Total atual da Padaria: R$ %.2f          |\n", total_padaria);                                    
                                    printf("---------------------------------------------\n");
                                    do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n'); 
                                    printf("Por favor, pressione ENTER para continuar...");               
                                    scanf("%c", &tecla);
                                }
                            break;

                            case 5:
                            break;

                            default:
                                printf("\n [ ERRO ] Codigo invalido! Tente novamente.\n");
                                printf("Por favor, pressione ENTER para continuar..."); 
                                scanf("%c", &tecla);
                                do { 
                                        scanf("%c", &lixo_de_memoria); 
                                    } while (lixo_de_memoria != '\n');
                            break;

                        }
                    }while(codigo !=5);
                break; 

                case 4:
                printf("Abrindo aba de Pagamento!\n");
                printf("Por favor, pressione ENTER para continuar...");
                scanf("%c", &tecla); 
                do { 
                    scanf("%c", &lixo_de_memoria); 
                } while (lixo_de_memoria != '\n');

                    do {
                        system("cls || clear");
                        total_geral = total_alimentos + total_limpeza + total_padaria;
                        printf("==================================\n");
                        printf("|    --- MENU DE PAGAMENTO ---   |\n");
                        printf("==================================\n");                        
                        printf("| [ 01 ] Cartao                  |\n");              
                        printf("| [ 02 ] Dinheiro                |\n");
                        printf("| [ 05 ] Sair                    |\n");
                        printf("==================================\n");
                        printf("| Total a pagar: R$ %.2f         |\n", total_geral);
                        printf("==================================\n");
                        printf("Selecione o metodo de pagamento:\n");
                        scanf("%d", &pag);

                        switch(pag){

                            case 1:
                                valor_total = total_geral;
                                printf("\nSELECIONADO CARTAO!\n" );
                                do { 
                                    scanf("%c", &lixo_de_memoria); 
                                } while (lixo_de_memoria != '\n');
                                printf("Por favor, pressione ENTER para continuar..."); 
                                scanf("%c", &tecla);
                                do {
                                    system("cls || clear");
                                    printf("===========================================\n");
                                    printf("| [ 01 ] Pagamento na maquina OK          |\n");
                                    printf("| [ 02 ] Pagamento na maquina FALHA       | \n");
                                    printf("| [ 05 ] Voltar para o Menu de Pagamento  |\n");
                                    printf("===========================================\n");
                                    printf("| Total a pagar: R$ %.2f                     |\n", total_geral);
                                    printf("===========================================\n");
                                    printf("Selecione o metodo de pagamento:\n");
                                    scanf("%d", &pag);
                                    if (pag == 1){
                                        printf("Pagamento aprovado, obrigado pela preferencia!\n");
                                        printf("Por favor, pressione ENTER para continuar..."); 
                                        scanf("%c", &tecla);
                                        do { 
                                            scanf("%c", &lixo_de_memoria); 
                                        } while (lixo_de_memoria != '\n');
                                    } else if (pag == 2){
                                        printf("Pagamento recusado, por favor tente novamente ou escolha outro metodo de pagamento.\n");
                                        printf("Por favor, pressione ENTER para continuar..."); 
                                        scanf("%c", &tecla);
                                        do { 
                                            scanf("%c", &lixo_de_memoria); 
                                        } while (lixo_de_memoria != '\n');
                                    }
                                } while (pag != 5);
                                break;

                            case 2:
                                valor_total = total_geral;
                                printf("\nSELECIONADO DINHEIRO!\n");
                                printf("\nCalculando desconto para pagamento em dinheiro...\n");
                                do { 
                                    scanf("%c", &lixo_de_memoria); 
                                } while (lixo_de_memoria != '\n');
                                printf("Por favor, pressione ENTER para continuar..."); 
                                scanf("%c", &tecla); 
                                if (valor_total <= 0) {
                                    printf("\n[ ERRO ] Valor total invalido! O valor total com desconto nao pode ser nulo ou negativo. Por favor, revise os itens do carrinho e tente novamente.\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla); 
                                } else if (valor_total > 0 && valor_total <= 50){
                                    desconto5 = valor_total * 0.05;
                                    valor_total -= desconto5;
                                    printf("\n==================================\n");
                                    printf("|       STATUS DO PAGAMENTO      |\n");
                                    printf("==================================\n");
                                    printf("| Metodo selecionado: DINHEIRO   |\n");
                                    printf("| Desconto [5%%]: R$ %.2f        |\n", desconto5); // O %-13.2f alinha o numero à esquerda e empurra a barra vertical pro lugar certo
                                    printf("| Total com desconto: R$ %.2f    |\n", valor_total);
                                    printf("==================================\n");
                                    printf("|   Obrigado pela preferencia!   |\n");
                                    printf("==================================\n\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla); 
                                } else if (valor_total > 50 && valor_total < 100){
                                    desconto10 = valor_total * 0.10;
                                    valor_total -= desconto10;
                                    printf("\n==================================\n");
                                    printf("|       STATUS DO PAGAMENTO      |\n");
                                    printf("==================================\n");
                                    printf("| Metodo selecionado: DINHEIRO   |\n");
                                    printf("| Desconto [10%%]: R$ %.2f       |\n", desconto10); // O %-13.2f alinha o numero à esquerda e empurra a barra vertical pro lugar certo
                                    printf("| Total com desconto: R$ %.2f    |\n", valor_total);
                                    printf("==================================\n");
                                    printf("|   Obrigado pela preferencia!   |\n");
                                    printf("==================================\n\n");
                                    printf("Por favor, pressione ENTER para continuar..."); 
                                    scanf("%c", &tecla); 
                                } else if (valor_total >= 100){
                                    desconto18 = valor_total * 0.18;
                                    valor_total -= desconto18;
                                    printf("\n==================================\n");
                                    printf("|       STATUS DO PAGAMENTO      |\n");
                                    printf("==================================\n");
                                    printf("| Metodo selecionado: DINHEIRO   |\n");
                                    printf("| Desconto [18%%]: R$ %.2f|\n", desconto18); // O %-13.2f alinha o numero à esquerda e empurra a barra vertical pro lugar certo
                                    printf("| Total com desconto: R$ %.2f|\n", valor_total);
                                    printf("==================================\n");
                                    printf("|   Obrigado pela preferencia!   |\n");
                                    printf("==================================\n\n");
                                    printf("Por favor, pressione ENTER para continuar...");  
                                    scanf("%c", &tecla); 
                                }
                                break;

                            case 5:
                                printf("Saindo da aba de Pagamento!\n"); 
                                printf("\nPor favor, pressione ENTER para continuar...");
                                do { 
                                    scanf("%c", &lixo_de_memoria); 
                                } while (lixo_de_memoria != '\n');
                                scanf("%c", &tecla); 
                            break;

                            default:
                                printf("\n [ ERRO ] Codigo invalido! Tente novamente.\n");
                                printf("\nPor favor, pressione ENTER para continuar..."); 
                                scanf("%c", &tecla); 
                                do {
                                    scanf("%c", &lixo_de_memoria); 
                                } while (lixo_de_memoria != '\n');
                            break;

                        }
                    }while(pag !=5);
                break;

                case 5:
                    printf("Encerrando o sistema, ate logo!\n");
                    printf("\nPor favor, pressione ENTER para continuar..."); 
                    scanf("%c", &tecla);
                    do {
                        scanf("%c", &lixo_de_memoria); 
                    } while (lixo_de_memoria != '\n');
                break;

                default:
                    printf("\n [ ERRO ] Opcao invalida no sistema, porfavor tente novamente!\n");
                    printf("\nPor favor,  pressione ENTER para continuar..."); 
                    scanf("%c", &tecla);
                    do {
                        scanf("%c", &lixo_de_memoria); 
                    } while (lixo_de_memoria != '\n'); 
                break;
            }
    }   while (opcao !=5);

    return 0;

}
