/*
* OGL01Shape3D.cpp: 3D Shapes
*/ 
// #include <windows.h> // untuk MS Windows
#include <GL/glut.h> // GLUT, termasuk glu.h dan gl.h

bool depan = true; // Menentukan apakah sisi depan ditampilkan

/* Inisialisasi Grafik OpenGL */
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Mengatur warna latar belakang menjadi hitam dan opaque
    glClearDepth(1.0f); // Mengatur kedalaman latar belakang ke posisi terjauh
    glEnable(GL_DEPTH_TEST); // Mengaktifkan pengujian kedalaman untuk z-culling
    glDepthFunc(GL_LEQUAL); // Mengatur jenis pengujian kedalaman
    glShadeModel(GL_SMOOTH); // Mengaktifkan shading yang halus
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Koreksi perspektif yang baik
}

/* Handler untuk event pengecatan jendela. Dipanggil saat jendela pertama kali muncul dan
setiap kali jendela perlu di-repaint. */
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Menghapus buffer warna dan kedalaman

    glBegin(GL_QUADS); // Mulai menggambar kubus warna dengan 6 quad (empat sisi)

    // Sisi atas (y = 1.0f)
    // Menentukan vertex dalam urutan melawan jarum jam (CCW) dengan normal mengarah keluar
    glColor3f(0.0f, 1.0f, 0.0f); // Hijau
    glVertex3f( 1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);

    // Sisi bawah (y = -1.0f)
    glColor3f(1.0f, 0.5f, 0.0f); // Oranye
    glVertex3f( 1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    // Sisi depan (z = 1.0f)
    if (depan) {
        glColor4f(1.0f, 0.0f, 0.0f, 0.5f); // Merah dengan transparansi
        glVertex3f( 1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f( 1.0f, -1.0f, 1.0f);
    }

    // Sisi belakang (z = -1.0f)
    glColor3f(1.0f, 1.0f, 0.0f); // Kuning
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f( 1.0f, 1.0f, -1.0f);

    // Sisi kiri (x = -1.0f)
    glColor3f(0.0f, 0.0f, 1.0f); // Biru
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // Sisi kanan (x = 1.0f)
    glColor3f(1.0f, 0.0f, 1.0f); // Magenta
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    
    glEnd(); // Mengakhiri penggambaran quad
    glutSwapBuffers(); // Menukar buffer depan dan belakang (double buffering)
}

/* Handler untuk event resize jendela. Dipanggil saat jendela pertama kali muncul dan
setiap kali jendela diubah ukurannya dengan lebar dan tinggi baru */
void reshape(GLsizei width, GLsizei height) { // GLsizei untuk integer non-negatif
    // Menghitung rasio aspek jendela yang baru
    if (height == 0) height = 1; // Untuk mencegah pembagian dengan 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Mengatur viewport untuk menutupi jendela yang baru
    glViewport(0, 0, width, height);

    // Mengatur rasio aspek dari volume potong untuk mencocokkan viewport
    glMatrixMode(GL_PROJECTION); // Untuk beroperasi pada matriks Proyeksi
    glLoadIdentity(); // Reset
    // Mengaktifkan proyeksi perspektif dengan fovy, aspect, zNear dan zFar
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

// Fungsi untuk menangani input keyboard
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        // Mengganti tampilan sisi depan menjadi belakang
        case 'b':
        case 'B':
            depan = false;
            break;
        // Mengganti tampilan sisi belakang menjadi depan
        case 'v':
        case 'V':
            depan = true;
            break;
        // Gerak ke kiri
        case 'a':
        case 'A':
            glTranslatef(-1.0, 0.0, 0.0);
            break;
        // Gerak ke kanan
        case 'd':
        case 'D':
            glTranslatef(1.0, 0.0, 0.0);
            break;
        // Gerak ke depan
        case 'w':
        case 'W':
            glTranslatef(0.0, 0.0, 1.0);
            break;
        // Gerak ke belakang
        case 's':
        case 'S':
            glTranslatef(0.0, 0.0, -1.0);
            break;
        // Gerak ke atas
        case 'q':
        case 'Q':
            glTranslatef(0.0, 1.0, 0.0);
            break;
        // Gerak ke bawah
        case 'e':
        case 'E':
            glTranslatef(0.0, -1.0, 0.0);
            break;
        // Putar ke kiri
        case 'j':
        case 'J':
            glRotatef(1.0, 0.0, -5.0, 0.0);
            break;
        // Putar ke kanan
        case 'l':
        case 'L':
            glRotatef(1.0, 0.0, 5.0, 0.0);
            break;
        // Putar ke samping kanan
        case 'i':
        case 'I':
            glRotatef(1.0, 0.0, 0.0, -5.0);
            break;
        // Putar ke samping kiri
        case 'k':
        case 'K':
            glRotatef(1.0, 0.0, 0.0, 5.0);
            break;
        // Putar ke atas
        case 'o':
        case 'O':
            glRotatef(1.0, -5.0, 0.0, 0.0);
            break;
        // Putar ke bawah
        case 'u':
        case 'U':
            glRotatef(1.0, 5.0, 0.0, 0.0);
            break;
    }
    display(); // Memanggil fungsi display untuk merender ulang
    // glutPostRedisplay(); // Tidak diperlukan di sini karena kita sudah memanggil display()
}

/* Fungsi utama: GLUT berjalan sebagai aplikasi konsol yang dimulai dari main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Menginisialisasi GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Mengaktifkan mode double buffering
    glutInitWindowSize(640, 480); // Mengatur lebar dan tinggi jendela awal
    glutInitWindowPosition(50, 50); // Menentukan sudut kiri atas jendela awal
    glutCreateWindow("Latihan 3D"); // Membuat jendela dengan judul yang diberikan
    glutDisplayFunc(display); // Mendaftarkan handler callback untuk event pengecatan jendela
    glutReshapeFunc(reshape); // Mendaftarkan handler callback untuk event resize jendela
    glutKeyboardFunc(keyboard); // Mendaftarkan handler callback untuk event keyboard
    initGL(); // Inisialisasi OpenGL
    glutMainLoop(); // Masuk ke dalam loop pemrosesan event tak terbatas
    return 0; // Akhiri program
}
