#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jogo_adivinhacao.h"

int numerosecreto;
int chutes;
int tentativas = 1;
int numtentativas;
double pontos = 1000;

void abertura() {
    printf("*********************\n");
    printf("*     Bem-Vindo     *\n");
    printf("*********************\n\n");
    
    printf("Tente descobrir em qual numero eu estou pensando de 1 a 100\n\n");
}

void dificuldade() {
    int nivel;

    printf("qual o nivel de difilculdade que voce deseja?\n");
    printf("(1) facil (2) medio (3) dificil\n");
    scanf("%d", &nivel);

    switch (nivel) {
    case 1:
        numtentativas = 10;
        break;
    case 2:
        numtentativas = 8;
        break;
    case 3:
        numtentativas = 6;
        break;
    default:
        printf("e pra escolher um numero de 1 a 3\n");
        break;
    }
}

void escolhe() {
    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();

    numerosecreto = numerogrande % 100;
}

void tamanho() {
    int maior = (chutes > numerosecreto);

        if(maior) {
            printf("Esse numero e maior do que o numero que estou pensando\n\n");
        } else {
            printf("Esse numero e menor do que o numero que eu estou pensando\n\n");
        }

}

void pontuacao() {
    double pontosperdidos = abs(tentativas - numerosecreto) / (double)2;
    pontos = pontos - pontosperdidos;
}

void fimdejogo() {
    int acertou;
    acertou = (chutes == numerosecreto);

        if(acertou) {
        printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\n\n");

        printf("Parabens! Voce ganhou!\n");
        printf("Voce acertou em %d tentativas!\n\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);

        } else {
        printf("       \\|/ ____ \\|/    \n");  
        printf("        @~/ ,. \\~@      \n");  
        printf("       /_( \\__/ )_\\    \n");  
        printf("          \\__U_/        \n");

        printf("Voce perdeu! Tente de novo!\n");
        }

}


int main() {

    abertura();
    dificuldade();
    escolhe();

    for(int i = 1; i <= numtentativas; i++) {
        printf("Tentativa %d de %d\n", i, numtentativas);
        printf("Qual o seu chute? ");
        scanf("%d", &chutes);

        if(chutes != numerosecreto) {
        tamanho();
        tentativas++;
        } else {
            break;
        }
    }

    pontuacao();
    fimdejogo();

}