#include <GL/glut.h>
#include <stdio.h>

// Ukuran window
int windowWidth = 700, windowHeight = 700;
bool color = true; // Variabel untuk menentukan warna

// Fungsi inisialisasi
void init() {
    glEnable(GL_BLEND); // Mengaktifkan blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Mengatur fungsi blending
    glClearColor(0.0, 0.0, 0.0, 0.0); // Mengatur warna latar belakang (hitam)
    glEnable(GL_DEPTH_TEST); // Mengaktifkan pengujian kedalaman
    glMatrixMode(GL_MODELVIEW); // Mengatur mode matriks ke MODELVIEW
}

// Fungsi untuk menggambar objek
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Menghapus buffer warna dan kedalaman
    glBegin(GL_QUADS); // Memulai penggambaran quad

    // Menggambar quad dengan warna berdasarkan nilai `color`
    if (color) {
        glColor3f(1.0, 0.0, 0.0); // Merah jika `color` true
    } else {
        glColor3f(1.0, 1.0, 1.0); // Putih jika `color` false
    }
    // Top face
    glVertex3f( 1.0f, -1.0f, -13.0f);
    glVertex3f(-1.0f, -1.0f, -13.0f);
    glVertex3f(-1.0f, -1.0f, -11.0f);
    glVertex3f( 1.0f, -1.0f, -11.0f);

    // Bottom face
    if (color) {
        glColor3f(1.0, 0.0, 0.0); // Merah lagi untuk bottom face
    } else {
        glColor3f(1.0, 1.0, 1.0); // Putih
    }
    glVertex3f( 1.0f, -3.0f, -13.0f);
    glVertex3f(-1.0f, -3.0f, -13.0f);
    glVertex3f(-1.0f, -3.0f, -11.0f);
    glVertex3f( 1.0f, -3.0f, -11.0f);

    // Front face
    if (color) {
        glColor3f(0.0, 1.0, 0.0); // Hijau untuk front face
    } else {
        glColor3f(1.0, 1.0, 1.0); // Putih
    }
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -11.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -11.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -3.0f, -11.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -3.0f, -11.0f);

    // Back face
    if (color) {
        glColor3f(0.0, 1.0, 0.0); // Hijau untuk back face
    } else {
        glColor3f(1.0, 1.0, 1.0); // Putih
    }
    glVertex3f( 1.0f, -3.0f, -13.0f);
    glVertex3f(-1.0f, -3.0f, -13.0f);
    glVertex3f(-1.0f, -1.0f, -13.0f);
    glVertex3f( 1.0f, -1.0f, -13.0f);

    // Left face
    if (color) {
        glColor3f(0.0, 0.0, 1.0); // Biru untuk left face
    } else {
        glColor3f(1.0, 1.0, 1.0); // Putih
    }
    glVertex3f(-1.0f, -1.0f, -11.0f);
    glVertex3f(-1.0f, -1.0f, -13.0f);
    glVertex3f(-1.0f, -3.0f, -13.0f);
    glVertex3f(-1.0f, -3.0f, -11.0f);

    // Right face
    if (color) {
        glColor3f(0.0, 0.0, 1.0); // Biru untuk right face
    } else {
        glColor3f(1.0, 1.0, 1.0); // Putih
    }
    glVertex3f(1.0f, -1.0f, -13.0f);
    glVertex3f(1.0f, -1.0f, -11.0f);
    glVertex3f(1.0f, -3.0f, -11.0f);
    glVertex3f(1.0f, -3.0f, -13.0f);

    glEnd(); // Mengakhiri penggambaran quad
    glutSwapBuffers(); // Menukar buffer untuk menampilkan frame yang baru dirender
}

// Fungsi untuk menangani perubahan ukuran jendela
void reshape(int width, int height) {
    if(height == 0) height = 1; // Menghindari pembagian dengan nol
    glMatrixMode(GL_PROJECTION); // Mengatur mode matriks untuk proyeksi
    glLoadIdentity(); // Mengatur ulang matriks proyeksi
    gluPerspective(45.0, width / height, 1.0, 400.0); // Mengatur perspektif
    glMatrixMode(GL_MODELVIEW); // Kembali ke MODELVIEW
}

// Fungsi untuk menangani input dari keyboard
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        // Gerakan ke kiri
        case 'a':
        case 'A':
            glTranslatef(-1.0, 0.0, 0.0);
            break;
        // Gerakan ke kanan
        case 'd':
        case 'D':
            glTranslatef(1.0, 0.0, 0.0);
            break;
        // Gerakan ke depan
        case 'w':
        case 'W':
            glTranslatef(0.0, 0.0, 1.0);
            break;
        // Gerakan ke belakang
        case 's':
        case 'S':
            glTranslatef(0.0, 0.0, -1.0);
            break;
        // Gerakan ke atas
        case 'q':
        case 'Q':
            glTranslatef(0.0, 1.0, 0.0);
            break;
        // Gerakan ke bawah
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
    glutPostRedisplay(); // Meminta untuk merender ulang
}

// Fungsi untuk menangani event mouse
void mouse(int button, int state, int x, int y) {
    // Jika tombol kiri mouse ditekan
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        color = false; // Ubah warna menjadi tidak berwarna
    } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        color = true; // Kembalikan warna menjadi normal
    }
    glutPostRedisplay(); // Meminta untuk merender ulang
}

// Titik awal program
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Inisialisasi GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Mengatur mode tampilan
    glutInitWindowSize(windowWidth, windowHeight); // Mengatur ukuran window
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - windowWidth) / 2, 
                            (glutGet(GLUT_SCREEN_HEIGHT) - windowHeight) / 2);
    glutCreateWindow("Latihan 3D"); // Membuat window dengan judul
    init(); // Panggil fungsi inisialisasi
    glutDisplayFunc(display); // Daftarkan fungsi display
    glutReshapeFunc(reshape); // Daftarkan fungsi reshape
    glutKeyboardFunc(keyboard); // Daftarkan fungsi keyboard
    glutMouseFunc(mouse); // Daftarkan fungsi mouse
    glutMainLoop(); // Masuk ke loop utama GLUT
}
