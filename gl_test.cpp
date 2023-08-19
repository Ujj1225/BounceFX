#include <iostream>
#include <GL/gl.h>
using namespace std;

int main()
{
    cout << "OpenGL Version: " << glGetString(GL_VERSION) << endl;
    return 0;
}
