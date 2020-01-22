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
#include <unordered_map> 
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
    unordered_map<string, int> stats;
    typedef unordered_map<string, int> innerMap;
    if(graphFileName != "") {
        unordered_map<string, innerMap> graph;
    }
    ifstream logFile(fileName);
    if(logFile.good()) {
        string input;
        while(getline(logFile,input))
        {
            string time = input.substr(input.find(':')+1, 2);
            int hour=stoi(time);
            if(hour<= endTime && hour >=startTime) {
                if(includeImages || !(input.find("jpg") || input.find("png") || 
                input.find("gif") || input.find("ico") || input.find("css") || 
                input.find("js"))) {
                // get referrer and hit url strings
                // add 'hit' url to map or increment it if its already there
                // if doing graph, then add get and referrer to map
                // or increment w referrer if already there
                }
            }
        }
        // call stats afficher method etc.
    }
    return 0;
} 
                        