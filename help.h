#include<windows.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>

using namespace std;
//linha da matriz
int jfirst=0;
//coluna da matriz
int ifirst=0;
//variavel auxiliar que recebe o valor do elemento [i][j] da matriz antes de atualizar esse valor
int aux;
//contadores para definir o número de passos dados para cada elemento da matriz percorrido
int ii=0;
int auxii=0;
int auxjj=0;
//define a direcao para a qual ira a BOLINHA
int direcao=2;
//movimento inicial em y
float tx=0.0;
//movimento inicial em y
float ty=0.0;
//movimento inicial em z
float tz=0.0;
//velocidade
int val=1;
int vel=80;
//comprimento do cano/T
float tamcanoh=1;
int win1;
int win2;
int win3;
// Angulo de rotação que define a direcao da camera
float angulo=0.0;
// vetor que representa a direcao da camera. 'ponto' para o qual o olho aponta
float lx=0.0f,centromundoy=0,lz=-1.0f;
//vetor que define a posicao da camera
float x=0.0f,cameray=1.5,z=1.0f;

static void display();
void anima(int valor);
void escolhecaminho();
void movevertical();
void movehorizontal();
void movet50ec(int valor);
void movet30eb(int valor);
void movet30ec(int valor);
void movet30db(int valor);
void movet30dc(int valor);
void escolhecaminhot();
/**
declara a matriz que dará origem ao movimento na cena 1
1= vertical
2= horizontal
31= joelho esquerda cima 90º
34= joelho esquerda baixo 90º
33= joelho direita cima 90º
32= joelho direita baixo 90º
5= Cruz
7=T
54= joelho esquerda  180º
47= Final esquerda 1 / Final direita 2
70= Final cima 1
80= Final baixo3->1
82= final baixo 3->2
**/
int cena1[12][16];
int ll,cc;
int caminho;

void cenarios(){
    //declara a variável para file
    ifstream txtFile;
    //abre o arquivo matriz
if (val==1)
    {
    txtFile.open("C:\\MarcosPedroso\\mapa.txt");
    }

    if(val==2)
    {
        txtFile.open("C:\\MarcosPedroso\\mapa1.txt");
    }

    if(val==3)
    {
        txtFile.open("C:\\MarcosPedroso\\mapa2.txt");
    }


    //Le o tamanho da matriz no arquivo
    txtFile >> ll >> cc;

    //le os valores e preenche a matriz
    for(int i=0; i<ll; i++)
        {
           for (int j=0;j<cc;j++)
           {
               txtFile>>cena1[i][j];
           }
        }
        for(int i=0; i<ll; i++)
        {
           for (int j=0;j<cc;j++)
           {
               cout<<cena1[i][j]<< "   ";
           }
           cout<<endl;
        }
}

