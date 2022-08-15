//
// Created by Surya Pradipta on 09/12/21.
//

#include "CTIS.h"

User::User() : username("unknown"), password("unknown"), name("unknown"){

}

User::User(string username, string password, string name)
: username(username), password(password), name(name){}

User::~User() {}


string User::getUsername() const {
    return username;
}

string User::getPassword() const {
    return password;
}

string User::getName() const {
    return name;
}

void User::setUsername(string username) {
    User::username = username;
}

void User::setPassword(string password) {
    User::password = password;
}

void User::setName(string name) {
    User::name = name;
}

ostream &operator<<(ostream &os, const User &user) {
    os << "Username: " << user.username
       << "\nPassword: " << user.password
       << "\nName: " << user.name ;
    return os;
}



