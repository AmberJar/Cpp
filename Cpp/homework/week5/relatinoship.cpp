#include <iostream>
#include <cstring>
using namespace std;

class CMaster;

class CDog{
    CMaster *pm;
};

class CMaster{
    CDog *dog[10];
};