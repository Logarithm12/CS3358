//File QueueCLL.h
// CLASS PROVIDED: QueueCLL (queue)
//
// TYPEDEFS for the QueueCLL class:
//   typedef _____ value_type
//     QueueCLL::value_type is the data type of the items in
//     the QueueCLL. It may be any of the C++ built-in types
//     (int, char, etc.), or a class with a default constructor,
//     a copy constructor, and an assignment operator.
//
//   typedef _____ size_type
//     QueueCLL::size_type is the data type of choice for any
//     quantifier/identifier object whose value is by nature
//     and intent always non-negative (unsigned).
//
// CONSTRUCTOR for the QueueCLL class:
//   QueueCLL()
//     Pre:  (none)
//     Post: The QueueCLL has been initialized to an empty queue.
//
// MODIFICATION MEMBER FUNCTIONS for the QueueCLL class:
//   void push(const value_type& entry)
//     Pre:  (none)
//     Post: A new copy of item with the specified data has been
//           added to the rear of the queue.
//
//   void pop()
//     Pre:  size() > 0.
//     Post: The front item has been removed from the queue.
//
// CONSTANT MEMBER FUNCTIONS for the QueueCLL class:
//   size_type size() const
//     Pre:  (none)
//     Post: The return value is the total number of items in the
//           queue.
//
//   value_type front() const
//     Pre:  size() > 0.
//     Post: The return value is the data of the front item of
//           the queue, but the queue is unchanged.
//
//   bool empty() const
//     Pre:  (none)
//     Post: The return value is true if the queue is empty,
//           otherwise false.
//
//   value_type peek(size_type n) const
//     Pre:  size() > 0.
//     Post: The return value is the data of the n-th item
//           (front item is 1st item) of the queue, with
//           circular wraparound.

// VALUE SEMANTICS for the QueueCLL class:
//   Assignments and the copy constructor may be used with QueueCLL
//   objects.

#ifndef QUEUE_CLL_H
#define QUEUE_CLL_H

#include <cstdlib>  // provides size_t

class QueueCLL
{
   
struct Node
{
    typedef int value_type;
    value_type data;
    Node* link;
};

public:
   //TYPEDEF
   typedef Node::value_type value_type;
   typedef size_t size_type;

   // CONSTRUCTORS and DESTRUCTOR
   QueueCLL();
   QueueCLL(const QueueCLL& src);
   ~QueueCLL();

   // MODIFICATION functions
   void push(const value_type& entry);
   value_type front() const;
   void pop();
   QueueCLL& operator=(const QueueCLL& rhs);

   // CONSTANT functions
   size_type size() const;
   bool empty() const;
   value_type peek(size_type n) const;

private:
   Node *rear_ptr;
   size_type numItems;
};

#endif
