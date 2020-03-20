#ifndef _COLLISION_
#define _COLLISION_
#include <math.h>
#ifndef _CLASS_HPP_
#define _CLASS_HPP_
#include "class.hpp"
#endif

extern int gametimer;
double x_coord(double x,double y,double angle){
    return x*cos(angle)-y*sin(angle);
}
double y_coord(double x,double y,double angle){
    return x*sin(angle)+y*cos(angle);
}

double coordination(int a,CPlayer *p,CRec q){
    double x=p->Get(0)-q.Center(0);
    double y=p->Get(1)-q.Center(1);
    if(a==0){
        x=x_coord(x,y,-1*q.Get(6));
        x+=q.Center(0);
        return x;
    }else if(a==1){
        y=y_coord(x,y,-1*q.Get(6));
        y+=q.Center(1);
        return y;
    }else if(a==2){
        x=x_coord(x,y,q.Get(6));
        x+=q.Center(0);
        return x;
    }else if(a==3){
        y=y_coord(x,y,q.Get(6));
        y+=q.Center(1);
        return y;
    }else {
        return 0;
    }
    
}

double coordination(int a,int cx,int cy,CRec q){
    double x=cx-q.Center(0);
    double y=cy-q.Center(1);
    if(a==0){
        x=x_coord(x,y,-1*q.Get(6));
        x+=q.Center(0);
        return x;
    }else if(a==1){
        y=y_coord(x,y,-1*q.Get(6));
        y+=q.Center(1);
        return y;
    }else if(a==2){
        x=x_coord(x,y,q.Get(6));
        x+=q.Center(0);
        return x;
    }else if(a==3){
        y=y_coord(x,y,q.Get(6));
        y+=q.Center(1);
        return y;
    }else {
        return 0;
    }
}

//球と長方形の距離
double Sphere_rec(CPlayer *p,CRec q){
    double distant=0;
    double x=coordination(0,p,q);
    double y=coordination(1,p,q);
    if(x<q.Min_return(0)){
        distant+=(q.Min_return(0)-x)*(q.Min_return(0)-x);
    }else if(x>q.Max_return(0)){
        distant+=(q.Max_return(0)-x)*(q.Max_return(0)-x);
    }
    if(y<q.Min_return(1)){
        distant+=(q.Min_return(1)-y)*(q.Min_return(1)-y);
    }else if(y>q.Max_return(1)){
        distant+=(q.Max_return(1)-y)*(q.Max_return(1)-y);
    }
    if(p->Get(2)<q.Min_return(2)){
        distant+=(q.Min_return(2)-p->Get(2))*(q.Min_return(2)-p->Get(2));
    }else if(p->Get(2)>q.Max_return(2)){
        distant+=(q.Max_return(2)-p->Get(2))*(q.Max_return(2)-p->Get(2));
    }
    return sqrt(distant);
} 

//衝突しているか
bool Coll_sphere_rec(CPlayer *p,CRec q,double a){
    if(Sphere_rec(p,q)<=a){
        p->Collision(1);
        return true;
    }else{
        p->Collision(0);
        return false;
    }
}

//長方形のどの方向に接しているか
//x\y||__1_|_____2____|_3__|  
// 1 || 11 |    12    |_13_|
// 2 || 21 |長方形本体22|_23_|
// 3 || 31 |    32    |_33_|
//三次元の時a==3
int Direction(CPlayer *p,CRec q,int a){
        int direct=0;
        double x=coordination(0,p,q);
        double y=coordination(1,p,q);
        if(x<q.Min_return(0)){
            direct+=1;
        }else if(x>q.Max_return(0)){
            direct+=3;
        }else {
            direct+=2;
        }
        if(y<q.Min_return(1)){
            direct+=30;
        }else if(y>q.Max_return(1)){
            direct+=10;
        }else {
            direct+=20;
        }
        if(a==3){
            if((p->Get(2)<q.Min_return(2))){
                direct+=100;
            }else if(p->Get(2)>q.Max_return(2)){
                direct+=300;
            }else {
                direct+=200;
            }
        }
        return direct;
}

//playerを長方形から弾く
void Coll(CPlayer *p,CRec q,CFlag *f){
    int a=2;
    if(Coll_sphere_rec(p,q,a)&&q.Get(6)!=0){
        switch(Direction(p,q,0)){
            case 11:
                p->Enter(0,p->Get(9));
                p->Enter(1,p->Get(10));
                break;
            case 12:
            case 22:
                 //if(p->Get(4)>0){break;}
                p->timer=glutGet(GLUT_ELAPSED_TIME);
                //p->Enter(4,0);
                if(q.bufferX!=0){
                    p->Enter(0,p->Get(9)+q.bufferX);
                }else{
                    p->Enter(0,p->Get(9));
                }
                p->Enter(1,p->Get(10));
                f->Down(0);
                break;
            case 13:
                p->Enter(0,p->Get(9));
                p->Enter(1,p->Get(10));
                break;
            case 21:
                p->Enter(0,p->Get(9));
                p->Enter(1,p->Get(10));
                break;
            case 23:
                p->Enter(0,p->Get(9));
                p->Enter(1,p->Get(10));
                break;
            case 31:
                break;
            case 32:
                p->Enter(4,0);
                p->Enter(0,p->Get(9));
                p->Enter(1,p->Get(10));
                break;
            case 33:
                p->Enter(0,p->Get(9));
                p->Enter(1,p->Get(10));
                break;
        }
    }else if(Coll_sphere_rec(p,q,a)&&q.Get(6)==0){
        switch(Direction(p,q,0)){
            case 11:
                p->Enter(0,q.Min_return(0)-a/1.414);
                p->Enter(1,q.Max_return(1)+a/1.414);
                break;
            case 12:
            case 22:
                if(p->Get(4)>0){break;}
                p->timer=glutGet(GLUT_ELAPSED_TIME);
                p->Enter(4,0);
                if(q.bufferX!=0){
                    p->Enter(0,p->Get(0)+q.bufferX);
                }
                if(q.bufferY!=0){
                    p->Enter(1,p->Get(1)+q.bufferY);
                }
                p->Enter(1,q.Max_return(1)+a);
                f->Down(0);
                if(q.flag==1){p->Enter(4,3);p->Enter(3,10);}
                if(q.flag==2){f->Menu(-2);}
                break;
            case 13:
                p->Enter(0,q.Max_return(0)+a/1.414);
                p->Enter(1,q.Max_return(1)+a/1.414);
                break;
            case 21:
                p->Enter(3,0);
                p->Enter(0,q.Min_return(0)-a);
                break;
            case 23:
                p->Enter(3,0);
                p->Enter(0,q.Max_return(0)+a);
                break;
            case 31:
                p->Enter(0,q.Min_return(0)-a/1.414);
                p->Enter(1,q.Min_return(1)-a/1.414);
                break;
            case 32:p->Enter(4,0);break;
            case 33:
                p->Enter(0,q.Max_return(0)+a/1.414);
                p->Enter(1,q.Min_return(1)-a/1.414);
                break;
        }
    }
}

void Coll(CPlayer *p,CFlag *f,coordinates q[],int a){
    int i;
    double distant=100;
    for(i=0;i<a;i++){
        if(q[i].flag==1){
        distant=(p->Get(0)-q[i].point_x)*(p->Get(0)-q[i].point_x);
        distant+=(p->Get(1)-q[i].point_y)*(p->Get(1)-q[i].point_y);
        if(distant<20){
            f->Menu(-1);
        }
    }
    }
}

#endif 
