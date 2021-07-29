#include <iostream> //for basic input and out
#include <string> //for use of strings
#include <fstream>   // to read CVS file
#include <stdlib.h>  //exit failure
#include <vector> //for use of vectors
#include <algorithm> //for use "remove" function
#include "open.h"
#include "database.h"
#include "output.h"
#include "node.h"
#include "residential.h"
#include "commercial.h"
using namespace std;

int main() {

	output outPut;
	database database1; //create 
	int size[2];
	int timeStep = 7;
	int refreshRate = 1;
	int coordinates[4];

	open(database1); 	//initialization
	database1.size(size);
	database database2(size[0], size[1]); 	//clone database
	
	for(int i = 1; i < timeStep; i++) {
		database2 = database1;
		residential(database1);
		commercial(database1);
		//industrial(database1);
		//pollution(database1);
		if(i % refreshRate == 0) {
			cout << "Time Step: " << i << endl;
			cout << "Available Workers " << database1.getWorkers();
			cout << " Available Goods " << database1.getGoods() << endl;
			outPut.printRegion(database1);
			}
		if(database1.isEqual(database1, database2)) {
			cout << endl << "Database no longer updating. " << endl;
			cout << "Time step: " << i << endl;
			outPut.printRegion(database1); cout << endl;
			break;
		}
		cout << endl;
	}
	cout << endl;

	cout << "Pollution" << endl;
	outPut.printPollutionMap(database1);
	outPut.printPopulations(database1);
	outPut.printPollutionTotal(database1);

	outPut.getCoordinates(database1, coordinates);

	outPut.printPopulations(database1, coordinates[0], coordinates[1], coordinates[2], coordinates[3]);
	cout << "Simulation complete" << endl;
	return 0;
}
