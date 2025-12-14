#include "BookTypeBST.h"
#include <iostream>
using namespace std;

// Constructor
BookTypeBST::BookTypeBST() : root(nullptr) {}

// Destructor
BookTypeBST::~BookTypeBST() {
    destroy(root);
}

// Recursive destroy
void BookTypeBST::destroy(Node* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

// Public insert
void BookTypeBST::insert(const BookType& book) {
    insert(root, book);
}

// Recursive insert
void BookTypeBST::insert(Node*& node, const BookType& book) {
    if (!node) {
        node = new Node(book);
        return;
    }
    if (book < node->data)
        insert(node->left, book);
    else if (book > node->data)
        insert(node->right, book);
    // duplicates ignored
}

// Public search
bool BookTypeBST::search(const std::string& isbn, BookType& result) const {
    return search(root, isbn, result);
}

// Recursive search
bool BookTypeBST::search(Node* node, const std::string& isbn, BookType& result) const {
    if (!node) return false;
    if (isbn == node->data.getISBN()) {
        result = node->data;
        return true;
    }
    if (isbn < node->data.getISBN())
        return search(node->left, isbn, result);
    else
        return search(node->right, isbn, result);
}

// Public inorder traversal (now supports std::function/lambdas)
void BookTypeBST::inorder(const std::function<void(const BookType&)>& visit) {
    inorder(root, visit);
}

// Recursive inorder traversal
void BookTypeBST::inorder(Node* node, const std::function<void(const BookType&)>& visit) {
    if (!node) return;
    inorder(node->left, visit);
    visit(node->data);
    inorder(node->right, visit);
}
