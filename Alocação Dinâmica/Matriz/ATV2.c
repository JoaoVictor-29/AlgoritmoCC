//QUESTÃO 2
void **liberar_matriz_real(int m, float **v){

    for(int i = 0; i < m; i++)
        free(v[i]);

    free(v);

}
