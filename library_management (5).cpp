#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string publisher;
    double price;

public:
    //constructor
    Book(string t, string a, string pub, int p) {
        title = t;
        author = a;
        publisher = pub;
        price = p;
    }

    //this function displays data of the book when called
    void getData() {
        cout << "Title: " << title << "\nAuthor: " << author << "\nPrice: $" << price << "\nPublisher: " << publisher<< "\n" << endl;
    }

    string getTitle() {
        return title;
    }


    static void search(Book books[], int size, string searchTitle) {
        bool bookFound = false;
        for(int i = 0; i < size; i++) {
            if(books[i].getTitle() == searchTitle) {
                cout <<"\n=======Search Test =======" << endl;
                cout <<"\n======= Book found! =======" << endl;
                books[i].getData();
                bookFound = true;
                return;
            }
        }

        if(!bookFound) {
            cout<<"\n======= " << searchTitle << " doesn't found!=======" << endl;
        }

    }

};

int main() {
   Book bookList[] = {
    Book("Effective Modern C++", "Scott Meyers", "O'Reilly Media", 780),
    Book("C++ Primer (5th Edition)", "Stanley B. Lippman, Josée Lajoie, and Barbara E. Moo", "Addison-Wesley", 890),
    Book("Programming: Principles and Practice Using C++", "Bjarne Stroustrup", "Addison-Wesley", 950),
    Book("Fluent Python", "Luciano Ramalho", "O'Reilly Media", 820),
    Book("Python Crash Course (2nd Edition)", "Eric Matthes", "No Starch Press", 650)
};
    int bookListLen = sizeof(bookList)/sizeof(bookList[0]);

    for(int i = 0; i < bookListLen; i++) {
        bookList[i].getData();
    }

    Book::search(bookList, bookListLen, "Programming: Principles and Practice Using C++");
    Book::search(bookList, bookListLen, "Basics of JAVA");


    return 0;
}
