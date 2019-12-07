/*************************************************************************
                           main  -  description
                             -------------------
    début                : $20/11/2019$
    copyright            : (C) $2019$ par $Sophie Crowley, Zakaria Nassreddine, Zihao Hua$
    e-mail               : $sophie.crowley@insa-lyon.fr$
*************************************************************************/

#include <iostream>
using namespace std;

#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetComplexe.h"

int main() {
    Catalogue cat;
    bool exit = false;
    int choice;
    while(!exit) {
        printf("Enter 1 to add to Catalogue, 2 to display catalogue, 3 to search in catalogue, or 4 to exit\n");
        if(cin >> choice) {
            switch(choice) {
                case 1: {
                    // ask if simple or complex, then get data and put into trajet
                    // check that complex ones are valid, aka depart/arrive stuff
                    // Ajouter
                    break;
                }
                case 2: {
                    cat.Afficher();
                    break;
                }
                case 3: {
                    char depart[30];
                    char arrive[30];
                    printf("Enter city of departure:\n");
                    cin >> depart;
                    printf("Enter city of arrival\n");
                    cin >> arrive;
                    cat.Rechercher(depart, arrive);
                    break;
                }
                case 4: {
                    exit = true;
                    break;
                }
                default: {
                    printf("Invalid input\n");
                    break;
                }
            }
        }
        else {
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(80,'\n');
        }
    }
    return 0;

}