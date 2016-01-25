/*
 * File: UniversalHealthCoverage.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the UniversalHealthCoverage problem
 * on Assignment #3.
 * [TODO: extend the documentation]
 */
#include <iostream>
#include <string>
#include "set.h"
#include "vector.h"
#include "console.h"
using namespace std;

/* Function: canOfferUniversalCoverage(Set<string>& cities,
 *                                     Vector< Set<string> >& locations,
 *                                     int numHospitals,
 *                                     Vector< Set<string> >& result);
 * Usage: if (canOfferUniversalCoverage(cities, locations, 4, result)
 * ==================================================================
 * Given a set of cities, a list of what cities various hospitals can
 * cover, and a number of hospitals, returns whether or not it's
 * possible to provide coverage to all cities with the given number of
 * hospitals.  If so, one specific way to do this is handed back in the
 * result parameter.
 */

bool canOfferUniversalCoverage (int numHospitals, Set <string> cities, Vector<Set<string> >& v, Vector<Set<string> >& chosen) {
    
   //base case - if the set of locations (v) is empty then we are ready to look at the results.
    if (v.isEmpty()) {
        //if the results vector (chosen) is of the size of number of hospitals we can have then it is a possibility. We still need to confirm whether or not the Sets that make up that Vector are possibilities.
        if (chosen.size() == numHospitals) {
            // for each Set in the results Vector we will pull it out into the subSet variable. Then we will look at each string in that Set.
            for (int i = 0; i < chosen.size(); i++) {
                Set <string> subSet = chosen[i];
                for (string str : subSet) {
                    // The way to see if the results Vector contains a way to have all of the cities covered with the number of hospitals is to see if each city in our set of cities can be found in the vector. I remove each city string that is found in the Vector.
                    if (cities.contains(str)) {
                        cities.remove(str);
                    }
                }
            }
            //If all of the cities were in the Vector than the set of cities will then be empty. So I say if the cities list is empty then we can return true and print out the chosen Vector.
            if (cities.isEmpty()) {
                cout <<chosen << endl;
                return true;
            }
        }
    }
    //recursive case - where the v Vector (locations) is not empty.
    else {
        //Choose Step
        // I take the first set in my locations vector and set it to the "first" variable.
        Set<string> first = v[0];
        //Then I remove it from the locations vector.
        v.remove(0);
        //Then I add it to the chosen vector.
        chosen.add(first);
        //Explore Step
        // Now I will send in the same number of Hospitals and cities but v without it's first set and chosen with a set added. This will continue recursively until v is empty and then it will be at the base case and will determine whether to return true or not. If it returns true, finished will be set to return true so it will not repeat this step.
        bool finished = canOfferUniversalCoverage(numHospitals, cities, v, chosen);
        if (finished) {
            return true;
        }
        //Unchoose Step
        //Now I remove what has been added to chosen and run v and chosen again.
        chosen.remove(chosen.size() -1);
        bool finished2 = canOfferUniversalCoverage(numHospitals, cities, v, chosen);
        v.insert(0, first);
        if (finished2) {
            return true;
        }
        
    }
    return false;
}


int main() {
    Set<string> cities;
    cities.add("A");
    cities.add("B");
    cities.add("C");
    cities.add("D");
    cities.add("E");
    cities.add("F");
    
    Vector<Set<string> > locations;
    Set<string> loc1;
    loc1.add("A");
    loc1.add("B");
    loc1.add("C");
    Set<string> loc2;
    loc2.add("A");
    loc2.add("C");
    loc2.add("D");
    Set<string> loc3;
    loc3.add("B");
    loc3.add("F");
    Set<string> loc4;
    loc4.add("C");
    loc4.add("E");
    loc4.add("F");
    locations.add(loc1);
    locations.add(loc2);
    locations.add(loc3);
    locations.add(loc4);
    Vector<Set<string> > result;
    int numHospitals = 3;
    
    cout << canOfferUniversalCoverage (numHospitals, cities, locations, result) << endl;
    
    return 0;
}


