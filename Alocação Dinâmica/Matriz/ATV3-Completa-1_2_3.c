#include <stdio.h>
#include <stdlib.h>

float **alocar_matriz_real(int m, int n);
void **liberar_matriz_real(int m, float **v);
void **criarMatriz(float **vet);
int main(){

    int m = 2, n = 2;

    float **vet = alocar_matriz_real(2, 2);

       for(int i = 0; i < m; i++){
        printf("\n");
        for(int j = 0; j < n; j++){
            printf("%.1f ", vet[i][j]);
        }
    }

    liberar_matriz_real(2, vet);

    criarMatriz(vet);

}

//QUESTÃO 1
float **alocar_matriz_real(int m, int n){

    float **mat;

    mat = (float **)malloc(m*sizeof(float *));

    for(int i = 0; i < m; i++)
        mat[i] = (float *)malloc(n*sizeof(float));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%f", &mat[i][j]);
        }
    }

    return mat;
}

//QUESTÃO 2
void **liberar_matriz_real(int m, float **v){

    for(int i = 0; i < m; i++)
        free(v[i]);

    free(v);

}

//QUESTÃO 3
void **criarMatriz(float **vet){

    int m, n;
    printf("\n");
    printf("Qual o tamanho da matriz? ");
    scanf("%d %d", &m, &n);

    vet = (float **)malloc(m*sizeof(float *));

    for(int i = 0; i < m; i++)
        vet[i] = (float *)malloc(n*sizeof(float));

    for(int i = 0; i < m; i++){
        printf("\n");
        for(int j = 0; j < n; j++){
            scanf("%f", &vet[i][j]);
        }
    }

    for(int i = 0; i < m; i++){
        printf("\n");
        for(int j = 0; j < n; j++){
            printf("%.1f ", vet[i][j]);
        }
    }
}
