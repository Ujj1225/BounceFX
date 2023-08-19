#include <IL/il.h>
#include <iostream>

int main()
{
    ilInit();
    if (ilGetInteger(IL_VERSION_NUM) < IL_VERSION)
    {
        std::cout << "DevIL version mismatch" << std::endl;
        return 1;
    }
    std::cout << "DevIL is installed and working" << std::endl;
    return 0;
}