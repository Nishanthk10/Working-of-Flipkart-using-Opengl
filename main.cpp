

#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>

#define PI 3.142
GLint m_viewport[4];
bool mButtonPressed = false;
float mouseX, mouseY;
GLfloat a = 0, b = 0, c = 0, d = 0, e = 0;
enum view { SCREEN1, SCREEN2, SCREEN3, SCREEN4, SCREEN5, SCREEN6, SCREEN7, SCREEN8, SCREEN9 };
view viewPage = SCREEN8; // initial value
bool keyStates[256] = { false };
GLint bc = 300;
float  counter = 600.0;
int shift = 0;
float buildingshift =1250 ;
float buildingvshift = -200;
float buildingshift1 = 1900;
float shiftdown = -50;
float counter1 = 300.0;
float counter2 = 600.0;
float counter3 = -200.0;
float ycounter = 0.0;
float txcounter = -600.0;
float tycounter = 0.0;
bool flag = 0;
float indi = 0.0;
float indi1 = 0.0;

// to draw text
void displayRasterText(float x, float y, float z, const char* stringToDisplay)
{
   

    glRasterPos3f(x, y, z);
    for (const char* c = stringToDisplay; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }


}
void displayRasterBigText(float x, float y, float z, const char* stringToDisplay)
{


    glRasterPos3f(x, y, z);
    for (const char* c = stringToDisplay; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }


}

//init method
void init()
{


    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1200, 1200, -700, 700);
    glMatrixMode(GL_MODELVIEW);


}

//key press operations defining
void keyOperations() {


    if (keyStates[13] == true && viewPage == SCREEN1) {
        viewPage = SCREEN2;
        printf("Enter key pressed\n");
    }
    if (keyStates['Q'] == true && viewPage == SCREEN2) {
        viewPage = SCREEN3;
        printf("Q key pressed\n");
    }
    if (keyStates['W'] == true && viewPage == SCREEN3) {
        viewPage = SCREEN4;
        printf("W key pressed\n");
    }
    if (keyStates['E'] == true && viewPage == SCREEN4) {
        viewPage = SCREEN5;
        printf("E key pressed\n");
    }
    if (keyStates['R'] == true && viewPage == SCREEN5) {
        viewPage = SCREEN6;
        printf("R key pressed\n");
    }
    if (keyStates['T'] == true && viewPage == SCREEN6) {
        viewPage = SCREEN7;
        printf("T key pressed\n");
    }
    if (keyStates['Y'] == true && viewPage == SCREEN7) {
        viewPage = SCREEN8;
        printf("Y key pressed\n");
    }
    if (keyStates['U'] == true && viewPage == SCREEN8) {
        viewPage = SCREEN9;
        printf("U key pressed\n");
    }
    if (keyStates['X'] == true && viewPage == SCREEN9) {
        exit(0);
    }


}


//drawfilledelipse 
void drawFilledelipse(GLfloat x, GLfloat y, GLfloat xcenter, GLfloat ycenter) //circle drawing
{


    int i;
    int triangleAmount = 20; //# of triangles used to draw circle
    GLfloat twicePi = 2.0f * PI;


    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + ((xcenter + 1) * cos(i * twicePi / triangleAmount)),
            y + ((ycenter - 1) * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();


}


//drawclouds
void drawClouds(int x, int y)
{


    glColor3f(255.0, 255.0, 255.0);
    drawFilledelipse(x, y, 80, 45);
    glColor3f(255.0, 255.0, 255.0);
    drawFilledelipse(x + 25, y + 15, 35, 35);
    glColor3f(255.0, 255.0, 255.0);
    drawFilledelipse(x + 25, y - 15, 35, 35);
    glColor3f(255.0, 255.0, 255.0);
    drawFilledelipse(x - 25, y - 15, 35, 35);
    glColor3f(255.0, 255.0, 255.0);
    drawFilledelipse(x - 25, y + 15, 35, 35);
}

void drawBlueClouds(int x, int y)
{


    glColor3f(0.67, 0.92, 0.99);
    drawFilledelipse(x, y, 80, 45);
    //glColor3f(255.0, 255.0, 255.0);
    //drawFilledelipse(x + 25, y + 15, 35, 35);
    //glColor3f(255.0, 255.0, 255.0);
    //drawFilledelipse(x + 25, y - 15, 35, 35);
    glColor3f(0.67, 0.92, 0.99);
    drawFilledelipse(x - 25, y - 15, 35, 35);
    glColor3f(0.67, 0.92, 0.99);
    drawFilledelipse(x - 25, y + 15, 35, 35);
}

//introscreen
void Screen1()
{
    glClearColor(0, 0, 0,0);
    glClear(GL_COLOR_BUFFER_BIT);



    glColor3f(1.0, 0, 0);
    displayRasterText(-450, 490, 0.0, "SAHYADRI COLLEGE OF ENGINEERING AND MANAGEMENT");

    glColor3f(1.0, 0, 0);
    displayRasterText(-230, 410, 0.0, "AN AUTONOMOUS INSTITUTE");

    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-450, 335, 0.0, "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");


    glColor3f(1.0, 0, 0);
    displayRasterText(-150, 250, 0.0, "A MINI PROJECT ON ");


    glColor3f(0.2, 0.5, 1.0);
    displayRasterText(-320, 175, 0.0, "WORKING OF FLIPKART USING OPENGL");


    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-100, 100, 0.0, "CREATED BY");


    glColor3f(1.0, 0, 0);
    displayRasterText(-800, -100, 0.0, " STUDENT NAMES");


    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-800, -200, 0.0, " NISHANTH K");
    displayRasterText(-800, -285, 0.0, " 4SF19CS107");
    displayRasterText(-800, -370, 0.0, " NEHA M");
    displayRasterText(-800, -455, 0.0, " 4SF19CS104");


    glColor3f(1.0, 0, 0);
    displayRasterText(500, -100, 0.0, "UNDER THE GUIDANCE OF");


    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(500, -200, 0.0, "MRS. VIDYA V V");


    glColor3f(1.0, 0, 0);
    displayRasterText(-250, -400, 0.0, "ACADEMIC YEAR 2021-2022");


    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-225, -550, 0.0, "PRESS ENTER TO START");


    glFlush();
    glutSwapBuffers();
}

void shirt(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0.07, 0.11, 0.34);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 28 * cos(th), y + 50 * sin(th));
    }

    glEnd();

}
void yshirt(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(1, 0.87, 0.17);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 35 * cos(th), y + 70 * sin(th));
    }

    glEnd();

}
void yshoe(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0.31, 0.11, 0.04);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 18 * cos(th), y + 15 * sin(th));
    }

    glEnd();

}
//menuscreen
void Screen2()
{
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(5);
    glColor3f(0.1, 0.1, 1.0);
    glBegin(GL_POLYGON);               //Nav
    glVertex2f(-1300,700);
    glVertex2f(1300, 700);
    glVertex2f(1300, 560);
    glVertex2f(-1300, 560);
    glEnd();


    glColor3f(1, 1, 1);   //Search
    glBegin(GL_POLYGON);
    glVertex2f(-900,675);
    glVertex2f(0, 675);
    glVertex2f(0, 585);
    glVertex2f(-900, 585);
    glEnd();

    displayRasterText(-1050, 625, 0.4, "Flipkart");
    glColor3f(0.4, 0.4, 0.4);
    displayRasterText(-850, 622, 0, "Search");

    glColor3f(1, 1, 1);   //Login
    glBegin(GL_POLYGON);
    glVertex2f(300, 675);
    glVertex2f(500, 675);
    glVertex2f(500, 585);
    glVertex2f(300, 585);
    glEnd();

    glColor3f(0, 0, 1);
    displayRasterText(353, 622, 0.4, "Login");
    glColor3f(1, 1, 1);
    displayRasterText(700, 622, 0, "More");
    glColor3f(1, 1, 1);
    displayRasterText(940, 622, 0, "Cart");


    glColor3f(0.8, 0.84, 0.27);
    glBegin(GL_POLYGON);                                //Mobile POLYGON
    glVertex2f(-1050, 300);
    glVertex2f(-450, 300);
    glVertex2f(-450, -300);
    glVertex2f(-1050, -300);
    glEnd();


    glColor3f(0.8, 0.84, 0.27);
    glBegin(GL_POLYGON);                                //Electronic POLYGON
    glVertex2f(-300, 300);
    glVertex2f(300, 300);
    glVertex2f(300, -300);
    glVertex2f(-300, -300);
    glEnd();

    glColor3f(0.8, 0.84, 0.27);
    glBegin(GL_POLYGON);                                //Fashion POLYGON
    glVertex2f(450, 300);
    glVertex2f(1050, 300);
    glVertex2f(1050, -300);
    glVertex2f(450, -300);
    glEnd();

    if (mouseX >= -450 && mouseX <= -350 && mouseY >= -100 && mouseY <= 100) {
        glColor3f(0, 0, 1);
        if (mButtonPressed) {
            viewPage = SCREEN3;
            mButtonPressed = false;
        }
    }
    else
        glColor3f(1, 1, 1);
    displayRasterBigText(-850, 0, 0.4, "Mobiles"); //Mobiles Text

   

    if (mouseX >= -100 && mouseX <= 100 && mouseY >= -100 && mouseY <= 100) {
        glColor3f(0, 0, 1);
        if (mButtonPressed) {
            viewPage = SCREEN3;


            mButtonPressed = false;
        }
    }
    else
        glColor3f(1, 1, 1);
    displayRasterBigText(-100, 0, 0.4, "Electronics"); //Electronics Text


    if (mouseX >= 350 && mouseX <= 450 && mouseY >= -100 && mouseY <= 100) {
        glColor3f(0, 0, 1);
        if (mButtonPressed) {
            viewPage = SCREEN3;
            mButtonPressed = false;
        }
    }
    else
        glColor3f(1, 1, 1);
    displayRasterBigText(680, 0, 0.4, "Fashion"); //Fashion Text


    glutPostRedisplay();
}

//instructionscreen

void Screen3() {


    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 1, 1);

    glLineWidth(5);
    glColor3f(0.1, 0.1, 1.0);
    glBegin(GL_POLYGON);               //Nav
    glVertex2f(-1300, 700);
    glVertex2f(1300, 700);
    glVertex2f(1300, 560);
    glVertex2f(-1300, 560);
    glEnd();


    glColor3f(1, 1, 1);   //Search
    glBegin(GL_POLYGON);
    glVertex2f(-900, 675);
    glVertex2f(0, 675);
    glVertex2f(0, 585);
    glVertex2f(-900, 585);
    glEnd();

    displayRasterText(-1050, 625, 0.4, "Flipkart");
    glColor3f(0.4, 0.4, 0.4);
    displayRasterText(-850, 622, 0, "Search");

    glColor3f(1, 1, 1);   //Login
    glBegin(GL_POLYGON);
    glVertex2f(300, 675);
    glVertex2f(500, 675);
    glVertex2f(500, 585);
    glVertex2f(300, 585);
    glEnd();

    glColor3f(0, 0, 1);
    displayRasterText(353, 622, 0.4, "Login");
    glColor3f(1, 1, 1);
    displayRasterText(700, 622, 0, "More");
    glColor3f(1, 1, 1);
    displayRasterText(940, 622, 0, "Cart");

    glColor3f(1, 0.23, 0);
    glBegin(GL_POLYGON);                                //Electronic POLYGON
    glVertex2f(-300, 70);
    glVertex2f(300, 70);
    glVertex2f(300, -65);
    glVertex2f(-300, -65);
    glEnd();

    if (mouseX >= -100 && mouseX <= 100 && mouseY >= -100 && mouseY <= 100) {
        glColor3f(0.61, 0.61, 0.61);
        if (mButtonPressed) {
            viewPage = SCREEN4;


            mButtonPressed = false;
        }
    }
    else
        glColor3f(1, 1, 1);
    displayRasterText(-120, -5, 0.4, "PLACE ORDER"); //Place Order Text

   


    glFlush();
    glutSwapBuffers();

}

void wheel(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 25 * cos(th), y + 25 * sin(th));
    }

    glEnd();

}

void gwheel(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0.11, 0.11, 0.11);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 28 * cos(th), y + 28 * sin(th));
    }

    glEnd();

}
void tree(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0.29, 0.61, 0.17);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 25 * cos(th), y + 25 * sin(th));
    }

    glEnd();

}

void whitewheel(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0.86, 0.86, 0.86);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 15 * cos(th), y + 15 * sin(th));
    }

    glEnd();

}
void gwhitewheel(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.38, 0.38);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 15 * cos(th), y + 15 * sin(th));
    }

    glEnd();

}

