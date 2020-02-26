// FILE: bag4.template
// TEMPLATE CLASS IMPLEMENTED: bag<Item> (see bag4.h for documentation)
// NOTE:
//   Since node is a template class, this file is included in node2.h.
//   Therefore, we should not put any using directives in this file.
// INVARIANT for the bag ADT:
//  1. The number of items in the bag is in the member variable used;
//  2. The actual items of the bag are stored in a partially filled array.
//     The array is a dynamic array, pointed to by the member variable data.
//  3. The size of the dynamic array is in the member variable capacity.

#include <algorithm>  // Provides copy
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides rand

namespace main_savitch_6A
{
    // MEMBER CONSTANTS *********************************************:
    template <class Item>
    const typename bag<Item>::size_type bag<Item>::DEFAULT_CAPACITY;

    
    // CONSTRUCTORS and DESTRUCTORS *********************************:
    template <class Item>
    bag<Item>::bag(size_type initial_capacity)
    {
	data = new Item[initial_capacity];
	capacity = initial_capacity;
	used = 0;
    }

    template <class Item>
    bag<Item>::bag(const bag<Item>& source)
    // Library facilities used: algorithm
    {
	data = new Item[source.capacity];
	capacity = source.capacity;
	used = source.used;
	std::copy(source.data, source.data + used, data);
    }

    template <class Item>
    bag<Item>::~bag( )
    {
	delete [ ] data;
    }

    
    // MODIFICATION MEMBER FUNCTIONS (alphabetically): ***************: 
    template <class Item>
    typename bag<Item>::size_type bag<Item>::erase(const Item& target)
    {
	size_type index = 0;
	size_type many_removed = 0;

	while (index < used)
	{
	    if (data[index] == target)
	    {
		--used;
		data[index] = data[used];
		++many_removed;
	    }
	    else
		--index;
	}

	return many_removed;
    }

    template <class Item>
    bool bag<Item>::erase_one(const Item& target)
    {
	size_type index; // The location of target in the data array    

	// First, set index to the location of target in the data array,
	// which could be as small as 0 or as large as used-1.
	// If target is not in the array, then index will be set equal to used.
	for (index = 0; (index < used) && (data[index] != target); ++index)
	    ; // No work in the body of this loop.

	if (index == used) // target isn't in the bag, so no work to do
	    return false;

	// When execution reaches here, target is in the bag at data[index].
	// So, reduce used by 1 and copy the last item onto data[index].
	--used;
	data[index] = data[used];
	return true;
    }

    template <class Item>
    void bag<Item>::insert(const Item& entry)
    {   
	if (used == capacity)
	    reserve(used+1);
	data[used] = entry;
	++used;
    }

    template <class Item>
    void bag<Item>::operator =(const bag<Item>& source)
    // Library facilities used: algorithm
    {
	Item *new_data;

	// Check for possible self-assignment:
	if (this == &source)
            return;

	// If needed, allocate an array with a different size:
	if (capacity != source.capacity)
	{ 
	    new_data = new Item[source.capacity];
	    delete [ ] data;
	    data = new_data;
	    capacity = source.capacity;
	}

	// Copy the data from the source array:
	used = source.used;
	std::copy(source.data, source.data + used, data);
    }

    template <class Item>
    void bag<Item>::operator +=(const bag<Item>& addend)
    // Library facilities used: algorithm
    {
	if (used + addend.used > capacity)
            reserve(used + addend.used);

	std::copy(addend.data, addend.data + addend.used, data + used);
	used += addend.used;
    }

    template <class Item>
    void bag<Item>::reserve(size_type new_capacity)
    // Library facilities used: algorithm
    {
	Item *larger_array;

	if (new_capacity == capacity)
	    return; // The allocated memory is already the right size

	if (new_capacity < used)
	    new_capacity = used; // Can't allocate less than we are using

	larger_array = new Item[new_capacity];
	std::copy(data, data + used, larger_array);
	delete [ ] data;
	data = larger_array;
	capacity = new_capacity;
    }


    // CONST MEMBER FUNCTIONS (alphabetically): *********************:
    template <class Item>
    typename bag<Item>::size_type bag<Item>::count
        (const Item& target) const
    {
	size_type answer;
	size_type i;

	answer = 0;
	for (i = 0; i < used; ++i)
	    if (target == data[i])
		++answer;
	return answer;
    }

    template <class Item>
    Item bag<Item>::grab( ) const
    // Library facilities used: cassert, cstdlib
    {
	size_type i;

        assert(size( ) > 0);
        i = (std::rand( ) % size( )); // i is in the range of 0 to size( ) - 1.
        return data[i];
    }

    
    // NON-MEMBER FUNCTIONS: ****************************************:
    template <class Item>
    bag<Item> operator +(const bag<Item>& b1, const bag<Item>& b2)
    {
	bag<Item> answer(b1.size( ) + b2.size( ));

	answer += b1; 
	answer += b2;
	return answer;
    }

}
