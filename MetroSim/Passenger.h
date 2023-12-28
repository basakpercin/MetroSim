/*
 * Passenger.h
 * CS15 Project 1
 *
 * by Basak Percin, June 2022
 *
 * A Passenger class that includes info and a print function regarding a 
 * passenger object.
 *
 */


#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>
#include <string>

struct Passenger
{

        int id, from, to;
        
        Passenger()
        {
                id   = -1;
                from = -1;
                to   = -1;
        }

        Passenger(int newId, int arrivalStation, int departureStation)
        {
                id   = newId;
                from = arrivalStation;
                to   = departureStation;
        }

        // implement the print function in Passenger.cpp
        void print(std::ostream &output);

};

#endif
