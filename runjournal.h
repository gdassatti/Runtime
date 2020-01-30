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

class Runjournal{

    public:

        static const size_t CAPACITY = 100;

        // default constructor
        Runjournal();

        void record(Runtime run);

        void display()const;

        void find_remove(Runtime& run);

        void distance_view(double distance);

        void time_sort();

        void distance_sort();

        std::string total_time()const;

        double total_distance()const;

        std::string average_pace()const;

        void save(std::ostream& outs);

    private:

        Runtime data[CAPACITY];
        size_t used;

};

#endif