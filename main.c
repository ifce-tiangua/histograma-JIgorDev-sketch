#include <stdio.h>
#include <stdlib.h>

void exibir_histograma(char *hist[], int vendas[], int total_categorias)
{
    int i, j;

    for (i = 0; i < total_categorias; i++)
    {
        if (vendas[i] == 0)
        {
            printf("0\n");
        }
        else
        {
            printf("%d ", vendas[i]);

            for (j = 0; j < vendas[i]; j++)
            {
                printf("%c", hist[i][j]);
            }

            printf("\n");
        }
    }
}

int main()
{
    int numero_de_categorias;
    scanf("%d", &numero_de_categorias);

    if (numero_de_categorias == 0)
    {
        printf("vazio\n");
        return 0;
    }

    int vendas[numero_de_categorias];
    char *histograma[numero_de_categorias];
    int i, j;

    for (i = 0; i < numero_de_categorias; i++)
    {
        scanf("%d", &vendas[i]);

        if (vendas[i] == 0)
        {
            histograma[i] = NULL;
        }
        else
        {
            histograma[i] = (char *)malloc(vendas[i] * sizeof(char));

            j = 0;
            while (j < vendas[i])
            {
                histograma[i][j] = '*';
                j++;
            }
        }
    }

    exibir_histograma(histograma, vendas, numero_de_categorias);

    for (i = 0; i < numero_de_categorias; i++)
    {
        if (histograma[i] != NULL)
        {
            free(histograma[i]);
        }
    }

    return 0;
}
