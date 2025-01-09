#include <GL/glut.h>
#include <cmath>

// Variabel untuk rotasi
float angleX = 0.0;
float angleY = 0.0;
float scale = 1.0; // Faktor skala awal
float lightPos[] = {0.0, 5.0, 5.0, 1.0};
bool hidden = false;
float yPos = 1.0;


void init() {
    glClearColor(0.5, 0.7, 1.0, 1.0); // CYAN
    glEnable(GL_DEPTH_TEST);          

    //CAHAYA
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);               

    //GLfloat light_position[] = { 0.0, 5.0, 5.0, 1.0 };  
    //glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    // Mengatur intensitas cahaya ambient dan diffuse
    //GLfloat ambient_light[] = { 0.2, 0.2, 0.2, 1.0 }; 
    //glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);

    //GLfloat diffuse_light[] = { 1.0, 0.8, 0.0, 1.0 };  

    glEnable(GL_NORMALIZE);
}

void drawCartesius()
{
	glLineWidth(1.0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	
	glVertex3f(-50.0, 0.0, 0.0);
	glVertex3f(50.0, 0.0, 0.0);
	
	glVertex3f(0.0, -50.0, 0.0);
	glVertex3f(0.0, 50.0, 0.0);
	
	glVertex3f(0.0, 0.0, -50.0);
	glVertex3f(0.0, 0.0, 50.0);
	glEnd();
}

void drawCube(float x, float y, float z, float width, float height, float depth, float r, float g, float b) {
    glColor3f(r, g, b);
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(width, height, depth);

    // Front face
    glBegin(GL_QUADS);
        glNormal3f(0.0, 0.0, 1.0);
        glVertex3d(-0.5, -0.5,  0.5); // BAWAH KIRI
        glVertex3d( 0.5, -0.5,  0.5); // BAWAH KANAN
        glVertex3d( 0.5,  0.5,  0.5); // ATAS KANAN
        glVertex3d(-0.5,  0.5,  0.5); // ATAS KIRI
    glEnd();

    // Back face
    glBegin(GL_QUADS);
        glNormal3f(0.0, 0.0, -1.0);
        glVertex3d(-0.5, -0.5, -0.5); // BAWAH KIRI
        glVertex3d(-0.5,  0.5, -0.5); // ATAS KIRI
        glVertex3d( 0.5,  0.5, -0.5); // ATAS KANAN
        glVertex3d( 0.5, -0.5, -0.5); // BAWAH KANAN
    glEnd();

    // Left face
    glBegin(GL_QUADS);
        glNormal3f(-1.0, 0.0, 0.0);
        glVertex3d(-0.5, -0.5, -0.5); // BAWAH DEPAN
        glVertex3d(-0.5, -0.5,  0.5); // BAWAH BELAKANG
        glVertex3d(-0.5,  0.5,  0.5); // ATAS BELAKANG
        glVertex3d(-0.5,  0.5, -0.5); // ATAS DEPAN
    glEnd();

    // Right face
    glBegin(GL_QUADS);
        glNormal3f(1.0, 0.0, 0.0);
        glVertex3d(0.5, -0.5, -0.5); // BAWAH DEPAN
        glVertex3d(0.5,  0.5, -0.5); // ATAS DEPAN
        glVertex3d(0.5,  0.5,  0.5); // ATAS BELAKANG
        glVertex3d(0.5, -0.5,  0.5); // BAWAH BELAKANG
    glEnd();

    // Top face
    glBegin(GL_QUADS);
        glNormal3f(0.0, 1.0, 0.0);
        glVertex3d(-0.5,  0.5, -0.5); // DEPAN KIRI
        glVertex3d( 0.5,  0.5, -0.5); // DEPAN KANAN
        glVertex3d( 0.5,  0.5,  0.5); // BELAKANG KANAN
        glVertex3d(-0.5,  0.5,  0.5); // BELAKANG KIRI
    glEnd();

    // Bottom face
    glBegin(GL_QUADS);
        glNormal3f(0.0, -1.0, 0.0);
        glVertex3d(-0.5, -0.5, -0.5); // DEPAN KIRI
        glVertex3d(-0.5, -0.5,  0.5); // BELAKANG KIRI
        glVertex3d( 0.5, -0.5,  0.5); // BELAKANG KANAN
        glVertex3d( 0.5, -0.5, -0.5); // DEPAN KANAN
    glEnd();
    glPopMatrix();
}

void drawCandle(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);

    glColor3ub(255, 255, 255);  
    // LILIN
    glPushMatrix();
        glRotatef(-90.0, 1.0, 0.0, 0.0);
        GLUquadric *quadric = gluNewQuadric();
        gluCylinder(quadric, 0.1, 0.1, 0.5, 10, 10);
        gluDeleteQuadric(quadric); 
    glPopMatrix();

    glColor3ub(255, 165, 0);  
    glPushMatrix();
        glTranslatef(0.0, 0.5, 0.0); 
        
        // API
    glBegin(GL_TRIANGLES);
        // Segitiga 1
        glNormal3f(0.0, 0.0, 1.0);
        glVertex3d(0.0, 0.3, 0.0); // Puncak di atas
        glVertex3d(-0.1, 0.0, -0.1);
        glVertex3d( 0.1, 0.0, -0.1);

        // Segitiga 2
        glNormal3f(0.0, 0.0, 1.0);
        glVertex3d(0.0, 0.3, 0.0); // Puncak di atas
        glVertex3d(-0.1, 0.0,  0.1);
        glVertex3d(-0.1, 0.0, -0.1);

        // Segitiga 3
        glNormal3f(0.0, 0.0, 1.0);
        glVertex3d(0.0, 0.3, 0.0); // Puncak di atas
        glVertex3d( 0.1, 0.0,  0.1);
        glVertex3d(-0.1, 0.0,  0.1);

        // Segitiga 4
        glNormal3f(0.0, 0.0, 1.0);
        glVertex3d(0.0, 0.3, 0.0); // Puncak di atas
        glVertex3d( 0.1, 0.0, -0.1);
        glVertex3d( 0.1, 0.0,  0.1);
    glEnd();

    glPopMatrix();

    glPopMatrix();
}

