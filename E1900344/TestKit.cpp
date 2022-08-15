/**
 * TestKit class defines a simple object type that represents a TestKit.
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
 * to create TestKit objects and initialize data member to default values.
 */
TestKit::TestKit() : testName("unknown"), kitID("unknown"), availableStock(0) {}

 /**
  * Constructor with 3 arguments,
  * to set the data member
  * to the value passed in the arguments
  * @param testName value passed in the argument.
  * @param kitId value passed in the argument.
  * @param availableStock value passed in the argument.
  */
TestKit::TestKit(string testName, string kitId, int availableStock)
: testName(std::move(testName)), kitID(std::move(kitId)), availableStock(availableStock) {}

/**
 * An user defined destructor
 */
TestKit::~TestKit() {}

/**
 * The getTestName getter method is used to
 * obtain the testName value
 * @return a string value of testName
 */
const string &TestKit::getTestName() const {
    return testName;
}

/**
 * The setTestName setter method is used to
 * set the value of testName data member.
 * @param testName value to set the testName data member.
 */
void TestKit::setTestName(const string &testName) {
    TestKit::testName = testName;
}

/**
 * The getKitId getter method is used to
 * obtain the kitID value
 * @return a string value of kitID
 */
const string &TestKit::getKitId() const {
    return kitID;
}

/**
 * The setTestName setter method is used to
 * set the value of kitId data member.
 * @param kitId value to set the kitId data member.
 */
void TestKit::setKitId(const string &kitId) {
    kitID = kitId;
}

/**
* The getAvailableStock getter method is used to
* obtain the availableStock value
* @return an int value of availableStock
*/
int TestKit::getAvailableStock() const {
    return availableStock;
}

/**
 * The setAvailableStock setter method is used to
 * set the value of availableStock data member.
 * @param availableStock value to set the availableStock data member.
 */
void TestKit::setAvailableStock(int availableStock) {
    TestKit::availableStock = availableStock;
}

/**
 * The output stream method is used to return
 * the detail TestKit object information.
 * @param os the original ostream object
 * @param kit access the private data member within a TestKit object.
 * @return detail TestKit object information.
 */
ostream &operator<<(ostream &os, const TestKit &kit) {
    os << "\nTest name: " << kit.testName
       << "\nKit ID: " << kit.kitID
       << "\nAvailable stock: " << kit.availableStock;
    return os;
}

/**
 * The addCovidTest used to append value to container.
 * @param covidTest reference covid test object.
 */
void TestKit::addCovidTest(CovidTest &covidTest) {
    covidTests.push_back(covidTest);
}

/**
 * The getCovidTest support method which is used to
 * get covidTests object address in container.
 * @return covid test object address or nullptr if empty.
 */
CovidTest *TestKit::getCovidTest() {
    for(auto & covidTest : covidTests) {
        return &covidTest;
    }
    return nullptr;
}

/**
 * The getCovidTests support method which is used to
 * get size of covidTests container.
 * @return address of covidTests container.
 */
vector<CovidTest> TestKit::getCovidTests() const {
    return covidTests;
}

