#include <GL/glut.h>
#include <cmath>

// Fungsi untuk menggambar hexagon
void drawHexagon() {
    glBegin(GL_POLYGON);

    for (int i = 0; i < 6; i++) {
        float angle = i * (2.0f * M_PI / 6); // Menghitung sudut untuk setiap vertex
        float x = 0.5f * cos(angle); // Menghitung koordinat x
        float y = 0.5f * sin(angle); // Menghitung koordinat y
        glVertex2f(x, y); // Menetapkan vertex
    }

    glEnd();
}

// Fungsi untuk menggambar tampilan
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Bersihkan buffer warna
    glColor3f(1.0f, 0.0f, 0.0f); // Warna merah untuk hexagon
    drawHexagon(); // Menggambar hexagon
    glFlush(); // Keluarkan semua perintah
}

// Fungsi untuk mengatur ukuran tampilan
void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

// Fungsi utama
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Hexagon in OpenGL");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Warna latar belakang putih (RGBA)
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop(); // Masuk ke loop utama
    return 0;
}

// untuk nengkompilenya 
// g++ hexagon.cpp -o hexagon -lGL -lGLU -lglut -lm
