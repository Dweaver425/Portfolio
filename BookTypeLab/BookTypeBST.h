#ifndef BOOKTYPEBST_H
#define BOOKTYPEBST_H

#include "BookType.h"
#include <string>
#include <functional>

class BookTypeBST {
private:
    struct Node {
        BookType data;
        Node* left;
        Node* right;
        Node(const BookType& book) : data(book), left(nullptr), right(nullptr) {}
    };
    Node* root;

    void insert(Node*& node, const BookType& book);
    bool search(Node* node, const std::string& isbn, BookType& result) const;
    void inorder(Node* node, const std::function<void(const BookType&)>& visit);
    void destroy(Node* node);

public:
    BookTypeBST();
    ~BookTypeBST();

    void insert(const BookType& book);
    bool search(const std::string& isbn, BookType& result) const;
    void inorder(const std::function<void(const BookType&)>& visit);
};

#endif
