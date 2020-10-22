#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>

#include "desenhanave.h"
#include "desenhaexercito.h"
#include "variaveisglobais.h"
#include "desenhaeatualiza.h"
#include "desenhaTiroInimigo.h"
#include "contagemVidas.h"

void atira(){
    if(tiro){
        atiraCaninha();
        if(acerto == 0 && yCaninha<700){
            yCaninha+=10;
        }
        else{
            acerto=0;
            tiro=0;
            yCaninha=80;
            
        }  
    }
}

void jogaTiroInimigo(){

    if(yTiroInimigo>0 && acertouOLulinha==0){
        yTiroInimigo-=10;
    }
    else{
        acertouOLulinha = 0;
        escolheInimigo = rand()%8;

            if(ativo[escolheInimigo]==1){
                yTiroInimigo = yVerticeGado;
                xTiroInimigo = xVerticeGado[escolheInimigo]-20;  
            }

            else if(ativo2[escolheInimigo]==1 ){
                yTiroInimigo = yVerticeGado-yGado2;
                xTiroInimigo = xVerticeGado[escolheInimigo];
            }

            else if(ativo3[escolheInimigo]==1){
                yTiroInimigo = yVerticeGado-yGado2-yGado2;
                xTiroInimigo = xVerticeGado[escolheInimigo];
            }
            
    }
    desenhaTiroInimigo();
}

void gameOver(){
    
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, idTexturaGameOver);
        glBegin(GL_TRIANGLE_FAN);

                    
            glTexCoord2f(0, 0);
            glVertex3f(150, 125,  0);

            glTexCoord2f(1, 0);
            glVertex3f( 550, 125,  0);

            glTexCoord2f(1, 1);
            glVertex3f( 550,  525,  0);

            glTexCoord2f(0, 1);
            glVertex3f(150,  525,  0);
                

        glEnd();
        glDisable(GL_TEXTURE_2D);
    
}

void ganhou(){
    
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, idTexturaGanhou);
        glBegin(GL_TRIANGLE_FAN);

                    
            glTexCoord2f(0, 0);
            glVertex3f(150, 125,  0);

            glTexCoord2f(1, 0);
            glVertex3f( 550, 125,  0);

            glTexCoord2f(1, 1);
            glVertex3f( 550,  525,  0);

            glTexCoord2f(0, 1);
            glVertex3f(150,  525,  0);
                

        glEnd();
        glDisable(GL_TEXTURE_2D);
    
}

void desenha() {

    if(!inicia){
        contagemdetempo++;
        if (contagemdetempo%22==0)
        {
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, idTexturaAperteI2);
            glBegin(GL_TRIANGLE_FAN);
            
                glTexCoord2f(0, 0);
                glVertex3f(0, 0,  0);

                glTexCoord2f(1, 0);
                glVertex3f( 700, 0,  0);

                glTexCoord2f(1, 1);
                glVertex3f( 700,  650,  0);

                glTexCoord2f(0, 1);
                glVertex3f(0,  650,  0);

            glEnd();
            glDisable(GL_TEXTURE_2D);

            glutSwapBuffers();
        }
        else if (contagemdetempo%5==0){
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, idTexturaAperteI);
            glBegin(GL_TRIANGLE_FAN);
            
                glTexCoord2f(0, 0);
                glVertex3f(0, 0,  0);

                glTexCoord2f(1, 0);
                glVertex3f( 700, 0,  0);

                glTexCoord2f(1, 1);
                glVertex3f( 700,  650,  0);

                glTexCoord2f(0, 1);
                glVertex3f(0,  650,  0);

            glEnd();
            glDisable(GL_TEXTURE_2D);

            glutSwapBuffers();
        }

    }
    
    else{
        if(pause==0&&continuaGanhou && continuaGanhou && desenhadoGameOver==0 ){

        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f (1, 1, 1);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, idTexturaFundo);
        glBegin(GL_TRIANGLE_FAN);
            
            glTexCoord2f(0, 0);
            glVertex3f(0, 0,  0);

            glTexCoord2f(1, 0);
            glVertex3f( 700, 0,  0);

            glTexCoord2f(1, 1);
            glVertex3f( 700,  650,  0);

            glTexCoord2f(0, 1);
            glVertex3f(0,  650,  0);

            glEnd();
            glDisable(GL_TEXTURE_2D);

            contagemVidas();
            desenhaLegenda();
            jogaTiroInimigo();
            desenhaNave();
            abateDeGado();
            abateDeGado2();
            abateDeGado3();
        	continuar(); 
            desenhaExercito();
            atira();
            abateLulinha();

            if (continuaPerdeu==0)
            {
                gameOver();
                desenhadoGameOver=1;
            }
            if(continuaGanhou==0){
                ganhou();
                desenhadoGameOver=1;
            }

            //nivel=nivel+1;
            //if(nivel>1000)
            //    jogaTiroInimigo();


            
            glutSwapBuffers();
        }
    }
}




void atualiza(int periodo) {
    
        
        glutPostRedisplay();
        glutTimerFunc(33,atualiza,0);
        
    

    //else{
        //tela ganhou companheiro
    //}
}
