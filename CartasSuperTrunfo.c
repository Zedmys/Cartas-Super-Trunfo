#include <stdio.h>

//-----------------------------------------------------------------------------
// ESTRUTURA DE DADOS
//-----------------------------------------------------------------------------

// Usar um 'typedef struct' nos permite criar um tipo de dado personalizado 'Carta'.
// Isso organiza o código, pois podemos passar uma única 'Carta' para uma função
// em vez de múltiplas variáveis separadas.
typedef struct {
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;


//-----------------------------------------------------------------------------
// PROTÓTIPOS DAS FUNÇÕES
//-----------------------------------------------------------------------------

// Declarar as funções aqui (protótipos) é uma boa prática em C.
// Isso informa ao compilador quais funções existem antes de serem usadas.

/**
 * @brief Coleta os dados de uma carta do usuário via terminal.
 * @param c Ponteiro para a struct Carta que será preenchida.
 */
void cadastrar_carta(Carta *c);

/**
 * @brief Exibe os dados, calcula os atributos derivados, e compara as duas cartas.
 * @param c1 A primeira carta a ser comparada.
 * @param c2 A segunda carta a ser comparada.
 */
void analisar_e_comparar_cartas(Carta c1, Carta c2);


//-----------------------------------------------------------------------------
// FUNÇÃO PRINCIPAL
//-----------------------------------------------------------------------------

// A função main() agora serve como um "maestro", orquestrando as chamadas
// para as outras funções e mantendo a lógica principal limpa e simples.
int main() {
    // Declaração das duas cartas que serão usadas no jogo.
    Carta carta1, carta2;

    // --- FASE 1: CADASTRO ---
    printf("--- Super Trunfo: Cadastro das Cartas ---\n\n");

    printf("--- Inserir dados da Carta 1 ---\n");
    cadastrar_carta(&carta1); // Passamos o endereço da carta1 para a função

    printf("\n--- Inserir dados da Carta 2 ---\n");
    cadastrar_carta(&carta2); // Passamos o endereço da carta2 para a função

    // --- FASE 2: ANÁLISE E COMPARAÇÃO ---
    printf("\n\n--- ANÁLISE E RESULTADO DAS COMPARAÇÕES ---\n");
    analisar_e_comparar_cartas(carta1, carta2);

    return 0; // Indica que o programa foi concluído com sucesso.
}


//-----------------------------------------------------------------------------
// IMPLEMENTAÇÃO DAS FUNÇÕES
//-----------------------------------------------------------------------------

void cadastrar_carta(Carta *c) {
    // A função recebe um ponteiro, então usamos '->' para acessar os membros da struct.
    printf("Digite a populacao: ");
    scanf("%lu", &c->populacao); // %lu para unsigned long int

    printf("Digite a area (em km2): ");
    scanf("%f", &c->area);

    printf("Digite o PIB (em bilhoes): ");
    scanf("%f", &c->pib);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &c->pontos_turisticos);
}

void analisar_e_comparar_cartas(Carta c1, Carta c2) {
    // --- Nível Aventureiro: Cálculo de Atributos ---
    float densidade1 = 0, pib_per_capita1 = 0;
    float densidade2 = 0, pib_per_capita2 = 0;

    // Verificações para evitar divisão por zero, um erro crítico.
    if (c1.area > 0) {
        densidade1 = (float)c1.populacao / c1.area;
    }
    if (c1.populacao > 0) {
        pib_per_capita1 = (c1.pib * 1000000000) / c1.populacao;
    }

    if (c2.area > 0) {
        densidade2 = (float)c2.populacao / c2.area;
    }
    if (c2.populacao > 0) {
        pib_per_capita2 = (c2.pib * 1000000000) / c2.populacao;
    }
    
    // Exibição dos dados completos
    printf("\n--- DADOS DA CARTA 1 ---\n");
    printf("Populacao: %lu\n", c1.populacao);
    printf("Area: %.2f km2\n", c1.area);
    printf("PIB: R$ %.2f bilhoes\n", c1.pib);
    printf("Pontos Turisticos: %d\n", c1.pontos_turisticos);
    printf("-> Densidade Populacional: %.2f hab/km2\n", densidade1);
    printf("-> PIB per Capita: R$ %.2f\n", pib_per_capita1);

    printf("\n--- DADOS DA CARTA 2 ---\n");
    printf("Populacao: %lu\n", c2.populacao);
    printf("Area: %.2f km2\n", c2.area);
    printf("PIB: R$ %.2f bilhoes\n", c2.pib);
    printf("Pontos Turisticos: %d\n", c2.pontos_turisticos);
    printf("-> Densidade Populacional: %.2f hab/km2\n", densidade2);
    printf("-> PIB per Capita: R$ %.2f\n", pib_per_capita2);

    // --- Nível Mestre: Comparação Atributo a Atributo ---
    // O resultado é 1 se a Carta 1 vencer, ou 0 caso contrário (vitória da Carta 2 ou empate).
    printf("\n--- COMPARACAO (1 = Carta 1 vence, 0 = Carta 2 vence/empata) ---\n");
    printf("Populacao: %d\n", c1.populacao > c2.populacao ? 1 : 0);
    printf("Area: %d\n", c1.area > c2.area ? 1 : 0);
    printf("PIB: %d\n", c1.pib > c2.pib ? 1 : 0);
    printf("Pontos Turisticos: %d\n", c1.pontos_turisticos > c2.pontos_turisticos ? 1 : 0);
    printf("PIB per Capita: %d\n", pib_per_capita1 > pib_per_capita2 ? 1 : 0);
    
    // Regra especial para Densidade: menor valor vence.
    printf("Densidade Populacional: %d\n", densidade1 < densidade2 ? 1 : 0);

    // --- Nível Mestre: Cálculo e Comparação do Super Poder ---
    // O 'cast' (float) garante que a soma seja feita com precisão de ponto flutuante.
    // Usamos 1.0f para garantir que a divisão da densidade seja feita com floats.
    float super_poder1 = (float)c1.populacao + c1.area + c1.pib + (float)c1.pontos_turisticos + pib_per_capita1 + (1.0f / densidade1);
    float super_poder2 = (float)c2.populacao + c2.area + c2.pib + (float)c2.pontos_turisticos + pib_per_capita2 + (1.0f / densidade2);

    printf("\n--- SUPER PODER ---\n");
    printf("Super Poder da Carta 1: %.2f\n", super_poder1);
    printf("Super Poder da Carta 2: %.2f\n", super_poder2);
    printf("Resultado da disputa de Super Poder: %d\n", super_poder1 > super_poder2 ? 1 : 0);
}