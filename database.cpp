#include "database.h"

using namespace std;

database::database()
{
    workers = 0;
    goods = 0;
}

database::database(int r, int c)
{
    workers = 0;
    goods = 0;

    vector<node> column;
    node node;

    /*
     *allocates memory for region
     */
    //creates column space in region
    for(int i = 0; i < r; i++)
    {
        column.push_back(node);
    }

    //creates row space in region
    for(int i = 0; i < c; i++)
    {
        region.push_back(column);
    }
}

/*
 *returns the size of the database
 */
void database::size(int a[])
{
    a[0] = region.size(); //rows
    a[1] = region[0].size(); //columns
}

/*
 *  Copies the data of region to a vector matrix
 */
vector<vector<node>> database::getRegion()
{
    return region;
}

/*
 *  Set Region
 */
void database::setRegion(vector<vector<char>> a, int m, int n)
{
    vector<node> column;
    node node;

    /*
     *allocates memory for region
     */
    //creates column space in region
    for(int i = 0; i < n; i++)
    {
        column.push_back(node);
    }

    //creates row space in region
    for(int i = 0; i < m; i++)
    {
        region.push_back(column);
    }

    /*
     *  populates region
     */
    for(int r = 0; r < a.size(); r++)
    {
        for(int c = 0; c < a[r].size(); c++)
        {
            region[r][c].setZone_Type(a[r][c]);
        }
    }
}

/*
 * Compares two database objets for equality
 */
bool database::isEqual(database a, database b)
{
    int size[2];

    a.size(size);

    for(int r = 0; r < size[0]; r++)
    {
        for(int c = 0; c < size[1]; c++)
        {
            if(!(a.getPopulation(r,c) == b.getPopulation(r,c)))
            {
                return false;
            }
        }
    }

    return true;
}

/*
 *  Get Zone Type
 */
char database::getZone_Type(int r, int c)
{
    return region[r][c].getZone_Type();
}

/*
 *  Set Zone Type
 */
void database::setZone_Type(int r, int c, char s)
{
    region[r][c].setZone_Type(s);
}

/*
 *  Get Population
 */
int database::getPopulation(int r, int c)
{
    return region[r][c].getPopulation();
}

/*
 *  Set Population
 */
void database::setPopulation(int r, int c, int i)
{
    region[r][c].setPopulation(i);
}

/*
 *  Get Pollution
 */
int database::getPollution(int r, int c)
{
    return region[r][c].getPollution();
}

/*
 *  Set Pollution
 */
void database::setPollution(int r, int c, int i)
{
    region[r][c].setPollution(i);
}

/*
 *Get workers
 */
int database::getWorkers()
{
    return workers;
}

/*
 *Set workers
 */
void database::setWorkers(int i)
{
    workers = i;
}

/*
 *Get for used_workers
 */
int database::getUsed_Workers()
{
    return used_workers;
}

/*
 *Set used_workers
 */
void database::setUsed_Workers(int i)
{
    used_workers = i;
}

/*
 *Get goods
 */
int database::getGoods()
{
    return goods;
}

/*
 *Set goods
 */
void database::setGoods(int i)
{
    goods = i;
}