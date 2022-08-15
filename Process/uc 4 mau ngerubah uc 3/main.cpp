#include <iostream>
#include "CTIS.h"
#include <vector>

using namespace std;

char mainMenu();
void adminLoginMenu();
char adminMenu();
void registerTestCentreManager(char &position);
void registerTestCentre();
void manageKitStock();


void recordNewTest();

char testerMenu();
void testerLoginMenu();

void registerPatient();

CTIS CTISSystem;
CentreOfficer *centreManagerLogin;
CentreOfficer *testerLogin;
int iCentreName;
TestCentre centreKitStock;





int cID = 0;
string generateCentreID() {
    cID++;
    string id = to_string(cID).length() == 1 ?("C00" + to_string(cID))
            : to_string(cID).length() == 2 ? ("C0" + to_string(cID))
            : to_string(cID);
    return id;
}

int kID = 0;
string generateKitID() {
    kID++;
    string id = to_string(kID).length() == 1 ?("K00" + to_string(kID))
            : to_string(kID).length() == 2 ? ("K0" + to_string(kID))
            : to_string(kID);
    return id;
}

int tID = 0;
string generateTestID() {
    tID++;
    string id = to_string(tID).length() == 1 ?("T00" + to_string(tID))
            : to_string(tID).length() == 2 ? ("T0" + to_string(tID))
            : to_string(kID);
    return id;
}


string testDate() {
    time_t curr_time;
    tm * curr_tm;
    char date_string[100];

    time(&curr_time);
    curr_tm = localtime(&curr_time);

    strftime(date_string, 50, "%F %R", curr_tm);
    return date_string;
}

int main() {
    char option;
    char tempPosition;
    do {
        option = mainMenu();
        switch (option) {
            case '1':
                tempPosition = 'A';
                cout << "Create your Test Centre Manager account\n" << endl;
                registerTestCentreManager(tempPosition);
                cout << "\nRegister success! A Test Centre Manager account is created." << endl;
                break;
            case '2':
                registerPatient();
                break;
            case '3':
                adminLoginMenu();
                break;
            case '4':
                testerLoginMenu();
                break;




            case '7':
                CTISSystem.showAllPatients();
                break;
            case '8':
                CTISSystem.showAllCentreOfficers();
                break;

            case 'e':
            case 'E':
                cout << "\nThank you" << endl;
                break;
            default:
                cout << "Invalid choice! Try again" << endl;
        }
    }while (option != 'E' && option != 'e');
    //delete centreOfficerLogin; // problem ketika exit
    return 0;
}

char mainMenu() {
    char option = 0;
    cout << "\nCovid Testing Information System (CTIS) Menu:" << endl;
    cout << "1. Register test centre manager" << endl;
    cout << "2. Register patient" << endl;
    cout << "3. Test centre manager login" << endl;
    cout << "4. Tester login" << endl;
    cout << "5. Patient login" << endl;
    cout << "\n7. Show all Patient "<< endl;
    cout << "8. All Centre Manager" << endl;
    cout << "Press (E/e) to exit" << endl;
    cout << "Menu of choices: ";
    cin >> option;
    cout << endl;
    return option;
}

void adminLoginMenu() {
    cout << "Use your Test Centre Manager account" << endl;
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    centreManagerLogin = CTISSystem.adminLoginValidation(username, password);
    if(centreManagerLogin == NULL)
        cout << "\nCan't find your Test Centre Manager account" << endl;
    else {
        cout << "\nWelcome, " << centreManagerLogin->getName() << endl;
        char option;
        char tempPosition;
        do {
            option = adminMenu();
            switch (option) {
                case '1':
                    registerTestCentre();
                    break;
                case '2':
                    tempPosition = 'T';
                    cout << "Create your Tester account\n" << endl;
                    registerTestCentreManager(tempPosition);
                    cout << "\nRegister success! A Tester account is created." << endl;
                    break;
                case '3':
                    manageKitStock();
                    break;
                case '7':
                    centreManagerLogin->getTestCentre()->showAllTestKit();
                    break;
                case '8':
                    CTISSystem.showAllTesters();
                    break;
                case '9':
                    centreManagerLogin->showAllTestCentre();
                    break;
                case 'e':
                case 'E':
                    cout << "Back to main menu..." << endl;
                    break;
                default:
                    cout << "Invalid choice! Try again" << endl;

            }
        }while (option != 'E' && option != 'e');
    }
}

