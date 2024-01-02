/**
 * Calculadora de polinômios - Trabalho acadêmico.
 * 
 * Autor: Vitor Arantes Vendramini
 * Criado em: 10 de Setembro de 2023
 * Última modificação: 26 de Setembro de 2023
 * 
 */

#include <stdio.h>
#include <locale.h>
#include <math.h>

/**
 * @brief Imprime um polinômio.
 *
 * Esta função imprime um polinômio dado um array de termos e seu grau.
 * Somente termos não nulos são impressos.
 *
 * @param termos Array contendo os coeficientes do polinômio.
 * @param grau Grau do polinômio.
 */
void imprimir_polinomio(int termos[], int grau)
{
    int i;

    for (i = grau; i >= 0; i--)
    {
        if (termos[i] != 0)
        { 
            if (i == grau)              // Primeiro termo.
            { 
                printf("%dx^%d", termos[i], i);
            }
            else if (i == 0)            // Último termo.
            { 
                if (termos[i] > 0)
                {
                    printf(" + %d", termos[i]);
                }
                else
                {
                    printf(" - %d", -termos[i]);
                }
            }
            else                        // Termos intermediários.
            { 
                if (termos[i] > 0)
                {
                    printf(" + %dx^%d", termos[i], i);
                }
                else
                {
                    printf(" - %dx^%d", -termos[i], i);
                }
            }
        }
    }
    printf("\n");
}

/**
 * @brief Calcula o valor de um polinômio para um dado x.
 *
 * Esta função calcula o valor do polinômio para um dado valor de x,
 * usando a expressão: valor = termo[i] * x^i.
 *
 * @param polinomio Array contendo os coeficientes do polinômio.
 * @param grau Grau do polinômio.
 * @param x O valor de x para avaliação do polinômio.
 * @return Retorna o valor calculado do polinômio.
 */
float valor_polinomio(int polinomio[], int grau, float x)
{
    float valor = 0;
    int i;

    for (i = grau; i >= 0; i--)   
    {
        valor += polinomio[i] * pow(x, i);
    }

    return valor;
}

/**
 * @brief Soma dois polinômios.
 *
 * Esta função soma dois polinômios e armazena o resultado em um terceiro array.
 *
 * @param termos1 Array dos coeficientes do primeiro polinômio.
 * @param grau1 Grau do primeiro polinômio.
 * @param termos2 Array dos coeficientes do segundo polinômio.
 * @param grau2 Grau do segundo polinômio.
 * @param resultado Array para armazenar o polinômio resultante.
 * @param grauR Grau do polinômio resultante.
 */
void soma_polinomio(int termos1[], int grau1, int termos2[], int grau2, int resultado[], int grauR)
{
    int i;

    for (i = 0; i <= grauR; i++) 
    {
        resultado[i] = 0;
    }

    for (i = 0; i <= grau1; i++)
    {
        resultado[i] += termos1[i];     
    }

    for (i = 0; i <= grau2; i++)
    {
        resultado[i] += termos2[i];
    }
}

/**
 * @brief Multiplica dois polinômios.
 *
 * Esta função multiplica dois polinômios e armazena o resultado em um array.
 *
 * @param termos1 Array dos coeficientes do primeiro polinômio.
 * @param grau1 Grau do primeiro polinômio.
 * @param termos2 Array dos coeficientes do segundo polinômio.
 * @param grau2 Grau do segundo polinômio.
 * @param resultado Array para armazenar o polinômio resultante.
 */
void multiplicacao_polinomio(int termos1[], int grau1, int termos2[], int grau2, int resultado[])
{
    int i, j;

    for (i = 0; i <= grau1 + grau2; i++)
    {
        resultado[i] = 0;
    }

    for (i = 0; i <= grau1; i++)                    
    {
        for (j = 0; j <= grau2; j++)
        {
            resultado[i + j] += termos1[i] * termos2[j];
        }
    }
}

