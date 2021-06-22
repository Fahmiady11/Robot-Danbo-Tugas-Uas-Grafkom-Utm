#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;
float spinX = 0.0,spinY = 0.0;
//boolean diff = true, spec = true ,amb=true;
static int lenganKanan = 0,bahuKanan=0,lenganKiri=0,bahuKiri=0,kepala=0;
void lingkaran(int xp, int yp, int r, int n){
    float a,x,y;
    glBegin(GL_POLYGON);
        a=6.28/n;
        for (int i=0; i<n; i++){
            x = xp+r * cos(i*a);
            y = yp+r * sin(i*a);
            glVertex2d(x,y);
       }
    glEnd();
}
void bulatanMata(float alas,float atas,float tinggi){
    float i;
    glPushMatrix();
   glColor3f(1.0, 1.0, 0.0);
    for(i=0;i<=tinggi;i+=alas/24){
        glTranslatef(0.0,0.0,alas/24);
        glColor3f(1.0, 1.0, 0.0);
        glutSolidTorus(alas/4,alas-((i*(alas-atas))/tinggi),16,16);
     }
    glColor3f(1.0, 1.0, 1.0);
    glutSolidCone(tinggi,0,20,1);
    glPopMatrix();
}
void mulut(void){
    //depan
    glBegin(GL_POLYGON);
    //glNormal3f(1.0,0.0,0.0);
    glVertex3f(-1.0, 1.0, 0.2);
    glVertex3f(1.0, 1.0, 0.2);
    glVertex3f(0.0, 0.0, 0.2);
    glEnd();
    //belakang
     glBegin(GL_POLYGON);
    //glNormal3f(1.0,0.0,0.0);
    glVertex3f(-1.0, 1.0, -0.2);
    glVertex3f(1.0, 1.0, -0.2);
    glVertex3f(0.0, 0.0, -0.2);
    glEnd();
    //atas
    glBegin(GL_POLYGON);
    //glNormal3f(1.0,0.0,0.0);
     glVertex3f(-1.0, 1.0, 0.2);
      glVertex3f(1.0, 1.0, 0.2);
       glVertex3f(1.0, 1.0, -0.2);
       glVertex3f(-1.0, 1.0, -0.2);
    glEnd();
    //samping kanan
    glBegin(GL_POLYGON);
    //glNormal3f(1.0,0.0,0.0);
    glVertex3f(-1.0, 1.0, 0.2);
      glVertex3f(0.0, 0.0, 0.2);
    glVertex3f(0.0, 0.0, -0.2);
     glVertex3f(-1.0, 1.0, -0.2);
    glEnd();
     //samping kiri
    glBegin(GL_POLYGON);
    //glNormal3f(1.0,0.0,0.0);
    glVertex3f(1.0, 1.0, 0.2);
      glVertex3f(0.0, 0.0, 0.2);
    glVertex3f(0.0, 0.0, -0.2);
     glVertex3f(1.0, 1.0, -0.2);
    glEnd();
}
void mata(void){
        glPushMatrix();
            glPushMatrix();
				glTranslatef(-0.3,0.2,0.6);
				bulatanMata(1,1,1);
			glPopMatrix();
			glPushMatrix();
				//eyeball right
				glTranslatef(2.2,0.2,0.6);
				bulatanMata(1,1,1);
			glPopMatrix();
        glPopMatrix();
        //pupil
        glTranslatef(-0.290,0.180,1.8);
		glPushMatrix();
            glColor3d(0,0,0);
            glScalef(0.1,0.1,0.0);
            glPushMatrix();
				lingkaran(0,0,4,50);
			glPopMatrix();

			glTranslatef(25.0,0.2,0.0);
			glPushMatrix();
				//eyeball right
				lingkaran(0,0,4,50);
			glPopMatrix();
        glPopMatrix();
}
void logo(void){
            glPushMatrix();
                glBegin(GL_POLYGON);
                glColor3f(1,0,0);
                glVertex3d(-5,-6,0);
                glVertex3d(1,7,0);
                glVertex3d(2.7,7,0);
                glVertex3d(-3,-6,0);
                glEnd();
                //kotak2
                glBegin(GL_POLYGON);
                glColor3f(1,0,0);
                glVertex3d(1,7,0);
                glVertex3d(2.7,7,0);
                glVertex3d(2.7,-1,0);
                glVertex3d(1,0.5,0);
                glEnd();
                //kotak3
                glBegin(GL_POLYGON);
                glColor3f(1,0,0);
                glVertex3d(-1 ,-0.5,0 );
                glVertex3d(1 ,-0.5,0 );
                glVertex3d(1 ,-2.3,0 );
                glVertex3d(-1.5 ,-2.3,0 );
                glEnd();
                 //segitiga1
                glBegin(GL_POLYGON);
                glColor3f(1,0,0);
                glVertex3d(1 ,0.2,0 );
                glVertex3d(2.7 ,-1.3,0 );
                glVertex3d(1 ,-3,0 );
                glEnd();

                //segitiga2
                glBegin(GL_POLYGON);
                glColor3f(1,0,0);
                glVertex3d(1 ,-3.3,0 );
                glVertex3d(2.7 ,-1.7,0 );
                glVertex3d(2.7 ,-3.3,0 );
                glEnd();
                 //lineA
                glBegin(GL_LINE_LOOP);
                glColor3f(0.0,0.0,1.0);
                glRotated(90.0,1,0,0);
                glVertex3d(-5 ,-6,0 );
                glVertex3d(1 ,7,0 );
                glVertex3d(2.7 ,7,0 );
                glVertex3d(2.7 ,-1,0 );
                glVertex3d(1.1 ,0.5,0 );
                glVertex3d(1.1 ,3.5,0 );
                glVertex3d(-0.6 ,-0.5,0 );
                glVertex3d(1 ,-0.5,0 );
                glVertex3d(1 ,0.2,0 );
                glVertex3d(2.7 ,-1.3,0 );
                glVertex3d(1 ,-3,0 );
                glVertex3d(1 ,-2.3,0 );
                glVertex3d(-1.4 ,-2.3,0 );
                glVertex3d(-3 ,-6,0 );
                glEnd();
                glBegin(GL_LINE_LOOP);
                glColor3f(0.0,0.0,1.0);
                glVertex3d(1 ,-3.3,0 );
                glVertex3d(2.7 ,-1.7,0 );
                glVertex3d(2.7 ,-3.3,0);
                glEnd();
            glPopMatrix();



}
void bawahan(void){
glBegin(GL_POLYGON);
    //glNormal3f(0.0,0.0,-1.0);
    //belakang
    glVertex3f(1.0, -1.0, -1.2);
    glVertex3f(-1.0, -1.0, -1.2);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glEnd();

    glBegin(GL_POLYGON);
    //glNormal3f(0.0,0.0,1.0);
    glVertex3f(-1.0, -1.0, 1.7);
    glVertex3f(1.0, -1.0, 1.7);
    glVertex3f(1.0, 1.0, 1.5);
    glVertex3f(-1.0, 1.0, 1.5);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    //glNormal3f(-1.0,0.0,0.0);
    glVertex3f(-1.2, -1.0, -1.0);
    glVertex3f(-1.2, -1.0, 1.4);
    glVertex3f(-1.0, 1.0, 1.4);
    glVertex3f(-1.0, 1.0, -1.0);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    //glNormal3f(-1.0,0.0,0.0);
    glVertex3f(1.2, -1.0, -1.0);
    glVertex3f(1.2, -1.0, 1.4);
    glVertex3f(1.0, 1.0, 1.4);
    glVertex3f(1.0, 1.0, -1.0);
    glEnd();


}
void sayap(void){

    glBegin(GL_POLYGON);
    //glNormal3f(0.0,0.0,-1.0);
    glVertex3f(1.0, -1.0, -1.8);
    glVertex3f(-1.0, -1.0, -1.8);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glEnd();

}
void segitiga(void){//format kiri
    //depan
    glBegin(GL_POLYGON);
    //glNormal3f(0.0,0.0,1.0);
    glVertex3f(-0.5,-0.5, 1.0);
    glVertex3f(0.0, -0.5, 1.0);
    glVertex3f(0.0, 1.0, 1.0);
    glVertex3f(-0.5, 0.5, 1.0);
    glEnd();

     //belakang
    glBegin(GL_POLYGON);
    //glNormal3f(0.0,0.0,1.0);
    glVertex3f(-0.5,-0.5, -1.0);
    glVertex3f(0.0, -0.5, -1.0);
    glVertex3f(0.0, 1.0, -1.0);
    glVertex3f(-0.5, 0.5, -1.0);
    glEnd();

     //samping kiri atas
    glBegin(GL_POLYGON);

    //glNormal3f(0.0,0.0,1.0);
    glVertex3f(-0.5,0.5, -1.0);
    glVertex3f(-0.5,0.5, 1.0);

    glVertex3f(0.0, 1.0,  1.0);
    glVertex3f(0.0, 1.0, -1.0);
    glEnd();

    //samping kiri bawah
    glBegin(GL_POLYGON);
    //glNormal3f(0.0,0.0,1.0);
    glVertex3f(-0.5,-0.5, -1.0);
    glVertex3f(-0.5,-0.5, 1.0);

    glVertex3f(-0.5, 0.5,  1.0);
    glVertex3f(-0.5, 0.5, -1.0);
    glEnd();

    //samping kanan
    glBegin(GL_POLYGON);
    //glNormal3f(0.0,0.0,1.0);
    glVertex3f(0.0,-0.5, -1.0);
    glVertex3f(0.0,-0.5, 1.0);

    glVertex3f(0.0, 1.0,  1.0);
    glVertex3f(0.0, 1.0, -1.0);
    glEnd();

    //bawah
    glBegin(GL_POLYGON);
    //glNormal3f(0.0,0.0,1.0);
    glVertex3f(-0.5,-0.5, -1.0);
    glVertex3f(-0.5,-0.5, 1.0);

    glVertex3f(0.0, -0.5,  1.0);
    glVertex3f(0.0, -0.5, -1.0);
    glEnd();




}
void balok(void){
    //depan
    glBegin(GL_POLYGON);
    //glNormal3f(0.0,0.0,1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
    //glNormal3f(0.0,0.0,-1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glEnd();

    //kiri
    glBegin(GL_POLYGON);
    //glNormal3f(-1.0,0.0,0.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
    //glNormal3f(1.0,0.0,0.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glEnd();

    //bawah
    glBegin(GL_POLYGON);
    //glNormal3f(0.0,-1.0,0.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glEnd();

    //atas
    glBegin(GL_POLYGON);
    //glNormal3f(0.0,1.0,0.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glEnd();

}
void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
 // glTranslated(0,1.5,0);
 GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
 GLfloat mat_shininess[] = { 100.0 };
 GLfloat mat_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
 glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);


 glPushMatrix();
     glLoadIdentity();

     glTranslated(0,-1.0,0);
     glRotatef((GLfloat)spinX, 1,0,0);
     glRotatef((GLfloat)spinY, 0,1,0);
     //glRotated(90, 1,0,0);
     glTranslated(0,1.0,0);

     glTranslated(0,1.5,0);
     glNormal3f(0.0,1.0,1.0);
     //kepala
     glPushMatrix();
         glRotatef((GLfloat)kepala,0.0,1.0,0.0);
         //rambut
         glPushMatrix();
                 glPushMatrix();
                        glColor3d(0,0,1);
                        glScalef(1.1,0.1,0.8);
                        balok();
                 glPopMatrix();
                 glPushMatrix();
                        glRotated(90,1,0,0);
                        glScalef(-0.1,-0.1,-0.1);
                        glColor3f(0,0.5,0);
                        glutSolidCone(20,15,100,4);
                        glColor3f(0.5,0.5,0);
                        glutWireCone(20.1,15,50,4);
                 glPopMatrix();
        glPopMatrix();

        glTranslated(0.0,-0.8,0.0);
        //wajah
        glPushMatrix();
            glPushMatrix();
                glColor3d(1,0,0);
                glScalef(1.2,0.2,0.2);
                balok();
            glPopMatrix();
            glPushMatrix();
                glColor3d(1,1,0);
                glScalef(1.1,0.7,0.8);
                balok();
            glPopMatrix();
            glTranslated(0.0,0.0,0.201);
             //glTranslated(0.0,0.0,4.201);
            glPushMatrix();
                 glTranslated(-0.303,0.2,0.480);
                 glScalef(0.3,0.3,0.2);
                mata();
                  //glTranslated(0.0,0.0,4.201);
                glPushMatrix();
                    glTranslated(0.0,0.0,1.100);
                    glScalef(2.3,2.3,0.0);
                    //mata();
                 glPopMatrix();
            glPopMatrix();
            glTranslated(0.0,-0.5,0.5);
            glPushMatrix();
                glColor3d(0,0,0);
                glScaled(0.2,0.2,1.0);
                mulut();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    glTranslatef (0.0, -2.4, 0.0);
    //badan
    glPushMatrix();
        glPushMatrix();
            glColor3d(0,0,0.8);
            glScalef(0.7,0.9,0.5);
            balok();
        glPopMatrix();
        glPushMatrix();
            glScalef(0.7,0.9,0.5);
            glColor3d(1,0,0);
            sayap();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0,-1.2,-0.1);
            glScalef(0.7,0.3,0.4);
            glColor3d(1,0,0);
            bawahan();
        glPopMatrix();
        glTranslatef(0.0f,0.2f,0.501f);
        glPushMatrix();
            glPushMatrix();
                glScalef(-0.12,-0.12,0.0);
                glColor3d(0,0,0);
                lingkaran(0,0,4,50);
            glPopMatrix();

                glTranslatef(0.0,0.0,0.002);

            glPushMatrix();
                glScalef(-0.102,-0.102,0.0);
                glColor3d(1,1,0);
                lingkaran(0,0,4,50);
            glPopMatrix();

                glTranslatef(0.0,-0.1,0.002);
                glRotated(180,0,0,1);

            glPushMatrix();
                glScalef(-0.1,-0.1,0.0);
                glColor3d(1,0,0);
                logo();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();

    glTranslatef (-0.4, -1.5, 0.0);
    //kaki
    glPushMatrix();
       glColor3d(1,1,0);
       glPushMatrix();
        glScalef(0.3,0.6,0.3);
        balok();
       glPopMatrix();

       glTranslatef (0.8,0.0, 0.0);

       glPushMatrix();
       glScalef(0.3,0.6,0.3);
        balok();
       glPopMatrix();
    glPopMatrix();

     glTranslatef (-0.3, 1.9, 0.0);
    //tangan
    glPushMatrix();
       //tangan kiri
       glPushMatrix();
            glTranslated(-2.0,-0.104,0.0);
            glTranslatef (1.0, 0.0, 0.0);
            glRotatef ((GLfloat) bahuKiri, 1.0, 0.0, 0.0);
            glTranslatef (1.0, 0.0, 0.0);
            //bahu kiri
            glPushMatrix();
                glColor3d(1,0,0);
                glScalef(0.8,0.6,0.3);
                segitiga();
            glPopMatrix();

            glTranslatef (1.0, 0.0, 0.0);
            glRotatef ((GLfloat) lenganKiri, 1.0, 0.0, 0.0);
            glTranslatef (1.0, 0.0, 0.0);
            //lengan kiri
            glPushMatrix();
                glColor3d(1,1,0);
                glTranslatef (-2.202, -0.8, 0.0);
                glScalef(0.16,0.7,0.25);
                balok();
            glPopMatrix();
       glPopMatrix();

       glTranslatef (1.8,0.0,0.0);
       glRotated(180,0,1,0);
       glTranslatef (0.401,0.0,0.0);
        //tangan kanan
       glPushMatrix();
            glTranslated(-2.0,-0.104,0.0);
            glTranslatef (1.0, 0.0, 0.0);
            glRotatef ((GLfloat) bahuKanan, 1.0, 0.0, 0.0);
            glTranslatef (1.0, 0.0, 0.0);
            //bahu kanan
            glPushMatrix();
                glColor3d(1,0,0);
                glScalef(0.8,0.6,0.3);
                segitiga();
            glPopMatrix();

            glTranslatef (1.0, 0.0, 0.0);
            glRotatef ((GLfloat) lenganKanan, 1.0, 0.0, 0.0);
            glTranslatef (1.0, 0.0, 0.0);
            //lengan kanan
            glPushMatrix();
                glColor3d(1,1,0);
                glTranslatef (-2.202, -0.8, 0.0);
                glScalef(0.16,0.7,0.25);
                balok();
            glPopMatrix();
       glPopMatrix();
    glPopMatrix();




 glPopMatrix();
 glutSwapBuffers();
 glFlush();
}
void spinDisplayXL(void)
{
 spinX = spinX + 0.03;
 glutPostRedisplay();
}
void spinDisplayXR(void)
{
 spinX = spinX - 0.03;
 glutPostRedisplay();
}
void spinDisplayYL(void)
{
 spinY = spinY - 0.03;
 glutPostRedisplay();
}
void spinDisplayYR(void)
{
 spinY = spinY + 0.03;
 glutPostRedisplay();
}

