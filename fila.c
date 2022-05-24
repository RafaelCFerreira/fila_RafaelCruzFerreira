#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FILA.H"


int main(){
    int option;
    char aux;
    struct sfila filaCampos_Guarus, filaGuarus_Campos;
    qinit(&filaCampos_Guarus);
    qinit(&filaGuarus_Campos);
    do{
        printf("1 - Cadastro Campos -> Guarus\n");
        printf("2 - Cadastro Guarus -> Campos\n");
        printf("3 - Liberar Carro\n");
        printf("0 - Fechar\n");
        printf("Escolha uma das opções acima: ");
        scanf("%d", &option);
        system("clear");
        switch (option){
            case 1: if(count(&filaCampos_Guarus) < MAX){
                printf("\nEntre com a placa do carro: ");
                scanf(" %c", &aux);
                enqueue(&filaCampos_Guarus, aux);
                printf("Primeiro carro: %c\n", first(&filaCampos_Guarus));
                printf("Último carro: %c\n", last(&filaCampos_Guarus));
                printf("Total de carros: %d\n\n", count(&filaCampos_Guarus));
            }else{
                printf("Fila cheia!!!\n\n");
            }
            break;
            case 2: if(count(&filaGuarus_Campos) < MAX){
                printf("\nEntre com a placa do carro: ");
                scanf(" %c", &aux);
                enqueue(&filaGuarus_Campos, aux);
                printf("Primeiro carro: %c\n", first(&filaGuarus_Campos));
                printf("Último carro: %c\n", last(&filaGuarus_Campos));
                printf("Total de carros: %d\n\n", count(&filaGuarus_Campos));
            }else{
                printf("Fila cheia!!!\n\n");
            }
	        break;
            case 3: printf("\nTravessia liberada! \n");
                printf("Sentido Campos->Guarus\n");
                if(!qisEmpty(&filaCampos_Guarus)){
                    printf("Atravessando carro: %c\n\n", first(&filaCampos_Guarus));
                    dequeue(&filaCampos_Guarus);
                    system("sleep 5");
                }else{
                    printf("Nenhum carro para atravesar.\n");
                }
                printf("Sentido Guarus->Campos\n");
                if(!qisEmpty(&filaGuarus_Campos)){
                    printf("Atravessando carro: %c\n\n", first(&filaGuarus_Campos));
                    dequeue(&filaGuarus_Campos);
                    system("sleep 5");
                }else{
                    printf("Nenhum carro para atravesar.\n");
                }
            break;
        }
    }while(option != 0); 
}
