/*
* - Algoritmo de Dijkstra em C -
* Luis Antonio Cardozo - 2018
* RA: 1752471-5
* Projeto: Mapa Estrutura de Dados I
*
* O objetivo � sair do ponto inicial origem (0) e chegar ao destino (3) pelo caminho mais curto
* utilizando os 7 primeiros do RA aluno x100 como peso entre os v�rices.
* O programa funciona de duas maneiras:

* 1) pergunta ao usu�rio a origem e destino e ap�s mostra o resultado. Bastando para isso descomentar
* o bloco entre as linhas 64 at� 72, essa op��o � boa para verificar que o programa executa em 100%
* o que se pede que ele fa�a.

* 2) Com as linhas citadas acimas e deixando elas comentadas, o programa j� executa e mostra o resultado
* com base no que foi definido na linha 190 como origem=0 e destino=3.
* 
*  Matriz de Dist�ncia
*    0   1    2     3     4
* 0  -   100  700   -     -
* 1  -   -    -     500   200
* 2  -   400  -     700   -
* 3  -   -    -     -     -
* 4  -   -    -     100   -

* Resposta: (0)->(1)->(4)->(3) = 400
*       ou  (3)<-(4)<-(1)<-(0) = 400 */

#include<locale.h>
#include <stdio.h>
#include <stdlib.h>

#define INF 9999
#define MAX 5
#define NUM 5


void imp_grafo(int grafo[MAX][MAX])
{
	setlocale(LC_ALL,"Portuguese");
int i,j;

    printf("\n>>>> MAPA ESTRUTURA DE DADOS I <<<<\n");
	printf("\n     Aluno:Luis Antonio Cardozo");
	printf("\n     RA: 1752471-5\n\n");
	printf(">>> Matriz base RA Aluno <<<\n\n");
	
for (i=0;i<MAX;i++)
{
for (j=0;j<MAX;j++)
printf("%3d ",grafo[i][j]);
printf("\n");
}
}


void dig_origem_destino(int *origem, int *destino)
{
	/* Bloco abaixo pergunta ao usu�rio a origem=0 e destino=3, valores definidos no mapa!!
	para utilizar favor descomentar esse bloco abaixo nas linhas 64 at� 72, se optar por deixar
	comentado esse bloco, o algoritmo executa valores definidos  na linha 190 onde est�
	 definido origem=0,destino=3 como pede-se no mapa*/

/*printf("Digite a origem - numeros entre '0' e '%d': ",MAX);
fflush(stdin);
scanf("%d",&*origem);
printf("\n");

printf("Digite o destino - numeros entre '0' e '%d': ",MAX);
fflush(stdin);
scanf("%d",&*destino);
printf("\n");*/

printf("Aeroportos que permanecem e menor caminho: ");
}

void inicializa(int *foi, int *custo, int *prec, int *estima) //inicializa as vari�veis.
{
int i;

for(i=0 ; i<MAX ; i++) //foi "visitado", custo "peso", prec "precedente" e estima "armazena o menor custo".
{
foi[i]= 0;
custo[i] = INF;
prec[i]=INF;
estima[i]= INF;
}
}


int estima_menor(int *estima, int *menor, int *posicao) //define qual o pr�ximo n� a ser visitado
{
int i;
*menor = estima[0];
*posicao = 0;

for (i=0;i<MAX;i++) //percorre todos os elementos de estima e identifica quem tem o menor custo.
{
if (estima[i] < *menor)
{
*menor = estima[i]; //quando atualizar menor, salva em posicao o �ndice (corresponde ao n� a ser visitado).
*posicao = i;
}
}
estima[*posicao]=INF; //Na pr�xima an�lise de estima o valor "menor atual" n�o far� parte, pois agora � n�mero infinito.
return *posicao; //retorna o �ndice da estima que corresponde ao n� de menor custo.
}


void calc_peso(int *estima, int *menor, int *posicao, int *foi, int origem, int destino, int *custo, int *prec, int M[MAX][MAX])
{ //fun��o para calcular os custos.
int k,j;
foi[origem]=0; //o primeiro n� j� recebe os valores.
custo[origem] = 0;
prec[origem] = origem;
k = origem; // usa-se o 'k' como sendo o vertice a ser visitado.

while(!foi[destino]) //enquanto o n� do destino ainda n�o foi visitado...
{

if(!foi[k]) //se o n� atual n�o foi visitado...
for(j=0 ; j<MAX ; j++) //visita os vizinhos.
if ((M[k][j]) > 0) //se o vizinho tiver custo maior que zero...
{
M[j][k]*=(-1); //marca o caminho inverso do n� ao precedente para n�o ser visitado novamente.

if(custo[j]>custo[k]+(M[k][j])) //se custo do n� for menor do que o calculado antes...
{
prec[j]=k; //atualiza o precedente.
custo[j]=custo[k]+(M[k][j]); //atualiza o custo.
estima[j]=custo[j]; //guarda o custo do n�, para despois ver quem tem o menor custo e ser escolhido como pr�ximo n� a ser visitado.
}
}
foi[k]=1; //marca o n� como visitado.
k=estima_menor(estima,menor,posicao); //atualiza o n� a ser visitado, verificando qual tem o menor custo.
}
}

