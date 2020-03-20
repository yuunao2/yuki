#include <stdio.h>
#include <math.h>
#include "./freeglut/include/GL/freeglut.h"
#include <sys/time.h>
#include <sys/resource.h>
#include "object.hpp"
#include "collision.hpp"
#include "character.hpp"
#include "print.hpp"
#ifndef _CLASS_HPP_
#define _CLASS_HPP_
#include "class.hpp"
#endif
int gametimer=0;
int Before_gametimer=0;
int finishtimer=0;
int GLframe = 0; //フレーム数
int GLtimenow = 0;//経過時間
int GLtimebase=0;//計測開始時間
int timerflag=0;

CPlayer player1=CPlayer(-490,-18,0);
CPlayer *Pplayer1=&player1;
CFlag flag1=CFlag();
CFlag *Pflag1=&flag1;


void Keyinput(CPlayer* p,CFlag *f){
    if(f->Get(100)){
        p->Enter(3,-1);
    }
    if(f->Get(102)){
        p->Enter(3,1);
    }
}

void rivive(CPlayer* p){
    if(p->Get(1)<-50){
        p->Enter(0,-540);
        p->Enter(1,-18);
        p->Enter(4,0);
        flag1.Menu(-1);
    }else if(flag1.Menu()<=0){
        p->Enter(0,-540);
        p->Enter(1,-18);
        p->Enter(4,0);
    }
}

void Timer(int a){
    if(flag1.Menu()>0){
    if(flag1.Menu()==2){
        LaunchTimer(Pshot[0],player1);
        LaunchTimer(Pshot[1],player1);
        LaunchTimer(Pshot[2],player1);
        LaunchTimer(Pshot[3],player1);
        LaunchTimer(Pshot[4],player1);
        LaunchTimer(Pshot[5],player1);
        LaunchTimer(Pshot[6],player1);
        LaunchTimer(Pshot[7],player1);
        LaunchTimer(Pshot[8],player1);
        LaunchTimer(Pshot[0],player1);
        glutTimerFunc(900,Timer,0);
    }else if(flag1.Menu()==3){
        LaunchTimer(Pshot[5],player1);
        glutTimerFunc(1000,Timer,0);
    }
    if(flag1.Menu()!=2){
        LaunchTimer(Pshot[0],player1);
        LaunchTimer(Pshot[1],player1);
        LaunchTimer(Pshot[2],player1);
        LaunchTimer(Pshot[3],player1);
        LaunchTimer(Pshot[4],player1);
        LaunchTimer(Pshot[6],player1);
        LaunchTimer(Pshot[7],player1);
        LaunchTimer(Pshot[8],player1);
        LaunchTimer(Pshot[0],player1);
    }
    if(flag1.Menu()!=2&&flag1.Menu()!=3){
        LaunchTimer(Pshot[5],player1);
        glutTimerFunc(3000,Timer,0);

    }
    }else if(timerflag==1){
        timerflag=0;
    }
}

void Launcher(CFlag f){
    if(f.Menu()==1){
        glColor3f(0,0,0.7);
        Launch(Pshot[0],player1,0,-3);
        Launch(Pshot[1],player1,0,0);
        Launch(Pshot[2],player1,0,0);
        Launch(Pshot[3],player1,0,0);
        Launch(Pshot[4],player1,0,0);
        Launch(Pshot[5],player1,0,0);
        Launch(Pshot[6],player1,0,0);
        Launch(Pshot[7],player1,0,0);
        Launch(Pshot[8],player1,0,0);
        Launch(Pshot[9],player1,0,0);
    }else if(f.Menu()==2){
        Launch(Pshot[0],player1,-0.5,-1);
        Launch(Pshot[1],player1,0.5,-1);
        Launch(Pshot[2],player1,0,-2);
        Launch(Pshot[3],player1,0,0);
        Launch(Pshot[4],player1,0,0);
        Launch(Pshot[5],player1,0,0);
        Launch(Pshot[6],player1,0,0);
        Launch(Pshot[7],player1,0,0);
        Launch(Pshot[8],player1,0,0);
        Launch(Pshot[9],player1,0,0);
    }else if(f.Menu()==3){
        Launch(Pshot[0],player1,0,-2);
        Launch(Pshot[1],player1,-1,-0.7);
        Launch(Pshot[2],player1,1,-0.7);
        Launch(Pshot[3],player1,-1,0);
        Launch(Pshot[4],player1,0,-1);
        Launch(Pshot[5],player1,0,-1);
        Launch(Pshot[6],player1,0,-1);
        Launch(Pshot[7],player1,0,0);
        Launch(Pshot[8],player1,0,0);
        Launch(Pshot[9],player1,0,0);
    }else if(f.Menu()==4){
        Launch(Pshot[0],player1,0,-2);
        Launch(Pshot[1],player1,-1,0);
        Launch(Pshot[2],player1,-1,0);
        Launch(Pshot[3],player1,-1,0.7);
        Launch(Pshot[4],player1,-1,0);
        Launch(Pshot[5],player1,-1,0);
        Launch(Pshot[6],player1,-1,0);
        Launch(Pshot[7],player1,-1,0);
        Launch(Pshot[8],player1,-1,0);
        Launch(Pshot[9],player1,-1,0);
    }
}

