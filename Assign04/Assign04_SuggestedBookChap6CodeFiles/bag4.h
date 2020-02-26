// FILE: bag4.h (part of the namespace main_savitch_6A)
// TEMPLATE CLASS PROVIDED: bag<item>
//
// TEMPLATE PARAMETER, TYPEDEFS and MEMBER CONSTANTS for the bag<Item> class:
//   The template parameter, Item, is the data type of the items in the bag,
//   also defined as bag<Item>::value_type. It may be any of the C++ built-in
//   types (int, char, etc.), or a class with a default constructor, an
//   assignment operator, and operators to test for equality (x == y) and 
//   non-equality (x != y). The definition bag<Item>::size_type is the data type
//   of any variable that keeps track of how many items are in a bag. The static
//   const DEFAULT_CAPACITY is the initial capacity of a bag created by the
//   default constructor.
// NOTE:
//   Many compilers require the use of the new keyword typename before using
//   the expressions bag<Item>::value_type and bag<Item>::size_type. Otherwise
//   the compiler doesn't have enough information to realize that it is the
//   name of a data type.
//
// CONSTRUCTOR for the bag<Item> template class:
//   bag(size_type initial_capacity = DEFAULT_CAPACITY)
//     Postcondition: The bag is empty with an initial capacity given by the
//     parameter. The insert function will work efficiently (without allocating
//     new memory) until this capacity is reached.
//
// MODIFICATION MEMBER FUNCTIONS for the bag<Item> template class:
//   size_type erase(const Item& target)
//     Postcondition: All copies of target have been removed from the bag. The
//     return value is the number of copies removed (which could be zero).
//
//   bool erase_one(const Item& target)
//     Postcondition: If target was in the bag, then one copy of target has
//     been removed; otherwise the bag is unchanged. A true return value
//     indicates that one copy was removed; false indicates that nothing was
//     removed.
//
//   void insert(const Item& entry)
//     Postcondition: A new copy of entry has been added to the bag.
//
//   void operator +=(const bag<Item>& addend)
//     Postcondition: Each item in addend has been added to this bag.
//
//   void reserve(size_type new_capacity)
//     Postcondition: The bag's current capacity is changed to new_capacity
//     (but not less than the number of items currently in the bag). The insert
//     function will work efficiently without allocating new memory) until the
//     capacity is reached.
//
// CONSTANT MEMBER FUNCTIONS for the bag<Item> template class:
//   size_type count(const Item& target) const
//     Postcondition: Return value is number of times target is in the bag.
//
//   Item grab( ) const
//     Precondition: size( ) > 0
//     Postcondition: The return value is a randomly selected item from the bag.
//
//   size_type size( ) const
//     Postcondition: The return value is the total number of items in the bag.
//
// NONMEMBER FUNCTIONS for the bag<Item> template class:
//   template <class Item>
//   bag<Item> operator +(const bag<Item>& b1, const bag<Item>& b2)
//     Postcondition: The bag returned is the union of b1 and b2.
//
// VALUE SEMANTICS for the bag<Item> template class:
//   Assignments and the copy constructor may be used with bag objects.
//
// DYNAMIC MEMORY USAGE by the bag<Item> template class: 
//   If there is insufficient dynamic memory, then the following functions call
//   new_handler: the constructors, resize, insert, operator += , operator +,
//   and the assignment operator.

#ifndef MAIN_SAVITCH_BAG4_H
#define MAIN_SAVITCH_BAG4_H
#include <cstdlib> // Provides size_t

namespace main_savitch_6A
{
    template <class Item>
    class bag
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
	typedef Item value_type;
	typedef std::size_t size_type;
	static const size_type DEFAULT_CAPACITY = 30;
        // CONSTRUCTORS and DESTRUCTOR
        bag(size_type initial_capacity = DEFAULT_CAPACITY);
        bag(const bag& source);
        ~bag( );
        // MODIFICATION MEMBER FUNCTIONS
        size_type erase(const Item& target);
        bool erase_one(const Item& target);
        void insert(const Item& entry);
        void operator =(const bag& source);
        void operator +=(const bag& addend);
        void reserve(size_type capacity);
        // CONSTANT MEMBER FUNCTIONS
        size_type count(const Item& target) const;
        Item grab( ) const;
        size_type size( ) const { return used; }
    private:
        Item *data;           // Pointer to partially filled dynamic array
        size_type used;       // How much of array is being used
        size_type capacity;   // Current capacity of the bag
    };

    // NONMEMBER FUNCTIONS
    template <class Item>
    bag<Item> operator +(const bag<Item>& b1, const bag<Item>& b2);
}

#include "bag4.template"  // Include the implementation
#endif
