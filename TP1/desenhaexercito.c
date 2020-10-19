#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include "desenhaexercito.h"
#include "variaveisglobais.h"

#define tamanhoLadoXSprite 50 //o lado do quadrado q contem a sprite do personagem principal tem 80 de largura e altura.
#define tamanhoLadoYSprite 50 //é retangular
#define xSpriteAtual 0.1 //x para a seleção da imagem da sprite

void abateDeGado(){
	for (int i = 0; i < 8; i++){
		if(xVerticeGado[i] <= xCaninha && xCaninha <= xVerticeGado[i]+tamanhoLadoXSprite){
			if(yCaninha-ladoCaninha<=yVerticeGado && yVerticeGado<= yCaninha+ladoCaninha)
				ativo[i]=0;		

				
	 			
		}
	}
	int soma = 0;
	 for (int i = 0; i < 8; ++i)
	 {
	 	soma = ativo[i]+ ativo2[i]+soma;
	 }
	 if (soma==0){
	 	continua=0;
	 }
		
	// printf("\n");
	
}

void abateDeGado2(){
	for (int i = 0; i < 7; i++){
		if(xVerticeGado[i]+xGado2 <= xCaninha && xCaninha <= xVerticeGado[i]+xGado2+tamanhoLadoXSprite){
			if(yCaninha-ladoCaninha<=yVerticeGado-yGado2 && yVerticeGado-yGado2<= yCaninha+ladoCaninha)
				ativo2[i]=0;			
		}
		
	}

	// for (int i = 0; i < 8; i++){
	// 	printf("%d \t",ativo[i]);
	// }
	// printf("\n");
	
	
}

void desenhaExercito(){

    //glEnable(GL_TEXTURE_2D);
    //glBindTexture(GL_TEXTURE_2D, idTexturaGado);
	for(int i=0; i<8;i++){
    //glBegin(GL_POLYGON);
  	
		if (ativo[i]){
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, idTexturaGado);
			glBegin(GL_POLYGON);
		
				glTexCoord2f(0.3, 1);
				glVertex3f(xVerticeGado[i],  yVerticeGado,  0); //cima esquerda

				glTexCoord2f(0.3,0.01);
				glVertex3f(xVerticeGado[i], yVerticeGado - tamanhoLadoYSprite, 0);

				glTexCoord2f(0.66, 0.01);
				glVertex3f(xVerticeGado[i]+tamanhoLadoXSprite, yVerticeGado - tamanhoLadoYSprite,0);

				glTexCoord2f(0.66,1);
				glVertex3f(xVerticeGado[i]+tamanhoLadoXSprite,yVerticeGado,0);


			glEnd();
		}
		if(xVerticeGado[0]<10)
			sinal*=-1;
		else if(xVerticeGado[7]>620)
				sinal*=-1;
		
		for (int u = 0; u < 8; u++)
		{
			xVerticeGado[u]+=sinal; 
		}
		
		  
    }

	for(int i=0; i<7;i++){
    //glBegin(GL_POLYGON);
  	
		if (ativo2[i]){
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, idTexturaGado);
			glBegin(GL_POLYGON);
		
				glTexCoord2f(0.3, 1);
				glVertex3f(xVerticeGado[i]+xGado2,  yVerticeGado-yGado2,  0); //cima esquerda

				glTexCoord2f(0.3,0.01);
				glVertex3f(xVerticeGado[i]+xGado2, yVerticeGado-yGado2 - tamanhoLadoYSprite, 0);

				glTexCoord2f(0.66, 0.01);
				glVertex3f(xVerticeGado[i]+xGado2+tamanhoLadoXSprite, yVerticeGado-yGado2 - tamanhoLadoYSprite,0);

				glTexCoord2f(0.66,1);
				glVertex3f(xVerticeGado[i]+xGado2+tamanhoLadoXSprite,yVerticeGado-yGado2,0);


			glEnd();
		}
		if(xVerticeGado[0]<10)
			sinal*=-1;
		else if(xVerticeGado[7]>620)
				sinal*=-1;
		
		for (int u = 0; u < 8; u++)
		{
			xVerticeGado[u]+=sinal; 
		}
		
		  
    }

    
    glDisable(GL_TEXTURE_2D);
}
