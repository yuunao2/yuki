#include "glpng.h"


pngInfo info[10];
GLuint texture[10];//画像読み込み

void Loadtexture(pngInfo *a,GLuint *b,std::string c){
    const char *p=c.c_str();
    *b=pngBind(p,PNG_NOMIPMAP,PNG_ALPHA,a,GL_CLAMP, GL_LINEAR, GL_LINEAR);
}

GLfloat color[] = { 1.0, 1.0, 0.0, 1.0 };

void Print(GLuint a,double x1,double y1,double z1,double x2,double y2){
    glBindTexture(GL_TEXTURE_2D,a);
    //glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
    glBlendFunc(
    GL_SRC_ALPHA,           // GLenum sfactor
    GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
        glTexCoord2d(0,1);
        glVertex3d(x1,y1,z1);
        glTexCoord2d(1,1);
        glVertex3d(x2,y1,z1);
        glTexCoord2d(1,0);
        glVertex3d(x2,y2,z1);
        glTexCoord2d(0,0);
        glVertex3d(x1,y2,z1);
        
    glEnd();
    glDisable(GL_TEXTURE_2D);

}

void Pictures(){
    Print(texture[0],-1,-1,-1,1,1);
}
