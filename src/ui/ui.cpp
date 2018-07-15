#include "ui.h"
#include "account/user.h"
#include <polaris/console>
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

void menu_fmt(const std::string& __s)
{
    pol::console.purge();
    pol::console.underline();
    std::cout << __s.front();
    pol::console.purge();
    std::cout << (__s.data() + 1) << '\n';
}

int ui_main()
{
    pol::console.clear_screen();
    pol::console.locate(0, 0);
    std::cout << "Welcome to Roco World!\n\n";
    std::cout << "Menu: \n";
    menu_fmt("Login");
    menu_fmt("Register");
    menu_fmt("Help");
    menu_fmt("Exit");
    std::cout.flush();
    pol::console.hide_cursor();
    char ch;
    while (ch = getch())
    {
        if (ch == 'L' || ch == 'l')
        {
            ui_login();
            break;
        }
        else if (ch == 'R' || ch == 'r')
        {
            ui_reg();
            break;
        }
        else if (ch == 'H' || ch == 'h')
        {
            ui_help();
            break;
        }
        else if (ch == 'E' || ch == 'e')
        {
            ui_exit();
            break;
        }
        else
        {
            alert("Unknown option!");
            continue;
        }
    }

    pol::console.show_cursor();
    pol::console.purge();
    pol::console.clear_screen();
    pol::console.locate(0, 0);
    return 0;
}

void ui_login()
{
    pol::console.clear_screen();

    while (true)
    {
        pol::console.locate(38, 0);
        pol::console.highlight();
        std::cout << "Login";
        pol::console.purge();
        pol::console.locate(0, 1);
        std::cout << "Userid: ";
        pol::console.clear_line_after();
        pol::console.locate(0, 2);
        std::cout << "Password: ";
        pol::console.clear_line_after();

        pol::console.locate(0, 4);
        pol::console.foreground_color(1);
        std::cout << "Note: You can use ";
        pol::console.highlight();
        std::cout << "Ctrl+E";
        pol::console.purge();
        pol::console.foreground_color(1);
        std::cout << " to echo on/off the password.";
        pol::console.purge();

        pol::console.locate(8, 1);
        unsigned id;
        std::string pwd;
        pol::console.show_cursor();
        std::cin >> id;
        pol::console.hide_cursor();
        accfile af(id);
        account a;
        a.from_file(af);

        if (a.name().front() == '?')
        {
            alert_clear();
            alert("Bad userid!");
            std::cin.clear();
            std::cin >> pwd;
            continue;
        }

        alert_clear();
        pol::console.locate(10, 2);
        pol::console.show_cursor();
        getch_b();
        char ch = getch_f();
        bool echo = false;

        while (ch = getch_f())
        {
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
                    pol::console.locate(10, 2);
                    for (std::size_t i=0; i<pwd.size(); ++i)
                        std::cout << '*';
                }
                else
                {
                    echo = true;
                    pol::console.locate(10, 2);
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
        getch_e();

        pol::console.hide_cursor();

        if (a.pwd() != pwd)
        {
            alert_clear();
            alert("Bad password!");
            continue;
        }

        alert_clear();
        user u;
        u.login(a);
        alert("Login succesfully!");
        sleep(1);
        break;
    }
}

void ui_reg()
{}

void ui_help()
{}

void ui_exit()
{}

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

}
