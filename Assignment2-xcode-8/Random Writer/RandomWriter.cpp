/*
 * File: RandomWriter.cpp
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Random Writer problem.
 */

#include <iostream>
#include "console.h"
#include "random.h"
#include "hashmap.h"
#include "strlib.h"
#include "vector.h"
#include <fstream>
#include "simpio.h"

using namespace std;
const int numStrings = 2000;

void randomWriter(HashMap<string, Vector<string> > hMap) {
    Vector<string> mapKeys = hMap.keys();
    int maxSize = 0;
    string bestKey = "";
    
    for (int i = 0; i < mapKeys.size(); i++) {
        Vector<string> values = hMap.get(mapKeys[i]);
        if (values.size() > maxSize) {
            maxSize = values.size();
            bestKey = mapKeys[i];
        }
    }
    
    Vector<string> bestValue = hMap.get(bestKey);
    int randomI = randomInteger(0, bestValue.size() - 1);
    string nextStr = bestValue[randomI];
    cout << bestKey << nextStr;
    
    for (int i = 0; i < numStrings; i ++) {
        Vector<string> nextValue = hMap.get(nextStr);
        int randomNextInt = randomInteger(0, nextValue.size()-1);
        string next = nextValue[randomNextInt];
        cout << next;
        nextStr = next;
    }
}


void randomWriterReader (string filename, int n) {
    
    string randomText = " ";
    HashMap<string, Vector<string> > hMap;
    
    
    ifstream input;
    input.open(filename);
    
    
    string line;
    string text;
    while (getline(input, line)) {
        text += line + "\n";
    }
    
    for (int i = 0; i < text.size() - n; i++) {
        string key = "";
        key += text[i];
        string value = "";
        value += text[i+1];
        Vector<string> newVect;
        
        if (hMap.containsKey(key)) {
            Vector<string>& existingValue = hMap[key];
            existingValue.add(value);
        }
        else {
            newVect.add(value);
            hMap.add(key, newVect);
        }
        
//        cout << key << endl;
    }
    
    randomWriter(hMap);
}

bool fileExists(string filename) {
    ifstream ifile(filename);
    return ifile;
}

int main() {
   
    
    while (true) {
        string str = getLine("Enter the source text: ");
        int n = getInteger("Enter the Markov order [1-10]: ");
        if (fileExists(str)) {
            randomWriterReader (str, n);
            break;
        }
    }
    return 0;
}
