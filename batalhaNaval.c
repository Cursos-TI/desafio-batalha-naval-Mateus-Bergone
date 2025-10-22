#include <stdio.h>

int main() {
    char colunas[10]= {'A','B','C','D','E','F','G','H','I','J'};

    //Tabuleiro 10x10
    int tabuleiro[10][10];

    //Inicializando o tabuleiro com 0
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                tabuleiro[i][j] = 0;
            }
        }

        //Navio horizontal
        int linhaH = 4, colunaH = 2;
        for(int k=0; k<3; k++) {
            tabuleiro[linhaH][colunaH + k] = 3;
        }

        //Navio vertical
        int linhaV = 6, colunaV = 7;
        for(int k=0; k<3; k++) {
            tabuleiro[linhaV + k][colunaV] = 3;
        }

        //Navio diagonal1
        int linhaD1 = 0, colunaD1 = 0;
        for (int k = 0; k < 3; k++) {
            tabuleiro[linhaD1 + k][colunaD1 + k] = 3;
        }

        //Navio diagonal2
        int linhaD2 = 7, colunaD2 = 1;
        for (int k = 0; k < 3; k++) {
            tabuleiro[linhaD2 + k][colunaD2 + k] = 3;
        }

    //Exibindo o tabuleiro
    printf("**** TABULEIRO BATALHA NAVAL ****\n\n");
    printf("   "); //Espaço para alinhar as letras das colunas

    //Cabeçalho
    for(int j=0; j<10; j++) {
        printf(" %c ", colunas[j]);
    }
    printf("\n");

    //Linhas
    for(int i=0; i<10; i++){
        printf("%2d ", i+1);
        for(int j=0; j<10; j++){
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}