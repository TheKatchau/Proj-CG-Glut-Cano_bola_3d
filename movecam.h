
static void resize(int width, int height)
{
    camera();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        ///quit
        case 27 :
        ///quit
        case 'q':
            exit(0);
            break;
        /// reset
        case 'r':
            angulo=0.0;
            lx=0.0f;
            lz=-1.0f;
            x=0.0f;
            z=2.0f;
            cameray=1.5;
            centromundoy=0;
            break;
            ///move camera pra cima
            case 'w':
            cameray+= 0.05;
            centromundoy+=0.05;
            break;
            ///move camera pra baixo
            case 's':
            cameray-= 0.05;
            centromundoy-=0.05;
            break;
            ///rotaciona camera pra cima
            case '8':
            centromundoy+=0.05;
            break;
            ///rotaciona camera pra baixo
            case '2':
            centromundoy-=0.05;
            break;
    }
    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

void arrows(int key,int xx, int yy){

    float passo = 0.1f;

	switch (key) {
		case GLUT_KEY_LEFT :
			angulo -= 0.05f;
			lx = sin(angulo);
			lz = -cos(angulo);
			break;
		case GLUT_KEY_RIGHT :
			angulo += 0.05f;
			lx = sin(angulo);
			lz = -cos(angulo);
			break;
		case GLUT_KEY_UP :
			x += lx * passo;
			z += lz * passo;
			break;
		case GLUT_KEY_DOWN :
			x -= lx * passo;
			z -= lz * passo;
			break;
	}
	glutPostRedisplay();
}

