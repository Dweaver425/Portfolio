#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "BookType.h"
#include <iostream>

using namespace std;

int main() 
{

    string authorNames[100] = {
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


    srand(static_cast<unsigned int>(time(0)));
    int bookCount = rand() % 100 + 1;    
    cout << "Random number of books: " << bookCount << endl;
