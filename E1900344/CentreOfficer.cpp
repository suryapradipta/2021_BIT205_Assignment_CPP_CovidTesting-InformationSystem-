/**
 * CentreOfficer concrete subclass of User
 * defines a simple object type that represents a CentreOfficer.
 * Student ID: E1900344
 * Date: 16 December 2021
 * C++ version: C++14
 * IDE : CLion
 */

#include <iostream>
#include <utility>
#include "CTIS.h"

/**
 * Default constructor without arguments,
 * to create CentreOfficer objects and initialize data member to default values.
 */
CentreOfficer::CentreOfficer() : position("unknown") {}

/**
 * Constructor with 4 arguments,
 * to set the data member
 * to the value passed in the arguments
 * @param usrname value passed in the argument.
 * @param pass value passed in the argument.
 * @param name value passed in the argument.
 * @param position value passed in the argument.
 */
CentreOfficer::CentreOfficer(const string &usrname, const string &pass, const string &name, string position)
        : User(usrname, pass, name), position(std::move(position)) {}

/**
* An user defined destructor
*/
CentreOfficer::~CentreOfficer() {}

/**
 * The getPosition getter method is used to
 * obtain the position value
 * @return a string value of position
 */
const string &CentreOfficer::getPosition() const {
    return position;
}

/**
 * The setPosition setter method is used to
 * set the value of position data member.
 * @param position value to set the position data member.
 */
void CentreOfficer::setPosition(const string &position) {
    CentreOfficer::position = position;
}

/**
 * The output stream method is used to return
 * the detail CentreOfficer object information.
 * @param os the original ostream object
 * @param officer access the private data member within a CentreOfficer object.
 * @return detail CentreOfficer object information.
 */
ostream &operator<<(ostream &os, const CentreOfficer &officer) {
    os << static_cast<const User &>(officer)
       << "\nPosition: " << officer.position;
    return os;
}

/**
 * The viewTestHistory pure virtual method which is used to
 * show test information for Centre Manager and Tester.
 */
void CentreOfficer::viewTestHistory() {
    if(position == "Centre manager") {
        for (t = testCentres.begin(); t < testCentres.end(); t++) {
            for(int j = 0; j < t->getTestKits().size(); j++) {
                for(int k = 0; k < t->getTestKit()[j].getCovidTests().size(); k++) {
                    cout << t->getTestKit()[j].getCovidTest()[k] << endl;
                }
            }
        }
    }
    else if(position == "Tester") {
        for (c = covidTests.begin(); c < covidTests.end(); c++)
            cout << *c << endl;
    }
}

/**
 * The addTestCentre used to append value to container.
 * @param testCentre reference testCentre object.
 */
void CentreOfficer::addTestCentre(TestCentre testCentre) {
    testCentres.push_back(testCentre);
}

/**
 * The getTestCentres used to get size of testCentres container.
 * @return address of testCentres container.
 */
vector<TestCentre> CentreOfficer::getTestCentres() const {
    return testCentres;
}

/**
 * The getTestCentre support method which is used to
 * get testCentres object address in container.
 * @return testCentres object address or nullptr if empty.
 */
TestCentre *CentreOfficer::getTestCentre() {
    for(auto & testCentre : testCentres) {
        return &testCentre;
    }
    return nullptr;
}

/**
 * The addCovidTest used to append value to container.
 * @param covidTest reference covidTest object.
 */
void CentreOfficer::addCovidTest(CovidTest &covidTest) {
    covidTests.push_back(covidTest);
}

/**
 * The getCovidTests used to get size of covidTests container.
 * @return address of covidTests container.
 */
vector<CovidTest> CentreOfficer::getCovidTests() const {
    return covidTests;
}

/**
 * The getCovidTest support method which is used to
 * get covidTests object address in container.
 * @return covidTests object address or nullptr if empty.
 */
CovidTest *CentreOfficer::getCovidTest() {
    for(auto & covidTest : covidTests) {
        return &covidTest;
    }
    return nullptr;
}