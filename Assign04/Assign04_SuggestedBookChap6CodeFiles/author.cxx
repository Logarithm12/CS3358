// FILE: author.cxx
// A demonstration program showing how the bag template class is used.
// The program reads some words into bags of Strings, and some numbers into
// a bag of integers. Then a silly story is written using these words.

#include <iostream>   // Provides cout and cin
#include <cstdlib>    // Provides EXIT_SUCCESS
#include <string>     // Provides string class
#include "bag4.h"     // Provides the bag template class
using namespace std;
using namespace main_savitch_6A;

const int ITEMS_PER_BAG = 4;  // Number of items to put into each bag
const int MANY_SENTENCES = 3; // Number of sentences in the silly story

// PROTOTYPE for a function used by this demonstration program
template <class Item, class SizeType, class MessageType>
void get_items(bag<Item>& collection, SizeType n, MessageType description)
// Postcondition: The string description has been written as a prompt to the
// screen. Then n items have been read from cin and added to the collection.
// Library facilities used: iostream, bag4.h
{
    Item user_input; // An item typed by the program's user
    SizeType i;

    cout << "Please type " << n << " " << description;
    cout << ", separated by spaces.\n";
    cout << "Press the <return> key after the final entry:\n";
    for (i = 1; i <= n; ++i)
    {
        cin >> user_input;
        collection.insert(user_input);
    }
    cout << endl;
}

int main( )
{
    bag<string> adjectives;  // Contains adjectives typed by user
    bag<int>    ages;        // Contains ages in the teens typed by user
    bag<string> names;       // Contains names typed by user 
    int line_number;         // Number of the output line

    // Fill the three bags with items typed by the program's user.
    cout << "Help me write a story.\n";
    get_items(adjectives, ITEMS_PER_BAG, "adjectives that describe a mood");
    get_items(ages,       ITEMS_PER_BAG, "integers in the teens");
    get_items(names,      ITEMS_PER_BAG, "first names");
    cout << "Thank you for your kind assistance.\n\n";

    // Use the items to write a silly story.
    cout << "LIFE\n";
    cout << "by A. Computer\n";
    for (line_number = 1; line_number <= MANY_SENTENCES; ++line_number)
        cout << names.grab( )      << " was only " 
             << ages.grab( )       << " years old, but he/she was "
             << adjectives.grab( ) << ".\n";
    cout << "Life is " << adjectives.grab( ) << ".\n";
    cout << "The (" << adjectives.grab( ) << ") end\n";

    return EXIT_SUCCESS;
}

