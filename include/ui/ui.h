#ifndef _ROCO_UI_H
#define _ROCO_UI_H 1

#include <string>
#include "core.h"

namespace roco
{

void menu_fmt(const std::string& __s);
int ui_main();
bool ui_login();
bool ui_reg();
void ui_help();
void ui_exit();

}

#endif
