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
void updateTestResult();
void patientLoginMenu();
char patientMenu();



CTIS CTISSystem;
int iCentreName;
CentreOfficer *centreManagerLogin;








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
                tempPosition = 'C';
                cout << "Create your Test Centre Manager account\n" << endl;
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

            case '7':
                CTISSystem.showAllPatients();
                break;
            case '8':
                CTISSystem.showAllCentreOfficers();
                break;

            case 'e':
            case 'E':
                cout << "Thank you" << endl;
                break;
            default:
                cout << "Invalid choice! Try again" << endl;
        }
    }while (option != 'E' && option != 'e');
    return 0;
}

char mainMenu() {
    char option = 0;
    cout << "\nCovid Testing Information System (CTIS) Menu:" << endl;
    cout << "1. Register test centre manager" << endl;
    cout << "2. Test centre manager login" << endl;
    cout << "3. Tester login" << endl;
    cout << "4. Patient login" << endl;
    cout << "\n7. Show all Patient "<< endl;
    cout << "8. All Centre Manager" << endl;
    cout << "Press (E/e) to exit" << endl;
    cout << "Menu of choices: ";
    cin >> option;
    cout << endl;
    return option;
}


void patientLoginMenu() {
    cout << "Use your Patient account" << endl;
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    Patient *patientLogin = CTISSystem.patientLoginValidation(username,password);
    if(patientLogin == NULL)
        cout << "\nCan't find your Patient account" << endl;
    else {
        cout << "\nWelcome, " << patientLogin->getName() << endl;
        char option;
        do {
            option = patientMenu();
            switch (option) {
                case '1':
                    cout << "Test history:" << endl;
                    patientLogin->viewTestHistory();
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

char patientMenu() {
    char choice = 0;
    cout << "\nPatient Menu:" << endl;
    cout << "1. View test history" << endl;
    cout << "Press (E/e) to back to main menu" << endl;
    cout << "Menu of choices: " << flush;
    cin >> choice;
    cout << endl;
    return choice;
}








CentreOfficer *testerLogin;
Patient *patientTest;
TestCentre *centreCovidTest;
TestKit *testKitCovidTest;
CentreOfficer *centreOfficerTest;
TestKit *testKitCovidTest1;
void recordNewTest() {
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
    string patientType = tempPatient.getPatientTypeObj()[iPatientType - 1];
    Patient newPatient(username, password, name, patientType, symptoms);

    CovidTest newCovidTest;
    newCovidTest.setTestDate(testDate());
    newCovidTest.setTestId(generateTestID());
    newCovidTest.setStatus("pending");

    // jika tidak ada di vector tambahkan
    if(CTISSystem.findPatientByUsername(username)) {
        CTISSystem.addPatient(newPatient);
    }
    // jika ada ambil object di vector
    patientTest = CTISSystem.getPatientByUsername(username);

    cout << endl;
    CTISSystem.showAllTestCentre();
    cout << "Select centre name: ";
    cin >> iCentreName;

    centreCovidTest = &CTISSystem.getTestCentre()[iCentreName-1];
    // hasil : dapet test centre yang approved dan sudah dapet ID
    if(centreCovidTest->getTestKitCollection().empty())
        cout << "\nCentre Manager haven't recorded the test kit" << endl;
    else {
        string kitID;
        centreCovidTest->showAvailableTestKit();
        cout << "\nEnter kid ID: ";
        cin >> kitID;
        while(!centreCovidTest->kitIDValidation(kitID)) {
            cout << "\nInvalid kit ID! Try again" << endl;
            cout << "Enter kid ID: ";
            cin >> kitID;
        }
        // testkit covid test berubah karena loopiing dari centre officer
        centreOfficerTest = CTISSystem.findCentreOfficer(centreCovidTest->getCentreName());
        testKitCovidTest = CTISSystem.findTestKitByCentreOfficer(*centreOfficerTest, kitID);
        testKitCovidTest1 = CTISSystem.findTestKit(kitID);
    }
    // cari centre officer


    // jika belum ngambil test tambahkan covid test
    if(patientTest->getCovidTestCollection().empty()) {
        patientTest->addCovidTest(newCovidTest);
        testerLogin->addCovidTest(newCovidTest);
        testKitCovidTest->addCovidTest(newCovidTest);
        testKitCovidTest->setAvailableStock(testKitCovidTest->getAvailableStock()-1);
        testKitCovidTest1->setAvailableStock(testKitCovidTest1->getAvailableStock()-1);
        cout << "\nRegister and record success! A new test is created for " << patientTest->getName() << endl;
    }
    else {
        // jika sudah set date kemudian tambahkan covid test
        cout << "\nPatient has taken test"<< endl;
        cout << "Only patient types and symptoms are updated" << endl;
        patientTest->setPatientType(tempPatient.getPatientTypeObj()[iPatientType - 1]);
        patientTest->setSymptoms(symptoms);

        patientTest->addCovidTest(newCovidTest);
        testerLogin->addCovidTest(newCovidTest);
        testKitCovidTest->addCovidTest(newCovidTest);
        testKitCovidTest->setAvailableStock(testKitCovidTest->getAvailableStock()-1);
        testKitCovidTest1->setAvailableStock(testKitCovidTest1->getAvailableStock()-1);
        cout << "\nRecord success! A new test is created for " << patientTest->getName() << endl;
    }
}


void updateTestResult() {
    string testID;
    string result;
    if(CTISSystem.numberOfPending()) {
        CTISSystem.showAllCovidTestID(); // setelah di set baru bisa di cek
        cout << "Enter test ID: ";
        cin >> testID;
        while(!CTISSystem.covidTestIDValidation(testID)) {
            cout << "\nInvalid test ID! Select another" << endl;
            cout << "Enter test ID: ";
            cin >> testID;
        }
        // show details test id
        cout << "\nCovid test details:";
        cout << *CTISSystem.findCovidTestTester(testID) << endl;
        // show patient information

        Patient *patientInfo;
        patientInfo = CTISSystem.getPatientCovidTest(testID);
        cout << "\nPatient details:" << endl;
        cout << "Patient name: " << patientInfo->getName() << endl;
        cout << "Patient type: " << patientInfo->getPatientType() << endl;
        cout << "Patient symptoms: " << patientInfo->getSymptoms() << endl;
        cout << "\nTest Centre details:" << endl;
        cout << CTISSystem.findTestCentreCovidTest(testID)->getCentreName() << endl;
        cout << "\nTest Kit details:" << endl;
        cout << CTISSystem.findTestKitCovidTest(testID)->getTestName() << endl;

        cout << "\nResult test:" << endl;
        cout << "1. Positive" << endl;
        cout << "2. Negative" << endl;
        cout << "Select result: ";
        cin >> result;
        if(result == "1")
            result = "Positive";
        else if(result == "2")
            result = "Negative";

        CTISSystem.findCovidTestPatient(testID)->setStatus("completed");
        CTISSystem.findCovidTestPatient(testID)->setResult(result);
        CTISSystem.findCovidTestPatient(testID)->setResultDate(testDate());

        CTISSystem.findCovidTestTester(testID)->setStatus("completed");
        CTISSystem.findCovidTestTester(testID)->setResult(result);
        CTISSystem.findCovidTestTester(testID)->setResultDate(testDate());

        CTISSystem.findCovidTestTestKit(testID)->setStatus("completed");
        CTISSystem.findCovidTestTestKit(testID)->setResult(result);
        CTISSystem.findCovidTestTestKit(testID)->setResultDate(testDate());
        cout << "\nThe test result is updated" << endl;
    }
    else
        cout << "No test results to update" << endl;

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
                case '2':
                    updateTestResult();
                    break;
                case'3':
                    cout << "Test history report:" << endl;
                    testerLogin->viewTestHistory();
                    break;

                case '5':
                    // testkit
                    testKitCovidTest->showAllCovidTest();
                    break;
                case '6':
                    //tester
                    CTISSystem.showALlCovidTest();
                    break;

                case '7':
                    // tester
                    testerLogin->showAllTesterCovidTest();
                    break;
                case '8':
                    // patient
                    patientTest->showAllPatientCovidTest();
                    break;
                case '9':
                    CTISSystem.showAllPatients();
                    break;

                case 'e':
                case 'E':
                    cout << "Back to main menu..." << endl;
                    break;
                case 'g':
                    CTISSystem.showAllPatientCovidTest();
                    break;
                case 'h':
                    CTISSystem.showAllCovidTestTester();
                    break;

                case 'i':
                    CTISSystem.showALlCovidTestTestKit();
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
    cout << "2. Updated test result" << endl;
    cout << "3. View test history report" << endl;

    // debug
    cout << "\n5. TestKit covid test" << endl;
    cout << "6. Tester CTIS covid test" << endl;
    cout << "7. Tester covid test" << endl;
    cout << "8. Patient covid test" << endl;
    cout << "9. all patient" << endl;
    cout << "g. all patient covid test" << endl;
    cout << "h. all tester covid test" << endl;
    cout << "i. all testKit covid test" << endl;
    cout << "Press (E/e) to back to main menu" << endl;
    cout << "Menu of choices: " << flush;
    cin >> choice;
    cout << endl;
    return choice;
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
                case '4':
                    cout << "Test history report:" << endl;
                    centreManagerLogin->viewTestHistory();
                    break;



                case '7':
                    centreManagerLogin->getTestCentre()->showAllTestKit();
                    break;


                case 'e':
                case 'E':
                    cout << "Back to main menu..." << endl;
                    break;

                case'q':
                    CTISSystem.showAllCentreOfficers();
                    break;
                case 'w':
                    centreManagerLogin->showAllTestCentre();
                    break;
                case 'f':
                    CTISSystem.showAllTestCentreInAllAdmin();
                    break;
                case 'g':
                    CTISSystem.showAllTesters();
                    break;
                case 'h':
                    CTISSystem.showAllTestKit();
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
    cout << "4. View test history report" << endl;


    cout << "\n7. all TEst Kit" << endl;
    cout << "w. All test centre registered in admin" << endl;
    cout << "q. CTIS all centre officer" << endl;
    cout << "f. showAllTestCentreInAllAdmin" << endl;
    cout << "g. All testers" << endl;
    cout << "h. all kit stock" << endl;
    cout << "Press (E/e) to back to main menu" << endl;
    cout << "Menu of choices: " << flush;
    cin >> choice;
    cout << endl;
    return choice;
}

void viewTestHistoryReport() {

}


TestCentre centreKitStock;
void manageKitStock() {
    cout << "Manage Test Kit Stock:" << endl;
    // jika admin login sudah daftar test centre baru bisa
    if(!centreManagerLogin->getTestCentreCollection().empty()) {
        int iTestKit = 0, availableStock, choice;
        string testKitName;
        cout << "1. Record new stock" << endl;
        cout << "2. Update stock" << endl;
        cout << "Menu of choices: ";
        cin >> choice;
        if(choice == 1) {
            if(centreKitStock.getNewStockTestKits() > 0) {
                cout << endl;
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
                string centreID = centreManagerLogin->getTestCentre()->getCentreId();
                CTISSystem.findTestCentre(centreID)->addTestKit(testKit);
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
                    cout << "Enter kit ID: ";
                    cin >> kitId;
                }

                TestKit *findTestKit = centreManagerLogin->getTestCentre()->findTestKit(kitId);

                cout << "Update stock: ";
                cin >> updateStock;

                findTestKit->setAvailableStock(updateStock);
                CTISSystem.findTestKit(kitId)->setAvailableStock(updateStock);
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


/**
 * registerTestCentre support method used to
 * allow Test Centre Managers / Admins register test centre
 * and recorded the Test Centre to centre managers.
 */
void registerTestCentre() {
    cout << "Register test centre:" << endl;
    // Show approved Test Centres and Centre Managers has not recorded Test Centre.
    if(CTISSystem.getNumOfApprovedTestCentres() > 0 && centreManagerLogin->getTestCentreCollection().empty()) {
        // Show Test Centres
        CTISSystem.showApprovedTestCentres();
        cout << "Select centre name: ";
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
        cout << "\nSorry, no test center to be approved" << endl;

}

/**
 * registerTestCentreManager support method used to
 * allow register Test Centre Manager to CTIS System.
 */

/**
 *
 * @param tempPosition
 */
void registerTestCentreManager(char &tempPosition) {
    // Centre officer dynamic object
    CentreOfficer *centreOfficer = nullptr;
    string username, password, name, position;
    cout << "Enter username: ";
    cin >> username;
    // Username cannot be the same
    if(tempPosition == 'C') {
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
    if(tempPosition == 'C') {
        position = "Centre manager";
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