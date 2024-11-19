#include <stdio.h>
#include <stdlib.h>

void preenche_histograma(char *histograma[], int vendas, int categoria) {
    int j;
    for (j = 0; j < vendas; j++) {
        histograma[categoria][j] = '*';
    }
}

void imprimir_histograma(char *histograma[], int quantidade_de_vendas[], int numero_de_categorias) {
    int i, j;
    for (i = 0; i < numero_de_categorias; i++) {
        printf("%d ", quantidade_de_vendas[i]);

        if (quantidade_de_vendas[i] == 0) {
            printf("\n");
        } else {
            for (j = 0; j < quantidade_de_vendas[i]; j++) {
                printf("%c", histograma[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int numero_de_categorias;
    scanf("%d", &numero_de_categorias);

    if (numero_de_categorias == 0) {
        printf("vazio\n");
        return 0;
    }

    int *quantidade_de_vendas = (int*) malloc(numero_de_categorias * sizeof(int));
    char **histograma = (char**) malloc(numero_de_categorias * sizeof(char*));

    int i;
    for (i = 0; i < numero_de_categorias; i++) {
        scanf("%d", &quantidade_de_vendas[i]);

        if (quantidade_de_vendas[i] == 0) {
            histograma[i] = NULL;
        } else {
            histograma[i] = (char*) malloc(quantidade_de_vendas[i] * sizeof(char));
            preenche_histograma(histograma, quantidade_de_vendas[i], i);
        }
    }

    imprimir_histograma(histograma, quantidade_de_vendas, numero_de_categorias);

    for (i = 0; i < numero_de_categorias; i++) {
        if (quantidade_de_vendas[i] > 0) {
            free(histograma[i]);
        }
    }
    free(quantidade_de_vendas);
    free(histograma);

    return 0;
}
