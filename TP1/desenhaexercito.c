#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include "desenhaexercito.h"
#include "variaveisglobais.h"

#define tamanhoLadoXSprite 104 //o lado do quadrado q contem a sprite do personagem principal tem 80 de largura e altura.
#define tamanhoLadoYSprite 110 //é retangular
#define xSpriteAtual 0.1 //x para a seleção da imagem da sprite 

float yVerticeSprite=100;

void desenhaExercito(){
	soldado.x=100;
	soldado.y=100;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, sprite_exercito);
    glBegin(GL_TRIANGLE_FAN);
  	for(int i=0; i<15;i++){
		if (ativo){
		    glTexCoord2f(0.3, 0);
		    glVertex3f(xVerticeSprite,  yVerticeSprite,  0);
		    yVerticeSprite-=tamanhoLadoSprite;
		    glTranslatef(soldado.x, soldado.y, 0);

		}
        
    }

    glEnd();
    glDisable(GL_TEXTURE_2D);
}
