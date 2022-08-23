#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


const int GENE = 6 ;
const int POP_SIZE = 80;


double chromosome[POP_SIZE][GENE] = { 0 };
double fitness[POP_SIZE];
double fitnessTeam[POP_SIZE];

void initializePopulation();
void printChromosome();
void evaluateChromosome();
void parentSelection();


int main() {

    initializePopulation();
    cout << "Print Chromosome" << endl;
    printChromosome();
    cout << endl;
    cout << "Evaluate Chromosome" << endl;
    evaluateChromosome();
   
    return 0;
}

void initializePopulation() {

   
    ifstream inFile;

    inFile.open("player_criteria1.csv");
    string line = "";
    string temp = "";

    if (inFile.is_open()) {
        cout << "File has been opened" << endl;

        int k = 0;
        int j = 0;
        while (getline(inFile, line))
        {
            if (line != "")
            {
                j = 0;
                line = line + ',';
                for (int i = 0; i <line.length(); i++)
                {
                    if (line[i] != ',')
                    {
                        temp += line[i];
                    }
                    else
                    {
                        chromosome[k][j] = stod(temp);
                        temp = "";
                        j++;
                    }
                }
            }
            k++;
        }


    }
    else {
        cout << "NO FILE HAS BEEN OPENED" << endl;
    }


    inFile.close();
    system("pause");
}

void printChromosome() {

    for (int c = 0; c < POP_SIZE; c++) {
        cout << endl;
        for (int g = 0; g < GENE; g++) {
            cout << chromosome[c][g] << " ";
        }
    }
}

void evaluateChromosome() {
    double attribute, totalAttribute, cost;

    int player1, player2, player3, player4, player5, player6, player7;

    for (int c = 0; c < POP_SIZE; c++) {
        double cost = 0.00, totalAttribute = 0, attribute = 0;
        for (int g = 0; g < GENE; g++) {
            if (g == 1 || g == 2 || g == 3 || g == 4) {

                attribute = chromosome[c][g];
                totalAttribute = totalAttribute + attribute;
               /* cout << totalAttribute;*/
            }
            if (g == 5); {
                cost = chromosome[c][g];
                /*cout << cost;*/
            }
            if (cost < 5500) {
                fitness[c] = fabs(totalAttribute / 8) + (0.5 - ((cost - 1000) / 9000));
            }
            else {
                fitness[c] = fabs(totalAttribute / 8) + (1 - ((cost - 1000) / 9000));
            }
        }
       
    }

    //do {
    //    player1 = rand() % POP_SIZE;
    //    player2 = rand() % POP_SIZE;
    //    player3 = rand() % POP_SIZE;
    //    player4 = rand() % POP_SIZE;
    //    player5 = rand() % POP_SIZE;
    //    player6 = rand() % POP_SIZE;
    //    player7 = rand() % POP_SIZE;

    //    fitnessTeam[0] = fitness[player1] + fitness[player2] + fitness[player3] + fitness[player4] + fitness[player5] + fitness[player6] + fitness[player7];

    //} 
    //while (player1 == player2 || player1 == player3 || player1 == player4 || player1 == player5 || player1 == player6 || player1 == player7 || player2 == player3 || player2 == player4 || player2 == player5 || player2 == player6 || player2 == player7 || player3 == player4 || player3 == player5 || player3 == player6 || player3 == player7 || player4 == player5 || player4 == player6 || player4 == player7 || player5 == player6 || player5 == player7 || player6 == player7);

    //    do {
    //        player1 = rand() % POP_SIZE;
    //        player2 = rand() % POP_SIZE;
    //        player3 = rand() % POP_SIZE;
    //        player4 = rand() % POP_SIZE;
    //        player5 = rand() % POP_SIZE;
    //        player6 = rand() % POP_SIZE;
    //        player7 = rand() % POP_SIZE;

    //        fitnessTeam[1] = fitness[player1] + fitness[player2] + fitness[player3] + fitness[player4] + fitness[player5] + fitness[player6] + fitness[player7];
    //    }      
    //    while (player1 == player2 || player1 == player3 || player1 == player4 || player1 == player5 || player1 == player6 || player1 == player7 || player2 == player3 || player2 == player4 || player2 == player5 || player2 == player6 || player2 == player7 || player3 == player4 || player3 == player5 || player3 == player6 || player3 == player7 || player4 == player5 || player4 == player6 || player4 == player7 || player5 == player6 || player5 == player7 || player6 == player7);

    
    for (int c = 0; c < POP_SIZE; c++) 
    {
        cout << fitness[c];
    }
}


void parentSelection() {

    int team1, team2;
    int indexParents[2];




}

    



