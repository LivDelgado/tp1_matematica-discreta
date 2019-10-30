#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h> 

void imprimeQuadradoMagico(int** q, int n){
    int i, j;
    printf("n = %d, Soma = %d\n",  n, (n * (n*n + 1)/2)); 
    
    for (i = 0; i < n; i++){ 
        
        for (j = 0; j < n; j++) {
            printf("%3d ", q[i][j]); 
        }
        
        printf("\n\n"); 
    }
}
 
int** quadradoMagicoImpar(int n) {
    if (n < 3 || n % 2 == 0)
        return NULL;

    int valor = 0;
    int tamanhoQuadrado = n*n;
    int c = n / 2, r = 0, i;

    int** quadradoMagico = (int**)malloc(n*sizeof(int*));

    for(i = 0; i < n; i++)
        quadradoMagico[i] = (int*)malloc(n*sizeof(int));

    while (++valor <= tamanhoQuadrado) {
        
        quadradoMagico[r][c] = valor;
        
        if (r == 0) {
        
            if (c == n - 1) {
                r++;
                
            } else {
                r = n - 1;
                c++;
            }
        
        } else if (c == n - 1) {
            r--;
            c = 0;
        
        } else if (quadradoMagico[r - 1][c + 1] == 0) {
            r--;
            c++;
        
        } else {
            r++;
        }
    }
    
    return quadradoMagico;
}

int** quadradoMagicoPar(int n) {
    if (n < 6 || (n - 2) % 4 != 0)
        return NULL;

    int tamanhoQuadrado = n * n;
    int metadeTamanho = n / 2;
    int subGridTamanhoQuadrado = tamanhoQuadrado / 4, i;

    int** subGrid = quadradoMagicoImpar(metadeTamanho);
    int fatoresGrid[] = {0, 2, 3, 1};
    int** quadradoMagico = (int**)malloc(n*sizeof(int*));

    for(i = 0; i < n; i++)
        quadradoMagico[i] = (int*)malloc(n*sizeof(int));

    int c, r;
    for (r = 0; r < n; r++) {
        
        for (c = 0; c < n; c++) {
            
            int grid = (r / metadeTamanho) * 2 + (c / metadeTamanho);
            quadradoMagico[r][c] = subGrid[r % metadeTamanho][c % metadeTamanho];
            quadradoMagico[r][c] += fatoresGrid[grid] * subGridTamanhoQuadrado;
        }
    }

    int numeroColunasEsquerda = metadeTamanho / 2;
    int numeroColunasDireita = numeroColunasEsquerda - 1;

    for (r = 0; r < metadeTamanho; r++)
        
        for (c = 0; c < n; c++) {
            
            if (c < numeroColunasEsquerda || c >= n - numeroColunasDireita
                    || (c == numeroColunasEsquerda && r == numeroColunasEsquerda)) {

                if (c == 0 && r == numeroColunasEsquerda)
                    continue;

                int tmp = quadradoMagico[r][c];
                quadradoMagico[r][c] = quadradoMagico[r + metadeTamanho][c];
                quadradoMagico[r + metadeTamanho][c] = tmp;
            }
        }

    return quadradoMagico;
}

int** quadradoMagicoDuplamentePar(int n)
{  
    int i, j; 
  
    int** quadradoMagico = (int**)malloc(n*sizeof(int*));

    for(i = 0; i < n; i++)
        quadradoMagico[i] = (int*)malloc(n*sizeof(int));

    for (i = 0; i < n; i++) 
        for ( j = 0; j < n; j++) 
            quadradoMagico[i][j] = (n*i) + j + 1; 
       
    for (i = 0; i < n/4; i++) 
        for (j = 0; j < n/4; j++) 
            quadradoMagico[i][j] = (n*n + 1) - quadradoMagico[i][j]; 
     
    for (i = 0; i < n/4; i++) 
        for (j = 3 * (n/4); j < n; j++) 
            quadradoMagico[i][j] = (n*n + 1) - quadradoMagico[i][j]; 
      
    for (i = 3 * n/4; i < n; i++) 
        for ( j = 0; j < n/4; j++) 
            quadradoMagico[i][j] = (n*n+1) - quadradoMagico[i][j]; 
     
    for (i = 3 * n/4; i < n; i++) 
        for ( j = 3 * n/4; j < n; j++) 
            quadradoMagico[i][j] = (n*n + 1) - quadradoMagico[i][j]; 
    
    for (i = n/4; i < 3*n/4; i++) 
        for ( j = n/4; j < 3 * n/4; j++) 
            quadradoMagico[i][j] = (n*n + 1) - quadradoMagico[i][j]; 

    return quadradoMagico; 
} 
  
void iniciaMontagemQuadradosMagicos(){
    int** q3 = quadradoMagicoImpar(3);
    int** q4 = quadradoMagicoDuplamentePar(4);
    int** q5 = quadradoMagicoImpar(5);
    int** q6 = quadradoMagicoPar(6);
    imprimeQuadradoMagico(q3, 3);
    imprimeQuadradoMagico(q4, 4);
    imprimeQuadradoMagico(q5, 5);
    imprimeQuadradoMagico(q6, 6);
    free(q3);
    free(q4);
    free(q5);
    free(q6);
}

int main (){ 
    iniciaMontagemQuadradosMagicos();
    return 0; 
} 