void myInit(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);

    GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f};

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);


    GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f};
    GLfloat lightPos0[] = {2.0f, 2.0f, 2.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);


    GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f};
    GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);


    GLfloat light_position_diff[] = { 1.0, -1.0, 1.0, 0.0 };
    GLfloat diffuse_light[] = { 1.0, 1.0, 1.0, 1.0 };

    GLfloat light_position_spec[] = { 1.0, -1.0, 1.0, 0.0 };
    GLfloat specular_light[] = { 1.0, 1.0, 1.0, 1.0 };


    glLightfv(GL_LIGHT0, GL_POSITION, light_position_diff);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);

    glLightfv(GL_LIGHT1, GL_POSITION, light_position_spec);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular_light);


    GLfloat ambient_light[] = { 0.9, 0.9, 0.9, 1.0 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient_light);

    glShadeModel (GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
	glShadeModel (GL_SMOOTH);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    //glEnable(GL_LIGHT2);
    //glEnable(GL_LIGHT3);
    glEnable(GL_NORMALIZE);
    glClearColor (0.0, 0.0, 0.0, 0.0);


}
void reshape(int w, int h)
{
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    if (w >= h)
        glOrtho (-3.5, 3.5, -3.5*(GLfloat)h/(GLfloat)w, 3.5*(GLfloat)h/(GLfloat)w, - 10.0, 10.0);
    else
        glOrtho (-3.5*(GLfloat)w/(GLfloat)h, 3.5*(GLfloat)w/(GLfloat)h, -3.5, 3.5, -10.0, 10.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void pencahayaan(bool light1,bool light2){

    GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f};
    //Color (0.2, 0.2, 0.2)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	if (light1 == true){
		//Add positioned light
		GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
		GLfloat lightPos0[] = {2.0f, 2.0f, 2.0f, 1.0f}; //Positioned at (4, 0, 8)
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
		glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	} else {
		GLfloat lightColor0[] = {0.0f, 0.0f, 0.0f, 0.0f};
		GLfloat lightPos0[] = {0.0f, 0.0f, 0.0f, 0.0f}; //Positioned at (4, 0, 8)
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
		glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	}
	if (light2 == true){
		//Add directed light
		GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
		//Coming from the direction (-1, 0.5, 0.5)
		GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
		glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
		glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	} else {
		GLfloat lightColor1[] = {0.0f, 0.0f, 0.0f, 0.0f}; //Color (0.5, 0.2, 0.2)
		GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
		glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
		glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	}

}

