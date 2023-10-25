#include<stdio.h>

char mostrarOpcoes(){
    char opcao;

    printf("Opções de pagamento:\n");
    printf("a À vista com 10%% de desconto\n");
    printf("b Em duas vezes(Preço da etiqueta\n" );
    printf("c De 3 ate 10 vezes com 3%% de juros ao mês(acima de R$100.00\n");

    printf("Escolha a opção desejada (a, b ou c):");
    getchar();
    scanf("%c", &opcao);

    return opcao; 
}

   //Função para calcular o valor das prestações
   void calcularPrestacoes(float totalGasto, char opcao){
    switch(opcao){
        case 'a':
        printf("Total com 10%% de desconto: R$%.2f\n", totalGasto *0.9);
        break;
        case 'b':
        printf("em Duas vezes:2x de R$%.2f\n", totalGasto / 2);
        break;
        case 'c':
        if(totalGasto > 100.000){
            int numParcelas;
            printf("Digite o numero de parcelas (3 a 10)");
            scanf("%d",&numParcelas);
            if(numParcelas >= 3 && numParcelas <= 10){
                float valorPrestacao = totalGasto / numParcelas * 1.03; //Com 3% de juros ao mes
                printf("Valor das prestações em %dx: R$%.2f\n", numParcelas, valorPrestacao);
            } else {
                printf("Numero de parcelas invalido.\n");
            }
        } else {
            printf("A Compra nao atende aos critérios não atende aos critérios de parcelamento.\n");
        }
        break;
        default:
        printf("Opção inválida.\n");
    }
   }
     
     int main(){
        float totalGasto;
        char opcao;

        //Solicita o total de gastos do cliente
        printf("Digite o total de gastos do cliente:");
        scanf("%f",&totalGasto);

        opcao = mostrarOpcoes();
        calcularPrestacoes(totalGasto,opcao);

        return 0;
     }