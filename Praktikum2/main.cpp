#include <iostream>
#include "cpu.h"
#include "prozess.h"

using namespace std;

int main()
{
    CPU c;
    c.run("init.txt");
    return 0;
}
