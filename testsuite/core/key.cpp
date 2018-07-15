#include <iostream>
#include <fstream>
#include <libp/include/console.h>
#include "ui.h"

int main()
{
    std::ofstream fout("key.txt");
    pol::console.clear_screen();
    pol::console.show_cursor();
    pol::console.locate(0, 0);
    std::cout << "Password: ";
    std::cout.flush();
    roco::getch_b();
    char ch;
    std::string pwd;
    bool echo = false;

    while (ch = roco::getch_f())
    {
        fout<<ch;
        if (ch == 127)
        {
            if (!pwd.empty())
            {
                pwd.pop_back();
                std::cout << '\b';
                std::cout.flush();
                pol::console.clear_line_after();
            }
            continue;
        }
        if (ch == 5)
        {
            if (echo)
            {
                echo = false;
                pol::console.locate(10, 0);
                for (std::size_t i=0; i<pwd.size(); ++i)
                    std::cout << '*';
            }
            else
            {
                echo = true;
                pol::console.locate(10, 0);
                for (std::size_t i=0; i<pwd.size(); ++i)
                    std::cout << pwd[i];
            }
            continue;
        }
        if (ch == '\n') break;
        pwd += ch;
        if (echo) std::cout << ch;
        else std::cout << '*';
        std::cout.flush();
    }
    roco::getch_e();
    for (char c:pwd) fout << (int)c << '|';
    fout<<'\n';
    return 0;
}
