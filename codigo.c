
// -------> Bibliotecas
#include <stdio.h>
#include <stdlib.h>

// -------> Dimensões da imagem
#define TAM 512

// -------> Estrutura do pixel
typedef struct {
    int r, g, b;
} pixel;

// Ponteiro para arquivo
  FILE *img1;

//-------> Definisão das funções 
void init(FILE *img1);
void salvar(char *nome, pixel imagem[TAM][TAM], char *identificador, int max, int coluna, int linha);

void copiarImg(char nome[], pixel imagem[TAM][TAM], char *identificador, int max, int coluna, int linha);
void rotacionar90H();
void armazenarMatriz(FILE *arquivo, pixel imagem[TAM][TAM], char *code, int *max, int *coluna, int *linha);
void rotacionar90AH();
void inverterHorizontal();
void inverterVertical();
void filtro(pixel imagem[TAM][TAM], int coluna, int linha);



//----------> Função main
int main(void){

  pixel imagem[TAM][TAM]; //cria uma matriz de pixeis para armazenar a imagem 
  int max; //o valor máximo de tonalidade de cada pixel
  int larg, alt; // largura e altura da imagem em pixeis
  char copia[100], continua, nome[100], identificador[3];
//---------> indentificador é o código para saber se a imagem é ascii(P3) ou binária

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
        img1 = fopen(nome, "r+");
        init(img1);
        armazenarMatriz(img1, imagem, identificador, &max, &larg, &alt);
        printf("\nDigite o nome da copia:");
        scanf("%s", copia);
        
        copiarImg(copia, imagem, identificador, max, larg, alt);
        fclose(img1);
        break;

        case 2:
        break;

        case 3:
        break;

        case 4:
        break;

      case 5:
        printf("\nDigite o nome da imagem:");
        scanf("%s", nome);
        img1 = fopen(nome, "r+");
        init(img1);
        armazenarMatriz(img1, imagem, identificador, &max, &larg, &alt);
        inverterHorizontal(imagem, larg, alt);
        salvar(nome, imagem, identificador, max, larg, alt);
        break;

      case 6:
        printf("\nDigite o nome da imagem:");
        scanf("%s", nome);
        img1 = fopen(nome, "r+");
        init(img1);
        armazenarMatriz(img1, imagem, identificador, &max, &larg, &alt);
        filtro(imagem, larg, alt);
        salvar(nome, imagem, identificador, max, larg, alt);
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
void copiarImg(char nome[], pixel imagem[TAM][TAM], char *identificador, int max, int coluna, int linha){
   int i, j;
   
  FILE *img2 = fopen(nome, "w+");
  
  if(img2 == NULL){
    printf("\nErro ao criar arquivo de copia!");
  }

  fprintf(img2, "P3\n");
  fprintf(img2, "%d\n ", coluna);
  fprintf(img2, "%d\n", linha);
  fprintf(img2, "%d\n", max);

  for (i = 0; i < linha; i++) {
      for (j = 0; j < coluna; j++) {
          fprintf(img2, "%d ", imagem[i][j].r);
          fprintf(img2, "%d ", imagem[i][j].g);
          fprintf(img2, "%d\n", imagem[i][j].b);
        }
    }

  fclose(img2);
}

void armazenarMatriz(FILE *arquivo, pixel imagem[TAM][TAM], char *identificador, int *max, int *coluna, int *linha) {
    int i, j;

    fscanf(arquivo, "%s", identificador);
    fscanf(arquivo, "%d", coluna);
    fscanf(arquivo, "%d", linha);
    fscanf(arquivo, "%d", max);

    for (i = 0; i < *linha; i++) {
        for (j = 0; j < *coluna; j++) {
            fscanf(arquivo, "%d", &imagem[i][j].r);
            fscanf(arquivo, "%d", &imagem[i][j].g);
            fscanf(arquivo, "%d", &imagem[i][j].b);
        }
    }

    fclose(arquivo);
}

void inverterHorizontal(pixel imagem[TAM][TAM], int coluna, int linha){
    pixel img[linha][coluna];
    int i, j;

    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            img[i][j].r = imagem[i][coluna - j].r; //salva em uma matriz do tipo pixel a imagem com suas 
            img[i][j].g = imagem[i][coluna - j].g; //linhas salvas em complementos, isso faz com que a imagem
            img[i][j].b = imagem[i][coluna - j].b; //pegue o pixel complementar no seu extremo oposto horizonal 
        }
    }
    //passa a imagem para a matriz original
    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            imagem[i][j].r = img[i][j].r;
            imagem[i][j].g = img[i][j].g;
            imagem[i][j].b = img[i][j].b;   
        }
    }
}


void salvar(char *nome, pixel imagem[TAM][TAM], char *identificador, int max, int coluna, int linha){
    FILE *arquivo  = fopen(nome, "w+");
    
    int i, j;
    
    fprintf(arquivo, "P3\n");
    fprintf(arquivo, "%d\n ", coluna);
    fprintf(arquivo, "%d\n", linha);
    fprintf(arquivo, "%d\n", max);

    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            fprintf(arquivo, "%d ", imagem[i][j].r);
            fprintf(arquivo, "%d ", imagem[i][j].g);
            fprintf(arquivo, "%d\n", imagem[i][j].b);
        }
    }

    fclose(arquivo);
}


void filtro(pixel imagem[TAM][TAM], int coluna, int linha){
    int i, j;
    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            imagem[i][j].r = (int) ((0.299 * imagem[i][j].r) + (0.587 * imagem[i][j].g) + (0.144 * imagem[i][j].b)); //calcula o valor para conversão
            imagem[i][j].g = imagem[i][j].r; //copia o valor para
            imagem[i][j].b = imagem[i][j].r; //todas componentes

            //testa o valor para ver se o mesmo não passou de 255
            if (imagem[i][j].r > 255) {
                imagem[i][j].r = 255;
                imagem[i][j].g = 255;
                imagem[i][j].b = 255;

            }

        }
    }
}