void drawPlate(float x, float y, float z, float radius) {
    GLUquadric *quadric = gluNewQuadric();  // Deklarasi dan inisialisasi quadric
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    
    // Silinder
    gluCylinder(quadric, 5.0, 5.0, 0.1, 50, 50);

    // Disk bawah
    glPushMatrix();
    glTranslatef(0.0, 0.0, -0.1); // Geser sedikit ke bawah
    gluDisk(quadric, 0.0, 5.0, 50, 1); // Disk bawah
    glPopMatrix();

    // Disk atas
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.1); // Geser sedikit ke atas
    gluDisk(quadric, 0.0, 5.0, 50, 1); // Disk atas
    glPopMatrix();

    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 5.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Terapkan skala
    glTranslatef(0.0f, yPos, 0.0f);
    glScalef(scale, scale, scale);

    // ROTASI
    glRotatef(angleX, 1.0, 0.0, 0.0); 
    glRotatef(angleY, 0.0, 1.0, 0.0); 

    if (hidden) {
        drawCartesius();
    }

    drawPlate(0.0, 0.0, 0.0, 4.5);

    // KUE BAWAH
    drawCube(0.0, 0.5, 0.0, //X,Y,Z
             4.0, 1.0, 4.0, //L,T,DEPTH
             1.0, 0.5, 0.5); //RGB
    // KUE TENGAH
    drawCube(0.0, 1.5, 0.0, 
             3.0, 1.0, 3.0, 
             1.0, 0.7, 0.5); 
    // KUE ATAS
    drawCube(0.0, 2.5, 0.0, 
             2.0, 1.0, 2.0, 
             1.0, 0.9, 0.5); 

    //LILIN
    // Baris pertama
    drawCandle(-0.7, 3.0, 0.5); // Lilin kiri
    drawCandle( 0.0, 3.0, 0.5); // Lilin tengah
    drawCandle( 0.7, 3.0, 0.5); // Lilin kanan

    // Baris kedua 
    drawCandle(-0.7, 3.0, -0.5); // Lilin kiri
    drawCandle( 0.0, 3.0, -0.5); // Lilin tengah
    drawCandle( 0.7, 3.0, -0.5); // Lilin kanan



    glutSwapBuffers();
}


void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / h, 1.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
            angleY -= 5.0; // ROTASI KE KIRI
            break;
        case 'd':
            angleY += 5.0; // ROTASI KE KANAN
            break;
        case 'h': // Menampilkan atau menyembunyikan garis kartesius
            hidden = !hidden;
            break;
        case '+': // Zoom in
            scale += 0.1;
            break;
        case 'w' :
			yPos += 0.1;
			break;
		case 's' :
			yPos -= 0.1;
			break;
        case '-': // Zoom out
            if (scale > 0.1) scale -= 0.1; // Hindari skala negatif
            break;
    }
    glutPostRedisplay(); 
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("TB UAS KUE");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard); 

    glutMainLoop();
    return 0;
}
