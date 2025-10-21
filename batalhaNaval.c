#include <stdio.h>

int main() {
    char linha[10]= {'A','B','C','D','E','F','G','H','I','J'};
    //Tabuleiro 10x10
    int tabuleiro[10][10];
    //Inicializando o tabuleiro com 0
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                tabuleiro[i][j] = 0;
            }
        }

        // Posicionando navio horizontal, começando em (linha 2, coluna 4)
        int linhaH = 2, colunaH = 4;
        for(int k=0; k<3; k++) {
            tabuleiro[linhaH][colunaH + k] = 3;
        }

        // Posicionando navio vertical, começando em (linha 6, coluna 7)
        int linhaV = 6, colunaV = 7;
        for(int k=0; k<3; k++) {
            tabuleiro[linhaV + k][colunaV] = 3;
        }

    //Exibindo o tabuleiro com letras e números
    printf("**** TABULEIRO BATALHA NAVAL ****\n\n");
    printf("   "); // Espaço para alinhar os números das colunas

    for(int j=0; j<10; j++) {
        printf("%2d ", j+1); // Números das colunas
    }
    printf("\n");
    for(int i=0; i<10; i++){
        printf("%c  ", linha[i]); // Letra da linha
        for(int j=0; j<10; j++){
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}