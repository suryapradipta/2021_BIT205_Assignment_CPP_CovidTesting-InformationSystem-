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

void CentreOfficer::setPosition(string position) {
    CentreOfficer::position = position;
}

ostream &operator<<(ostream &os, const CentreOfficer &officer) {
    os << static_cast<const User &>(officer)
    << "\nPosition: " << officer.position;
    return os;
}

void CentreOfficer::viewTestHistory() {
    if(position == "Centre officer") {
        for(int i = 0; i < testCentres.size(); i++) {
            for(int j = 0; j < testCentres[i].getTestKitCollection().size(); j++) {
                for(int k = 0; k < testCentres[i].getTestKit()[j].getCovidTestCollection().size(); k++) {
                    cout << testCentres[i].getTestKit()[j].getCovidTest()[k] << endl;
                }
            }
        }
    }
    else if(position == "Tester") {
        for(int i = 0; i < testerCovidTest.size(); i++){
            cout << testerCovidTest[i] << endl;
        }
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
    testerCovidTest.push_back(covidTest);
}

void CentreOfficer::showAllTesterCovidTest() {
    for(int i = 0; i < testerCovidTest.size(); i++) {
        cout << i <<testerCovidTest[i] << endl;
    }
}

vector<CovidTest> CentreOfficer::getCovidTestCollection() const {
    return testerCovidTest;
}

CovidTest *CentreOfficer::getCovidTest() {
    for(int i = 0; i < testerCovidTest.size(); i++) {
        return &testerCovidTest[i];
    }
    return NULL;
}











