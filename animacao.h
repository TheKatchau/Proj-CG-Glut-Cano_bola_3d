#include "desenhacenas.h"
#include "movecam.h"


void anima(int valor)
{
        cout<<"\n "<<" posicao i: "<<ifirst<<" ";
        cout<<" posicao j: "<<jfirst;
        cout<<"  valor: "<<cena1[ifirst][jfirst]<<"--\n";
        cout<<"\n "<<" posicao i: "<<ifirst-1<<" ";
        cout<<" posicao j-1: "<<jfirst-1;
        cout<<"  valor: "<<cena1[ifirst-1][jfirst]<<"--\n";
        if (cena1[1][7]==70)
        {
            cena1[1][7]=2;
        }
        /**inicia animacao de 3 para 1*/
        if(val==1 && direcao==2)
        {
        //inicio, percorre a primeira linha da matriz e encontra onde se inicia a animacao:
            if(cena1[ifirst][jfirst]==0 && ifirst==0){
                do
                    {
                        jfirst++;
                    }
                while (cena1[ifirst][jfirst]==0 and ifirst==0);
                aux=cena1[ifirst][jfirst];
            }
        }
        ///Inicia movimento 3->1
            if(val==1 && cena1[ifirst][jfirst]==70)
            {
                if(direcao==2){
                    if(ii<10)
                    {
                        tz+=-tamcanoh/10;
                        ii++;
                        glutPostRedisplay();
                        glutTimerFunc(vel,anima,0);
                    }
                    else
                    {
                        ii=0;
                        ifirst++;
                        glutPostRedisplay();
                    }
                }

                if(direcao==8){
                    if(ii<10)
                    {
                            tz+=tamcanoh/10;
                            ii++;
                            glutPostRedisplay();
                            glutTimerFunc(vel,anima,0);
                    }
                }
            }

            if(val==1 && cena1[ifirst][jfirst]==47)
            {
                if(direcao==6)
                {
                    if(ii<10)
                    {
                        tx+=tamcanoh/10;
                        ii++;
                        glutPostRedisplay();
                        glutTimerFunc(vel,anima,0);
                    }
                    else
                    {
                        ii=0;
                        jfirst++;
                        glutPostRedisplay();
                    }
                }
            }

        ///Inicia Animacao de 1 para 2
        if(val==2 && direcao==4)
        {
        //inicio, percorre a primeira linha da matriz e encontra onde se inicia a animacao:
            if(cena1[ifirst][jfirst]==0 && jfirst==15){
                do
                    {
                        ifirst++;
                        cout<<"\n "<<" posicao i: "<<ifirst<<" ";
                        cout<<" posicao j: "<<jfirst;
                        cout<<"  valor: "<<cena1[ifirst][jfirst]<<"--\n";
                    }
                while (cena1[ifirst][jfirst]==0 && jfirst==15);
                aux=cena1[ifirst][jfirst];
            }
        }


        ///inicia/termina movimento 1->2 3->2
        if(val==2)
        {
            if(cena1[ifirst][jfirst]==47 && direcao==4)
                movehorizontal();
            if(cena1[ifirst][jfirst]==48 && direcao==2)
                movevertical();
        }

        ///inicia/termina movimento 2->3 1->3
        if(val==3)
        {
            if(cena1[ifirst][jfirst]==82 && direcao==8)
                movevertical();
            if(cena1[ifirst][jfirst]==80 && direcao==8)
                movevertical();
        }

        ///inicia/termina movimento 2->1 3->1
        if(val==3)
        {
            if(cena1[ifirst][jfirst]==47 && direcao==6)
                movehorizontal();
            if(cena1[ifirst][jfirst]==70 && direcao==2)
                movevertical();
        }

        ///Ao se deparar com uma cruz
        if(cena1[ifirst][jfirst]==5)
            escolhecaminho();
        ///Ao se deparar com uma T
        if(cena1[ifirst][jfirst]==7)
            escolhecaminhot();
        ///caminho eh vertical
        if(cena1[ifirst][jfirst]==2 && ifirst<12)
            movevertical();
        ///caminho eh horizontal
        if(cena1[ifirst][jfirst]==1 && jfirst>0)
            movehorizontal();
        ///Joelho de 90
        if(cena1[ifirst][jfirst]==54)
            glutTimerFunc(vel,movet50ec,0);
        ///Joelho de 30 Esquerda Baixo
        if(cena1[ifirst][jfirst]==34)
            glutTimerFunc(vel,movet30eb,0);
        ///Joelho de 30 Esquerda Cima
        if(cena1[ifirst][jfirst]==31)
            glutTimerFunc(vel,movet30ec,0);
        ///Joelho de 30 Direita Cima
        if(cena1[ifirst][jfirst]==33)
            glutTimerFunc(vel,movet30dc,0);
        ///Joelho de 30 Direita Baixo
        if(cena1[ifirst][jfirst]==32)
            glutTimerFunc(vel,movet30db,0);

        ///1 para 2
        if(cena1[ifirst][jfirst]==47 && val==1 && direcao==4)
        {
            win2 = glutCreateWindow("Cena 2");
            glutDestroyWindow(win1);
            val=2;
            cenarios();
            ifirst=0;
            jfirst=15;
            direcao=4;
            aux=47;
            tx=0;
            ty=0;
            tz=0;
            angulo=185.3;
            lx=0.0f;
            lz=1.0f;
            x=1.5f;
            z=-9.0f;
            cameray=1.5;
            centromundoy=0;
            glutSetWindow(win2);
            glutDisplayFunc(desenhacena2);
            glutReshapeFunc(resize);
            glutKeyboardFunc(key);
            glutSpecialFunc(arrows);
            glutIdleFunc(idle);

            glEnable(GL_DEPTH_TEST);
            glDepthFunc(GL_LEQUAL);
        }
        ///1 para 3
        if(cena1[ifirst][jfirst]==70 && direcao==8 && val==1)
        {
            win3 = glutCreateWindow("Cena 3");
            glutDestroyWindow(win1);
            val=3;
            cenarios();
            ifirst=9;
            jfirst=11;
            direcao=8;
            aux=80;
            tx=0;
            ty=0;
            tz=0;
            angulo=185.4;
            lx=0.0f;
            lz=1.0f;
            x=0.0f;
            z=-1.0f;
            cameray=1.5;
            centromundoy=0;
            glutSetWindow(win3);
            glutDisplayFunc(desenhacena3);
            glutReshapeFunc(resize);
            glutKeyboardFunc(key);
            glutSpecialFunc(arrows);
            glutIdleFunc(idle);
            glEnable(GL_DEPTH_TEST);
            glDepthFunc(GL_LEQUAL);
        }

        ///2 PARA 1
        if(cena1[ifirst][jfirst]==47 && direcao==6 && val==2)
        {
            win1 = glutCreateWindow("Cena 1");
            glutDestroyWindow(win2);
            val=1;
            cenarios();
            ifirst=7;
            jfirst=0;
            direcao=6;
            tx=0;
            ty=0;
            tz=0;
            angulo=179.1;
            lx=0.0f;
            lz=1.0f;
            x=-8.0f;
            z=-9.0f;
            cameray=1.5;
            centromundoy=0;
            aux=47;
            glutSetWindow(win1);
            glutDisplayFunc(desenhacena1);
            glutReshapeFunc(resize);
            glutKeyboardFunc(key);
            glutSpecialFunc(arrows);
            glutIdleFunc(idle);

            glEnable(GL_DEPTH_TEST);
            glDepthFunc(GL_LEQUAL);
        }
        ///2 para 3
        if(cena1[ifirst][jfirst]==48 && val==2 && direcao==8)
        {
            win3 = glutCreateWindow("Cena 3");
            glutDestroyWindow(win2);
            val=3;
            cenarios();
            ifirst=9;
            jfirst=5;
            direcao=8;
            aux=82;
            tx=0;
            ty=0;
            tz=0;
            angulo=185.4;
            lx=0.0f;
            lz=1.0f;
            x=-7.0f;
            z=-1.0f;
            cameray=1.5;
            centromundoy=0;
            glutSetWindow(win3);
            glutDisplayFunc(desenhacena3);
            glutReshapeFunc(resize);
            glutKeyboardFunc(key);
            glutSpecialFunc(arrows);
            glutIdleFunc(idle);

            glEnable(GL_DEPTH_TEST);
            glDepthFunc(GL_LEQUAL);
        }
        ///3 para 1
        if((cena1[ifirst][jfirst]==80 && direcao==2) && val==3)
        {
            win1 = glutCreateWindow("Cena 1");
            glutDestroyWindow(win3);
            val=1;
            cenarios();
            ifirst=0;
            jfirst=7;
            direcao=2;
            tx=0;
            ty=0;
            tz=0;
            angulo=0.0;
            lx=0.0f;
            lz=-1.0f;
            x=0.0f;
            z=1.0f;
            cameray=1.5;
            centromundoy=0;
            aux=70;
            glutSetWindow(win1);
            glutDisplayFunc(desenhacena1);
            glutReshapeFunc(resize);
            glutKeyboardFunc(key);
            glutSpecialFunc(arrows);
            glutIdleFunc(idle);

            glEnable(GL_DEPTH_TEST);
            glDepthFunc(GL_LEQUAL);
        }

        ///3 para 2
        if(cena1[ifirst][jfirst]==82 && val==3 && direcao==2)
           {
                win2 = glutCreateWindow("Cena 2");
                glutDestroyWindow(win3);
                val=2;
                cenarios();
                ifirst=0;
                jfirst=13;
                direcao=2;
                aux=48;
                tx=0;
                ty=0;
                tz=0;
                angulo=0.0;
                lx=0.0f;
                lz=-1.0f;
                x=0.0f;
                z=1.0f;
                cameray=1.5;
                centromundoy=0;
                glutSetWindow(win2);
                glutDisplayFunc(desenhacena2);
                glutReshapeFunc(resize);
                glutKeyboardFunc(key);
                glutSpecialFunc(arrows);
                glutIdleFunc(idle);


                glEnable(GL_DEPTH_TEST);
                glDepthFunc(GL_LEQUAL);
           }

}

