//**********************************************************//
// Runjournal class implementation file                     //
//                                                          //
// Contains the data for multiple runs (time and distance)  //
// Created by Gavin Dassatti                                //
// CS 2401                                                  //
// Last Modified 1/30/2020                                  //
//**********************************************************//
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include "runjournal.h"
#include "runtime.h"
using namespace std;


// default constructor initializes used to 0
Runjournal::Runjournal(){

    used = 0;

}

// record function takes in a run as a parameter 
// and adds it to the list
void Runjournal::record(Runtime run){

    if(used < CAPACITY){

        data[used] = run;
        used++;

    } else {

        cout << "Error. The list has reached maximum capacity :/" << endl;

    }

}

// display function displays all of
// runs in the list to the screen
void Runjournal::display()const{

    for(size_t i = 0; i < used; i++){

        cout << data[i] << endl;

    }

}

// find remove function takes in a run as a
// parameter compares the time from that run to
// all runs on the list and if they are equal
// it will display the distance and pace and asks 
// the user if they would like to remove it
void Runjournal::find_remove(Runtime& run){

    char y_n;

    for(size_t i = 0; i < used; i++){

        if(data[i].get_time() == run.get_time()){

            cout << endl;
            cout << "Distance: " << run.get_distance() << endl;
            cout << "Pace: " << run.pace() << endl;
            cout << "Would you like to remove this run from the list? (y/n): ";
            cin >> y_n;
            cout << endl;

            if(y_n == 'y'||y_n == 'Y'){

                data[i] = data[used - 1];
                used--;

            }

        }

    }

}

// distance view takes in a double as it's parameter, 
// compares that to every distance of every run in the list
// and displays the runs that match that distance
void Runjournal::distance_view(double distance){

    for(size_t i = 0; i < used; i++){

        if(data[i].get_distance() == distance){

            cout << data[i] << endl;

        }

    }

}

// the time sort function uses a bubble sort algorithm
// to sort the list of runs from least to greatest amount of
// time
void Runjournal::time_sort(){

    bool done = false;
    int j;
    Runtime tmp;   

    while(!done){

        done = true;

        for(j = used - 1; j > 0; --j){

            if(data[j].get_time() < data[j - 1].get_time()){

                done = false;
                tmp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = tmp;

            }

        }

    } 

}

// the distance sort function uses a bubble sort algorith 
// to sort the list of runs from least to greatest amount
// of distance
void Runjournal::distance_sort(){

    bool done = false;
    int j;
    Runtime tmp;

    while(!done){

        done = true;

        for(j = used - 1; j > 0; --j){

            if(data[j].get_distance() < data[j - 1].get_distance()){

                done = false;
                tmp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = tmp;

            }

        }

    }

}

// the total time function adds up all the time
// from every run in the list and displays it in
// hours::minutes::seconds format
string Runjournal::total_time()const{

    string total;
    Runtime tmp;

    for(size_t i = 0; i < used; i++){

        tmp.set_time(tmp.get_time() + data[i].get_time());

    }

    total = to_string(tmp.get_time().get_hours()) + ":" + to_string(tmp.get_time().get_minutes()) + ":" + to_string(tmp.get_time().get_seconds());
    
    return total;

}

//the total distance function returns the sum of
// all of the distances in the list of runs
double Runjournal::total_distance()const{

    double total = 0;

    for(size_t i = 0; i < used; i++){

        total += data[i].get_distance();

    }

    return total;

}

// the average pace function adds up the total distance
// and total amount of time for all of the runs in the list 
// and returns the average pace in hours::minutes::seconds
// format
string Runjournal::average_pace()const{

    double tot_distance = 0;
    string pace;
    Runtime tmp;

    for(size_t i = 0; i < used; i++){

        tot_distance += data[i].get_distance();
        tmp.set_time(tmp.get_time() + data[i].get_time());

    }

    tmp.set_time(tmp.get_time() / tot_distance);
    pace = to_string(tmp.get_time().get_hours()) + ":" + to_string(tmp.get_time().get_minutes()) + ":" + to_string(tmp.get_time().get_seconds());
    return pace;

}

// the save function outstreams the list of runs
// to the specified output file when the program
// concludes
void Runjournal::save(ostream& outs){

    for(size_t i = 0; i < used; i++){

        outs << data[i] << endl;

    }

}