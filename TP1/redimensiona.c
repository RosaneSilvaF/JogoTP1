#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "variaveisglobais.h"
#include "redimensiona.h"


void redimensiona(int w, int h) {
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 700, 0, 650, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
}