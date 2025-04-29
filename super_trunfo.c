#include <stdio.h>
#include <string.h>

// Definição da estrutura para uma carta
typedef struct
{
    char estado;                   // Letra de A a H
    char codigo[4];                // Ex: A01 (3 chars + '\0')
    char cidade[100];              // Nome da cidade
    unsigned long int populacao;   // Número de habitantes
    float area;                    // Área em km²
    float pib;                     // PIB em bilhões de reais
    int pontos_turismo;            // Número de pontos turísticos
    float desnsidade_populacional; // Densidade populacional
    float pib_per_capita;          // PIB per capita
    float super_poder;             // Soma dos valores (população, área, PIB,
                                   // número de pontos turísticos, PIB per capita e o inverso da densidade populacional)
} Carta;

// Função que preenche e retorna uma carta
Carta preencherCarta(int num)
{
    Carta c;

    printf("Digite os dados da Carta %d:\n", num);

    printf("Estado (A-H): ");
    scanf(" %c", &c.estado); 

    printf("Código da Carta (ex: %c01): ", c.estado);
    scanf(" %3[^\n]", c.codigo);

    printf("Nome da Cidade: ");
    scanf(" %199[^\n]", c.cidade);

    printf("População: ");
    scanf("%lu", &c.populacao);

    printf("Área (km²): ");
    scanf("%f", &c.area);

    printf("PIB (bilhões de reais): ");
    scanf("%f", &c.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c.pontos_turismo);

    // Calculando densidade populacional e PIB per capita
    c.desnsidade_populacional = (float)c.populacao / c.area;
    float pib_em_bilhao = c.pib * 1e9;  // Convertendo o PIB para bilhões
    c.pib_per_capita = pib_em_bilhao / (float)c.populacao;

    // Calculando o super poder (atributo fictício)
    c.super_poder = (float)c.populacao + 
                    c.area + 
                    c.pib + 
                    (float)c.pontos_turismo + 
                    c.pib_per_capita - 
                    (1 / c.desnsidade_populacional);

    printf("\n"); // Linha em branco para separar cartas

    return c;
}

// Função para comparar cartas com base em um atributo
void compararCartas(Carta c1, Carta c2, const char* atributo)
{
    printf("Comparação de Cartas (Atributo: %s):\n", atributo);

    if (strcmp(atributo, "População") == 0)
    {
        printf("Carta 1 - %s (População: %lu)\n", c1.cidade, c1.populacao);
        printf("Carta 2 - %s (População: %lu)\n", c2.cidade, c2.populacao);
        if (c1.populacao > c2.populacao)
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.cidade);
        else
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.cidade);
    }
    else if (strcmp(atributo, "Área") == 0)
    {
        printf("Carta 1 - %s (Área: %.2f km²)\n", c1.cidade, c1.area);
        printf("Carta 2 - %s (Área: %.2f km²)\n", c2.cidade, c2.area);
        if (c1.area > c2.area)
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.cidade);
        else
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.cidade);
    }
    else if (strcmp(atributo, "PIB") == 0)
    {
        printf("Carta 1 - %s (PIB: %.2f bilhões de reais)\n", c1.cidade, c1.pib);
        printf("Carta 2 - %s (PIB: %.2f bilhões de reais)\n", c2.cidade, c2.pib);
        if (c1.pib > c2.pib)
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.cidade);
        else
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.cidade);
    }
    else if (strcmp(atributo, "Densidade Populacional") == 0)
    {
        printf("Carta 1 - %s (Densidade Populacional: %.2f hab/km²)\n", c1.cidade, c1.desnsidade_populacional);
        printf("Carta 2 - %s (Densidade Populacional: %.2f hab/km²)\n", c2.cidade, c2.desnsidade_populacional);
        if (c1.desnsidade_populacional < c2.desnsidade_populacional)
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.cidade);
        else
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.cidade);
    }
    else if (strcmp(atributo, "PIB per Capita") == 0)
    {
        printf("Carta 1 - %s (PIB per Capita: %.2f reais)\n", c1.cidade, c1.pib_per_capita);
        printf("Carta 2 - %s (PIB per Capita: %.2f reais)\n", c2.cidade, c2.pib_per_capita);
        if (c1.pib_per_capita > c2.pib_per_capita)
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.cidade);
        else
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.cidade);
    }
    else if (strcmp(atributo, "Super Poder") == 0)
    {
        printf("Carta 1 - %s (Super Poder: %.2f Pontos)\n", c1.cidade, c1.super_poder);
        printf("Carta 2 - %s (Super Poder: %.2f Pontos)\n", c2.cidade, c2.super_poder);
        if (c1.super_poder > c2.super_poder)
            printf("Resultado: Carta 1 (%s) venceu!\n", c1.cidade);
        else
            printf("Resultado: Carta 2 (%s) venceu!\n", c2.cidade);
    }

    printf("\n"); // Linha em branco para separar comparações
}

// Função para exibir os dados das cartas
void exibirCarta(Carta c)
{
    printf("Estado: %c\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Nome da Cidade: %s\n", c.cidade);
    printf("População: %lu\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões de reais\n", c.pib);
    printf("Número de Pontos Turísticos: %d\n", c.pontos_turismo);
    printf("Densidade Populacional: %.2f hab/km²\n", c.desnsidade_populacional);
    printf("PIB per Capita: %.2f reais\n", c.pib_per_capita);
    printf("Super Poder: %.2f Pontos\n", c.super_poder);
    printf("\n");
}

int main()
{
    Carta cartas[2];

    // Preencher as cartas
    cartas[0] = preencherCarta(1);
    cartas[1] = preencherCarta(2);

    // Exibir as cartas
    for (int i = 0; i < 2; i++)
    {
        printf("Carta %d:\n", i + 1);
        exibirCarta(cartas[i]);
    }

    // Comparar as cartas baseadas no atributo escolhido
    compararCartas(cartas[0], cartas[1], "População"); // Altere o atributo conforme necessário

    return 0;
}
