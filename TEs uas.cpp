#include <GL/glut.h>
#include <cmath>

// Variabel untuk rotasi
float rotX = 0.0;
float rotY = 0.0;
float scale = 1.0; 
bool hidden = false;
float xPos = 0.0;
float yPos = 0.0;
float zPos = 0.0;
float cameraX = 0.0f, cameraY = 0.0f, cameraZ = 5.0f; // Posisi kamera

void init() {
    glClearColor(0.5, 0.7, 1.0, 1.0); // CYAN
    glEnable(GL_DEPTH_TEST); 
    glEnable(GL_COLOR_MATERIAL); // Mengaktifkan material warna

    //CAHAYA
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);               

    GLfloat ambient_light[] = { 0.3, 0.3, 0.3, 1.0 }; // Cahaya ambient
    GLfloat diffuse_light[] = { 0.8, 0.8, 0.8, 1.0 }; // Cahaya diffuse
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);

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

//Gupita
void drawCube(float x, float y, float z, float width, float height, float depth, float r, float g, float b) {
    glColor3f(r, g, b);
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(width, height, depth);

    // Front face
    glBegin(GL_QUADS);
        glNormal3f(0.0, 0.0, 1.0);
        glVertex3d(-0.5, -0.5, 0.5); // BAWAH KIRI
        glVertex3d( 0.5, -0.5, 0.5); // BAWAH KANAN
        glVertex3d( 0.5, 0.5, 0.5); // ATAS KANAN
        glVertex3d(-0.5, 0.5, 0.5); // ATAS KIRI
    glEnd();

    // Back face
    glBegin(GL_QUADS);
        glNormal3f(0.0, 0.0, -1.0);
        glVertex3d(-0.5, -0.5, -0.5); // BAWAH KIRI
        glVertex3d(-0.5, 0.5, -0.5); // ATAS KIRI
        glVertex3d( 0.5, 0.5, -0.5); // ATAS KANAN
        glVertex3d( 0.5, -0.5, -0.5); // BAWAH KANAN
    glEnd();

    // Left face
    glBegin(GL_QUADS);
        glNormal3f(-1.0, 0.0, 0.0);
        glVertex3d(-0.5, -0.5, -0.5); // BAWAH DEPAN
        glVertex3d(-0.5, -0.5, 0.5); // BAWAH BELAKANG
        glVertex3d(-0.5, 0.5, 0.5); // ATAS BELAKANG
        glVertex3d(-0.5, 0.5, -0.5); // ATAS DEPAN
    glEnd();

    // Right face
    glBegin(GL_QUADS);
        glNormal3f(1.0, 0.0, 0.0);
        glVertex3d(0.5, -0.5, -0.5); // BAWAH DEPAN
        glVertex3d(0.5, 0.5, -0.5); // ATAS DEPAN
        glVertex3d(0.5, 0.5, 0.5); // ATAS BELAKANG
        glVertex3d(0.5, -0.5, 0.5); // BAWAH BELAKANG
    glEnd();

    // Top face
    glBegin(GL_QUADS);
        glNormal3f(0.0, 1.0, 0.0);
        glVertex3d(-0.5, 0.5, -0.5); // DEPAN KIRI
        glVertex3d( 0.5, 0.5, -0.5); // DEPAN KANAN
        glVertex3d( 0.5, 0.5, 0.5); // BELAKANG KANAN
        glVertex3d(-0.5, 0.5, 0.5); // BELAKANG KIRI
    glEnd();

    // Bottom face
    glBegin(GL_QUADS);
        glNormal3f(0.0, -1.0, 0.0);
        glVertex3d(-0.5, -0.5, -0.5); // DEPAN KIRI
        glVertex3d(-0.5, -0.5, 0.5); // BELAKANG KIRI
        glVertex3d( 0.5, -0.5, 0.5); // BELAKANG KANAN
        glVertex3d( 0.5, -0.5, -0.5); // DEPAN KANAN
    glEnd();
    glPopMatrix();
}

