     The purpose of this project is to design, code and test a metro simulator. 
The simulator uses the greenline metro. The simulator takes in 3 commands, move
train, add passenger and finish. Each passenger ([ID, Arrival -> Destination])
will be created and queued(FIFO) according to their arrival stations. Moving
train will remove passengers whose destination station is the current station 
and add every passenger at current station to the train according to their 
destination stations. Removed passenger info will be logged into the output file
provided at the beginning of the program by the user. Passengers on the train
and passengers waiting at stations will be printed to the console. 

Did this project as a part of Tufts Data Structures class
