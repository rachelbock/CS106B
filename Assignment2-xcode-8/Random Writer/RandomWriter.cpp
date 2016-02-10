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

string randomWriter(HashMap<string, Vector<string> > hMap, int n) {
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
    nextStr = "";
    
    for (int i = 1; i < n; i++) {
        nextStr += bestKey[i];
    }
    
    nextStr += bestValue[randomI];
    
    for (int i = 0; i < numStrings; i ++) {
        
        Vector<string> nextValue = hMap.get(nextStr);
        
        if (nextValue.isEmpty()) {
            nextStr = bestKey;
        }
        else {
            int randomNextInt = randomInteger(0, nextValue.size()-1);
            string next = nextValue[randomNextInt];
            finalStr+= next;
            string currentKey = nextStr;
            nextStr = "";
        
            for (int j = 1; j < n; j++) {
                nextStr += currentKey[j];
            }
            nextStr += next;
        }
    }
    return finalStr;
}



string randomWriterReader (string filename, int n) {
    
    HashMap<string, Vector<string> > hMap;

    //Open the file provided.
    ifstream input;
    input.open(filename);
    
    string line;
    string text;
    //While there are lines in the text, add them to a string called text with a carriage return after each line.
    while (getline(input, line)) {
        text += line + "\n";
    }
    
    //for each character in the file minus the markov order, create a blank key and value.
    for (int i = 0; i < text.size() - n; i++) {
        string key = "";
        string value = "";
        
        //for each character between 0 and markov order, set the key to be the character at that point up to the markov order. If
        //j is the last markov order than set the value to be teh character at text[i+n}
        for (int j = 0; j < n; j++) {
            
            key += text[i+j];
            if (j == n-1) {
                value += text[i+n];
            }
        }
        //check if the hashmap contains the key - if it does, add the value to the existing value hashmap.
        //If not, then create a new vector and add it and add that to the hashmap.
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
    
   return randomWriter(hMap, n);
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
