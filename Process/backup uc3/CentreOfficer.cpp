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
    << "\nposition: " << officer.position;
    return os;
}

void CentreOfficer::viewTestHistory() {}




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









