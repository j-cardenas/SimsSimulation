#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "open.h"
#include "database.h"
#include "output.h"
#include "node.h"
#include "industrial.h"
using namespace std;

void industrial(database &database1) {

	output outPut;
	int size[2];
	int time = 7;
	int rule1 = 0;
	int rule2 = 0;
	int rule3 = 0;
	int rule4 = 0;
	database1.size(size);

	int work = database1.getWorkers();
	int good = database1.getGoods();

	//dummy vector as seen within residential and commercial sections
	vector<vector<int>> vec(size[0], vector<int> (size[1], 0));
	for(int a = 0; a < size[0]; a++) {
		for(int b = 0; b < size[1]; b++) {
		}
	}

	cout << endl;

		for(int j = 0; j < size[0]; j++){	//nested for loops iterating through values within the 2D vector
			for(int k = 0; k < size[1]; k++){

				//rule 1
				if(database1.getZone_Type(j, k) == 'I'){	//if statements relating to given paramenters as seen within industrial section
					if(!(j+1 > size[0]-1)){
						if(database1.getZone_Type(j+1, k+1) == 'T') {	//Rule 1
							rule1++;				//If a cell has a population of 0, is adjacent to a powerline in the current time step, and
												//there are at least 2 available workers, that cell’s population will increase by 1 in the next
												//time step and the available workers are assigned to that job
						}
						if(database1.getZone_Type(j+1, k-1) == 'T') {
							rule1++;
						}
						if(database1.getZone_Type(j+1, k) == 'T') {
							rule1++;
						}
					if(j < size[0]){
						if(database1.getZone_Type(j, k+1) == 'T') {
							 rule1++;
						}
						if(database1.getZone_Type(j-1, k+1) == 'T') {
							rule1++;
						}
						if(database1.getZone_Type(j-1, k-1) == 'T') {
							rule1++;
						}
						if(database1.getZone_Type(j-1, k) == 'T') {
							rule1++;
						}
						if(database1.getZone_Type(j, k-1) == 'T') {
							rule1++;
						}
						if(rule1 >= 1 && database1.getPopulation(j, k) == 0 && database1.getWorkers() >= 2) {
							if(work >= 2)	//setting goods and adding to temp workers variable once parameter is met
							{
							work = work - 2;
							database1.setGoods(database1.getGoods() + 1);
							vec[j][k] = 1;
							rule1 = 0;	//setting rule counter back to zero
							}
						}
					}
					rule1 = 0;
					}
				}

				//rule 2
				if(database1.getZone_Type(j, k) == 'I') {

					if(!(j+1 > size[0]-1)){		//if statements again checking whether data values meet given parameters
						if(database1.getPopulation(j+1, k+1) >= 1) {
							rule2++;
						}
						if(database1.getPopulation(j+1, k-1) >= 1) {
							rule2++;
						}
						if(database1.getPopulation(j+1, k) >= 1) {
							rule2++;
						}
					}							//Rule 2
												//If a cell has a population of 0, is adjacent to at least one cell with a population of at least
												//1, and there are at least 2 available workers, that cell’s population will increase by 1 in
												//the next time step and the available workers are assigned to thatjob

					if(j < size[0]){
						if(database1.getPopulation(j, k+1) >= 1) {
							 rule2++;
						}
						if(database1.getPopulation(j-1, k+1) >= 1) {
							rule2++;
						}
						if(database1.getPopulation(j-1, k-1) >= 1) {
							rule2++;
						}
						if(database1.getPopulation(j-1, k) >= 1) {
							rule2++;
						}
						if(database1.getPopulation(j, k-1) >= 1) {
							rule2++;
						}
						if(rule2 >= 1 && database1.getPopulation(j, k) >= 0 && database1.getWorkers() >= 2) {	//checking given parameters, if parameters are met, data held within both temp variable and goods are stored
							//database1.setPopulation(j, k, database1.getPopulation(j, k) + 1);
							if(work >= 2)
							{
							//database1.setWorkers(database1.getWorkers() - 2);
							work = work - 2;
							database1.setGoods(database1.getGoods() + 1);
							vec[j][k] = 1;
							}
						}
					}
					rule2 = 0;
				}

				//rule 3
				if(database1.getPopulation(j, k) == 1) {	//if statements again checking to see whether given parameters are met

					if(!(j+1 > size[0]-1)){
						if(database1.getPopulation(j+1, k+1) >= 1) {
							rule3++;
						}
						if(database1.getPopulation(j+1, k-1) >= 1) {
							rule3++;
						}
						if(database1.getPopulation(j+1, k) >= 1) {
							rule3++;
						}						//Rule 3
												//If a cell has a population of 1, is adjacent to at least two cells with a population of at
												//least 1, and there are at least 2 available workers, that cell’s population will increase by
												//1 in the next time step and the available workers are assigned to thatjob
					}
					if(j < size[0]){
						if(database1.getPopulation(j, k+1) >= 1) {
							 rule3++;
						}
						if(database1.getPopulation(j-1, k+1) >= 1) {
							rule3++;
						}
						if(database1.getPopulation(j-1, k-1) >= 1) {
							rule3++;
						}
						if(database1.getPopulation(j-1, k) >= 1) {
							rule3++;
						}
						if(database1.getPopulation(j, k-1) >= 1) {
							rule3++;
						}
						if(rule3 >= 2 && database1.getPopulation(j, k) >= 1 && database1.getWorkers() >= 2) {
							if(work >= 2)		//if given parameters are met, temp work variable is and setGoods function is called
							{
							//database1.setPopulation(j, k, database1.getPopulation(j, k) + 1);
							rule3 = 0;
							work = work - 2;
							//database1.setWorkers(database1.getWorkers() - 2);
							database1.setGoods(database1.getGoods() + 1);
							vec[j][k] = 1;
							}
						}
					}
					rule3 = 0;
				}

				//rule 4
				if(database1.getPopulation(j, k) == 2) {	//if statements again called in order to see whether given parameters are met

					if(!(j+1 > size[0]-1)){
						if(database1.getPopulation(j+1, k+1) >= 2) {
							rule4++;
						}
						if(database1.getPopulation(j+1, k-1) >= 2) {
							rule4++;
						}
						if(database1.getPopulation(j+1, k) >= 2) {
							rule4++;
						}
					}						//Rule 4
											// If a cell has a population of 2, is adjacent to at least four cells with a population of at
											//least 2, and there are at least 2 available workers, that cell’s population will increase by
											//1 in the next time step and the available workers are assigned to thatjob
					if(j < size[0]){
						if(database1.getPopulation(j, k+1) >= 2) {
							 rule4++;
						}
						if(database1.getPopulation(j-1, k+1) >= 2) {
							rule4++;
						}
						if(database1.getPopulation(j-1, k-1) >= 2) {
							rule4++;
						}
						if(database1.getPopulation(j-1, k) >= 2) {
							rule4++;
						}
						if(database1.getPopulation(j, k-1) >= 2) {
							rule4++;
						}
						if(rule4 >= 4 && database1.getPopulation(j, k) >= 2 && database1.getWorkers() >= 2) {
							if(work >= 2)		//if given values meet parameters, temp work variable is altered, setGoods function is called
							{
							//database1.setPopulation(j, k, database1.getPopulation(j, k) + 1);
							//database1.setWorkers(database1.getWorkers() - 2);
							work = work - 2;
							database1.setGoods(database1.getGoods() + 1);
							vec[j][k] = 1;
							}
						}
					}
					rule4 = 0;
				}
				}

			}




		//dummy loop increases database cells by 1 if dummy vector has 1
		//increases number of workers every time a population is increased
		for(int a = 0; a < size[0]; a++) {
			for(int b = 0; b < size[1]; b++) {
				if(vec[a][b] == 1) {
					database1.setPopulation(a, b, database1.getPopulation(a, b) + 1);
					database1.setWorkers(database1.getWorkers() - 2);
				}
			}
		}


	}

