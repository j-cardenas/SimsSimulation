#ifndef NODEH
#define NODEH

#include <string>

using namespace std;

class node
{
    public:
            node();

            char getZone_Type();
            void setZone_Type(char s);

            int getPopulation();
            void setPopulation(int i);

            int getPollution();
            void setPollution(int i);

    private:
            char zone_type;
            int population;
            int pollution;
};

#endif