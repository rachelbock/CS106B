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

string randomWriter(HashMap<string, Vector<string> > hMap) {
    string finalStr = "";
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
    finalStr += bestKey;
    finalStr += nextStr;
    
    for (int i = 0; i < numStrings; i ++) {
        Vector<string> nextValue = hMap.get(nextStr);
        int randomNextInt = randomInteger(0, nextValue.size()-1);
        string next = nextValue[randomNextInt];
        finalStr+= next;
        nextStr = next;
    }
    return finalStr;
}



string randomWriterReader (string filename, int n) {
    
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
        
        for (int j = 1; j < n; j++) {
            key += text[i+j];
            if (j == n-1) {
                value += text[i+n];
            }
        }
        
        if (hMap.containsKey(key)) {
            Vector<string>& existingValue = hMap[key];
            existingValue.add(value);
        }
        else {
            Vector<string> newVect;
            newVect.add(value);
            hMap.add(key, newVect);
        }

    }
    
   return randomWriter(hMap);
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
            cout << randomWriterReader (str, n);
            break;
        }
    }
    return 0;
}
