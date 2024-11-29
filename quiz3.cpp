/*
* OGL01Shape3D.cpp: 3D Shapes
*/
// #include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

bool depan = true;

/* Initialize OpenGL Graphics */
void initGL() {
glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
glClearDepth(1.0f); // Set background depth to farthest
glEnable(GL_DEPTH_TEST); // Enable depth testing for z-culling
glDepthFunc(GL_LEQUAL); // Set the type of depth-test
glShadeModel(GL_SMOOTH); // Enable smooth shading
glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Nice perspective corrections
}

/* Handler for window-repaint event. Called back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers


glBegin(GL_QUADS); // Begin drawing the color cube with 6 quads
// Top face (y = 1.0f)
// Define vertices in counter-clockwise (CCW) order with normal pointing out
glColor3f(0.0f, 1.0f, 0.0f); // Green
glVertex3f( 1.0f, 1.0f, -1.0f);
glVertex3f(-1.0f, 1.0f, -1.0f);
glVertex3f(-1.0f, 1.0f, 1.0f);
glVertex3f( 1.0f, 1.0f, 1.0f);

// Bottom face (y = -1.0f)
glColor3f(1.0f, 0.5f, 0.0f); // Orange
glVertex3f( 1.0f, -1.0f, 1.0f);
glVertex3f(-1.0f, -1.0f, 1.0f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glVertex3f( 1.0f, -1.0f, -1.0f);

// Front face (z = 1.0f)
if (depan) {
glColor4f(1.0f, 0.0f, 0.0f, 0.5f); // Red
glVertex3f( 1.0f, 1.0f, 1.0f);
glVertex3f(-1.0f, 1.0f, 1.0f);
glVertex3f(-1.0f, -1.0f, 1.0f);
glVertex3f( 1.0f, -1.0f, 1.0f);
}

// Back face (z = -1.0f)
glColor3f(1.0f, 1.0f, 0.0f); // Yellow
glVertex3f( 1.0f, -1.0f, -1.0f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glVertex3f(-1.0f, 1.0f, -1.0f);
glVertex3f( 1.0f, 1.0f, -1.0f);

// Left face (x = -1.0f)
glColor3f(0.0f, 0.0f, 1.0f); // Blue
glVertex3f(-1.0f, 1.0f, 1.0f);
glVertex3f(-1.0f, 1.0f, -1.0f);
glVertex3f(-1.0f, -1.0f, -1.0f);
glVertex3f(-1.0f, -1.0f, 1.0f);

// Right face (x = 1.0f)
glColor3f(1.0f, 0.0f, 1.0f); // Magenta
glVertex3f(1.0f, 1.0f, -1.0f);
glVertex3f(1.0f, 1.0f, 1.0f);
glVertex3f(1.0f, -1.0f, 1.0f);
glVertex3f(1.0f, -1.0f, -1.0f);
glEnd();
glutSwapBuffers(); // Swap the front and back frame buffers (double buffering)
}

/* Handler for window re-size event. Called back when the window first appears and
whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) { // GLsizei for non-negative integer
// Compute aspect ratio of the new window
if (height == 0) height = 1; // To prevent divide by 0
GLfloat aspect = (GLfloat)width / (GLfloat)height;

// Set the viewport to cover the new window
glViewport(0, 0, width, height);

// Set the aspect ratio of the clipping volume to match the viewport
glMatrixMode(GL_PROJECTION); // To operate on the Projection matrix
glLoadIdentity(); // Reset
// Enable perspective projection with fovy, aspect, zNear and zFar
gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void keyboard(unsigned char key, int x, int y) {
switch (key) {
//gerak ke kiri
case 'b':
case 'B':
depan = false;
break;
//gerak ke kiri
case 'v':
case 'V':
depan = true;
break;
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
display();
//glutPostRedisplay();
}


/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
glutInit(&argc, argv); // Initialize GLUT
glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
glutInitWindowSize(640, 480); // Set the window's initial width & height
glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
glutCreateWindow("Latihan 3D"); // Create window with the given title
glutDisplayFunc(display); // Register callback handler for window re-paint event
glutReshapeFunc(reshape); // Register callback handler for window re-size event
glutKeyboardFunc(keyboard);
initGL(); // Our own OpenGL initialization
glutMainLoop(); // Enter the infinite event-processing loop
return 0;
}