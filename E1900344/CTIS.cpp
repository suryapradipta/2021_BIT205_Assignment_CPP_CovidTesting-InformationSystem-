
#include "CTIS.h"
#include <iostream>

/**
 * A default constructor which is used to
 * initialise default value of CTIS System.
 */
CTIS::CTIS() {
    // Add approved Test Centres by hard-coded
    TestCentre testCentre1("approved","Tapah Health Clinic");
    TestCentre testCentre2("approved","Kampar Health Clinic");
    addTestCentre(testCentre1);
    addTestCentre(testCentre2);
}

/**
* An user defined destructor
*/
CTIS::~CTIS() {}

/**
 * The addCentreManager used to append value to container.
 * @param centreManager reference of centreManager object.
 */
void CTIS::addCentreManager(CentreOfficer &centreManager) {
    CTISCentreManagers.push_back(centreManager);
}

/**
 * The addTestCentre used to append value to container.
 * @param testCentre reference of testCentre object.
 */
void CTIS::addTestCentre(TestCentre &testCentre) {
    CTISTestCentres.push_back(testCentre);
}

/**
 * The addTester used to append value to container.
 * @param tester reference of tester object.
 */
void CTIS::addTester(CentreOfficer &tester) {
    CTISTesters.push_back(tester);
}

/**
 * The addPatient used to append value to container.
 * @param patient reference of patient object.
 */
void CTIS::addPatient(Patient &patient) {
    CTISPatients.push_back(patient);
}

/**
 * The findCentreManager support method which is used to
 * compare Centre Manager username in container.
 * @param username reference to compare.
 * @return true if found or false not found.
 */
bool CTIS::findCentreManager(const string& username) {
    for(auto & CTISCentreOfficer : CTISCentreManagers) {
        if(CTISCentreOfficer.getUsername() == username)
            return true;
    }
    return false;
}



/**
 * The findTester support method used to
 * get the address of a Test Center object based on the username in the container.
 * @param username reference to compare.
 * @return true if found or false not found.
 */
bool CTIS::findTester(const string& username) {
    for(auto & CTISTester : CTISTesters) {
        if(CTISTester.getUsername() == username)
            return true;
    }
    return false;
}

/**
 * The findPatient support method used to
 * get the address of a Patient object based on the username in the container.
 * @param username reference to compare.
 * @return true if found or false not found.
 */
bool CTIS::findPatient(const string& username) {
    for(auto & CTISPatient : CTISPatients) {
        if(CTISPatient.getUsername() == username)
            return false;
    }
    return true;
}

/**
 * The getTestCentreByID support method used to
 * get the address of a Test Center object based on the center ID in the container.
 * @param centreID reference to compare.
 * @return address of a Test Center object or nullptr if not found.
 */
TestCentre *CTIS::getTestCentreByID(const string& centreID) {
    for(auto & CTISTestCentre : CTISTestCentres) {
        if(CTISTestCentre.getCentreId() == centreID)
            return &CTISTestCentre;
    }
    return nullptr;
}

/**
 * getTestCentre support method used to
 * get CTISTestCentres object address in container.
 * @return CTISTestCentres object address or nullptr if empty.
 */
TestCentre *CTIS::getTestCentre() {
    for(auto & CTISTestCentre : CTISTestCentres) {
        return &CTISTestCentre;
    }
    return nullptr;
}

/**
 * The getPatient support method used to
 * get the address of a Patient object based on the username in the container.
 * @param username reference to compare.
 * @return address of a Patient object or nullptr if not found.
 */
Patient *CTIS::getPatient(const string& username) {
    for(auto & CTISPatient : CTISPatients) {
        if(CTISPatient.getUsername() == username)
            return &CTISPatient;
    }
    return nullptr;
}

/**
 * The getTestKit support method used to
 * get the address of a TestKit object based on the kitID in the container.
 * @param kitID reference to compare.
 * @return address of a TestKit object or nullptr if not found.
 */
TestKit *CTIS::getTestKit(const string& kitID) {
    for(auto & CTISTestCentre : CTISTestCentres) {
        for(int j = 0; j< CTISTestCentre.getTestKits().size(); j++) {
            if(CTISTestCentre.getTestKit()[j].getKitId() == kitID) {
                return &CTISTestCentre.getTestKit()[j];
            }
        }
    }
    return nullptr;
}

/**
 * The getCentreManager support method used to
 * get the address of a CentreOfficer object based on the centreName in the container.
 * @param centreName reference to compare.
 * @return address of a CentreOfficer object or nullptr if not found.
 */
CentreOfficer *CTIS::getCentreManager(const string& centreName) {
    for(auto & CTISCentreOfficer : CTISCentreManagers) {
        for(int j = 0; j < CTISCentreOfficer.getTestCentres().size(); j++) {
            if(CTISCentreOfficer.getTestCentre()[j].getCentreName() == centreName) {
                return &CTISCentreOfficer;
            }
        }
    }
    return nullptr;
}

