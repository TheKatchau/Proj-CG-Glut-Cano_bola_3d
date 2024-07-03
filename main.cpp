#include "animacao.h"

int main(int argc, char *argv[])
{
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
    cenarios();
    glutInit(&argc, argv);
    int width = 1000;
    int height = 800;
    glutInitWindowSize(width, height);
    int x =300;
    int y =15;
    glutInitWindowPosition(x, y);
    win1 = glutCreateWindow("Cena 1");
    glutSetWindow(win1);
    glutDisplayFunc(desenhacena1);

    glutReshapeFunc(resize);
    glutKeyboardFunc(key);
    glutSpecialFunc(arrows);
    glutIdleFunc(idle);
    glClearColor(0,1,1,1);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glutTimerFunc(vel, anima, val);

    glutMainLoop();
    return EXIT_SUCCESS;
}
