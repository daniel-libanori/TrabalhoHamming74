#include <stdio.h>
#include <stdlib.h>




void converteDecBin(int numDec, int numBin[4]){

    for(int i=8, j=0;j<4;j++){
        if(numDec/i>0){
            numBin[j]=1;
            numDec-=i;
        }
        else{
            numBin[j]=0;
        }
        i/=2;
    }
}

void codificacao(int numBin[4], int infoTransmissao[7]){

    int geradora [7][4]={{1,1,0,1},{1,0,1,1},{1,0,0,0},{0,1,1,1},{0,1,0,0},{0,0,1,0},{0,0,0,1}};

    for(int i=0;i<7;i++){
        for(int j=0;j<4;j++){
            geradora[i][j] *=  numBin[j];
            infoTransmissao[i] += geradora[i][j];
        }
    }

}












void interface(int infoTransmissao[7]){

    int numAlteracoes=0;
    int alteracoes[3]={-1,-1,-1};
    int aux=0;
    int controle=0;

    printf("\n\nQuantos bits voce deseja alterar? (de 0 a 3 bits)\nR:");
    scanf("%d", &numAlteracoes);

    while(numAlteracoes!=controle){

        printf("Digite a posicao que deseja alterar (de 0 a 6): ");
        scanf("%d", &aux);
        if(aux < -1 || aux > 7){
            printf("Posicao Invalida, tente novamente");
            continue;
        }

        for(int i=0;i<numAlteracoes;i++)
            if(alteracoes[i]==aux){
                printf("Posicao digitada ja esta alterada, digite outra");
                aux=-1;
            }

        if(aux!=-1){
            alteracoes[controle]=aux;
            controle++;
        }

    }


    for(int i=0;i<7;i++){
        for(int j=0;j<3;j++){
            if(alteracoes[j]==i)
                infoTransmissao[i] = !infoTransmissao[i];

        }



    }










}
