#include <stdio.h>
// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

// Constantes para quantidade de movimentos
#define MOV_BISPO 5
#define MOV_TORRE 5
#define MOV_RAINHA 8


      // Função recursiva para o Bispo - Nível Mestre
void movimentarBispoRecursivo(int movimentos) {
    if (movimentos == MOV_BISPO && MOV_BISPO > 0) { // Adicionado MOV_BISPO > 0 para consistência
        printf("--------------------------\n");
        printf("### Movimentação do Bispo (Recursivo - %d Casas Diagonal Superior Direita) ###\n", MOV_BISPO);
        printf("--------------------------\n");
    }

    if (movimentos == 0) {
        printf("\n--------------------------\n");
        return;
    }

    printf("Cima, Direita\n"); // Ou "Cima\nDireita\n" se preferir
    movimentarBispoRecursivo(movimentos - 1);
}


// Função recursiva - Torre
void movimentarTorre(int movimentos) {
    if (movimentos == MOV_TORRE) {
        printf("### Movimentação da Torre (5 casas para Direita) ###\n");
        printf("--------------------------\n");
    }

    if (movimentos == 0) {
        printf("\n--------------------------\n");
        return;
    }

    printf("Direita\n");
    movimentarTorre(movimentos - 1);
}


// Função recursiva - Rainha
void movimentarRainha(int movimentos) {
    if (movimentos == MOV_RAINHA) {
        printf("### Movimentação da Rainha (8 casas para Esquerda) ###\n");
        printf("--------------------------\n");
    }

    if (movimentos == 0) {
        printf("\n--------------------------\n");
        return;
    }

    printf("Esquerda\n");
    movimentarRainha(movimentos - 1);
}


// Função com Condições Múltiplas - Cavalo
void movimentarCavalo() {
    printf("### Movimentação do Cavalo (1 Movimento em L - Cima e Direita) ###\n");
    printf("--------------------------\n");
    int passosCima = 0;
    int passosDireita = 0;

    // Loop com controle por múltiplas variáveis
    for (;;) {
        // Movimento na direção Cima
        if (passosCima < 2) {
            printf("Cima\n");
            passosCima++;

            if (passosCima < 2) {
                continue; // Continua subindo até alcançar 2 passos
            }
        }

        // Movimento na direção Direita
        if (passosCima == 2 && passosDireita < 1) {
            printf("Direita\n");
            passosDireita++;
            break; // Movimento em L concluído
        }
    }
    printf("\n--------------------------\n");
    printf("### Fim de Jogo ###\n");
    printf("--------------------------\n");
}


// Função Principal
int main() {
    movimentarBispoRecursivo(MOV_BISPO);    // Usando Recursão
    movimentarTorre(MOV_TORRE);             // Usando recursão
    movimentarRainha(MOV_RAINHA);           // Usando recursão
    movimentarCavalo();                     // Usando condições e variáveis múltiplas

    return 0;
}