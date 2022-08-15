//
// Created by Surya Pradipta on 09/12/21.
//


#include "CTIS.h"
#include <iostream>

using namespace std;

TestKit::TestKit() : testName("unknown"), kitID("unknown"), availableStock(0) {}

TestKit::TestKit(string testName, string kitID, int availableStock)
: testName(testName), kitID(kitID), availableStock(availableStock) {}

TestKit::~TestKit() {}

string TestKit::getTestName() const {
    return testName;
}

string TestKit::getKitId() const {
    return kitID;
}

int TestKit::getAvailableStock() const {
    return availableStock;
}

void TestKit::setTestName(string testName) {
    TestKit::testName = testName;
}

void TestKit::setKitId(string kitID) {
    TestKit::kitID = kitID;
}

void TestKit::setAvailableStock(int availableStock) {
    TestKit::availableStock = availableStock;
}

ostream &operator<<(ostream &os, const TestKit &kit) {
    os << "\nTest name: " << kit.testName
    << "\nKit ID: " << kit.kitID
    << "\nAvailable stock: " << kit.availableStock;
    return os;
}

void TestKit::addCovidTest(CovidTest &covidTest) {
    covidTests.push_back(covidTest);
}

void TestKit::showAllCovidTest() {
    for(int i = 0; i < covidTests.size(); i++) {
        cout << covidTests[i] << endl;
    }

}

CovidTest *TestKit::getCovidTest() {
    for(int i = 0; i < covidTests.size(); i++) {
        return &covidTests[i];
    }
    return NULL;
}

vector<CovidTest> TestKit::getCovidTestCollection() const {
    return covidTests;
}





