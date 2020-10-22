#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "variaveisglobais.h"
#include "eventosteclado.h"
#include "ladospriteandando.h"
#include "atiracaninha.h"
#include "desenhaeatualiza.h"
#include "reinicializa.h"


void teclado(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
        break;
        case 32:
            costas=1;
            tiro=1;
            if(yCaninha==80){
                xCaninha=xVerticeSprite+40;
            }
            
        break;
        case 105:
        case 73:
            inicia=1;
        break;
        
        case 112:
        case 80:
            if(pause==1){
                pause=0;
                pausaMusica(pause);
            } 
            else{
                pause=1;
                pausaMusica(pause);
            }
                
        break;
        case 114:
        case 82:
            reinicializa();
        break;
        
    }
}

void especial(int key, int x, int y){
    switch (key){
        case GLUT_KEY_LEFT:
            spriteEsquerda();
            costas=0;
        break;

        case GLUT_KEY_RIGHT:
            spriteDireita();
            costas=0;
        break;
            
    }
}
