#include <GL/glut.h>

int windowWidth = 700, windowHeight = 700; // Ukuran jendela
GLuint *texid = new GLuint[2]; // Array untuk menyimpan ID tekstur
GLuint texwidth = 4; // Lebar tekstur
GLuint texheight = 1; // Tinggi tekstur

// Data tekstur untuk tekstur 1
GLubyte texData[16] = {
    0xFF, 0x00, 0x00, 0xFF, // Merah
    0x00, 0xFF, 0x00, 0xFF, // Hijau
    0x00, 0x00, 0xFF, 0xFF, // Biru
    0xFF, 0xFF, 0xFF, 0xFF  // Putih
};

// Data tekstur untuk tekstur 2
GLubyte texData2[16] = {
    0x00, 0xFF, 0x00, 0xFF, // Hijau
    0x00, 0xFF, 0x00, 0xFF, // Hijau
    0x00, 0x00, 0xFF, 0xFF, // Biru
    0xFF, 0xFF, 0xFF, 0xFF  // Putih
};

// Fungsi untuk inisialisasi tekstur
void InitTexture() {
    glEnable(GL_TEXTURE_2D); // Mengaktifkan tekstur 2D
    glGenTextures(2, texid); // Menghasilkan 2 ID tekstur

    // Set Textur 1 (index 0)
    glBindTexture(GL_TEXTURE_2D, texid[0]); // Mengikat ID tekstur 0
    glTexImage2D(GL_TEXTURE_2D, 0, 4, texwidth, texheight, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData); // Membuat tekstur
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // Mengatur filter min
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // Mengatur filter maks

    // Set Textur 2 (index 1)
    glBindTexture(GL_TEXTURE_2D, texid[1]); // Mengikat ID tekstur 1
    glTexImage2D(GL_TEXTURE_2D, 0, 4, texwidth, texheight, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData2); // Membuat tekstur
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // Mengatur filter min
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // Mengatur filter maks
}

// Fungsi untuk inisialisasi OpenGL
void init() {
    glEnable(GL_BLEND); // Mengaktifkan blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Mengatur fungsi blending
    glClearColor(0.0, 0.0, 0.0, 0.0); // Mengatur warna latar belakang
    glEnable(GL_DEPTH_TEST); // Mengaktifkan pengujian kedalaman
    glMatrixMode(GL_MODELVIEW); // Mengatur mode matriks
    InitTexture(); // Memanggil fungsi inisialisasi tekstur
}

// Fungsi untuk menggambar objek
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Menghapus buffer warna dan kedalaman

    // Menggambar objek pertama dengan tekstur 1 (index 0)
    glBindTexture(GL_TEXTURE_2D, texid[0]); // Mengikat tekstur 1
    glBegin(GL_QUADS); // Memulai menggambar quad

    // Koordinat untuk quad pertama
    // Top face
    glVertex3f(1.0f, -1.0f, -8.0f);
    glVertex3f(-1.0f, -1.0f, -8.0f);
    glVertex3f(-1.0f, -1.0f, -6.0f);
    glVertex3f(1.0f, -1.0f, -6.0f);
    // Bottom face
    glVertex3f(1.0f, -3.0f, -6.0f);
    glVertex3f(-1.0f, -3.0f, -6.0f);
    glVertex3f(-1.0f, -3.0f, -8.0f);
    glVertex3f(1.0f, -3.0f, -8.0f);
    
    // Front face
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, -1.0f, -6.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -6.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -3.0f, -6.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -3.0f, -6.0f);

    // Back face
    glVertex3f(1.0f, -3.0f, -8.0f);
    glVertex3f(-1.0f, -3.0f, -8.0f);
    glVertex3f(-1.0f, -1.0f, -8.0f);
    glVertex3f(1.0f, -1.0f, -8.0f);

    // Koordinat untuk sisi lainnya
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
    
    glEnd(); // Mengakhiri penggambaran quad

    // Menggambar objek kedua dengan tekstur 2 (index 1)
    glBindTexture(GL_TEXTURE_2D, texid[1]); // Mengikat tekstur 2
    glBegin(GL_QUADS); // Memulai menggambar quad

    // Koordinat untuk quad kedua
    // Top face
    glVertex3f(1.0f, -1.0f, -13.0f);
    glVertex3f(-1.0f, -1.0f, -13.0f);
    glVertex3f(-1.0f, -1.0f, -11.0f);
    glVertex3f(1.0f, -1.0f, -11.0f);
    // Bottom face
    glVertex3f(1.0f, -3.0f, -13.0f);
    glVertex3f(-1.0f, -3.0f, -13.0f);
    glVertex3f(-1.0f, -3.0f, -11.0f);
    glVertex3f(1.0f, -3.0f, -11.0f);
    
    // Front face
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, -1.0f, -11.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -11.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -3.0f, -11.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -3.0f, -11.0f);
    
    // Back face
    glVertex3f(1.0f, -3.0f, -13.0f);
    glVertex3f(-1.0f, -3.0f, -13.0f);
    glVertex3f(-1.0f, -1.0f, -13.0f);
    glVertex3f(1.0f, -1.0f, -13.0f);

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
    
    glEnd(); // Mengakhiri penggambaran quad
    glutSwapBuffers(); // Menukar buffer untuk menampilkan gambar baru
}

// Fungsi untuk menangani perubahan ukuran jendela
void reshape(int width, int height) {
    if (height == 0) height = 1; // Menghindari pembagian dengan nol
    glMatrixMode(GL_PROJECTION); // Mengatur mode matriks ke proyeksi
    glLoadIdentity(); // Mengatur ulang matriks proyeksi
    gluPerspective(45.0, width / height, 1.0, 400.0); // Menentukan perspektif
    glMatrixMode(GL_MODELVIEW); // Kembali ke mode model view
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
    glutMainLoop(); // Masuk ke loop utama GLUT
}
