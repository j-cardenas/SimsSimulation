#include <iostream>
#include <string>
#include <fstream>   // to read CSV file
#include <stdlib.h>  //exit failure
#include <vector>
#include <algorithm>
#include "open.h"
#include "database.h"
#include "output.h"
#include "node.h"
#include "pollution.h"
using namespace std;

void pollution(database &database1) {

	int size[2];			//creating array for row and column size
	database1.size(size);	//initializing size array with database sizes
	int temppol = 0;

	for(int j = 0; j < size[0]; j++){	//nested for loop initialized in order to loop through values held within 2D vector
		for(int k = 0; k < size[1]; k++){
			if((database1.getZone_Type(j, k) == 'I')){
				temppol = database1.getPopulation(j,k);		//temporary variable utilized in order to store pollution values within the setPollution function
				database1.setPollution(j,k,temppol);		//storing given pollution value
				}
			}
		}

	for(int j = 0; j < size[0]; j++){	//again nested for loop initialized in order to loop through values held within 2D vector
		for(int k = 0; k < size[1]; k++){
			if(database1.getPollution(j,k) > 0 && database1.getZone_Type(j,k) == 'I')
			{
				database1.setPollution(j+1,k,database1.getPollution(j,k) - 1);	//setting new Pollution value to cells below

			}
}
}

/*
	for(int j = 0; j < 2; j++){
		for(int k = -2; k < 0; k++){
			if(database1.getPollution(j,k) == 0 && database1.getZone_Type(j+1,k) == 'I')
			{
			}
		}

	}

*/
}
