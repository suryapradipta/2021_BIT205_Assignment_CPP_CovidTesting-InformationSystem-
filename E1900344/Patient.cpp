/**
 * Patient concrete subclass of User
 * defines a simple object type that represents a Patient.
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
 * to create Patient objects and initialize data member to default values.
 */
Patient::Patient() : patientType("unknown"), symptoms("unknown") {
    // Create patient type by hard-coded
    addPatientType("returnee");
    addPatientType("quarantined");
    addPatientType("close contact");
    addPatientType("infected");
    addPatientType("suspected");
}

 /**
  * Constructor with 4 arguments,
  * to set the data member
  * to the value passed in the arguments
  * @param usrname value passed in the argument.
  * @param pass value passed in the argument.
  * @param name value passed in the argument.
  * @param patientType value passed in the argument.
  * @param symptoms value passed in the argument.
  */
Patient::Patient(const string &usrname, const string &pass, const string &name, string patientType,
                 string symptoms) : User(usrname, pass, name),
                 patientType(std::move(patientType)),symptoms(std::move(symptoms)) {}

/**
* An user defined destructor
*/
Patient::~Patient() {}

/**
 * The getPatientType getter method is used to
 * obtain the patientType value
 * @return a string value of patientType
 */
const string &Patient::getPatientType() const {
    return patientType;
}

/**
 * The setPatientType setter method is used to
 * set the value of patientType data member.
 * @param patientType value to set the patientType data member.
 */
void Patient::setPatientType(const string &patientType) {
    Patient::patientType = patientType;
}

/**
 * The getSymptoms getter method is used to
 * obtain the symptoms value
 * @return a string value of symptoms
 */
const string &Patient::getSymptoms() const {
    return symptoms;
}

/**
 * The setSymptoms setter method is used to
 * set the value of symptoms data member.
 * @param symptoms value to set the symptoms data member.
 */
void Patient::setSymptoms(const string &symptoms) {
    Patient::symptoms = symptoms;
}

/**
 * The output stream method is used to return
 * the detail Patient object information.
 * @param os the original ostream object
 * @param patient access the private data member within a Patient object.
 * @return detail Patient object information.
 */
ostream &operator<<(ostream &os, const Patient &patient) {
    os << static_cast<const User &>(patient)
       << "\nPatient type: " << patient.patientType
       << "\nSymptoms: " << patient.symptoms;
    return os;
}

/**
 * The viewTestHistory pure virtual method which is used to
 * show test information for Patient.
 */
void Patient::viewTestHistory() {
    for (c = covidTests.begin(); c < covidTests.end(); c++)
        cout << *c << endl;
}

/**
 * The addPatientType used to append value to container.
 * @param patientType reference patientType object.
 */
void Patient::addPatientType(string patientType) {
    patientTypes.push_back(patientType);
}

/**
 * The showAllPatientType support method which is used to
 * show all patient type in the container.
 */
void Patient::showAllPatientType() {
    for(int i = 0; i < patientTypes.size(); i++)
        cout << i+1 << ". " << patientTypes[i] << endl;
}

/**
 * The getSelectedPatientType support method which is used to
 * get patient type address in the container.
 */
string *Patient::getSelectedPatientType() {
    for(auto & i : patientTypes) {
        return &i;
    }
    return nullptr;
}

/**
 * The addCovidTest used to append value to container.
 * @param covidTest reference covidTest object.
 */
void Patient::addCovidTest(CovidTest &covidTest) {
    covidTests.push_back(covidTest);
}

/**
 * The getCovidTest support method which is used to
 * get covidTest object address in container.
 * @return covidTest object address or nullptr if empty.
 */
CovidTest *Patient::getCovidTest() {
    for(auto & covidTest : covidTests) {
        return &covidTest;
    }
    return nullptr;
}

/**
 * The getCovidTests used to get size of covidTests container.
 * @return address of covidTests container.
 */
vector<CovidTest> Patient::getCovidTests() const {
    return covidTests;
}



