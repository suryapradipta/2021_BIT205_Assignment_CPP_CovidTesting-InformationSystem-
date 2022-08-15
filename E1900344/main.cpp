/**
 * The CTIS Console Program implements
 * the Covid Testing Information System application which consists of various menus:
 * Add new user, manage kit stock, manage test records, and view test history.
 * Student ID: E1900344
 * Date: 16 December 2021
 * C++ version: C++14
 * IDE : CLion
 * The program works well without errors or interruptions.
 */

#include <iostream>

#include "CTIS.h"

#include <vector>

using namespace std;

// Function prototype
char mainMenu();
// Menu & login for Admin
void adminLoginMenu();
char adminMenu();
void registerTestCentreManager(char &position);
void registerTestCentre();
void manageKitStock();

// Menu & login for Tester
char testerMenu();
void testerLoginMenu();
void recordNewTest();
void updateTestResult();

// Menu & login for Patient
void patientLoginMenu();
char patientMenu();

// Supporting method
string generateCentreID();
string generateKitID();
string generateTestID();
string date();

// Global variable
int iCentreName;
int cID = 0;
int kID = 0;
int tID = 0;

// Global object
CTIS CTISSystem;
CentreOfficer *testerLogin;
CentreOfficer *centreManagerLogin;
TestCentre centreKitStock;


/**
 * main method used to
 * provide various menu for User:
 * Register Test Centre Manager,
 * Test Centre Manager Login,
 * Tester Login,
 * and Patient Login.
 */
int main() {
    char option;
    char tempPosition;
    do {
        option = mainMenu();
        switch (option) {
            case '1':
                tempPosition = 'C';
                cout << "\t\tCreate your Test Centre Manager account\n" << endl;
                registerTestCentreManager(tempPosition);
                cout << "\nRegister success! A Test Centre Manager account is created." << endl;
                break;
            case '2':
                adminLoginMenu();
                break;
            case '3':
                testerLoginMenu();
                break;
            case '4':
                patientLoginMenu();
                break;
            case 'e':
            case 'E':
                cout << "\t\tApplication closed" << endl;
                break;
            default:
                cout << "Invalid choice! Try again" << endl;
        }
    }while (option != 'E' && option != 'e');
    return 0;
}

/**
 * mainMenu support method used to
 * show various menu for User:
 * Register Test Centre Manager,
 * Test Centre Manager Login,
 * Tester Login,
 * and Patient Login.
 */
char mainMenu() {
    char option = 0;
    cout << "\n\n\t\tCovid Testing Information System (CTIS) Menu\n" << endl;
    cout << "1. Register test centre manager" << endl;
    cout << "2. Test centre manager login" << endl;
    cout << "3. Tester login" << endl;
    cout << "4. Patient login" << endl;
    cout << "Press (E/e) to exit" << endl;
    cout << "\nMenu of choices: ";
    cin >> option;
    cout << endl;
    return option;
}

/**
 * patientLoginMenu support method used to
 * provide menu for Patient.
 */
void patientLoginMenu() {
    cout << "\t\tUse your Patient account\n" << endl;
    string usrname, passw;
    cout << "Enter username     : ";
    cin >> usrname;
    cout << "Enter password     : ";
    cin >> passw;
    // Find Patient object based on username and password
    Patient *patientLogin = CTISSystem.patientLoginValidation(usrname,passw);
    if(patientLogin == nullptr)
        cout << "\nCan't find your Patient account" << endl;
    // Patient found
    else {
        cout << "\nWelcome, " << patientLogin->getName() << endl;
        char option;
        do {
            option = patientMenu();
            switch (option) {
                case '1':
                    cout << "\t\tTest history" << endl;
                    patientLogin->viewTestHistory();
                    break;
                case 'e':
                case 'E':
                    cout << "Back to main menu" << endl;
                    break;
                default:
                    cout << "Invalid choice! Try again" << endl;
            }
        }while (option != 'E' && option != 'e');
    }
}

/**
 * patientMenu support method used to
 * show menu for Patient.
 * @return a char of selected menu.
 */
char patientMenu() {
    char choice = 0;
    cout << "\n\t\tPatient Menu\n" << endl;
    cout << "1. View test history" << endl;
    cout << "Press (E/e) to log out" << endl;
    cout << "\nMenu of choices: " << flush;
    cin >> choice;
    cout << endl;
    return choice;
}

/**
 * recordNewTest support method used to
 * allow Tester administer test for Patient
 */
