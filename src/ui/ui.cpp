#include "ui.h"
#include "account/user.h"
#include "console.h"
#include "textbox.h"
#include <cstdlib>

namespace roco
{

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
    char ch; bool e;
    getch_b();

    while (ch = getch_f())
    {
        switch (ch)
        {
            case 'L': case 'l': getch_e(); e = ui_login(); break;
            case 'R': case 'r': getch_e(); ui_reg();  e = 0; break;
            case 'H': case 'h': getch_e(); ui_help(); e = 0; break;
            case 'E': case 'e': getch_e(); ui_exit(); e = 1; break;
            default: alert_ex("Unknown option!");     e = 0; break;
        }
        if (e) break;
        else getch_b();
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
    }
    getch_e();
    pol::console.show_cursor();
    pol::console.purge();
    pol::console.clear_screen();
    pol::console.locate(0, 0);
    return 0;
}

bool ui_login()
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
        std::cout << "Ctrl+B";
        pol::console.purge();
        pol::console.foreground_color(1);
        std::cout << " to cancel the register, or use ";
        pol::console.highlight();
        std::cout << "Ctrl+E";
        pol::console.purge();
        pol::console.foreground_color(1);
        std::cout << " to echo on/off the password.";
        pol::console.purge();

        unsigned id;

        if (!numboxin_ex({1,8}, id))
        {
            alert_ex("Login cancelled!");
            sleep(1);
            return false;
        }

        account a;
        a.from_file(std::move(accfile(id)));

        if (a.name().front() == '?')
        {
            alert_ex("Bad userid!");
            std::cin.clear();
            continue;
        }

        alert_clear();
        std::string pwd;
        pwdboxin({2,10}, pwd);

        if (a.pwd() != pwd)
        {
            alert_ex("Bad password!");
            continue;
        }

        alert_clear();
        user u;
        u.login(a);
        alert_ex("Login successfully!");
        sleep(1);
        return true;
    }
}

bool ui_reg()
{
    pol::console.clear_screen();

    while (true)
    {
        pol::console.locate(36, 0);
        pol::console.highlight();
        std::cout << "Register";
        pol::console.purge();
        pol::console.locate(0, 1);
        std::cout << "Userid: ";
        pol::console.clear_line_after();
        pol::console.locate(0, 2);
        std::cout << "Username: ";
        pol::console.clear_line_after();
        pol::console.locate(0, 3);
        std::cout << "Password: ";
        pol::console.clear_line_after();

        pol::console.locate(0, 4);
        pol::console.foreground_color(1);
        std::cout << "Note: You can use ";
        pol::console.highlight();
        std::cout << "Ctrl+B";
        pol::console.purge();
        pol::console.foreground_color(1);
        std::cout << " to cancel the register, or use ";
        pol::console.highlight();
        std::cout << "Ctrl+E";
        pol::console.purge();
        pol::console.foreground_color(1);
        std::cout << " to echo on/off the password.";
        pol::console.purge();

        unsigned id;

        if (!numboxin_ex({1,8}, id))
        {
            alert_ex("Register cancelled!");
            sleep(1);
            return false;
        }

        if (!id)
        {
            alert_ex("Bad userid!");
            std::cin.clear();
            continue;
        }

        if (accfile(id).is_open())
        {
            alert_ex("Account existed!");
            continue;
        }

        alert_clear();
        std::string name;

        if (!textboxin_ex({2,10}, name))
        {
            alert_ex("Register cancelled!");
            sleep(1);
            return false;
        }

        std::string pwd;
        pwdboxin({3,10}, pwd);

        user u;
        if (!u.reg(account(id, name, pwd)))
        {
            alert("Register failed!");
            continue;
        }

        alert("Register successfully!");
        sleep(1);
        return true;
    }
}

void ui_help()
{}

void ui_exit()
{}

}
