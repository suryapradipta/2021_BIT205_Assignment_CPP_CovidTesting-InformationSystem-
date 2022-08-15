//
// Created by Surya Pradipta on 09/12/21.
//

#include <iostream>
#include "CTIS.h"

CTIS::CTIS() {
    TestCentre testCentre1("approved","Tapah Health Clinic");
    TestCentre testCentre2("approved","Kampar Health Clinic");
    addTestCentre(testCentre1);
    addTestCentre(testCentre2);
}

CTIS::~CTIS() {}

void CTIS::addCentreOfficer(CentreOfficer &centreOfficer) {
    CTISCentreOfficers.push_back(centreOfficer);
}

vector<CentreOfficer> CTIS::getCentreOfficerCollection() const {
    return CTISCentreOfficers;
}

void CTIS::showAllCentreOfficers() {
    for (int i = 0; i < CTISCentreOfficers.size(); i++)
        cout << CTISCentreOfficers[i] << endl;
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

void CTIS::addTestCentre(TestCentre &testCentre) {
    CTISTestCentres.push_back(testCentre);
}

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




// tester ============
CentreOfficer *CTIS::testerLoginValidation(string username, string password) {
    for(int i = 0; i < CTISTesters.size(); i++) {
        if (CTISTesters[i].getUsername() == username && CTISTesters[i].getPassword() == password)
            return &CTISTesters[i];
    }
    return NULL;
}





// patinet=======

void CTIS::addPatient(Patient &patient) {
    CTISPatients.push_back(patient);
}

Patient *CTIS::getPatient() {
    for(auto & CTISPatient : CTISPatients) {
        return &CTISPatient;
    }
    return NULL;
}

vector<Patient> CTIS::getPatientCollection() const {
    return CTISPatients;
}

void CTIS::showAllPatients() {
    for(int i = 0; i < CTISPatients.size(); i++) {
        cout << CTISPatients[i] << endl << endl;
    }
}


void CTIS::showAllPatientName() {
    for(int i = 0; i < CTISPatients.size(); i++) {
        cout << i+1 << ". " << CTISPatients[i].getName() << endl;
    }
}


void CTIS::showALlCovidTest() {
    for(int i = 0; i < CTISTesters.size(); i++) {
        for (int j = 0; j < CTISTesters[i].getCovidTestCollection().size(); j++) {
            cout << CTISTesters[i].getCovidTestCollection()[j] << endl;
        }
    }
}

int CTIS::getPatient(string username) {
    for(int i = 0; i < CTISPatients.size(); i++) {
        if(CTISPatients[i].getUsername() == username)
        return i;
    }
    return -1;
}

bool CTIS::findPatientByUsername(string username) {
    for(int i = 0; i < CTISPatients.size(); i++) {
        if(CTISPatients[i].getUsername() == username)
            return false;
    }
    return true;
}




