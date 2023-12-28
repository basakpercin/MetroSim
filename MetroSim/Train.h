/*
 * Train.h
 * CS15 Project 1
 *
 * by Basak Percin, June 2022
 *
 * A Train class that representes a list of PassengerQueues ordered by 
 * destination stations.
 *
 */

#ifndef __TRAIN_H__
#define __TRAIN_H__

#include <fstream>
#include <vector>
#include <string>

#include "Passenger.h"
#include "PassengerQueue.h"

using namespace std;

class Train
{
    public:
        Train();
        Train(int numStations, vector<string> stationNames, ofstream *outputFile);
        Train(const Train &other);
        Train &operator=(const Train &other);
        ~Train();

        void removePassenger(int currentStation);
        void addPassenger(Passenger p);
        void print(std::ostream &output);

    private:
        std::vector<PassengerQueue> wagons;
        std::ofstream *outputFile;
        std::vector<string> stationNames;
};

#endif