void faz_caminho(int *caminho, int destino, int *prec, int *cont_caminho, int origem,int *estima, int *custo)
{ //fun��o que guarda no vetor caminho, a rota para tra�ar o caminho de menor custo.
int i,j; //obs. caminho[0] guarda o �ltimo n� e caminho[cont_caminho] guarda o n� origem

caminho[0]= destino; //guarda em caminho[0] o n� destino.
i=1;
j=destino;


while (prec[j] >=0) //enquanto o precedente do n� n�o � zero "n� de origem", ou seja, enquanto n�o chega na origem.
{
(*cont_caminho)++; //incrementa o contador para saber o tamanho do vetor caminho.
caminho[i]=prec[j]; //caminho[0] j� preenchido. Caminho (a partir do 1) com o valor do precedente do n� atual j.
i++;
j=prec[j]; //faz o n� atual ser o seu precedente.
if (j==origem) //se n� atual igual a origem, significa que chegou na origem e a rota completa j� est� guardada no vetor caminho.
break;
}
}

void imprime_caminho(int *caminho, int origem, int destino, int cont_caminho,int *custo)
{ //fun��o para imprimir a rota armazenada no vetor caminho.
int k,j,i,contador;
k=cont_caminho; //atualiza k com o tamanho do vetor caminho.
contador=k; //contador para diferenciar a impress�o do destino.

while (k>=0)
{
j=k;
i=caminho[j]; //armazena em i o valor de caminho para depois fazer a equivalencia com os v�rtices "ABCDEF".
if (contador>0)
printf("%d -> ",i);
else //contador n�o foi maior que zero, ou seja, � o �ltimo n� a ser impresso...
printf("%d\n",i); //n�o aparece a seta.
k--; //decrementa k para imprimir o pr�ximo caminho
contador--; //decrementa o contador que n�o deixar� imprimir a seta para o �ltimo n�.

}

printf("\n");
printf("MENOR custo entre origem '%d' e o destino '%d' �: %d\n\n\n\n",origem,destino,custo[destino]);
}




main()
{

int* caminho= (int*)malloc(sizeof(caminho));
int menor,estima[MAX],posicao;
int foi[MAX],custo[MAX],prec[MAX],origem=0,destino=3;// Define origem 0 e destino 3, como se pede no mapa 

float tstart=0, tend=0, tempo=0;
int nciclo=0;
int N =1, K;
int i,j,aux=0;
int M[MAX][MAX]={{0,100,700,  0,  0},// Matriz definida de acordo com RA do aluno cada n�mero x100 define o peso entre v�rtices
                 {0,  0,  0,500,200},
                 {0,400,  0,700,  0},
                 {0,  0,  0,  0,  0},
                 {0,  0,  0,100,  0}};
char pal[MAX];

for (i=1; i<NUM; i++){
for (j=1; j<NUM; j++){

}
}

for (aux=0; aux<NUM*NUM; aux++){

M[i][j] = atoi(pal);
M[j][i] = atoi(pal);
}

imp_grafo(M);

do
{
int cont_caminho=0; //zera o contador que indica o tamanho do vetor caminho
printf("\nConforme Mapa, e baseado no algoritmo de Dijkstra pede-se:\n\nMenor caminho entre origem 0 e destino 3 para calculo do caminho de menor custo!\n\n");
//printf("\n SAIR - digite origem '0' e destino '0'\n\n");
dig_origem_destino(&origem,&destino);

if(origem==destino)
{
printf("\nOp��o escolhida foi origem [0] e destino [0]\n PROGRAMA FINALIZADO\n");
system("pause");
break;
}

inicializa(foi,custo,prec,estima); //inicializa as vari�veis.
calc_peso(estima,&menor,&posicao,foi,origem,destino,custo,prec,M); //calcula os custos
faz_caminho(caminho,destino,prec,&cont_caminho,origem,estima,custo); //armazena o caminho de menor custo
imprime_caminho(caminho,origem,destino,cont_caminho,custo); //imprime o caminho de menor custo

system("pause");

}while(origem==destino);

return 0;
}
