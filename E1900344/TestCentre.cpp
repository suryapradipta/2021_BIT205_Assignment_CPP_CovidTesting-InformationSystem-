/**
 * TestCentre class defines a simple object type that represents a TestCentre.
 * Student ID: E1900344
 * Date: 16 December 2021
 * C++ version: C++14
 * IDE : CLion
 */

#include "CTIS.h"

#include <iostream>
#include <utility>
using namespace std;

/**
 * Default constructor without arguments,
 * to create TestCentre objects and initialize data member to default values.
 */
TestCentre::TestCentre() : centreId("unknown"), centreName("unknown") {
    // Append new stock of Test Kit by hard-coded
    TestKit testKit1("SGTi-flex COVID-19 IgG", "newStock", 0);
    TestKit testKit2("T-Detect COVID Test", "newStock", 0);
    TestKit testKit3("SARS-CoV-2 RBD IgG test", "newStock", 0);
    addNewStock(testKit1);
    addNewStock(testKit2);
    addNewStock(testKit3);
}

/**
 * Constructor with 2 arguments,
 * to set the data member
 * to the value passed in the arguments
 * @param centreId value passed in the argument.
 * @param centreName value passed in the argument.
 */
TestCentre::TestCentre(string centreId, string centreName) : centreId(std::move(centreId)), centreName(std::move(centreName)) {}

/**
 * An user defined destructor
 */
TestCentre::~TestCentre() {}

/**
 * The getCentreId getter method is used to
 * obtain the centreId value
 * @return a string value of centreId
 */
const string &TestCentre::getCentreId() const {
    return centreId;
}

/**
 * The setCentreId setter method is used to
 * set the value of centreId data member.
 * @param centreId value to set the centreId data member.
 */
void TestCentre::setCentreId(const string &centreId) {
    TestCentre::centreId = centreId;
}

/**
 * The getCentreName getter method is used to
 * obtain the centreName value
 * @return a string value of centreName
 */
const string &TestCentre::getCentreName() const {
    return centreName;
}

/**
 * The setCentreName setter method is used to
 * set the value of centreName data member.
 * @param centreName value to set the centreName data member.
 */
void TestCentre::setCentreName(const string &centreName) {
    TestCentre::centreName = centreName;
}

/**
 * The output stream method is used to return
 * the detail TestCentre object information.
 * @param os the original ostream object
 * @param centre access the private data member within a TestCentre object.
 * @return detail TestCentre object information.
 */
ostream &operator<<(ostream &os, const TestCentre &centre) {
    os << "\nCentre ID: " << centre.centreId
       << "\nCentre name: " << centre.centreName;
    return os;
}

/**
 * The addNewStock used to append value to container.
 * @param testKit reference testKit object.
 */
void TestCentre::addNewStock(TestKit &testKit) {
    newStocks.push_back(testKit);
}

/**
 * The showNewStocks support method which is used to
 * show new stock of Test Kit in container.
 */
void TestCentre::showNewStocks() {
    for(int i = 0; i < newStocks.size(); i++) {
        if(newStocks[i].getKitId() == "newStock")
            cout << i+1 << ". " << newStocks[i].getTestName() << endl;
    }
}

/**
 * The getNumOfNewStocks support method which is used to
 * get num of new stocks in container.
 * @return int num of stock.
 */
int TestCentre::getNumOfNewStocks() {
    int newStock = 0;
    for(auto & i : newStocks) {
        if(i.getKitId() == "newStock")
            newStock++;
    }
    return newStock;
}

/**
 * The getNewStock support method which is used to
 * get newStocks object address in container.
 * @return newStocks object address or nullptr if empty.
 */
TestKit *TestCentre::getNewStock() {
    for(auto & newStock : newStocks) {
        return &newStock;
    }
    return nullptr;
}

/**
 * The addTestKit used to append value to container.
 * @param testKit reference testKit object.
 */
void TestCentre::addTestKit(TestKit &testKit) {
    testKits.push_back(testKit);
}

/**
 * The getTestKits used to get size of testKits container.
 * @return address of testKits container.
 */
vector<TestKit> TestCentre::getTestKits() const {
    return testKits;
}

/**
 * The showAllTestKit support method which is used to
 * show all Test Kit in the container.
 */
void TestCentre::showAllTestKit() {
    for (t = testKits.begin(); t < testKits.end(); t++)
        cout << *t << endl;
}

/**
 * The getTestKit support method which is used to
 * get testKits object address in container.
 * @return testKits object address or nullptr if empty.
 */
TestKit *TestCentre::getTestKit() {
    for(auto & testKit : testKits) {
        return &testKit;
    }
    return nullptr;
}

/**
 * The getTestKit support method which is used to
 * find teskits object address in container based on kitID.
 * @param kitID reference to compare.
 * @return testKits object address or nullptr if empty.
 */
TestKit *TestCentre::findTestKit(const string& kitID) {
    for(auto & testKit : testKits) {
        if(testKit.getKitId() == kitID)
            return &testKit;
    }
    return nullptr;
}

/**
 * The getTestKit support method which is used to
 * compare teskits object address in container based on kitID.
 * @param kitID reference to compare.
 * @return true if found or false not found.
 */
bool TestCentre::kitIDValidation(const string& kitID) {
    for(auto & testKit : testKits) {
        if(testKit.getKitId() == kitID)
            return true;
    }
    return false;
}

/**
 * The showAvailableTestKit support method which is used to
 * show all available Test Kit in container.
 */
void TestCentre::showAvailableTestKit() {
    for(auto & testKit : testKits) {
        if(testKit.getAvailableStock() > 0)
            cout << testKit << endl;
    }
}