//************************************************//
// Runtime class implementation file              //
//                                                //
// Contains the time and distance data for a run  //
// Created by Gavin Dassatti                      //
// CS 2401                                        //
// Last date modified 1/29/2020                   //                      
//************************************************//
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
    return tmp;

}

Runtime Runtime::operator -(const Runtime& rhs)const{

    Runtime tmp;
    tmp.rtime = rtime - rhs.rtime;
    tmp.distance = distance - rhs.distance;
    return tmp;

}

Runtime Runtime::operator *(const double& rhs)const{

    Runtime tmp;
    tmp.rtime = rtime * rhs;
    tmp.distance = distance * rhs;
    return tmp;

}

Runtime Runtime::operator /(const double& rhs)const{

    Runtime tmp;
    tmp.rtime = rtime / rhs;
    tmp.distance = distance / rhs;
    return tmp;

}

bool Runtime::operator ==(const Runtime& rhs)const{

    if(rtime == rhs.rtime && distance == rhs.distance){

        return true;

    }else{

        return false;

    }

}

bool Runtime::operator !=(const Runtime& rhs)const{

    if(rtime != rhs.rtime && distance != rhs.distance){

        return true;

    }else{

        return false;

    }

}

bool Runtime::distance_equal(double d)const{

    if(distance == d){

        return true;

    }
    
}

void Runtime::input(istream& ins){
    // do something
}

void Runtime::output(ostream& outs)const{
    // do something
}

Runtime operator *(const double& lhs, const Runtime& rhs){
    // do something
}

ostream& operator <<(std::ostream& outs, const Runtime& rhs){
    // do something
}

istream& operator >>(std::istream& ins, Runtime& rhs){
    // do something
}