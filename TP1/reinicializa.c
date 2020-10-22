#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "variaveisglobais.h"

void reinicializa(){
	xVerticeSprite = 325;
	yCaninha = 80;
	xCaninha = 200;
	ladoCaninha = 14;
	xVerticeGado[0]= 10;
	xVerticeGado[1]= 90;
	xVerticeGado[2]= 170;
	xVerticeGado[3]= 250;
	xVerticeGado[4]= 330;
	xVerticeGado[5]= 410;
	xVerticeGado[6]= 490;
	xVerticeGado[7]= 570;
	xVerticeGado2[0]= 10;
	xVerticeGado2[1]= 90;
	xVerticeGado2[2]= 170;
	xVerticeGado2[3]= 250;
	xVerticeGado2[4]= 330;
	xVerticeGado2[5]= 410;
	xVerticeGado2[6]= 490;
	xVerticeGado2[7]= 570;
	yVerticeGado = 500;
	xTiroInimigo = 0;
	yTiroInimigo = 0;
	ladoDir=1;
	ladoEsq=1;
	direita=0;
	frames=0;
	costas=1;
	primeiraVez=1;
	tiro=0;
	xGado2=30;
	yGado2=50; 
	pause=0; 
	acerto=0; 
	nivel=0;
	sinal=0.1;
	sinal2=0.1;
	sinal3=0.1;
	continuaPerdeu=1;
	continuaGanhou=1;
	tiroInimigo=1;
	tamanho=0; 
	escolheInimigo=0;
	vidas=3; 
	acertouOLulinha = 0;
	desenhadoGameOver=0;

	for (int i = 0; i < 8; ++i)
	{
		ativo[i]=1;
	}
	for (int i = 0; i < 7; ++i)
	{
		ativo2[i]=1;
	}
	for (int i = 0; i < 7; ++i)
	{
		ativo3[i]=1;
	}
}