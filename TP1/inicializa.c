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
    idTexturaGameOver = carregaTextura("gameOver.png");
    idTexturaGanhou = carregaTextura("ganhou.png");
    idTexturaVidas1 = carregaTextura("vidas1.png");
    idTexturaVidas2 = carregaTextura("vidas2.png");
    idTexturaVidas3 = carregaTextura("vidas3.png");
    idTexturaAlgema = carregaTextura("algema.png");
    idTexturaAperteI= carregaTextura("apertei.png");
    idTexturaAperteI2= carregaTextura("apertei2.png");
    idTexturaLegenda= carregaTextura("pausar.png");
}
