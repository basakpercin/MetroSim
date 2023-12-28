/*
 * unit_test.cpp
 * CS15 Project 1
 * 
 * by Basak Percin, June 2022
 *
 * An implementation of the unit tests for the Metro Simulator.
 * 
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include "MetroSim.h"
#include "Train.h"

using namespace std;

int main()
{
    vector<string> testStationNames;
    testStationNames.push_back("0th Station");
    testStationNames.push_back("1st Station");
    testStationNames.push_back("2nd Station");
    testStationNames.push_back("3rd Station");
    testStationNames.push_back("4th Station");

    ofstream testOutputs("test_outputs.txt");

    Train *testTrain =  new Train(5, testStationNames, &testOutputs); 
    vector<PassengerQueue> stations(5);
    MetroSim testSim = MetroSim(testTrain, stations, 0, testStationNames);

    testSim.addPassenger(Passenger(1, 1, 2));
    testSim.addPassenger(Passenger(2, 1, 3));
    testSim.addPassenger(Passenger(3, 1, 2));
    testSim.addPassenger(Passenger(4, 2, 3));
    testSim.addPassenger(Passenger(5, 2, 4));
    testSim.addPassenger(Passenger(6, 3, 4));
    testSim.addPassenger(Passenger(7, 3, 4));

    testSim.moveTrain();
    testSim.moveTrain();
    testSim.moveTrain();
    testSim.moveTrain();
    testSim.moveTrain();
    testSim.moveTrain();
    testSim.moveTrain();
    testSim.moveTrain();

    vector<string> testExpected;
    testExpected.push_back("Passenger 1 left train at station 2nd Station");
    testExpected.push_back("Passenger 3 left train at station 2nd Station");
    testExpected.push_back("Passenger 2 left train at station 3rd Station");
    testExpected.push_back("Passenger 4 left train at station 3rd Station");
    testExpected.push_back("Passenger 5 left train at station 4th Station");
    testExpected.push_back("Passenger 6 left train at station 4th Station");
    testExpected.push_back("Passenger 7 left train at station 4th Station");

    testOutputs.close();

    ifstream actualOutputFile("test_outputs.txt");
    string line;
    int i = 0;
    if(actualOutputFile.is_open()) {
        while(getline(actualOutputFile, line)) {
            if(line != testExpected[i]) {
                cout << "Not Expected result at line " << i << endl;
                exit(-1);
            }
            i++;
        }
        cout << "Unit tests successful" << endl;
        actualOutputFile.close();
    } else {
        cerr << "Error: could not open file" << endl;
        exit(0);
    }
}