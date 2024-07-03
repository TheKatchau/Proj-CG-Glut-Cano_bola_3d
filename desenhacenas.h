#include "primitivas.h"
void desenhacena1()
{
    if(cena1[ifirst][jfirst]==70)
            caminho=1;
    if(cena1[ifirst][jfirst]==47)
            caminho=2;
        glClearColor(0,1,1,1);
        camera();
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        if(caminho==1)
        {
            glTranslatef(0,0,0.5);
            esfera();
        }
        if(caminho==2)
        {
            glTranslatef(-9,0,-7.5);
            esfera();
        }



        glPopMatrix();
        glPushMatrix();
                glTranslatef(-9,0,-7.5);
                glRotatef(90,0,1,0);
                cano(0.3,0.5);
        glPopMatrix();
        glPushMatrix();
                glTranslatef(0,0,0);
                cano(0.3,0.5);
        glPopMatrix();
        glRotatef(180,1,0,0);
        ///inicio
        cano(0.3, 1);
        glTranslatef(0,0,1);
        cano(0.3, 1);
        glTranslatef(0,0,1);
        ///T1
        T(0.3, 1);
        glPushMatrix();
        ///Lado esquerdo
            glTranslatef(-1.5,0,0);
            glPushMatrix();
            ///primeiro cano
                glRotatef(90,0,1,0);
                cano(0.3, 1);
            glPopMatrix();
            ///segundo cano
            glTranslatef(-1,0,0);
            glRotatef(90,0,1,0);
            cano(0.3, 1);
        glPopMatrix();
        ///curva de 180
        glPushMatrix();
            glTranslatef(-2.5,0,0);
            glTranslatef(0,0,0.5);
            glRotatef(90,1,0,0);
            glRotatef(90,0,0,1);
            curva180(20,20);
        glPopMatrix();
        ///canos ligados ah cruz pela esquerda
        glPushMatrix();
            glTranslatef(-1.5,0,0);
            glTranslatef(0,0,1);
            glPushMatrix();
            ///cano 1
                glRotatef(90,0,1,0);
                cano(0.3, 1);
            glPopMatrix();
            ///cano 2
            glTranslatef(-1,0,0);
            glRotatef(90,0,1,0);
            cano(0.3, 1);
        glPopMatrix();
        glTranslatef(0,0,0.5);
        ///cruz
        Cruz(0.3, 1);
        glPushMatrix();
            glTranslatef(0,0,0.5);
            cano(0.3, 1);
            glTranslatef(0,0,1);
            cano(0.3, 1);
            glTranslatef(0,0,1);
            cano(0.3, 1);
            glTranslatef(0,0,1);
            cano(0.3, 1);
            glTranslatef(0,0,1);
            cano(0.3, 1);
        glPopMatrix();
        ///direita da cruz
        glPushMatrix();
            glTranslatef(1,0,0.5);
            /// curva de 90 -> 34
            glPushMatrix();
                glRotatef(270,1,0,0);
                curva90(20,20);
            glPopMatrix();
            glTranslatef(0.5,0,0);
            cano(0.3,1);
            glTranslatef(0,0,1);
            cano(0.3,1);
            glTranslatef(0,0,1);
            cano(0.3,1);
            glTranslatef(0,0,1);
            cano(0.3,1);
            glTranslatef(0,0,1);
            cano(0.3,1);
            ///curva de 90->31
            glPushMatrix();
                glTranslatef(-0.5,0,1);
                glPushMatrix();
                    glRotatef(90,1,0,0);
                    curva90(20,20);
                glPopMatrix();
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-1,0,1.5);
                glRotatef(270,0,1,0);
                ///T inferior
                T(0.3, 1);
                glTranslatef(0,0,0.5);
                glPushMatrix();
                    glRotatef(90,0,0,1);
                    cano(0.3,1);
                    glTranslatef(0,0,1);
                    cano(0.3,1);
                    /// curva de 90 -> 33
                    glTranslatef(0,0.5,1.5);
                    glRotatef(270,0,1,0);
                    glRotatef(180,1,0,0);
                    curva90(20,20);
                glPopMatrix();
                glPopMatrix();
            glTranslatef(-5,0,0);
            cano(0.3,1);
            glTranslatef(0,0,-1);
            cano(0.3,1);
            glTranslatef(0,0,-1);
            cano(0.3,1);
            glPushMatrix();
            /// curva 90 ->34
                glTranslatef(-0.5,0,0);
                glRotatef(270,1,0,0);
                curva90(20,20);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-2,0,-0.5);
                glPushMatrix();
                    glRotatef(90,0,1,0);
                    cano(0.3,1);
                glPopMatrix();
                glTranslatef(-0.5,0,0.5);
                /// curva de 90 -> 32
                glPushMatrix();
                    glRotatef(270,1,0,0);
                    glRotatef(180,0,1,0);
                    curva90(20,20);
                glPopMatrix();
                glTranslatef(-0.5,0,0);
                cano(0.3,1);
                glPushMatrix();
                glTranslatef(-0.5,0,1);
                glPushMatrix();
                    glRotatef(90,1,0,0);
                    curva90(20,20);
                    glRotatef(270,1,0,0);
                    glRotatef(90,0,1,0);
                    glTranslatef(-0.5,0,-1.5);
                    cano(0.3,1);
                glPopMatrix();
            glPopMatrix();
            glPopMatrix();
        glPopMatrix();
        glutSwapBuffers();
}

