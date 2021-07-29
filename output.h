#ifndef OUTPUTH
#define OUTPUTH

#include "node.h"
#include "database.h"
#include <iostream>
#include <vector>

using namespace std;

class output
{
    public:
            output();

            /*
             *  Prints map of the Region
             */
            void printRegion(database d);

            /*
             *  Counts and displays population of all zones in Region
             */
            void printPopulations(database d);

            /*
             *  Counts and displays population of all zones a section of the Region
             */
            void printPopulations(database d, int minX, int minY, int maxX, int maxY);

            /*
             *  Prints map of pollution in the Region
             */
            void printPollutionMap(database d);

            /*
             *  Counts and displays total pollution of the Region
             */
            void printPollutionTotal(database d);

            /*
             *  Changes the values of a given array to bounds of a subregion
             *  The indexes represent, in order: X1, Y1, X2, Y2
             */
            void getCoordinates(database d, int coordinance[]);

    private:
};

#endif