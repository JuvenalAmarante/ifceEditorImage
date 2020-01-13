// -------> Bibliotecas
#include <stdio.h>
#include <stdlib.h>


// -------> Dimensões da imagem
#define ALTURA 0
#define LARGURA 0

// Nome dos arquivos 
#define FOTO "lenna.png"
#define COPIA "len.png"

//-------> Definisão das funções 
void init(FILE *img1);
void copiarImg(FILE *img1);

void rotacionar90H();
void rotacionar90AH();
void girarHorizontal();
void girarVertical();
void filtro();

//----------> Função main
int main(void){
  FILE *img1;
  img1 = fopen(FOTO, "r+");
  
  init(img1);
  copiarImg(img1);
  
  fclose(img1);
  
  return 0;
}

//-----> Função para verificar erros na inicialização

void init(FILE *img1){
  if(img1 == NULL){
    printf("Erro ao iniciar arquivo");
    exit(0);
  }
}


// Função copiar imagem 
void copiarImg(FILE *img1){
//------> Arquivo c
  FILE *img2 = fopen(COPIA, "w+");
  char aux;
//-------> Cursor para o inicio do arquivo
  rewind(img1); 
//-------> Copiando caracteres 
  while(!(feof(img1))){
    aux = getc(img1); 
       fputc(aux,img2);
  }
//----> Fechando arquivo
  fclose(img2);
}
