#ifndef DATABASEH
#define DATABASEH

#include "node.h"
#include <vector>

using namespace std;

class database
{
    public:
            database();

            database(int r, int c);
            
            /*
             * changes the values of a given array to the length and width of the region
             * index 0 is the number of rows, index 1 is the number of columns
             */
            void size(int a[]);
            
            /*
             * Copies the data of region to a vector matrix
             */
            vector<vector<node>> getRegion();

            /*
             * Initializes the region by populating the vector matrix with given values
             */
            void setRegion(vector<vector<char>> r, int m, int n);

            /*
             * Compares two database objets for equality
             */
            bool isEqual(database a, database b);
            
            /*
             *set and get for zone type. E.X. 'R' 'I' 'C' 'T' '#'
             */
            char getZone_Type(int r, int c);
            void setZone_Type(int r, int c, char s);
            
            /*
             *set and get for population
             */
            int getPopulation(int r, int c);
            void setPopulation(int r, int c, int i);

            /*
             *set and get for polution
             */
            int getPollution(int r, int c);
            void setPollution(int r, int c, int i);

            /*
             *set and get for workers
             */
            int getWorkers();
            void setWorkers(int i);

            /*
             *set and get for used_workers
             */
            int getUsed_Workers();
            void setUsed_Workers(int i);

            /*
             *set and get for goods
             */
            int getGoods();
            void setGoods(int i);

    private:
            vector<vector<node>> region;

            int workers;

            int used_workers;

            int goods;
};

#endif