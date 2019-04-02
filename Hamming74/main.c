#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "antesTransmitir.h"

void decodfica(int infoTransmissao[7]){

    int paridade[3][7] = {{1,0,1,0,1,0,1},{0,1,1,0,0,1,1},{0,0,0,1,1,1,1}};
    int vetorAux[7], resultado[3]={0,0,0};
    int falhaTransm=0;
    int verificaPosFalha=0;

    for(int i=0;i<7;i++)
            vetorAux[i] = infoTransmissao[i];


    while(falhaTransm==1){

        for(int i=0;i<3;i++){ //multiplica matrizes
            for(int j=0;j<7;j++){
                resultado +=  paridade[i][j] * vetorAux[j];
            }
        }

        if(falhaTransm==0){
            for(int i=0;i<3;i++){//verifica modulo
                resultado[i] %= 2;
                if(resultado[i] != 0){
                    falhaTransm = 1;
                }
            }
        } else if(falhaTransm>1){
            printf("\n\nNao foi possivel corrigir a informacao recebida.")
        }


        if(falhaTransm==1){//corrigir
            for(int i=3;i>0;i--){
                verificaPosFalha +=  pow(resultado[i-1],(i-1));
            }
            vetorAux[verificaPosFalha-1] = !vetorAux[verificaPosFalha-1];
        }




    }


}

void main(){
    int numBin[4];
    int numDec;
    int infoTransmissao[7]={0,0,0,0,0,0,0};

    printf("\nDigite um número decimal de 0 a 15: ");
    scanf("%d", &numDec);

    converteDecBin(numDec,numBin);

    printf("\n\nNumero Binario: ");
    for(int i=0; i<4;i++)
      printf("%d", numBin[i]);

    codificacao(numBin,infoTransmissao);

    printf("\n\nNumero Transmissao: ");
    for(int i=0; i<7;i++)
      printf("  %d  ", infoTransmissao[i]);


    interface(infoTransmissao);

    printf("\n\nNumero Transmissao Alterado: ");
    for(int i=0; i<7;i++)
      printf("  %d  ", infoTransmissao[i]);



}


