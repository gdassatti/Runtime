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

    if(rtime.get_hours() == rhs.get_time().get_hours() && rtime.get_minutes() == rhs.get_time().get_minutes() && rtime.get_seconds() == rhs.get_time().get_seconds() && abs(distance - rhs.distance) < .10){

        return true;

    }else{

        return false;

    }

}

bool Runtime::operator !=(const Runtime& rhs)const{

    if(rtime.get_hours() == rhs.get_time().get_hours() && rtime.get_minutes() == rhs.get_time().get_minutes() && rtime.get_seconds() == rhs.get_time().get_seconds() && abs(distance - rhs.distance) < .10){

        return false;

    }else{

        return true;

    }

}

bool Runtime::distance_equal(double d)const{ // done

    if(abs(distance - d) > .10){

        return false;

    } else {

        return true;

    }

}

void Runtime::input(std::istream& ins){
    
    char c;

    ins >> rtime;
    ins.get(c);
    ins >> distance;

}

void Runtime::output(std::ostream& outs)const{

    outs << rtime;
    outs << "   ";
    outs << distance; 

}

Runtime operator *(const double& lhs, const Runtime& rhs){
    
    Runtime tmp;
    tmp.set_time(lhs * rhs.get_time());
    tmp.set_distance(lhs * rhs.get_distance());
    return tmp;

}

ostream& operator <<(std::ostream& outs, const Runtime& rhs){
    
    rhs.output(outs);
    return outs;

}

istream& operator >>(std::istream& ins, Runtime& rhs){
    
    rhs.input(ins);
    return ins;

}