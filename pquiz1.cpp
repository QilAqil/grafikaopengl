#include <GL/glut.h> // Mengimpor GLUT untuk pemrograman grafis

// Variabel global
int x = 200; // Posisi horizontal objek
bool kanan = true; // Variabel untuk mengatur arah gerakan

// Fungsi inisialisasi OpenGL
void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0); // Mengatur warna latar belakang menjadi putih
    gluOrtho2D(0.0, 800.0, 0.0, 600.0); // Mengatur sistem koordinat 2D
}

/* Fungsi idle (tidak digunakan dalam kode ini)
void idle() {
    glutPostRedisplay(); // Meminta untuk merender ulang saat idle
}*/

// Fungsi timer untuk mengatur pembaruan tampilan
void timer(int value) {
    glutPostRedisplay(); // Meminta untuk merender ulang
    glutTimerFunc(10, timer, 0); // Memanggil timer lagi setelah 10 ms
}

// Fungsi untuk menggambar objek
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Menghapus buffer warna

    // Mengupdate posisi objek berdasarkan arah gerakan (kanan atau kiri)
    if (kanan) {
        x++; // Jika bergerak ke kanan, tambahkan ke posisi
        glTranslatef(1.0, 0.0, 0.0); // Menerapkan tranlasi ke kanan
        if (x > 600) { // Jika melewati batas kanan
            kanan = false; // Ubah arah gerakan ke kiri
        }
    } else {
        x--; // Jika bergerak ke kiri, kurangi posisi
        glTranslatef(-1.0, 0.0, 0.0); // Menerapkan translasi ke kiri
        if (x < 0) { // Jika melewati batas kiri
            kanan = true; // Ubah arah gerakan ke kanan
        }
    }

    // Menggambar kuadrilateral (persegi) berwarna merah
    glColor3f(1.0, 0.0, 0.0); // Mengatur warna objek menjadi merah
    glBegin(GL_QUADS); // Memulai menggambar quad
    glVertex2f(200.0, 200.0); // Sudut kiri bawah
    glVertex2f(200.0, 400.0); // Sudut kiri atas
    glVertex2f(400.0, 400.0); // Sudut kanan atas
    glVertex2f(400.0, 200.0); // Sudut kanan bawah
    glEnd(); // Mengakhiri penggambaran quad

    glutSwapBuffers(); // Menukar buffer depan dan belakang (double buffering)
}

// Fungsi utama
int main(int argc, char** argv) { // Mengubah void menjadi int untuk standar C++
    glutInit(&argc, argv); // Menginisialisasi GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Mengatur mode tampilan menjadi double buffering dan RGB
    glutInitWindowSize(800, 600); // Mengatur ukuran jendela
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 800) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 600) / 2); // Menempatkan jendela di tengah layar
    glutCreateWindow("Percobaan Pertama Saya"); // Membuat jendela dengan judul
    
    init(); // Pemanggilan fungsi inisialisasi
    glutDisplayFunc(display); // Mendaftarkan fungsi display untuk render
    // glutIdleFunc(idle); // Tidak digunakan
    glutTimerFunc(0, timer, 0); // Memulai timer
    glutMainLoop(); // Masuk ke dalam loop pemrosesan event tak terbatas
    return 0; // Mengembalikan 0 untuk menunjukkan program berakhir dengan sukses
}
