#include <stdio.h>
#include <stdlib.h>

void **alocar_matriz_real(int m, int n);
int main(){

    int m = 2, n = 2;

    /*float **vet = */alocar_matriz_real(2, 2);

   /* for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%.1f %.1f", vet[i][j]);
        }
    }
*/
}

void **alocar_matriz_real(int m, int n){

    float **mat;

    mat = (float **)malloc(m*sizeof(float *));

    for(int i = 0; i < m; i++)
        mat[i] = (float *)malloc(n*sizeof(float));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%f", &mat[m][n]);
        }
    }

     for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%f %f", mat[i][j]);
        }
    }
    /*return mat;*/
}