void car() {
    

    glColor3f(0.76, 0, 0); //Car
    glBegin(GL_POLYGON);
    glVertex2f(790, -650);
    glVertex2f(780, -600);
    glVertex2f(880, -600);
    glVertex2f(900, -550);
    glVertex2f(1040, -580);
    glVertex2f(1050, -590);
    glVertex2f(1100, -600);
    glVertex2f(1100, -640);
    glVertex2f(1090, -650);
    glEnd();

    glColor3f(0.27, 0.6, 0.76); //Glass
    glBegin(GL_POLYGON);
    glVertex2f(865, -600);
    glVertex2f(902, -560);
    glVertex2f(1035, -585);
    glVertex2f(1052, -600);
    glEnd();

    glLineWidth(5);
    glColor3f(0.76, 0, 0); //Glass
    glBegin(GL_LINES);
    glVertex2f(902, -600);
    glVertex2f(902, -560);
    glEnd();

    glLineWidth(5);
    glColor3f(0.76, 0, 0); //Glass
    glBegin(GL_LINES);
    glVertex2f(990, -600);
    glVertex2f(990, -570);
    glEnd();

    glLineWidth(8);
    glColor3f(1, 0.95, 0.64); //Light
    glBegin(GL_LINES);
    glVertex2f(782, -620);
    glVertex2f(800, -620);
    glEnd();

    glLineWidth(8);
    glColor3f(0.46, 0.01, 0.01); //Light
    glBegin(GL_LINES);
    glVertex2f(1100, -620);
    glVertex2f(1080, -620);
    glEnd();

    gwheel(870, -650);
    gwhitewheel(870, -650);
    gwheel(1020, -650);
    gwhitewheel(1020, -650);
    glutPostRedisplay();
}
void car1() {


    glColor3f(0.59, 0, 0.71); //Car
    glBegin(GL_POLYGON);
    glVertex2f(790, -650);
    glVertex2f(780, -600);
    glVertex2f(880, -600);
    glVertex2f(900, -550);
    glVertex2f(1040, -580);
    glVertex2f(1050, -590);
    glVertex2f(1100, -600);
    glVertex2f(1100, -640);
    glVertex2f(1090, -650);
    glEnd();

    glColor3f(0.27, 0.6, 0.76); //Glass
    glBegin(GL_POLYGON);
    glVertex2f(865, -600);
    glVertex2f(902, -560);
    glVertex2f(1035, -585);
    glVertex2f(1052, -600);
    glEnd();

    glLineWidth(5);
    glColor3f(0.59, 0, 0.71); //Glass
    glBegin(GL_LINES);
    glVertex2f(902, -600);
    glVertex2f(902, -560);
    glEnd();

    glLineWidth(5);
    glColor3f(0.59, 0, 0.71); //Glass
    glBegin(GL_LINES);
    glVertex2f(990, -600);
    glVertex2f(990, -570);
    glEnd();

    glLineWidth(8);
    glColor3f(1, 0.95, 0.64); //Light
    glBegin(GL_LINES);
    glVertex2f(782, -620);
    glVertex2f(800, -620);
    glEnd();

    glLineWidth(8);
    glColor3f(0.46, 0.01, 0.01); //Light
    glBegin(GL_LINES);
    glVertex2f(1100, -620);
    glVertex2f(1080, -620);
    glEnd();

    gwheel(870, -650);
    gwhitewheel(870, -650);
    gwheel(1020, -650);
    gwhitewheel(1020, -650);
    glutPostRedisplay();
}
void Screen4()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.55, 0.81, 1,0);

    drawClouds(550, 450);  //Clouds
    drawClouds(-350, 550);
    drawClouds(950, 450);
    drawClouds(-850, 550);

    glColor3f(0, 0.74, 0.39);  //Land
    glBegin(GL_POLYGON);
    glVertex2f(-1320, -500);
    glVertex2f(1320, -500);
    glVertex2f(1320, -720);
    glVertex2f(-1320, -720);
    glEnd();

    glColor3f(0.54, 0.54, 0.54);
    displayRasterText(-900, 200, 0, "PRESS E TO PROCEED");

    glColor3f(1, 0.86, 0.68); //Warehouse 1
    glBegin(GL_POLYGON);
    glVertex2f(-900, -500);
    glVertex2f(-900, -100);
    glVertex2f(-550, 0);
    glVertex2f(-200, -100);
    glVertex2f(-200, -500);
    glEnd();

    glColor3f(0.75, 0.18, 0);  //Roof 1
    glBegin(GL_POLYGON);
    glVertex2f(-550, 0);
    glVertex2f(50, 0);
    glVertex2f(315, -100);
    glVertex2f(0, -100);
    glVertex2f(-200, -100);
    glEnd();

    glColor3f(0.89, 0.78, 0.63);  //WarehouseWall 1
    glBegin(GL_POLYGON);
    glVertex2f(-200, -100);
    glVertex2f(-200, -500);
    glVertex2f(0, -500);
    glVertex2f(0, -100);
    glEnd();

    glColor3f(0.21, 0.51, 0.74);  //BlueStrip 1
    glBegin(GL_POLYGON);
    glVertex2f(-200, -150);
    glVertex2f(-200, -200);
    glVertex2f(0, -200);
    glVertex2f(0, -150);
    glEnd();

    glLineWidth(10);
    glColor3f(0.89, 0.78, 0.63);  //Shade X
    glBegin(GL_LINES);
    glVertex2f(-900, -160);
    glVertex2f(-200, -160);
    glEnd();

    glLineWidth(20);
    glColor3f(0.89, 0.78, 0.63);  //Shade Y
    glBegin(GL_LINES);
    glVertex2f(-880, -500);
    glVertex2f(-880, -160);
    glEnd();

    

    glColor3f(0.2, 0.2, 0.2); //Warehouse door 11
    glBegin(GL_POLYGON);
    glVertex2f(-805, -500);
    glVertex2f(-805, -400);
    glVertex2f(-705, -400);
    glVertex2f(-705, -500);
    glEnd();

    glColor3f(0.2, 0.2, 0.2); //Hole
    glBegin(GL_POLYGON);
    glVertex2f(-770, -100);
    glVertex2f(-770, -130);
    glVertex2f(-750, -130);
    glVertex2f(-750, -100);
    glEnd();

    glColor3f(0.66, 0.66, 0.66); //Shutter
    glBegin(GL_POLYGON);
    glVertex2f(-815, -400);
    glVertex2f(-815, -375);
    glVertex2f(-705, -375);
    glVertex2f(-705, -400);
    glEnd();

    glLineWidth(20);
    glColor3f(0.89, 0.78, 0.63);  //Shade Y
    glBegin(GL_LINES);
    glVertex2f(-650, -500);
    glVertex2f(-650, -160);
    glEnd();

    glColor3f(0.2, 0.2, 0.2); //Warehouse door 12
    glBegin(GL_POLYGON);
    glVertex2f(-600, -500);
    glVertex2f(-600, -400);
    glVertex2f(-500, -400);
    glVertex2f(-500, -500);
    glEnd();

    glColor3f(0.2, 0.2, 0.2); //Hole
    glBegin(GL_POLYGON);
    glVertex2f(-565, -100);
    glVertex2f(-565, -130);
    glVertex2f(-545, -130);
    glVertex2f(-545, -100);
    glEnd();

    glColor3f(0.66, 0.66, 0.66);   //Shutter
    glBegin(GL_POLYGON);
    glVertex2f(-610, -400);
    glVertex2f(-610, -375);
    glVertex2f(-500, -375);
    glVertex2f(-500, -400);
    glEnd();

    glLineWidth(20);
    glColor3f(0.89, 0.78, 0.63);  //Shade Y
    glBegin(GL_LINES);
    glVertex2f(-450, -500);
    glVertex2f(-450, -160);
    glEnd();

    glColor3f(0.2, 0.2, 0.2); //Warehouse door 13
    glBegin(GL_POLYGON);
    glVertex2f(-360, -500);
    glVertex2f(-360, -400);
    glVertex2f(-260, -400);
    glVertex2f(-260, -500);
    glEnd();

    glColor3f(0.2, 0.2, 0.2); //Hole
    glBegin(GL_POLYGON);
    glVertex2f(-325, -100);
    glVertex2f(-325, -130);
    glVertex2f(-305, -130);
    glVertex2f(-305, -100);
    glEnd();

    glColor3f(0.66, 0.66, 0.66);   //Shutter
    glBegin(GL_POLYGON);
    glVertex2f(-370, -400);
    glVertex2f(-370, -375);
    glVertex2f(-260, -375);
    glVertex2f(-260, -400);
    glEnd();

    

    glColor3f(1, 0.86, 0.68); //Warehouse 2
    glBegin(GL_POLYGON);
    glVertex2f(0, -500);
    glVertex2f(0, -100);
    glVertex2f(350, 0);
    glVertex2f(700, -100);
    glVertex2f(700, -500);
    glEnd();

    glLineWidth(10);
    glColor3f(0.89, 0.78, 0.63);  //Shade X
    glBegin(GL_LINES);
    glVertex2f(0, -160);
    glVertex2f(700, -160);
    glEnd();

    /*glLineWidth(20);
    glColor3f(0.89, 0.78, 0.63);  //Shade Y
    glBegin(GL_LINES);
    glVertex2f(18, -500);
    glVertex2f(18, -160);
    glEnd();*/

    glColor3f(0.75, 0.18, 0);  //Roof 2
    glBegin(GL_POLYGON);
    glVertex2f(350, 0);
    glVertex2f(900, 0);
    glVertex2f(1150, -100);
    glVertex2f(700, -100);
    glEnd();
    

    glColor3f(0.89, 0.78, 0.63);  //WarehouseWall 2
    glBegin(GL_POLYGON);
    glVertex2f(700, -100);
    glVertex2f(700, -500);
    glVertex2f(1140, -500);
    glVertex2f(1140, -100);
    glEnd();


    glColor3f(0.21, 0.51, 0.74);  //BlueStrip 2
    glBegin(GL_POLYGON);
    glVertex2f(700, -150);
    glVertex2f(700, -200);
    glVertex2f(1140, -200);
    glVertex2f(1140, -150);
    glEnd();

    glColor3f(0.2, 0.2, 0.2); //Warehouse door 21
    glBegin(GL_POLYGON);
    glVertex2f(80, -500);
    glVertex2f(80, -400);
    glVertex2f(180, -400);
    glVertex2f(180, -500);
    glEnd();

    glColor3f(0.2, 0.2, 0.2); //Hole
    glBegin(GL_POLYGON);
    glVertex2f(105, -100);
    glVertex2f(105, -130);
    glVertex2f(125, -130);
    glVertex2f(125, -100);
    glEnd();

    glColor3f(0.66, 0.66, 0.66); //Shutter 2
    glBegin(GL_POLYGON);
    glVertex2f(70, -400);
    glVertex2f(70, -375);
    glVertex2f(180, -375);
    glVertex2f(180, -400);
    glEnd();

    glLineWidth(20);
    glColor3f(0.89, 0.78, 0.63);  //Shade Y
    glBegin(GL_LINES);
    glVertex2f(250, -500);
    glVertex2f(250, -160);
    glEnd();

    glColor3f(0.2, 0.2, 0.2); //Warehouse door 22
    glBegin(GL_POLYGON);
    glVertex2f(300, -500);
    glVertex2f(300, -400);
    glVertex2f(400, -400);
    glVertex2f(400, -500);
    glEnd();

    glColor3f(0.2, 0.2, 0.2); //Hole
    glBegin(GL_POLYGON);
    glVertex2f(335, -100);
    glVertex2f(335, -130);
    glVertex2f(355, -130);
    glVertex2f(355, -100);
    glEnd();

    glColor3f(0.66, 0.66, 0.66);   //Shutter 2
    glBegin(GL_POLYGON);
    glVertex2f(290, -400);
    glVertex2f(290, -375);
    glVertex2f(400, -375);
    glVertex2f(400, -400);
    glEnd();

    glLineWidth(20);
    glColor3f(0.89, 0.78, 0.63);  //Shade Y
    glBegin(GL_LINES);
    glVertex2f(450, -500);
    glVertex2f(450, -160);
    glEnd();

    glColor3f(0.2, 0.2, 0.2); //Warehouse door 23
    glBegin(GL_POLYGON);
    glVertex2f(530, -500);
    glVertex2f(530, -400);
    glVertex2f(630, -400);
    glVertex2f(630, -500);
    glEnd();

    glColor3f(0.2, 0.2, 0.2); //Hole
    glBegin(GL_POLYGON);
    glVertex2f(575, -100);
    glVertex2f(575, -130);
    glVertex2f(595, -130);
    glVertex2f(595, -100);
    glEnd();

    glColor3f(0.66, 0.66, 0.66);   //Shutter 2
    glBegin(GL_POLYGON);
    glVertex2f(520, -400);
    glVertex2f(520, -375);
    glVertex2f(630, -375);
    glVertex2f(630, -400);
    glEnd();

    
    wheel(490, -545);  //wheel

    glColor3f(0.88, 0.88, 0.88); //Truck tail
    glBegin(GL_POLYGON);
    glVertex2f(430, -550);
    glVertex2f(430, -400);
    glVertex2f(730, -400);
    glVertex2f(730, -550);
    glEnd();

    glColor3f(0.8, 0.8, 0.8); //Truck tail
    glBegin(GL_POLYGON);
    glVertex2f(430, -550);
    glVertex2f(430, -400);
    glVertex2f(530, -400);
    glVertex2f(530, -550);
    glEnd();

    glColor3f(0.43, 0.43, 0.43); //Truck tail
    glBegin(GL_POLYGON);
    glVertex2f(430, -550);
    glVertex2f(430, -450);
    glVertex2f(530, -450);
    glVertex2f(530, -550);
    glEnd();

    glColor3f(1, 0.36, 0.07); //Truck head
    glBegin(GL_POLYGON);
    glVertex2f(730, -550);
    glVertex2f(730, -430);
    glVertex2f(800, -430);
    glVertex2f(830, -470);
    glVertex2f(830, -550);
    glEnd();

    glColor3f(0.42, 0.7, 0.81); //Truck glass
    glBegin(GL_POLYGON);
    glVertex2f(740, -500);
    glVertex2f(740, -445);
    glVertex2f(790, -445);
    glVertex2f(815, -480);
    glVertex2f(815, -500);
    glEnd();

    wheel(780, -553);
    whitewheel(780, -553);
    wheel(680, -553);
    whitewheel(680, -553);
    wheel(570, -553);
    whitewheel(570, -553);
    if (mouseX >= 0 && mouseX <= 730 && mouseY >= -1550 && mouseY <= -400) {
        glColor3f(0, 0, 1);
        if (mButtonPressed) {
            viewPage = SCREEN6;
            mButtonPressed = false;
        }
    }
    else {
        glColor3f(0, 0.12, 0.7);
        displayRasterText(590, -490, 0.0, "ekart");
    }

    glLineWidth(4);
    glColor3f(0.84, 0.59, 0.2); //Boxes 1
    glBegin(GL_LINE_LOOP);
    glVertex2f(-520, -530);
    glVertex2f(-520, -500);
    glVertex2f(-550, -500);
    glVertex2f(-550, -530);
    glEnd();
    glColor3f(0.99, 0.7, 0.26); 
    glBegin(GL_POLYGON);
    glVertex2f(-520, -530);
    glVertex2f(-520, -500);
    glVertex2f(-550, -500);
    glVertex2f(-550, -530);
    glEnd();

    glLineWidth(4);
    glColor3f(0.84, 0.59, 0.2); //Boxes 2
    glBegin(GL_LINE_LOOP);
    glVertex2f(-490, -530);
    glVertex2f(-490, -500);
    glVertex2f(-520, -500);
    glVertex2f(-520, -530);
    glEnd();
    glColor3f(0.99, 0.7, 0.26);
    glBegin(GL_POLYGON);
    glVertex2f(-490, -530);
    glVertex2f(-490, -500);
    glVertex2f(-520, -500);
    glVertex2f(-520, -530);
    glEnd();

    glLineWidth(4);
    glColor3f(0.84, 0.59, 0.2); //Boxes 3
    glBegin(GL_LINE_LOOP);
    glVertex2f(-460, -530);
    glVertex2f(-460, -500);
    glVertex2f(-490, -500);
    glVertex2f(-490, -530);
    glEnd();
    glColor3f(0.99, 0.7, 0.26);
    glBegin(GL_POLYGON);
    glVertex2f(-460, -530);
    glVertex2f(-460, -500);
    glVertex2f(-490, -500);
    glVertex2f(-490, -530);
    glEnd();

    glLineWidth(4);
    glColor3f(0.84, 0.59, 0.2); //Boxes 4
    glBegin(GL_LINE_LOOP);
    glVertex2f(-430, -530);
    glVertex2f(-430, -500);
    glVertex2f(-460, -500);
    glVertex2f(-460, -530);
    glEnd();
    glColor3f(0.99, 0.7, 0.26);
    glBegin(GL_POLYGON);
    glVertex2f(-430, -530);
    glVertex2f(-430, -500);
    glVertex2f(-460, -500);
    glVertex2f(-460, -530);
    glEnd();

    glLineWidth(4);
    glColor3f(0.84, 0.59, 0.2); //Boxes 5
    glBegin(GL_LINE_LOOP);
    glVertex2f(-505, -500);
    glVertex2f(-505, -470);
    glVertex2f(-535, -470);
    glVertex2f(-535, -500);
    glEnd();
    glColor3f(0.99, 0.7, 0.26);
    glBegin(GL_POLYGON);
    glVertex2f(-505, -500);
    glVertex2f(-505, -470);
    glVertex2f(-535, -470);
    glVertex2f(-535, -500);
    glEnd();

    glLineWidth(4);
    glColor3f(0.84, 0.59, 0.2); //Boxes 6
    glBegin(GL_LINE_LOOP);
    glVertex2f(-475, -500);
    glVertex2f(-475, -470);
    glVertex2f(-505, -470);
    glVertex2f(-505, -500);
    glEnd();
    glColor3f(0.99, 0.7, 0.26);
    glBegin(GL_POLYGON);
    glVertex2f(-475, -500);
    glVertex2f(-475, -470);
    glVertex2f(-505, -470);
    glVertex2f(-505, -500);
    glEnd();

    glLineWidth(4);
    glColor3f(0.84, 0.59, 0.2); //Boxes 7
    glBegin(GL_LINE_LOOP);
    glVertex2f(-445, -500);
    glVertex2f(-445, -470);
    glVertex2f(-475, -470);
    glVertex2f(-475, -500);
    glEnd();
    glColor3f(0.99, 0.7, 0.26);
    glBegin(GL_POLYGON);
    glVertex2f(-445, -500);
    glVertex2f(-445, -470);
    glVertex2f(-475, -470);
    glVertex2f(-475, -500);
    glEnd();

    glLineWidth(4);
    glColor3f(0.84, 0.59, 0.2); //Boxes 8
    glBegin(GL_LINE_LOOP);
    glVertex2f(-460, -470);
    glVertex2f(-460, -440);
    glVertex2f(-490, -440);
    glVertex2f(-490, -470);
    glEnd();
    glColor3f(0.99, 0.7, 0.26);
    glBegin(GL_POLYGON);
    glVertex2f(-460, -470);
    glVertex2f(-460, -440);
    glVertex2f(-490, -440);
    glVertex2f(-490, -470);
    glEnd();
    
    glLineWidth(4);
    glColor3f(0.84, 0.59, 0.2); //Boxes 9
    glBegin(GL_LINE_LOOP);
    glVertex2f(-490, -470);
    glVertex2f(-490, -440);
    glVertex2f(-520, -440);
    glVertex2f(-520, -470);
    glEnd();
    glColor3f(0.99, 0.7, 0.26);
    glBegin(GL_POLYGON);
    glVertex2f(-490, -470);
    glVertex2f(-490, -440);
    glVertex2f(-520, -440);
    glVertex2f(-520, -470);
    glEnd();

    glLineWidth(4);
    glColor3f(0.84, 0.59, 0.2); //Boxes 1
    glBegin(GL_LINE_LOOP);
    glVertex2f(80, -630);
    glVertex2f(80, -600);
    glVertex2f(110, -600);
    glVertex2f(110, -630);
    glEnd();
    glColor3f(0.99, 0.7, 0.26);
    glBegin(GL_POLYGON);
    glVertex2f(80, -630);
    glVertex2f(80, -600);
    glVertex2f(110, -600);
    glVertex2f(110, -630);
    glEnd();

    glLineWidth(4);
    glColor3f(0.84, 0.59, 0.2); //Boxes 2
    glBegin(GL_LINE_LOOP);
    glVertex2f(110, -630);
    glVertex2f(110, -600);
    glVertex2f(140, -600);
    glVertex2f(140, -630);
    glEnd();
    glColor3f(0.99, 0.7, 0.26);
    glBegin(GL_POLYGON);
    glVertex2f(110, -630);
    glVertex2f(110, -600);
    glVertex2f(140, -600);
    glVertex2f(140, -630);
    glEnd();

    glLineWidth(4);
    glColor3f(0.84, 0.59, 0.2); //Boxes 3
    glBegin(GL_LINE_LOOP);
    glVertex2f(140, -630);
    glVertex2f(140, -600);
    glVertex2f(170, -600);
    glVertex2f(170, -630);
    glEnd();
    glColor3f(0.99, 0.7, 0.26);
    glBegin(GL_POLYGON);
    glVertex2f(140, -630);
    glVertex2f(140, -600);
    glVertex2f(170, -600);
    glVertex2f(170, -630);
    glEnd();

    glLineWidth(4);
    glColor3f(0.84, 0.59, 0.2); //Boxes 4
    glBegin(GL_LINE_LOOP);
    glVertex2f(170, -630);
    glVertex2f(170, -600);
    glVertex2f(200, -600);
    glVertex2f(200, -630);
    glEnd();
    glColor3f(0.99, 0.7, 0.26);
    glBegin(GL_POLYGON);
    glVertex2f(170, -630);
    glVertex2f(170, -600);
    glVertex2f(200, -600);
    glVertex2f(200, -630);
    glEnd();

    glLineWidth(4);
    glColor3f(0.84, 0.59, 0.2); //Boxes 5
    glBegin(GL_LINE_LOOP);
    glVertex2f(95, -600);
    glVertex2f(95, -570);
    glVertex2f(125, -570);
    glVertex2f(125, -600);
    glEnd();
    glColor3f(0.99, 0.7, 0.26);
    glBegin(GL_POLYGON);
    glVertex2f(95, -600);
    glVertex2f(95, -570);
    glVertex2f(125, -570);
    glVertex2f(125, -600);
    glEnd();

    glLineWidth(4);
    glColor3f(0.84, 0.59, 0.2); //Boxes 6
    glBegin(GL_LINE_LOOP);
    glVertex2f(125, -600);
    glVertex2f(125, -570);
    glVertex2f(155, -570);
    glVertex2f(155, -600);
    glEnd();
    glColor3f(0.99, 0.7, 0.26);
    glBegin(GL_POLYGON);
    glVertex2f(125, -600);
    glVertex2f(125, -570);
    glVertex2f(155, -570);
    glVertex2f(155, -600);
    glEnd();


    glLineWidth(4);
    glColor3f(0.84, 0.59, 0.2); //Boxes 7
    glBegin(GL_LINE_LOOP);
    glVertex2f(155, -600);
    glVertex2f(155, -570);
    glVertex2f(185, -570);
    glVertex2f(185, -600);
    glEnd();
    glColor3f(0.99, 0.7, 0.26);
    glBegin(GL_POLYGON);
    glVertex2f(155, -600);
    glVertex2f(155, -570);
    glVertex2f(185, -570);
    glVertex2f(185, -600);
    glEnd();

    glLineWidth(4);
    glColor3f(0.84, 0.59, 0.2); //Boxes 8
    glBegin(GL_LINE_LOOP);
    glVertex2f(140, -570);
    glVertex2f(140, -540);
    glVertex2f(170, -540);
    glVertex2f(170, -570);
    glEnd();
    glColor3f(0.99, 0.7, 0.26);
    glBegin(GL_POLYGON);
    glVertex2f(140, -570);
    glVertex2f(140, -540);
    glVertex2f(170, -540);
    glVertex2f(170, -570);
    glEnd();

    glColor3f(0.99, 0.7, 0.26);
    glBegin(GL_POLYGON);
    glVertex2f(140, -570);
    glVertex2f(140, -540);
    glVertex2f(170, -540);
    glVertex2f(170, -570);
    glEnd();

    /*glLineWidth(4);
    glColor3f(0.84, 0.59, 0.2); //Boxes 9
    glBegin(GL_LINE_LOOP);
    glVertex2f(-490, -470);
    glVertex2f(-490, -440);
    glVertex2f(-520, -440);
    glVertex2f(-520, -470);
    glEnd();
    glColor3f(0.99, 0.7, 0.26);
    glBegin(GL_POLYGON);
    glVertex2f(-490, -470);
    glVertex2f(-490, -440);
    glVertex2f(-520, -440);
    glVertex2f(-520, -470);
    glEnd();*/

    



    glFlush();
    glutSwapBuffers();


}


