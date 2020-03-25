#include "includes.h"

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