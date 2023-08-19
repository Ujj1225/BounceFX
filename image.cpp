#include "glad/glad.h"
#include <GL/glut.h>
#include <iostream>
#include <IL/il.h>

using namespace std;

GLuint imageTexture; // Global variable to store the texture ID

void display(void)
{
    // First clearing all the pixel of frame buffer to default color
    glClear(GL_COLOR_BUFFER_BIT);

    // Bind the texture
    glBindTexture(GL_TEXTURE_2D, imageTexture);

    // Drawing a rectangle using the image
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0);
    glVertex2f(0.0, 0.0);
    glTexCoord2f(1.0, 0.0);
    glVertex2f(1.0, 0.0);
    glTexCoord2f(1.0, 1.0);
    glVertex2f(1.0, 1.0);
    glTexCoord2f(0.0, 1.0);
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

    // Set up OpenGL context
    // glEnable(GL_DEPTH_TEST);
    // Enable depth testing
    // glClearColor(0.0, 0.0, 0.0, 1.0);
    // Set clear color to black

    // Initializing DevIL
    ilInit();

    // Generating image ID to reference loaded images
    ILuint imageID;
    ilGenImages(1, &imageID);

    // Set the newly generated image as the current working image
    ilBindImage(imageID);

    // Loading image
    if (ilLoadImage("pika.jpg"))
    {
        // Generate a texture ID
        glGenTextures(1, &imageTexture);

        // Bind the texture
        glBindTexture(GL_TEXTURE_2D, imageTexture);

        // Set texture parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // Convert the image to RGBA format
        ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);

        // Get image width and height
        int width = ilGetInteger(IL_IMAGE_WIDTH);
        int height = ilGetInteger(IL_IMAGE_HEIGHT);

        // Get image data
        ILubyte *imageData = ilGetData();

        // Load the image data into the texture
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

        // Image loaded successfully message
        cout << "Successful image loading" << endl;
    }
    else
    {
        // Failed to load image message
        cout << "Failed to load image" << endl;
    }

    // Set the display function and start the main loop
    glutDisplayFunc(display);
    glutMainLoop();

    // Delete the DevIL image and cleanup
    ilDeleteImages(1, &imageID);

    return 0;
}