void recordNewTest() {
    Patient tempPatient;
    cout << "\t\tRegister Patient\n" << endl;
    int iPatientType;
    string usrname, passw, name, symptoms;
    // Input patient information
    cout << "Enter username     : ";
    cin >> usrname;
    cout << "Enter password     : ";
    cin >> passw;
    cout << "Enter name         : ";
    getline(cin >> ws, name);
    cout << "\n\t\tPatient type\n" << endl;
    tempPatient.showAllPatientType();
    cout << "\nSelect patient type: ";
    cin >> iPatientType;
    cout << "Enter symptoms     : ";
    getline(cin >> ws, symptoms);

    // Get patient type based on selected index
    string patientType = tempPatient.getSelectedPatientType()[iPatientType - 1];
    // Create Patient object
    Patient newPatient(usrname, passw, name, patientType, symptoms);

    // Create CovidTest object
    CovidTest newCovidTest;
    newCovidTest.setTestDate(date());
    newCovidTest.setTestId(generateTestID());
    newCovidTest.setStatus("pending");

    // Add if Patient object is not in vector
    if(CTISSystem.findPatient(usrname)) {
        CTISSystem.addPatient(newPatient);
    }

    // Get Patient object in vector
    Patient *patientTest;
    patientTest = CTISSystem.getPatient(usrname);


    cout << "\n\t\tTest Centre\n" << endl;
    CTISSystem.showAllTestCentres();
    cout << "Select centre name: ";
    cin >> iCentreName;

    // Get Test Centre object based on the selected index
    TestCentre *centreCovidTest;
    centreCovidTest = &CTISSystem.getTestCentre()[iCentreName-1];

    TestKit *testKitCovidTest;
    TestKit *testKitCovidTest1;
    CentreOfficer *centreManagerTest;

    // Centre Manager must record test kit first
    if(centreCovidTest->getTestKits().empty())
        cout << "\nCentre Manager haven't recorded the test kit" << endl;
    else {
        string kitID;
        cout << "\n\t\tAvailable Test Kit" << endl;
        centreCovidTest->showAvailableTestKit();
        cout << "\nEnter kid ID: ";
        cin >> kitID;
        while(!centreCovidTest->kitIDValidation(kitID)) {
            cout << "\nInvalid kit ID! Try again" << endl;
            cout << "Enter kid ID: ";
            cin >> kitID;
        }
        // Find Test Kit object
        centreManagerTest = CTISSystem.getCentreManager(centreCovidTest->getCentreName());
        testKitCovidTest = CTIS::getTestKitByManager(*centreManagerTest, kitID);
        testKitCovidTest1 = CTISSystem.getTestKit(kitID);
    }

    // Patient has not taken test
    if(patientTest->getCovidTests().empty()) {
        patientTest->addCovidTest(newCovidTest);
        testerLogin->addCovidTest(newCovidTest);
        testKitCovidTest->addCovidTest(newCovidTest);
        // Set available stock of Test Kit
        testKitCovidTest->setAvailableStock(testKitCovidTest->getAvailableStock()-1);
        testKitCovidTest1->setAvailableStock(testKitCovidTest1->getAvailableStock()-1);
        cout << "\nRegister and record success! A new test is created for " << patientTest->getName() << endl;
    }
    else {
        cout << "\nPatient has taken test"<< endl;
        cout << "Only patient types and symptoms are updated" << endl;
        patientTest->setPatientType(tempPatient.getSelectedPatientType()[iPatientType - 1]);
        patientTest->setSymptoms(symptoms);

        patientTest->addCovidTest(newCovidTest);
        testerLogin->addCovidTest(newCovidTest);
        testKitCovidTest->addCovidTest(newCovidTest);

        // Set available stock of Test Kit
        testKitCovidTest->setAvailableStock(testKitCovidTest->getAvailableStock()-1);
        testKitCovidTest1->setAvailableStock(testKitCovidTest1->getAvailableStock()-1);
        cout << "\nRecord success! A new test is created for " << patientTest->getName() << endl;
    }
}

/**
 * updateTestResult support method used to
 * allow Tester to update information of the test.
 */
