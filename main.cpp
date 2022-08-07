#include <iostream>
#include <vector>

#include "Menu.h"

int main()
{
    std::vector<std::string> options = {
        "hello",
        "world",
    };

    int idx = menu::draw(options);

    system("cls");
    switch (idx)
    {
    case 0:
        std::cout << "world!" << std::endl;
        std::cin.get();
        break;
    case 1:
        std::cout << "hello" << std::endl;
        std::cin.get();
        break;
    }

    system("pause > nul");

    return 0;
}