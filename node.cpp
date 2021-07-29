#include "node.h"

using namespace std;

node::node()
{
    zone_type = '.';
    population = 0;
    pollution = 0;
}

char node::getZone_Type()
{
    return zone_type;
}

void node::setZone_Type(char s)
{
    zone_type = s;
}

int node::getPopulation()
{
    return population;
}

void node::setPopulation(int i)
{
    population = i;
}

int node::getPollution()
{
    return pollution;
}

void node::setPollution(int i)
{
    pollution = i;
}