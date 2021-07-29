#include <iostream>
#include <string>
#include <vector>
#include "output.h"
#include "database.h"
#include "node.h"

using namespace std;

output::output()
{

}

/*
 *  Prints map of the Region
 */
void output::printRegion(database d)
{
    int size[2];

    d.size(size);

    for(int r = 0; r < size[0]; r++)
    {
        for(int c = 0; c < size[1]; c++)
        {
            if(d.getPopulation(r,c) == 0)
            {
                cout << d.getZone_Type(r,c) << " ";
            }
            
            else
            {
                cout << d.getPopulation(r,c) << " ";
            }
        }

        cout << endl;
    }
}

/*
 *  Counts and displays population of all zones in Region
 */
void output::printPopulations(database d)
{
    int populations[3] = {0, 0, 0}; //index 0 is residence, index 1 is industrial, index 2 is commercial
    
    int size[2]; //size of region

    d.size(size);

    /*
     *the origion of the region in this loop is the top left
     */
    for(int r = 0; r < size[0]; r++)
    {
        for(int c = 0; c < size[1]; c++)
        {
            /*
             * counts all zone populations
             */
            switch(d.getZone_Type(r,c))
            {
                case 'R':   //residential
                            populations[0] += d.getPopulation(r,c);
                            break;

                case 'I':   //industrial
                            populations[1] += d.getPopulation(r,c);
                            break;

                case 'C':   //commercial
                            populations[2] += d.getPopulation(r,c);
                            break;

                default: 
                            break;
            }
        }
    }

    /*
     *prints population totals for residential, industrial, and commercial
     */
    cout << "The total populations for the region are:" << endl;
    cout << "Residential: " << populations[0] << endl;
    cout << "Industrial: " << populations[1] << endl;
    cout << "Commercial: " << populations[2] << endl;
}

/*
 *  Counts and displays population of all zones in a section of the Region
 */
void output::printPopulations(database d,int minX, int minY, int maxX, int maxY)
{
    int populations[3] = {0,0,0}; //index 0 is residence, index 1 is industrial, index 2 is commercial
    int pollution = 0; //pollution counter
    
    /*
     *the origion of the region in this loop is the top left
     */
    for(int r = minY; r < maxY; r++)
    {
        for(int c = minX; c < maxX; c++)
        {
            /*
             * counts all zone populations
             */
            switch(d.getZone_Type(r,c))
            {
                case 'R':   //residential
                            populations[0] += 1;
                            pollution += d.getPollution(r,c);
                            break;

                case 'I':   //industrial
                            populations[1] += 1;
                            pollution += d.getPollution(r,c);
                            break;

                case 'C':   //commercial
                            populations[2] += 1;
                            pollution += d.getPollution(r,c);
                            break;

                default: 
                            pollution += d.getPollution(r,c);
                            break;
            }
        }
    }

    /*
     *prints population totals for residential, industrial, and commercial
     */
    cout << "The total populations for the region are:" << endl;
    cout << "Residential: " << populations[0] << endl;
    cout << "Industrial: " << populations[1] << endl;
    cout << "Commercial: " << populations[2] << endl;
    cout << "The total amount of pollution in the requested area is " << pollution << " units" << endl;
}

/*
 *  Prints map of pollution in the Region
 */
void output::printPollutionMap(database d)
{
    int size[2];

    d.size(size);

    for(int r = 0; r < size[0]; r++)
    {
        for(int c = 0; c < size[1]; c++)
        {
            cout << d.getPollution(r,c) << " ";
        }

        cout << endl;
    }
}

/*
 *  Counts and displays total pollution of the Region
 */
void output::printPollutionTotal(database d)
{
    int pollution = 0; //total pollution in the Region
    int size[2]; //size of region

    d.size(size);

    /*
     *  Counts pollution units
     */
    for(int r = 0; r < size[0]; r++)
    {
        for(int c = 0; c < size[1]; c++)
        {
           pollution += d.getPollution(r,c);
        }
    }

    /*
     *  Prints pollution count
     */
    cout << "The total amount of pollution in the region is " << pollution << "units." << endl;
}

/*
 *  Changes the values of a given array to bounds of a subregion
 *  The indexes represent, in order: X1, Y1, X2, Y2
 */
void output::getCoordinates(database d, int coordinance[])
{
    int size[2];

    d.size(size);

    bool valid = false;

    /*
     * Will loop until coordinance are valid
     */
    while(!valid)
    {
        /*
         *  Prompts user for coordinace
         */
        cout << "Please enter the diagonal corners of the area you wish to have more information about." << endl;
        cout << "MinX = 0, MinY = 0, MaxX = " << size[1] - 1 << ", MaxY = " << size[0] - 1 << endl;

        /*
         *  Gets coordinance from user
         */
        cout << "X1: ";
        cin >> coordinance[0];

        cout << "Y1: ";
        cin >> coordinance[1];

        cout << "X2: ";
        cin >> coordinance[2];

        cout << "Y2: ";
        cin >> coordinance[3];

        valid = true;

        /*
         *  Tests for minimum bounds
         */
        if(coordinance[0] < 0 || coordinance[1] < 0)
        {
            valid = false;
        }

        /*
         *  Tests for maximum bounds
         */
        if(coordinance[2] > size[1] || coordinance[3] > size[0])
        {
            valid = false;
        }

        /*
         *  Tests for minimum coordinates being less than maximum coordinates
         */
        if(coordinance[0] > coordinance[2] || coordinance[1] > coordinance[3])
        {
            valid = false;
        }

        /*
         *  Error message
         */
        if(!valid)
        {
            cout << "Invalid coordinance" << endl;
        }
    }

    /*
     *  Corrects coordinaces to use top left as the origon of the Region
     */
    int temp = coordinance[1];
    coordinance[1] = coordinance[3];
    coordinance[3] = temp;
}