//Gupita
void drawCandle(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);

    glColor3f(255, 255, 255);
   
    // LILIN
    glPushMatrix();
        glRotatef(-90.0, 1.0, 0.0, 0.0);
        GLUquadric *quadric = gluNewQuadric();
        gluCylinder(quadric, 0.1, 0.1, 0.5, 10, 10);//quadric, baseRadius, topRadius, height, slices, stacks
        gluDeleteQuadric(quadric); 
    glPopMatrix();

    glColor3f(1.0, 0.65, 0.0); // Warna oranye  
    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0); 
        
    // API
	glBegin(GL_TRIANGLES);
	
	// Segitiga 1
	glNormal3f(0.0, 0.6, -0.8);
	glVertex3d(0.0, 0.3, 0.0); // Puncak di atas
	glVertex3d(-0.1, 0.0, -0.1);
	glVertex3d(0.1, 0.0, -0.1);
	
	// Segitiga 2
	glNormal3f(-0.8, 0.6, 0.0);
	glVertex3d(0.0, 0.3, 0.0); // Puncak di atas
	glVertex3d(-0.1, 0.0, 0.1);
	glVertex3d(-0.1, 0.0, -0.1);
	
	// Segitiga 3
	glNormal3f(0.0, 0.6, 0.8);
	glVertex3d(0.0, 0.3, 0.0); // Puncak di atas
	glVertex3d(0.1, 0.0, 0.1);
	glVertex3d(-0.1, 0.0, 0.1);
	
	// Segitiga 4
	glNormal3f(0.8, 0.6, 0.0);
	glVertex3d(0.0, 0.3, 0.0); // Puncak di atas
	glVertex3d(0.1, 0.0, -0.1);
	glVertex3d(0.1, 0.0, 0.1);
	
	glEnd();


    glPopMatrix();

    glPopMatrix();
}

//Sep Naufal
void drawPlate(float x, float y, float z, float radius) {
    GLUquadric *quadric = gluNewQuadric(); // Deklarasi dan inisialisasi quadric
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    
    // Silinder
    gluCylinder(quadric, 5.0, 5.0, 0.1, 50, 1);

    // Disk atas
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.1); 
    gluDisk(quadric, 0.0, 5.0, 50, 1); // Disk atas
    glPopMatrix();

    // Disk bawah
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0); 
    gluDisk(quadric, 0.0, 5.0, 50, 1); // Disk bawah
    glPopMatrix();

    glPopMatrix();
}

//Sep Naufal
void tutup() {
    GLUquadric* quadric = gluNewQuadric(); // Membuat objek quadric
    
    glPushMatrix(); 

    glColor4f(1.0, 1.0, 1.0, 0.5);
    glTranslatef(0.0, 0.0, 0.0); // Memindahkan posisi silinder (opsional)
    glRotatef(-90.0, 1.0, 0.0, 0.0); // Merotasi silinder agar tegak
    gluCylinder(quadric, 4.0, 2.0, 4.0, 50, 1); // Silinder dengan radius 5.0, tinggi 0.1, dan detail 50 segmen

	// Disk atas
    glPushMatrix();
    glTranslatef(0.0, 0.0, 4.0); 
    gluDisk(quadric, 0.0, 2.0, 50, 1); // Disk atas
    glPopMatrix();
    
    glPopMatrix(); 
    gluDeleteQuadric(quadric); 
}

