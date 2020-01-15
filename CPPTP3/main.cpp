/******************************************************************************
                           main  -  description
                             -------------------
    début                : $15/01/2020$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, Mohamed EDDAHABI 
    e-mail               : $sophie.crowley@insa-lyon.fr$
                           $zakaria.nassreddine@insa-lyon.fr$
                           $mohamed.eddhabi@insa-lyon.fr$
*******************************************************************************/

#include <iostream> 
#include <string> 
#include <cstdlib>
#include <map> 
#include <fstream>

using namespace std; 
  
int main(int argc, char** argv) 
{ 
    string fileName = argv[(argc-1)];
    if(argc==1) {
        printf("\nNo log file name was passed");
        return 0; 
    }
    string graphFileName = "";
    bool includeImages = true;
    int startTime = 0;
    int endTime = 24;
    for (int i = 0; i < argc-1; ++i) {
        if (string(argv[i]) == "-g") { 
            if((i+1)< argc-1 && string(argv[i+1]).at(0)!='-') {
                graphFileName =  string(argv[++i]);
            }
            else {
                printf("No graph file name was passed, graph will not be made");
            }  
        }
        else if (string(argv[i]) == "-e") { 
            includeImages = false;     
        }        
        else if (string(argv[i]) == "-t") {
            if((i+1)< argc-1 && atoi(argv[i+1])>=0 && atoi(argv[i+1])<24 
            && string(argv[i+1]).at(0)!='-') {
                startTime = atoi(argv[++i]);
                endTime = startTime+1;
            }
            else {
                printf("No hour was given, time will not be accounted for");
            }    
        }
    } 
    map<string, int> stats;
    typedef map<string, int> innerMap;
    if(graphFileName != "") {
        map<string, innerMap> graph;
    }
    ifstream logFile(fileName);
    if(logFile.good()) {
        string input;
        while(getline(logFile,input))
        {
            string time = input.substr(input.find(':')+1, 2);
            int hour=stoi(time);
            // get time
            // if : time is between (or equal to) start and end time then do loop stuff
            // get file type
            // if includeImages = true || its not an image file  then do loop stuff
            // get referrer and hit url strings
            // add 'hit' url to map or increment it if its already there
            // if doing graph, then add get and referrer to map
            // or increment w referrer if already there
        }
        // call stats afficher method etc.
    }
    return 0;
} 
                        