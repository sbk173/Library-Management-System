#include<iostream>
#include<fstream>
#include<cstdio>

using namespace std;

class Book{
    public:
        string bookname;
        string author;
        string genre;
        int qty;

        // Book(string name , string auth , string gen , int n){
        //     bookname = name;
        //     author = auth;
        //     genre = gen;
        //     qty = n;
        // }

        void display(){
            cout<<"Name: "<<bookname<<"\t";
            cout<<"Author: "<<author<<"\t";
            cout<<"Genre: "<<genre<<"\t";
            cout<<"Available Quantity: "<<qty<<endl;
        }

    friend istream &operator>>(istream &input , Book &b);
};


istream &operator>>(istream &input , Book &b){
    cout<<"Enter Book Name: ";
    input>>b.bookname;

    cout<<"Enter Author's Name: ";
    input>>b.author;


    cout<<"Enter Genre of the book: ";
    input>>b.genre;

    cout<<"Enter Book Quantity: ";
    input>>b.qty;

    return input;
}

string admin_uid = "Admin";
string admin_pass = "Admin";

Book createObj(string line){ // Helper to create book object from comma separated values
    Book book;
    int index = 0;
    int count = 0;
    for(int i=0;i<line.length();i++){
        if(line[i] == ','){
            if(count == 0){
                book.bookname = line.substr(index,i-index);
            }
            else if(count ==1){
                book.author= line.substr(index,i-index);
            }
            else if (count ==2){
                book.genre= line.substr(index,i-index);
            }
            else if (count ==3){
                string temp;
                temp= line.substr(index,i-index);
                book.qty = stoi(temp);
            }
            index = i+1;
            count++;
        }
    }
    return book;
}

void search(int parameter , string search){ //Generic Search algo
    
    string line;
    ifstream fp("Available_Books.txt");
    while(getline(fp , line)){
        
        Book book = createObj(line);
        if(parameter == 1){ //1 is Book Name
            if(book.bookname == search){
                book.display();
            }
        }
        else if(parameter ==2){ //2 is author
            if(book.author == search){
                book.display();
            }
        }
        else if(parameter == 3){ //3 is genre
            if(book.genre == search){
                book.display();
            }
        }  
    }
}

void searchByName(string name){ //Search books by name
    search(1,name);
}

void searchByAuthor(string name){ //Search books by Author
    search(2,name);
}

void searchByGenre(string genre){ //Search books by Genre
    search(3,genre);
}

void borrowBook(string book,string user){ //Call to borrow a book
    string line;
    Book borrowed;
    ifstream fp("Available_Books.txt");
    int found =0;
    ofstream fp2("temp.txt");
    while(getline(fp,line)){
        Book b = createObj(line);
        if(b.bookname == book){
            found =1;
            borrowed = b;
            b.qty--;
            if(b.qty == 0){
                continue;
            }
        }
        else{
            fp2<<b.bookname<<','<<b.author<<','<<b.genre<<','<<b.qty<<','<<'\n';
        }
    }
    char new_name[] = "Available_Books.txt";
    char old_name[] = "temp.txt";
    remove(new_name);
    rename(old_name,new_name);

    if(found ==0){
        cout<<"Sorry,Book is Currently Unavailable\n";
    }
    else{
        cout<<"Your Book has been issued\n";
        ofstream of;
        of.open("Borrowed_Books.txt",ios::app);
        of<<borrowed.bookname<<','<<borrowed.author<<','<<borrowed.genre<<','<<1<<','<<user<<'\n';
    }

}

void AddBook(Book b){ //Call to add book to library
    ofstream of;
    of.open("Available_Books.txt",ios::app);
    of<<b.bookname<<','<<b.author<<','<<b.genre<<','<<b.qty<<','<<'\n';
    of.close();
    cout<<"Book Successfully Added"<<endl;
}

void removeBook(string book){ //Call to remove book from library
    string line;
    ifstream fp("Available_Books.txt");
    int found =0;
    ofstream fp2("temp.txt");
    while(getline(fp,line)){
        Book b = createObj(line);
        if(b.bookname == book){
            continue;
        }
        else{
            fp2<<b.bookname<<','<<b.author<<','<<b.genre<<','<<b.qty<<','<<'\n';
        }
    }
    char new_name[] = "Available_Books.txt";
    char old_name[] = "temp.txt";
    remove(new_name);
    rename(old_name,new_name);
    cout<<"Book Successfully Removed"<<endl;
}


void returnBook(Book b){ //Call for updating Available Books;
    string line;
    int flag = 0;
    string book = b.bookname;
    ifstream fp("Available_Books.txt");

    ofstream fp2("temp.txt");
    while(getline(fp,line)){
        Book b = createObj(line);
        if(b.bookname == book){
            b.qty++;
            flag = 1;
        }
        fp2<<b.bookname<<','<<b.author<<','<<b.genre<<','<<b.qty<<','<<'\n';
    }
    char new_name[] = "Available_Books.txt";
    char old_name[] = "temp.txt";
    fp.close();
    fp2.close();
    remove(new_name);
    rename(old_name,new_name);
    if(flag == 0){
        
        AddBook(b);
    }
    cout<<"Your Book has been returned"<<endl;
}


void giveback(string book,string user){ //Call for updating Borrowed Books 
    ifstream fp("Borrowed_Books.txt");
    string line;
    int flag = 0;
    Book toUpdate ;
    ofstream fp1("temp.txt");
    while(getline(fp,line)){
        Book b = createObj(line);
        if(b.bookname == book){
            int pos = line.find_last_of(',');
            string by = line.substr(pos+1,line.length()-pos);
            if(user == by){
                flag = 1;
                toUpdate = b;
            }
            else{
                fp1<<line<<'\n';
            }
        }
        else{
            fp1<<line<<'\n';
        }
    }
    fp.close();
    fp1.close();
    char new_name[] = "Borrowed_Books.txt";
    char old_name[] = "temp.txt";
    remove(new_name);
    rename(old_name,new_name);
    if(flag!=0){
        returnBook(toUpdate);
    }
}

void UsersBooks(string user){// Display all the books borrowed by a user
    ifstream fp("Borrowed_Books.txt");
    string line;

    while(getline(fp,line)){
        Book b = createObj(line);
        int pos = line.find_last_of(',');
        string by = line.substr(pos+1,line.length()-pos);
        if(user == by){
            b.display();
        }

    }
}





void registerUser(string uid , string pass){//To Register new User
    ofstream of;
    of.open("Users.txt",ios::app);
    of<<uid<<','<<pass<<'\n';
    of.close();
    cout<<"User Registered Successfully\n";
}

bool Authenticate(string uid , string passwd){// To validate user
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



int main(){
    
    // Book b;
    // cin>>b;

   //AddBook(b);
   searchByGenre("Horror");
   searchByName("ABC");
   searchByAuthor("GREG");
   cout<<Authenticate("ABC","ABC")<<endl;
   //borrowBook("ABC","Admin");
   UsersBooks("Admin");
    removeBook("KKL");

}