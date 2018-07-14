#include "ui.h"
#include <polaris/console>
#include <unistd.h>

namespace roco
{

int ui_main()
{
    pol::console.locate(0, 0);
    std::cerr << "Menu: " << std::endl;
    ::sleep(1);
    pol::console.locate(0, 0);
    pol::console.clear_screen();
    return 0;
}

}
