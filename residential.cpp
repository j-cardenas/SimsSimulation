/*
*The residential function takes in the database and runs through the simulation
*checking to see if all criteria are met before increasing the population of the
*residential zones.
*
*Rule 1: 		If the current cell's population is 0 (denoted by char 'R') and is adjacent 
*				to at least 1 powerline (denoted by char 'T'), then increase the current cell's population by 1.
*Rule 2:		If the current cell's population is 0 and is adjacent to at least 1 cell
*				with population of at least 1, then increase the current cell's 
*				population by 1.
*Rule 3:		If the current cell's population is 1 and is adjacent to at least 2
*				cells with populations of at least 1, then increase the current cell's 
*				population by 1.
*Rule 4:		If the current cell's population is 2 and is adjacent to at least 4
*				cells with populations of at least 2, then increase the current cell's
*				population by 1.
*Rule 5:		If the current cell's population is 3 and is adjacent to at least 6
*				cells with populations of at least 3, then increase the current cell's
*				population by 1.
*Rule 6:		If the current cell's population is 4 and is adjacent to at least 8
*				cells with the populations of at least 4, then increase the current
*				cells' population by 1.
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
using namespace std; 

void residential(database &database1) {

	int size[2];			//creating array for row and column size
	int rule1 = 0;			//counters for each of the rules
	int rule2 = 0;
	int rule3 = 0;
	int rule4 = 0;
	int rule5 = 0;
	int rule6 = 0;
	database1.size(size);	//initializing size array with database sizes

	//dummy vector
	vector<vector<int>> vec(size[0], vector<int> (size[1], 0));
	for(int a = 0; a < size[0]; a++) {
		for(int b = 0; b < size[1]; b++) {
		}
	}

	for(int j = 0; j < size[0]; j++){ 
		for(int k = 0; k < size[1]; k++){

			//rule 1
			if((database1.getZone_Type(j, k) == 'R') && (database1.getPopulation(j, k) == 0)){		
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
					if(database1.getZone_Type(j-1, k+1) == 'T') {	//checks if there is a 'T' NE
						rule1++;}
					if(database1.getZone_Type(j-1, k-1) == 'T') {	//checks if there is a 'T' NW
						rule1++;}
					if(database1.getZone_Type(j-1, k) == 'T') { 	//checks ifther is a 'T' N
						rule1++;}
					if(database1.getZone_Type(j, k-1) == 'T') { 	//checks if there is a 'T' W
						rule1++;}	
					if(rule1 >= 1 && database1.getPopulation(j, k) == 0) {
						vec[j][k] = 1;
						rule1 = 0;
					}
				}
				rule1 = 0;
			}
			
			//rule 2
			if((database1.getZone_Type(j ,k) == 'R') && (database1.getPopulation(j, k) == 0)) {
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
					if(rule2 >= 1 && database1.getPopulation(j, k) >= 0) {
						rule2 = 0;
						vec[j][k] = 1;
					}
				}
				rule2 = 0;
			}
			
			//rule 3
			if(database1.getPopulation(j, k) == 1) {
				if(!(j+1 > size[0]-1)){
					if(database1.getPopulation(j+1, k+1) >= 1) { 	//checks if there is a 1 SE
						rule3++;}
					if(database1.getPopulation(j+1, k-1) >= 1) { 	//checks if there is a 1 SW
						rule3++;}
					if(database1.getPopulation(j+1, k) >= 1) {	 	//checks if there is a 1 S
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
					if(rule3 >= 2 && database1.getPopulation(j, k) >= 1) {
						vec[j][k] = 1;
						rule3 = 0;
					}
				}
				rule3 = 0;
			}
			
			//rule 4
			if(database1.getPopulation(j, k) == 2) {
				if(!(j+1 > size[0]-1)){
					if(database1.getPopulation(j+1, k+1) >= 2) { 	//checks if there is a 2 SE
						rule4++;}
					if(database1.getPopulation(j+1, k-1) >= 2) { 	//checks if there is a 2 SW
						rule4++;}
					if(database1.getPopulation(j+1, k) >= 2) { 		//checks if there is a 2 S
						rule4++;}
				}
				if(j < size[0]){
					if(database1.getPopulation(j, k+1) >= 2) { 		//checks if there is 2 E
							rule4++;}
					if(database1.getPopulation(j-1, k+1) >= 2) { 	//checks if there is a 2 NE
						rule4++;}
					if(database1.getPopulation(j-1, k-1) >= 2) { 	//checks if there is a 2 NW
						rule4++;}
					if(database1.getPopulation(j-1, k) >= 2) { 		//checks ifther is a 2 N
						rule4++;}
					if(database1.getPopulation(j, k-1) >= 2) { 		//checks if there is a 2 W
						rule4++;}
					if(rule4 >= 4 && database1.getPopulation(j, k) >= 2) {
						vec[j][k] = 1;
						rule4 = 0;
					}
				}
				rule4 = 0;
			}
			
			//rule 5 
			if(database1.getPopulation(j, k) == 3) {
				if(!(j+1 > size[0]-1)){
					if(database1.getPopulation(j+1, k+1) >= 3) { 	//checks if there is a 3 SE
						rule5++;}
					if(database1.getPopulation(j+1, k-1) >= 3) { 	//checks if there is a 3 SW
						rule5++;}
					if(database1.getPopulation(j+1, k) >= 3) { 		//checks if there is a 3 S
						rule5++;}
				}
				if(j < size[0]){
					if(database1.getPopulation(j, k+1) >= 3) { 		//checks if there is 3 E
							rule5++;}
					if(database1.getPopulation(j-1, k+1) >= 3) { 	//checks if there is a 3 NE
						rule5++;}
					if(database1.getPopulation(j-1, k-1) >= 3) { 	//checks if there is a 3 NW
						rule5++;}
					if(database1.getPopulation(j-1, k) >= 3) { 		//checks ifther is a 3 N
						rule5++;}
					if(database1.getPopulation(j, k-1) >= 3) { 		//checks if there is a 3 W
						rule5++;}
					if(rule5 >= 6 && database1.getPopulation(j, k) >= 3) {
						vec[j][k];
						rule5 = 0;
					}
				}
			rule5 = 0;
			}
			
			//rule 6 
			if(database1.getPopulation(j, k) == 4) {
				if(!(j+1 > size[0]-1)){
					if(database1.getPopulation(j+1, k+1) >= 4) { 	//checks if there is a 4 SE
						rule6++;}
					if(database1.getPopulation(j+1, k-1) >= 4) { 	//checks if there is a 4 SW
						rule6++;}
					if(database1.getPopulation(j+1, k) >= 4) { 		//checks if there is a 4 S
						rule6++;}
				}
				if(j < size[0]){
					if(database1.getPopulation(j, k+1) >= 4) { 		//checks if there is 4 E
							rule6++;}
					if(database1.getPopulation(j-1, k+1) >= 4) { 	//checks if there is a 4 NE
						rule6++;}
					if(database1.getPopulation(j-1, k-1) >= 4) { 	//checks if there is a 4 NW
						rule6++;}
					if(database1.getPopulation(j-1, k) >= 4) { 		//checks ifther is a 4 N
						rule6++;}
					if(database1.getPopulation(j, k-1) >= 4) { 		//checks if there is a 4 W
						rule6++;}
					if(rule6 >= 8 && database1.getPopulation(j, k) >= 4) {
						vec[j][k] = 1;
						rule6 = 0;
					}
				}
				rule6 = 0;
			}		
			
		}
	}

	//dummy loop increases database cells by 1 if dummy vector has 1
	//increases number of workers every time a population is increased	
	for(int a = 0; a < size[0]; a++) {
		for(int b = 0; b < size[1]; b++) {
			if(vec[a][b] == 1){
				database1.setPopulation(a, b, database1.getPopulation(a, b) + 1);
				database1.setWorkers(database1.getWorkers() + 1);
			}
		}
	}
		
}