void escolhecaminho()
{
        srand(time(NULL));
        int number;
        number = rand() % 4+1;
        //number=2;
        if(number==4)
        {
            direcao=8;
            aux=cena1[ifirst][jfirst];
            cena1[ifirst][jfirst]=2;
        }
        if(number==3)
        {
            direcao=6;
            aux=cena1[ifirst][jfirst];
            cena1[ifirst][jfirst]=1;
        }
        if(number==2)
        {
            direcao=4;
            aux=cena1[ifirst][jfirst];
            cena1[ifirst][jfirst]=1;
        }
        if(number==1)
        {
            direcao=2;
            aux=cena1[ifirst][jfirst];
            cena1[ifirst][jfirst]=2;
        }


        cout<<"/**********************************/\n"<<number<<"\n/**********************************/\n";
        cout<<"/**********************************/\n"<<direcao<<"\n/**********************************/\n";
}

void movevertical()
{
    if(val==1)
    {
        if(ifirst==0)
                {
                    ///define o ponto de saida para o mapa 3 após o inicio da animação
                    if(cena1[ifirst][jfirst]!=70)
                        {
                             if(ii<10)
                                {
                                    tz+=-tamcanoh/10;
                                    ii++;
                                    glutPostRedisplay();
                                    glutTimerFunc(vel,anima,1);
                                }
                                else{
                                    ii=0;
                                    cena1[ifirst][jfirst]=70;
                                    glutPostRedisplay();
                                    glutTimerFunc(vel,anima,1);
                                    }
                        }
                }
    }
        if (val==1)
        {
            if(direcao==2 && ifirst>0)
            {
                if(ii<10)
                {
                    tz+=-tamcanoh/10;
                    ii++;
                    glutPostRedisplay();
                    glutTimerFunc(vel,anima,1);
                }
                else
                {
                        cena1[ifirst][jfirst]=aux;
                        ifirst++;
                        aux=cena1[ifirst][jfirst];
                        ii=0;
                        glutPostRedisplay();
                        glutTimerFunc(vel,anima,1);
                }

            }
            if(direcao==8 && ifirst<12)
            {
                if(ii<10)
                {
                    tz+=tamcanoh/10;
                    ii++;
                    glutPostRedisplay();
                    glutTimerFunc(vel,anima,1);
                }
                else
                {
                    cena1[ifirst][jfirst]=aux;
                    ifirst--;
                    aux=cena1[ifirst][jfirst];
                    ii=0;
                    glutPostRedisplay();
                    glutTimerFunc(vel,anima,1);
                }
            }
        }
        else
        {
         if(direcao==2 && ifirst>=0)
            {
                if(ii<10)
                {
                    tz+=-tamcanoh/10;
                    ii++;
                    glutPostRedisplay();
                    glutTimerFunc(vel,anima,1);
                }
                else
                {
                        cena1[ifirst][jfirst]=aux;
                        ifirst++;
                        aux=cena1[ifirst][jfirst];
                        ii=0;
                        glutPostRedisplay();
                        glutTimerFunc(vel,anima,1);
                }

            }
            if(direcao==8 && ifirst<12)
            {
                if(ii<10)
                {
                    tz+=tamcanoh/10;
                    ii++;
                    glutPostRedisplay();
                    glutTimerFunc(vel,anima,1);
                }
                else
                {
                    cena1[ifirst][jfirst]=aux;
                    ifirst--;
                    aux=cena1[ifirst][jfirst];
                    ii=0;
                    glutPostRedisplay();
                    glutTimerFunc(vel,anima,1);
                }
            }
        }

}

