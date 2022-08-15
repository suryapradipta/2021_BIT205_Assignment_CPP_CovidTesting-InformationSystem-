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
CentreOfficer *CTIS::getCentreOfficer() {
    for(int i = 0; i < CTISCentreOfficers.size(); i++) {
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

vector<TestCentre> CTIS::getTestCentreCollection() const {
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

void CTIS::showAllTestCentre() {
    for(int i = 0; i < CTISTestCentres.size(); i++) {
        cout << i+1 << ". " << CTISTestCentres[i].getCentreName() << endl;
    }
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

void CTIS::showALlCovidTest() {
    for(int i = 0; i < CTISTesters.size(); i++) {
        for (int j = 0; j < CTISTesters[i].getCovidTestCollection().size(); j++) {
            cout << CTISTesters[i].getCovidTestCollection()[j] << endl;
        }
    }
}


void CTIS::showAllCovidTestID() {
    for(int i = 0; i < CTISTesters.size(); i++) {
        for (int j = 0; j < CTISTesters[i].getCovidTestCollection().size(); j++) {
            if(CTISTesters[i].getCovidTest()[j].getStatus() == "pending")
                cout << CTISTesters[i].getCovidTest()[j].getTestId() << endl;
        }
    }
}

Patient *CTIS::getCovidTestByID(string testID) {
    for(int i = 0; i < CTISPatients.size(); i++) {
        for (int j = 0; j < CTISPatients[i].getCovidTestCollection().size(); j++) {
            if(CTISPatients[i].getCovidTestCollection()[j].getTestId() == testID) {
                return &CTISPatients[i];
            }

        }
    }
    return NULL;
}
CovidTest *CTIS::findCovidTestTester(string testID) {
    for(int i = 0; i < CTISTesters.size(); i++) {
        for(int j = 0; j < CTISTesters[i].getCovidTestCollection().size(); j++) {
            if(CTISTesters[i].getCovidTest()[j].getTestId() == testID)
                return &CTISTesters[i].getCovidTest()[j]; // yang dikirim objectnya
        }
    }
    return nullptr;
}

Patient *CTIS::getPatientCovidTest(string testID) {
    for(int i = 0; i < CTISPatients.size(); i++) {
        for(int j = 0; j < CTISPatients[i].getCovidTestCollection().size(); j++) {
            if(CTISPatients[i].getCovidTestCollection()[j].getTestId() == testID)
                return &CTISPatients[i]; // yang dikirim objectnya
        }
    }
    return nullptr;
}

CovidTest *CTIS::findCovidTestPatient(string testID) {
    for(int i = 0; i < CTISPatients.size(); i++) {
        for(int j = 0; j < CTISPatients[i].getCovidTestCollection().size(); j++) {
            if(CTISPatients[i].getCovidTestCollection()[j].getTestId() == testID)
                return &CTISPatients[i].getCovidTest()[j];
        }
    }
    return nullptr;
}

CovidTest *CTIS::findCovidTestTestKit(string testID) {
    for(int i = 0; i < CTISCentreOfficers.size(); i++) {
        for(int j = 0; j < CTISCentreOfficers[i].getTestCentreCollection().size(); j++) {
            for(int k =0; k<CTISCentreOfficers[i].getTestCentre()[j].getTestKitCollection().size();k++ ) {
                for(int l = 0; l < CTISCentreOfficers[i].getTestCentre()[j].getTestKit()[k].getCovidTestCollection().size(); l++) {
                    if(CTISCentreOfficers[i].getTestCentre()[j].getTestKit()[k].getCovidTest()[l].getTestId() == testID) {
                        return &CTISCentreOfficers[i].getTestCentre()[j].getTestKit()[k].getCovidTest()[l];
                    }
                }
            }
        }
    }
    return nullptr;
}



//debug
void CTIS::showAllTestCentreInAllAdmin() {
    for(int i = 0; i < CTISCentreOfficers.size(); i++) {
        cout << "============================================" << endl;
        cout << CTISCentreOfficers[i] << endl;
        for(int j = 0; j < CTISCentreOfficers[i].getTestCentreCollection().size(); j++) {
            cout << CTISCentreOfficers[i].getTestCentre()[j] << endl;

        }
    }
}

void CTIS:: showAllTesters() {
    for(int i = 0; i < CTISTesters.size(); i++) {
        cout << CTISTesters[i] << endl;
        cout << "============================================" << endl;
    }
}

void CTIS::showAllTestKit() {
    for(int i = 0; i < CTISCentreOfficers.size(); i++) {
        cout << "============================================" << endl;
        cout << CTISCentreOfficers[i] << endl;
        for(int j = 0; j < CTISCentreOfficers[i].getTestCentreCollection().size(); j++) {
            cout << CTISCentreOfficers[i].getTestCentre()[j] << endl;
            for(int k = 0; k <CTISCentreOfficers[i].getTestCentreCollection()[j].getTestKitCollection().size();k++) {
                cout << CTISCentreOfficers[i].getTestCentreCollection()[j].getTestKit()[k] << endl;

            }

        }
    }
}

void CTIS::showAllPatientCovidTest() {
    for(int i = 0; i <CTISPatients.size(); i++) {
        cout << "============================================" << endl;
        cout << CTISPatients[i] << endl;
        for (int  j = 0; j< CTISPatients[i].getCovidTestCollection().size(); j++) {
            cout <<CTISPatients[i].getCovidTest()[j] << endl;
        }
    }
}

Patient *CTIS::getPatientByUsername(string username) {
    for(int i = 0; i < CTISPatients.size(); i++) {
        if(CTISPatients[i].getUsername() == username)
            return &CTISPatients[i];
    }
    return nullptr;
}

TestCentre *CTIS::findTestCentre(string centreID) {
    for(int i = 0; i < CTISTestCentres.size(); i++) {
        if(CTISTestCentres[i].getCentreId() == centreID)
            return &CTISTestCentres[i];
    }
    return nullptr;
}

void CTIS::showAllCovidTestTester() {
    for(int i = 0; i < CTISTesters.size(); i++) {
        cout << "============== "<< endl;
        cout << CTISTesters[i] << endl;
        for(int j = 0; j < CTISTesters[i].getCovidTestCollection().size();j++) {
            cout <<  CTISTesters[i].getCovidTest()[j] << endl;
        }
    }
}

void CTIS::showALlCovidTestTestKit() {
    for(int i = 0; i < CTISCentreOfficers.size(); i++) {
        for(int j = 0; j < CTISCentreOfficers[i].getTestCentreCollection().size(); j++) {
            for(int k =0; k<CTISCentreOfficers[i].getTestCentre()[j].getTestKitCollection().size();k++ ) {
                for(int l = 0; l < CTISCentreOfficers[i].getTestCentre()[j].getTestKit()[k].getCovidTestCollection().size(); l++) {
                    cout << CTISCentreOfficers[i].getTestCentre()[j].getTestKit()[k].getCovidTest()[l] << endl;
                }
            }
        }
    }

}

TestCentre *CTIS::findTestCentreCovidTest(string testID) {
    for(int i = 0; i < CTISCentreOfficers.size(); i++) {
        for(int j = 0; j < CTISCentreOfficers[i].getTestCentreCollection().size(); j++) {
            for(int k =0; k<CTISCentreOfficers[i].getTestCentre()[j].getTestKitCollection().size();k++ ) {
                for(int l = 0; l < CTISCentreOfficers[i].getTestCentre()[j].getTestKit()[k].getCovidTestCollection().size(); l++) {
                    if(CTISCentreOfficers[i].getTestCentre()[j].getTestKit()[k].getCovidTest()[l].getTestId() == testID) {
                        return &CTISCentreOfficers[i].getTestCentre()[j];
                    }
                }
            }
        }
    }
    return nullptr;
}

TestKit *CTIS::findTestKitCovidTest(string testID) {
    for(int i = 0; i < CTISCentreOfficers.size(); i++) {
        for(int j = 0; j < CTISCentreOfficers[i].getTestCentreCollection().size(); j++) {
            for(int k =0; k<CTISCentreOfficers[i].getTestCentre()[j].getTestKitCollection().size();k++ ) {
                for(int l = 0; l < CTISCentreOfficers[i].getTestCentre()[j].getTestKit()[k].getCovidTestCollection().size(); l++) {
                    if(CTISCentreOfficers[i].getTestCentre()[j].getTestKit()[k].getCovidTest()[l].getTestId() == testID) {
                        return &CTISCentreOfficers[i].getTestCentre()[j].getTestKit()[k];
                    }
                }
            }
        }
    }
    return nullptr;
}

bool CTIS::covidTestIDValidation(string testID) {
    for(int i = 0; i < CTISTesters.size(); i++) {
        for(int j = 0; j < CTISTesters[i].getCovidTestCollection().size();j++) {
            if(CTISTesters[i].getCovidTest()[j].getTestId() == testID)
                return true;
        }
    }
    return false;
}

TestKit *CTIS::findTestKit(string kitID) {
    for(int i = 0; i < CTISTestCentres.size(); i++) {
        for(int j = 0; j<CTISTestCentres[i].getTestKitCollection().size(); j++) {
            if(CTISTestCentres[i].getTestKit()[j].getKitId() == kitID) {
                return &CTISTestCentres[i].getTestKit()[j];
            }
        }
    }
    return NULL;
}

bool CTIS::numberOfPending() {
    for(int i = 0; i< CTISTesters.size(); i++) {
        for(int j = 0;  j< CTISTesters[i].getCovidTestCollection().size();j++) {
            if(CTISTesters[i].getCovidTest()[j].getStatus() == "pending")
                return true;
        }
    }
    return false;
}

Patient *CTIS::patientLoginValidation(string username, string password) {
    for (int i = 0; i < CTISPatients.size(); i++) {
        if(CTISPatients[i].getUsername() == username && CTISPatients[i].getPassword() == password) {
            return &CTISPatients[i];
        }
    }
    return NULL;
}

CentreOfficer *CTIS::findCentreOfficer(string centreName) {
    for(int i = 0; i < CTISCentreOfficers.size(); i++) {
        for(int j = 0; j < CTISCentreOfficers[i].getTestCentreCollection().size(); j++) {
            if(CTISCentreOfficers[i].getTestCentre()[j].getCentreName() == centreName) {
                return &CTISCentreOfficers[i];
            }
        }
    }
    return nullptr;
}

TestKit *CTIS::findTestKitByCentreOfficer(CentreOfficer &centreOfficer, string kitID) {
    for(int i = 0; i < centreOfficer.getTestCentreCollection().size(); i++) {
        for(int j = 0; j < centreOfficer.getTestCentre()[i].getTestKitCollection().size(); j++) {
            if(centreOfficer.getTestCentre()[i].getTestKit()[j].getKitId() == kitID) {
                return &centreOfficer.getTestCentre()[i].getTestKit()[j];
            }
        }
    }
    return NULL;
}

bool CTIS::availableTestKit() {
    for(int i = 0; i < CTISCentreOfficers.size(); i++) {
        for(int j = 0; i < CTISCentreOfficers[i].getTestCentreCollection().size(); j++) {
            for(int k = 0; i < CTISCentreOfficers[i].getTestCentre()[j].getTestKitCollection().size(); k++) {
                if(CTISCentreOfficers[i].getTestCentre()[j].getTestKit()[k].getAvailableStock() > 0)
                    return true;
            }
        }
    }
    return false;
}

bool CTIS::kitIDValidation(string kitID) {
    for(int i = 0; i < CTISCentreOfficers.size(); i++) {
        for(int j = 0; i < CTISCentreOfficers[i].getTestCentreCollection().size(); j++) {
            for(int k = 0; i < CTISCentreOfficers[i].getTestCentre()[j].getTestKitCollection().size(); k++) {
                if(CTISCentreOfficers[i].getTestCentre()[j].getTestKit()[k].getKitId() == kitID)
                    return true;
            }
        }
    }
    return false;
}











