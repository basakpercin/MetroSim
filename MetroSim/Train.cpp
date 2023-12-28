/*
 * Train.cpp
 * CS15 Project 1
 * 
 * by Basak Percin, June 2022
 *
 * An implementation of the Train.h interface, the Train can be used to add or
 * remove Passengers to and from the train and prints who left the train at 
 * which station.
 *
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Train.h"
#include "PassengerQueue.h"


using namespace std;

Train::Train()
{
//     std::vector<PassengerQueue> this->wagons(0);
//     this->outputFile = cout;
}

Train::Train(int numStations, vector<string> stationNames, ofstream *outputFile)
{
    this->wagons = std::vector<PassengerQueue> (numStations);
    this->outputFile = outputFile;
    this->stationNames = stationNames;
}

Train::Train(const Train &other)
{

}

Train &Train::operator=(const Train &other)
{

}

Train::~Train()
{

}

/* removePassenger
 *    Purpose: Removes passengers from wagons according to their destination
 *             stations and writes the removed passenger to output file.
 * Parameters: Current Station as int.
 *    Returns: None
 */
void Train::removePassenger(int currentStation)
{
    while (wagons[currentStation].size() != 0)
    {
        Passenger passengerToRemove = wagons[currentStation].front();
        *outputFile << "Passenger " << passengerToRemove.id << " left train at " 
                << "station " << stationNames[currentStation] << endl;
        wagons[currentStation].dequeue();
    }
}

/* addPassenger
 *    Purpose: Adds passengers to wagons according to their destination
 *             stations.
 * Parameters: Passenger object.
 *    Returns: None
 */
void Train::addPassenger(Passenger p)
{
    int dest = p.to;
    wagons[dest].enqueue(p);
}

/* Print
 *    Purpose: Prints the passengers on the train.
 * Parameters: An ostream to print to
 *    Returns: None
 */
void Train::print(std::ostream &output)
{
    //iterates over wagons and uses print of passengerqueues?
    for(auto it=wagons.begin(); it!= wagons.end(); it++)
    {
        it->print(output);
    }
}