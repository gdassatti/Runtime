//**********************************************************//
// Runjournal class implementation file                     //
//                                                          //
// Contains the data for multiple runs (time and distance)  //
// Created by Gavin Dassatti                                //
// CS 2401                                                  //
// Last Modified 1/29/2020                                  //
//**********************************************************//
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include "runjournal.h"
#include "runtime.h"
using namespace std;

Runjournal::Runjournal(){

    used = 0;

}

void Runjournal::record(Runtime run){

    if(used < CAPACITY){

        data[used] = run;
        used++;

    } else {

        cout << "Error. The list has reached maximum capacity :/" << endl;

    }

}

void Runjournal::display()const{

    for(size_t i = 0; i < used; i++){

        cout << data[i] << endl;

    }

}

void Runjournal::find_remove(Runtime& run){

    char y_n;

    for(size_t i = 0; i < used; i++){

        if(data[i].get_time() == run.get_time()){

            cout << "Distance: " << run.get_distance() << endl;
            cout << "Pace: " << run.get_pace() << endl;
            cout << "Would you like to remove this run from the list? (y/n): ";
            cin >> y_n;

            if(y_n == 'y'||y_n == 'Y'){

                data[i] = data[used - 1];
                used--;

            }

        }

    }

}

void Runjournal::distance_view(double distance){

    for(size_t i = 0; i < used; i++){

        if(data[i].get_distance() == distance){

            cout << data[i] << endl;

        }

    }

}

void Runjournal::time_sort(){

    bool done = false;
    int j;
    Runtime tmp;   

    while(!done){

        done = true;

        for(j = used - 1; j > 0; --j){

            if(data[j].get_time() < data[j-1].get_time()){

                done = false;
                tmp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = tmp;

            }

        }

    } 

}

void Runjournal::distance_sort(){

    bool done = false;
    int j;
    Runtime tmp;

    while(!done){

        done = true;

        for(j = used - 1; j < 0; --j){

            if(data[j].get_distance() < data[j - 1].get_distance()){

                done = false;
                tmp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = tmp;

            }

        }

    }

}

string Runjournal::total_time()const{

    string total;
    Runtime tmp;

    for(size_t i = 0; i < used; i++){

        tmp.set_time(tmp.get_time() + data[i].get_time());

    }

    total = "Hours: " + to_string(tmp.get_time().get_hours()) + " Minutes: " + to_string(tmp.get_time().get_minutes()) + " Seconds: " + to_string(tmp.get_time().get_seconds());
    
    return total;

}

double Runjournal::total_distance()const{

    double total = 0;

    for(size_t i = 0; i < used; i++){

        total += data[i].get_distance();

    }

    return total;

}

string Runjournal::average_pace()const{

    double tot_distance = 0;
    string pace;
    Runtime tmp;

    for(size_t i = 0; i < used; i++){

        tot_distance += data[i].get_distance;
        tmp.set_time(tmp.get_time() + data[i].get_time());

    }

    tmp.set_time(tmp.get_time() / tot_distance);
    pace = to_string(tmp.get_time().get_hours()) + ":" + to_string(tmp.get_time().get_minutes()) + ":" + to_string(tmp.get_time().get_seconds());
    return pace;

}

void Runjournal::save(ostream& outs){

    for(int i = 0; i < used; i++){

        outs << data[i] << endl;

    }

}