char adminMenu() {
    char choice = 0;
    cout << "\nAdmin Menu:" << endl;
    cout << "1. Register test centre" << endl;
    cout << "2. Register tester" << endl;
    cout << "3. Manage test kit stock" << endl;
    cout << "\n7. all TEst Kit" << endl;
    cout << "8. All testers" << endl;
    cout << "9. All test centre registered in admin" << endl;
    cout << "Press (E/e) to back to main menu" << endl;
    cout << "Menu of choices: " << flush;
    cin >> choice;
    cout << endl;
    return choice;
}



void registerPatient() {
    Patient tempPatient;
    cout << "Register Patient:" << endl;
    string username, password, name, symptoms;
    int iPatientType;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    cout << "Enter name: ";
    getline(cin >> ws, name);
    cout << "Patient type: " << endl;
    tempPatient.showAllPatientType();
    cout << "Select patient type: ";
    cin >> iPatientType;
    cout << "Enter symptoms: ";
    getline(cin >> ws, symptoms);
    string patientType = tempPatient.getPatientType()[iPatientType-1];
    Patient newPatient(username, password, name, patientType, symptoms);
    CTISSystem.addPatient(newPatient);
}

Patient *patientTest;
void recordNewTest() {
    int iPatient;
    cout << "Record new test:" << endl;
    CTISSystem.showAllPatientName();
    cout << "Select patient name: ";
    cin >> iPatient;
    patientTest = &CTISSystem.getPatient()[iPatient-1];
    if(patientTest->getCovidTestCollection().empty()) {
        cout << *patientTest << endl;
    }
    else {

        patientTest->setPatientType();

    }



}

void testerLoginMenu() {
    cout << "Use your Tester account" << endl;
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    testerLogin = CTISSystem.testerLoginValidation(username, password);
    if(testerLogin == NULL)
        cout << "\nCan't find your Tester account" << endl;
    else {
        cout << "\nWelcome, " << testerLogin->getName() << endl;
        char option;
        do {
            option = testerMenu();
            switch (option) {
                case '1':
                    recordNewTest();
                    break;
                case '6':
                    CTISSystem.showALlCovidTest();
                    break;

                case '7':
                    testerLogin->showAllTesterCovidTest();
                    break;
                case '8':
                    //patientTest->showAllPatientCovidTest();
                    break;
                case '9':
                    CTISSystem.showAllPatients();
                    break;

                case 'e':
                case 'E':
                    cout << "Back to main menu..." << endl;
                    break;
                default:
                    cout << "Invalid choice! Try again" << endl;
            }
        }while (option != 'E' && option != 'e');
    }


}

char testerMenu() {
    char choice = 0;
    cout << "\nTester Menu:" << endl;
    cout << "1. Record new test" << endl;
    cout << "7. all covid test in tester" << endl;
    cout << "8. all covid test in patient" << endl;
    cout << "9. all patient" << endl;
    cout << "Press (E/e) to back to main menu" << endl;
    cout << "Menu of choices: " << flush;
    cin >> choice;
    cout << endl;
    return choice;
}

void registerTestCentre()
{
    cout << "Register test centre:" << endl;

    if(CTISSystem.getNumOfApprovedTestCentres() > 0 && centreManagerLogin->getTestCentreCollection().empty()) { // <1

        CTISSystem.showApprovedTestCentres();
        cout << "Select centre name: ";
        cin >> iCentreName;

        // get centrename
        string tempCentreName = CTISSystem.getTestCentre()[iCentreName-1].getCentreName();
        // create test centre
        TestCentre testCentre(generateCentreID(), tempCentreName);
        // set test centre in CTIS
        CTISSystem.getTestCentre()[iCentreName-1].setCentreId(testCentre.getCentreId());

        // add test centre to centre officer
        centreManagerLogin->addTestCentre(testCentre);
        cout << "\nThe test centre is created and recorded for the centre manager" << endl;
    }
    else
        cout << "\nSorry, no test center to be approved" << endl;

}

