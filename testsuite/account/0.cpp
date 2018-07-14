#include <iostream>
#include "user.h"
using namespace std;
using namespace roco;

int main()
{
    accfile af(666);
    account a;
    a.from_file(af);
    user u;
    cout<<u.login(a)<<endl;
    cout<<u<<endl;
    return 0;
}
