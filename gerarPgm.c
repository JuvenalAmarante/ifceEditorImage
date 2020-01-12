#include <stdio.h> 
  
void main() 
{ 
    int i, j, temp = 0; 
    int width = 13, height = 13; 
  
    // Array da Imagem que será convertido
    int image[13][13] = { 
      { 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15 }, 
      { 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31}, 
      { 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47}, 
      { 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63}, 
      { 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79}, 
      { 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95 }, 
      { 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111}, 
      { 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127}, 
      { 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143, 143}, 
      { 159, 159, 159, 159, 159, 159, 159, 159, 159, 159, 159, 159, 159}, 
      { 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175}, 
      { 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191, 191}, 
      { 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207, 207} 
    }; 
  
    FILE* pgmimg; 
    pgmimg = fopen("pgmimg.pgm", "wb"); 
  
    // Escrevendo o tipo de "criptografia" 
    fprintf(pgmimg, "P2\n");  
  
    // Escrevendo altura e largura 
    fprintf(pgmimg, "%d %d\n", width, height);  
  
    // Escrevendo o valor de cinza maximo 
    fprintf(pgmimg, "255\n");  
    int count = 0; 
    for (i = 0; i < height; i++) { 
        for (j = 0; j < width; j++) { 
            temp = image[i][j]; 
  
            // Escrevendo os tons de cinza no array de 2 dimensões 
            fprintf(pgmimg, "%d ", temp); 
        } 
        fprintf(pgmimg, "\n"); 
    } 
    fclose(pgmimg); 
}
