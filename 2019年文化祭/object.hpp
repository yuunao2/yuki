#ifndef _OBJEcT_HPP_
#define _OBJEcT_HPP_
#ifndef _CLASS_HPP_
#define _CLASS_HPP_
#include "class.hpp"
#endif
#define PI 3.14159

#include "rectangle.hpp"


coordinates shot[10][10];
Pcoordinates Pshot[10][10];


extern coordinates shot[10][10];



//長方形
void plate(CRec p){
    if(1){
        glPushMatrix();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        if(p.Get(6)!=0){
            glTranslatef(p.Center(0),p.Center(1),p.Center(2));
            glRotatef((p.Get(6)*180)/PI,p.Get(7),p.Get(8),p.Get(9));
            glTranslatef(-1*p.Center(0),-1*p.Center(1),-1*p.Center(2));
        }
        
        glBegin(GL_QUADS);
        glVertex3d(p.Get(0),p.Get(1),p.Get(2));
        glVertex3d(p.Get(0)+p.Get(3),p.Get(1),p.Get(2));
        glVertex3d(p.Get(0)+p.Get(3),p.Get(1)+p.Get(4),p.Get(2));
        glVertex3d(p.Get(0),p.Get(1)+p.Get(4),p.Get(2));
        glEnd();
        glBegin(GL_QUADS);
        glVertex3d(p.Get(0),p.Get(1),p.Get(2)+p.Get(5));
        glVertex3d(p.Get(0)+p.Get(3),p.Get(1),p.Get(2)+p.Get(5));
        glVertex3d(p.Get(0)+p.Get(3),p.Get(1)+p.Get(4),p.Get(2)+p.Get(5));
        glVertex3d(p.Get(0),p.Get(1)+p.Get(4),p.Get(2)+p.Get(5));
        glEnd();
        glBegin(GL_QUADS);
        glVertex3d(p.Get(0),p.Get(1),p.Get(2));
        glVertex3d(p.Get(0),p.Get(1),p.Get(2)+p.Get(5));
        glVertex3d(p.Get(0),p.Get(1)+p.Get(4),p.Get(2)+p.Get(5));
        glVertex3d(p.Get(0),p.Get(1)+p.Get(4),p.Get(2));
        glEnd();
        glBegin(GL_QUADS);
        glVertex3d(p.Get(0)+p.Get(3),p.Get(1),p.Get(2));
        glVertex3d(p.Get(0)+p.Get(3),p.Get(1),p.Get(2)+p.Get(5));
        glVertex3d(p.Get(0)+p.Get(3),p.Get(1)+p.Get(4),p.Get(2)+p.Get(5));
        glVertex3d(p.Get(0)+p.Get(3),p.Get(1)+p.Get(4),p.Get(2));
        glEnd();
        glPopMatrix();
    }
}

void gunbase(coordinates p[]){
    double aaa=2.5;
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
        glBegin(GL_QUADS);
        glVertex3d(p[0].before_x-aaa,p[0].before_y-aaa,0);
        glVertex3d(p[0].before_x+aaa,p[0].before_y-aaa,0);
        glVertex3d(p[0].before_x+aaa,p[0].before_y+aaa,0);
        glVertex3d(p[0].before_x-aaa,p[0].before_y+aaa,0);
        glEnd();
        glBegin(GL_QUADS);
        glVertex3d(p[0].before_x-aaa,p[0].before_y-aaa,0);
        glVertex3d(p[0].before_x+aaa,p[0].before_y-aaa,0);
        glVertex3d(p[0].before_x+aaa,p[0].before_y+aaa,0);
        glVertex3d(p[0].before_x-aaa,p[0].before_y+aaa,0);
        glEnd();
        glBegin(GL_QUADS);
        glVertex3d(p[0].before_x-aaa,p[0].before_y-aaa,0);
        glVertex3d(p[0].before_x-aaa,p[0].before_y-aaa,0);
        glVertex3d(p[0].before_x-aaa,p[0].before_y+aaa,0);
        glVertex3d(p[0].before_x-aaa,p[0].before_y+aaa,0);
        glEnd();
        glBegin(GL_QUADS);
        glVertex3d(p[0].before_x+aaa,p[0].before_y-aaa,0);
        glVertex3d(p[0].before_x+aaa,p[0].before_y-aaa,0);
        glVertex3d(p[0].before_x+aaa,p[0].before_y+aaa,0);
        glVertex3d(p[0].before_x+aaa,p[0].before_y+aaa,0);
        glEnd();
}

