#include "includes.h"

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 650);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Luladrão roubou meu coração");

    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    glutSpecialFunc(especial);
    glutDisplayFunc(desenha);
    glutTimerFunc(33,atualiza,0);

    inicializa();

    glutMainLoop();

    return 0;
}