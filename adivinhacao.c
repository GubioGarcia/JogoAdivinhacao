#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("\n");
    printf("*Bem vindo ao jogo de adivinhacao*\n \n");

    // Declara o numeroSecreto de forma aleatoria 
    int numeroSecreto;
    srand(time(NULL));  // Define a semente do gerador de números aleatórios
    numeroSecreto = rand();   // Gera um número aleatório entre 0 e RAND_MAX
    numeroSecreto = numeroSecreto % 100;   // Limita o número ao intervalo desejado (1-100)

    // Prepara para o chute inicial do Usuario
    int numeroUsuario;
    int tentativasMaximas;
    float pontos = 1000.0;

    int nivel;
    printf("Escoha o nivel de dificuldade: \n");
    printf("(1) Facil, (2) Medio, (3) Dificil \n");
    printf("Digite o numero correspondente ao nivel desejado: ");
    scanf("%d", &nivel);

    while (nivel < 1 || nivel > 3) {
        printf("Informe um nivel valido: ");
        scanf("%d", &nivel);
    }

    switch (nivel)  {
        case 1:
            tentativasMaximas = 20;
            break;
        
        case 2:
            tentativasMaximas = 15;
            break;

        default:
            tentativasMaximas = 6;
            break;
    }

    printf("\nTente acertar o numero secreto definido aleatoriamente pertencente ao intervalo de 1 a 100. \n");

    // Recebe chutes e retorna informacoes pertinentes ao usuario
    // while (numeroUsuario != numeroSecreto)
    int numeroTentativas;
    for (numeroTentativas = 1; numeroTentativas <= tentativasMaximas; numeroTentativas++) {
        printf("Qual o seu palpite? ");
        scanf("%d", &numeroUsuario);
        if (numeroUsuario <= 0 || numeroUsuario > 100) {
            printf("Informe um numero pertencente ao intervalo 1 a 100 \n");
            numeroTentativas--;
        } else {
            printf("Seu chute foi: %d.\n", numeroUsuario);
        }

        if (numeroUsuario == numeroSecreto) break;
        else if  (numeroUsuario > numeroSecreto) {
            pontos = pontos - (numeroUsuario - numeroSecreto) / 2.0;
            printf("Seu chute foi maior que o numero secreto. Tentativa %d. \n", numeroTentativas);
        } else {
            pontos = pontos - (numeroSecreto - numeroUsuario) / 2.0;
            printf("Seu chute foi menor que o numero secreto. Tentativa %d. \n", numeroTentativas);
        }
    }

    if (numeroUsuario == numeroSecreto) {
        printf("\nParabens! Voce acertou com %d tentativas! Pontuacao Final = %.1f \n", numeroTentativas, pontos);
        printf("Voce e um bom jogador! Reinicie o jogo para uma nova rodada.\n");
    } else {
        printf("\nVOCE PERDEU!\nO numero secreto era: %d.\nReinicie e tente novamente.\n", numeroSecreto);
    }

    return 0;
}