// In this module, we will have a simple functionality to load images from user's computer
// We will display the loaded image in applicaiton window
#include "glad/glad.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <SOIL/SOIL.h>
using namespace std;
void display(void)
{
    // First clearing all the pixel of frame buffer to default color
    glClear(GL_COLOR_BUFFER_BIT);
    cout << "Loading image from: " << "pika.jpg" << endl;
    // Loading image
    GLint imageTexture = SOIL_load_OGL_texture("pika.jpg", 0, 0, 0);
    // Checking for error while loading
    if (imageTexture == 0)
    {
        cout << "Failed to load image" << endl;
    }
    // Bindtexture tells OpenGL to use the loaded image for rendering
    glBindTexture(GL_TEXTURE_2D, imageTexture);
    // Drawing a rectangle using the image
    glBegin(GL_QUADS);
    // glColor3f(1.0, 0.5, 0.5);
    // We cant specify color because we have provided the texture
    glVertex2f(0.0, 0.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(1.0, 1.0);
    glVertex2f(0.0, 1.0);
    glEnd();
    // To swap front and back buffers which helps in smooth animation
    glutSwapBuffers();
}
int main(int argc, char **argv)
{
    // Initializing glut library
    glutInit(&argc, argv);
    // Initializing display mode
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(500, 500);
    glutCreateWindow("ImageFX");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}