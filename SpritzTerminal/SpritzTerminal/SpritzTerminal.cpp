#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    bool foundJRE = false;

    string path = std::getenv("PATH");
    


    if (!foundJRE) {
        std::cout << "[ERROR]: Please install Java 8 (JRE) and add it to PATH!";
    }
    else {
        system("java -jar spritz-cl.jar");
    }
    return -1;
}