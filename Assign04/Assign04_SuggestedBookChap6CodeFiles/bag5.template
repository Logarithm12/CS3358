// FILE: bag5.template
// CLASS implemented: bag (see bag5.h for documentation)
// NOTE:
//   Since bag is a template class, this file is included in node2.h.
// INVARIANT for the bag class:
//   1. The items in the bag are stored on a linked list;
//   2. The head pointer of the list is stored in the member variable head_ptr;
//   3. The total number of items in the list is stored in the member variable
//       many_nodes.

#include <cassert>  // Provides assert
#include <cstdlib>  // Provides NULL, rand
#include "node2.h"  // Provides node 

namespace main_savitch_6B
{
    template <class Item>
    bag<Item>::bag( )
    // Library facilities used: cstdlib
    {
	head_ptr = NULL;
	many_nodes = 0;
    }

    template <class Item>
    bag<Item>::bag(const bag<Item>& source)
    // Library facilities used: node2.h
    {
	node<Item> *tail_ptr;  // Needed for argument of list_copy

	list_copy(source.head_ptr, head_ptr, tail_ptr);
	many_nodes = source.many_nodes;
    }

    template <class Item>
    bag<Item>::~bag( )
    // Library facilities used: node2.h
    {
	list_clear(head_ptr);
	many_nodes = 0;
    }

    template <class Item>
    typename bag<Item>::size_type bag<Item>::count(const Item& target) const
    // Library facilities used: cstdlib, node2.h
    {
	size_type answer;
	const node<Item> *cursor;
	
	answer = 0;
	cursor = list_search(head_ptr, target);
	while (cursor != NULL)
	{
	    // Each time that cursor is not NULL, we have another occurrence of
	    // target, so we add one to answer, and move cursor to the next
	    // occurrence of the target.
	    ++answer;
	    cursor = cursor->link( );
	    cursor = list_search(cursor, target);
	}
	return answer;
    }

    template <class Item>
    typename bag<Item>::size_type bag<Item>::erase(const Item& target)
    // Library facilities used: cstdlib, node2.h
    {
        size_type answer = 0;
        node<Item> *target_ptr;

        target_ptr = list_search(head_ptr, target);
        while (target_ptr != NULL)
        {
            // Each time that target_ptr is not NULL, we have another occurrence
	    // of target. We remove this target using the same technique that
	    // was used in erase_one.
            ++answer;
            target_ptr->set_data( head_ptr->data( ) );
            target_ptr = target_ptr->link( );
            target_ptr = list_search(target_ptr, target);
            list_head_remove(head_ptr);
        }
        return answer;
    }
    
    template <class Item>
    bool bag<Item>::erase_one(const Item& target)
    // Library facilities used: cstdlib, node2.h
    {
	node<Item> *target_ptr;

	target_ptr = list_search(head_ptr, target);
	if (target_ptr == NULL)
	    return false; // target isn't in the bag, so no work to do
	target_ptr->set_data( head_ptr->data( ) );
	list_head_remove(head_ptr);
	--many_nodes;
	return true;
    }

    template <class Item>
    Item bag<Item>::grab( ) const
    // Library facilities used: cassert, cstdlib, node2.h
    {
	size_type i;
	const node<Item> *cursor;

	assert(size( ) > 0);
	i = (std::rand( ) % size( )) + 1;
	cursor = list_locate(head_ptr, i);
	return cursor->data( );
    }

    template <class Item>
    void bag<Item>::insert(const Item& entry)
    // Library facilities used: node2.h
    {
	list_head_insert(head_ptr, entry);
	++many_nodes;
    }

    template <class Item>
    void bag<Item>::operator +=(const bag<Item>& addend)
    // Library facilities used: node2.h
    {
	node<Item> *copy_head_ptr;
	node<Item> *copy_tail_ptr;
	
	if (addend.many_nodes > 0)
	{
	    list_copy(addend.head_ptr, copy_head_ptr, copy_tail_ptr);
	    copy_tail_ptr->set_link( head_ptr ); 
	    head_ptr = copy_head_ptr;
	    many_nodes += addend.many_nodes;
	}
    }
    
    template <class Item>
    void bag<Item>::operator =(const bag<Item>& source)
    // Library facilities used: node2.h
    {
	node<Item> *tail_ptr; // Needed for argument to list_copy

	if (this == &source)
            return;

	list_clear(head_ptr);
	many_nodes = 0;

	list_copy(source.head_ptr, head_ptr, tail_ptr);
	many_nodes = source.many_nodes;
    }

    template <class Item>
    bag<Item> operator +(const bag<Item>& b1, const bag<Item>& b2)
    {
	bag<Item> answer;

	answer += b1; 
	answer += b2;
	return answer;
    }

}
