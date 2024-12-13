#include <GL/glut.h> // Mengimpor GLUT untuk pemrograman grafis

// Ukuran jendela
int windowWidth = 700, windowHeight = 700;

// Fungsi inisialisasi OpenGL
void init() {
    glEnable(GL_BLEND); // Mengaktifkan blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Mengatur fungsi blending
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Mengatur warna latar belakang (putih)
    glEnable(GL_DEPTH_TEST); // Mengaktifkan pengujian kedalaman
    glMatrixMode(GL_MODELVIEW); // Mengatur mode matriks ke MODELVIEW
}

// Fungsi untuk menggambar objek
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Menghapus buffer warna dan kedalaman

    // Mengatur warna dan transparansi untuk kuadrilateral
    glColor4f(1.0f, 0.0f, 0.0f, 0.5f); // Merah dengan transparansi 0.5
    glBegin(GL_QUADS); // Memulai menggambar quad
    glVertex3f(0.0, 0.0, 0.0); // Sudut kiri bawah
    glVertex3f(10.0, 0.0, 0.0); // Sudut kanan bawah
    glVertex3f(10.0, 20.0, 0.0); // Sudut kanan atas
    glVertex3f(0.0, 20.0, 0.0); // Sudut kiri atas
    glEnd(); // Mengakhiri penggambaran quad

    // Mengatur warna dan transparansi untuk bola
    glColor4f(0.0f, 0.0f, 1.0f, 0.5f); // Biru dengan transparansi 0.5
    glutSolidSphere(5.0, 200, 100); // Menggambar bola solid dengan radius 5.0
    glutSwapBuffers(); // Menukar buffer depan dan belakang (double buffering)
}

// Fungsi untuk menangani perubahan ukuran jendela
void reshape(int width, int height) {
    if (height == 0) height = 1; // Menghindari pembagian dengan nol
    glMatrixMode(GL_PROJECTION); // Mengatur mode matriks ke PROJECTION
    glLoadIdentity(); // Mengatur ulang matriks proyeksi
    // Mengatur proyeksi perspektif
    gluPerspective(45.0f, (float)width / (float)height, 1.0f, 400.0f); // fovy, aspect, zNear, zFar
    glMatrixMode(GL_MODELVIEW); // Kembali ke mode MODELVIEW
}

// Fungsi untuk menangani input dari keyboard
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        // Gerakan ke kiri
        case 'a':
        case 'A':
            glTranslatef(-1.0, 0.0, 0.0); // Pindah ke kiri
            break;
        // Gerakan ke kanan
        case 'd':
        case 'D':
            glTranslatef(1.0, 0.0, 0.0); // Pindah ke kanan
            break;
        // Gerakan ke depan
        case 'w':
        case 'W':
            glTranslatef(0.0, 0.0, 1.0); // Pindah ke depan
            break;
        // Gerakan ke belakang
        case 's':
        case 'S':
            glTranslatef(0.0, 0.0, -1.0); // Pindah ke belakang
            break;
        // Gerakan ke atas
        case 'q':
        case 'Q':
            glTranslatef(0.0, 1.0, 0.0); // Pindah ke atas
            break;
        // Gerakan ke bawah
        case 'e':
        case 'E':
            glTranslatef(0.0, -1.0, 0.0); // Pindah ke bawah
            break;
        // Putar ke kiri
        case 'j':
        case 'J':
            glRotatef(1.0, 0.0, -5.0, 0.0); // Rotasi ke kiri
            break;
        // Putar ke kanan
        case 'l':
        case 'L':
            glRotatef(1.0, 0.0, 5.0, 0.0); // Rotasi ke kanan
            break;
        // Putar ke samping kanan
        case 'i':
        case 'I':
            glRotatef(1.0, 0.0, 0.0, -5.0); // Rotasi ke samping kanan
            break;
        // Putar ke samping kiri
        case 'k':
        case 'K':
            glRotatef(1.0, 0.0, 0.0, 5.0); // Rotasi ke samping kiri
            break;
        // Putar ke atas
        case 'o':
        case 'O':
            glRotatef(1.0, -5.0, 0.0, 0.0); // Rotasi ke atas
            break;
        // Putar ke bawah
        case 'u':
        case 'U':
            glRotatef(1.0, 5.0, 0.0, 0.0); // Rotasi ke bawah
            break;
    }
    glutPostRedisplay(); // Meminta untuk merender ulang
}

// Fungsi utama
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Inisialisasi GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Mengatur mode tampilan menjadi double buffering dan RGB
    glutInitWindowSize(windowWidth, windowHeight); // Mengatur ukuran jendela
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - windowWidth) / 2, // Menempatkan jendela di tengah layar
                           (glutGet(GLUT_SCREEN_HEIGHT) - windowHeight) / 2);
    glutCreateWindow("Latihan 3D"); // Membuat jendela dengan judul
    init(); // Memanggil fungsi inisialisasi
    glutDisplayFunc(display); // Mendaftarkan fungsi display untuk render
    glutReshapeFunc(reshape); // Mendaftarkan fungsi reshape untuk ukuran jendela
    glutKeyboardFunc(keyboard); // Mendaftarkan fungsi keyboard untuk input
    glutMainLoop(); // Masuk ke dalam loop pemrosesan event tak terbatas
    return 0; // Menghentikan program
}
