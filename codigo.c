// -------> Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// -------> Dimensões da imagem
#define ALTURA 0
#define LARGURA 0

// Ponteiro para arquivo
  FILE *img1;

//-------> Definição das funções
void init(FILE *img1);
void copiarImg(FILE *img1, char nome[]);

void rotacionar90H();
void rotacionar90AH();
void girarHorizontal();
void girarVertical();
void filtro();

//----------> Função main
int main(void){
	setlocale(LC_ALL, "Portuguese");
	char nome[100];
	char copia[100], continua;
	short int escolha, control = 0;

	while(1){
	 printf("Olá, o que deseja fazer?\n\n[1] - Gerar cópia da imagem\n[2] - Rotacionar sentido horário\n[3] - Rotacionar sentido anti-horáio\n[4] - Inverter verticalmente\n[5] - Inverter horizontalmente\n[6] - Filtro escala de cinza\n[0] - Encerrar aplicação\n\n>>> ");
	 scanf("%hi", &escolha);
    
    switch(escolha){
      case 0:
        printf("\nObrigado por utilizar o programa! ^^");
        exit(0);
      case 1:
        printf("\nDigite o nome da imagem: ");
        scanf("%s", nome);

        printf("\nDigite o nome da cópia: ");
        scanf("%s", copia);
        img1 = fopen(nome, "r+");
        init(img1);
        copiarImg(img1, copia);
        fclose(img1);
        break;

        case 2:
        break;

        case 3:
        break;

        case 4:
        break;

        case 5:
        break;

        case 6:
        break;

        default:
          printf("\nOpção inválida, tente novamente!\n\n");
          break;
      }
 }
    
}

//-----> Função para verificar erros na inicialização

void init(FILE *img1){
  if(img1 == NULL){
    printf("Erro ao iniciar arquivo");
    exit(0);
  }
}


// Função copiar imagem 
void copiarImg(FILE *img1 , char nome[]){
//------> Arquivo c
  FILE *img2 = fopen(nome, "w+");
  if(img2 == NULL){
    printf("\nErro ao criar arquivo de copia!");
  }
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