void Screen5() {



    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.11, 0.33, 0.89, 1);


    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-550, 200, 0.0, "As most warehouses are in economically viable location outside city zones");


    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-1050, 100, 0.0, "There are 66 new large-scale fulfillment and sortation centres have been added in the states of Assam, Chattisgarh, Gujarat, Haryana, Karnataka,");


    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-600, 0, 0.0, " Maharashtra, Odisha, Punjab, Rajasthan, Tamil Nadu, Telangana, and West Bengal. ");

    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-1000, -100, 0.0, "In addition, Flipkart has also strengthened its last-mile reach with the addition of more than 1,000 new delivery hubs (DH) across the country.");

    glColor3f(0.97, 0.99, 0.18);
    displayRasterText(-200, -400, 0.0, "PRESS R TO CONTINUE ");

    glFlush();
    glutSwapBuffers();




}


void Screen6()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 0.86, 0.65, 0);

    
    
    glBegin(GL_POLYGON);         //sky
    glColor3f(0.4, 0.85, 0.97);
    glVertex2f(-1300, 720);
    glVertex2f(1300, 720);
    glColor3f(1, 1, 0.62);
    glVertex2f(1300, -500);
    glVertex2f(-1300, -500);
    glEnd();

    drawBlueClouds(550, 450);  //Clouds
    drawBlueClouds(-350, 550);
    drawBlueClouds(950, 450);
    drawBlueClouds(-850, 550);

    glBegin(GL_POLYGON);         //background building
    glColor3f(0.83, 0.78, 0.49);
    glVertex2f(-1300, -500);
    glVertex2f(-1300, 0);
    glVertex2f(-700, 0);
    glVertex2f(-700, -500);
    glEnd();
    glBegin(GL_POLYGON);   
    glVertex2f(-700,-500);
    glVertex2f(-700, 200);
    glVertex2f(-650, 200);
    glVertex2f(-650, -500);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-650, -500);
    glVertex2f(-650, -200);
    glVertex2f(-600, -200);
    glVertex2f(-600, -500);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-600, -500);
    glVertex2f(-600, 100);
    glVertex2f(-550, 100);
    glVertex2f(-550, -500);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-550, -500);
    glVertex2f(-550, -100);
    glVertex2f(-500, -100);
    glVertex2f(-500, -500);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-500, -500);
    glVertex2f(-500, 300);
    glVertex2f(-450, 300);
    glVertex2f(-450, -500);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-450, -500);
    glVertex2f(-450, 200);
    glVertex2f(-400, 200);
    glVertex2f(-400, -500);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-400, -500);
    glVertex2f(-400, 100);
    glVertex2f(0, 100);
    glVertex2f(0, -500);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(100, -500);
    glVertex2f(100, -100);
    glVertex2f(200, -100);
    glVertex2f(200, -500);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(600, -500);
    glVertex2f(600, 200);
    glVertex2f(650, 200);
    glVertex2f(650, -500);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(650, -500);
    glVertex2f(650, 100);
    glVertex2f(700, 100);
    glVertex2f(700, -500);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(700, -500);
    glVertex2f(700, 300);
    glVertex2f(750, 300);
    glVertex2f(750, -500);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(750, -500);
    glVertex2f(750, 250);
    glVertex2f(800, 250);
    glVertex2f(800, -500);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(750, -500);
    glVertex2f(750, 0);
    glVertex2f(1300, 0);
    glVertex2f(1300, -500);
    glEnd();

  
    glBegin(GL_POLYGON);        //road
    glColor3f(0.24, 0.24, 0.24);
    glVertex2f(-1300, -700);
    glVertex2f(-1300, -500);
    glVertex2f(1300, -500);
    glVertex2f(1300, -700);
    glEnd();

    glBegin(GL_POLYGON);        //side path
    glColor3f(0.99, 0.87, 0.72);
    glVertex2f(-1300, -540);
    glVertex2f(-1300, -500);
    glVertex2f(1300, -500);
    glVertex2f(1300, -540);
    glEnd();

    glBegin(GL_POLYGON);        //grass
    glColor3f(0.45, 1, 0.21);
    glVertex2f(-1300, -515);
    glVertex2f(-1300, -500);
    glVertex2f(1300, -500);
    glVertex2f(1300, -515);
    glEnd();

    glBegin(GL_POLYGON);        //building
    glColor3f(1,1,1);
    glVertex2f(-1100, -500);
    glVertex2f(-1100, 400);
    glVertex2f(-740, 400);
    glVertex2f(-740, -500);
    glEnd();

    glBegin(GL_POLYGON);        //glass
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1050, 400);
    glVertex2f(-1050,450);
    glVertex2f(-790, 450);
    glVertex2f(-790, 400);
    glEnd();

    glBegin(GL_POLYGON);        //
    glColor3f(1, 1, 1);
    glVertex2f(-1000, 460);
    glVertex2f(-1000, 510);
    glVertex2f(-840, 510);
    glVertex2f(-840, 460);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);        // Vertical line
    glColor3f(1, 1, 1);
    glVertex2f(-920, 510);
    glVertex2f(-920, 550);
    glEnd();

    glBegin(GL_POLYGON);        //line
    glColor3f(1, 1, 1);
    glVertex2f(-1100, 450);
    glVertex2f(-1100, 460);
    glVertex2f(-740, 460);
    glVertex2f(-740, 450);
    glEnd();

    glBegin(GL_POLYGON);        //glass 1
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1070, 320);
    glVertex2f(-1070, 380);
    glVertex2f(-1010, 380);
    glVertex2f(-1010, 320);
    glEnd();

    glBegin(GL_POLYGON);        //glass 1
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-990, 320);
    glVertex2f(-990, 380);
    glVertex2f(-930, 380);
    glVertex2f(-930, 320);
    glEnd();

    glBegin(GL_POLYGON);        //glass 1
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-910, 320);
    glVertex2f(-910, 380);
    glVertex2f(-850, 380);
    glVertex2f(-850, 320);
    glEnd();

    glBegin(GL_POLYGON);        //glass 1
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-830, 320);
    glVertex2f(-830, 380);
    glVertex2f(-770, 380);
    glVertex2f(-770, 320);
    glEnd();

    glBegin(GL_POLYGON);        //glass 2
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1070, 240);
    glVertex2f(-1070, 300);
    glVertex2f(-1010, 300);
    glVertex2f(-1010, 240);
    glEnd();

    glBegin(GL_POLYGON);        //glass 2
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-990, 240);
    glVertex2f(-990, 300);
    glVertex2f(-930, 300);
    glVertex2f(-930, 240);
    glEnd();

    glBegin(GL_POLYGON);        //glass 2
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-910, 240);
    glVertex2f(-910, 300);
    glVertex2f(-850, 300);
    glVertex2f(-850, 240);
    glEnd();

    glBegin(GL_POLYGON);        //glass 2
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-830, 240);
    glVertex2f(-830, 300);
    glVertex2f(-770, 300);
    glVertex2f(-770, 240);
    glEnd();

    glBegin(GL_POLYGON);        //glass 3
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1070, 160);
    glVertex2f(-1070, 220);
    glVertex2f(-1010, 220);
    glVertex2f(-1010, 160);
    glEnd();

    glBegin(GL_POLYGON);        //glass 3
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-990, 160);
    glVertex2f(-990, 220);
    glVertex2f(-930, 220);
    glVertex2f(-930, 160);
    glEnd();

    glBegin(GL_POLYGON);        //glass 3
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-910, 160);
    glVertex2f(-910, 220);
    glVertex2f(-850, 220);
    glVertex2f(-850, 160);
    glEnd();

    glBegin(GL_POLYGON);        //glass 3
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-830, 160);
    glVertex2f(-830, 220);
    glVertex2f(-770, 220);
    glVertex2f(-770, 160);
    glEnd();

    glBegin(GL_POLYGON);        //glass 4
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1070, 80);
    glVertex2f(-1070, 140);
    glVertex2f(-1010, 140);
    glVertex2f(-1010, 80);
    glEnd();

    glBegin(GL_POLYGON);        //glass 4
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-990, 80);
    glVertex2f(-990, 140);
    glVertex2f(-930, 140);
    glVertex2f(-930, 80);
    glEnd();

    glBegin(GL_POLYGON);        //glass 4
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-910, 80);
    glVertex2f(-910, 140);
    glVertex2f(-850, 140);
    glVertex2f(-850, 80);
    glEnd();

    glBegin(GL_POLYGON);        //glass 4
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-830, 80);
    glVertex2f(-830, 140);
    glVertex2f(-770, 140);
    glVertex2f(-770, 80);
    glEnd();

    glBegin(GL_POLYGON);        //glass 5
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1070, 0);
    glVertex2f(-1070, 60);
    glVertex2f(-1010, 60);
    glVertex2f(-1010, 0);
    glEnd();

    glBegin(GL_POLYGON);        //glass 5
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-990, 0);
    glVertex2f(-990, 60);
    glVertex2f(-930, 60);
    glVertex2f(-930, 0);
    glEnd();

    glBegin(GL_POLYGON);        //glass 5
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-910, 0);
    glVertex2f(-910, 60);
    glVertex2f(-850, 60);
    glVertex2f(-850, 0);
    glEnd();

    glBegin(GL_POLYGON);        //glass 5
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-830, 0);
    glVertex2f(-830, 60);
    glVertex2f(-770, 60);
    glVertex2f(-770, 0);
    glEnd();

    glBegin(GL_POLYGON);        //glass 6
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1070, 0);
    glVertex2f(-1070, 60);
    glVertex2f(-1010, 60);
    glVertex2f(-1010, 0);
    glEnd();

    glBegin(GL_POLYGON);        //glass 6
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-990, 0);
    glVertex2f(-990, 60);
    glVertex2f(-930, 60);
    glVertex2f(-930, 0);
    glEnd();

    glBegin(GL_POLYGON);        //glass 6
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-910, 0);
    glVertex2f(-910, 60);
    glVertex2f(-850, 60);
    glVertex2f(-850, 0);
    glEnd();

    glBegin(GL_POLYGON);        //glass 6
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-830, 0);
    glVertex2f(-830, 60);
    glVertex2f(-770, 60);
    glVertex2f(-770, 0);
    glEnd();

    glBegin(GL_POLYGON);        //glass 7
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1070, -80);
    glVertex2f(-1070, -20);
    glVertex2f(-1010, -20);
    glVertex2f(-1010, -80);
    glEnd();

    glBegin(GL_POLYGON);        //glass 7
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-990, -80);
    glVertex2f(-990, -20);
    glVertex2f(-930, -20);
    glVertex2f(-930, -80);
    glEnd();

    glBegin(GL_POLYGON);        //glass 7
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-910, -80);
    glVertex2f(-910, -20);
    glVertex2f(-850, -20);
    glVertex2f(-850, -80);
    glEnd();

    glBegin(GL_POLYGON);        //glass 7
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-830, -80);
    glVertex2f(-830, -20);
    glVertex2f(-770, -20);
    glVertex2f(-770, -80);
    glEnd();


    glBegin(GL_POLYGON);        //building 2
    glColor3f(0.57, 0.34, 0.06);
    glVertex2f(-1180, -500);
    glVertex2f(-1180, -100);
    glVertex2f(-540, -100);
    glVertex2f(-540, -500);
    glEnd();

    

    glBegin(GL_POLYGON);        //glass 1
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1100, -160);
    glVertex2f(-1100, -120);
    glVertex2f(-1030, -120);
    glVertex2f(-1030, -160);
    glEnd();

    glBegin(GL_POLYGON);        //glass 1
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1010, -160);
    glVertex2f(-1010, -120);
    glVertex2f(-940, -120);
    glVertex2f(-940, -160);
    glEnd();

    glBegin(GL_POLYGON);        //glass 1
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-920, -160);
    glVertex2f(-920, -120);
    glVertex2f(-850, -120);
    glVertex2f(-850, -160);
    glEnd();

    glBegin(GL_POLYGON);        //glass 1
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-830, -160);
    glVertex2f(-830, -120);
    glVertex2f(-760, -120);
    glVertex2f(-760, -160);
    glEnd();

    glBegin(GL_POLYGON);        //glass 1
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-740, -160);
    glVertex2f(-740, -120);
    glVertex2f(-670, -120);
    glVertex2f(-670, -160);
    glEnd();

    glBegin(GL_POLYGON);        //glass 1
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-650, -160);
    glVertex2f(-650, -120);
    glVertex2f(-580, -120);
    glVertex2f(-580, -160);
    glEnd();

    glBegin(GL_POLYGON);        //glass 2
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1100, -180);
    glVertex2f(-1100, -220);
    glVertex2f(-1030, -220);
    glVertex2f(-1030, -180);
    glEnd();

    glBegin(GL_POLYGON);        //glass 3
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1100, -240);
    glVertex2f(-1100, -280);
    glVertex2f(-1030, -280);
    glVertex2f(-1030, -240);
    glEnd();

    glBegin(GL_POLYGON);        //glass 4
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1100, -300);
    glVertex2f(-1100, -340);
    glVertex2f(-1030, -340);
    glVertex2f(-1030, -300);
    glEnd();

    glBegin(GL_POLYGON);        //glass 5
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1100, -360);
    glVertex2f(-1100, -400);
    glVertex2f(-1030, -400);
    glVertex2f(-1030, -360);
    glEnd();

    glBegin(GL_POLYGON);        //glass 6
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1100, -420);
    glVertex2f(-1100, -460);
    glVertex2f(-1030, -460);
    glVertex2f(-1030, -420);
    glEnd();

    glBegin(GL_POLYGON);        //glass 2
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-650, -220);
    glVertex2f(-650, -180);
    glVertex2f(-580, -180);
    glVertex2f(-580, -220);
    glEnd();

    glBegin(GL_POLYGON);        //glass 2
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-650, -280);
    glVertex2f(-650, -240);
    glVertex2f(-580, -240);
    glVertex2f(-580, -280);
    glEnd();

    glBegin(GL_POLYGON);        //glass 2
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-650, -300);
    glVertex2f(-650, -340);
    glVertex2f(-580, -340);
    glVertex2f(-580, -300);
    glEnd();

    glBegin(GL_POLYGON);        //glass 2
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-650, -400);
    glVertex2f(-650, -360);
    glVertex2f(-580, -360);
    glVertex2f(-580, -400);
    glEnd();

    glBegin(GL_POLYGON);        //glass 2
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-650, -460);
    glVertex2f(-650, -420);
    glVertex2f(-580, -420);
    glVertex2f(-580, -460);
    glEnd();

    glBegin(GL_POLYGON);  //Entrance
    glColor3f(1, 1, 1);
    glVertex2f(-1015, -500);
    glVertex2f(-1015, -175);
    glVertex2f(-665, -175);
    glVertex2f(-665, -500);
    glEnd();

    glBegin(GL_POLYGON);  //big glass
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1005, -500);
    glVertex2f(-1005, -185);
    glVertex2f(-675, -185);
    glVertex2f(-675, -500);
    glEnd();

    glLineWidth(3);    
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-900, -420);
    glVertex2f(-900, -185);
    glVertex2f(-780, -420);
    glVertex2f(-780, -185);
    glVertex2f(-1005, -420);
    glVertex2f(-675, -420);
    glVertex2f(-1005, -370);
    glVertex2f(-675, -370);
    glVertex2f(-1005, -320);
    glVertex2f(-675, -320);
    glVertex2f(-1005, -270);
    glVertex2f(-675, -270);
    glVertex2f(-1005, -225);
    glVertex2f(-675, -225);
    glEnd();


    glLineWidth(10);        //entrance
    glBegin(GL_LINES);
    glColor3f(0.99, 0.87, 0.72);
    glVertex2f(-838, -500);
    glVertex2f(-838, -420);
    glVertex2f(-950, -500);
    glVertex2f(-950, -420);
    glVertex2f(-730, -500);
    glVertex2f(-730, -420);
    glEnd();

    glBegin(GL_POLYGON);        //building 3
    glColor3f(1, 1, 1);
    glVertex2f(-200-100, -500);
    glVertex2f(-200 - 100, 350);
    glVertex2f(200 - 100, 350);
    glVertex2f(200 - 100, -500);
    glEnd();

    glBegin(GL_POLYGON);        //glass
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-150 - 100, 350);
    glVertex2f(-150 - 100, 400);
    glVertex2f(150 - 100, 400);
    glVertex2f(150 - 100, 350);
    glEnd();

    glBegin(GL_POLYGON);        //
    glColor3f(1, 1, 1);
    glVertex2f(-100 - 100, 410);
    glVertex2f(-100 - 100, 460);
    glVertex2f(100 - 100, 460);
    glVertex2f(100 - 100, 410);
    glEnd();

    glBegin(GL_POLYGON);        //line
    glColor3f(1, 1, 1);
    glVertex2f(-200 - 100, 400);
    glVertex2f(-200 - 100, 410);
    glVertex2f(200 - 100, 410);
    glVertex2f(200 - 100, 400);
    glEnd();

    glBegin(GL_POLYGON);        //glass
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-200 - 100, 250);
    glVertex2f(-200 - 100, 300);
    glVertex2f(200 - 100, 300);
    glVertex2f(200 - 100, 250);
    glEnd();

    glBegin(GL_POLYGON);        //glass
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-200 - 100, 230);
    glVertex2f(-200 - 100, 180);
    glVertex2f(200 - 100, 180);
    glVertex2f(200 - 100, 230);
    glEnd();

    glBegin(GL_POLYGON);        //glass
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-200 - 100, 110);
    glVertex2f(-200 - 100, 160);
    glVertex2f(200 - 100, 160);
    glVertex2f(200 - 100, 110);
    glEnd();

    glBegin(GL_POLYGON);        //glass
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-200 - 100, 40);
    glVertex2f(-200 - 100, 90);
    glVertex2f(200 - 100, 90);
    glVertex2f(200 - 100, 40);
    glEnd();

    glBegin(GL_POLYGON);        //glass
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-200 - 100, -30);
    glVertex2f(-200 - 100, 20);
    glVertex2f(200 - 100, 20);
    glVertex2f(200 - 100, -30);
    glEnd();

    glBegin(GL_POLYGON);        //glass
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-200 - 100, -100);
    glVertex2f(-200 - 100, -50);
    glVertex2f(200 - 100, -50);
    glVertex2f(200 - 100, -100);
    glEnd();

    glBegin(GL_POLYGON);        //glass
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-200 - 100, -170);
    glVertex2f(-200 - 100, -120);
    glVertex2f(200 - 100, -120);
    glVertex2f(200 - 100, -170);
    glEnd();

    glBegin(GL_POLYGON);        //glass
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-200 - 100, -240);
    glVertex2f(-200 - 100, -190);
    glVertex2f(200 - 100, -190);
    glVertex2f(200 - 100, -240);
    glEnd();

    glBegin(GL_POLYGON);        //glass
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-200 - 100, -310);
    glVertex2f(-200 - 100, -260);
    glVertex2f(200 - 100, -260);
    glVertex2f(200 - 100, -310);
    glEnd();

    glBegin(GL_POLYGON);        //glass
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-200 - 100, -330);
    glVertex2f(-200 - 100, -380);
    glVertex2f(200 - 100, -380);
    glVertex2f(200 - 100, -330);
    glEnd();

    glBegin(GL_POLYGON);        //glass
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-200 - 100, -400);
    glVertex2f(-200 - 100, -500);
    glVertex2f(200 - 100, -500);
    glVertex2f(200 - 100, -400);
    glEnd();

    glLineWidth(10);        //entrance
    glBegin(GL_LINES);
    glColor3f(0.99, 0.87, 0.72);
    glVertex2f(-100 - 100, -500);
    glVertex2f(-100 - 100, -400);
    glVertex2f(-0 - 100, -500);
    glVertex2f(-0 - 100, -400);
    glVertex2f(100 - 100, -500);
    glVertex2f(100 - 100, -400);
    glEnd();

    glBegin(GL_POLYGON);        //building 4
    glColor3f(0.57, 0.34, 0.06);
    glVertex2f(-1100+ buildingshift, -500 );
    glVertex2f(-1100+ buildingshift, 400 + buildingvshift);
    glVertex2f(-740+ buildingshift, 400 + buildingvshift);
    glVertex2f(-740+ buildingshift, -500 );
    glEnd();

    glBegin(GL_POLYGON);        //glass
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1050 + buildingshift, 400 + buildingvshift);
    glVertex2f(-1050 + buildingshift, 450 + buildingvshift);
    glVertex2f(-790 + buildingshift, 450 + buildingvshift);
    glVertex2f(-790 + buildingshift, 400 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //
    glColor3f(0.57, 0.34, 0.06);
    glVertex2f(-1000 + buildingshift, 460 + buildingvshift);
    glVertex2f(-1000 + buildingshift, 510 + buildingvshift);
    glVertex2f(-840 + buildingshift, 510 + buildingvshift);
    glVertex2f(-840 + buildingshift, 460 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //line
    glColor3f(0.57, 0.34, 0.06);
    glVertex2f(-1100 + buildingshift, 450 + buildingvshift);
    glVertex2f(-1100 + buildingshift, 460 + buildingvshift);
    glVertex2f(-740 + buildingshift, 460 + buildingvshift);
    glVertex2f(-740 + buildingshift, 450 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 1
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1070 + buildingshift, 320 + buildingvshift);
    glVertex2f(-1070 + buildingshift, 380 + buildingvshift);
    glVertex2f(-1010 + buildingshift, 380 + buildingvshift);
    glVertex2f(-1010 + buildingshift, 320 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 1
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-990 + buildingshift, 320 + buildingvshift);
    glVertex2f(-990 + buildingshift, 380 + buildingvshift);
    glVertex2f(-930 + buildingshift, 380 + buildingvshift);
    glVertex2f(-930 + buildingshift, 320 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 1
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-910 + buildingshift, 320 + buildingvshift);
    glVertex2f(-910 + buildingshift, 380 + buildingvshift);
    glVertex2f(-850 + buildingshift, 380 + buildingvshift);
    glVertex2f(-850 + buildingshift, 320 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 1
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-830 + buildingshift, 320 + buildingvshift);
    glVertex2f(-830 + buildingshift, 380 + buildingvshift);
    glVertex2f(-770 + buildingshift, 380 + buildingvshift);
    glVertex2f(-770 + buildingshift, 320 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 2
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1070 + buildingshift, 240 + buildingvshift);
    glVertex2f(-1070 + buildingshift, 300 + buildingvshift);
    glVertex2f(-1010 + buildingshift, 300 + buildingvshift);
    glVertex2f(-1010 + buildingshift, 240 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 2
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-990 + buildingshift, 240 + buildingvshift);
    glVertex2f(-990 + buildingshift, 300 + buildingvshift);
    glVertex2f(-930 + buildingshift, 300 + buildingvshift);
    glVertex2f(-930 + buildingshift, 240 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 2
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-910 + buildingshift, 240 + buildingvshift);
    glVertex2f(-910 + buildingshift, 300 + buildingvshift);
    glVertex2f(-850 + buildingshift, 300 + buildingvshift);
    glVertex2f(-850 + buildingshift, 240 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 2
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-830 + buildingshift, 240 + buildingvshift);
    glVertex2f(-830 + buildingshift, 300 + buildingvshift);
    glVertex2f(-770 + buildingshift, 300 + buildingvshift);
    glVertex2f(-770 + buildingshift, 240 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 3
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1070 + buildingshift, 160 + buildingvshift);
    glVertex2f(-1070 + buildingshift, 220 + buildingvshift);
    glVertex2f(-1010 + buildingshift, 220 + buildingvshift);
    glVertex2f(-1010 + buildingshift, 160 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 3
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-990 + buildingshift, 160 + buildingvshift);
    glVertex2f(-990 + buildingshift, 220+ buildingvshift);
    glVertex2f(-930 + buildingshift, 220 + buildingvshift);
    glVertex2f(-930 + buildingshift, 160 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 3
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-910 + buildingshift, 160 + buildingvshift);
    glVertex2f(-910 + buildingshift, 220 + buildingvshift);
    glVertex2f(-850 + buildingshift, 220 + buildingvshift);
    glVertex2f(-850 + buildingshift, 160+ buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 3
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-830 + buildingshift, 160 + buildingvshift);
    glVertex2f(-830 + buildingshift, 220 + buildingvshift);
    glVertex2f(-770 + buildingshift, 220 + buildingvshift);
    glVertex2f(-770 + buildingshift, 160 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 4
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1070 + buildingshift, 80 + buildingvshift);
    glVertex2f(-1070 + buildingshift, 140 + buildingvshift);
    glVertex2f(-1010 + buildingshift, 140 + buildingvshift);
    glVertex2f(-1010 + buildingshift, 80 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 4
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-990 + buildingshift, 80 + buildingvshift);
    glVertex2f(-990 + buildingshift, 140 + buildingvshift);
    glVertex2f(-930 + buildingshift, 140 + buildingvshift);
    glVertex2f(-930 + buildingshift, 80 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 4
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-910 + buildingshift, 80 + buildingvshift);
    glVertex2f(-910 + buildingshift, 140 + buildingvshift);
    glVertex2f(-850 + buildingshift, 140 + buildingvshift);
    glVertex2f(-850 + buildingshift, 80 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 4
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-830 + buildingshift, 80 + buildingvshift);
    glVertex2f(-830 + buildingshift, 140 + buildingvshift);
    glVertex2f(-770 + buildingshift, 140 + buildingvshift);
    glVertex2f(-770 + buildingshift, 80 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 5
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1070 + buildingshift, 0 + buildingvshift);
    glVertex2f(-1070 + buildingshift, 60 + buildingvshift);
    glVertex2f(-1010 + buildingshift, 60 + buildingvshift);
    glVertex2f(-1010 + buildingshift, 0 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 5
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-990 + buildingshift, 0 + buildingvshift);
    glVertex2f(-990 + buildingshift, 60 + buildingvshift);
    glVertex2f(-930 + buildingshift, 60 + buildingvshift);
    glVertex2f(-930 + buildingshift, 0 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 5
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-910 + buildingshift, 0 + buildingvshift);
    glVertex2f(-910 + buildingshift, 60 + buildingvshift);
    glVertex2f(-850 + buildingshift, 60 + buildingvshift);
    glVertex2f(-850 + buildingshift, 0 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 5
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-830 + buildingshift, 0 + buildingvshift);
    glVertex2f(-830 + buildingshift, 60 + buildingvshift);
    glVertex2f(-770 + buildingshift, 60 + buildingvshift);
    glVertex2f(-770 + buildingshift, 0 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 6
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1070 + buildingshift, 0 + buildingvshift);
    glVertex2f(-1070 + buildingshift, 60 + buildingvshift);
    glVertex2f(-1010 + buildingshift, 60 + buildingvshift);
    glVertex2f(-1010 + buildingshift, 0 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 6
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-990 + buildingshift, 0 + buildingvshift);
    glVertex2f(-990 + buildingshift, 60 + buildingvshift);
    glVertex2f(-930 + buildingshift, 60 + buildingvshift);
    glVertex2f(-930 + buildingshift, 0 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 6
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-910 + buildingshift, 0 + buildingvshift);
    glVertex2f(-910 + buildingshift, 60 + buildingvshift);
    glVertex2f(-850 + buildingshift, 60 + buildingvshift);
    glVertex2f(-850 + buildingshift, 0 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 6
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-830 + buildingshift, 0 + buildingvshift);
    glVertex2f(-830 + buildingshift, 60 + buildingvshift);
    glVertex2f(-770 + buildingshift, 60 + buildingvshift);
    glVertex2f(-770 + buildingshift, 0 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 7
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1070 + buildingshift, -80 + buildingvshift);
    glVertex2f(-1070 + buildingshift, -20 + buildingvshift);
    glVertex2f(-1010 + buildingshift, -20 + buildingvshift);
    glVertex2f(-1010 + buildingshift, -80 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 7
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-990 + buildingshift, -80 + buildingvshift);
    glVertex2f(-990 + buildingshift, -20 + buildingvshift);
    glVertex2f(-930 + buildingshift, -20 + buildingvshift);
    glVertex2f(-930 + buildingshift, -80 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 7
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-910 + buildingshift, -80 + buildingvshift);
    glVertex2f(-910 + buildingshift, -20 + buildingvshift);
    glVertex2f(-850 + buildingshift, -20 + buildingvshift);
    glVertex2f(-850 + buildingshift, -80 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 7
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-830 + buildingshift, -80 + buildingvshift);
    glVertex2f(-830 + buildingshift, -20 + buildingvshift);
    glVertex2f(-770 + buildingshift, -20 + buildingvshift);
    glVertex2f(-770 + buildingshift, -80 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);                          //building 5
    glColor3f(0.57, 0.34, 0.06);
    glVertex2f(-1100 + buildingshift1, -500);
    glVertex2f(-1100 + buildingshift1, 400 + buildingvshift);
    glVertex2f(-740 + buildingshift1, 400 + buildingvshift);
    glVertex2f(-740 + buildingshift1, -500);
    glEnd();

    glBegin(GL_POLYGON);        //glass
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1050 + buildingshift1, 400 + buildingvshift);
    glVertex2f(-1050 + buildingshift1, 450 + buildingvshift);
    glVertex2f(-790 + buildingshift1, 450 + buildingvshift);
    glVertex2f(-790 + buildingshift1, 400 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //
    glColor3f(0.57, 0.34, 0.06);
    glVertex2f(-1000 + buildingshift1, 460 + buildingvshift);
    glVertex2f(-1000 + buildingshift1, 510 + buildingvshift);
    glVertex2f(-840 + buildingshift1, 510 + buildingvshift);
    glVertex2f(-840 + buildingshift1, 460 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //line
    glColor3f(0.57, 0.34, 0.06);
    glVertex2f(-1100 + buildingshift1, 450 + buildingvshift);
    glVertex2f(-1100 + buildingshift1, 460 + buildingvshift);
    glVertex2f(-740 + buildingshift1, 460 + buildingvshift);
    glVertex2f(-740 + buildingshift1, 450 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 1
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1070 + buildingshift1, 320 + buildingvshift);
    glVertex2f(-1070 + buildingshift1, 380 + buildingvshift);
    glVertex2f(-1010 + buildingshift1, 380 + buildingvshift);
    glVertex2f(-1010 + buildingshift1, 320 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 1
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-990 + buildingshift1, 320 + buildingvshift);
    glVertex2f(-990 + buildingshift1, 380 + buildingvshift);
    glVertex2f(-930 + buildingshift1, 380 + buildingvshift);
    glVertex2f(-930 + buildingshift1, 320 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 1
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-910 + buildingshift1, 320 + buildingvshift);
    glVertex2f(-910 + buildingshift1, 380 + buildingvshift);
    glVertex2f(-850 + buildingshift1, 380 + buildingvshift);
    glVertex2f(-850 + buildingshift1, 320 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 1
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-830 + buildingshift1, 320 + buildingvshift);
    glVertex2f(-830 + buildingshift1, 380 + buildingvshift);
    glVertex2f(-770 + buildingshift1, 380 + buildingvshift);
    glVertex2f(-770 + buildingshift1, 320 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 2
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1070 + buildingshift1, 240 + buildingvshift);
    glVertex2f(-1070 + buildingshift1, 300 + buildingvshift);
    glVertex2f(-1010 + buildingshift1, 300 + buildingvshift);
    glVertex2f(-1010 + buildingshift1, 240 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 2
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-990 + buildingshift1, 240 + buildingvshift);
    glVertex2f(-990 + buildingshift1, 300 + buildingvshift);
    glVertex2f(-930 + buildingshift1, 300 + buildingvshift);
    glVertex2f(-930 + buildingshift1, 240 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 2
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-910 + buildingshift1, 240 + buildingvshift);
    glVertex2f(-910 + buildingshift1, 300 + buildingvshift);
    glVertex2f(-850 + buildingshift1, 300 + buildingvshift);
    glVertex2f(-850 + buildingshift1, 240 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 2
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-830 + buildingshift1, 240 + buildingvshift);
    glVertex2f(-830 + buildingshift1, 300 + buildingvshift);
    glVertex2f(-770 + buildingshift1, 300 + buildingvshift);
    glVertex2f(-770 + buildingshift1, 240 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 3
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1070 + buildingshift1, 160 + buildingvshift);
    glVertex2f(-1070 + buildingshift1, 220 + buildingvshift);
    glVertex2f(-1010 + buildingshift1, 220 + buildingvshift);
    glVertex2f(-1010 + buildingshift1, 160 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 3
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-990 + buildingshift1, 160 + buildingvshift);
    glVertex2f(-990 + buildingshift1, 220 + buildingvshift);
    glVertex2f(-930 + buildingshift1, 220 + buildingvshift);
    glVertex2f(-930 + buildingshift1, 160 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 3
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-910 + buildingshift1, 160 + buildingvshift);
    glVertex2f(-910 + buildingshift1, 220 + buildingvshift);
    glVertex2f(-850 + buildingshift1, 220 + buildingvshift);
    glVertex2f(-850 + buildingshift1, 160 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 3
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-830 + buildingshift1, 160 + buildingvshift);
    glVertex2f(-830 + buildingshift1, 220 + buildingvshift);
    glVertex2f(-770 + buildingshift1, 220 + buildingvshift);
    glVertex2f(-770 + buildingshift1, 160 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 4
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1070 + buildingshift1, 80 + buildingvshift);
    glVertex2f(-1070 + buildingshift1, 140 + buildingvshift);
    glVertex2f(-1010 + buildingshift1, 140 + buildingvshift);
    glVertex2f(-1010 + buildingshift1, 80 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 4
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-990 + buildingshift1, 80 + buildingvshift);
    glVertex2f(-990 + buildingshift1, 140 + buildingvshift);
    glVertex2f(-930 + buildingshift1, 140 + buildingvshift);
    glVertex2f(-930 + buildingshift1, 80 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 4
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-910 + buildingshift1, 80 + buildingvshift);
    glVertex2f(-910 + buildingshift1, 140 + buildingvshift);
    glVertex2f(-850 + buildingshift1, 140 + buildingvshift);
    glVertex2f(-850 + buildingshift1, 80 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 4
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-830 + buildingshift1, 80 + buildingvshift);
    glVertex2f(-830 + buildingshift1, 140 + buildingvshift);
    glVertex2f(-770 + buildingshift1, 140 + buildingvshift);
    glVertex2f(-770 + buildingshift1, 80 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 5
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1070 + buildingshift1, 0 + buildingvshift);
    glVertex2f(-1070 + buildingshift1, 60 + buildingvshift);
    glVertex2f(-1010 + buildingshift1, 60 + buildingvshift);
    glVertex2f(-1010 + buildingshift1, 0 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 5
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-990 + buildingshift1, 0 + buildingvshift);
    glVertex2f(-990 + buildingshift1, 60 + buildingvshift);
    glVertex2f(-930 + buildingshift1, 60 + buildingvshift);
    glVertex2f(-930 + buildingshift1, 0 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 5
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-910 + buildingshift1, 0 + buildingvshift);
    glVertex2f(-910 + buildingshift1, 60 + buildingvshift);
    glVertex2f(-850 + buildingshift1, 60 + buildingvshift);
    glVertex2f(-850 + buildingshift1, 0 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 5
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-830 + buildingshift1, 0 + buildingvshift);
    glVertex2f(-830 + buildingshift1, 60 + buildingvshift);
    glVertex2f(-770 + buildingshift1, 60 + buildingvshift);
    glVertex2f(-770 + buildingshift1, 0 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 6
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1070 + buildingshift1, 0 + buildingvshift);
    glVertex2f(-1070 + buildingshift1, 60 + buildingvshift);
    glVertex2f(-1010 + buildingshift1, 60 + buildingvshift);
    glVertex2f(-1010 + buildingshift1, 0 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 6
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-990 + buildingshift1, 0 + buildingvshift);
    glVertex2f(-990 + buildingshift1, 60 + buildingvshift);
    glVertex2f(-930 + buildingshift1, 60 + buildingvshift);
    glVertex2f(-930 + buildingshift1, 0 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 6
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-910 + buildingshift1, 0 + buildingvshift);
    glVertex2f(-910 + buildingshift1, 60 + buildingvshift);
    glVertex2f(-850 + buildingshift1, 60 + buildingvshift);
    glVertex2f(-850 + buildingshift1, 0 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 6
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-830 + buildingshift1, 0 + buildingvshift);
    glVertex2f(-830 + buildingshift1, 60 + buildingvshift);
    glVertex2f(-770 + buildingshift1, 60 + buildingvshift);
    glVertex2f(-770 + buildingshift1, 0 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 7
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-1070 + buildingshift1, -80 + buildingvshift);
    glVertex2f(-1070 + buildingshift1, -20 + buildingvshift);
    glVertex2f(-1010 + buildingshift1, -20 + buildingvshift);
    glVertex2f(-1010 + buildingshift1, -80 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 7
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-990 + buildingshift1, -80 + buildingvshift);
    glVertex2f(-990 + buildingshift1, -20 + buildingvshift);
    glVertex2f(-930 + buildingshift1, -20 + buildingvshift);
    glVertex2f(-930 + buildingshift1, -80 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 7
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-910 + buildingshift1, -80 + buildingvshift);
    glVertex2f(-910 + buildingshift1, -20 + buildingvshift);
    glVertex2f(-850 + buildingshift1, -20 + buildingvshift);
    glVertex2f(-850 + buildingshift1, -80 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //glass 7
    glColor3f(0.29, 0.8, 1);
    glVertex2f(-830 + buildingshift1, -80 + buildingvshift);
    glVertex2f(-830 + buildingshift1, -20 + buildingvshift);
    glVertex2f(-770 + buildingshift1, -20 + buildingvshift);
    glVertex2f(-770 + buildingshift1, -80 + buildingvshift);
    glEnd();

    glBegin(GL_POLYGON);        //building middle
    glColor3f(0.46, 0.28, 0.11);
    glVertex2f(505 , -500 );
    glVertex2f(505  , 0 );
    glVertex2f(800  , 0 );
    glVertex2f(800 , -500 );
    glEnd();

    glBegin(GL_POLYGON);        //glass middle
    glColor3f(0.29, 0.8, 1);
    glVertex2f(505, -500);
    glVertex2f(505, -50);
    glVertex2f(800, -50);
    glVertex2f(800, -500);
    glEnd();

    glLineWidth(3);
    glColor3f(0.46, 0.28, 0.11);
    glBegin(GL_LINES);
    glVertex2f(550,-500);
    glVertex2f(550, -50);
    glVertex2f(600, -500);
    glVertex2f(600, -50);
    glVertex2f(650, -500);
    glVertex2f(650, -50);
    glVertex2f(700, -500);
    glVertex2f(700, -50);
    glVertex2f(750, -500);
    glVertex2f(750, -50);
    glEnd();

    glLineWidth(8);
    glColor3f(0.46, 0.28, 0.11);
    glBegin(GL_LINES);
    glVertex2f(400, -500);
    glVertex2f(400, -420);
    glEnd();

    tree(400,-430);  //Tree 1
    tree(380, -430);
    tree(420, -430);
    tree(410, -410);
    tree(390, -410);
    tree(400, -390);

    float x1 = 500;

    glLineWidth(8);
    glColor3f(0.46, 0.28, 0.11);
    glBegin(GL_LINES);
    glVertex2f(400 + x1, -500);
    glVertex2f(400 + x1, -420);
    glEnd();

    tree(400 + x1, -430);  //Tree 2
    tree(380 + x1, -430);
    tree(420 + x1, -430);
    tree(410 + x1, -410);
    tree(390 + x1, -410);
    tree(400 + x1, -390);

    float x2 = 650;

    glLineWidth(8);
    glColor3f(0.46, 0.28, 0.11);
    glBegin(GL_LINES);
    glVertex2f(400 + x2, -500);
    glVertex2f(400 + x2, -420);
    glEnd();

    tree(400 + x2, -430);  //Tree 2
    tree(380 + x2, -430);
    tree(420 + x2, -430);
    tree(410 + x2, -410);
    tree(390 + x2, -410);
    tree(400 + x2, -390);

    float x3 = -650;

    glLineWidth(8);
    glColor3f(0.46, 0.28, 0.11);
    glBegin(GL_LINES);
    glVertex2f(400 + x3, -500);
    glVertex2f(400 + x3, -420);
    glEnd();

    tree(400 + x3, -430);  //Tree 3
    tree(380 + x3, -430);
    tree(420 + x3, -430);
    tree(410 + x3, -410);
    tree(390 + x3, -410);
    tree(400 + x3, -390);

    float x4 = -750;

    glLineWidth(8);
    glColor3f(0.46, 0.28, 0.11);
    glBegin(GL_LINES);
    glVertex2f(400 + x4, -500);
    glVertex2f(400 + x4, -420);
    glEnd();

    tree(400 + x4, -430);  //Tree 4
    tree(380 + x4, -430);
    tree(420 + x4, -430);
    tree(410 + x4, -410);
    tree(390 + x4, -410);
    tree(400 + x4, -390);

    float x5 = -850;

    glLineWidth(8);
    glColor3f(0.46, 0.28, 0.11);
    glBegin(GL_LINES);
    glVertex2f(400 + x5, -500);
    glVertex2f(400 + x5, -420);
    glEnd();

    tree(400 + x5, -430);  //Tree 5
    tree(380 + x5, -430);
    tree(420 + x5, -430);
    tree(410 + x5, -410);
    tree(390 +x5, -410);
    tree(400 +x5, -390);
    
    float x6 = -950;

    glLineWidth(8);
    glColor3f(0.46, 0.28, 0.11);
    glBegin(GL_LINES);
    glVertex2f(400 + x6, -500);
    glVertex2f(400 +x6, -420);
    glEnd();

    tree(400 + x6, -430);  //Tree 5
    tree(380 + x6, -430);
    tree(420 + x6, -430);
    tree(410 + x6, -410);
    tree(390 + x6, -410);
    tree(400 + x6, -390);

    glLoadIdentity();
    counter2 = counter2 - 0.8;
    if (counter2 < -2474.000) {
        counter2 = 300.0;
    }
    glTranslated(counter2, 100, 0.0);
    car1();
    
    glLoadIdentity();
    wheel(-870 + shift, -545 + shiftdown);  //wheel

    glColor3f(0.88, 0.88, 0.88); //Truck tail
    glBegin(GL_POLYGON);
    glVertex2f(-930 +shift , -550 + shiftdown);
    glVertex2f(-930 + shift, -400 + shiftdown);
    glVertex2f(-630 + shift, -400 + shiftdown);
    glVertex2f(-630 + shift, -550 + shiftdown);
    glEnd();

    glColor3f(0.8, 0.8, 0.8); //Truck tail
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift, -550 + shiftdown);
    glVertex2f(-930 + shift, -400 + shiftdown);
    glVertex2f(-830 + shift, -400 + shiftdown);
    glVertex2f(-830 + shift, -550 + shiftdown);
    glEnd();

    glColor3f(0.43, 0.43, 0.43); //Truck tail
    glBegin(GL_POLYGON);
    glVertex2f(-930 + shift, -550 + shiftdown);
    glVertex2f(-930 + shift, -450 + shiftdown);
    glVertex2f(-830 + shift, -450 + shiftdown);
    glVertex2f(-830 + shift, -550 + shiftdown);
    glEnd();

    glColor3f(1, 0.36, 0.07); //Truck head
    glBegin(GL_POLYGON);
    glVertex2f(-630 + shift, -550 + shiftdown);
    glVertex2f(-630 + shift, -430 + shiftdown);
    glVertex2f(-570 + shift, -430 + shiftdown);
    glVertex2f(-530 + shift, -470 + shiftdown);
    glVertex2f(-530 + shift, -550 + shiftdown);
    glEnd();

    glColor3f(0.42, 0.7, 0.81); //Truck glass
    glBegin(GL_POLYGON);
    glVertex2f(-620 + shift, -500 + shiftdown);
    glVertex2f(-620 + shift, -445 + shiftdown);
    glVertex2f(-580 + shift, -445 + shiftdown);
    glVertex2f(-545 + shift, -480 + shiftdown);
    glVertex2f(-545 + shift, -500 + shiftdown);
    glEnd();

    wheel(-590 + shift, -553 + shiftdown);
    whitewheel(-590 + shift, -553 + shiftdown);
    wheel(-690 + shift, -553 + shiftdown);
    whitewheel(-690 + shift, -553 + shiftdown);
    wheel(-790 + shift, -553 + shiftdown);
    whitewheel(-790 + shift, -553 + shiftdown);

    glColor3f(0, 0.12, 0.7);
    displayRasterText(-770 + shift, -490 + shiftdown, 0.0, "ekart");

    


    glLoadIdentity();
    counter1 = counter1 - 1;
    if (counter1 < -2474.000) {
        counter1 = 300.0;
    }
    glTranslated(counter1,-25,0.0);
    car();
    

    glFlush();
    glutSwapBuffers();

}
void Screen7()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.11, 0.33, 0.89, 1);

    glColor3f(1, 1, 1);
    displayRasterText(-600, 300, 0, "Flipkart has their own logistics Ekart. Ekart is the one who delivers the product to you.");

    glColor3f(1, 1, 1);
    displayRasterText(-580, 200, 0, "Pricing and remote delivery were major reasons for them to start their own logistics.");

    glColor3f(1, 1, 1);
    displayRasterText(-500, 100, 0, "It is mandatory for the sellers to ship the product only through Ekart.");
    glColor3f(1, 1, 1);
    displayRasterText(-200, 0, 0, "Ekart is backbone of flipkart");

    glColor3f(0.84, 0.83, 0.14);
    displayRasterText(-200, -200, 0, "PRESS Y TO CONTINUE ");



    glFlush();
    glutSwapBuffers();
}
void blueglass(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0.12, 0.67, 1);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 45 * cos(th), y + 45 * sin(th));
    }

    glEnd();

}
void borderglass(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0.99, 0.77, 0.48);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 55 * cos(th), y + 55 * sin(th));
    }

    glEnd();

}

