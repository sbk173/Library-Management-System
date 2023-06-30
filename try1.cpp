#include "UserFuncs.h"
#include "BookFuncs.h"

#include <iostream>
using namespace std;

int main()
{
    UserManager A;
    string uname;
    string pwd;

    A.registerUser("Hari","codecode");
    
    cout<<"               "<<"WELCOME TO THE LIBRARY!"<<"             "<<endl;

    cout<<"                  "<<"--Please Login --"<<"               "<<endl;
    cout<<endl;

    while(true)
    {
        cout<<"Username: ";
        
        cin>>uname;

        cout<<"Password: ";
        
        cin>>pwd;

        if( A.Authenticate(uname, pwd))
        {
            cout<<endl;
            cout<<"                  "<<"--Login Successful-- "<<endl;
            break;
        }
        else
        {
            cout<<"Login failed. Try agian"<<endl;
            cout<<endl;
        }
    }

    

 







    //Ending space:
    for(int i =0; i<5;i++) cout<<endl;
}

