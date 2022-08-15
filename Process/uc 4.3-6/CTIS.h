//
// Created by Surya Pradipta on 09/12/21.
//

#ifndef ASSIGNMENTCOBA1_CTIS_H
#define ASSIGNMENTCOBA1_CTIS_H

#include <string>
#include <ostream>
#include <vector>

using namespace std;

class User {
private:
    string username;
    string password;
    string name;
public:
    User();
    User(string username, string password, string name);
    virtual ~User();
    string getUsername() const;
    string getPassword() const;
    string getName() const;
    void setUsername(string username);
    void setPassword(string password);
    void setName(string name);
    friend ostream &operator<<(ostream &os, const User &user);
    virtual void viewTestHistory() = 0 ;
};

class CovidTest {
private:
    string testID;
    string testDate;
    string result;
    string resultDate;
    string status;

public:
    CovidTest();
    CovidTest(string testId, string testDate, string result, string resultDate,
              string status);
    virtual ~CovidTest();
    string getTestId() const;
    string getTestDate() const;
    string getResult() const;
    string getResultDate() const;
    string getStatus() const;
    void setTestId(string testId);
    void setTestDate(string testDate);
    void setResult(string result);
    void setResultDate(string resultDate);
    void setStatus(string status);
    friend ostream &operator<<(ostream &os, const CovidTest &test);
};

class TestKit{
private:
    string testName;
    string kitID;
    int availableStock;
    vector<CovidTest> covidTests;

public:
    TestKit();
    TestKit(string testName, string kitID, int availableStock);
    virtual ~TestKit();
    string getTestName() const;
    string getKitId() const;
    int getAvailableStock() const;
    void setTestName(string testName);
    void setKitId(string kitID);
    void setAvailableStock(int availableStock);
    friend ostream &operator<<(ostream &os, const TestKit &kit);

    void addCovidTest(CovidTest &covidTest);
    void showAllCovidTest();
    CovidTest *getCovidTest();
    vector<CovidTest> getCovidTestCollection() const;
};

class TestCentre {
private:
    string centreId;
    string centreName;

    vector<TestKit> newStocks;
    vector<TestKit> testKits;
public:
    TestCentre();
    TestCentre(string centreName);
    TestCentre(string centreId, string centreName);
    virtual ~TestCentre();
    string getCentreId() const;
    string getCentreName() const;
    void setCentreId(string centreId);
    void setCentreName(string centreName);
    friend ostream &operator<<(ostream &os, const TestCentre &centre);


    void addTestKit(TestKit &testKit);
    vector<TestKit> getTestKitCollection() const;
    void showAllTestKit();


    void addNewStock(TestKit &testKit);




    void allNewStock();
    void showNewStockTestKits();
    int getNewStockTestKits();
    TestKit *getTestKit();
    TestKit *getNewStock();
    TestKit *getTestKitByID(string kitID);

    TestKit *findTestKit(string kitID);
    bool kitIDValidation(string kitID);







};





class CentreOfficer : public User{
private:
    string position;
    vector<TestCentre> testCentres;
    vector<CovidTest> testerCovidTest;

public:
    CentreOfficer();
    CentreOfficer(string username, string password, string name, string position);
    virtual ~CentreOfficer();
    string getPosition() const;
    void setPosition(string position);
    friend ostream &operator<<(ostream &os, const CentreOfficer &officer);
    void viewTestHistory() override;

    void addTestCentre(TestCentre testCentre);
    vector<TestCentre> getTestCentreCollection() const;
    void showAllTestCentre();
    TestCentre *getTestCentre();

    void addCovidTest(CovidTest &covidTest);
    void showAllTesterCovidTest();

    vector<CovidTest> getCovidTestCollection() const;
    CovidTest *getCovidTest();

};

class Patient : public User{
private:
    string patientType;
    string symptoms;
    vector<string> patientTypeCollection;
    vector<CovidTest> patientCovidTests;
public:
    Patient();
    Patient(string username, string password, string name, string patientType,
            string symptoms);
    virtual ~Patient();
    string getPatientType() const;
    string getSymptoms() const;
    void setPatientType(string patientType);
    void setSymptoms(string symptoms);
    friend ostream &operator<<(ostream &os, const Patient &patient);
    void viewTestHistory() override;


    void addCovidTest(CovidTest &covidTest);
    void showAllPatientCovidTest();
    CovidTest *getCovidTest();
    vector<CovidTest> getCovidTestCollection() const;


    void addPatientType(string patientType);
    void showAllPatientType();
    string *getPatientTypeObj();
};




class CTIS {
private:
    vector<CentreOfficer> CTISCentreOfficers;
    vector<CentreOfficer> CTISTesters;
    vector<TestCentre> CTISTestCentres;
    vector<Patient> CTISPatients;

public:
    CTIS();
    virtual ~CTIS();

    void addCentreOfficer(CentreOfficer &centreOfficer);
    vector<CentreOfficer> getCentreOfficerCollection() const;
    void showAllCentreOfficers();
    bool findUsernameCentreOfficer(string username);
    CentreOfficer *adminLoginValidation(string username, string password);
    CentreOfficer *getCentreOfficer();

    Patient *patientLoginValidation(string username, string password);

    // DEBUG
    void showAllTestCentreInAllAdmin();
    void showAllTesters();
    void showAllTestKit();

    void showAllPatientCovidTest();
    void showAllCovidTestTester();
    void showALlCovidTestTestKit();





    // tester
    void addTester(CentreOfficer &tester);
    vector<CentreOfficer> getTester() const;
    bool findUsernameTester(string username);



// ==== test centre
    void addTestCentre(TestCentre &testCentre);
    vector<TestCentre> getTestCentreCollection() const;
    TestCentre *getTestCentre();
    void showApprovedTestCentres();
    int getNumOfApprovedTestCentres(); // untuk nge show rumah sakit yang pending
    void showAllTestCentre();
    TestCentre *findTestCentre(string centreID);

    // patient
    void addPatient(Patient &patient);
    Patient *getPatient();
    vector<Patient> getPatientCollection() const;
    void showAllPatients();
    void showAllPatientName();
    int getPatient(string username);
    bool findPatientByUsername(string username);
    Patient *getPatientByUsername(string username);



    // tester
    CentreOfficer *testerLoginValidation(string username, string password);

    void showALlCovidTest();
    void showAllCovidTestID();
    Patient *getCovidTestByID(string testID);


    CovidTest *findCovidTestTester(string testID);
    Patient *getPatientCovidTest(string testID);
    TestCentre *findTestCentreCovidTest(string testID);
    TestKit *findTestKitCovidTest(string testID);

    CovidTest *findCovidTestPatient(string testID);
    CovidTest *findCovidTestTestKit(string testID);

    bool covidTestIDValidation(string testID);

    TestKit *findTestKit(string kitID);
    bool numberOfPending();






};

#endif //ASSIGNMENTCOBA1_CTIS_H