void updateTestResult() {
    string testID;
    string result;
    if(CTISSystem.getNumOfPendingCovidTest()) {
        CTISSystem.showAllCovidTestID();
        cout << "Enter test ID: ";
        cin >> testID;
        while(!CTISSystem.covidTestIDValidation(testID)) {
            cout << "\nInvalid test ID! Select another" << endl;
            cout << "Enter test ID: ";
            cin >> testID;
        }
        // Show Test details
        cout << "\n\t\tCovid test details\n";
        cout << *CTISSystem.getCovidTestOfTester(testID) << endl;

        // Show additional details
        Patient *patientInfo;
        patientInfo = CTISSystem.getPatientByCovidTest(testID);
        cout << "\n\t\tPatient details\n" << endl;
        cout << "Patient name: " << patientInfo->getName() << endl;
        cout << "Patient type: " << patientInfo->getPatientType() << endl;
        cout << "Patient symptoms: " << patientInfo->getSymptoms() << endl;
        cout << "\n\t\tTest Centre details\n" << endl;
        cout << CTISSystem.getTestCentreByCovidTest(testID)->getCentreName() << endl;
        cout << "\n\t\tTest Kit details\n" << endl;
        cout << CTISSystem.getTestKitByCovidTest(testID)->getTestName() << endl;

        cout << "\n\t\tResult test\n" << endl;
        cout << "1. Positive" << endl;
        cout << "2. Negative" << endl;
        cout << "\nSelect result: ";
        cin >> result;
        if(result == "1")
            result = "Positive";
        else if(result == "2")
            result = "Negative";

        // Update information
        CTISSystem.getPatientCovidTest(testID)->setStatus("completed");
        CTISSystem.getPatientCovidTest(testID)->setResult(result);
        CTISSystem.getPatientCovidTest(testID)->setResultDate(date());

        CTISSystem.getCovidTestOfTester(testID)->setStatus("completed");
        CTISSystem.getCovidTestOfTester(testID)->setResult(result);
        CTISSystem.getCovidTestOfTester(testID)->setResultDate(date());

        CTISSystem.getCovidTet(testID)->setStatus("completed");
        CTISSystem.getCovidTet(testID)->setResult(result);
        CTISSystem.getCovidTet(testID)->setResultDate(date());
        cout << "\nThe test result is updated" << endl;
    }
    else
        cout << "No test results to update" << endl;

}

/**
 * testerLoginMenu support method used to
 * provide various menu for tester.
 */
void testerLoginMenu() {
    cout << "\t\tUse your Tester account\n" << endl;
    string usrname, passw;
    cout << "Enter username: ";
    cin >> usrname;
    cout << "Enter password: ";
    cin >> passw;
    // Find Tester object based on username and password
    testerLogin = CTISSystem.testerLoginValidation(usrname, passw);
    if(testerLogin == nullptr)
        cout << "\nCan't find your Tester account" << endl;
    // Tester found
    else {
        cout << "\nWelcome, " << testerLogin->getName() << endl;
        char choice;
        do {
            choice = testerMenu();
            switch (choice) {
                case '1':
                    recordNewTest();
                    break;
                case '2':
                    updateTestResult();
                    break;
                case'3':
                    cout << "\t\tTest history report" << endl;
                    testerLogin->viewTestHistory();
                    break;
                case 'e':
                case 'E':
                    cout << "Back to main menu" << endl;
                    break;
                default:
                    cout << "Invalid choice! Try again" << endl;
            }
        }while (choice != 'E' && choice != 'e');
    }
}

/**
 * testerMenu support method used to
 * show various menu for tester.
 * @return a char of selected menu.
 */
char testerMenu() {
    char choice = 0;
    cout << "\n\t\tTester Menu\n" << endl;
    cout << "1. Record new test" << endl;
    cout << "2. Update test result" << endl;
    cout << "3. View test history report" << endl;
    cout << "Press (E/e) to log out" << endl;
    cout << "\nMenu of choices: " << flush;
    cin >> choice;
    cout << endl;
    return choice;
}

/**
 * adminLoginMenu support method used to
 * provide various menu for admin.
 */
void adminLoginMenu() {
    cout << "\t\tUse your Test Centre Manager account\n" << endl;
    string usrname, passw;
    cout << "Enter username     : ";
    cin >> usrname;
    cout << "Enter password     : ";
    cin >> passw;
    // Find Centre Manager object based on username and password
    centreManagerLogin = CTISSystem.adminLoginValidation(usrname, passw);
    if(centreManagerLogin == nullptr)
        cout << "\nCan't find your Test Centre Manager account" << endl;
    // Centre Manager found
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
                    cout << "\t\tCreate your Tester account\n" << endl;
                    registerTestCentreManager(tempPosition);
                    cout << "\nRegister success! A Tester account is created." << endl;
                    break;
                case '3':
                    manageKitStock();
                    break;
                case '4':
                    cout << "\t\tTest history report" << endl;
                    centreManagerLogin->viewTestHistory();
                    break;
                case 'e':
                case 'E':
                    cout << "Back to main menu" << endl;
                    break;
                default:
                    cout << "Invalid choice! Try again" << endl;
            }
        }while (option != 'E' && option != 'e');
    }
}