//Sep Naufal
void kaki(float x, float y, float z, float radius, float height, float r, float g, float b) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glColor3f(r, g, b);
    GLUquadric *quadric = gluNewQuadric();

    // Silinder (kaki meja)
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    gluCylinder(quadric, radius, radius, height, 20, 20);

    // Lingkaran bawah
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0); 
    gluDisk(quadric, 0.0, radius, 20, 1);
    glPopMatrix();

    // Lingkaran atas
    glPushMatrix();
    glTranslatef(0.0, 0.0, height); 
    gluDisk(quadric, 0.0, radius, 20, 1);
    glPopMatrix();

    gluDeleteQuadric(quadric);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 5.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glTranslatef(cameraX, cameraY, -cameraZ);
    glRotatef(xPos, 1, 0, 0);
    glRotatef(zPos, 0, 0, 1);
    
    GLfloat lightPosition[] = {10.0, 10.0, 0.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    glPushMatrix();
    glRotatef(rotX, 1.0, 0.0, 0.0); 
    glRotatef(rotY, 0.0, 1.0, 0.0); 
    
    glScalef(scale, scale, scale);

	 if (hidden) {
        drawCartesius();
    }
	
    // Kue bawah
    drawCube(0.0, 0.5, 0.0, 4.0, 1.0, 4.0, 1.0, 0.5, 0.5); 
    // KUE TENGAH
    drawCube(0.0, 1.5, 0.0, 3.0, 1.0, 3.0, 1.0, 0.7, 0.5);
    // KUE ATAS
    drawCube(0.0, 2.5, 0.0, 2.0, 1.0, 2.0, 1.0, 0.9, 0.5); 

    //LILIN
    drawCandle(-0.7, 3.0, 0.5); // Lilin kiri
    drawCandle( 0.0, 3.0, 0.5); // Lilin tengah
    drawCandle( 0.7, 3.0, 0.5); // Lilin kanan

    drawCandle(-0.7, 3.0, -0.5); // Lilin kiri
    drawCandle( 0.0, 3.0, -0.5); // Lilin tengah
    drawCandle( 0.7, 3.0, -0.5); // Lilin kanan

	//HIASAN TINGKAT 3
	//PART1
    //DEPAN
    glPushMatrix();
    glTranslatef(3.0, 3.0, 1.0);
    glRotatef(90.0, 0.0, 0.0, 1.0); // Rotasi kaki agar Horizontal (opsional)
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 2.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
    //BELAKANG
    glPushMatrix();
    glTranslatef(3.0, 3.0, -1.0);
    glRotatef(90.0, 0.0, 0.0, 1.0); 
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 2.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
    //KANAN
    glPushMatrix();
    glTranslatef(1.0, 3.0, -3.0);
    glRotatef(90.0, 1.0, 0.0, 0.0); 
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 2.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
	//KIRI
	glPushMatrix();
    glTranslatef(-1.0, 3.0, -3.0);
    glRotatef(90.0, 1.0, 0.0, 0.0); 
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 2.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
    
    //PART2
    //DEPAN
    glPushMatrix();
    glTranslatef(3.0, 2.5, 1.0);
    glRotatef(90.0, 0.0, 0.0, 1.0); 
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 2.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
    //BELAKANG
    glPushMatrix();
    glTranslatef(3.0, 2.5, -1.0);
    glRotatef(90.0, 0.0, 0.0, 1.0); 
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 2.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
    //KANAN
    glPushMatrix();
    glTranslatef(1.0, 2.5, -3.0);
    glRotatef(90.0, 1.0, 0.0, 0.0); 
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 2.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
	//KIRI
	glPushMatrix();
    glTranslatef(-1.0, 2.5, -3.0);
    glRotatef(90.0, 1.0, 0.0, 0.0); 
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 2.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
    
    //HIASAN TINGKAT 2
    //PART1
    //DEPAN
    glPushMatrix();
    glTranslatef(3.5, 2.0, 1.5);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 3.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
    //BELAKANG
    glPushMatrix();
    glTranslatef(3.5, 2.0, -1.5);
    glRotatef(90.0, 0.0, 0.0, 1.0); 
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 3.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
    //KANAN
    glPushMatrix();
    glTranslatef(1.5, 2.0, -3.5);
    glRotatef(90.0, 1.0, 0.0, 0.0); 
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 3.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
	//KIRI
	glPushMatrix();
    glTranslatef(-1.5, 2.0, -3.5);
    glRotatef(90.0, 1.0, 0.0, 0.0); 
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 3.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
    
    //PART2
    //DEPAN BAWAH
    glPushMatrix();
    glTranslatef(3.5, 1.5, 1.5);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 3.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
    //BELAKANG BAWAH
    glPushMatrix();
    glTranslatef(3.5, 1.5, -1.5);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 3.0, 0.5, 0.3, 0.1);
    glPopMatrix();
    //KANAN BAWAH
    glPushMatrix();
    glTranslatef(1.5, 1.5, -3.5);
    glRotatef(90.0, 1.0, 0.0, 0.0); 
    glColor3f(0.5, 0.3, 0.1);
    kaki(0.0, 2.0, 0.0, 0.1, 3.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
	//KIRI BAWAH
	glPushMatrix();
    glTranslatef(-1.5, 1.5, -3.5);
    glRotatef(90.0, 1.0, 0.0, 0.0); 
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 3.0, 0.5, 0.3, 0.1);
    glPopMatrix();
    
    //HIASAN TINGKAT 1
    //DEPAN
    glPushMatrix();
    glTranslatef(4.0, 1.0, 2.0);
    glRotatef(90.0, 0.0, 0.0, 1.0); 
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 4.0, 0.5, 0.3, 0.1);
    glPopMatrix();
    //BELAKANG
    glPushMatrix();
    glTranslatef(4.0, 1.0, -2.0);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 4.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
    //KANAN
    glPushMatrix();
    glTranslatef(2.0, 1.0, -4.0);
    glRotatef(90.0, 1.0, 0.0, 0.0); 
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 4.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
	//KIRI
	glPushMatrix();
    glTranslatef(-2.0, 1.0, -4.0);
    glRotatef(90.0, 1.0, 0.0, 0.0); 
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 4.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
    
    //PART2
    //DEPAN
    glPushMatrix();
    glTranslatef(4.0, 0.5, 2.0);
    glRotatef(90.0, 0.0, 0.0, 1.0); 
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 4.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
    //BELAKANG
    glPushMatrix();
    glTranslatef(4.0, 0.5, -2.0);
    glRotatef(90.0, 0.0, 0.0, 1.0); 
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 4.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
    //KANAN
    glPushMatrix();
    glTranslatef(2.0, 0.5, -4.0);
    glRotatef(90.0, 1.0, 0.0, 0.0); 
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 4.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
	//KIRI
	glPushMatrix();
    glTranslatef(-2.0, 0.5, -4.0);
    glRotatef(90.0, 1.0, 0.0, 0.0); 
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 4.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
    
    //PART3
    //DEPAN
    glPushMatrix();
    glTranslatef(4.0, 0.0, 2.0);
    glRotatef(90.0, 0.0, 0.0, 1.0); 
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 4.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
    //BELAKANG
    glPushMatrix();
    glTranslatef(4.0, 0.0, -2.0);
    glRotatef(90.0, 0.0, 0.0, 1.0); 
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 4.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
    //KANAN
    glPushMatrix();
    glTranslatef(2.0, 0.0, -4.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);  
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 4.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
	//KIRI
	glPushMatrix();
    glTranslatef(-2.0, 0.0, -4.0);
    glRotatef(90.0, 1.0, 0.0, 0.0); 
    glColor3f(0.5, 0.3, 0.1); 
    kaki(0.0, 2.0, 0.0, 0.1, 4.0, 0.5, 0.3, 0.1); 
    glPopMatrix();
    
    
    glPopMatrix();

	glPushMatrix();
    //PIRING
    drawPlate(0.0, -0.2, 0.0, 0.0);
    glPopMatrix();
    
	glPushMatrix();
    // KAKI MEJA
    kaki(-3.0, -4.2, -3.0, 0.3, 4.0, 0.5, 0.3, 0.1);
    kaki( 3.0, -4.2, -3.0, 0.3, 4.0, 0.5, 0.3, 0.1);
    kaki(-3.0, -4.2, 3.0, 0.3, 4.0, 0.5, 0.3, 0.1);
    kaki( 3.0, -4.2, 3.0, 0.3, 4.0, 0.5, 0.3, 0.1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0f, yPos, 0.0f);
    glTranslatef(0.0, -0.1, 0.0); 
    tutup(); 

    glPopMatrix();
	

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
            rotY -= 5.0; // ROTASI KE KIRI
            break;
        case 'd':
            rotY += 5.0; // ROTASI KE KANAN
            break;
        case 'h': 
            hidden = !hidden; // HIDDEN KARTESIUS
            break;
        case '+': 
            scale += 0.1; // +++++
            break;
        case 'w' : 
            yPos += 5.1; // TRANSLATTED ATAS
            break;
        case 's' :
            yPos -= 5.1; // TRANSLATED BAWAH
            break;
        case 'q':
            xPos = xPos + 5; //ROTASI KE ATAS
            if (xPos > 360)
                xPos = 0;
            break;
        break;
        case 'e':
            xPos = xPos - 5; //ROTASI KEBAWAh
            if (xPos > 360)
                xPos = 0;
            break;
        case '-': 
            scale -= 0.1; // ------
            break;
        case 'i': // Maju
            cameraZ -= 0.5f;
            break;
        case 'k': // Mundur
            cameraZ += 0.5f;
            break;
        case 'j': // Geser kiri
            cameraX -= 0.5f;
            break;
        case 'l': // Geser kanan
            cameraX += 0.5f;
            break;
    }
    glutPostRedisplay(); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("TB UAS KUE");
    glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard); 

    glutMainLoop();
    return 0;
}