void movehorizontal()
{
            if(direcao==4 && jfirst>0)
            {
                if(ii<10)
                {
                    tx+=-tamcanoh/10;
                    ii++;
                    glutPostRedisplay();
                    glutTimerFunc(vel,anima,val);
                }
                else
                {
                    ///impede que a função trave no momento de escolha
                        if (aux!=47)
                        {
                            cena1[ifirst][jfirst]=aux;
                        }
                        jfirst--;
                        aux=cena1[ifirst][jfirst];
                        ii=0;
                        glutPostRedisplay();
                        glutTimerFunc(vel,anima,val);
                }
            }
            if(direcao==6 && jfirst<15)
            {
                 if(ii<10)
                {
                    tx+=tamcanoh/10;
                    ii++;
                    glutPostRedisplay();
                    glutTimerFunc(vel,anima,1);
                }
                else
                {
                    if (aux!=47)
                        {
                            cena1[ifirst][jfirst]=aux;
                        }
                        jfirst++;
                        aux=cena1[ifirst][jfirst];
                        ii=0;
                        glutPostRedisplay();
                        glutTimerFunc(vel,anima,1);
                }
            }
}

void movet50ec(int valor)
{
    if(cena1[ifirst][jfirst]==54)
    {
        if(cena1[ifirst+1][jfirst]==54)
        {
            if(ii<10)
            {
                tz-=tamcanoh/10;
                ii++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet50ec,1);
            }
            if(auxii<2)
            {
                tx-=tamcanoh/10;
                auxii++;
            }
            if(auxii==2&&ii==10&&auxjj<12)
            {
                tx+=tamcanoh/10;
                auxjj++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet50ec,1);
            }
            if(auxii==2&&ii==10&&auxjj==12)
            {
                cena1[ifirst][jfirst]=aux;
                ifirst=ifirst+1;
                jfirst=jfirst+1;
                aux=cena1[ifirst][jfirst];
                auxii=0;
                auxjj=0;
                ii=0;
                direcao=6;
                anima(0);
            }
        }
    if(cena1[ifirst-1][jfirst]==54)
        {
            if(ii<10)
            {
                tz+=tamcanoh/10;
                ii++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet50ec,1);
            }
            if(auxii<1)
            {
                tx-=tamcanoh/10;
                auxii++;
                //glutTimerFunc(vel,movet50ec,30);
            }
            if(auxii==1 && ii==10 && auxjj<11)
            {
                tx+=tamcanoh/10;
                auxjj++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet50ec,1);
            }
            if(auxii==1 && ii==10 && auxjj==11)
            {
                cena1[ifirst][jfirst]=aux;
                jfirst=jfirst+1;
                ifirst=ifirst-1;
                aux=cena1[ifirst][jfirst];
                auxii=0;
                auxjj=0;
                ii=0;
                direcao=6;
                anima(1);
            }
        }
    }
}