void twhitewheel(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0.86, 0.86, 0.86);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 25 * cos(th), y + 25 * sin(th));
    }

    glEnd();

}
void twheel(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 45 * cos(th), y + 45 * sin(th));
    }

    glEnd();

}
void face(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(1, 0.75, 0.52);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 25 * cos(th), y + 35 * sin(th));
    }

    glEnd();

}
void hat(int x, int y)
{
    float th;
    glBegin(GL_POLYGON);
    glColor3f(0, 0.18, 0.53);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(x + 25 * cos(th), y + 15 * sin(th));
    }

    glEnd();

}
void deliveryguy() {
    face(-373, -225);
    hat(-373, -205);
    glPopMatrix();

    glColor3f(0, 0.18, 0.53); //hat
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(-395, -215);
    glVertex2f(-325, -215);
    glEnd();

    glColor3f(1, 0.75, 0.52); //skin
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(-395, -220);
    glVertex2f(-350, -220);
    glEnd();

    glColor3f(1, 0.7, 0.21); //Parcel
    glBegin(GL_POLYGON);
    glVertex2f(-350, -370);
    glVertex2f(-350, -300);
    glVertex2f(-290, -300);
    glVertex2f(-290, -370);
    glEnd();

    glColor3f(0.07, 0.11, 0.34); //Shirt
    glBegin(GL_POLYGON);
    glVertex2f(-405, -390);
    glVertex2f(-405, -300);
    glVertex2f(-350, -300);
    glVertex2f(-355, -390);
    glEnd();

    glColor3f(0, 0.44, 0.84); //Pant
    glBegin(GL_POLYGON);
    glVertex2f(-395, -500);
    glVertex2f(-405, -390);
    glVertex2f(-355, -390);
    glVertex2f(-365, -500);
    glEnd();

    glColor3f(0.08, 0.08, 0.08); //Shoe
    glBegin(GL_POLYGON);
    glVertex2f(-395, -525);
    glVertex2f(-395, -500);
    glVertex2f(-365, -500);
    glVertex2f(-350, -515);
    glVertex2f(-350, -525);
    glEnd();

    shirt(-377, -300);


    glColor3f(1, 0.75, 0.52); //hand
    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex2f(-375, -305);
    glVertex2f(-370, -345);
    glVertex2f(-370, -335);
    glVertex2f(-350, -335);
    glEnd();
    glutPostRedisplay();
}


