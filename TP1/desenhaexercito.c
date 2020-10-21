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

void abateLulinha(){

	if(xVerticeSprite <= xTiroInimigo && xTiroInimigo <= xVerticeSprite+tamanhoLadoXSprite){
		if(yTiroInimigo-10<=yVerticeSprite && yVerticeSprite<= yTiroInimigo+10){
			printf("Lulinha foi atingido!!!");
			vidas-=1;
			printf(vidas);	
		}
		if(vidas==0){
			continua=1;
		}
		
	}
	
}
void abateDeGado(){
	for (int i = 0; i < 8; i++){
		if(xVerticeGado[i] <= xCaninha && xCaninha <= xVerticeGado[i]+tamanhoLadoXSprite){
			if(yCaninha-ladoCaninha<=yVerticeGado && 
				yVerticeGado<= yCaninha+ladoCaninha && 
				ativo[i]==1){
				ativo[i]=0;	
				acerto=1;	
			}
		
		}

	}	
	// printf("\n");
	
}

void abateDeGado2(){
	for (int i = 0; i < 7; i++){
		if(xVerticeGado[i]+xGado2 <= xCaninha && xCaninha <= xVerticeGado[i]+xGado2+tamanhoLadoXSprite){
			if(yCaninha-ladoCaninha<=yVerticeGado-yGado2 && 
				yVerticeGado-yGado2<= yCaninha+ladoCaninha && 
				ativo2[i]==1){

				ativo2[i]=0;	
				acerto=1;		
			}
		}
		
	}

	// for (int i = 0; i < 8; i++){
	// 	printf("%d \t",ativo[i]);
	// }
	// printf("\n");
	
	
}

void abateDeGado3(){
	for (int i = 0; i < 7; i++){
		if(xVerticeGado[i]+xGado2 <= xCaninha && xCaninha <= xVerticeGado[i]+xGado2+tamanhoLadoXSprite){
			if(yCaninha-ladoCaninha<=yVerticeGado+yGado2 && 
				yVerticeGado+yGado2<= yCaninha+ladoCaninha && 
				ativo3[i]==1){

				ativo3[i]=0;
				acerto=1;			
			}
		}
		
	}

	// for (int i = 0; i < 8; i++){
	// 	printf("%d \t",ativo[i]);
	// }
	// printf("\n");
	
	
}
void continuar(){
	int soma = 0;
	for (int i = 0; i < 8; ++i){
	 	soma += ativo[i];
	}
	for (int i = 0; i < 7; ++i){
	 	soma += ativo2[i];
	}
		for (int i = 0; i < 7; ++i){
	 	soma += ativo3[i];
	}
	
	if (soma==0){
		continua=0;
	}
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
				glVertex3f(xVerticeGado2[i],  yVerticeGado,  0); //cima esquerda

				glTexCoord2f(0.3,0.01);
				glVertex3f(xVerticeGado2[i], yVerticeGado - tamanhoLadoYSprite, 0);

				glTexCoord2f(0.66, 0.01);
				glVertex3f(xVerticeGado2[i]+tamanhoLadoXSprite, yVerticeGado - tamanhoLadoYSprite,0);

				glTexCoord2f(0.66,1);
				glVertex3f(xVerticeGado2[i]+tamanhoLadoXSprite,yVerticeGado,0);


			glEnd();
		}
		if(xVerticeGado2[0]<5)
			sinal2*=-1;
		else if(xVerticeGado2[7]>620)
				sinal2*=-1;
		
		for (int u = 0; u < 8; u++)
		{
			xVerticeGado2[u]-=sinal2*2; 
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
	for(int i=0; i<7;i++){
    //glBegin(GL_POLYGON);
  	
		if (ativo3[i]){
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, idTexturaGado);
			glBegin(GL_POLYGON);
		
				glTexCoord2f(0.3, 1);
				glVertex3f(xVerticeGado[i]+xGado2,  yVerticeGado+yGado2,  0); //cima esquerda

				glTexCoord2f(0.3,0.01);
				glVertex3f(xVerticeGado[i]+xGado2, yVerticeGado+yGado2 - tamanhoLadoYSprite, 0);

				glTexCoord2f(0.66, 0.01);
				glVertex3f(xVerticeGado[i]+xGado2+tamanhoLadoXSprite, yVerticeGado+yGado2 - tamanhoLadoYSprite,0);

				glTexCoord2f(0.66,1);
				glVertex3f(xVerticeGado[i]+xGado2+tamanhoLadoXSprite,yVerticeGado+yGado2,0);


			glEnd();
		}
		if(xVerticeGado[0]<10)
			sinal3*=-1;
		else if(xVerticeGado[7]>620)
				sinal3*=-1;
		
		for (int u = 0; u < 8; u++)
		{
			xVerticeGado[u]+=sinal3*2; 
		}
		
		  
    }

    
    glDisable(GL_TEXTURE_2D);
}
