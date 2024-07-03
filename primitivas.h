#include"help.h"
#define PI 3.1415927

using namespace std;

static void esfera(void){
    glPushMatrix();
        glColor3d(1,0,1);
        glTranslatef(tx,ty,tz);
        glutSolidSphere(0.07,10,10);
    glPopMatrix();
}


void cano(GLfloat raio,GLfloat tamanho)
{
    GLfloat x = 0.0;
    GLfloat y = 0.0;
    GLfloat angulo = 0.0;
    GLfloat angulo_step = 0.1;
    /** Desenha o cano */
    if(tamanho==0.5)
    {
        glColor3ub(200,0,255);
    }
    else
        glColor3ub(0,0,0);

    glBegin(GL_LINE_STRIP);
    angulo = 0.0;
        while( angulo < 2*PI )
        {
            x = raio * cos(angulo);
            y = raio * sin(angulo);
            glVertex3f(x, y , tamanho);
            glVertex3f(x, y , 0.0);
            angulo+= angulo_step;
        }
    glEnd();
}

static void curva180(int aneis, int lados)
{
    glColor3ub(255,255,0);
    int i, j, k;
    double s, t, x, y, z, doispi;
    doispi = 2 * PI;
    glPushMatrix();
        glTranslatef(0.5,0,0);
        glRotatef(90,1,0,0);
        cano(0.3,0.5);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.5,0,0);
        glRotatef(90,1,0,0);
        cano(0.3,0.5);
    glPopMatrix();
    glColor3ub(255,255,0);
    for (i = 0; i < aneis; i++)
    {
        glBegin(GL_LINE_STRIP);
        for (j = 0; j <= lados/2; j++)
        {
            for (k = 1; k >= 0; k--)
            {
                s = (i + k) % aneis + 0.5;
                t = j % lados;
                x = (0.5+.3*cos(s*doispi/aneis))*cos(t*doispi/lados);
                y = (0.5+.3*cos(s*doispi/aneis))*sin(t*doispi/lados);
                z = .3 * sin(s * doispi / aneis);
                glVertex3f(x, y, z);
            }
        }
        glEnd();
    }
}

static void curva90(int aneis, int lados)
{
    glPushMatrix();
        glTranslatef(-0.5,0.5,0);
        glRotatef(90,0,1,0);
        cano(0.3,0.5);
    glPopMatrix();
    glColor3ub(0,255,0);
    int i, j, k;
    double s, t, x, y, z, doispi;
    doispi = 2 * PI;
    for (i = 0; i < aneis; i++)
    {
        glBegin(GL_LINE_STRIP);
        for (j = 0; j <= lados/4; j++)
        {
            for (k = 1; k >= 0; k--)
            {
                s = (i + k) % aneis + 0.5;
                t = j % lados;
                x = (0.5+.3*cos(s*doispi/aneis))*cos(t*doispi/lados);
                y = (0.5+.3*cos(s*doispi/aneis))*sin(t*doispi/lados);
                z = .3 * sin(s * doispi / aneis);
                glVertex3f(x, y, z);
            }
        }
        glEnd();
    }
}

void T(GLfloat raio,GLfloat tamanho)
{
GLfloat h0, h1, angulo, x, y;
    int i, j;
    int fatias = 16;
    /// Desenha o cano vertical
    glPushMatrix();
    glRotatef(220,0,0,1);
    glColor3f( 1.0f, 0.0,0 );
    for (i = 0; i < fatias; i++ )
    {
        ///fatias de 1->3 e 12->16
        if (i<4 || i>11)
        {
            h0 = (float)i / (float)fatias;
            h1 = (float)(i+1) / (float)fatias;
            glBegin(GL_LINE_STRIP);
            ///circunferencia total
                for ( j = 0; j <= 360; ++ j )
                {
                    angulo = PI * (float)j * PI / 180.0f;
                    x = raio * cos(angulo);
                    y = raio * sin(angulo);
                    glVertex3f( x, y, h0 );
                    glVertex3f( x, y, h1 );
                }
            glEnd();
            }
            ///fatias de 4->11
            else if (i>3&&i<12)
            {
                h0 = (float)i / (float)fatias;
                h1 = (float)(i+1) / (float)fatias;
                glBegin(GL_LINE_STRIP);
                ///transforma os sementos do cilindro em segmentos de circunferencia
                    for ( j = 0; j <= 90; ++ j )
                    {
                        angulo = PI * (float)j * PI / 180.0f;
                        x = raio * cos(angulo);
                        y = raio * sin(angulo);
                        glVertex3f( x, y, h0 );
                        glVertex3f( x, y, h1 );
                    }
                glEnd();
            }
    }
    glPopMatrix();
    glTranslatef(0,0,0.5);
///cano horizontal
    glPushMatrix();
        glTranslatef(-0.5,0,0);
        glRotatef(90,0,1,0);
        glRotatef(45,0,0,1);
        for (i = 0; i < fatias; i++ )
        {
            ///fatias de 1->4
            if (i<5)
            {
                h0 = (float)i / (float)fatias;
                h1 = (float)(i+1) / (float)fatias;
                glBegin(GL_LINE_STRIP);
                ///transforma os sementos do cilindro em segmentos de circunferencia
                    for ( j = 0; j <= 30; ++ j )
                    {
                        angulo = PI * (float)j * PI / 180.0f;
                        x = raio * cos(angulo);
                        y = raio * sin(angulo);
                        glVertex3f( x, y, h0 );
                        glVertex3f( x, y, h1 );
                    }
                glEnd();
            }
        }
    glRotatef(180,0,0,1);
    for (i = 0; i < fatias; i++ )
        {
            ///fatias de 1->4
            if(i<5)
            {
                h0 = (float)i / (float)fatias;
                h1 = (float)(i+1) / (float)fatias;
                glBegin(GL_LINE_STRIP);
                ///circunferencia total
                    for ( j = 0; j <= 360; ++ j )
                    {
                        angulo = PI * (float)j * PI / 180.0f;
                        x = raio * cos(angulo);
                        y = raio * sin(angulo);
                        glVertex3f( x, y, h0 );
                        glVertex3f( x, y, h1 );
                    }
                glEnd();
            }
    }
    glPopMatrix();
}

