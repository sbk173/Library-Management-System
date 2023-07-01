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

bool existingUser(string uid){
    string line;
    ifstream fp("Users.txt");
    while(getline(fp,line)){
        for(int i=0;i<line.length();i++){
            if(line[i] == ','){
                string name = line.substr(0,i);
                if(name == uid){
                    return true;
                }
                else{
                    break;
                }
            }
        }
    }
    return false;

}

string Login()
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
            return uname;
        }
        else
        {
            cout<<"Login failed. Try agian"<<endl;
            cout<<endl;
        }
    }

}

string SignUp()
{
    string uname;
    string pwd;

    cout<<"                  "<<"--Create New Login --"<<"               "<<endl;

    cout<<"Create Username: ";
    cin>>uname;

    cout<<"Create password: ";
    cin>>pwd;

    cout<<endl;
    if(existingUser(uname) == false){
        UserManager A;
        A.registerUser(uname,pwd);

        cout<<"                  "<<"--SignUp Successful-- "<<endl;
        return uname;
    }
    else{
        return "-1";
    }
    
    

}