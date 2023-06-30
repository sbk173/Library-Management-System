#include "UserFuncs.h"

void UserManager::registerUser(string uid , string pass){
    ofstream of;
    of.open("Users.txt",ios::app);
    of<<uid<<','<<pass<<'\n';
    of.close();
    cout<<"User Registered Successfully\n";
}

bool UserManager::Authenticate(string uid , string passwd){
    string line;
    ifstream fp("Users.txt");
    while(getline(fp,line)){
        for(int i=0;i<line.length();i++){
            if(line[i] == ','){
                string name = line.substr(0,i);
                if(name == uid){
                    string pass = line.substr(i+1,line.length()-i-1);
                    if(pass == passwd) return true;
                }
                else{
                    break;
                }
            }
        }
    }
    return false;
}

void Login()
{
    UserManager A;
    string uname;
    string pwd;

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

}

void SignUp()
{
    string uname;
    string pwd;

    cout<<"                  "<<"--Create New Login --"<<"               "<<endl;

    cout<<"Create Username: ";
    cin>>uname;

    cout<<"Create password: ";
    cin>>pwd;

    cout<<endl;

    UserManager A;
    A.registerUser(uname,pwd);

    cout<<"                  "<<"--SignUp Successful-- "<<endl;
    

}