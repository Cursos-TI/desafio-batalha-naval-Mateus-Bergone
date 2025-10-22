#include <stdio.h>
#include <stdlib.h>

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

//HABILIDADES
#define S_HAB 5  //tamanho das matrizes de habilidade
    int cone[S_HAB][S_HAB];
    int cruz[S_HAB][S_HAB];
    int octaedro[S_HAB][S_HAB];

    //CONE apontando para baixo.
    for (int i = 0; i < S_HAB; i++) {
        for (int j = 0; j < S_HAB; j++) {
            int centro = S_HAB/2; // 2
            if (i == 0) cone[i][j] = (j == centro) ? 1 : 0;
            else if (i == 1) cone[i][j] = (j >= centro-1 && j <= centro+1) ? 1 : 0;
            else if (i == 2) cone[i][j] = (j >= centro-2 && j <= centro+2) ? 1 : 0;
            else if (i == 3) cone[i][j] = (j >= centro-2 && j <= centro+2) ? 1 : 0;
            else cone[i][j] = 0;
        }
    }

    //CRUZ (centro é origem)
    for (int i = 0; i < S_HAB; i++) {
        for (int j = 0; j < S_HAB; j++) {
            int centro = S_HAB/2;
            cruz[i][j] = (i == centro || j == centro) ? 1 : 0;
        }
    }

    //OCTAEDRO
    for (int i = 0; i < S_HAB; i++) {
        for (int j = 0; j < S_HAB; j++) {
            int centro = S_HAB/2;
            int dist = abs(i - centro) + abs(j - centro);
            octaedro[i][j] = (dist <= 2) ? 1 : 0;
        }
    }

    // Pontos de origem no tabuleiro (linha, coluna)
    int origemConeL = 0, origemConeC = 7; //cone mais à direita no topo
    int origemCruzL = 3, origemCruzC = 5; //cruz mais ao centro
    int origemOctL = 7, origemOctC = 4;   //octaedro mais abaixo

    // Aplicar CONE:
    for (int i = 0; i < S_HAB; i++) {
        for (int j = 0; j < S_HAB; j++) {
            int tabL = origemConeL + (i - 0);
            int tabC = origemConeC + (j - S_HAB/2);
            if (tabL >= 0 && tabL < 10 && tabC >= 0 && tabC < 10) {
                if (cone[i][j] == 1 && tabuleiro[tabL][tabC] != 3) tabuleiro[tabL][tabC] = 5;
            }
        }
    }
    
    //Aplicar CRUZ:
    for (int i = 0; i < S_HAB; i++) {
        for (int j = 0; j < S_HAB; j++) {
            int tabL = origemCruzL + (i - S_HAB/2);
            int tabC = origemCruzC + (j - S_HAB/2);
            if (tabL >= 0 && tabL < 10 && tabC >= 0 && tabC < 10) {
                if (cruz[i][j] == 1 && tabuleiro[tabL][tabC] != 3) tabuleiro[tabL][tabC] = 5;
            }
        }
    }

    //Aplicar OCTAEDRO:
    for (int i = 0; i < S_HAB; i++) {
        for (int j = 0; j < S_HAB; j++) {
            int tabL = origemOctL + (i - S_HAB/2);
            int tabC = origemOctC + (j - S_HAB/2);
            if (tabL >= 0 && tabL < 10 && tabC >= 0 && tabC < 10) {
                if (octaedro[i][j] == 1 && tabuleiro[tabL][tabC] != 3) tabuleiro[tabL][tabC] = 5;
            }
        }
    }

    //Exibir tabuleiro com habilidades aplicadas
    printf("\n**** TABULEIRO COM HABILIDADES ****\n\n");
    printf("   ");

    for(int j=0; j<10; j++) printf(" %c ", colunas[j]);
    printf("\n");
    for(int i=0; i<10; i++){
        printf("%2d ", i+1);
        for(int j=0; j<10; j++){
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}