void desenhacena2(){
    glClearColor(1,0.5,0,1);
    camera();
    glMatrixMode(GL_MODELVIEW);

    if(cena1[ifirst][jfirst] == 48)
        caminho=2;

    if(cena1[ifirst][jfirst] == 47)
        caminho=1;
    ///se vem do 3
    if(caminho == 2)
    {
        glPushMatrix();
            glTranslatef(0,0,1.9);
            esfera();
        glPopMatrix();
    }
    ///se vem do 1
    if(caminho == 1)
    {
        glPushMatrix();
            glTranslatef(1.5,0,-6.5);
            esfera();
        glPopMatrix();
    }
    glPushMatrix();
        glTranslatef(1,0,-6.5);
        glRotatef(90,0,1,0);
        cano(0.3,0.5);
    glPopMatrix();

    cano(0.3, 1);
    glTranslatef(0,0,-1);
    cano(0.3, 1);
    glTranslatef(0,0,-1);
    cano(0.3, 1);
    glTranslatef(0,0,-1);
    cano(0.3, 1);
    ///curva de 90 ->31
    glPushMatrix();
        glTranslatef(-0.5,0,0);
        glPushMatrix();
            glRotatef(270,1,0,0);
            glRotatef(0,0,0,1);
            curva90(20,20);
        glPopMatrix();
        /// canos horizontais
        glTranslatef(-0.5,0,-0.5);
        glPushMatrix();
            glTranslatef(-1,0,0);
            glRotatef(90,0,1,0);
            cano(0.3,1);
            glTranslatef(0,0,-1);
            cano(0.3,1);
            glTranslatef(0,0,-1);
            cano(0.3,1);
        glPopMatrix();
        ///curva de 90 -> 32
        glTranslatef(-3,0,0);
        glPushMatrix();
            glTranslatef(-0.5,0,-0.5);
            glRotatef(270,1,0,0);
            glRotatef(180,0,0,1);
            curva90(20,20);
        glPopMatrix();
        glTranslatef(-1,0,-1.5);
        cano(0.3,1);
        glTranslatef(0,0,-1);
        cano(0.3,1);
        ///curva de 90 -> 33
        glPushMatrix();
            glTranslatef(0.5,0,0);
            glRotatef(90,1,0,0);
            glRotatef(180,0,0,1);
            curva90(20,20);
        glPopMatrix();
        glTranslatef(0,0,-0.5);
        ///canos verticais
        glPushMatrix();
            glTranslatef(1,0,0);
            glRotatef(90,0,1,0);
            cano(0.3,1);
            glTranslatef(0,0,1);
            cano(0.3,1);
            glTranslatef(0,0,1);
            cano(0.3,1);
            glTranslatef(0,0,1);
            cano(0.3,1);
            glTranslatef(0,0,1);
            cano(0.3,1);
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void desenhacena3(){
    glClearColor(0.2,0.5,1,1);
    camera();
    glMatrixMode(GL_MODELVIEW);
    ///A entrada veio da tela 1
    if (cena1[ifirst][jfirst]==80)
        caminho=1;
    ///A entrada veio da tela 2
    if (cena1[ifirst][jfirst]==82)
        caminho=2;


    ///inicia a BOLINHA na coordena referente
    if (caminho ==1)
    {
        glPushMatrix();
        glTranslatef(0,0,-0.5);
        esfera();
        cano(0.3,0.5);
        glPopMatrix();
    }
    glPushMatrix();
        glTranslatef(0,0,-0.5);
        cano(0.3,0.5);
    glPopMatrix();
    ///inicia a BOLINHA na coordena referente
    if (caminho==2)
    {
        glPushMatrix();
            glTranslatef(-6,0,-0.5);
            cano(0.3,0.5);
            esfera();
        glPopMatrix();
    }
    glPushMatrix();
        glTranslatef(0,0,-0.5);
        cano(0.3,0.5);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-6,0,-0.5);
        cano(0.3,0.5);
    glPopMatrix();
    ///canos verticais vindos da cena 1
    cano(0.3, 1);
    glTranslatef(0,0,1);
    cano(0.3, 1);
    glTranslatef(0,0,1);
    ///cruz
    Cruz(0.3, 1);
    glTranslatef(0,0,0.5);
    ///cano vertical
    cano(0.3, 1);
    glTranslatef(0,0,1);
    cano(0.3, 1);
    glTranslatef(0,0,1);
    glTranslatef(0.5,0,0.5);
    ///primeiro T
    glPushMatrix();
        glRotatef(270,0,1,0);
        T(0.3, 1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.5,0,-0.5);
        ///curva de 90 -> 32
        glPushMatrix();
            glRotatef(90,1,0,0);
            curva90(20,20);
        glPopMatrix();
        /// canos verticais
        glTranslatef(0.5,0,-2);
        cano(0.3, 1);
        glTranslatef(0,0,1);
        cano(0.3, 1);
        glTranslatef(-0.5,0,-1);
        ///curva de 90 -> 33
        glPushMatrix();
            glRotatef(270,1,0,0);
            curva90(20,20);
        glPopMatrix();
    glPopMatrix();
    glTranslatef(-1,0,0);
    ///canos horizontais
    glTranslatef(-1,0,0);
    glPushMatrix();
        glRotatef(90,0,1,0);
        cano(0.3,1);
        glTranslatef(0,0,-1);
        cano(0.3,1);
    glPopMatrix();
    glTranslatef(-1,0,0);
    ///segundo T
    glPushMatrix();
        glRotatef(270,0,1,0);
        T(0.3, 1);
    glPopMatrix();
    ///canos verticais meio
    glPushMatrix();
        glTranslatef(-0.5,0,-2.5);
        cano(0.3,1);
        glTranslatef(0,0,1);
        cano(0.3,1);
        glTranslatef(-0.5,0,-1.5);
        ///T baixo meio
        glPushMatrix();
            glRotatef(90,0,1,0);
            T(0.3, 1);
        glPopMatrix();
        /// canos horizontais lado negativo
        glPushMatrix();
            glTranslatef(-1,0,0);
            glRotatef(90,0,1,0);
            cano(0.3,1);
            glTranslatef(0,0,-1);
            cano(0.3,1);
            glTranslatef(0,0,-1);
            Cruz(0.3, 1);
            glRotatef(270,0,1,0);
            glTranslatef(0,0,-1.5);
            cano(0.3,1);
            glTranslatef(0,0,-1);
            cano(0.3,1);
        glPopMatrix();
        /// canos horizontais lado positivo
        glPushMatrix();
            glTranslatef(1,0,0);
            glRotatef(90,0,1,0);
            cano(0.3,1);
            glTranslatef(0,0,1);
            cano(0.3,1);
        glPopMatrix();
     glPopMatrix();
    ///canos horizontais
    glTranslatef(-2,0,0);
    glPushMatrix();
        glRotatef(90,0,1,0);
        cano(0.3,1);
        glTranslatef(0,0,-1);
        cano(0.3,1);
    glPopMatrix();
    glTranslatef(-1,0,0);

    glPushMatrix();
    ///Cano vertical fim
        glPushMatrix();
            glTranslatef(-0.5,0,-1.5);
            cano(0.3,1);
            glTranslatef(0,0,-1);
            cano(0.3,1);
        glPopMatrix();
        ///terceiro T
        glPushMatrix();
            glRotatef(270,0,1,0);
            T(0.3, 1);
        glPopMatrix();
        ///curva de 90 ->34
        glTranslatef(-1.5,0,-0.5);
        glPushMatrix();
            glRotatef(270,1,0,0);
            glRotatef(180,0,0,1);
            curva90(20,20);
        glPopMatrix();
        ///cano vertical curva
        glTranslatef(-0.5,0,-2);
        cano(0.3, 1);
        glTranslatef(0,0,1);
        cano(0.3, 1);
        ///curva 90 ->31
        glTranslatef(0.5,0,-1);
        glPushMatrix();
            glRotatef(90,1,0,0);
            glRotatef(180,0,0,1);
            curva90(20,20);
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}

