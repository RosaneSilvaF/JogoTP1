#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>

#include "carregatextura.h"
#include "variaveisglobais.h"
#include "inicializa.h"

void inicializa() {
    glClearColor(1, 1, 1, 1);

    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    idTexturaFundo = carregaTextura("fundo.png");
    idTexturaLulinha= carregaTextura("sprite_lulinha.png");
    idTexturaCaninha = carregaTextura("caninha.png");
    idTexturaGado = carregaTextura("sprite_exercito.png");
}
