#ifndef _ROCO_CORE_H
#define _ROCO_CORE_H 1

#include "config.h"
#include <string>

namespace roco
{

char getch();
void getch_b();
char getch_f();
void getch_e();
char getche();
int sleep(double __s);
void alert(const std::string& __s);
void alert_clear();
void alert_ex(const std::string& __s);
int stoi_ex(const std::string& __s);

}

#endif