void manageKitStock() {
    cout << "Manage Test Kit Stock:" << endl;
    if(!centreManagerLogin->getTestCentreCollection().empty()) {
        int iTestKit = 0, availableStock, choice;
        string testKitName;
        cout << "1. Record new stock" << endl;
        cout << "2. Update stock" << endl;
        cout << "Menu of choices: ";
        cin >> choice;
        cout << endl;
        if(choice == 1) {
            if(centreKitStock.getNewStockTestKits() > 0) {
                centreKitStock.showNewStockTestKits();
                cout << "Select test kit: ";
                cin >> iTestKit;
                cout << "Enter stock: ";
                cin >> availableStock;
                // nama kit
                testKitName = centreKitStock.getNewStock()[iTestKit-1].getTestName();
                // buat object
                TestKit testKit(testKitName, generateKitID(), availableStock);
                // set
                centreKitStock.getNewStock()[iTestKit-1].setKitId(testKit.getKitId());
                centreKitStock.getNewStock()[iTestKit-1].setAvailableStock(testKit.getAvailableStock());
                // pushback
                centreManagerLogin->getTestCentre()->addTestKit(testKit);
            }
            else
                cout << "All new test kit stock has been received" << endl;
        }
        else if (choice == 2){
            string kitId;
            int updateStock;
            if(!centreManagerLogin->getTestCentre()->getTestKitCollection().empty()) {
                centreManagerLogin->getTestCentre()->showAllTestKit();
                cout << "\nEnter kit ID: ";
                cin >> kitId;

                while(centreManagerLogin->getTestCentre()->findTestKit(kitId) == nullptr) {
                    cout << "\nInvalid kit ID! Try another" << endl;
                    cout << "\nEnter kit ID: ";
                    cin >> kitId;
                }

                TestKit *findTestKit = centreManagerLogin->getTestCentre()->findTestKit(kitId);

                cout << "Update stock: ";
                cin >> updateStock;

                findTestKit->setAvailableStock(updateStock);
                string tempName = findTestKit->getTestName();
                cout << "\nThe stock of " << tempName << " is updated to " << findTestKit->getAvailableStock() << endl;
            }
            else
                cout << "You haven't recorded the stock kit" << endl;
        }
    }
    else
        cout << "\nYou haven't recorded the test centre" << endl;
}

void registerTestCentreManager(char &tempPosition) {
    CentreOfficer *centreOfficer = NULL;
    string username, password, name, position;
    cout << "Enter username: ";
    cin >> username;
    if(tempPosition == 'A') {
        while(CTISSystem.findUsernameCentreOfficer(username)) {
            cout << "That admin username is taken. Try another." << endl;
            cout << "Enter new username ";
            cin >> username;
        }
    }
    else if(tempPosition == 'T') {
        while(CTISSystem.findUsernameTester(username)) {
            cout << "That tester username is taken. Try another." << endl;
            cout << "Enter new username ";
            cin >> username;
        }
    }
    cout << "Enter password: ";
    cin >> password;
    cout << "Enter name: ";
    getline(cin >> ws, name);
    if(tempPosition == 'A') {
        position = "Admin";
        centreOfficer = new CentreOfficer(username, password, name, position);
        CTISSystem.addCentreOfficer(*centreOfficer);
    }
    else if(tempPosition == 'T') {
        position = "Tester";
        centreOfficer = new CentreOfficer(username, password, name, position);
        CTISSystem.addTester(*centreOfficer);
    }
    delete centreOfficer;
}





/*
Kalo alamat vector dia nunjuk ke index 0
 lebih baik alamat nunjuk ke object address
 *
 * */