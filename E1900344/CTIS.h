#ifndef E1900344_CTIS_H
#define E1900344_CTIS_H
#include <vector>
#include <ostream>

using namespace std;

class User {
public:
    User();
    User(string usrname, string passw, string name);
    ~User();
    const string &getUsername() const;
    void setUsername(const string &newUsername);
    const string &getPassword() const;
    void setPassword(const string &newPassword);
    const string &getName() const;
    void setName(const string &newName);
    friend ostream &operator<<(ostream &os, const User &user);
    virtual void viewTestHistory() = 0 ;
private:
    string username;
    string password;
    string name;
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
    ~CovidTest();
    const string &getTestId() const;
    void setTestId(const string &testId);
    const string &getTestDate() const;
    void setTestDate(const string &testDate);
    const string &getResult() const;
    void setResult(const string &result);
    const string &getResultDate() const;
    void setResultDate(const string &resultDate);
    const string &getStatus() const;
    void setStatus(const string &status);
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
    TestKit(string testName, string kitId, int availableStock);
    ~TestKit();
    const string &getTestName() const;
    void setTestName(const string &testName);
    const string &getKitId() const;
    void setKitId(const string &kitId);
    int getAvailableStock() const;
    void setAvailableStock(int availableStock);
    friend ostream &operator<<(ostream &os, const TestKit &kit);
    void addCovidTest(CovidTest &covidTest);
    CovidTest *getCovidTest();
    vector<CovidTest> getCovidTests() const;
};

class TestCentre {
private:
    string centreId;
    string centreName;
    vector<TestKit> newStocks;
    vector<TestKit> testKits;
    vector<TestKit>::iterator t;
public:
    TestCentre();
    TestCentre(string centreId, string centreName);
    ~TestCentre();
    const string &getCentreId() const;
    void setCentreId(const string &centreId);
    const string &getCentreName() const;
    void setCentreName(const string &centreName);
    friend ostream &operator<<(ostream &os, const TestCentre &centre);
    void addNewStock(TestKit &testKit);
    void showNewStocks();
    int getNumOfNewStocks();
    TestKit *getNewStock();
    void addTestKit(TestKit &testKit);
    vector<TestKit> getTestKits() const;
    void showAllTestKit();
    TestKit *getTestKit();
    TestKit *findTestKit(const string& kitID);
    bool kitIDValidation(const string& kitID);
    void showAvailableTestKit();

};

class CentreOfficer : public User{
private:
    string position;
    vector<TestCentre> testCentres;
    vector<CovidTest> covidTests;
    vector<CovidTest>::iterator c;
    vector<TestCentre>::iterator t;

public:
    CentreOfficer();
    CentreOfficer(const string &usrname, const string &pass, const string &name, string position);
    ~CentreOfficer();
    const string &getPosition() const;
    void setPosition(const string &position);
    friend ostream &operator<<(ostream &os, const CentreOfficer &officer);
    void viewTestHistory() override;
    void addTestCentre(TestCentre testCentre);
    vector<TestCentre> getTestCentres() const;
    TestCentre *getTestCentre();
    void addCovidTest(CovidTest &covidTest);
    vector<CovidTest> getCovidTests() const;
    CovidTest *getCovidTest();
};

class Patient : public User{
private:
    string patientType;
    string symptoms;
    vector<string> patientTypes;
    vector<CovidTest> covidTests;
    vector<CovidTest>::iterator c;

public:
    Patient();
    Patient(const string &usrname, const string &pass, const string &name, string patientType,
            string symptoms);
    ~Patient();
    const string &getPatientType() const;
    void setPatientType(const string &patientType);
    const string &getSymptoms() const;
    void setSymptoms(const string &symptoms);
    friend ostream &operator<<(ostream &os, const Patient &patient);
    void viewTestHistory() override;
    void addPatientType(string patientType);
    void showAllPatientType();
    string *getSelectedPatientType();
    void addCovidTest(CovidTest &covidTest);
    CovidTest *getCovidTest();
    vector<CovidTest> getCovidTests() const;
};

class CTIS {
private:
    vector<CentreOfficer> CTISCentreManagers;
    vector<CentreOfficer> CTISTesters;
    vector<TestCentre> CTISTestCentres;
    vector<Patient> CTISPatients;

public:
    CTIS();
    ~CTIS();
    void addCentreManager(CentreOfficer &centreManager);
    void addTestCentre(TestCentre &testCentre);
    void addTester(CentreOfficer &tester);
    void addPatient(Patient &patient);
    bool findCentreManager(const string& username);
    bool findTester(const string& username);
    bool findPatient(const string& username);
    TestCentre *getTestCentreByID(const string& centreID);
    TestCentre *getTestCentre();
    Patient *getPatient(const string& username);
    TestKit *getTestKit(const string& kitID);
    CentreOfficer *getCentreManager(const string& centreName);
    static TestKit *getTestKitByManager(CentreOfficer &centreOfficer, const string& kitID);
    CovidTest *getCovidTestOfTester(const string& testID);
    Patient *getPatientByCovidTest(const string& testID);
    TestCentre *getTestCentreByCovidTest(const string& testID);
    TestKit *getTestKitByCovidTest(const string& testID);
    CovidTest *getPatientCovidTest(const string& testID);
    CovidTest *getCovidTet(const string& testID);
    CentreOfficer *adminLoginValidation(const string& usrname, const string& pass);
    Patient *patientLoginValidation(const string& username, const string& password);
    CentreOfficer *testerLoginValidation(const string& username, const string& password);
    int getNumOfApprovedTestCentres();
    void showApprovedTestCentres();
    void showAllTestCentres();
    void showAllCovidTestID();
    bool getNumOfPendingCovidTest();
    bool covidTestIDValidation(const string& testID);
};
#endif //E1900344_CTIS_H
