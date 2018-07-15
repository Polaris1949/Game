#ifndef _ROCO_UI_H
#define _ROCO_UI_H 1

#include <string>

namespace roco
{

char getch();
void getch_b();
char getch_f();
void getch_e();
char getche();
int sleep(double __s);
void menu_fmt(const std::string& __s);
int ui_main();
void ui_login();
void ui_reg();
void ui_help();
void ui_exit();
void alert(const std::string& __s);
void alert_clear();

}

#endif
