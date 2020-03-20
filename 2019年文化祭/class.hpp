//プレイヤーのクラス
class CPlayer{
private:
    double point_x;
    double point_y;
    double point_z;
    double accX;
    double accY;
    double accZ;
    double before_x;
    double before_y;
    double before_z;
    double velX;
    double velY;
    double velZ;
    bool  flag_coll;
public:
    int timer;
    CPlayer(double x,double y,double z){
        point_x=x;
        point_y=y;
        point_z=z;
        accX=0;
        accY=0;
        accZ=0;
        before_x=0;
        before_y=0;
        before_z=0;
        velX=0;
        velY=0;
        velZ=0;
        timer=0;
        flag_coll=false;
    }
    
    double Get(int a){
        switch(a){
            case 0:return point_x;
            case 1:return point_y;
            case 2:return point_z;
            case 3:return velX;
            case 4:return velY;
            case 5:return velZ;
            case 6:return accX;
            case 7:return accY;
            case 8:return accZ;
            case 9:return before_x;
            case 10:return before_y;
            case 11:return before_z;
            default:return 0;
        }return 0;
    }
    
    int Enter(int a,double b){
        switch(a){
            case 0:point_x=b;return 0;
            case 1:point_y=b;return 0;
            case 2:point_z=b;return 0;
            case 3:velX=b;;return 0;
            case 4:velY=b;return 0;
            case 5:velZ=b;return 0;
            case 6:accX=b;return 0;
            case 7:accY=b;return 0;
            case 8:accZ=b;return 0;
            case 9:before_x=b;return 0;
            case 10:before_y=b;return 0;
            case 11:before_z=b;return 0;
            default:return 1;
        }return 0;
    }

    void Acceleration(int gametimer){
        before_x=point_x*1.00001;
        before_y=point_y*1.00001;
        before_z=point_z;
        velX=velX;
        velY=velY-2*(gametimer-timer)*0.0001;
        velZ=velZ;
        point_x+=velX;
        point_y+=velY;
        point_z+=velZ;
        velX*=0.6;
    }
    
    void Display(){
        glColor3f(0,0,0);
        glPushMatrix();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(point_x,point_y,point_z);
        glutSolidSphere(2,10,10);
        glPopMatrix();
    }
    bool Collision(int a){
        switch(a){
            case 1:flag_coll=true;break;
            case 0:flag_coll=false;break;
            default:return flag_coll;
        }
        return flag_coll;
    }
    
};

//キーボード入力用フラグ
class CFlag{
private:
    bool flag_right;
    bool flag_up;
    bool flag_left;
    bool flag_down;
    bool flag_jump;
    int flag_menu;
    int flag_menu_before;
public:
    CFlag(){
        flag_down=false;
        flag_left=false;
        flag_right=false;
        flag_right=false;
        flag_jump=false;
        flag_menu=0;
        flag_menu_before=flag_menu;
    }
    
    bool Get(int a){
        switch(a){
            case 100:
                return flag_left;
            case 101:
                return flag_up;
            case 102:
                return flag_right;
            case 103:
                return  flag_down;
            case 0:
                return flag_jump;
        }return false;
    }
    
    void Up(int a){
        switch(a){
            case 100:
                flag_left=true;break;
            case 101:
                flag_up=true;break;
            case 102:
                flag_right=true;break;
            case 103:
                flag_down=true;break;
            case 0:
                flag_jump=true;break;
            
        }
    }
    
    void Down(int a){
        switch(a){
            case 100:
                flag_left=false;break;
            case 101:
                flag_up=false;break;
            case 102:
                flag_right=false;break;
            case 103:
                flag_down=false;break;
            case 0:
                flag_jump=false;break;
        }
    }

    int Menu(int a){
        flag_menu=a;
        if(a>0&&a<5){
            flag_menu_before=flag_menu;
        }
        if(a>4){flag_menu=0;flag_menu_before=0;}
        return flag_menu;
    }
    
    int Menu(){
        return flag_menu;
    }
    
    int Before(){
        return flag_menu_before;
    }
};

//長方形
class CRec{
private:
    double x;
    double y;
    double z;
    double x2;
    double y2;
    double z2;
    double angle;
    double axisX;
    double axisY;
    double axisZ;
public:
    int flag=0;
    double bufferX=0;
    double bufferY=0;
    int timer=0;
    double before_x;
    double before_y;
    
    CRec(double ex,double ey,double ez,double exs,double eyh,
double ezv,double ang,double ax,double ay,double az){
    x=ex;y=ey,z=ez,x2=exs,y2=eyh,z2=ezv;angle=ang;axisX=ax;axisY=ay,axisZ=az;
    before_x=x;before_y=y;
    }
    
    double Max_return(int i){
    switch(i){
        case 0:if(x<x+x2){return x+x2;}
        else {return x;}
        case 1:if(y<y+y2){return y+y2;}
        else {return y;}
        case 2:if(z<z+z2){return z+z2;}
        else {return z;}
    }return 0;
}
    double Min_return(int i){
        switch(i){
            case 0:if(x<x+x2){return x;}
            else {return x+x2;}
            case 1:if(y<y+y2){return y;}
            else {return y+y2;}
            case 2:if(z<z+z2){return z;}
            else {return z+z2;}
        }return 0;
    }

    double Center(int i){
        switch(i){
            case 0:return (x2+x*2)/2;
            case 1:return (y2+y*2)/2;
            case 2:return (z2+z*2)/2;
        }return 0;
    }
    
    double Get(int i){
        switch(i){
            case 0:return x;
            case 1:return y;
            case 2:return z;
            case 3:return x2;
            case 4:return y2;
            case 5:return z2;
            case 6:return angle;
            case 7:return axisX;
            case 8:return axisY;
            case 9:return axisZ;
        }return 0;
    }
    
    void Move(double width,double depth,double a){
        if(x<=before_x){
            bufferX=a;
        }else if(x>before_x+width){
            bufferX=-a;
        }
        if(y<=before_y){
            bufferY=a;
        }else if(y>before_y+depth){
            bufferY=-a;
        }
        if(width==0){
            bufferX=0;
        }
        if(depth==0){
            bufferY;
        }
        if(width!=0){x+=bufferX;}
        if(depth!=0){y+=bufferY;}
        
    }    
};


