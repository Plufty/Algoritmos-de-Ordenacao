#include<stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<time.h>

//Insertion Sort
void insertionSort(int *vetor, int tamanho)
{
    int i, j, x;
    for(i = 1; i < tamanho; i++)
    {
        x = vetor[i];
        j = (i-1);
        while(j >= 0 && vetor[j] > x)
        {
            vetor[j+1] = vetor[j];
            vetor[j] = x;
            j--;
        }
    }
}

//Bubble Sort
void bubbleSort(int *vetor, int n)
{
	int i,j;
    for( i = 0; i < n; i++ )
    {
        for(j=0;j<(n-(i+1));j++)
        {
            if ( vetor[j] > vetor[j+1] )
            {
                int aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}

//Selection Sort
void selectionSort(int *vetor, int n)
{
    int i;
    for (i = 0; i < (n-1); i++)
    {
        int menorIndice=i;
        for(int j = (i+1); j <= (n-1); j++)
        {
            if(vetor[menorIndice] > vetor[j])
            {
                menorIndice = j;
            }
        }
        int temp = vetor[i];
        vetor[i] = vetor[menorIndice];
        vetor[menorIndice] = temp;
    }
}

//Shell Sort
void shellSort(int *vetor, int n)
{
    int i , j , x;
    int h = 1;

    do 
    {
        h = 3*h+1;
    } while(h < n);

    do 
    {
        h /= 3;
        for(i = h; i < n; i++) 
        {
            x = vetor[i];
            j = i - h;

            while (j >= 0 && x < vetor[j]) 
            {
                vetor[j + h] = vetor[j];
                j -= h;
            }
            vetor[j + h] = x;
        }
    }while(h > 1);
}

//Merge Sort
void merge(int vetor[], int inicio, int meio, int fim) {
 	
 	int com1 = inicio, com2 = meio+1, comAux = 0, vetAux[fim-inicio+1];
	while(com1<=meio && com2<=fim)
    {
 		if(vetor[com1] <= vetor[com2])
        {
 			vetAux[comAux] = vetor[com1];
 			com1++;
        }
        else
        {
            vetAux[comAux] = vetor[com2];
            com2++; 
        }
        comAux++; 
	}
	while(com1<=meio)
    { //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++; 
    }
	while(com2<=fim)
    { //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;com2++; 
	}
 	for(comAux=inicio;comAux<=fim;comAux++)
    { //Move os elementos de volta para o vetor original
 		vetor[comAux] = vetAux[comAux-inicio];
 	}
 }
 
void mergeSort(int* vetor, int inicio, int fim)
{
	if (inicio < fim) 
    {
 		int meio = (inicio+fim)/2;
 		mergeSort(vetor, inicio, meio);
		mergeSort(vetor, meio+1, fim);
		merge(vetor, inicio, meio, fim);
 	}
}

//Quick Sort
void particao(int* vetor, int esq,int dir , int *i,int *j)
{
	int x,w;
	*i = esq;
	*j = dir;
	x = vetor[(*i + *j) / 2];
	do
    {
		while( x > vetor[*i])(*i)++;
		while( x < vetor[*j])(*j)--;
		if(*i <= *j)
        {
			w = vetor[*i];
			vetor[*i] = vetor[*j];
			vetor[*j] = w;
			(*i)++;
			(*j)--;
		}
	}while(*i <= *j);
}

void ordena(int *vetor, int esq, int dir)
{
	int i,j;
	particao(vetor,esq,dir,&i,&j);
	if(esq < j)
    {
		ordena(vetor,esq,j);
	}
	if(i< dir){
		ordena(vetor,i,dir);
	}
}

void quickSort(int *vetor,int n)
{
	ordena(vetor,0,n-1);
}

//Quick Sort Media

void particaoMEDIA(int* vetor, int esq,int dir , int *i,int *j){
	int x,w;
	*i = esq;
	*j = dir;
	//Calculo de media
	int result,t,minpos=0,maxpos=0;
	int aux[3];
	aux[0]=*i+(rand()%(*j-*i));
	aux[1]=*i+(rand()%(*j-*i));
	aux[2]=*i+(rand()%(*j-*i));

	for(t=0;t<3;t++)
    {
		if(vetor[aux[t]]< vetor[minpos])
        {
			minpos=t;
		}
		if(vetor[aux[t]]>vetor[maxpos])
        {
			maxpos=t;
		}
	}


	for(t=0;t<3;t++)
    {
		if(t!= minpos && t != maxpos)
        {
			result =aux[t];
		}
	}
    
    x = vetor[result];
	do
    {
		while( x > vetor[*i])
			(*i)++;
		while( x < vetor[*j])
			(*j)--;
		if(*i <= *j){
			w = vetor[*i];
			vetor[*i] =vetor[*j];
			vetor[*j] = w;
			(*i)++;
			(*j)--;
		}
	}while(*i <= *j);
}

void ordenaMEDIA(int *vetor, int esq, int dir)
{
	int i,j;
	particaoMEDIA(vetor,esq,dir,&i,&j);
	if(esq < j)
    {
		ordenaMEDIA(vetor,esq,j);
	}
	if(i<dir)
    {
		ordenaMEDIA(vetor,i,dir);
	}
}

void quickSortMEDIA(int *vetor,int n)
{
	ordenaMEDIA(vetor,0,n-1);
}



void gravaVetorOrdenado(int *vetor, int tamanho, char* algoritmo)
{
    FILE *fp;
    int i;   
    fp = fopen(algoritmo, "w");    
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    for (i = 0; i<tamanho; i++)
    {
        fprintf(fp, "%d\n", vetor[i]);
    }
    printf("Vetor ordenado com sucesso!\n");        
    fclose(fp); //Entrada Gerada, fechando arquivo
}



void salvaEntrada(int tamanho, int tipo)
{
    FILE *fp;
    int i;
    char *nome_arquivo= (char*)malloc(50 * sizeof(char));

    if(tipo == 1)
    {
        sprintf(nome_arquivo, "./Entradas/Random/entradarandom%d.txt", tamanho);
        fp = fopen(nome_arquivo, "w");
        if (fp == NULL)
        {
            printf("Erro ao abrir o arquivo!\n");
            exit(1);
        }                    
        fprintf(fp, "%d\n", tamanho);
        
        srand(time(NULL)); //usando como seed o valor da hora do sistema para o rand.
        for (i=0; i < tamanho; i++)
        {
            // gerando valores aleatórios na faixa de 0 a 1.000.000
            fprintf(fp, "%d\n",((rand() % 1000) * 1000)+ rand() % 1000 + ((rand()%9 + 1) * 1000000));
        }
    }
    if (tipo == 2)
    {
        sprintf(nome_arquivo, "./Entradas/Crescente/entradacrescente%d.txt", tamanho);
        fp = fopen(nome_arquivo, "w");
        if (fp == NULL)
        {
            printf("Erro ao abrir o arquivo!\n");
            exit(1);
        }                    
        fprintf(fp, "%d\n", tamanho);
        for (i=0; i < tamanho; i++)
        {
            // gerando valores aleatórios na faixa de 0 a 1.000.000
            fprintf(fp, "%d\n", i+1);
        }

    }
    if (tipo == 3)
    {
        sprintf(nome_arquivo, "./Entradas/Decrescente/entradadecrescente%d.txt", tamanho);
        fp = fopen(nome_arquivo, "w");
        if (fp == NULL)
        {
            printf("Erro ao abrir o arquivo!\n");
            exit(1);
        }                    
        fprintf(fp, "%d\n", tamanho);
        for (i=tamanho; i > 0; i--)
        {
            // gerando valores aleatórios na faixa de 0 a 1.000.000
            fprintf(fp, "%d\n", i);
        }
        
    }                    
        fclose(fp); //Entrada Gerada, fechando arquivo
        free(nome_arquivo);
}

void geraEntrada (int tamanho, int tipo, int* vetor)
{
    FILE* fp;
    int i;
    char *nome_arquivo= (char*)malloc(50 * sizeof(char));
    if(tipo == 1)
    {
        sprintf(nome_arquivo, "./Entradas/Random/entradarandom%d.txt", tamanho);        
    }
    if(tipo == 2)
    {
        sprintf(nome_arquivo, "./Entradas/Crescente/entradacrescente%d.txt", tamanho);        
    }
    if(tipo == 3)
    {
        sprintf(nome_arquivo, "./Entradas/Decrescente/entradadecrescente%d.txt", tamanho);        
    }

    fp = fopen(nome_arquivo, "r");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    fscanf(fp, "%d", &tamanho);

    for(i = 0; i <tamanho; i++)
    {
        fscanf(fp, "%d", &vetor[i]);
    }                 
    fclose(fp); //Entrada Gerada, fechando arquivo
    free(nome_arquivo);
}

void operacoes(int algoritmo, int tamanho, int tipo)
{
    FILE *fp;
    double start;//variável para guardar o tempo inicial
    double end; //Variavel para guardar o tempo final
    double tempo_gasto;//variável para guardar o tempo de execução do algoritmo
    int *vetor;//vetor para armazenar as entradas    
    char *nome_saida_algoritmo = (char*)malloc(100 * sizeof(char));    
    char *nome_saida_tempo_algoritmo = (char*)malloc(100 * sizeof(char));
    char *nome_tipo = (char*)malloc(15 * sizeof(char));
    if(tipo == 1)
    {
        nome_tipo = "random";
    }
    if(tipo == 2)
    {
        nome_tipo = "crescente";
    }
    if(tipo == 3)
    {
        nome_tipo = "decrescente";
    }

    //Salva a entrada de numeros
    salvaEntrada(tamanho, tipo);     
    vetor = (int*)malloc(sizeof(int) * tamanho);
    printf("Arquivo de entrada gerado. \n");
    geraEntrada(tamanho, tipo, vetor); //Gera sequencia de numeros
    printf("Gravando dados no vetor para aplicar o algoritmo.\n");
    start = clock(); //inicio
    if(algoritmo == 1)
    {
        sprintf(nome_saida_algoritmo, "./Saidas/Ordenado/Insertion/saidainsertion%s%d.txt", nome_tipo, tamanho);
        sprintf(nome_saida_tempo_algoritmo, "./Saidas/Tempos/Insertion/tempoinsertion%s%d.txt", nome_tipo, tamanho);
        printf("Aplicando algoritmo Insertion Sort para ordenacao. Por favor aguarde...");        
        insertionSort(vetor, tamanho); //Ordena o Vetor
    }
    if(algoritmo == 2)
    {
        sprintf(nome_saida_algoritmo, "./Saidas/Ordenado/Bubble/saidabubble%s%d.txt", nome_tipo, tamanho);
        sprintf(nome_saida_tempo_algoritmo, "./Saidas/Tempos/Bubble/tempobubble%s%d.txt", nome_tipo, tamanho);
        printf("Aplicando algoritmo Bubble Sort para ordenacao. Por favor aguarde...");         
        bubbleSort(vetor, tamanho); //Ordena o Vetor
    }
    if(algoritmo == 3)
    {
        sprintf(nome_saida_algoritmo, "./Saidas/Ordenado/Selection/saidaselection%s%d.txt", nome_tipo, tamanho);
        sprintf(nome_saida_tempo_algoritmo, "./Saidas/Tempos/Selection/temposelection%s%d.txt", nome_tipo, tamanho);
        printf("Aplicando algoritmo Selection Sort para ordenacao. Por favor aguarde...");         
        selectionSort(vetor, tamanho); //Ordena o Vetor
    }
    if(algoritmo == 4)
    {
        sprintf(nome_saida_algoritmo, "./Saidas/Ordenado/Shell/saidashell%s%d.txt", nome_tipo, tamanho);
        sprintf(nome_saida_tempo_algoritmo, "./Saidas/Tempos/Shell/temposhell%s%d.txt", nome_tipo, tamanho);
        printf("Aplicando algoritmo Shell Sort para ordenacao. Por favor aguarde...");         
        shellSort(vetor, tamanho); //Ordena o Vetor
    }
    if(algoritmo == 5)
    {
        sprintf(nome_saida_algoritmo, "./Saidas/Ordenado/Merge/saidamerge%s%d.txt", nome_tipo, tamanho);
        sprintf(nome_saida_tempo_algoritmo, "./Saidas/Tempos/Merge/tempomerge%s%d.txt", nome_tipo, tamanho);
        printf("Aplicando algoritmo Merge Sort para ordenacao. Por favor aguarde...");         
        mergeSort(vetor, 0, tamanho-1); //Ordena o Vetor
    }
    if(algoritmo == 6)
    {
        sprintf(nome_saida_algoritmo, "./Saidas/Ordenado/Quick/saidaquick%s%d.txt", nome_tipo, tamanho);
        sprintf(nome_saida_tempo_algoritmo, "./Saidas/Tempos/Quick/tempoquick%s%d.txt", nome_tipo, tamanho);
        printf("Aplicando algoritmo Quick Sort para ordenacao. Por favor aguarde...");         
        quickSort(vetor, tamanho); //Ordena o Vetor
    }
    if(algoritmo == 7)
    {
        sprintf(nome_saida_algoritmo, "./Saidas/Ordenado/QuickMEDIA/saidaquickmedia%s%d.txt", nome_tipo, tamanho);
        sprintf(nome_saida_tempo_algoritmo, "./Saidas/Tempos/QuickMEDIA/tempoquickmedia%s%d.txt", nome_tipo, tamanho);
        printf("Aplicando algoritmo Quick Sort com pivô escolhido com o metodo da media para ordenacao. Por favor aguarde...");         
        quickSortMEDIA(vetor, tamanho); //Ordena o Vetor
    }
    system("cls");
    end = clock();//fim
    tempo_gasto = ((end - start) / (double)CLOCKS_PER_SEC); //Calcula diferenca de tempo entre inicio e fim    
    
    fp = fopen(nome_saida_tempo_algoritmo, "w");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    } 
    fprintf(fp, "Tempo Gasto: %.6lf\n", tempo_gasto);//gravando o tempo gasto                        
    fclose(fp); //tempo gravado, fechando arquivo
    gravaVetorOrdenado(vetor, tamanho, nome_saida_algoritmo);//gravando o vetor ordenado
    free(vetor);   
    free(nome_tipo);     
    free(nome_saida_algoritmo);    
    free(nome_saida_tempo_algoritmo);
}



int main()
{
    //Variáveis
    int menu = -1; // menu
    int tamanho; // variável para selecionar o tamanho da entrada
    int algoritmo;// variável para definir o algoritmo usado

    while(menu != 0)
    {
        printf("Escolha um algoritmo:\n1 - Insertion sort\n2 - Bubble sort\n3 - Selection sort\n4 - Shell sort\n5 - Merge Sort\n6 - Quick Sort\n7 - Quick Sort Media\n0 - Encerrar\n");
        scanf("%d", &menu); 
        algoritmo = menu;
        system("cls");  //Limpando a Tela     

        if (menu == 1 || menu == 2 || menu == 3 || menu == 4 || menu == 5 || menu == 6 || menu == 7)
        {
            while(menu != 0)
            {
                printf("Escolha a quantidade de instancias:\n1 - 10 \n2 - 100 \n3 - 1000 \n4 - 10.000 \n5 - 100.000 \n6 - 1.000.000\n9 - Voltar\n0 - Encerrar\n");
                scanf("%d", &menu);
                system("cls");//Limpando a Tela
                if(menu == 1)
                {
                    tamanho = 10;
                    while(menu != 0)
                    {
                        printf("Escolha o tipo de entrada:\n1 - Random \n2 - Crescente \n3 - Decrescente\n9 - Voltar\n0 - Encerrar\n");
                        scanf("%d", &menu);
                        system("cls");//Limpando a Tela
                        if (menu == 1 || menu == 2 || menu == 3)
                        {
                            operacoes(algoritmo, tamanho, menu);
                        }
                        else if (menu == 9)
                        {
                            break;
                        }
                        else if(menu != 0)
                        {
                            printf("Opcao Invalida.\n");
                        }
                    }
                }
                else if(menu == 2)
                {
                    tamanho = 100;
                    while(menu != 0)
                    {
                        printf("Escolha o tipo de entrada:\n1 - Random \n2 - Crescente \n3 - Decrescente\n9 - Voltar\n0 - Encerrar\n");
                        scanf("%d", &menu);
                        system("cls");//Limpando a Tela
                        if (menu == 1 || menu == 2 || menu == 3)
                        {
                            operacoes(algoritmo, tamanho, menu);
                        }
                        else if (menu == 9)
                        {
                            break;
                        }
                        else if(menu != 0)
                        {
                            printf("Opcao Invalida.\n");
                        }
                    }
                }
                else if(menu == 3)
                {
                    tamanho = 1000;
                    while(menu != 0)
                    {
                        printf("Escolha o tipo de entrada:\n1 - Random \n2 - Crescente \n3 - Decrescente\n9 - Voltar\n0 - Encerrar\n");
                        scanf("%d", &menu);
                        system("cls");//Limpando a Tela
                        if (menu == 1 || menu == 2 || menu == 3)
                        {
                            operacoes(algoritmo, tamanho, menu);
                        }
                        else if (menu == 9)
                        {
                            break;
                        }
                        else if(menu != 0)
                        {
                            printf("Opcao Invalida.\n");
                        }
                    }
                }
                else if(menu == 4)
                {
                    tamanho = 10000;
                    while(menu != 0)
                    {
                        printf("Escolha o tipo de entrada:\n1 - Random \n2 - Crescente \n3 - Decrescente\n9 - Voltar\n0 - Encerrar\n");
                        scanf("%d", &menu);
                        system("cls");//Limpando a Tela
                        if (menu == 1 || menu == 2 || menu == 3)
                        {
                            operacoes(algoritmo, tamanho, menu);
                        }
                        else if (menu == 9)
                        {
                            break;
                        }
                        else if(menu != 0)
                        {
                            printf("Opcao Invalida.\n");
                        }
                    }
                }
                else if(menu == 5)
                {
                    tamanho = 100000;
                    while(menu != 0)
                    {
                        printf("Escolha o tipo de entrada:\n1 - Random \n2 - Crescente \n3 - Decrescente\n9 - Voltar\n0 - Encerrar\n");
                        scanf("%d", &menu);
                        system("cls");//Limpando a Tela
                        if (menu == 1 || menu == 2 || menu == 3)
                        {
                            operacoes(algoritmo, tamanho, menu);
                        }
                        else if (menu == 9)
                        {
                            break;
                        }
                        else if(menu != 0)
                        {
                            printf("Opcao Invalida.\n");
                        }
                    }
                }
                else if(menu == 6)
                {
                    tamanho = 1000000;
                    while(menu != 0)
                    {
                        printf("Escolha o tipo de entrada:\n1 - Random \n2 - Crescente \n3 - Decrescente\n9 - Voltar\n0 - Encerrar\n");
                        scanf("%d", &menu);
                        system("cls");//Limpando a Tela
                        if (menu == 1 || menu == 2 || menu == 3)
                        {
                            operacoes(algoritmo, tamanho, menu);
                        }
                        else if (menu == 9)
                        {
                            break;
                        }
                        else if(menu != 0)
                        {
                            printf("Opcao Invalida.\n");
                        }
                    }
                }
                else if (menu == 9)
                {
                    break;
                }
                
            }


        }
    }

    printf("O programa sera encerrado!\n");
    return 0;
}