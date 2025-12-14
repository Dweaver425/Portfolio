
#include <iostream>
#include "BookType.h" 
#include <string>
using namespace std;

BookType::BookType() 
{
    title = " ";
    numAuthors = 0;
    authors = nullptr;
    publisher = " ";
    yearPublished =  0;
    isbn = "000-0-00-000000-0";
    price = 0.0;
    numCoppies = 0; 
}
  
BookType::BookType(int yearPublished, std::string title, int numAuthors, std::string* authors, std::string publisher, std::string isbn, double price, int numCoppies) 
{
    this->title = title;
    this->numAuthors = numAuthors;
    this->authors = new std::string[numAuthors];
    for (int i = 0; i < numAuthors; i++) {
        this->authors[i] = authors[i];
    }
    this->publisher = publisher;
    this->yearPublished = yearPublished;
    this->isbn = isbn;
    this->price = price;
    this->numCoppies = numCoppies;
}

BookType::~BookType() {
    delete[] authors;
}

void BookType::setBookInfo(int yearPublished, std::string title, int numAuthors, std::string* authors, std::string publisher, std::string isbn, double price, int numCoppies) 
{
    this->title = title;
    this->numAuthors = numAuthors;
    delete[] this->authors;
    this->authors = new std::string[numAuthors];
    for (int i = 0; i < numAuthors; i++) {
        this->authors[i] = authors[i];
    }
    this->publisher = publisher;
    this->yearPublished = yearPublished;
    this->isbn = isbn;
    this->price = price;
    this->numCoppies = numCoppies;
}

void BookType::printBookInfo() 
{
    cout << "Title: " << title << endl;
    cout << "Number of Authors: " << numAuthors << endl;
    cout << "Authors: ";
    for (int i = 0; i < numAuthors; i++) {
        cout << authors[i];
        if (i < numAuthors - 1) cout << ", ";
    }
    cout << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Year Published: " << yearPublished << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Price: $" << price << endl;
    cout << "Number of Copies: " << numCoppies << endl;
    cout << "------------------------" << endl;
}

void BookType::updatePrice(double newPrice) 
{
    price = newPrice;
}

void BookType::updateNumCopies(int changeInCopies) 
{
    numCoppies += changeInCopies;
}

void BookType::deleteBook() {
    title = "";
    numAuthors = 0;
    publisher = "";
    isbn = "";
    price = 0.0;
    numCoppies = 0;
}