void display1(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1,1,1,1);
    glPushMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1,1,-1,1,-1,1);
    Stroke_characters(40,300,"ACTION");
    Stroke_characters(70,180,"GAME");
    Bitmap_characters(-0.3,-0.6,"PUSH \"s\" TO START");
    glPopMatrix();
    glutPostRedisplay();

}

void display2(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.7,0.7,1,1);
    Bitmap_characters(0.7,0.8,std::to_string((gametimer-Before_gametimer)/1000));
    finishtimer=gametimer-Before_gametimer;
    Pictures();
    glPushMatrix();
        glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(player1.Get(0)-40,player1.Get(0)+40,-40,40,1,-1);
            glColor3f(0.2,0.2,0.2);           
            object(player1,Pflag1);
            player1.Display();
            if(timerflag==0){
            glutTimerFunc(100,Timer,0);
            timerflag=1;
            }
            Launcher(flag1);
            glPushMatrix();
    glPopMatrix();
    glutPostRedisplay();
}

void display3(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1,1,1,1);
    Stroke_characters(50,300,"GAME\nOVER");        
    Bitmap_characters(-0.36,-0.6,"PUSH \"r\" TO RESTART");
    Bitmap_characters(-0.6,-0.75,"PUSH \"p\" TO BACK TO TOP MENU");
    glutPostRedisplay();
}

void display4(){
    if(flag1.Before()<4){
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1,1,1,1);
        Stroke_characters(40,350,"CLEAR\nLEVEL");
        Stroke_characters(420,200,std::to_string(flag1.Before()));
        Bitmap_characters(-0.4,-0.45,"finished for");
        Bitmap_characters(0.03,-0.45,std::to_string((finishtimer)/1000));
        Bitmap_characters(0.13,-0.45,"seconds");
        Bitmap_characters(-0.36,-0.6,"PUSH \"c\" TO CONTINUE");
        glutPostRedisplay();
    }
    if(flag1.Before()==4){
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1,1,1,1);
        Stroke_characters(50,350,"ALL\nCLEAR");
        Bitmap_characters(-0.4,-0.5,"finished for");
        Bitmap_characters(0.03,-0.5,std::to_string((finishtimer)/1000));
        Bitmap_characters(0.13,-0.5,"seconds");
        Bitmap_characters(-0.36,-0.6,"PUSH \"c\" TO FINISH");

        glutPostRedisplay();
    }
}

void display(){
    GLframe++;
    GLtimenow = glutGet(GLUT_ELAPSED_TIME);
    if (GLtimenow - GLtimebase > 1000){//１秒以上たったらfpsを出力
		//printf("fps:%f\r",GLframe*1000.0/(GLtimenow-GLtimebase));
		GLtimebase = GLtimenow;//基準時間を設定		
		GLframe = 0;//フレーム数をリセット
	}
	printf("fps:%f\r",GLframe*1000.0/(GLtimenow-GLtimebase));
    switch(flag1.Menu()){
        case 0:
            rivive(Pplayer1);
            display1();
            RectangleEnter(flag1);
            break;
        case -1:
            rivive(Pplayer1);
            display3();
            RectangleEnter(flag1);
            break;
        case -2:
            rivive(Pplayer1);
            display4();
            //printf("%d",flag1.Before());
            RectangleEnter(flag1);
            break;
        default:       
            display2();break;
    }
    if(flag1.Menu()<1){
        gametimer=glutGet(GLUT_ELAPSED_TIME);
        Before_gametimer=glutGet(GLUT_ELAPSED_TIME);
        rivive(Pplayer1);
        
    }
}


