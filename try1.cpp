#include "UserFuncs.h"
#include "BookFuncs.h"

#include <iostream>
using namespace std;

int main()
{
    cout<<"               "<<"WELCOME TO THE LIBRARY!"<<"             "<<endl;

    cout<<"               -- Actions: 1.Login 2.SignUp -- "<<endl;

    int op;

    while(true)
    {
        cout<<"Enter Option: ";
        cin>>op;

        if(op == 1)
        {
            Login();
            break;
        } 
        else if(op == 2)
        {
            SignUp();
            break;
        } 
        else 
        {
            cout<<"Invalid Option. Try agian.";
        }
    }
    cout<<endl<<endl;

    //-----------------------------------------------------------------------------------------------
    
    while(true)
    {
          cout<<"Actions: \n1.Search Book \n2.Add Book \n3.Borrow Book \n9.Exit"<<endl;
        cout<<"Option: ";
        cin>>op;

        if(op == 1)
        {
            string key;
            cout<<"Enter key phrase: ";
            cin>>key;
            cout<<endl;

            cout<<endl<<"Search Result:"<<endl;

            search(key);
        }
        else if (op == 2)
        {
            Book temp;
            cin>>temp;

            AddBook(temp);

            cout<<"                --Book added--"<<endl;
        }
        else if( op == 3)
        {

        }
        else if( op == 9)
        {
            cout<<"                            --Goodbye--"<<endl;
            exit(0);
        }
        else
        {
            cout<<"Invalid Option"<<endl;
        }  

        cout<<endl<<endl;
    }

    





    

 







    //Ending space:
    for(int i =0; i<5;i++) cout<<endl;
}