/**
 * adminLoginMenu support method used to
 * show various menu for admin.
 * @return a char of selected menu.
 */
char adminMenu() {
    char choice = 0;
    cout << "\n\t\tAdmin Menu\n" << endl;
    cout << "1. Register test centre" << endl;
    cout << "2. Register tester" << endl;
    cout << "3. Manage test kit stock" << endl;
    cout << "4. View test history report" << endl;
    cout << "Press (E/e) to log out" << endl;
    cout << "\nMenu of choices: " << flush;
    cin >> choice;
    cout << endl;
    return choice;
}

/**
 * manageKitStock support method used to
 * allow manage kit stock of test kits.
 */
void manageKitStock() {

    cout << "\t\tManage Test Kit Stock\n" << endl;
    // Test Center must be saved to Center Manager first
    if(!centreManagerLogin->getTestCentres().empty()) {
        int choice;
        cout << "1. Record new stock" << endl;
        cout << "2. Update stock" << endl;
        cout << "\nMenu of choices: ";
        cin >> choice;
        if(choice == 1) {
            int iTestKit = 0, stock;
            string testKit_name;
            // Show new stock of Test Kits
            if(centreKitStock.getNumOfNewStocks() > 0) {
                cout << endl;
                centreKitStock.showNewStocks();
                cout << "\nSelect test kit      : ";
                cin >> iTestKit;
                cout << "Enter stock          : ";
                cin >> stock;
                // Get test kit name by selected user
                testKit_name = centreKitStock.getNewStock()[iTestKit-1].getTestName();
                // Create test kit object
                TestKit testKit(testKit_name, generateKitID(), stock);
                // Set new stock status to ID
                centreKitStock.getNewStock()[iTestKit-1].setKitId(testKit.getKitId());
                centreKitStock.getNewStock()[iTestKit-1].setAvailableStock(testKit.getAvailableStock());
                // Record to vector TestKit in CTIS and TestCentre
                centreManagerLogin->getTestCentre()->addTestKit(testKit);
                string centreID = centreManagerLogin->getTestCentre()->getCentreId();
                CTISSystem.getTestCentreByID(centreID)->addTestKit(testKit);
                cout << "\nThe new stock received and recorded to the Test Centre" << endl;
            }
            else
                cout << "\nAll new test kit stock has been received" << endl;
        }
        else if (choice == 2){
            string kit_id;
            int updateStock;
            // Centre Manager must record stock Test Kit first
            if(!centreManagerLogin->getTestCentre()->getTestKits().empty()) {
                cout << "\n\t\tUpdate Kit Stock" << endl;
                // Show all Test Kit
                centreManagerLogin->getTestCentre()->showAllTestKit();
                cout << "\nEnter kit ID: ";
                cin >> kit_id;

                // Validation kit ID entered based on vector in Test Centre
                while(centreManagerLogin->getTestCentre()->findTestKit(kit_id) == nullptr) {
                    cout << "\nInvalid kit ID! Try another" << endl;
                    cout << "Enter kit ID: ";
                    cin >> kit_id;
                }
                // Get TestKit object based on kit ID
                TestKit *getTestKit = centreManagerLogin->getTestCentre()->findTestKit(kit_id);

                cout << "Update stock: ";
                cin >> updateStock;

                // Update stock of TestKit object in CTIS and TestCentre vector
                getTestKit->setAvailableStock(updateStock);
                CTISSystem.getTestKit(kit_id)->setAvailableStock(updateStock);
                string temp_testName = getTestKit->getTestName();
                cout << "\nThe stock of " << temp_testName << " is updated to " << getTestKit->getAvailableStock() << endl;
            }
            else
                cout << "\nYou haven't recorded the stock kit" << endl;
        }
    }
    else
        cout << "\nYou haven't recorded the test centre" << endl;
}

/**
 * registerTestCentre support method used to
 * allow Test Centre Managers / Admins register test centre
 * and recorded the Test Centre to centre managers.
 */
