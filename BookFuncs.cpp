#include "BookFuncs.h"

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

void getline1(istream &input , string &target){
    string temp;
    char ch;

    while(input.peek() !='\n'){
        input.get(ch);
        temp+=ch;
    }
    target = temp;
}

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

void search(string search){ //Universal search by phrase
    
    string line;
    bool found;
    ifstream fp("Available_Books.txt");
    while(getline(fp , line)){
        
        Book book = createObj(line);

        if(book.author.find(search) != string::npos || book.bookname.find(search) != string::npos || book.genre == search )  
        {
            book.display();
            found = true;
        }
    }
    if(found == false) cout<<"                     --No matches found."<<endl;
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
        fp2<<b.bookname<<','<<b.author<<','<<b.genre<<','<<b.qty<<','<<'\n';
    }
    char new_name[] = "Available_Books.txt";
    char old_name[] = "temp.txt";
    int res = remove(new_name);
    cout<<res;

    rename(old_name,new_name);

    if(found ==0){
        cout<<"Sorry,Book is Currently Unavailable\n";
    }
    else{
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
}

void giveback(string book,string user){ //Call for updating Borrowed Books (Incomplete)
    ifstream fp("Borrowed_Books.txt");
    string line;

    while(getline(fp,line)){
        Book b = createObj(line);
        if(b.bookname == book){
            string user;
        }
    }
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
        else{
            fp2<<b.bookname<<','<<b.author<<','<<b.genre<<','<<b.qty<<','<<'\n';
        }
    }
    char new_name[] = "Available_Books.txt";
    char old_name[] = "temp.txt";
    remove(new_name);
    rename(old_name,new_name);
    if(flag == 0){
        AddBook(b);
    }
}