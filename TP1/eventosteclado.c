#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>

#include "variaveisglobais.h"
#include "eventosteclado.h"
#include "ladospriteandando.h"


void teclado(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
        break;
        case 32:
            costas=1;
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
