//
// Created by Surya Pradipta on 09/12/21.
//


#include "CTIS.h"

#include <iostream>
using namespace std;

TestCentre::TestCentre() : centreId("unknown"), centreName("unknown") {
    /*newStocks.emplace_back("Johnson & Johnson", "newStock", 0);
    newStocks.emplace_back("AstraZeneca", "newStock", 0);
*/

    TestKit testKit1("Johnson & Johnson", "newStock", 0);
    TestKit testKit2("AstraZeneca", "newStock", 0);
    addNewStock(testKit1);
    addNewStock(testKit2);

}

TestCentre::TestCentre(string centreId, string centreName)
: centreId(centreId), centreName(centreName) {}

TestCentre::TestCentre(string centreName) : centreName(centreName){}

TestCentre::~TestCentre() {}

string TestCentre::getCentreId() const {
    return centreId;
}

string TestCentre::getCentreName() const {
    return centreName;
}

void TestCentre::setCentreId(string centreId) {
    TestCentre::centreId = centreId;
}

void TestCentre::setCentreName(string centreName) {
    TestCentre::centreName = centreName;
}

ostream &operator<<(ostream &os, const TestCentre &centre) {
    os << "\ncentreID: " << centre.centreId
       << "\ncentreName: " << centre.centreName;
    return os;
}

//==========================================================


void TestCentre::addNewStock(TestKit &testKit) {
    newStocks.push_back(testKit);
}


void TestCentre::allNewStock() {
    for(int i = 0; i < newStocks.size(); i++) {
        cout << i << newStocks[i] << endl;
    }
}

void TestCentre::showNewStockTestKits() {
    for(int i = 0; i < newStocks.size(); i++) {
        if(newStocks[i].getKitId() == "newStock")
            cout << i+1 << ". " << newStocks[i].getTestName() << endl;
    }
}

int TestCentre::getNewStockTestKits() {
    int newStock = 0;
    for(int i = 0; i < newStocks.size(); i++) {
        if(newStocks[i].getKitId() == "newStock")
            newStock++;
    }
    return newStock;
}



TestKit *TestCentre::getNewStock() {
    for(int i = 0; i < newStocks.size(); i++) {
        return &newStocks[i];
    }
    return NULL;
}




void TestCentre::addTestKit(TestKit &testKit) {
    testKits.push_back(testKit);
}




void TestCentre::showAllTestKit() {
    for(int i = 0; i < testKits.size(); i++) {
        cout << i << testKits[i] << endl;
    }
}




TestKit *TestCentre::getTestKit() {
    for(int i = 0; i < testKits.size(); i++) {
        return &testKits[i];
    }
    return NULL;
}





vector<TestKit> TestCentre::getTestKitCollection() const {
    return testKits;
}






















