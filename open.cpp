#include <iostream> //for basic input and out
#include <string> //for use of strings
#include <fstream>   // to read CVS file
#include <stdlib.h>  //exit failure
#include <vector> //for use of vectors
#include <algorithm> //for use "remove" function
#include "open.h"
#include "database.h"
using namespace std;

void open(database &database1) {

  //Variables
  string filename;     //config.txt
  string regionLayout; //Config.txt first line
  int  maxSteps;       //Config.txt second line
  int refreshRate;     //Config.txt third line
  ifstream configFile;
  ifstream regionFile;
  ifstream regionFile2; //Vector file
  string line;

  //Region (vector) size
  int y = -1; //row
  int x = -1; 
  int maxX = 0; //column



/*******************obtaining config.txt************************/
  
  //User input
  cout << "Beginning simulation"<<endl;
  cout << "Please enter the name of the configuration file: ";
  cin  >> filename; //obtaining config.txt

  //Opening filename to obtain .CSV file
  configFile.open(filename); 
    
  //Checking if file opened properly
  if(!configFile.is_open())  
  {cout << "ERROR: ConfigFile Open" <<endl;
   exit (EXIT_FAILURE);}



//Updated code
for (int i=0; i<3;i++)
{
 if (i==0){
    getline(configFile, line);
      regionLayout = line.substr(line.find(":") + 1);
      cout <<endl<<"Region Layout: "<<regionLayout<<endl;
  }
  if (i==1){
    getline(configFile, line);
      maxSteps = stoi(line.substr(line.find(":") + 1));
      cout <<"Time Limit: "<<maxSteps<<endl;
  }
  if (i==2){
    getline(configFile, line);
      refreshRate = stoi(line.substr(line.find(":") + 1));
      cout <<"Refresh Rate: "<<refreshRate<<endl<<endl;
  }
}
configFile.close();


/***********************Vector***********************************/


  //Opening file
  regionFile.open(regionLayout); 
  //Checking if file opened properly
  if(!regionFile.is_open())
  {cout << "ERROR: Region File Open" <<endl;
   exit (EXIT_FAILURE);}
  //initializing vector
  vector<vector<char>> vec; //(y , vector<char> (maxX));// (if needed)


  while(regionFile.good())  {  
    vector<char> vecRow;
    getline(regionFile, line);
      line.erase(remove(line.begin(), line.end(), ','), line.end());

    if(line.length() != 0)
    {
      //populating row vector
      for (int i = 0; i < line.size(); ++i) { 

      vecRow.push_back(line[i]);
     
      }
      vec.push_back(vecRow);
      y++;
    }
    //finding maxX
     x = line.length();
    if (x>maxX) {maxX=x;} 

  }

  cout <<"Initial Region State"<<endl<<endl;

  //upper border
  for(int i=0;i<(maxX+1);i++) {cout<<"--";}
  cout<<endl;

  //Display vector
  for (vector<char> &vec_row : vec) {
    cout << "|"; //left border
    //
        for (char &x : vec_row) {
            cout << x <<" ";
        }
      cout << "|"; //right border
      cout << endl;
  }

  //lower border
  for(int i=0;i<(maxX+1);i++) {cout<<"--";}
  cout <<endl;

  database1.setRegion(vec, y, maxX - 1); //fill database with 2d vector

  //Closing file
  regionFile.close();


}
