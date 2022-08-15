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

class TestKit{
private:
    string testName;
    string kitID;
    int availableStock;
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
    void addNewStock(TestKit &testKit);

    vector<TestKit> getTestKitCollection() const;
    void showAllTestKit();
    void allNewStock();

    void showNewStockTestKits();
    int getNewStockTestKits();
    TestKit *getTestKit();
    TestKit *getNewStock();




};

class CentreOfficer : public User{
private:
    string position;
    vector<TestCentre> testCentres;

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

};

class CTIS {
private:
    // user
    vector<CentreOfficer> CTISCentreOfficers;
    vector<CentreOfficer> CTISTesters;
    // test centre
    vector<TestCentre> CTISTestCentres;

public:
    CTIS();
    virtual ~CTIS();
    void addCentreOfficer(CentreOfficer &centreOfficer);
    vector<CentreOfficer> getCentreOfficers() const;
    void showAllCentreOfficers();
    bool findUsernameCentreOfficer(string username);

    CentreOfficer *adminLoginValidation(string username, string password);


    // tester
    void addTester(CentreOfficer &tester);
    vector<CentreOfficer> getTester() const;
    bool findUsernameTester(string username);
    void showAllTesters();


// ==== test centre
    vector<TestCentre> getCTISTestCentreCollection() const;
    TestCentre *getTestCentre();
    void showApprovedTestCentres();
    int getNumOfApprovedTestCentres(); // untuk nge show rumah sakit yang pending
    bool testCentreValidation(CentreOfficer *centreOfficer);

    TestCentre *findTestCentre(string centreName);

};

#endif //ASSIGNMENTCOBA1_CTIS_H
