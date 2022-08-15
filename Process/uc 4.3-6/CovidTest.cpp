//
// Created by Surya Pradipta on 11/12/21.
//

#include "CTIS.h"

CovidTest::CovidTest() : testID("unknown"), testDate("unknown"), result("unknown"),
                        resultDate("unknown"), status("unknown") {}

CovidTest::CovidTest (string testId, string testDate, string result, string resultDate, string status) :
testID(testId), testDate(testDate), result(result), resultDate(resultDate),
status(status) {}

CovidTest::~CovidTest() {}

string CovidTest::getTestId() const {
    return testID;
}

string CovidTest::getTestDate() const {
    return testDate;
}

string CovidTest::getResult() const {
    return result;
}

string CovidTest::getResultDate() const {
    return resultDate;
}

string CovidTest::getStatus() const {
    return status;
}

void CovidTest::setTestId(string testId) {
    testID = testId;
}

void CovidTest::setTestDate(string testDate) {
    CovidTest::testDate = testDate;
}

void CovidTest::setResult(string result) {
    CovidTest::result = result;
}

void CovidTest::setResultDate(string resultDate) {
    CovidTest::resultDate = resultDate;
}

void CovidTest::setStatus(string status) {
    CovidTest::status = status;
}

ostream &operator<<(ostream &os, const CovidTest &test) {
    os << "\nTest ID: " << test.testID
    << "\nTest date: " << test.testDate
    << "\nResult: " << test.result
    << "\nResult date: " << test.resultDate
    << "\nStatus: " << test.status;
    return os;
}

