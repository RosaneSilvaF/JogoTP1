#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>

GLuint idTexturaFundo,idTexturaLulinha;
GLuint texturaAtual;
float xTextura,yTextura,xPosicaoSprite,xVerticeSprite=160;
int ladoDir=1,ladoEsq=1,direita=0,frames=0,costas=1,primeiraVez=1;

GLuint carregaTextura(const char* arquivo) {
    GLuint idTextura = SOIL_load_OGL_texture(
                           arquivo,
                           SOIL_LOAD_AUTO,
                           SOIL_CREATE_NEW_ID,
                           SOIL_FLAG_INVERT_Y
                       );

    if (idTextura == 0) {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }

    return idTextura;
}

void inicializa() {
    glClearColor(1, 1, 1, 1);

    // habilita mesclagem de cores, para termos suporte a texturas
    // com transparência
    glEnable(GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    idTexturaFundo = carregaTextura("fundo.png");
    idTexturaLulinha= carregaTextura("sprite_lulinha.png");
}

void desenhaNave(){
    texturaAtual=idTexturaLulinha;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texturaAtual);
    glBegin(GL_TRIANGLE_FAN);
        if (costas){
            glTexCoord2f(0.4, 0);
            glVertex3f(xVerticeSprite, 10,  0);
            xVerticeSprite+=80;

            glTexCoord2f(0.5, 0);
            glVertex3f( xVerticeSprite, 10,  0);

            glTexCoord2f(0.5,1);
            glVertex3f( xVerticeSprite,  90,  0);
            xVerticeSprite-=80;

            glTexCoord2f(0.4, 1);
            glVertex3f(xVerticeSprite,  90,  0);
        }
        else{
            if(!direita){
                glTexCoord2f(xPosicaoSprite, 0);
                glVertex3f(xVerticeSprite, 10,  0);
                xPosicaoSprite+=0.1;
                xVerticeSprite+=80;

                glTexCoord2f(xPosicaoSprite, 0);
                glVertex3f( xVerticeSprite, 10,  0);

                glTexCoord2f(xPosicaoSprite,1);
                glVertex3f( xVerticeSprite,  90,  0);
                xPosicaoSprite-=0.1;
                xVerticeSprite-=80;

                glTexCoord2f(xPosicaoSprite, 1);
                glVertex3f(xVerticeSprite,  90,  0);
            }

            else{
                glTexCoord2f(xPosicaoSprite, 0);
                glVertex3f(xVerticeSprite, 10,  0);
                xPosicaoSprite+=0.1;
                xVerticeSprite+=80;

                glTexCoord2f(xPosicaoSprite, 0);
                glVertex3f( xVerticeSprite, 10,  0);

                glTexCoord2f(xPosicaoSprite,1);
                glVertex3f( xVerticeSprite,  90,  0);
                xPosicaoSprite-=0.1;
                xVerticeSprite-=80;

                glTexCoord2f(xPosicaoSprite, 1);
                glVertex3f(xVerticeSprite,  90,  0);
            }
        }

    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void desenha() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (1, 1, 1);

    // Habilita o uso de texturas
    glEnable(GL_TEXTURE_2D);

    // Começa a usar a textura que criamos
    glBindTexture(GL_TEXTURE_2D, idTexturaFundo);
    glBegin(GL_TRIANGLE_FAN);
        // Associamos um canto da textura para cada vértice
        glTexCoord2f(0, 0);
        glVertex3f(0, 0,  0);

        glTexCoord2f(1, 0);
        glVertex3f( 400, 0,  0);

        glTexCoord2f(1, 1);
        glVertex3f( 400,  600,  0);

        glTexCoord2f(0, 1);
        glVertex3f(0,  600,  0);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    desenhaNave();

    glutSwapBuffers();
}

void redimensiona(int w, int h) {
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 400, 0, 600, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
}

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

void spriteEsquerda() {
  
  if (primeiraVez)
  {
    xVerticeSprite=160;
    primeiraVez=0;
  }
  if (ladoEsq)
  {
    xPosicaoSprite=0.3;
      ladoEsq=0;
      ladoDir=1;

  }
  else{
    if (xVerticeSprite>=10)
    {
        xVerticeSprite-=10;
    }
  
    xPosicaoSprite-=0.1;
    
  }
  if (xPosicaoSprite<0.1)
  {
      xPosicaoSprite=0.3;
  }
  direita=1;
}

void spriteDireita() {  
  if (primeiraVez)
  {
    xVerticeSprite=160;
    primeiraVez=0;
  }
  if (ladoDir)
  {
      xPosicaoSprite=0.5;
      ladoDir=0;

      ladoEsq=1;
  }
  else {
    if (xVerticeSprite<320)
    {
        xVerticeSprite+=10;
    }
    xPosicaoSprite+=0.1;
  }
  if (xPosicaoSprite>0.9)
  {
      xPosicaoSprite=0.5;
  }
  direita=0;
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

void atualiza(int periodo) {
    glutPostRedisplay();
    glutTimerFunc(33,atualiza,0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 600);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Carregando textura com SOIL");

    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    glutSpecialFunc(especial);
    glutDisplayFunc(desenha);
    glutTimerFunc(33,atualiza,0);

    inicializa();

    glutMainLoop();

    return 0;
}