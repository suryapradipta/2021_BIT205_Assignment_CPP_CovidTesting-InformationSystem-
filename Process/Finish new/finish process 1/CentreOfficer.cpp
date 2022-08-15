//
// Created by Surya Pradipta on 09/12/21.
//

#include <iostream>
#include "CTIS.h"

CentreOfficer::CentreOfficer() : position("unknown") {}

CentreOfficer::CentreOfficer(string username, string password, string name, string position)
        : User(username, password, name), position(position) {}

CentreOfficer::~CentreOfficer() {}

string CentreOfficer::getPosition() const {
    return position;
}
/**
 *
 * @param position
 */
void CentreOfficer::setPosition(string position) {
    CentreOfficer::position = position;
}

ostream &operator<<(ostream &os, const CentreOfficer &officer) {
    os << static_cast<const User &>(officer)
    << "\nPosition: " << officer.position;
    return os;
}

void CentreOfficer::viewTestHistory() {
    if(position == "Centre manager") {
        for (t = testCentres.begin(); t < testCentres.end(); t++) {
            for(int j = 0; j < t->getTestKitCollection().size(); j++) {
                for(int k = 0; k < t->getTestKit()[j].getCovidTestCollection().size(); k++) {
                    cout << t->getTestKit()[j].getCovidTest()[k] << endl;
                }
            }
        }
    }
    else if(position == "Tester") {
        for (c = covidTests.begin(); c < covidTests.end(); c++)
            cout << *c << endl;
    }
}




void CentreOfficer::addTestCentre(TestCentre testCentre) {
    testCentres.push_back(testCentre);
}

void CentreOfficer::showAllTestCentre()
{
    for(int i = 0; i < testCentres.size(); i++) {
        cout << testCentres[i] << endl;
    }
}

vector<TestCentre> CentreOfficer::getTestCentreCollection() const {
    return testCentres;
}

TestCentre *CentreOfficer::getTestCentre() {
    for(int i = 0; i < testCentres.size(); i++) {
       return &testCentres[i];
    }
    return NULL;
}

void CentreOfficer::addCovidTest(CovidTest &covidTest) {
    covidTests.push_back(covidTest);
}

void CentreOfficer::showAllTesterCovidTest() {
    for(int i = 0; i < covidTests.size(); i++) {
        cout << i << covidTests[i] << endl;
    }
}

vector<CovidTest> CentreOfficer::getCovidTestCollection() const {
    return covidTests;
}

CovidTest *CentreOfficer::getCovidTest() {
    for(int i = 0; i < covidTests.size(); i++) {
        return &covidTests[i];
    }
    return NULL;
}











