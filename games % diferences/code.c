#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[50];
    int jogadores_ativos;
} Jogo;

void classificarJogos(Jogo* jogos, int num_jogos) {
    int i, j;
    for (i = 0; i < num_jogos - 1; i++) {
        for (j = 0; j < num_jogos - i - 1; j++) {
            if (jogos[j].jogadores_ativos < jogos[j+1].jogadores_ativos) {
                Jogo temp = jogos[j];
                jogos[j] = jogos[j+1];
                jogos[j+1] = temp;
            }
        }
    }
}

void exibirClassificacao(Jogo* jogos, int num_jogos) {
    int total_jogadores = 0;
    int i;
    for (i = 0; i < num_jogos; i++) {
        total_jogadores += jogos[i].jogadores_ativos;
    }

    printf("Classificação dos jogos mais jogados:\n");
    for (i = 0; i < num_jogos; i++) {
        float porcentagem_ativos = ((float) jogos[i].jogadores_ativos / total_jogadores) * 100;
        printf("%d. %s: %.2f%% de jogadores ativos\n", i+1, jogos[i].nome, porcentagem_ativos);
    }
}

int main() {
    srand(time(0));

    // Dados fictícios de jogos
    Jogo jogos[] = {
        {"Fortnite", rand() % 4000000 + 1000000},
        {"Minecraft", rand() % 500000 + 500000},
        {"League of Legends", rand() % 500000 + 500000},
        {"Valorant", rand() % 400000 + 100000},
        {"Among Us", rand() % 400000 + 100000}
    };

    int num_jogos = sizeof(jogos) / sizeof(jogos[0]);

    // Classificar os jogos pelo número de jogadores ativos
    classificarJogos(jogos, num_jogos);

    // Exibir classificação e porcentagem de jogadores ativos
    exibirClassificacao(jogos, num_jogos);

    return 0;
}