void Screen8() {

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.45, 0.84, 1, 0);

    glColor3f(0, 0.7, 0.22); //Land 
    glBegin(GL_POLYGON);
    glVertex2f(-1300, -720);
    glVertex2f(-1300, -400);
    glVertex2f(1300, -400);
    glVertex2f(1300, -720);
    glEnd();


    drawBlueClouds(550, 450);  //Clouds
    drawBlueClouds(-350, 550);
    drawBlueClouds(950, 450);
    drawBlueClouds(-850, 550);

    glColor3f(1, 0.52, 0.23); //Chimney
    glBegin(GL_POLYGON);
    glVertex2f(-245, 150);
    glVertex2f(-245, 400);
    glVertex2f(-155, 400);
    glVertex2f(-155, 150);
    glEnd();

    glColor3f(0.99, 0.77, 0.48); //Chimney
    glBegin(GL_POLYGON);
    glVertex2f(-255, 400);
    glVertex2f(-255, 450);
    glVertex2f(-145, 450);
    glVertex2f(-145, 400);
    glEnd();

    glColor3f(0.97, 0.1, 0.1); //House 
    glBegin(GL_POLYGON);
    glVertex2f(-300, -400);
    glVertex2f(-300, 150);
    glVertex2f(0, 450);
    glVertex2f(300, 150);
    glVertex2f(300, -400);
    glEnd();

    borderglass(0, 250);
    blueglass(0, 250);
    glColor3f(0.99, 0.77, 0.48);
    glBegin(GL_LINES);
    glVertex2f(0, 195);
    glVertex2f(0, 300);
    glVertex2f(-55, 250);
    glVertex2f(55, 250);
    glEnd();

    glColor3f(0.99, 0.77, 0.48); //Steps 
    glBegin(GL_POLYGON);
    glVertex2f(-125, -400);
    glVertex2f(-125, -375);
    glVertex2f(125, -375);
    glVertex2f(125, -400);
    glEnd();
    glColor3f(0.88, 0.68, 0.42); //Steps 
    glBegin(GL_POLYGON);
    glVertex2f(-100, -375);
    glVertex2f(-100, -350);
    glVertex2f(100, -350);
    glVertex2f(100, -375);
    glEnd();

    glColor3f(0, 0.49, 0.59); //Door 
    glBegin(GL_POLYGON);
    glVertex2f(-90, -350);
    glVertex2f(-90, -10);
    glVertex2f(90, -10);
    glVertex2f(90, -350);
    glEnd();

    glColor3f(0, 0.4, 0.49); //Door 
    glBegin(GL_POLYGON);
    glVertex2f(-70, -330);
    glVertex2f(-70, -200);
    glVertex2f(70, -200);
    glVertex2f(70, -330);
    glEnd();

    int up = 170;

    glColor3f(0, 0.4, 0.49); //Door 
    glBegin(GL_POLYGON);
    glVertex2f(-70, -330 + up);
    glVertex2f(-70, -200 + up);
    glVertex2f(70, -200 + up);
    glVertex2f(70, -330 + up);
    glEnd();

    glColor3f(0.73, 0.73, 0.73); //Door Handle
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2f(-65, -180);
    glEnd();

    glLineWidth(5);
    glColor3f(0.99, 0.77, 0.48); //Door border 
    glBegin(GL_LINE_LOOP);
    glVertex2f(-90, -350);
    glVertex2f(-90, -10);
    glVertex2f(90, -10);
    glVertex2f(90, -350);
    glEnd();

    glColor3f(0.99, 0.77, 0.48); //Roof 
    glLineWidth(30);
    glBegin(GL_LINES);
    glVertex2f(-350, 120);
    glVertex2f(0, 450);
    glVertex2f(0, 450);
    glVertex2f(350, 120);
    glEnd();

    glColor3f(0.12, 0.67, 1); //Window 1
    glBegin(GL_POLYGON);
    glVertex2f(-265, -150);
    glVertex2f(-265, 50);
    glVertex2f(-135, 50);
    glVertex2f(-135, -150);
    glEnd();

    glLineWidth(5);
    glColor3f(0.99, 0.77, 0.48); //Window border
    glBegin(GL_LINE_LOOP);
    glVertex2f(-265, -150);
    glVertex2f(-265, 50);
    glVertex2f(-135, 50);
    glVertex2f(-135, -150);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-200, -150);
    glVertex2f(-200, 50);
    glVertex2f(-265, -50);
    glVertex2f(-135, -50);
    glEnd();

    int shift = 400;

    glColor3f(0.12, 0.67, 1); //Window 2
    glBegin(GL_POLYGON);
    glVertex2f(-265 + shift, -150);
    glVertex2f(-265 + shift, 50);
    glVertex2f(-135 + shift, 50);
    glVertex2f(-135 + shift, -150);
    glEnd();

    glColor3f(0.99, 0.77, 0.48); //Window 2 border
    glBegin(GL_LINE_LOOP);
    glVertex2f(-265 + shift, -150);
    glVertex2f(-265 + shift, 50);
    glVertex2f(-135 + shift, 50);
    glVertex2f(-135 + shift, -150);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-200 + shift, -150);
    glVertex2f(-200 + shift, 50);
    glVertex2f(-265 + shift, -50);
    glVertex2f(-135 + shift, -50);
    glEnd();

    int inc = 50;
    int dec = -50;
    int tshift = -50;
    int tshiftdown = 220;
    

    glLoadIdentity();
    txcounter = txcounter + 0.4;

    if (txcounter < 0)
    {
        glTranslatef(txcounter, 0, 0);
        indi = indi + 1;
        flag = 1;
       
    }
    
        twheel(-870 + tshift + inc - 140, -545 + tshiftdown + inc - 100);  //wheel

        glColor3f(0.88, 0.88, 0.88); //Truck tail
        glBegin(GL_POLYGON);
        glVertex2f(-930 + tshift + dec, -550 + tshiftdown + dec);
        glVertex2f(-930 + tshift + dec, -400 + tshiftdown + inc);
        glVertex2f(-630 + tshift + inc, -400 + tshiftdown + inc);
        glVertex2f(-630 + tshift + inc, -550 + tshiftdown + dec);
        glEnd();

        glColor3f(0.8, 0.8, 0.8); //Truck tail
        glBegin(GL_POLYGON);
        glVertex2f(-930 + tshift - 100 + dec, -550 + tshiftdown + dec);
        glVertex2f(-930 + tshift - 100 + dec, -400 + tshiftdown + inc);
        glVertex2f(-830 + tshift - 100 + inc, -400 + tshiftdown + inc);
        glVertex2f(-830 + tshift - 100 + inc, -550 + tshiftdown + dec);
        glEnd();

        glColor3f(0.43, 0.43, 0.43); //Truck tail
        glBegin(GL_POLYGON);
        glVertex2f(-930 + tshift - 100 + dec, -550 + tshiftdown + dec);
        glVertex2f(-930 + tshift - 100 + dec, -450 + tshiftdown + inc);
        glVertex2f(-830 + tshift - 100 + inc, -450 + tshiftdown + inc);
        glVertex2f(-830 + tshift - 100 + inc, -550 + tshiftdown + dec);
        glEnd();

        glColor3f(1, 0.36, 0.07); //Truck head
        glBegin(GL_POLYGON);
        glVertex2f(-630 + tshift + 100 + dec, -550 + tshiftdown + dec);
        glVertex2f(-630 + tshift + 100 + dec, -430 + tshiftdown + inc);
        glVertex2f(-570 + tshift + 100 + inc, -430 + tshiftdown + inc);
        glVertex2f(-530 + tshift + 100 + inc, -470 + tshiftdown + inc);
        glVertex2f(-530 + tshift + 100 + inc, -550 + tshiftdown + dec);
        glEnd();

        glColor3f(0.42, 0.7, 0.81); //Truck glass
        glBegin(GL_POLYGON);
        glVertex2f(-620 + tshift + 100 + dec + 10, -500 + tshiftdown + dec + 30);
        glVertex2f(-620 + tshift + 100 + dec + 10, -445 + tshiftdown + inc - 10);
        glVertex2f(-580 + tshift + 100 + inc - 10, -445 + tshiftdown + inc - 10);
        glVertex2f(-545 + tshift + 100 + inc - 10, -480 + tshiftdown + inc - 10);
        glVertex2f(-545 + tshift + 100 + inc - 10, -500 + tshiftdown + dec + 30);
        glEnd();

        twheel(-590 + tshift + inc + 60, -553 + tshiftdown + inc - 100);
        twhitewheel(-590 + tshift + inc + 60, -553 + tshiftdown + inc - 100);
        twheel(-690 + tshift + inc, -553 + tshiftdown + inc - 100);
        twhitewheel(-690 + tshift + inc, -553 + tshiftdown + inc - 100);
        twheel(-790 + tshift + inc - 60, -553 + tshiftdown + inc - 100);
        twhitewheel(-790 + tshift + inc - 60, -553 + tshiftdown + inc - 100);

        glColor3f(0, 0.12, 0.7);
        displayRasterText(-820 + tshift + inc, -540 + tshiftdown + inc, 0.0, "ekart");
    

    glLoadIdentity();
    if (indi == 1500) {

        counter3 = counter3 + 0.2;

        if (counter3 > 150.0) {

            ycounter = ycounter + 0.2;
            if (ycounter > 143.0) {
                glColor3f(0.54, 0.54, 0.54);
                displayRasterText(500, 0, 0, "Pakage has been delivered");
                glColor3f(0.37, 0.37, 0.37);
                displayRasterText(510, -100, 0, "PRESS U TO CONTINUE");

                glColor3f(0, 0, 0); //door black
                glBegin(GL_POLYGON);
                glVertex2f(-90, -350);
                glVertex2f(-90, -10);
                glVertex2f(90, -10);
                glVertex2f(90, -350);
                glEnd();
                glLoadIdentity();


                face(0, -80);

                glColor3f(0, 0, 0);
                glPointSize(4);
                glBegin(GL_POINTS);
                glVertex2f(-8, -78);
                glVertex2f(8, -78);
                glEnd();


                glColor3f(1, 0.87, 0.17); //shirt
                glBegin(GL_POLYGON);
                glVertex2f(32, -240);
                glVertex2f(32, -150);
                glVertex2f(-32, -150);
                glVertex2f(-32, -240);
                glEnd();

                yshirt(0, -180);

                glColor3f(1, 0.75, 0.52); //hand
                glLineWidth(7);
                glBegin(GL_LINES);
                glVertex2f(27, -140);
                glVertex2f(40, -140);
                glVertex2f(40, -140);
                glVertex2f(40, -220);
                glEnd();

                glColor3f(1, 0.75, 0.52); //hand
                glLineWidth(7);
                glBegin(GL_LINES);
                glVertex2f(-27, -140);
                glVertex2f(-40, -140);
                glVertex2f(-40, -140);
                glVertex2f(-40, -220);
                glEnd();


                glColor3f(0.06, 0.13, 0.48); //pant
                glBegin(GL_POLYGON);
                glVertex2f(32, -220);
                glVertex2f(29, -345);
                glVertex2f(-29, -345);
                glVertex2f(-32, -220);
                glEnd();

                yshoe(-15, -345);
                yshoe(15, -345);
                glLoadIdentity();
                glTranslated(300.0, 142.0, 0.0);
                deliveryguy();
            }
        }
        if (ycounter < 143) {

            glTranslated(counter3, ycounter, 0.0);
            deliveryguy();
            glutPostRedisplay();
            indi1 = indi1 + 1;
        }
        else {
            glTranslated(300.0, 142.0, 0.0);

        }

    }
    printf("%f    ", indi1);
    
    


    

    glFlush();
    glutSwapBuffers();
}


