#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

#include "carregatextura.h"
#include "variaveisglobais.h"
#include "inicializa.h"


void inicializa() {
    glClearColor(1, 1, 1, 1);

    glEnable(GL_BLEND);
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
    idTexturaComecar = carregaTextura("comecar.png");
    idTexturaControles = carregaTextura("controles.png");
    idTexturaTitulo = carregaTextura("titulo.png");
    idTexturaLegenda= carregaTextura("pausar.png");

    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,4096);
    music=Mix_LoadMUS("music.mp3");
    if(!music) {
        printf("Mix_LoadMUS(\"music.mp3\"): %s\n", Mix_GetError());
        // this might be a critical error...
}

    //musicaFundo=Mix_LoadMUS("HINO DA INDEPENDÊNCIA DO BRASIL.mp3");


}
