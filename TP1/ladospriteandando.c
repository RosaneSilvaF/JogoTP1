#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>

#include "variaveisglobais.h"
#include "ladospriteandando.h"


void spriteEsquerda() {
  
  if (primeiraVez)
  {
    xVerticeSprite=160;
    primeiraVez=0;
  }
  if (ladoEsq)
  {
    xPosicaoSprite=0.3;
      ladoEsq=0;
      ladoDir=1;

  }
  else{
    if (xVerticeSprite>=10)
    {
        xVerticeSprite-=10;
    }
  
    xPosicaoSprite-=0.1;
    
  }
  if (xPosicaoSprite<0.1)
  {
      xPosicaoSprite=0.3;
  }
  direita=1;
}

void spriteDireita() {  
  if (primeiraVez)
  {
    xVerticeSprite=160;
    primeiraVez=0;
  }
  if (ladoDir)
  {
      xPosicaoSprite=0.5;
      ladoDir=0;

      ladoEsq=1;
  }
  else {
    if (xVerticeSprite<320)
    {
        xVerticeSprite+=10;
    }
    xPosicaoSprite+=0.1;
  }
  if (xPosicaoSprite>0.9)
  {
      xPosicaoSprite=0.5;
  }
  direita=0;
}