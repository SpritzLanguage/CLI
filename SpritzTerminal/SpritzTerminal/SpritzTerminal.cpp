#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    bool foundJRE = false;

    string path = "";
    char* buf = nullptr;
    size_t sz = 0;
    if (_dupenv_s(&buf, &sz, "PATH") == 0 && buf != nullptr)
    {
        path = buf;
        free(buf);
    }
    if (path.find("java") != std::string::npos) {
        foundJRE = true;
    }


    if (!foundJRE) {
        std::cout << "[ERROR]: Please install Java 8 (JRE) and add it to PATH!";
    }
    else {
        system("java -jar spritz-cl.jar");
    }
    return -1;
}