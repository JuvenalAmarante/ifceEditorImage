// -------> Bibliotecas
#include <stdio.h>
#include <stdlib.h>


// -------> Dimensões da imagem
#define ALTURA 0
#define LARGURA 0

// Ponteiro para arquivo
  FILE *img1;

//-------> Definisão das funções 
void init(FILE *img1);
void copiarImg(FILE *img1, char nome[]);

void rotacionar90H();
void rotacionar90AH();
void girarHorizontal();
void girarVertical();
void filtro();

//----------> Função main
int main(void){
  char nome[100];
  char copia[100], continua;
  short int op, control = 0;

  while(control == 0){
    printf("Olá, o que deseja fazer?");
    printf("\n1) Gerar copia da imagem;");
    printf("\n2) Rotacionar sentido horario;");
    printf("\n3) Rotacionar sentido anti-horario;");
    printf("\n4) Inverter verticalmente;");
    printf("\n5) Inverter horizontalmente;");
    printf("\n6) Filtro escala de cinza.\n");


    scanf("%hi", &op);

    switch(op){
      case 1:
        printf("\nDigite o nome da imagem:");
        scanf("%s", nome);

        printf("\nDigite o nome da copia:");
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
          printf("\n Opção inválida!");
          exit(0);
          break;
      }
    
    getchar();
    printf("\nDeseja fazer outra operação? (s/n)");
    scanf("\n%c", &continua);

    if(!(continua == 83 || continua == 115)){
       printf("\nObrigado por utilizar o programa! ^^");
        control = 1;
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
