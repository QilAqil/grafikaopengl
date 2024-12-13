#include <GL/glut.h>
int windowWidth = 700,
windowHeight = 700;
GLuint *texid = new GLuint[2];
GLuint texwidth=4;
GLuint texheight=1;
GLubyte texData[16] =
{
0xFF,0x00,0x00,0xFF, // red
0x00,0xFF,0x00,0xFF, // rgreen
0x00,0x00,0xFF,0xFF, // blue
0xFF,0xFF,0xFF,0xFF // white
};
GLubyte texData2[16] =
{
0x00,0xFF,0x00,0xFF, // rgreen
0x00,0xFF,0x00,0xFF, // rgreen
0x00,0x00,0xFF,0xFF, // blue
0xFF,0xFF,0xFF,0xFF // white
};
void InitTexture()
{
glEnable(GL_TEXTURE_2D);
glGenTextures(2, texid);
//Set Texture 1 (index 0)
glBindTexture(GL_TEXTURE_2D, texid[0]);
glTexImage2D (GL_TEXTURE_2D, 0, 4, texwidth,
texheight, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData);
glTexParameteri(GL_TEXTURE_2D,
GL_TEXTURE_MIN_FILTER, GL_NEAREST);
glTexParameteri(GL_TEXTURE_2D,
GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//Set Texture 2 (index 1)
glBindTexture(GL_TEXTURE_2D, texid[1]);
glTexImage2D (GL_TEXTURE_2D, 0, 4, texwidth,
texheight, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData2);
glTexParameteri(GL_TEXTURE_2D,
GL_TEXTURE_MIN_FILTER, GL_NEAREST);
glTexParameteri(GL_TEXTURE_2D,
GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//glTexParameteri(GL_TEXTURE_2D,
// GL_TEXTURE_MIN_FILTER, GL_LINEAR); //salah
//glTexParameteri(GL_TEXTURE_2D,
// GL_TEXTURE_MAG_FILTER, GL_LINEAR); // salah
}
void init() {
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
glClearColor(0.0, 0.0, 0.0, 0.0);
glEnable(GL_DEPTH_TEST);
glMatrixMode(GL_MODELVIEW);
InitTexture();
}
void display() {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//Get Texture 1 (index 0)
glBindTexture(GL_TEXTURE_2D, texid[0]);
glBegin(GL_QUADS);
// Top face
glVertex3f( 1.0f, -1.0f, -8.0f);
glVertex3f(-1.0f, -1.0f, -8.0f);
glVertex3f(-1.0f, -1.0f, -6.0f);
glVertex3f( 1.0f, -1.0f, -6.0f);
// Bottom face
glVertex3f( 1.0f, -3.0f, -6.0f);
glVertex3f(-1.0f, -3.0f, -6.0f);
glVertex3f(-1.0f, -3.0f, -8.0f);
glVertex3f( 1.0f, -3.0f, -8.0f);
// Front face
glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -6.0f);
glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -6.0f);
glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -3.0f, -6.0f);
glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -3.0f, -6.0f);
// Back face
glVertex3f( 1.0f, -3.0f, -8.0f);
glVertex3f(-1.0f, -3.0f, -8.0f);
glVertex3f(-1.0f, -1.0f, -8.0f);
glVertex3f( 1.0f, -1.0f, -8.0f);
// Left face
glVertex3f(-1.0f, -1.0f, -6.0f);
glVertex3f(-1.0f, -1.0f, -8.0f);
glVertex3f(-1.0f, -3.0f, -8.0f);
glVertex3f(-1.0f, -3.0f, -6.0f);
// Right face
glVertex3f(1.0f, -1.0f, -8.0f);
glVertex3f(1.0f, -1.0f, -6.0f);
glVertex3f(1.0f, -3.0f, -6.0f);
glVertex3f(1.0f, -3.0f, -8.0f);
glEnd();
//Get Texture 2 (index 1)
glBindTexture(GL_TEXTURE_2D, texid[1]);
glBegin(GL_QUADS);
// Top face
glVertex3f( 1.0f, -1.0f, -13.0f);
glVertex3f(-1.0f, -1.0f, -13.0f);
glVertex3f(-1.0f, -1.0f, -11.0f);
glVertex3f( 1.0f, -1.0f, -11.0f);
// Bottom face
glVertex3f( 1.0f, -3.0f, -13.0f);
glVertex3f(-1.0f, -3.0f, -13.0f);
glVertex3f(-1.0f, -3.0f, -11.0f);
glVertex3f( 1.0f, -3.0f, -11.0f);
// Front face
glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -11.0f);
glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -11.0f);
glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -3.0f, -11.0f);
glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -3.0f, -11.0f);
// Back face
glVertex3f( 1.0f, -3.0f, -13.0f);
glVertex3f(-1.0f, -3.0f, -13.0f);
glVertex3f(-1.0f, -1.0f, -13.0f);
glVertex3f( 1.0f, -1.0f, -13.0f);
// Left face
glVertex3f(-1.0f, -1.0f, -11.0f);
glVertex3f(-1.0f, -1.0f, -13.0f);
glVertex3f(-1.0f, -3.0f, -13.0f);
glVertex3f(-1.0f, -3.0f, -11.0f);
// Right face
glVertex3f(1.0f, -1.0f, -13.0f);
glVertex3f(1.0f, -1.0f, -11.0f);
glVertex3f(1.0f, -3.0f, -11.0f);
glVertex3f(1.0f, -3.0f, -13.0f);
glEnd();
glutSwapBuffers();
}
void reshape(int width, int height) {
if(height == 0)height = 1;
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45.0, width / height, 1.0, 400.0);
glMatrixMode(GL_MODELVIEW);
}
void keyboard(unsigned char key, int x, int y) {
switch (key) {
//gerak ke kiri
case 'a':
case 'A':
glTranslatef(-1.0, 0.0, 0.0);
break;
//gerak ke kanan
case 'd':
case 'D':
glTranslatef(1.0, 0.0, 0.0);
break;
//gerak ke depan
case 'w':
case 'W':
glTranslatef(0.0, 0.0, 1.0);
break;
//gerak ke belakang
case 's':
case 'S':
glTranslatef(0.0, 0.0, -1.0);
break;
//gerak ke atas
case 'q':
case 'Q':
glTranslatef(0.0, 1.0, 0.0);
break;
//gerak ke bawah
case 'e':
case 'E':
glTranslatef(0.0, -1.0, 0.0);
break;
//rotate ke kiri
case 'j':
case 'J':
glRotatef(1.0, 0.0, -5.0, 0.0);
break;
//rotate ke kanan
case 'l':
case 'L':
glRotatef(1.0, 0.0, 5.0, 0.0);
break;
//rotate ke samping kanan
case 'i':
case 'I':
glRotatef(1.0, 0.0, 0.0, -5.0);
break;
//rotate ke samping kiri
case 'k':
case 'K':
glRotatef(1.0, 0.0, 0.0, 5.0);
break;
//rotate ke atas
case 'o':
case 'O':
glRotatef(1.0, -5.0, 0.0, 0.0);
break;
//rotate ke bawah
case 'u':
case 'U':
glRotatef(1.0, 5.0, 0.0, 0.0);
break;
}
glutPostRedisplay();
}
int main(int argc, char** argv) { //salah
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(windowWidth, windowHeight);
glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - windowWidth) / 2,
(glutGet(GLUT_SCREEN_HEIGHT) - windowHeight) / 2);
glutCreateWindow("Latihan 3D");
init();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutKeyboardFunc(keyboard);
glutMainLoop();
}