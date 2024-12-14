#include <GL/glut.h>
#include <cmath>

// Fungsi untuk menggambar segitiga berulang
void drawTriangles(float initialSize, int count) {
    for (int i = 0; i < count; ++i) {
        float size = initialSize - (i * 0.05f); // Mengurangi ukuran setiap segitiga
        glBegin(GL_LINE_LOOP); // Memulai menggambar segitiga
        for (int j = 0; j < 3; ++j) {
            glVertex2f(
                size * cos(j * 2.0f * M_PI / 3.0f),
                size * sin(j * 2.0f * M_PI / 3.0f)
            );
        }
        glEnd(); // Selesai menggambar

        // Pindahkan posisi segitiga ke tengah window
        glTranslatef(0.0f, 0.0f, 0.0f); 
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.65f, 0.0f); // Warna oranye

    float initialSize = 0.5f; // Ukuran awal segitiga
    int numberOfTriangles = 15; // Banyaknya segitiga yang akan digambar

    drawTriangles(initialSize, numberOfTriangles); // Panggil fungsi untuk menggambar segitiga

    glFlush(); // Mengosongkan buffer
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Latar belakang hitam
    glColor3f(1.0f, 0.65f, 0.0f); // Warna oranye
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // Set ortogonal proyeksi
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Segitiga Berulang");

    init(); // Inisialisasi pengaturan
    glutDisplayFunc(display); // Set fungsi display

    glutMainLoop(); // Mulai loop utama GLUT
    return 0;
}