void obstacle(CPlayer p,CFlag *f,double x,double y,double x2){
    double aaa=0.5;
    glColor3f(0.8,0,0);
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
        glBegin(GL_QUADS);
        glVertex3d(x,y,0);
        glVertex3d(x+x2,y,0);
        glVertex3d(x+x2,y+aaa,0);
        glVertex3d(x,y+aaa,0);
        glEnd();
        glBegin(GL_QUADS);
        glVertex3d(x,y,0);
        glVertex3d(x+x2,y,0);
        glVertex3d(x+x2,y+aaa,0);
        glVertex3d(x,y+aaa,0);
        glEnd();
        glBegin(GL_QUADS);
        glVertex3d(x,y,0);
        glVertex3d(x,y,0);
        glVertex3d(x,y+aaa,0);
        glVertex3d(x,y+aaa,0);
        glEnd();
        glBegin(GL_QUADS);
        glVertex3d(x+x2,y,0);
        glVertex3d(x+x2,y,0);
        glVertex3d(x+x2,y+aaa,0);
        glVertex3d(x+x2,y+aaa,0);
        glEnd();
        
        glBegin(GL_TRIANGLES);
        glVertex3d(x,y+aaa,0);
        glVertex3d(x+x2,y+aaa,0);
        glVertex3d(x+x2/2,y+aaa+1,0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glVertex3d(x,y,0);
        glVertex3d(x+x2,y,0);
        glVertex3d(x+x2/2,y-1,0);
        glEnd();
    glPopMatrix();
    double distant=0;
    if(p.Get(0)<x){
        distant+=(x-p.Get(0))*(x-p.Get(0));
    }else if(p.Get(0)>x+x2){
        distant+=(x+x2-p.Get(0))*(x+x2-p.Get(0));
    }
    if(p.Get(1)<y){
        distant+=(y-p.Get(1))*(y-p.Get(1));
    }else if(p.Get(1)>y+aaa){
        distant+=(y+aaa-p.Get(1))*(y+aaa-p.Get(1));
    }
    if(distant<2.2){
        f->Menu(-1);
    }
}

//物の表示
void object(CPlayer p,CFlag* f){
    plate(rectangle1);
        plate(rectangle2);
        plate(rectangle3);
        plate(rectangle4);
        plate(rectangle5);
        plate(rectangle6);
        plate(rectangle7);
        plate(rectangle8);
        plate(rectangle9);
        plate(rectangle10);
        plate(rectangle11);
        plate(rectangle12);
        plate(rectangle13);
        plate(rectangle14);
        plate(rectangle15);
        plate(rectangle16);
        plate(rectangle17);
        plate(rectangle18);
        plate(rectangle19);
        plate(rectangle20);
        plate(rectangle21);
        plate(rectangle22);
        plate(rectangle23);
        plate(rectangle24);
        plate(rectangle25);
        plate(rectangle26);
        plate(rectangle27);
        plate(rectangle28);
        plate(rectangle29);
        plate(rectangle30);
        plate(rectangle31);
        plate(rectangle32);
        plate(rectangle33);
        plate(rectangle34);
        plate(rectangle35);
        plate(rectangle36);
        plate(rectangle37);
        plate(rectangle38);
        plate(rectangle39);
        plate(rectangle40);
        plate(rectangle41);
        plate(rectangle42);
        plate(rectangle43);
        plate(rectangle44);
        plate(rectangle45);
        plate(rectangle46);
        plate(rectangle47);
        plate(rectangle48);
        plate(rectangle49);
        plate(rectangle50);
        gunbase(shot[0]);
        gunbase(shot[1]);
        gunbase(shot[2]);
        gunbase(shot[3]);
        gunbase(shot[4]);
        gunbase(shot[5]);
        gunbase(shot[6]);
        gunbase(shot[7]);
        gunbase(shot[8]);
        gunbase(shot[9]);
        rectangle49.flag=2;
    if(f->Menu()==1){
        rectangle16.Move(5,0,0.1);
        obstacle(p,f,75,-27,5);
    }else if(f->Menu()==2){
        rectangle2.Move(6,0,0.1);
        rectangle3.Move(6,0,0.12);
        rectangle4.Move(6,0,0.14);
        rectangle5.Move(6,0,0.16);
        rectangle6.Move(6,0,0.18);
        rectangle7.Move(6,0,0.2);
        rectangle9.Move(6,0,0.2);
        rectangle10.Move(6,0,0.17);
        rectangle11.Move(6,0,0.23);
        rectangle12.Move(6,0,0.1);
        rectangle13.Move(6,0,0.3);
        rectangle14.Move(6,0,0.26);
        rectangle15.Move(0,6,0.23);
        obstacle(p,f,-404,-20,5);
        obstacle(p,f,-288,-20,5);
        obstacle(p,f,-204,-23,5);
        obstacle(p,f,-195,-23,5);
        obstacle(p,f,-181,-18,5);
        obstacle(p,f,-165,-21,5);
    }else if(f->Menu()==3){
        rectangle2.Move(10,0,0.1);
        rectangle6.Move(15,0,0.2);
        rectangle11.Move(5,0,0.1);
        rectangle13.Move(0,5,0.1);
        rectangle14.Move(0,5,0.11);
        rectangle49.flag=2;
        obstacle(p,f,-475,-15,5);
        obstacle(p,f,-460,-15,5);
        obstacle(p,f,-445,-15,5);
        obstacle(p,f,-320,-27,5);
        obstacle(p,f,-295,-27,5);
        obstacle(p,f,-181,-3,5);
        obstacle(p,f,-162,4,5);
        obstacle(p,f,-40,-17,5);
    }else if(f->Menu()==4){
        rectangle2.Move(5,0,0.1);
        rectangle3.Move(5,0,0.1);
        rectangle4.Move(5,0,0.1);
        rectangle5.Move(5,0,0.1);
        rectangle6.Move(5,0,0.1);
        rectangle7.Move(5,0,0.1);
        rectangle8.Move(5,0,0.1);
        rectangle9.Move(5,0,0.1);
        rectangle10.Move(5,0,0.1);
        rectangle11.Move(5,0,0.1);
        rectangle12.Move(5,0,0.1);
        rectangle13.Move(5,0,0.14);
        rectangle14.Move(5,0,0.1);
        rectangle15.Move(5,0,0.2);
        rectangle17.Move(5,0,0.1);
        rectangle18.Move(5,0,0.1);
        rectangle19.Move(5,0,0.2);
        rectangle20.Move(5,0,0.1);
        rectangle21.Move(0,5,0.1);
        rectangle22.Move(0,5,0.2);
        rectangle23.Move(5,0,0.1);
        rectangle24.Move(5,0,0.1);
        rectangle25.Move(5,0,0.2);
        rectangle26.Move(5,0,0.1);
        rectangle27.Move(5,0,0.2);
        rectangle28.Move(5,0,0.1);
        rectangle29.Move(5,0,0.1);
        rectangle30.Move(5,0,0.2);
        rectangle31.Move(5,0,0.13);
        rectangle32.Move(5,0,0.1);
        rectangle33.Move(5,0,0.2);
        rectangle34.Move(5,0,0.1);
        rectangle35.Move(5,0,0.1);
        rectangle49.flag=2;
        obstacle(p,f,-470,-25,5);
        obstacle(p,f,-447,-20,5);
        obstacle(p,f,-390,-28,5);
        obstacle(p,f,-225,-27,5);
        obstacle(p,f,-200,-23,5);
        obstacle(p,f,-168,-15,5);
        obstacle(p,f,-135,0,5);
        obstacle(p,f,-105,-5,5);
        obstacle(p,f,-40,-20,5);
        obstacle(p,f,10,-18,5);
        obstacle(p,f,-2.9,-4,5);
        obstacle(p,f,40,-18,5);
        obstacle(p,f,110,0,5);
        obstacle(p,f,260,3,5);
        obstacle(p,f,280,3,5);
        obstacle(p,f,300,3,5);
        obstacle(p,f,360,5,5);
        obstacle(p,f,400,-5,5);
        obstacle(p,f,450,-15,5);
        obstacle(p,f,480,-10,5);
        obstacle(p,f,500,-25,5);
        obstacle(p,f,530,-10,5);
        obstacle(p,f,560,-2,5);
    }
}

//地面の直線
void ground(){
    glColor3f(0,0,0);
    glBegin(GL_LINES);
        glVertex3f(-100,-15,0);
        glVertex3f(100,-15,0);
    glEnd();
}

void Launch(Pcoordinates q[],CPlayer p,double x,double y){
    glColor3f(0.1,0.1,0.1);
    int i;
    for(i=1;i<10;i++){
    if(q[i]->flag==1){
        q[i]->point_x+=x;
        q[i]->point_y+=y;
        glPushMatrix();
        glMatrixMode(GL_MODELVIEW);
        glTranslatef(q[i]->point_x,q[i]->point_y,q[i]->point_z);
        glutSolidSphere(2,20,20);
        glPopMatrix();
        if((p.Get(0)-q[i]->point_x)*(p.Get(0)-q[i]->point_x)+
            (p.Get(1)-q[i]->point_y)*(p.Get(1)-q[i]->point_y)>20000){
            q[i]->flag=0;
            q[i]->point_x=q[i]->before_x;
            q[i]->point_y=q[i]->before_y;
            q[i]->point_z=q[i]->before_z;
        }
    }
    }
}


void LaunchTimer(Pcoordinates q[],CPlayer p){
    int i=0;
    for(i=0;i<10;i++){
        if(q[i]->flag==0 ){
            if(i==0){
            q[i]->flag=1;
            }else if(q[i-1]->flag==1){
                q[i]->flag=1;
            }
        }
    }
}

void BulletEnter(coordinates p[],Pcoordinates q[],double x,double y){
    int bbb;
    for(bbb=0;bbb<10;bbb++){
        p[bbb].point_x=x;
        p[bbb].point_y=y;
        p[bbb].point_z=0;
        p[bbb].before_x=x;
        p[bbb].before_y=y;
        p[bbb].before_z=0;
        p[bbb].flag=0;
        q[bbb]=&p[bbb];
    }
}


#endif
