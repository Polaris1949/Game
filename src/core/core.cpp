#include "core.h"
#include "console.h"
#include <cstdlib>

namespace roco
{

char getch()
{
    char c;
    system("stty -echo");
    system("stty -icanon");
    c=getchar();
    system("stty icanon");
    system("stty echo");
    return c;
}

void getch_b()
{
    system("stty -echo");
    system("stty -icanon");
}

char getch_f()
{
    return getchar();
}

void getch_e()
{
    system("stty icanon");
    system("stty echo");
}

char getche()
{
    char c;
    system("stty -icanon");
    c=getchar();
    system("stty icanon");
    return c;
}

int sleep(double __s)
{
    return ::system((std::string("sleep ") + std::to_string(__s)).data());
}

void alert(const std::string& __s)
{
    pol::console.purge();
    pol::console.save_cursor();
    pol::console.locate(0, 23);
    pol::console.highlight();
    std::cout << __s;
    std::cout.flush();
    pol::console.recover_cursor();
    pol::console.purge();
}

void alert_clear()
{
    pol::console.purge();
    pol::console.save_cursor();
    pol::console.locate(0, 23);
    pol::console.clear_line_after();
    pol::console.recover_cursor();
    pol::console.purge();
}

void alert_ex(const std::string& __s)
{
    alert_clear();
    alert(__s);
}

int stoi_ex(const std::string& __s)
{
    try
    {
        return std::stoi(__s);
    }
    catch (...)
    {
        return 0;
    }
}

}
