/**
 * User is abstract class of Patient and CentreOfficer,
 * defines a simple object type that represents a User
 * Student ID: E1900344
 * Date: 16 December 2021
 * C++ version: C++14
 * IDE : CLion
 */

#include <utility>
#include "CTIS.h"

/**
 * Default constructor without arguments,
 * to create User objects and initialize data member to default values.
 */
User::User() : username("unknown"), password("unknown"), name("unknown"){}

/**
 * Constructor with 3 arguments,
 * to set the data member
 * to the value passed in the arguments.
 * @param usrname value passed in the argument.
 * @param passw value passed in the argument.
 * @param name value passed in the argument.
 */
User::User(string usrname, string passw, string name)
: username(std::move(usrname)), password(std::move(passw)), name(std::move(name)) {}

/**
 * An user defined destructor
 */
User::~User() {}

/**
 * The getUsername getter method is used to
 * obtain the username value
 * @return a string value of username
 */
const string &User::getUsername() const {
    return username;
}

/**
 * The setUsername setter method is used to
 * set the value of username data member.
 * @param newUsername value to set the username data member.
 */
void User::setUsername(const string &newUsername) {
    User::username = newUsername;
}

/**
 * The getPassword getter method is used to
 * obtain the password value
 * @return a string value of password
 */
const string &User::getPassword() const {
    return password;
}

/**
 * The setPassword setter method is used to
 * set the value of password data member.
 * @param newPassword value to set the password data member.
 */
void User::setPassword(const string &newPassword) {
    User::password = newPassword;
}

/**
 * The getName getter method is used to
 * obtain the name value
 * @return a string value of name
 */
const string &User::getName() const {
    return name;
}

/**
 * The setName setter method is used to
 * set the value of name data member.
 * @param newName value to set the name data member.
 */
void User::setName(const string &newName) {
    User::name = newName;
}

/**
 * The output stream method is used to return
 * the detail User object information.
 * @param os the original ostream object
 * @param user access the private data member within a User object.
 * @return detail User object information.
 */
ostream &operator<<(ostream &os, const User &user) {
    os << "Username: " << user.username
       << "\nPassword: " << user.password
       << "\nName: " << user.name ;
    return os;
}


