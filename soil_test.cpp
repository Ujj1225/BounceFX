#include <SOIL/SOIL.h>
#include <iostream>

int main()
{
    if (SOIL_load_OGL_texture("/home/ujjwaljha/Graphics_project/pika.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y) == 0)
    {
        std::cout << "SOIL is not properly installed." << std::endl;
        return 1;
    }
    std::cout << "SOIL is properly installed." << std::endl;
    return 0;
}