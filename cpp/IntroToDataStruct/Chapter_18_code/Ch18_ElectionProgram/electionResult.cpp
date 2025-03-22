 
//*************************************************************
// Author: D.S. Malik  
//
// This program processes voting data for student council
// president's post. It outputs each candidate's name and the 
// votes they received. The name of the winner is also printed.
//*************************************************************

#include <iostream>  
#include <string>
#include <fstream>
#include "candidateType.h"
#include "unorderedArrayListType.h"
 
using namespace std;

const int NO_OF_CANDIDATES = 6;

void fillNames(ifstream& inFile, 
             unorderedArrayListType<candidateType>& cList);
void processVotes(ifstream& inFile, 
             unorderedArrayListType<candidateType>& cList);
void addVotes(unorderedArrayListType<candidateType>& cList);

void printHeading();
void printResults
       (const unorderedArrayListType<candidateType>& cList);

int main()
{
    unorderedArrayListType<candidateType> 
                        candidateList(NO_OF_CANDIDATES);
	
    candidateType temp;
	
    ifstream inFile;
	
    inFile.open("candData.txt");
    if (!inFile)											
    {
        cout << "Input file (candData.txt) does not exist. " 
             << "Program terminates!!" << endl;
        return 1;
    }
	
    fillNames(inFile, candidateList);
	
    candidateList.sort();
	
    inFile.close();
    inFile.clear();
	
    inFile.open("voteData.txt");  
    if (!inFile)												
    {
        cout << "Input file (voteData.txt) does not exist. "
             << "Program terminates!!" << endl;
        return 1;
    }
	
    processVotes(inFile, candidateList);
	
    addVotes(candidateList);
	
    printHeading();
    printResults(candidateList);

    return 0;
}

void fillNames(ifstream& inFile, 
               unorderedArrayListType<candidateType>& cList)
{
    string firstN;
    string lastN;
    candidateType temp;

    for (int i = 0; i < NO_OF_CANDIDATES; i++)
    {
        inFile >> firstN >> lastN;
        temp.setName(firstN, lastN);
        cList.insertEnd(temp);
    }
}

void processVotes(ifstream& inFile, 
                unorderedArrayListType<candidateType>& cList)
{
    string firstN;
    string lastN;
    int region;
    int votes;
    int candLocation;
	
    candidateType temp;

    inFile >> firstN >> lastN >> region >> votes;

    temp.setName(firstN, lastN);
    temp.setVotes(region, votes);

    while (inFile)
    {
        candLocation = cList.binSearch(temp);

        if (candLocation != -1)
        {
            cList.retrieveAt(candLocation, temp);
            temp.updateVotesByRegion(region, votes);
            cList.replaceAt(candLocation, temp);
        }

        inFile >> firstN >> lastN >> region >> votes;

        temp.setName(firstN, lastN);
        temp.setVotes(region, votes);
    }
}
	
void addVotes(unorderedArrayListType<candidateType>& cList)
{
    candidateType temp;

    for (int i = 0; i < NO_OF_CANDIDATES; i++)
    {
        cList.retrieveAt(i, temp);
        temp.calculateTotalVotes();
        cList.replaceAt(i, temp);
    }
}

void printHeading()
{
    cout << "   --------------------Election Results-----"
         << "---------------" << endl << endl;
    cout << "                  		      Votes" << endl;
    cout << "  Candidate Name    Region1  Region2  Region3  "
         << "Region4   Total"<<endl;
    cout << "------------------  -------  -------  "
         << "-------  -------  ------" << endl;
}

void printResults(const 
               unorderedArrayListType<candidateType>& cList)
{
    cout << "See Programming Exercise 18." << endl;
}
	
