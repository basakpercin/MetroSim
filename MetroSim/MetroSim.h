/*
 * MetroSim.h
 * CS15 Project 1
 *
 * by Basak Percin, June 2022
 *
 * A MetroSim class that includes functions that moves the train and adds 
 * passengers to the simulation.
 *
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include <vector>
#include <fstream>
#include <string>

#include "Passenger.h"
#include "Train.h"
#include "PassengerQueue.h"

using namespace std;

class MetroSim
{
public:
    MetroSim(Train *train, std::vector<PassengerQueue> stations, 
            int currentStation, std::vector<string> stationNames);
    ~MetroSim();

    void moveTrain();
    void addPassenger(Passenger p);
    
    void print(std::ostream &output);
    
private:
    Train *train;
    std::vector<PassengerQueue> stations;
    int currentStation;
    std::vector<string> stationNames;
    void moveCurrentStationPassengersToTrain();
};

#endif
