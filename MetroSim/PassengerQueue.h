/*
 * PassengerQueue.h
 * CS15 Project 1
 *
 * by Basak Percin, June 2022
 *
 * A PassengerQueue class that representes a queue of passengers and includes
 * functions.
 *
 */


#ifndef __PASSENGERQUEUE_H__
#define __PASSENGERQUEUE_H__

#include <iostream>
#include "Passenger.h"
#include <list>
#include <string>

struct PassengerQueue
{
    public:
        PassengerQueue();
        ~PassengerQueue();

        Passenger front();                                //front
        void      dequeue();                              //pop
        void      enqueue(const Passenger &passenger);    //push
        int       size();                                 //size
        
        void print(std::ostream &output);
        //Output: [1, 1->2][2, 1->3][3, 2->3][4, 2->3]

    private:
        std::list<Passenger> pQueue;
};

#endif