void Screen9()
{


    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.11, 0.33, 0.89, 1);
    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-850, 350, 0.0, "The importance of technology leading to e-commerce is largely appreciated");
    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-850, 250, 0.0, "These platforms help connect the proudcers and the consumers, which is an economic growth booster");
    glColor3f(1.0, 1.0, 1.0);
    displayRasterText(-850, 150, 0.0, "Although these companies may have their differences, they remain vital in the areas under which they operate");
    glColor3f(0.84, 0.83, 0.14);
   
    displayRasterText(-850, 0, 0.0, "THANK YOU !");

    glColor3f(0.97, 0.99, 0.18);
    displayRasterText(-200, -400, 0.0, "PRESS X TO EXIT ");


    glFlush();
    glutSwapBuffers();




}







//main display function
void display()
{
    keyOperations();
    glClear(GL_COLOR_BUFFER_BIT);


    switch (viewPage)
    {
    case SCREEN1:
        Screen1();
        break;
    case  SCREEN2:
        Screen2();
        break;
    case  SCREEN3:
        Screen3();
        break;
    case  SCREEN4:
        Screen4();
        break;
    case  SCREEN5:
        Screen5();
        break;
    case  SCREEN6:
        Screen6();
        break;
    case  SCREEN7:
        Screen7();
        break;
    case  SCREEN8:
        Screen8();
        break;
    case  SCREEN9:
        Screen9();
        break;
   
    }
    glFlush();
    glLoadIdentity();
    glutSwapBuffers();
}


