/*
 * Passenger.cpp
 * CS15 Project 1
 * 
 * by Basak Percin, June 2022
 *
 * An implementation of the Passenger.h interface, the Passenger.cpp prints 
 * passenger data as id, arrival station and destination station.
 *
 */

#include <iostream>
#include <string>
#include "Passenger.h"

using namespace std;

/* Print
 *    Purpose: Prints the passenger information to the output stream
 * Parameters: An ostream to print to
 *    Returns: None
 *     Output: Expected output as: [PASSENGER_ID, ARRIVAL->DEPARTURE]
 */
void Passenger::print(std::ostream &output)
{
        output << "[" << this->id << ", " << this->from << "->" << this->to 
        << "]";
}
