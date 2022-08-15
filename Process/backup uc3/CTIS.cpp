//
// Created by Surya Pradipta on 09/12/21.
//

#include <iostream>
#include "CTIS.h"

CTIS::CTIS() {
    CTISTestCentres.emplace_back("approved","Balimed Hospital");
    CTISTestCentres.emplace_back("approved","Prima Medika Hospital");
}

CTIS::~CTIS() {}

void CTIS::addCentreOfficer(CentreOfficer &centreOfficer) {
    CTISCentreOfficers.push_back(centreOfficer);
}

vector<CentreOfficer> CTIS::getCentreOfficers() const {
    return CTISCentreOfficers;
}

void CTIS::showAllCentreOfficers() {
    for(int i = 0; i < CTISCentreOfficers.size(); i++) {
        cout << CTISCentreOfficers[i] << endl;
    }
}

bool CTIS::findUsernameCentreOfficer(string username) {
    for(int i = 0; i < CTISCentreOfficers.size(); i++) {
        if(CTISCentreOfficers[i].getUsername() == username)
            return true;
    }
    return false;
}

CentreOfficer *CTIS::adminLoginValidation(string username, string password) {
    for(int i = 0; i < CTISCentreOfficers.size(); i++) {
        if (CTISCentreOfficers[i].getUsername() == username && CTISCentreOfficers[i].getPassword() == password)
            return &CTISCentreOfficers[i];
    }
    return NULL;
}


// ==== test centre
TestCentre *CTIS::getTestCentre() {
    for(int i = 0; i < CTISTestCentres.size(); i++) {
        return &CTISTestCentres[i];
    }
    return NULL;
}

vector<TestCentre> CTIS::getCTISTestCentreCollection() const {
    return CTISTestCentres;
}

void CTIS::showApprovedTestCentres() {
    for(int i = 0; i < CTISTestCentres.size(); i++) {
        if(CTISTestCentres[i].getCentreId() == "approved")
            cout << i+1 << ". " << CTISTestCentres[i].getCentreName() << endl;
    }
}

int CTIS::getNumOfApprovedTestCentres() {
    int pending = 0;
    for(int i = 0; i < CTISTestCentres.size(); i++) {
        if(CTISTestCentres[i].getCentreId() == "approved")
            pending++;
    }
    return pending;
}


// ====tester
void CTIS::addTester(CentreOfficer &tester) {
    CTISTesters.push_back(tester);
}

vector<CentreOfficer> CTIS::getTester() const { // ambil semua vector // kalo yang lagi 1 return object[i] address untuk push back , ambil alamat dari object sesuai index
    return CTISTesters;
}

bool CTIS::findUsernameTester(string username) {
    for(int i = 0; i < CTISTesters.size(); i++) {
        if(CTISTesters[i].getUsername() == username)
            return true;
    }
    return false;
}

void CTIS::showAllTesters() {
    for(int i = 0; i < CTISTesters.size(); i++) {
        cout << CTISTesters[i] << endl;
    }
}



TestCentre *CTIS::findTestCentre(string centreName) {
    for(int i = 0; i < CTISTestCentres.size(); i++) {
        if(CTISTestCentres[i].getCentreName() == centreName)
            return &CTISTestCentres[i];
    }
    return NULL;
}










