#include <iostream>
#include<fstream>
#include<cstdio>

using namespace std;

class Book{
    public:
        string bookname;
        string author;
        string genre;
        int qty;

        Book(string name , string auth , string gen , int n){
            bookname = name;
            author = auth;
            genre = gen;
            qty = n;
        }
        Book(){}

        void display(){
            cout<<"Name: "<<bookname<<"\t";
            cout<<"Author: "<<author<<"\t";
            cout<<"Genre: "<<genre<<"\t";
            cout<<"Quantity: "<<qty<<endl;
        }

    friend istream &operator>>(istream &input , Book &b);
    friend void getline1(istream &input , string &target);
};

istream &operator>>(istream & , Book &);
void getline1(istream &input , string &target);

Book createObj(string );

void search(int  , string );
void search(string);

void searchByName(string );

void searchByAuthor(string );

void searchByGenre(string );

void borrowBook(string ,string );

void AddBook(Book );

void removeBook(string );

void giveback(string ,string );

void returnBook(Book );

void UsersBooks(string);