void movet30eb(int valor)
{
    if(direcao==6 && cena1[ifirst][jfirst]==34){
        {if(cena1[ifirst+1][jfirst]==2 || cena1[ifirst+1][jfirst]==5 || cena1[ifirst+1][jfirst]==32|| cena1[ifirst+1][jfirst]==7)
        {
            if(auxii<3&&direcao!=2)
            {
                tx+=tamcanoh/10;
                auxii++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet30eb,3);
            }

            if(auxii==3 && ii<1 && direcao!=2)
            {
                tx+=tamcanoh/5;
                tz+=-tamcanoh/10;
                ii++;
                glutPostRedisplay();
            }
             if(auxii==3 && ii==1 && auxjj<5 && direcao!=2)
            {
                tz+=-tamcanoh/10;
                auxjj++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet30eb,3);
            }

            }
            if(auxii==3 && ii==1 && auxjj==5 &&direcao!=2)
            {
                cena1[ifirst][jfirst]=aux;
                ifirst=ifirst+1;
                aux=cena1[ifirst][jfirst];
                direcao=2;
                auxii=0;
                auxjj=0;
                ii=0;
                anima(1);
            }
        }
    }
     if(direcao==8 && cena1[ifirst][jfirst]==34){
        if(cena1[ifirst][jfirst-1]==1||cena1[ifirst][jfirst-1]==5||cena1[ifirst][jfirst-1]==7)
        {
            if(auxii<2 && direcao!=4)
            {
                tz+=tamcanoh/10;
                auxii++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet30eb,3);
            }
            if(auxii==2 && ii<2 &&direcao!=4)
            {
                tx+=-tamcanoh/10;
                tz+=tamcanoh/10;
                ii++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet30eb,3);
            }
            if(auxii==2 && ii==2 && auxjj<13 && direcao!=4)
            {
                tx+=-tamcanoh/10;
                auxjj++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet30eb,3);
            }

        }
        if(auxii==2 && ii==2 && auxjj==13 &&direcao!=4)
        {
            cena1[ifirst][jfirst]=aux;
            jfirst=jfirst-1;
            aux=cena1[ifirst][jfirst];
            direcao=4;
            auxii=0;
            auxjj=0;
            ii=0;
            anima(1);
        }
    }
}