void registerTestCentre() {
    cout << "\t\tRegister test centre\n" << endl;
    // Show approved Test Centres and Centre Managers has not recorded Test Centre.
    if(centreManagerLogin->getTestCentres().empty()) {
        if(CTISSystem.getNumOfApprovedTestCentres() > 0) {
            // Show Test Centres
            CTISSystem.showApprovedTestCentres();
            cout << "\nSelect centre name: ";
            cin >> iCentreName;
            // Validation select centre name
            while(iCentreName >=3) {
                cout << "\nInvalid centre name! select another" << endl;
                cout << "Select centre name: ";
                cin >> iCentreName;
            }
            // Find centre name by index
            string centreName = CTISSystem.getTestCentre()[iCentreName-1].getCentreName();
            // Create object Test Centre
            TestCentre testCentre(generateCentreID(), centreName);
            // Set Test Center approved status in CTIS to ID
            CTISSystem.getTestCentre()[iCentreName-1].setCentreId(testCentre.getCentreId());
            // Record Test Centre to Centre Manager based on Centre Manager account login
            centreManagerLogin->addTestCentre(testCentre);
            cout << "\nThe test centre is created and recorded for the centre manager" << endl;
        }
        else
            cout << "Sorry, no test center to be approved" << endl;
    }
    else
        cout << "Admin is only responsible for one test centre!" << endl;
}

/**
 * registerTestCentreManager support method used to
 * allow register Test Centre Manager to CTIS System.
 * @param tempPosition reference to differentiate between Centre Manager or Tester.
 */
void registerTestCentreManager(char &tempPosition) {
    // Centre officer dynamic object
    CentreOfficer *centreOfficer = nullptr;
    string usrname, passw, name, post;
    cout << "Enter username     : ";
    cin >> usrname;
    // Admin username cannot be the same
    if(tempPosition == 'C') {
        while(CTISSystem.findCentreManager(usrname)) {
            cout << "\nThat admin username is taken. Try another." << endl;
            // input new username
            cout << "Enter new username : ";
            cin >> usrname;
        }
    }
    // Tester username cannot be the same
    else if(tempPosition == 'T') {
        while(CTISSystem.findTester(usrname)) {
            cout << "\nThat tester username is taken. Try another." << endl;
            // input new username
            cout << "Enter new username : ";
            cin >> usrname;
        }
    }

    cout << "Enter password     : ";
    cin >> passw;

    cout << "Enter name         : ";
    getline(cin >> ws, name);

    if(tempPosition == 'C') {
        // Set position to Centre Manager
        post = "Centre manager";
        // Create object Centre Officer
        centreOfficer = new CentreOfficer(usrname, passw, name, post);
        // Add to the vector
        CTISSystem.addCentreManager(*centreOfficer);
    }
    else if(tempPosition == 'T') {
        // Set position to Tester
        post = "Tester";
        // Create object Centre Officer
        centreOfficer = new CentreOfficer(usrname, passw, name, post);
        // Add to the vector Centre Officer in CTIS
        CTISSystem.addTester(*centreOfficer);
    }
    // Deallocate memory space
    delete centreOfficer;
}

/**
 * Determine the length of centreID.
 * @return a string of centreID with one/two positive int or zero.
 */
string generateCentreID() {
    cID++;
    string centre_id = to_string(cID).length() == 1 ?("C00" + to_string(cID))
            : to_string(cID).length() == 2 ? ("C0" + to_string(cID))
            : to_string(cID);
    return centre_id;
}

/**
 * Determine the length of kitID.
 * @return a string of kitID with one/two positive int or zero.
 */
string generateKitID() {
    kID++;
    string kit_ID = to_string(kID).length() == 1 ?("K00" + to_string(kID))
            : to_string(kID).length() == 2 ? ("K0" + to_string(kID))
            : to_string(kID);
    return kit_ID;
}

/**
 * Determine the length of testID.
 * @return a string of testID with one/two positive int or zero.
 */
string generateTestID() {
    tID++;
    string id = to_string(tID).length() == 1 ?("T00" + to_string(tID))
            : to_string(tID).length() == 2 ? ("T0" + to_string(tID))
            : to_string(kID);
    return id;
}

/**
 * Generate current time using The strftime() function.
 * @return a string of date and time from calendar.
 */
string date() {
    // get time based on current time system
    time_t localTime;
    tm * currTime;
    char dt[100];
    time(&localTime);
    currTime = localtime(&localTime);
    // convert to string
    strftime(dt, 50, "%F %R", currTime);
    return dt;
}
