//**********************************************************************************************//
//  Runjournal class header file                                                                //
//                                                                                              //
//  Contains an array of run time objects (hours::minutes::seconds) and the distance for each   //
//  Created by Gavin Dassatti                                                                   //
//  CS 2401                                                                                     //
//  Last modified: 1/29/2020                                                                    //
//**********************************************************************************************//
#ifndef RUNJOURNAL_H
#define RUNJOURNAL_H
#include "runtime.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

class Runjournal{ // declaration of Runjournal class

    public:

        // constant used for the size of array
        static const size_t CAPACITY = 100;

        // default constructor
        Runjournal();

        // the record function adds an additonal run to the back of the list
        // if there is enough room to store it
        void record(Runtime run);

        // the display function displays all of 
        // the different runs to the output sreen
        void display()const;

        // the find_remove function locates a run with a particular time,
        // displays the distance and pace to the screen and gives you the
        // option to remove it from the array
        void find_remove(Runtime& run);

        // the distance_view function takes in a specific distance as its parameter, 
        // searches the array for a run or runs with that same distance and outputs
        // the run or runs to the screen
        void distance_view(double distance);

        // the time_sort function uses a bubble sort algorithm to sort the list of runs
        // from least to greatest time
        void time_sort();

        // the distance_sort function uses a bubble sort algorithm to sort the list of runs
        // from least to greatest distance
        void distance_sort();

        // the total_time function flows through the list and adds up the time for each run
        // and returns the total amount of time as a string
        std::string total_time()const;

        // the total_distance function flows through the list and adds up the distance for
        // each run and returns the total distance as a double
        double total_distance()const;

        // the average_pace function adds up the total amount of time and the total distance
        // and divides the time by the distance and returns the average pace as a string
        std::string average_pace()const;

        // the save function outputs the updated version of the list to a new file
        void save(std::ostream& outs);

    private:

        // array of class Runtime which stores all the different runs and their data
        Runtime data[CAPACITY];

        // variable that is going to be the same as how many elements there are in the array
        size_t used;

};

#endif