/**
 * @brief Função principal do programa que permite ao usuário calcular valores, somas e multiplicações de polinômios.
 *
 * Esta função exibe um menu interativo onde o usuário pode escolher entre calcular o valor de um polinômio em um dado ponto, somar dois polinômios,
 * multiplicar dois polinômios ou sair do programa. Cada opção do menu leva a uma série de solicitações de entrada para coletar os coeficientes
 * e, quando necessário, os graus dos polinômios envolvidos nas operações. Após a execução de cada operação, os resultados são exibidos na tela.
 *
 * Conforme as instruções do professor, todos os "printf" deveriam estar apenas na função main.
 */
int main()
{
    int escolha;
    setlocale(LC_ALL, "Portuguese_Brazil");

    while (1)
    {
        printf("\n---Menu---:\n");
        printf("1. Calcular o valor de polinômio\n");
        printf("2. Calcular a soma de polinômios\n");
        printf("3. Calcular a multiplicação de polinômios\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        if (escolha == 1)
        {
            int grau, i;
            printf("Digite o grau do polinômio: ");
            scanf("%d", &grau);

            int polinomio[grau + 1];

            printf("Digite os coeficientes do polinômio em ordem decrescente dos expoentes:\n");

            for (i = grau; i >= 0; i--)
            {
                printf("Coeficiente de x^%d: ", i);
                scanf("%d", &polinomio[i]);
            }

            float x;

            printf("Digite o valor de x: ");
            scanf("%f", &x);

            printf("P(%.2f) = %.2f\n", x, valor_polinomio(polinomio, grau, x));

            printf("Pressione 'Enter' para continuar...");
            getchar();
            getchar();
        }

        else if (escolha == 2)
        {
            int grau1, grau2, grauResultado, i;

            printf("\nDigite o grau do primeiro polinômio: ");
            scanf("%d", &grau1);

            int termos1[grau1 + 1];

            printf("\nDigite os coeficientes do primeiro polinômio em ordem decrescente dos expoentes:\n");

            for (i = grau1; i >= 0; i--)
            {
                printf("Coeficiente de x^%d: ", i);
                scanf("%d", &termos1[i]);
            }

            printf("\nDigite o grau do segundo polinômio: ");
            scanf("%d", &grau2);

            int termos2[grau2 + 1];

            printf("\nDigite os coeficientes do segundo polinômio em ordem decrescente dos expoentes:\n");

            for (i = grau2; i >= 0; i--)
            {
                printf("Coeficiente de x^%d: ", i);
                scanf("%d", &termos2[i]);
            }

            if (grau1 > grau2)
            {
                grauResultado = grau1;
            }
            else
            {
                grauResultado = grau2;
            }

            int resultado[grauResultado];

            soma_polinomio(termos1, grau1, termos2, grau2, resultado, grauResultado);

            printf("\nA soma entre P(x) e Q(x) = ");
            imprimir_polinomio(resultado, grauResultado);

            printf("Pressione 'Enter' para continuar...");
            getchar();
            getchar();
        }

        else if (escolha == 3)
        {
            int grau1, grau2, i;

            printf("\nDigite o grau do primeiro polinômio: ");
            scanf("%d", &grau1);

            int termos1[grau1 + 1];

            printf("\nDigite os coeficientes do primeiro polinômio em ordem decrescente dos expoentes:\n");

            for (i = grau1; i >= 0; i--)
            {
                printf("Coeficiente de x^%d: ", i);
                scanf("%d", &termos1[i]);
            }

            printf("\nDigite o grau do segundo polinômio: ");
            scanf("%d", &grau2);

            int termos2[grau2 + 1];

            printf("\nDigite os coeficientes do segundo polinômio em ordem decrescente dos expoentes:\n");

            for (i = grau2; i >= 0; i--)
            {
                printf("Coeficiente de x^%d: ", i);
                scanf("%d", &termos2[i]);
            }

            int resultado[grau1 + grau2];

            multiplicacao_polinomio(termos1, grau1, termos2, grau2, resultado);

            printf("\nA multiplicação entre P(x) e Q(x) = ");
            imprimir_polinomio(resultado, grau1 + grau2);

            printf("Pressione 'Enter' para continuar...");
            getchar();
            getchar();
        }

        else if (escolha == 4)
        {
            printf("Saindo...\n");
            break;
        }
        else
        {
            printf("Opção inválida. Tente novamente.\n");
        }
    }
    return 0;
}
