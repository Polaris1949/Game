#include <iostream>
#include "account.hpp"
using namespace std;
using namespace roco;

int main()
{
    accfile af(666);
    account a;
    a.from_file(af);
    user u;
    cout<<a.login(u, "ChenPi[2538]")<<endl;
    cout<<u<<endl;
    return 0;
}
