#include "BookTypeBST.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include "BookType.h"
#include <iostream>
using namespace std;


// Removed stray main and bst declaration
int main() 
{
    const int MAX_BOOKS = 100;
    BookTypeBST bst;
    std::string title[100] = {
        "The Lost Kingdom", "Shadows of Tomorrow", "Whispering Pines", "The Last Voyage", "Echoes in the Mist", "The Forgotten Garden", "Midnight Sun", "The Secret Heir", "Beneath the Surface", "The Clockmaker’s Daughter",
        "The Silver Key", "A World Apart", "The Painted Sky", "The Final Chapter", "The Glass Castle", "The Hidden Path", "The Silent Storm", "The Crimson Crown", "The Wandering Star", "The Iron Gate",
        "The Winter’s Promise", "The Golden Thread", "The Sapphire Sea", "The Broken Compass", "The Emerald Isle", "The Phantom’s Mask", "The Moonlit Road", "The Secret Library", "The Enchanted Forest", "The Distant Shore",
        "The Fire Within", "The Shadow’s Edge", "The Whispering Wind", "The Forgotten City", "The Midnight Train", "The Hidden Valley", "The Silver Lining", "The Last Ember", "The Wandering Heart", "The Crystal Lake",
        "The Secret Door", "The Golden Hour", "The Lost Map", "The Silent Watcher", "The Broken Sword", "The Painted Veil", "The Final Stand", "The Glass Tower", "The Hidden Truth", "The Crimson Tide",
        "The Wandering Mind", "The Iron Will", "The Winter’s Tale", "The Golden Cage", "The Sapphire Ring", "The Broken Bridge", "The Emerald Crown", "The Phantom’s Curse", "The Moonlit Garden", "The Secret Passage",
        "The Enchanted Mirror", "The Distant Land", "The Firefly’s Dance", "The Shadow’s Call", "The Whispering Leaves", "The Forgotten Tale", "The Midnight Song", "The Hidden Fortress", "The Silver Arrow", "The Last Hope",
        "The Wandering Spirit", "The Crystal Palace", "The Secret Island", "The Golden Dream", "The Lost Letter", "The Silent River", "The Broken Chain", "The Painted Moon", "The Final Quest", "The Glass Garden",
        "The Hidden Gem", "The Crimson Forest", "The Wandering Wolf", "The Iron Throne", "The Winter’s Night", "The Golden Bridge", "The Sapphire Crown", "The Broken Promise", "The Emerald Forest", "The Phantom’s Shadow",
        "The Moonlit Path", "The Secret Kingdom", "The Enchanted Castle", "The Distant Echo", "The Fire and Ice", "The Shadow’s Game", "The Whispering Shadows", "The Forgotten Hero", "The Midnight Hour", "The Hidden Treasure"
    };

    std::string authorNames[100] = {
    "Alice Smith", "Bob Johnson", "Carol Williams", "David Brown", "Emily Jones", "Frank Miller", "Grace Davis", "Henry Wilson", "Irene Moore", "Jack Taylor",
    "Karen Anderson", "Larry Thomas", "Monica Jackson", "Nathan White", "Olivia Harris", "Paul Martin", "Quinn Thompson", "Rachel Garcia", "Steve Martinez", "Tina Robinson",
    "Uma Clark", "Victor Rodriguez", "Wendy Lewis", "Xavier Lee", "Yolanda Walker", "Zachary Hall", "Amber Allen", "Brian Young", "Chloe King", "Derek Wright",
    "Ella Scott", "Felix Green", "Gina Adams", "Harold Baker", "Isla Nelson", "Jason Carter", "Kelly Mitchell", "Liam Perez", "Mia Roberts", "Noah Turner",
    "Owen Phillips", "Paige Campbell", "Quinn Parker", "Riley Evans", "Sara Edwards", "Tyler Collins", "Ursula Stewart", "Vince Sanchez", "Willow Morris", "Xander Rogers",
    "Yasmine Reed", "Zane Cook", "April Morgan", "Ben Bell", "Clara Murphy", "Dean Bailey", "Eva Rivera", "Finn Cooper", "Gemma Richardson", "Hugo Cox",
    "Ivy Howard", "Jake Ward", "Kate Torres", "Leo Peterson", "Maya Gray", "Nick Ramirez", "Opal James", "Peter Watson", "Quinn Brooks", "Rose Kelly",
    "Sam Sanders", "Tessa Price", "Uri Bennett", "Vera Wood", "Wade Barnes", "Xena Ross", "Yara Henderson", "Zeke Coleman", "Abby Jenkins", "Blake Perry",
    "Cassie Powell", "Dylan Long", "Elise Patterson", "Freddie Hughes", "Gwen Flores", "Hank Simmons", "Ingrid Foster", "Joel Butler", "Kara Bryant", "Logan Alexander",
    "Molly Russell", "Nate Griffin", "Olive Hayes", "Preston Myers", "Quinn Bishop", "Ruby Stone", "Sean Warren", "Tara Chapman", "Ulysses Hart", "Violet Armstrong"
    };

    std::string publishers[100] = {
    "HarperCollins", "Penguin Random House", "Simon & Schuster", "Hachette Book Group", "Macmillan Publishers",
    "Scholastic", "Bloomsbury", "Oxford University Press", "Cambridge University Press", "Pearson",
    "Wiley", "Springer", "McGraw-Hill", "Cengage", "Elsevier",
    "SAGE Publications", "Taylor & Francis", "Johns Hopkins University Press", "MIT Press", "Dover Publications",
    "Vintage Books", "Crown Publishing", "Knopf", "Little, Brown and Company", "Farrar, Straus and Giroux",
    "Grove Atlantic", "Algonquin Books", "Beacon Press", "Graywolf Press", "Europa Editions", "Tor Books",
    "St. Martin's Press", "Avon Books", "Ballantine Books", "Bantam Books", "Berkley Books",
    "Del Rey", "Dutton", "Ecco", "Grand Central Publishing", "G.P. Putnam's Sons",
    "Harcourt", "Houghton Mifflin", "Hyperion", "Kensington Publishing", "Mariner Books",
    "Minotaur Books", "Mira Books", "Mulholland Books", "New Directions", "Orbit Books",
    "Pantheon Books", "Picador", "Plume", "Portfolio", "PublicAffairs",
    "Riverhead Books", "Scribner", "Seal Press", "Seven Stories Press", "Soho Press",
    "Sourcebooks", "Spiegel & Grau", "Sterling Publishing", "Thomas Nelson", "Thames & Hudson",
    "Viking Press", "William Morrow", "Workman Publishing", "Zondervan", "Chronicle Books",
    "Disney-Hyperion", "Abrams Books", "Andrews McMeel Publishing", "Arcadia Publishing", "Blackstone Publishing",
    "Candlewick Press", "Counterpoint Press", "Da Capo Press", "Flatiron Books", "Gibbs Smith",
    "Grove Press", "Hanover Square Press", "Harlequin", "Head of Zeus", "Kogan Page",
    "Liveright Publishing", "Melville House", "New Press", "No Starch Press", "Other Press",
    "Quirk Books", "Red Hen Press", "Restless Books", "Skyhorse Publishing", "Sourcebooks Landmark",
    "Tin House Books", "Verso Books", "W.W. Norton & Company", "Yale University Press"
    };


    srand(static_cast<unsigned int>(time(0)));
    int bookCount = rand() % 100 + 1;    

    BookType books[MAX_BOOKS];

    for (int i = 0; i < MAX_BOOKS; i++) {
        int yearPublished = rand() % (2025 - 1900 + 1) + 1900;
        std::string bookTitle = title[rand() % 100];
        int numAuthors = rand() % 4 + 1; // Random number of authors between 1 and 4
        std::string* bookAuthors = new std::string[numAuthors];
        for (int j = 0; j < numAuthors; j++) {
            bookAuthors[j] = authorNames[rand() % 100];
        }
        std::string publisher = publishers[rand() % 100];
        std::string isbn = std::to_string(rand() % 900 + 100) + "-" + std::to_string(rand() % 9) + "-" + std::to_string(rand() % 90 + 10) + "-" + std::to_string(rand() % 900000 + 100000) + "-" + std::to_string(rand() % 9);
        double price = static_cast<double>(rand() % 5000) / 100.0;
        int numCoppies = rand() % 100 + 1;
        books[i].setBookInfo(yearPublished, bookTitle, numAuthors, bookAuthors, publisher, isbn, price, numCoppies);

        // Insert into BST using getters
        BookType tempBook;
        tempBook.setBookInfo(yearPublished, bookTitle, numAuthors, bookAuthors, publisher, isbn, price, numCoppies);
        bst.insert(tempBook);
        delete[] bookAuthors;
    }


    cout << "\nISBNs in BST (in order):\n";
    bst.inorder([](const BookType& b) { cout << b.getISBN() << endl; });


    for (int i = 0; i < MAX_BOOKS; i++)
    {
    books[i].printBookInfo();
    }

    cout << "Done" << endl;


    return 0; 
}