void movet30ec(int valor)
{
    if(direcao==2 && cena1[ifirst][jfirst]==31){
        if(cena1[ifirst][jfirst-1]==1||cena1[ifirst][jfirst-1]==5||cena1[ifirst][jfirst-1]==32 ||cena1[ifirst][jfirst-1]==7)
        {
            if(auxii<2&&direcao!=4)
            {
                tz+=-tamcanoh/10;
                auxii++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet30ec,3);
            }

            if(auxii==2 && ii<2 &&direcao!=4)
            {
                tx+=-tamcanoh/10;
                tz+=-tamcanoh/10;
                ii++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet30ec,3);
            }
            if(auxii==2 && ii==2 && auxjj<13 &&direcao!=4)
            {
                tx+=-tamcanoh/10;
                auxjj++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet30ec,3);
            }
            if(auxii==2 && ii==2 && auxjj==13 &&direcao!=4)
            {
                cena1[ifirst][jfirst]=aux;
                jfirst=jfirst-1;
                aux=cena1[ifirst][jfirst];
                direcao=4;
                auxii=0;
                auxjj=0;
                ii=0;
                anima(1);
            }
        }

    }
    if(direcao==6 && cena1[ifirst][jfirst]==31){
        if(cena1[ifirst-1][jfirst]==2||cena1[ifirst-1][jfirst]==5||cena1[ifirst-1][jfirst]==7)
        {
            if(auxii<3&&direcao!=8)
            {
                tx+=tamcanoh/10;
                auxii++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet30ec,3);
            }

            if(auxii==3 && ii<1 &&direcao!=8)
            {
                tx+=tamcanoh/5;
                tz+=tamcanoh/10;
                ii++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet30ec,3);
            }
            if(auxii==3 && ii==1 && auxjj<5 &&direcao!=8)
            {
                tz+=tamcanoh/10;
                auxjj++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet30ec,3);
            }

        }
        if(auxii==3 && ii==1 && auxjj==5 &&direcao!=8)
        {
            cena1[ifirst][jfirst]=aux;
            ifirst=ifirst-1;
            aux=cena1[ifirst][jfirst];
            direcao=8;
            auxii=0;
            auxjj=0;
            ii=0;
            anima(1);
        }
    }
}

