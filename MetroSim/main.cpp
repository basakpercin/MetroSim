/*
 * main.cpp
 * CS15 Project 1
 * 
 * by Basak Percin, June 2022
 *
 * An implementation of the Metro Simulator.
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include "MetroSim.h"
#include "PassengerQueue.h"
#include "Passenger.h"
#include "Train.h"

using namespace std;

int passengerId = 1;

void executeCommand(string command, MetroSim &simulator) 
{
    vector<string> commands;

    if(command.compare("m f") == 0) {
        cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
        exit(0);
    } else if (command.compare("m m") == 0) {
        simulator.moveTrain();
    } else if (command.front() == 'p') {
        string space_delimiter = " ";
        vector<string> words{};

        size_t pos = 0;

        while ((pos = command.find(space_delimiter)) != string::npos) {
            words.push_back(command.substr(0, pos));
            command.erase(0, pos + space_delimiter.length());
        }
        words.push_back(command);

        // words -> words[0] - p words[1] - arr, words[2] - departure

        int arriv = stoi(words[1]);
        int depart = stoi(words[2]);

        Passenger p = Passenger(passengerId, arriv, depart);
        ++passengerId;
        simulator.addPassenger(p);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3 or argc > 4) {
        cerr << "Usage: ./MetroSim stationsFile outputFile [commandsFile]"
        << endl;
        exit(0);
    }

    //Create and open a text file for outputs from command line input
    ofstream outputFile(argv[2]);

    string line;
    int numStations;
    vector<string> stationNames;
    ifstream stationsFile(argv[1]);

    if(stationsFile.is_open()) {
        while(getline(stationsFile, line)) {
            stationNames.push_back(line);
        }
        numStations = stationNames.size();

        stationsFile.close();
    } else {
        cerr << "Error: could not open file " << argv[1] << endl;
        exit(0);
    }

    // initialize sim
    // use stationFile - create train and call the constructor of metrosim
    Train *greenMetro = new Train(numStations, stationNames, &outputFile);
    vector<PassengerQueue> stations(numStations);

    MetroSim greenLine = MetroSim(greenMetro, stations, 0, stationNames);

    if(argc == 4) {
        ifstream commandFile(argv[3]);
        if(commandFile.is_open()) {
            while(getline(commandFile, line)) {
                greenLine.print(cout);
                cout << "Command? ";
                executeCommand(line, greenLine);
            }
            greenLine.print(cout);
            cout << "Command? ";
            cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
            commandFile.close();
            exit(0);
        }
    } else {
        string inputCommand;

        while(true) {
            greenLine.print(cout);
            cout << "Command? ";
            getline(cin, inputCommand);
            executeCommand(inputCommand, greenLine);
        }
    }
}