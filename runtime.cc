#include "runtime.h"
#include "MyTime.h"
#include <iostream>
using namespace std;

Runtime::Runtime(){
    rtime = 0;
    distance = 0.0;
}

Runtime Runtime::operator +(const Runtime& rhs)const{
    Runtime tmp;
    tmp.rtime = rtime + rhs.rtime;
    tmp.distance = distance + rhs.distance;
    tmp.simplify();
    return tmp;
}