void movet30db(int valor)
{
    if(direcao==4 && cena1[ifirst][jfirst]==32){
        {if(cena1[ifirst+1][jfirst]==2 || cena1[ifirst+1][jfirst]==5 || cena1[ifirst+1][jfirst]==7)
        {
            if(auxii<3&&direcao!=2)
            {
                tx+=-tamcanoh/10;
                auxii++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet30db,3);
            }

            if(auxii==3 && ii<1 && direcao!=2)
            {
                tx+=-tamcanoh/5;
                tz+=-tamcanoh/10;
                ii++;
                glutPostRedisplay();
            }
             if(auxii==3 && ii==1 && auxjj<5 && direcao!=2)
            {
                tz+=-tamcanoh/10;
                auxjj++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet30db,3);
            }

            }
            if(auxii==3 && ii==1 && auxjj==5 &&direcao!=2)
            {
                cena1[ifirst][jfirst]=aux;
                ifirst=ifirst+1;
                aux=cena1[ifirst][jfirst];
                direcao=2;
                auxii=0;
                auxjj=0;
                ii=0;
                anima(1);
            }
        }
    }
     if(direcao==8 && cena1[ifirst][jfirst]==32){
        if(cena1[ifirst][jfirst+1]==1||cena1[ifirst][jfirst+1]==5||cena1[ifirst][jfirst+1]==34||cena1[ifirst][jfirst+1]==7)
        {
            if(auxii<2 && direcao!=6)
            {
                tz+=tamcanoh/10;
                auxii++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet30db,3);
            }
            if(auxii==2 && ii<2 &&direcao!=6)
            {
                tx+=tamcanoh/10;
                tz+=tamcanoh/10;
                ii++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet30db,3);
            }
            if(auxii==2 && ii==2 && auxjj<13 && direcao!=6)
            {
                tx+=tamcanoh/10;
                auxjj++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet30db,3);
            }

        }
        if(auxii==2 && ii==2 && auxjj==13 &&direcao!=6)
        {
            cena1[ifirst][jfirst]=aux;
            jfirst=jfirst+1;
            aux=cena1[ifirst][jfirst];
            direcao=6;
            auxii=0;
            auxjj=0;
            ii=0;
            anima(1);
        }
    }
}

