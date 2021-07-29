/*
*The commercial function takes in workers, goods, and database and runs through
*the simulation checking to see if all criteria are met before increasing
*population of the commercial zones. 
*
*Rule 1: 	If the current cell's population is 0 (denoted by char 'C'), there is at least 
*			1 adjacent powerline (denoted by char 'T'), there is at least 1 worker, 
*			and at least 1 good, then increase the current cell's population by 1.
*Rule 2: 	If the current cell's population is 0, there is at least 1 adjacent cell
*			with a population of 1, there is at least 1 worker, and at least 1 goods, 
*			then increase the current cell's population by 1.
*Rule 3: 	If the current cell's population is 1, there are at least 2 adjacent cells with 
*			a population of 1, there is at least 1 worker, and at at least 1 goods,
*			then increase the current cell's population by 1.
*/

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
#include "residential.h"
#include "commercial.h"
using namespace std; 

void commercial(database &database1) {

	int size[2];							//creating an array for row and column size
	int rule1 = 0;							//counters for rules
	int rule2 = 0;
	int rule3 = 0;
	database1.size(size);					//initiallizing size array with database sizes
	int worker = database1.getWorkers();	//temporary counter for worker
	int goods = database1.getGoods();		//temporary counter for goods

	//dummy vector
	vector<vector<int>> vec(size[0], vector<int> (size[1], 0));
	for(int a = 0; a < size[0]; a++) {
		for(int b = 0; b < size[1]; b++) {
		}
	}	
	
	for(int j = 0; j < size[0]; j++){ 
		for(int k = 0; k < size[1]; k++){
			
			//rule 1
			if((database1.getZone_Type(j, k) == 'C') && (database1.getPopulation(j, k) == 0)){		
				if(!(j+1 > size[0]-1)){
					if(database1.getZone_Type(j+1, k+1) == 'T') { 	//checks if there is a 'T' SE
						rule1++;}
					if(database1.getZone_Type(j+1, k-1) == 'T') { 	//checks if there is a 'T' SW
						rule1++;}
					if(database1.getZone_Type(j+1, k) == 'T') { 	//checks if there is a 'T' S
						rule1++;}
				}						
				if(j < size[0]){
					if(database1.getZone_Type(j, k+1) == 'T') { 	//checks if there is 'T' E
							rule1++;}
					if(database1.getZone_Type(j-1, k+1) == 'T') { 	//checks if there is a 'T' NE
						rule1++;}
					if(database1.getZone_Type(j-1, k-1) == 'T') { 	//checks if there is a 'T' NW
						rule1++;}
					if(database1.getZone_Type(j-1, k) == 'T') { 	//checks ifther is a 'T' N
						rule1++;}
					if(database1.getZone_Type(j, k-1) == 'T') { 	//checks if there is a 'T' W
						rule1++;}	
					if(rule1 >= 1 && database1.getPopulation(j, k) == 0 &&
						worker >= 1 && goods >= 1) {
						worker--;
						goods--;
						vec[j][k] = 1;
						rule1 = 0;
					}
				}
				rule1 = 0;
			}
			
			//rule 2 
			if((database1.getZone_Type(j, k) == 'C') && (database1.getPopulation(j, k) == 0)){		
				if(!(j+1 > size[0]-1)){
					if(database1.getPopulation(j+1, k+1) >= 1) { 	//checks if there is a 1 SE
						rule2++;}
					if(database1.getPopulation(j+1, k-1) >= 1) { 	//checks if there is a 1 SW
						rule2++;}
					if(database1.getPopulation(j+1, k) >= 1) { 		//checks if there is a 1 S
						rule2++;}
				}						
				if(j < size[0]){
					if(database1.getPopulation(j, k+1) >= 1) { 		//checks if there is 1 E
							rule2++;}
					if(database1.getPopulation(j-1, k+1) >= 1) { 	//checks if there is a 1 NE
						rule2++;}
					if(database1.getPopulation(j-1, k-1) >= 1) { 	//checks if there is a 1 NW
						rule2++;}
					if(database1.getPopulation(j-1, k) >= 1) { 		//checks ifther is a 1 N
						rule2++;}
					if(database1.getPopulation(j, k-1) >= 1) { 		//checks if there is a 1 W
						rule2++;}	
					if(rule1 >= 1 && database1.getPopulation(j, k) == 0 &&
						worker >= 1 && goods >= 1) {
						worker--;
						goods--;
						vec[j][k] = 0;
						rule2 = 0;
					}
				}
				rule2 = 0;
			}
			
			//rule 3 
			if((database1.getPopulation(j, k) == 1)) {		
				if(!(j+1 > size[0]-1)){
					if(database1.getPopulation(j+1, k+1) >= 1) { 	//checks if there is a 1 SE
						rule3++;}
					if(database1.getPopulation(j+1, k-1) >= 1) { 	//checks if there is a 1 SW
						rule3++;}
					if(database1.getPopulation(j+1, k) >= 1) { 		//checks if there is a 1 S
						rule3++;}
				}						
				if(j < size[0]){
					if(database1.getPopulation(j, k+1) >= 1) { 		//checks if there is 1 E
							rule3++;}
					if(database1.getPopulation(j-1, k+1) >= 1) { 	//checks if there is a 1 NE
						rule3++;}
					if(database1.getPopulation(j-1, k-1) >= 1) { 	//checks if there is a 1 NW
						rule3++;}
					if(database1.getPopulation(j-1, k) >= 1) { 		//checks ifther is a 1 N
						rule3++;}
					if(database1.getPopulation(j, k-1) >= 1) { 		//checks if there is a 1 W
						rule3++;}	
					if(rule3 >= 2 && database1.getPopulation(j, k) == 1 &&
						worker >= 1 && goods >= 1) {
						worker--;
						goods--;
						vec[j][k] = 0;
						rule3 = 0;
					}
				}
				rule3 = 0;
			}
		}
	}

	//dummy loop increases database cells by 1 if dummy vector has 1
	//increases number of workers every time a population is increased
	for(int a = 0; a < size[0]; a++) {
		for(int b = 0; b < size[1]; b++) {
			if(vec[a][b] == 1) {
				database1.setPopulation(a, b, database1.getPopulation(a, b) + 1);
				database1.setWorkers(database1.getWorkers() - 1);
				database1.setGoods(database1.getGoods() - 1);
			}
		}	
	}	
	
}
