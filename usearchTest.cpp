#include "UserFuncs.h"
#include "BookFuncs.h"
#include <cstring>

void Usearch(string search){ //Generic Search algo
    
    string line;
    ifstream fp("Available_Books.txt");
    while(getline(fp , line)){
        
        Book book = createObj(line);

        if(book.author.find(search) != string::npos || book.bookname.find(search) != string::npos || book.genre == search )  
        {
            book.display();
        }
    }
}

// int main()
// {
//     Usearch("Theory");
// }