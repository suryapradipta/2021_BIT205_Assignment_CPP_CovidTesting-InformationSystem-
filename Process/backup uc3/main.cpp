#include <iostream>
#include "CTIS.h"
#include <vector>

using namespace std;

char mainMenu();
void adminLogin();
char adminLoginMenu();
void registerTestCentreManager(char &position);
void registerTestCentre();

void manageKitStock();

CTIS CTISSystem;
CentreOfficer *centreOfficerLogin;
int iCentreName;
TestCentre testCentre;

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
                adminLogin();
                break;

            case 'e':
            case 'E':
                cout << "\nThank you" << endl;
                break;


            case '8':
                CTISSystem.showAllCentreOfficers();
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
    cout << "2. Test centre manager login" << endl;
    cout << "3. Tester login" << endl;
    cout << "4. Patient login" << endl;

    cout << "\n8. All Centre Manager" << endl;
    cout << "Press (E/e) to exit" << endl;
    cout << "Menu of choices: ";
    cin >> option;
    cout << endl;
    return option;
}

void adminLogin() {
    cout << "Use your Test Centre Manager account" << endl;
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    centreOfficerLogin = CTISSystem.adminLoginValidation(username, password);
    if(centreOfficerLogin == NULL)
        cout << "\nCan't find your Test Centre Manager account" << endl;
    else {
        cout << "\nWelcome, " << centreOfficerLogin->getName() << endl;
        char option;
        char tempPosition;
        do {
            option = adminLoginMenu();
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
                case '7':
                    testCentre.showAllTestKit();
                    break;
                case '8':
                    CTISSystem.showAllTesters();
                    break;
                case '9':
                    centreOfficerLogin->showAllTestCentre();
                    break;
                case 'e':
                case 'E':
                    cout << "\nBack to main menu..." << endl;
                    break;
                default:
                    cout << "Invalid choice! Try again" << endl;

            }
        }while (option != 'E' && option != 'e');
    }
}

char adminLoginMenu() {
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



void registerTestCentre()
{
    cout << "Register test centre:" << endl;

    if(CTISSystem.getNumOfApprovedTestCentres() > 0 && centreOfficerLogin->getTestCentreCollection().empty()) { // <1

        CTISSystem.showApprovedTestCentres();
        cout << "Select centre name: ";
        cin >> iCentreName;

        // get centrename
        string tempCentreName = CTISSystem.getTestCentre()[iCentreName - 1].getCentreName();
        // create test centre
        TestCentre testCentre(generateCentreID(), tempCentreName);
        // set test centre in CTIS
        CTISSystem.getTestCentre()[iCentreName - 1].setCentreId(testCentre.getCentreId());

        // add test centre to centre officer
        centreOfficerLogin->addTestCentre(testCentre);
        cout << "\nThe test centre is created and recorded for the centre manager" << endl;
    }
    else
        cout << "\nSorry, no test center to be approved" << endl;

}

void manageKitStock() {
    // debug untuk menampilkan new stock
    testCentre.allNewStock();


    cout << "Manage Test Kit Stock:" << endl;
    int iTestKit = 0, availableStock;
    string testKitName;
    testCentre.showNewStockTestKits();
    if(testCentre.getNewStockTestKits() >= 0) {
        cout << "Select test kit: ";
        cin >> iTestKit;
        cout << "Enter stock: ";
        cin >> availableStock;
    }
    else {
        cout << "Update stock: ";
        cin >> availableStock;
    }

    testKitName = testCentre.getNewStock()[iTestKit-1].getTestName();

    TestKit testKit(testKitName, generateKitID(), availableStock);

    testCentre.getNewStock()[iTestKit-1].setKitId(testKit.getKitId());
    testCentre.getNewStock()[iTestKit-1].setAvailableStock(testKit.getAvailableStock());

    testCentre.addTestKit(testKit);




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