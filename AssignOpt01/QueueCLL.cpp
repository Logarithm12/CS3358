// FILE: QueueCLL.cpp
// IMPLEMENTS: QueueCLL (see QueueCLL.h for documentation.)
//
// INVARIANT for the QueueCLL class:
//   1. The number of items in the QueueCLL is stored in the member
//      variable numItems.
//   2. The items themselves are stored in a circular linked list
//      of Nodes.
//      2.1 The member variable rear_ptr points to the rear of the
//          QueueCLL (tail node of the circular linked list).
//      2.2 The rear_ptr is set to the null address if the circular
//          linked list (thus queue) is empty.

#include <iostream>
#include <cassert> // provides assert
#include <cstdlib> // provides size_t
using namespace std;

#include "QueueCLL.h"

QueueCLL::QueueCLL() : numItems(0)
{
}

QueueCLL::QueueCLL(const QueueCLL &src) : numItems(src.numItems)
{
   if (src.rear_ptr != nullptr)
   {
      if (src.numItems == 1)
      {
         Node *rearfront = new Node();
         rearfront->data = src.rear_ptr->data;
         rearfront->link = rearfront;
         rear_ptr = rearfront;
      }
      else
      {
         Node *srcIter = src.rear_ptr, *thisIter;
         Node *firstEntry = new Node();
         firstEntry->data = srcIter->data;
         thisIter = firstEntry;
         rear_ptr = firstEntry;
         srcIter = srcIter->link;
         while (srcIter != src.rear_ptr)
         {
            Node *newNode = new Node();
            newNode->data = srcIter->data;
            thisIter->link = newNode;
            thisIter = newNode;
            srcIter = srcIter->link;
         }
         thisIter->link = rear_ptr;
      }
   }
}

QueueCLL::~QueueCLL()
{
   if (rear_ptr != nullptr)
   {
      Node *p, *temp;
      p = rear_ptr->link;
      rear_ptr->link = nullptr;
      while (p != nullptr)
      {
         temp = p->link;
         free(p);
         p = temp;
      }
   }
}

QueueCLL &QueueCLL::operator=(const QueueCLL &rhs)
{
   if (this != &rhs)
   {
      if (rhs.rear_ptr != nullptr)
      {
         if (rhs.numItems == 1)
         {
            Node *rearfront = new Node();
            rearfront->data = rhs.rear_ptr->data;
            rearfront->link = rearfront;
            this->~QueueCLL();
            rear_ptr = rearfront;
            this->numItems = rhs.numItems;
         }
         else
         {
            Node *srcIter = rhs.rear_ptr, *thisIter, *newPtr;
            Node *firstEntry = new Node();
            firstEntry->data = srcIter->data;
            thisIter = firstEntry;
            newPtr = firstEntry;
            srcIter = srcIter->link;
            while (srcIter != rhs.rear_ptr)
            {
               Node *newNode = new Node();
               newNode->data = srcIter->data;
               thisIter->link = newNode;
               thisIter = newNode;
               srcIter = srcIter->link;
            }
            thisIter->link = newPtr;
            this->~QueueCLL();
            rear_ptr = newPtr;
            this->numItems = rhs.numItems;
         }
      }
   }
   return *this;
}

void QueueCLL::push(const value_type &entry)
{
   Node *newEntry = new Node();
   newEntry->data = entry;

   if (numItems == 0)
   {
      newEntry->link = rear_ptr;
      rear_ptr = newEntry;
      rear_ptr->link = newEntry;
      ++numItems;
   }
   else
   {
      newEntry->link = rear_ptr->link;
      rear_ptr->link = newEntry;
      rear_ptr = newEntry;
      ++numItems;
   }
}

QueueCLL::value_type QueueCLL::front() const
{
   return rear_ptr->link->data;
}

void QueueCLL::pop()
{
   assert(numItems > 0);
   if (numItems == 1)
   {
      free(rear_ptr);
      rear_ptr = 0;
      --numItems;
   }
   else
   {
      Node *temp = rear_ptr->link;
      rear_ptr->link = temp->link;
      free(temp);
      temp = nullptr;
      --numItems;
   }
}

QueueCLL::size_type QueueCLL::size() const
{
   return numItems;
}

bool QueueCLL::empty() const
{
   return numItems == 0;
}

QueueCLL::value_type QueueCLL::peek(size_type n) const
{
   Node *iter = rear_ptr;
   for (int i = 0; i < n; ++i)
      iter = iter->link;

   return iter->data;
}
