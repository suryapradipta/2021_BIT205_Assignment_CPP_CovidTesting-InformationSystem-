//
// Created by Surya Pradipta on 11/12/21.
//

#include "CTIS.h"
#include <iostream>

using namespace std;

Patient::Patient() : patientType("unknown"), symptoms("unknown") {
    addPatientType("returnee");
    addPatientType("quarantined");
    addPatientType("close contact");
    addPatientType("infected");
    addPatientType("suspected");


}

Patient::Patient(string username, string password, string name, string patientType,
                 string symptoms) : User(username, password, name),
                 patientType(patientType), symptoms(symptoms) {}

Patient::~Patient() {}

string Patient::getPatientType() const {
    return patientType;
}

string Patient::getSymptoms() const {
    return symptoms;
}

void Patient::setPatientType(string patientType) {
    Patient::patientType = patientType;
}

void Patient::setSymptoms(string symptoms) {
    Patient::symptoms = symptoms;
}

ostream &operator<<(ostream &os, const Patient &patient) {
    os << static_cast<const User &>(patient)
    << "\nPatient type: " << patient.patientType
    << "\nSymptoms: " << patient.symptoms;
    return os;
}

void Patient::viewTestHistory() {
    for(int i = 0; i < covidTests.size(); i++) {
        cout << covidTests[i] << endl;
    }

}


void Patient::addPatientType(string patientType) {
    patientTypeCollection.push_back(patientType);
}

void Patient::showAllPatientType() {
    for (c = covidTests.begin(); c < covidTests.end(); c++)
        cout << *c << endl;

}

string *Patient::getPatientTypeObj() {
    for(auto & i : patientTypeCollection) {
        return &i;
    }
    return nullptr;
}

void Patient::addCovidTest(CovidTest &covidTest) {
    covidTests.push_back(covidTest);
}

void Patient::showAllPatientCovidTest() {
    for(int i = 0; i < covidTests.size(); i++) {
        cout << i << ". " << covidTests[i] << endl;
    }
}

CovidTest *Patient::getCovidTest() {
    for(auto & covidTest : covidTests) {
        return &covidTest;
    }
    return nullptr;
}

vector<CovidTest> Patient::getCovidTestCollection() const {
    return covidTests;
}



