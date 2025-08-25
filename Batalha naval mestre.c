#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // Posições fixas dos navios
    int linhaH = 2, colunaH = 1;
    int linhaV = 5, colunaV = 7;

    // Posicionar navio horizontal
    (colunaH + NAVIO <= TAMANHO) ? 
        ({ for (int i=0;i<NAVIO;i++) tabuleiro[linhaH][colunaH+i] = 3; }) : 0;

    // Posicionar navio vertical
    (linhaV + NAVIO <= TAMANHO) ? 
        ({ for (int i=0;i<NAVIO;i++) tabuleiro[linhaV+i][colunaV] = 3; }) : 0;

    int linha, coluna;
    char continuar = 's';

    while (continuar == 's') {
        // Mostrar tabuleiro (agora com navios visíveis)
        printf("\n=== TABULEIRO ===\n");
        printf("Legenda: 0=água, 3=navio, 1=acerto, 2=erro\n\n");

        // Cabeçalho
        printf("   ");
        for (int c=0;c<TAMANHO;c++) printf("%2d ", c);
        printf("\n");

        for (int i=0;i<TAMANHO;i++) {
            printf("%2d ", i);
            for (int j=0;j<TAMANHO;j++) {
                printf(" %d ", tabuleiro[i][j]);
            }
            printf("\n");
        }

        // Entrada
        printf("\nDigite coordenadas (linha coluna): ");
        scanf("%d %d", &linha, &coluna);

        // Verificação com ternário
        (linha<0||linha>=TAMANHO||coluna<0||coluna>=TAMANHO) ? 
            printf("❌ Coordenadas inválidas!\n") : 
            (tabuleiro[linha][coluna]==3 ? 
                (tabuleiro[linha][coluna]=1, printf("💥 Acertou um navio!\n")) :
             tabuleiro[linha][coluna]==0 ? 
                (tabuleiro[linha][coluna]=2, printf("🌊 Água...\n")) :
                printf("⚠️ Já bombardeado!\n"));

        printf("\nDeseja jogar outra bomba? (s/n): ");
        scanf(" %c", &continuar);
    }

    printf("\n=== FIM DO JOGO ===\n");
    return 0;
}
