#ifndef BOOKTYPE_H
#define BOOKTYPE_H

#include <string>

class BookType 
{
public:
    BookType(); // default constructor
    BookType(int yearPublished, std::string title, int numAuthors, std::string* authors,
             std::string publisher, std::string isbn, double price, int numCoppies);
    ~BookType(); // destructor

    void setBookInfo(int yearPublished, std::string title, int numAuthors,
                     std::string* authors, std::string publisher, std::string isbn,
                     double price, int numCoppies);
    void printBookInfo();
    void updatePrice(double newPrice);
    void updateNumCopies(int changeInCopies);
    void deleteBook();

    std::string getISBN() const { return isbn; }
    std::string getTitle() const { return title; }
    std::string getFirstAuthor() const { return (authors && numAuthors > 0) ? authors[0] : ""; }

    // <<< Add these operator overloads >>>
    bool operator<(const BookType& other) const { return isbn < other.isbn; }
    bool operator>(const BookType& other) const { return isbn > other.isbn; }
    bool operator==(const BookType& other) const { return isbn == other.isbn; }

private:
    std::string title;
    int numAuthors;
    std::string* authors; // dynamic array of authors
    std::string publisher;
    int yearPublished;
    std::string isbn;
    double price;
    int numCoppies;
};


#endif