void keyboard (unsigned char key, int x, int y)
{
 switch (key)
 {
 case 's':
     if(bahuKanan<110){
        bahuKanan = (bahuKanan + 5) % 360;
     }
 glutPostRedisplay();
 break;
 case 'S':
     if(bahuKanan>-110){
        bahuKanan = (bahuKanan - 5) % 360;
     }
 glutPostRedisplay();
 break;

 case 'w':
    if(bahuKiri>-110){
        bahuKiri = (bahuKiri - 5) % 360;
     }
 glutPostRedisplay();
 break;
 case 'W':
 if(bahuKiri<110){
        bahuKiri = (bahuKiri + 5) % 360;
     }
 glutPostRedisplay();
 break;

 case 'a':
  if(lenganKiri>-90){
    lenganKiri = (lenganKiri - 5) % 360;
  }
 glutPostRedisplay();
 break;
 case 'A':
 if(lenganKiri<0){
    lenganKiri = (lenganKiri + 5) % 360;
  }
 cout<<lenganKiri<<endl;
 glutPostRedisplay();
 break;

 case 'd':
  if(lenganKanan<90){
    lenganKanan = (lenganKanan + 5) % 360;
  }
 glutPostRedisplay();
 break;
 case 'D':
 if(lenganKanan>0){
    lenganKanan = (lenganKanan - 5) % 360;
  }
 glutPostRedisplay();
 break;

 case 'x':
  glutIdleFunc(spinDisplayXL);
 break;
 case 'X':
  glutIdleFunc(spinDisplayXR);
 break;

 case 'y':
 glutIdleFunc(spinDisplayYL);
 break;
 case 'Y':
 glutIdleFunc(spinDisplayYR);
 break;

 case 'p':
 glutIdleFunc(NULL);
 break;
 case 'P':
 glutIdleFunc(NULL);
 break;

 /*case '1':
         if (amb == true){
         GLfloat ambient_light[] = { 0.3, 0.3, 0.3, 1.0 };
         glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient_light);
         amb = false;
         }
         else{
         GLfloat ambient_light[] = { 0.9, 0.9, 0.9, 1.0 };
         glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient_light);
         amb = true;
         }
 break;
 case '2':
         if (diff == true){
         glDisable(GL_LIGHT0);
         diff = false;
         }
         else{
         glEnable(GL_LIGHT0);
         diff = true;
         }
 break;
 case '3':
         if (spec == true){
         glDisable(GL_LIGHT1);
         spec = false;
         }
         else{
         glEnable(GL_LIGHT1);
         spec = true;
         }
break;*/

 display();

 case 27:
 exit(0);
 break;
 default:
 break;
 }
}
void mykey (int key, int x, int y)
{
 switch (key)
 {
 case GLUT_KEY_LEFT:
     if(kepala>-95){
        kepala=(kepala-5)%360;
     }
 break;

 case GLUT_KEY_RIGHT:
     if(kepala<95){
        kepala=(kepala+5)%360;
     }
 break;

 }
  display();
}

int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB |  GLUT_DEPTH );
 glutInitWindowSize (800, 800);
 glutInitWindowPosition (30, 30);
 glutCreateWindow("tugasUAS_190_127");
 myInit();
 glutDisplayFunc(display);
 pencahayaan(true,true);
 glutReshapeFunc(reshape);
 glutSpecialFunc(mykey);
 glutKeyboardFunc(keyboard);
 glutMainLoop();
 return 0;
 }