/**
 * The getTestKitByManager support method used to
 * get the address of a TestKit object based on
 * the Centre Manager object and kit ID in the container.
 * @param centreManager reference object to compare.
 * @param kitID reference to compare.
 * @return address of a TestKit object or nullptr if not found.
 */
TestKit *CTIS::getTestKitByManager(CentreOfficer &centreManager, const string& kitID) {
    for(int x = 0; x < centreManager.getTestCentres().size(); x++) {
        for(int y = 0; y < centreManager.getTestCentre()[x].getTestKits().size(); y++) {
            if(centreManager.getTestCentre()[x].getTestKit()[y].getKitId() == kitID) {
                return &centreManager.getTestCentre()[x].getTestKit()[y];
            }
        }
    }
    return nullptr;
}

/**
 * The getCovidTestOfTester support method used to
 * get the address of a CovidTest object based on the test ID in the container.
 * @param testID reference to compare.
 * @return address of a CovidTest object or nullptr if not found.
 */
CovidTest *CTIS::getCovidTestOfTester(const string& testID) {
    for(auto & CTISTester : CTISTesters) {
        for(int j = 0; j < CTISTester.getCovidTests().size(); j++) {
            if(CTISTester.getCovidTest()[j].getTestId() == testID)
                return &CTISTester.getCovidTest()[j];
        }
    }
    return nullptr;
}

/**
 * The getPatientByCovidTest support method used to
 * get the address of a Patient object based on the test ID in the container.
 * @param testID reference to compare.
 * @return address of a Patient object or nullptr if not found.
 */
Patient *CTIS::getPatientByCovidTest(const string& testID) {
    for(auto & CTISPatient : CTISPatients) {
        for(int j = 0; j < CTISPatient.getCovidTests().size(); j++) {
            if(CTISPatient.getCovidTests()[j].getTestId() == testID)
                return &CTISPatient;
        }
    }
    return nullptr;
}

/**
 * The getTestCentreByCovidTest support method used to
 * get the address of a TestCentre object based on the test ID in the container.
 * @param testID reference to compare.
 * @return address of a TestCentre object or nullptr if not found.
 */
TestCentre *CTIS::getTestCentreByCovidTest(const string& testID) {
    for(auto & CTISCentreOfficer : CTISCentreManagers) {
        for(int j = 0; j < CTISCentreOfficer.getTestCentres().size(); j++) {
            for(int k =0; k< CTISCentreOfficer.getTestCentre()[j].getTestKits().size(); k++ ) {
                for(int l = 0; l < CTISCentreOfficer.getTestCentre()[j].getTestKit()[k].getCovidTests().size(); l++) {
                    if(CTISCentreOfficer.getTestCentre()[j].getTestKit()[k].getCovidTest()[l].getTestId() == testID) {
                        return &CTISCentreOfficer.getTestCentre()[j];
                    }
                }
            }
        }
    }
    return nullptr;
}

/**
 * The getTestKitByCovidTest support method used to
 * get the address of a TestKit object based on the test ID in the container.
 * @param testID reference to compare.
 * @return address of a TestKit object or nullptr if not found.
 */
TestKit *CTIS::getTestKitByCovidTest(const string& testID) {
    for(auto & CTISCentreOfficer : CTISCentreManagers) {
        for(int j = 0; j < CTISCentreOfficer.getTestCentres().size(); j++) {
            for(int k =0; k< CTISCentreOfficer.getTestCentre()[j].getTestKits().size(); k++ ) {
                for(int l = 0; l < CTISCentreOfficer.getTestCentre()[j].getTestKit()[k].getCovidTests().size(); l++) {
                    if(CTISCentreOfficer.getTestCentre()[j].getTestKit()[k].getCovidTest()[l].getTestId() == testID) {
                        return &CTISCentreOfficer.getTestCentre()[j].getTestKit()[k];
                    }
                }
            }
        }
    }
    return nullptr;
}

/**
 * The getPatientCovidTest support method used to
 * get the address of a CovidTest object based on the test ID in the container.
 * @param testID reference to compare.
 * @return address of a CovidTest object or nullptr if not found.
 */
CovidTest *CTIS::getPatientCovidTest(const string& testID) {
    for(auto & CTISPatient : CTISPatients) {
        for(int j = 0; j < CTISPatient.getCovidTests().size(); j++) {
            if(CTISPatient.getCovidTests()[j].getTestId() == testID)
                return &CTISPatient.getCovidTest()[j];
        }
    }
    return nullptr;
}

/**
 * The getCovidTet support method used to
 * get the address of a CovidTest object based on the test ID in the container.
 * @param testID reference to compare.
 * @return address of a CovidTest object or nullptr if not found.
 */