void movet30dc(int valor)
{
    if(direcao==2 && cena1[ifirst][jfirst]==33)
        {
        if(cena1[ifirst][jfirst+1]==1||cena1[ifirst][jfirst+1]==5||cena1[ifirst][jfirst+1]==7)
        {
            if(auxii<2&&direcao!=6)
            {
                tz+=-tamcanoh/10;
                auxii++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet30dc,3);
            }

            if(auxii==2 && ii<2 &&direcao!=6)
            {
                tx+=tamcanoh/10;
                tz+=-tamcanoh/10;
                ii++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet30dc,3);
            }
            if(auxii==2 && ii==2 && auxjj<13 &&direcao!=6)
            {
                tx+=tamcanoh/10;
                auxjj++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet30dc,3);
            }
            if(auxii==2 && ii==2 && auxjj==13 &&direcao!=6)
            {
                cena1[ifirst][jfirst]=aux;
                jfirst=jfirst+1;
                aux=cena1[ifirst][jfirst];
                direcao=6;
                auxii=0;
                auxjj=0;
                ii=0;
                anima(1);
            }
        }
    }
    if(direcao==4 && cena1[ifirst][jfirst]==33){
        if(cena1[ifirst-1][jfirst]==2||cena1[ifirst-1][jfirst]==5||cena1[ifirst-1][jfirst]==32||cena1[ifirst-1][jfirst]==7)
        {
            if(auxii<3&&direcao!=8)
            {
                tx+=-tamcanoh/10;
                auxii++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet30dc,3);
            }

            if(auxii==3 && ii<1 &&direcao!=8)
            {
                tx+=-tamcanoh/5;
                tz+=tamcanoh/10;
                ii++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet30dc,3);
            }
            if(auxii==3 && ii==1 && auxjj<5 &&direcao!=8)
            {
                tz+=tamcanoh/10;
                auxjj++;
                glutPostRedisplay();
                glutTimerFunc(vel,movet30dc,3);
            }

        }
        if(auxii==3 && ii==1 && auxjj==5 && direcao!=8)
        {
            cena1[ifirst][jfirst]=aux;
            ifirst=ifirst-1;
            aux=cena1[ifirst][jfirst];
            direcao=8;
            auxii=0;
            auxjj=0;
            ii=0;
            anima(1);
        }
    }

}

void escolhecaminhot(){
    int help;
    if(cena1[ifirst][jfirst+1]==0)
    {
        help=3;
    }
    if(cena1[ifirst][jfirst-1]==0)
    {
        help=2;
    }
    if(cena1[ifirst+1][jfirst]==0)
    {
        help=1;
    }
    if(cena1[ifirst-1][jfirst]==0)
    {
        help=4;
    }
     srand(time(NULL));
        int number = rand() % 4+1;
        if (number==help)
        {
            if (number==4)
                number--;
            else
                number++;
        }

        if(number==4)
        {
                direcao=8;
                aux=cena1[ifirst][jfirst];
                cena1[ifirst][jfirst]=2;
        }

        if(number==3)
        {
                direcao=6;
                aux=cena1[ifirst][jfirst];
                cena1[ifirst][jfirst]=1;
    }
        if(number==2)
        {
                direcao=4;
                aux=cena1[ifirst][jfirst];
                cena1[ifirst][jfirst]=1;

        }
        if(number==1)
        {
                direcao=2;
                aux=cena1[ifirst][jfirst];
                cena1[ifirst][jfirst]=2;
        }
        cout<<"/**********************************/\n"<<number<<"\n/**********************************/\n";
        cout<<"/**********************************/\n"<<direcao<<"\n/**********************************/\n";
}

