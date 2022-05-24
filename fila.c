#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FILA.H"


int main(){
    int option;
    char aux;
    struct sfila filaCampos, filaGuarus;
    qinit(&filaCampos);
    qinit(&filaGuarus);
    do{
        printf("1 - Cadastro Campos -> Guarus\n");
        printf("2 - Cadastro Guarus -> Campos\n");
        printf("3 - Liberar Carro\n");
        printf("0 - Fechar\n");
        printf("Escolha uma das opções acima: ");
        scanf("%d", &option);
        system("clear");
        switch (option){
            case 1: if(count(&filaCampos) < MAX){
                printf("\nEntre com a placa do carro: ");
                scanf(" %c", &aux);
                enqueue(&filaCampos, aux);
                printf("Primeiro carro: %c\n", first(&filaCampos));
                printf("Último carro: %c\n", last(&filaCampos));
                printf("Total de carros: %d\n\n", count(&filaCampos));
            }else{
                printf("Fila cheia!!!\n\n");
            }
            break;
            case 2: if(count(&filaGuarus) < MAX){
                printf("\nEntre com a placa do carro: ");
                scanf(" %c", &aux);
                enqueue(&filaGuarus, aux);
                printf("Primeiro carro: %c\n", first(&filaGuarus));
                printf("Último carro: %c\n", last(&filaGuarus));
                printf("Total de carros: %d\n\n", count(&filaGuarus));
            }else{
                printf("Fila cheia!!!\n\n");
            }
	        break;
            case 3: printf("\n* Travessia liberada! *\n");
                printf("Sentido Campos-Guarus\n");
                if(!qisEmpty(&filaCampos)){
                    printf("\tAtravessando carro: %c\n\n", first(&filaCampos));
                    dequeue(&filaCampos);
                }else{
                    printf("\tNao há carros para atravesar.\n");
                }
                printf("Sentido Guarus-Campos\n");
                if(!qisEmpty(&filaGuarus)){
                    printf("\tAtravessando carro: %c\n\n", first(&filaGuarus));
                    dequeue(&filaGuarus);
                }else{
                    printf("\tNao há carros para atravesar.\n");
                }
            break;
        }
    }while(option != 0); 
}