// inbuilt functions//
void passiveMotionFunc(int x, int y) {


    mouseX = float(x) / (m_viewport[2] / 1200.0) - 600.0;
    mouseY = -(float(y) / (m_viewport[3] / 700.0) - 350.0);
    glutPostRedisplay();
}


void mouseClick(int buttonPressed, int state, int x, int y) {


    if (buttonPressed == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        mButtonPressed = true;
    else
        mButtonPressed = false;
    glutPostRedisplay();
}


void keyPressed(unsigned char key, int x, int y)
{
    keyStates[key] = true;
    glutPostRedisplay();
}


void keyReleased(unsigned char key, int x, int y)
{
    keyStates[key] = false;
}





void key(int key, int x, int y) {

    switch (key)
    {
    case GLUT_KEY_LEFT:
        shift=shift-5;
        if (shift == 1680) {
            viewPage = SCREEN7;
        }
        glutPostRedisplay();
        
        break;
    case GLUT_KEY_RIGHT:
        if (shift == 1680) {
            viewPage = SCREEN7;
        }
        shift= shift+5;
        
        glutPostRedisplay();
        
        break;
    
    
    }
   
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 50);
    glutInitWindowSize(1300.0, 700.0);
    glutCreateWindow("Working of Flipkart");
    glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(keyReleased);
    glutMouseFunc(mouseClick);
    glutPassiveMotionFunc(passiveMotionFunc);
    glGetIntegerv(GL_VIEWPORT, m_viewport);
    glutDisplayFunc(display);
    init();
    glutSpecialFunc(key);
    glutIdleFunc(car);
    glutMainLoop();
}