void idle(){
    if(flag1.Menu()>0){
    player1.Acceleration(gametimer);
    Coll(Pplayer1,rectangle2,Pflag1);
    Coll(Pplayer1,rectangle1,Pflag1);
    Coll(Pplayer1,rectangle3,Pflag1);
    Coll(Pplayer1,rectangle4,Pflag1);
    Coll(Pplayer1,rectangle5,Pflag1);
    Coll(Pplayer1,rectangle6,Pflag1);
    Coll(Pplayer1,rectangle7,Pflag1);
    Coll(Pplayer1,rectangle8,Pflag1);
    Coll(Pplayer1,rectangle9,Pflag1);
    Coll(Pplayer1,rectangle10,Pflag1);
    Coll(Pplayer1,rectangle11,Pflag1);
    Coll(Pplayer1,rectangle12,Pflag1);
    Coll(Pplayer1,rectangle13,Pflag1);
    Coll(Pplayer1,rectangle14,Pflag1);
    Coll(Pplayer1,rectangle15,Pflag1);
    Coll(Pplayer1,rectangle16,Pflag1);
    Coll(Pplayer1,rectangle17,Pflag1);
    Coll(Pplayer1,rectangle18,Pflag1);
    Coll(Pplayer1,rectangle19,Pflag1);
    Coll(Pplayer1,rectangle20,Pflag1);
    Coll(Pplayer1,rectangle21,Pflag1);
    Coll(Pplayer1,rectangle22,Pflag1);
    Coll(Pplayer1,rectangle23,Pflag1);
    Coll(Pplayer1,rectangle24,Pflag1);
    Coll(Pplayer1,rectangle25,Pflag1);
    Coll(Pplayer1,rectangle26,Pflag1);
    Coll(Pplayer1,rectangle27,Pflag1);
    Coll(Pplayer1,rectangle28,Pflag1);
    Coll(Pplayer1,rectangle29,Pflag1);
    Coll(Pplayer1,rectangle30,Pflag1);
    Coll(Pplayer1,rectangle31,Pflag1);
    Coll(Pplayer1,rectangle32,Pflag1);
    Coll(Pplayer1,rectangle33,Pflag1);
    Coll(Pplayer1,rectangle34,Pflag1);
    Coll(Pplayer1,rectangle35,Pflag1);
    Coll(Pplayer1,rectangle36,Pflag1);
    Coll(Pplayer1,rectangle37,Pflag1);
    Coll(Pplayer1,rectangle38,Pflag1);
    Coll(Pplayer1,rectangle39,Pflag1);
    Coll(Pplayer1,rectangle40,Pflag1);
    Coll(Pplayer1,rectangle41,Pflag1);
    Coll(Pplayer1,rectangle42,Pflag1);
    Coll(Pplayer1,rectangle43,Pflag1);
    Coll(Pplayer1,rectangle44,Pflag1);
    Coll(Pplayer1,rectangle45,Pflag1);
    Coll(Pplayer1,rectangle46,Pflag1);
    Coll(Pplayer1,rectangle47,Pflag1);
    Coll(Pplayer1,rectangle48,Pflag1);
    Coll(Pplayer1,rectangle49,Pflag1);
    Coll(Pplayer1,rectangle50,Pflag1);
    Coll(Pplayer1,Pflag1,shot[0],4);
    Coll(Pplayer1,Pflag1,shot[1],4);
    Coll(Pplayer1,Pflag1,shot[2],4);
    Coll(Pplayer1,Pflag1,shot[3],4);
    Coll(Pplayer1,Pflag1,shot[4],4);
    Coll(Pplayer1,Pflag1,shot[5],4);
    Coll(Pplayer1,Pflag1,shot[6],4);
    Coll(Pplayer1,Pflag1,shot[7],4);
    Coll(Pplayer1,Pflag1,shot[8],4);
    Coll(Pplayer1,Pflag1,shot[9],4);
    Keyinput(Pplayer1,Pflag1);
    rivive(Pplayer1);
    }
    glutSwapBuffers();
    gametimer=glutGet(GLUT_ELAPSED_TIME);
}

void special(int key,int x,int y){
    if(flag1.Menu()>0){
        flag1.Up(key);
        player1.Enter(10,player1.Get(3));
        if(flag1.Get(101) && !flag1.Get(0) && player1.Get(4)>-0.2){
        player1.Collision(0);
        player1.timer=glutGet(GLUT_ELAPSED_TIME);
        player1.Enter(4,1.1);
        flag1.Up(0);
        }

    }
}

void specialup(int key,int x,int y){
    flag1.Down(key);
}

void keyboard(unsigned char key,int x,int y){
    switch(flag1.Menu()){
        case 0:
            if(key=='s'){
                flag1.Menu(1);
            }
            break;
        case -1:
            if(key=='r'){
                flag1.Menu(flag1.Before());
                break;
            }else if(key=='p'){
                flag1.Menu(0);
                rivive(Pplayer1);
                flag1.Menu(5);
                break;
            }
        case -2:
            if(key=='c'){
                flag1.Menu(flag1.Before()+1);rivive(Pplayer1);
                break;
            }
        default:
            if(key=='q'){
                player1.Enter(1,10);
                player1.Enter(0,100);
                player1.Enter(4,0);
            }
    }
}

int main(int argc,char *argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(600,600);
    glutCreateWindow("aaa");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutIgnoreKeyRepeat(GL_TRUE);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutSpecialUpFunc(specialup);
    Loadtexture(&info[0],&texture[0],"./grass.png");
    glutMainLoop();
    return 0;
}