static void Cruz(GLfloat raio,GLfloat tamanho)
{
    GLfloat h0, h1, angulo, x, y;
    int i, j;
    int fatias = 16;
    glColor3f( 0.0f, 0.0,1 );
    /// Desenha o cano vertical
    for (i = 0; i < fatias; i++ )
    {
        ///fatias de 1->3 e 12->16
        if (i<4 || i>11)
        {
            h0 = (float)i / (float)fatias;
            h1 = (float)(i+1) / (float)fatias;
            glBegin(GL_LINE_STRIP);
            ///circunferencia total
                for ( j = 0; j <= 360; ++ j )
                {
                    angulo = PI * (float)j * PI / 180.0f;
                    x = raio * cos(angulo);
                    y = raio * sin(angulo);
                    glVertex3f( x, y, h0 );
                    glVertex3f( x, y, h1 );
                }
            glEnd();
            }
    }
    glTranslatef(0,0,0.5);
    /// Desenha o cano horizontal
    glPushMatrix();
        glTranslatef(-0.5,0,0);
        glRotatef(90,0,1,0);
        glRotatef(45,0,0,1);
        for (i = 0; i < fatias; i++ )
        {
            ///totalidade
            if (i<fatias)
            {
                h0 = (float)i / (float)fatias;
                h1 = (float)(i+1) / (float)fatias;
                glBegin(GL_LINE_STRIP);
                ///transforma os sementos do cilindro em segmentos de circunferencia
                    for ( j = 0; j <= 30; ++ j )
                    {
                        angulo = PI * (float)j * PI / 180.0f;
                        x = raio * cos(angulo);
                        y = raio * sin(angulo);
                        glVertex3f( x, y, h0 );
                        glVertex3f( x, y, h1 );
                    }
                glEnd();
            }
        }
    glRotatef(180,0,0,1);
    for (i = 0; i < fatias; i++ )
        {
            ///fatias de 4->11
            if (i>3&&i<12)
            {
                h0 = (float)i / (float)fatias;
                h1 = (float)(i+1) / (float)fatias;
                glBegin(GL_LINE_STRIP);
                ///transforma os sementos do cilindro em segmentos de circunferencia
                    for ( j = 0; j <= 30; ++ j )
                    {
                        angulo = PI * (float)j * PI / 180.0f;
                        x = raio * cos(angulo);
                        y = raio * sin(angulo);
                        glVertex3f( x, y, h0 );
                        glVertex3f( x, y, h1 );
                    }
                glEnd();
            }
            else
            {
                h0 = (float)i / (float)fatias;
                h1 = (float)(i+1) / (float)fatias;
                glBegin(GL_LINE_STRIP);
                ///circunferencia total
                    for ( j = 0; j <= 360; ++ j )
                    {
                        angulo = PI * (float)j * PI / 180.0f;
                        x = raio * cos(angulo);
                        y = raio * sin(angulo);
                        glVertex3f( x, y, h0 );
                        glVertex3f( x, y, h1 );
                    }
                glEnd();
            }
    }
    glPopMatrix();
}

static void camera(void){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100,1,0.0001,10);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x, cameray, z,
			x+lx, centromundoy,  z+lz,
			0.0f, 1.0,  0.0f);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
