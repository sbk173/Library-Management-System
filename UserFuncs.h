//#pragma once

#include <iostream>
#include <fstream>
#include<cstdio>

using namespace std;

class UserManager 
{
    public:
    bool Authenticate(string  , string );

    void registerUser(string  , string );
};

void Login();

void SignUp();