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

}





void Patient::addPatientType(string patientType) {
    patientTypeCollection.push_back(patientType);
}

void Patient::showAllPatientType() {
    for(int i = 0; i < patientTypeCollection.size(); i++) {
        cout << i+1 << ". " << patientTypeCollection[i] << endl;
    }

}

string *Patient::getPatientType() {
    for(int i = 0; i < patientTypeCollection.size(); i++) {
        return &patientTypeCollection[i];
    }
    return nullptr;
}




void Patient::addCovidTest(CovidTest &covidTest) {
    patientCovidTests.push_back(covidTest);
}

void Patient::showAllPatientCovidTest() {
    for(int i = 0; i < patientCovidTests.size(); i++) {
        cout << i+1 << ". " << patientCovidTests[i] << endl;
    }
}

CovidTest *Patient::getCovidTest() {
    for(int i = 0; i < patientCovidTests.size(); i++) {
        return &patientCovidTests[i];
    }
    return nullptr;
}

vector<CovidTest> Patient::getCovidTestCollection() const {
    return patientCovidTests;
}



