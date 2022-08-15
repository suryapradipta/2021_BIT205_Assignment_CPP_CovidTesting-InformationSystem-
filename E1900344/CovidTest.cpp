/**
 * CovidTest class defines a simple object type that represents a CovidTest.
 * Student ID: E1900344
 * Date: 16 December 2021
 * C++ version: C++14
 * IDE : CLion
 */

#include <utility>
#include "CTIS.h"


/**
 * Default constructor without arguments,
 * to create Covid Test objects and initialize data member to default values.
 */
CovidTest::CovidTest() : testID("unknown"), testDate("unknown"), result("unknown"), resultDate("unknown"),
status("unknown") {}

 /**
  * Constructor with 5 arguments,
  * to set the data member
  * to the value passed in the arguments
  * @param testId value passed in the argument.
  * @param testDate value passed in the argument.
  * @param result value passed in the argument.
  * @param resultDate value passed in the argument.
  * @param status value passed in the argument.
  */
CovidTest::CovidTest(string testId, string testDate, string result, string resultDate,
                     string status) : testID(std::move(testId)), testDate(std::move(testDate)),
                                      result(std::move(result)), resultDate(std::move(resultDate)),
                                      status(std::move(status)) {}

/**
 * An user defined destructor
 */
CovidTest::~CovidTest() {}

/**
 * The getTestId getter method is used to
 * obtain the testID value
 * @return a string value of testID
 */
const string &CovidTest::getTestId() const {
    return testID;
}

/**
 * The setTestId setter method is used to
 * set the value of testID data member.
 * @param testID value to set the testID data member.
 */
void CovidTest::setTestId(const string &testId) {
    testID = testId;
}

/**
 * The getTestDate getter method is used to
 * obtain the testDate value
 * @return a string value of testDate
 */
const string &CovidTest::getTestDate() const {
    return testDate;
}

/**
 * The setTestDate setter method is used to
 * set the value of testDate data member.
 * @param testDate value to set the testDate data member.
 */
void CovidTest::setTestDate(const string &testDate) {
    CovidTest::testDate = testDate;
}

/**
 * The getResult getter method is used to
 * obtain the result value
 * @return a string value of result
 */
const string &CovidTest::getResult() const {
    return result;
}

/**
 * The setResult setter method is used to
 * set the value of result data member.
 * @param result value to set the result data member.
 */
void CovidTest::setResult(const string &result) {
    CovidTest::result = result;
}

/**
 * The getResultDate getter method is used to
 * obtain the resultDate value
 * @return a string value of resultDate
 */
const string &CovidTest::getResultDate() const {
    return resultDate;
}

/**
 * The setResultDate setter method is used to
 * set the value of resultDate data member.
 * @param resultDate value to set the resultDate data member.
 */
void CovidTest::setResultDate(const string &resultDate) {
    CovidTest::resultDate = resultDate;
}

/**
 * The getStatus getter method is used to
 * obtain the status value
 * @return a string value of status
 */
const string &CovidTest::getStatus() const {
    return status;
}

/**
 * The setStatus setter method is used to
 * set the value of status data member.
 * @param status value to set the status data member.
 */
void CovidTest::setStatus(const string &status) {
    CovidTest::status = status;
}

/**
 * The output stream method is used to return
 * the detail CovidTest object information.
 * @param os the original ostream object
 * @param test access the private data member within a CovidTest object.
 * @return detail CovidTest object information.
 */
ostream &operator<<(ostream &os, const CovidTest &test) {
    os << "\nTest ID: " << test.testID
       << "\nTest date: " << test.testDate
       << "\nResult: " << test.result
       << "\nResult date: " << test.resultDate
       << "\nStatus: " << test.status;
    return os;
}