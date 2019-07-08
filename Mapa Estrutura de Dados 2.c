/*
* Ordenação Quicksort em C
* Luis Antonio Cardozo - 2018
* RA: 1752471-5
* Projeto: Mapa Estrutura de Dados II
* Objetivo:
*Com base no exposto, desenvolva um programa em linguagem C que cumpra os seguintes requisitos.
1. Crie um vetor com 8 posições.
2. Cada posição corresponde aos dígitos do seu RA.
3. Exiba o vetor preenchido.
4. Aplique o algoritmo de ordenação Quicksort.
5. Exiba o vetor ordenado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
 
// Define uma constante
#define MAX 8
 
void quick_sort(int *a, int left, int right);
 
// Função main
int main(int argc, char** argv)
{
 setlocale(LC_ALL,"Portuguese");	
 int i, vet[MAX]= {1,7,5,2,4,7,1,5};
 
 // Realiza a leitura MAX ou 8 valores
 
 /*for(i = 0; i < MAX; i++)
{
  printf("Digite um valor: "); //caso fossem digitados o RA do aluno, descomentar esse bloco!!
  scanf("%d", &vet[i]);
   }*/
   
   
   // Imprime os valores digitados
   printf("\n>>>> MAPA ESTRUTURA DE DADOS II <<<<\n");
	printf("\n     Aluno: Luis Antonio Cardozo\n\n\n");
   printf("Valores predefinidos (RA) do Aluno: \n") ;
	for ( i = 0; i < 8; i++ ) 
	printf (" %d ", vet[i] );
 
 // Ordena os valores
 quick_sort(vet, 0, MAX - 1);
 
 // Imprime os valores ordenados
 
  printf("\nValores ordenados método Quicksort: \n") ;
 for(i = 0; i < MAX; i++)
 {
  printf(" %d ", vet[i]);
 }
 printf("\n\n");
 system("pause");
 return 0;
}
 
// Função de Ordenação Quicksort.
void quick_sort(int *a, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}
