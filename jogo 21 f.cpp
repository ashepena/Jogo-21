#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar uma carta (1 a 10)
int gCarta() {
    return (rand() % 10) + 1;
}

// Função para distribuir cartas iniciais
int qCartas() {
    int soma = 0, carta;

    printf("Suas cartas iniciais sao:\n");
    for (int i = 0; i < 3; i++) {
        carta = gCarta();
        printf("Carta %d: %d\n", i + 1, carta);
        soma += carta;
    }

    printf("Soma total: %d\n", soma);
    return soma;
}

// Função do turno do jogador
int turnoJ(int soma) {
    char r;
    int carta;

    while (soma < 21) {
        printf("Deseja mais uma carta? (s/n): ");
        scanf(" %c", &r);

        if (r == 's' || r == 'S') {
            carta = gCarta();
            printf("Voce recebeu um %d\n", carta);
            soma += carta;
            printf("Nova soma: %d\n", soma);
        } else {
            break;
        }
    }

    return soma;
}

// Função do turno do computador
int turnoC() {
    return (rand() % 19) +  3;
}

// Função para verificar o resultado
int verificar(int jogador, int computador) {
    if (jogador > 21) {
        printf("\nSuas cartas somam %d. Voce passou de 21 e perdeu!\n", jogador);
        return -1; // derrota
    }

    printf("\nComputador fez %d pontos.\n", computador);

    if (jogador > computador) {
        printf("Parabens! Voce venceu esta rodada!\n");
        return 1; // vitória
    } else if (jogador == computador) {
        printf("Empate!\n");
        return 0; // empate
    } else {
        printf("O computador venceu!\n");
        return -1; // derrota
    }
}

int main() {
    int jogador, computador;
    int vitorias = 0, derrotas = 0, empate = 0;
    char r;

    srand(time(NULL));

    do {
        printf("\n=== JOGO 21 ===\n");

        jogador = qCartas();
        jogador = turnoJ(jogador);

        if (jogador > 21) {
            printf("\nVoce perdeu!\n");
            derrotas++;
        } else {
            computador = turnoC();
            int r = verificar(jogador, computador);

            if (r == 1) vitorias++;
            else if (r == 0) empate++;
            else derrotas++;
        }

        printf("\nPlacar atual: %d vitoria(s), %d empate(s) e %d derrota(s)\n",
               vitorias, empate, derrotas);

        printf("\nDeseja jogar novamente? (s/n): ");
        scanf(" %c", &r);

    } while (r == 's' || r == 'S');

    printf("\nJogo encerrado. Placar final: %d vitoria(s), %d empate(s) e %d derrota(s)\n",
           vitorias, empate, derrotas);

    printf("Obrigado por jogar!\n");

    return 0;
}  
