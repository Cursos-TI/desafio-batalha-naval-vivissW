#include <stdio.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3
#define TAM_HAB 7
#define EFEITO 5
#define AGUA 0

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    int cone[TAM_HAB][TAM_HAB] = {0};
    int cruz[TAM_HAB][TAM_HAB] = {0};
    int octaedro[TAM_HAB][TAM_HAB] = {0};

    int centro = TAM_HAB / 2;

    // Inicializando o tabuleiro com água
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Navios
    int navio_horizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navio_vertical[TAMANHO_NAVIO] = {3, 3, 3};
    int navio_diagonal[TAMANHO_NAVIO] = {3, 3, 3};

    // Navio horizontal
    int linhaH = 1;
    int colunaH = 3;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = navio_horizontal[i];
    }

    // Navio vertical
    int linhaV = 5;
    int colunaV = 6;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = navio_vertical[i];
    }

    // Navios diagonais
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[6 - i][i] = 3;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[i][9 - i] = 3;
    }

    // Inicializando habilidades com 0 e definindo posições afetadas com 1

    // Cone (triângulo apontando para baixo a partir do topo central)
    for (int i = 0; i <= centro; i++) {
        for (int j = centro - i; j <= centro + i; j++) {
            cone[i][j] = 1;
        }
    }

    // Cruz (linha e coluna central)
    for (int i = 0; i < TAM_HAB; i++) {
        cruz[centro][i] = 1; // linha central
        cruz[i][centro] = 1; // coluna central
    }

    // Octaedro (forma de losango)
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if ((i - centro) + (j - centro) <= centro) {
                octaedro[i][j] = 1;
            }
        }
    }

    // Aplicando habilidades no tabuleiro

    // Cone
    int origemCone[2] = {2, 4};
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (cone[i][j] == 1) {
                int x = origemCone[0] - centro + i;
                int y = origemCone[1] - centro + j;
                if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO && tabuleiro[x][y] == AGUA) {
                    tabuleiro[x][y] = EFEITO;
                }
            }
        }
    }

    // Cruz
    int origemCruz[2] = {5, 5};
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (cruz[i][j] == 1) {
                int x = origemCruz[0] - centro + i;
                int y = origemCruz[1] - centro + j;
                if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO && tabuleiro[x][y] == AGUA) {
                    tabuleiro[x][y] = EFEITO;
                }
            }
        }
    }

    // Octaedro
    int origemOct[2] = {7, 7};
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (octaedro[i][j] == 1) {
                int x = origemOct[0] - centro + i;
                int y = origemOct[1] - centro + j;
                if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO && tabuleiro[x][y] == AGUA) {
                    tabuleiro[x][y] = EFEITO;
                }
            }
        }
    }

    // Exibir o tabuleiro final
    printf("   ");
    for (char letra = 'A'; letra < 'A' + TAMANHO; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
