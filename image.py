from OpenGL.GLUT import *
from OpenGL.GL import *
from OpenGL.GLU import *
import sys

# Global variable to store the texture ID
imageTexture = None

def display():
    glClear(GL_COLOR_BUFFER_BIT)

    if imageTexture is not None:
        glEnable(GL_TEXTURE_2D)
        glBindTexture(GL_TEXTURE_2D, imageTexture)
        
        glBegin(GL_QUADS)
        glTexCoord2f(0.0, 0.0)
        glVertex2f(0.0, 0.0)
        glTexCoord2f(1.0, 0.0)
        glVertex2f(1.0, 0.0)
        glTexCoord2f(1.0, 1.0)
        glVertex2f(1.0, 1.0)
        glTexCoord2f(0.0, 1.0)
        glVertex2f(0.0, 1.0)
        glEnd()
        
        glDisable(GL_TEXTURE_2D)

    glutSwapBuffers()

def main():
    glutInit(sys.argv)
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE)
    glutInitWindowSize(500, 500)
    glutCreateWindow(b"ImageFX")
    
    global imageTexture
    imageTexture = glGenTextures(1)
    
    # Loading image using Pillow (PIL)
    from PIL import Image
    img = Image.open("pika.jpg")
    img_data = img.tobytes()
    
    glBindTexture(GL_TEXTURE_2D, imageTexture)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img.width, img.height, 0, GL_RGB, GL_UNSIGNED_BYTE, img_data)
    
    glutDisplayFunc(display)
    glutMainLoop()

if __name__ == "__main__":
    main()
