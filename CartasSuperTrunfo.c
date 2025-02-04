#include <stdio.h>
#include <string.h>

#define NUM_ESTADOS 8
#define CIDADES_POR_ESTADO 4

typedef struct {
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

void cadastrarCartas(Carta cartas[]) {
    char estados[NUM_ESTADOS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int index = 0;

    printf("Cadastro de cartas do Super Trunfo - Países\n");
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 1; j <= CIDADES_POR_ESTADO; j++) {
            // Gerar código da carta
            snprintf(cartas[index].codigo, sizeof(cartas[index].codigo), "%c%02d", estados[i], j);

            printf("\nCadastro da cidade: %s\n", cartas[index].codigo);

            printf("Digite a população: ");
            scanf("%d", &cartas[index].populacao);

            printf("Digite a área (em km²): ");
            scanf("%f", &cartas[index].area);

            printf("Digite o PIB (em bilhões de USD): ");
            scanf("%f", &cartas[index].pib);

            printf("Digite o número de pontos turísticos: ");
            scanf("%d", &cartas[index].pontos_turisticos);

            // Cálculo da densidade populacional e PIB per capita
            if (cartas[index].area > 0) {
                cartas[index].densidade_populacional = cartas[index].populacao / cartas[index].area;
            } else {
                cartas[index].densidade_populacional = 0.0;
            }

            if (cartas[index].populacao > 0) {
                cartas[index].pib_per_capita = cartas[index].pib / cartas[index].populacao;
            } else {
                cartas[index].pib_per_capita = 0.0;
            }

            index++;
        }
    }
}

void exibirCartas(Carta cartas[], int totalCartas) {
    printf("\nCartas cadastradas:\n");
    for (int i = 0; i < totalCartas; i++) {
        printf("\nCidade: %s\n", cartas[i].codigo);
        printf("População: %d\n", cartas[i].populacao);
        printf("Densidade populacional: %.2f hab/km²\n", cartas[i].densidade_populacional);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f bilhões de USD\n", cartas[i].pib);
        printf("PIB per capita: %.2f USD\n", cartas[i].pib_per_capita * 1e6); // PIB em milhões por habitante
        printf("Pontos turísticos: %d\n", cartas[i].pontos_turisticos);
    }
}

int main() {
    Carta cartas[NUM_ESTADOS * CIDADES_POR_ESTADO];

    cadastrarCartas(cartas);
    exibirCartas(cartas, NUM_ESTADOS * CIDADES_POR_ESTADO);

    return 0;
}
