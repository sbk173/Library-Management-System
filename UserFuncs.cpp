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
