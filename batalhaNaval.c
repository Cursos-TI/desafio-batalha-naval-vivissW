

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

    // Nível Novato - Posicionamento dos Navios
   #include <stdio.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    

    // água
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Cabeçalho com letras (A-J)
    printf("   ");
    for (char letra = 'A'; letra < 'A' + TAMANHO; letra++) {
        printf("%c ", letra);
    }
    printf("\n");

    // Exibe o tabuleiro com numeração das linhas (1-10)
    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1); // numeração da linha
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
     
    // navios 
    int navio_horizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navio_vertical[TAMANHO_NAVIO] = {3, 3, 3};


    int linhaH = 1;    // linha 2
    int colunaH = 3;   // coluna 4
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = navio_horizontal[i];
    }

    // Posiciona navio vertical na coluna 7, linhas 6 a 8 (índices 5–7, 6)
    int linhaV = 5;    // linha 6
    int colunaV = 6;   // coluna 7
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = navio_vertical[i];
    }

    return 0;
}

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
