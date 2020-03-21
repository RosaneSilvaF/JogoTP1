#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>

GLuint idTexturaFundo,idTexturaLulinhaParado;

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
    idTexturaLulinhaParado= carregaTextura("lulinha_costas.png");
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
        glVertex3f( 500, 0,  0);

        glTexCoord2f(1, 1);
        glVertex3f( 500,  700,  0);

        glTexCoord2f(0, 1);
        glVertex3f(0,  700,  0);

        glBindTexture(GL_TEXTURE_2D, idTexturaLulinhaParado);
        glTexCoord2f(0, 0);
        glVertex3f(100, 50,  0);

        glTexCoord2f(1, 0);
        glVertex3f( 202, 50,  0);

        glTexCoord2f(1, 1);
        glVertex3f( 202,  139,  0);

        glTexCoord2f(0, 1);
        glVertex3f(100,  139,  0);

    glEnd();
    glDisable(GL_TEXTURE_2D);

    glutSwapBuffers();
}

void redimensiona(int w, int h) {
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 500, 0, 700, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
}

void teclado(unsigned char key, int x, int y) {
    switch (key) {
    case 27:
        exit(0);
    }
}

void atualiza() {
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 700);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Carregando textura com SOIL");

    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    glutDisplayFunc(desenha);
    glutIdleFunc(atualiza);

    inicializa();

    glutMainLoop();

    return 0;
}