CovidTest *CTIS::getCovidTet(const string& testID) {
    for(auto & CTISCentreOfficer : CTISCentreManagers) {
        for(int j = 0; j < CTISCentreOfficer.getTestCentres().size(); j++) {
            for(int k =0; k< CTISCentreOfficer.getTestCentre()[j].getTestKits().size(); k++ ) {
                for(int l = 0; l < CTISCentreOfficer.getTestCentre()[j].getTestKit()[k].getCovidTests().size(); l++) {
                    if(CTISCentreOfficer.getTestCentre()[j].getTestKit()[k].getCovidTest()[l].getTestId() == testID) {
                        return &CTISCentreOfficer.getTestCentre()[j].getTestKit()[k].getCovidTest()[l];
                    }
                }
            }
        }
    }
    return nullptr;
}

/**
 * The adminLoginValidation support method used to
 * compare usernames and passwords of Centre Manager objects in containers.
 * @param usrname username to compare
 * @param pass password to compare
 * @return CTISCentreOfficer object address or nullptr if empty.
 */
CentreOfficer *CTIS::adminLoginValidation(const string& usrname, const string& pass) {
    for(auto & CTISCentreOfficer : CTISCentreManagers) {
        if (CTISCentreOfficer.getUsername() == usrname && CTISCentreOfficer.getPassword() == pass)
            return &CTISCentreOfficer;
    }
    return nullptr;
}

/**
 * The patientLoginValidation support method used to
 * compare usernames and passwords of Patient objects in containers.
 * @param username username to compare
 * @param password password to compare
 * @return CTISPatient object address or nullptr if empty.
 */
Patient *CTIS::patientLoginValidation(const string& username, const string& password) {
    for (auto & CTISPatient : CTISPatients) {
        if(CTISPatient.getUsername() == username && CTISPatient.getPassword() == password) {
            return &CTISPatient;
        }
    }
    return nullptr;
}

/**
 * The testerLoginValidation support method used to
 * compare usernames and passwords of Tester objects in containers.
 * @param username username to compare
 * @param password password to compare
 * @return CTISTester object address or nullptr if empty.
 */
CentreOfficer *CTIS::testerLoginValidation(const string& username, const string& password) {
    for(auto & CTISTester : CTISTesters) {
        if (CTISTester.getUsername() == username && CTISTester.getPassword() == password)
            return &CTISTester;
    }
    return nullptr;
}

/**
 * getNumOfApprovedTestCentres support method used to
 * calculate num of approved Test Centre object.
 * @return num of approved Test Centre object.
 */
int CTIS::getNumOfApprovedTestCentres() {
    int approved = 0;
    for(auto & CTISTestCentre : CTISTestCentres) {
        if(CTISTestCentre.getCentreId() == "approved")
            approved++;
    }
    return approved;
}

/**
 * showApprovedTestCentres support method used to
 * display approved Test Center object center name.
 */
void CTIS::showApprovedTestCentres() {
    for(int idx = 0; idx < CTISTestCentres.size(); idx++) {
        if(CTISTestCentres[idx].getCentreId() == "approved")
            cout << idx+1 << ". " << CTISTestCentres[idx].getCentreName() << endl;
    }
}

/**
 * showAllTestCentres support method used to
 * display all Test Center object center name.
 */
void CTIS::showAllTestCentres() {
    for(int idx = 0; idx < CTISTestCentres.size(); idx++)
        cout << idx+1 << ". " << CTISTestCentres[idx].getCentreName() << endl;
}

/**
 * showAllCovidTestID support method used to
 * displays the test ID of the pending Covid Test object.
 */
void CTIS::showAllCovidTestID() {
    for(auto & CTISTester : CTISTesters) {
        for (int idx = 0; idx < CTISTester.getCovidTests().size(); idx++) {
            if(CTISTester.getCovidTest()[idx].getStatus() == "pending")
                cout << CTISTester.getCovidTest()[idx].getTestId() << endl;
        }
    }
}

/**
 * The getNumOfPendingCovidTest support method used to
 * get the num of pending Covid Test object.
 * @return true if found or false not found.
 */
bool CTIS::getNumOfPendingCovidTest() {
    for(auto & CTISTester : CTISTesters) {
        for(int j = 0;  j< CTISTester.getCovidTests().size(); j++) {
            if(CTISTester.getCovidTest()[j].getStatus() == "pending")
                return true;
        }
    }
    return false;
}

/**
 * The covidTestIDValidation support method used to
 * compare test ID of Tester objects in containers.
 * @param testID reference to compare.
 * @return true if found or false not found.
 */
bool CTIS::covidTestIDValidation(const string& testID) {
    for(auto & CTISTester : CTISTesters) {
        for(int j = 0; j < CTISTester.getCovidTests().size(); j++) {
            if(CTISTester.getCovidTest()[j].getTestId() == testID)
                return true;
        }
    }
    return false;
}