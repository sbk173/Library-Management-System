#include "UserFuncs.h"
#include "BookFuncs.h"

#include <iostream>

using namespace std;

string currentUser = "Hari";

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
            currentUser= Login();
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
        cout<<"Actions: \n1.Search Book \n2.Add Book \n3.Borrow Book \n4.Return Book \n9.Exit"<<endl;
        cout<<"Option: ";
        cin>>op;

        if(op == 1)
        {   
            system("clear");
            cout<<endl<< "                           --Book Search--"<<endl;
            string key;
            cout<<"Enter key phrase: ";
            cin>>key;
            cout<<endl;

            cout<<endl<<"Search Result:"<<endl;

            search(key);
        }
        else if (op == 2)
        {
            system("clear");
            cout<<endl<< "                           --Add Book--"<<endl;
            Book temp;
            cin>>temp;

            AddBook(temp);

            cout<<endl<<"                --Book added--"<<endl;
        }
        else if( op == 3)
        {
            system("clear");
            cout<<endl<< "                           --Borrow Book--"<<endl;
            cout<<"Enter Book Name"<<endl;
            string temp;
            cin>>temp;

            borrowBook(temp, currentUser);

            cout<<"                               --Borrow Successful--";
        }
        else if(op == 4){
            system("clear");
            cout<<endl<< "                           --Return Book--"<<endl;
            string book;
            cout<<"Enter Book To Return"<<endl;
            cin>>book;
            giveback(book, currentUser);
            cout<<"                                --Return Successful--";
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
    //for(int i =0; i<5;i++) cout<<endl;

    system("clear");
}

