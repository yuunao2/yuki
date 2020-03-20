#include <string>

void Bitmap_characters(float x,float y,std::string str){
    const char *p=str.c_str();
    const unsigned char *p2=reinterpret_cast<const unsigned char*>(p);
    glPushMatrix;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1,1,-1,1,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(x,y);
    glColor3f(0,0,0);
    glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,p2);
    glPopMatrix();
}

void Stroke_characters(float x,float y,std::string str){
    const char *p=str.c_str();
    const unsigned char *p2=reinterpret_cast<const unsigned char*>(p);
    glPushMatrix;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(x,y,0);
    glColor3f(0,0,0);
    glutStrokeString(GLUT_STROKE_ROMAN,p2);
    glPopMatrix();
}

void Stroke_string(float x,float y,std::string str){
    const char *p=str.c_str();
    const unsigned char *p2=reinterpret_cast<const unsigned char*>(p);
    glPushMatrix;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(x,y,0);
    glColor3f(0,0,0);
    glutStrokeString(GLUT_STROKE_ROMAN,p2);
    glPopMatrix();
}
