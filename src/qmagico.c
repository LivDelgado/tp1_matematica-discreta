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

    int value = 0;
    int squareSize = n * n;
    int c = n / 2, r = 0,i;

    int** result = (int**)malloc(n*sizeof(int*));

    for(i=0;i<n;i++)
        result[i] = (int*)malloc(n*sizeof(int));

    while (++value <= squareSize) {
        result[r][c] = value;
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
        } else if (result[r - 1][c + 1] == 0) {
            r--;
            c++;
        } else {
            r++;
        }
    }
    return result;
}

int** quadradoMagicoPar(int n) {
    if (n < 6 || (n - 2) % 4 != 0)
        return NULL;

    int size = n * n;
    int halfN = n / 2;
    int subGridSize = size / 4, i;

    int** subGrid = quadradoMagicoImpar(halfN);
    int gridFactors[] = {0, 2, 3, 1};
    int** result = (int**)malloc(n*sizeof(int*));

    for(i=0;i<n;i++)
        result[i] = (int*)malloc(n*sizeof(int));

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int grid = (r / halfN) * 2 + (c / halfN);
            result[r][c] = subGrid[r % halfN][c % halfN];
            result[r][c] += gridFactors[grid] * subGridSize;
        }
    }

    int nColsLeft = halfN / 2;
    int nColsRight = nColsLeft - 1;

    for (int r = 0; r < halfN; r++)
        for (int c = 0; c < n; c++) {
            if (c < nColsLeft || c >= n - nColsRight
                    || (c == nColsLeft && r == nColsLeft)) {

                if (c == 0 && r == nColsLeft)
                    continue;

                int tmp = result[r][c];
                result[r][c] = result[r + halfN][c];
                result[r + halfN][c] = tmp;
            }
        }

    return result;
}

int** quadradoMagicoDuplamentePar(int n)
{  
    int i, j; 
  
    int** quadradoMagico = (int**)malloc(n*sizeof(int*));

    for(i=0;i<n;i++)
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
    imprimeQuadradoMagico(quadradoMagicoImpar(3), 3);
    imprimeQuadradoMagico(quadradoMagicoDuplamentePar(4),4);
    imprimeQuadradoMagico(quadradoMagicoImpar(5),5);
    imprimeQuadradoMagico(quadradoMagicoPar(6),6);
}

int main (){ 
    iniciaMontagemQuadradosMagicos();
    return 0; 
} 
