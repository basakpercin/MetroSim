/*
 * PassengerQueue.cpp
 * CS15 Project 1
 * 
 * by Basak Percin, June 2022
 *
 * An implementation of the PassengerQueue.h interface, the PassengerQueue can
 * be used to create passenger queues in which passengers are given by command 
 * files or user inputs.
 *
 */


#include <iostream>
#include <string>
#include "PassengerQueue.h"

#include <list>    //list::front/pop_front/push_back/size


using namespace std;


//Initializes
PassengerQueue::PassengerQueue()
{
    pQueue = std::list<Passenger>();
}

PassengerQueue::~PassengerQueue()
{
    
}

/* Front - front
 *    Purpose: Gets the passenger at the front of the queue
 * Parameters: None
 *    Returns: Returns the first passenger at the queue
 */
Passenger PassengerQueue::front()
{
    return pQueue.front();
}

/* Dequeue - pop
 *    Purpose: Removes the passenger at the front of the queue
 * Parameters: None
 *    Returns: None
 */
void PassengerQueue::dequeue()
{
    pQueue.pop_front();  
}

/* Enqueue - push
 *    Purpose: Inserts a new passenger at the back of the queue
 * Parameters: A passenger object
 *    Returns: None
 */
void PassengerQueue::enqueue(const Passenger &passenger)
{
    pQueue.push_back(passenger);
}

/* Size
 *    Purpose: Gets the passenger at the front of the queue
 * Parameters: None
 *    Returns: Returns Size as integer
 */
int PassengerQueue::size()
{
    return pQueue.size();
}


/* Print
 *    Purpose: Prints each passenger in the queue to the output stream from
 *             front to back, each as [PASSENGER_ID, ARRIVAL->DEPARTURE] with
 *             no spaces or commas in between them.
 * Parameters: An ostream to print to
 *    Returns: None
 */
void PassengerQueue::print(std::ostream &output)
{
    for(auto it=pQueue.begin(); it != pQueue.end(); it++){
        it->print(output);
    }
}

//Passengers on the train: {[1, 0->2]
//[2, 0->3]
//}