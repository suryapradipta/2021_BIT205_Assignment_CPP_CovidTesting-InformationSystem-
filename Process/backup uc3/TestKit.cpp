//
// Created by Surya Pradipta on 09/12/21.
//


#include "CTIS.h"

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
    os << "\ntestName: " << kit.testName
    << "\nkitID: " << kit.kitID
    << "\navailableStock: " << kit.availableStock;
    return os;
}





