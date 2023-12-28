/*
 * MetroSim.cpp
 * CS15 Project 1
 * 
 * by Basak Percin, June 2022
 *
 * An implementation of the MetroSim.h interface, the MetroSim can
 * be used to simulate the metro.
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "MetroSim.h"
#include "Train.h"

using namespace std;

MetroSim::MetroSim(Train *train, vector<PassengerQueue> stations, 
            int currentStation, vector<string> stationNames)
{
    this->train = train;
    this->stations = stations;
    this->currentStation = currentStation;
    this->stationNames = stationNames;
}

MetroSim::~MetroSim()
{

}

/* moveTrain
 *    Purpose: Moves train to next station.
 * Parameters: None.
 *    Returns: None
 */
void MetroSim::moveTrain()
{
    moveCurrentStationPassengersToTrain();

    ++currentStation;
    int numStations = stations.size();
    if (currentStation == numStations) {
        currentStation = 0;
    }

    this->train->removePassenger(currentStation);
    // moveCurrentStationPassengersToTrain();
}

/* addPassenger
 *    Purpose: Adds passengers to stations according to their arrival stations.
 * Parameters: Passenger object.
 *    Returns: None
 */
void MetroSim::addPassenger(Passenger p)
{
    int arr = p.from;
    stations[arr].enqueue(p);
}

/* Print
 *    Purpose: Prints the simulation.
 * Parameters: An ostream to print to
 *    Returns: None
 */
void MetroSim::print(std::ostream &output)
{
    output << "Passengers on the train: {";
    this->train->print(output);
    output << "}" << endl;

    int i = 0;
    for(auto it=stations.begin(); it != stations.end(); it++){
        if(i == currentStation) {
            output << "TRAIN: ";
        } else {
            output << "       ";
        }
        output << "[" << i << "] " << stationNames[i] << " {";
        it->print(output);
        output << "}" << endl;
        i++;
    }
}

void MetroSim::moveCurrentStationPassengersToTrain()
{
    while (stations[currentStation].size() != 0) 
    {
        this->train->addPassenger(stations[currentStation].front());
        stations[currentStation].dequeue();
    }
}