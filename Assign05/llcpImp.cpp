#include <iostream>
#include <cstdlib>
#include "llcpInt.h"
using namespace std;

int FindListLength(Node *headPtr)
{
   int length = 0;

   while (headPtr != 0)
   {
      ++length;
      headPtr = headPtr->link;
   }

   return length;
}

bool IsSortedUp(Node *headPtr)
{
   if (headPtr == 0 || headPtr->link == 0) // empty or 1-node
      return true;
   while (headPtr->link != 0) // not at last node
   {
      if (headPtr->link->data < headPtr->data)
         return false;
      headPtr = headPtr->link;
   }
   return true;
}

void InsertAsHead(Node *&headPtr, int value)
{
   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   newNodePtr->link = headPtr;
   headPtr = newNodePtr;
}

void InsertAsTail(Node *&headPtr, int value)
{
   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   newNodePtr->link = 0;
   if (headPtr == 0)
      headPtr = newNodePtr;
   else
   {
      Node *cursor = headPtr;

      while (cursor->link != 0) // not at last node
         cursor = cursor->link;
      cursor->link = newNodePtr;
   }
}

void InsertSortedUp(Node *&headPtr, int value)
{
   Node *precursor = 0,
        *cursor = headPtr;

   while (cursor != 0 && cursor->data < value)
   {
      precursor = cursor;
      cursor = cursor->link;
   }

   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   newNodePtr->link = cursor;
   if (cursor == headPtr)
      headPtr = newNodePtr;
   else
      precursor->link = newNodePtr;

   ///////////////////////////////////////////////////////////
   /* using-only-cursor (no precursor) version
   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   //newNodePtr->link = 0;
   //if (headPtr == 0)
   //   headPtr = newNodePtr;
   //else if (headPtr->data >= value)
   //{
   //   newNodePtr->link = headPtr;
   //   headPtr = newNodePtr;
   //}
   if (headPtr == 0 || headPtr->data >= value)
   {
      newNodePtr->link = headPtr;
      headPtr = newNodePtr;
   }
   //else if (headPtr->link == 0)
   //   head->link = newNodePtr;
   else
   {
      Node *cursor = headPtr;
      while (cursor->link != 0 && cursor->link->data < value)
         cursor = cursor->link;
      //if (cursor->link != 0)
      //   newNodePtr->link = cursor->link;
      newNodePtr->link = cursor->link;
      cursor->link = newNodePtr;
   }

   ////////////////// commented lines removed //////////////////

   Node *newNodePtr = new Node;
   newNodePtr->data = value;
   if (headPtr == 0 || headPtr->data >= value)
   {
      newNodePtr->link = headPtr;
      headPtr = newNodePtr;
   }
   else
   {
      Node *cursor = headPtr;
      while (cursor->link != 0 && cursor->link->data < value)
         cursor = cursor->link;
      newNodePtr->link = cursor->link;
      cursor->link = newNodePtr;
   }
   */
   ///////////////////////////////////////////////////////////
}

bool DelFirstTargetNode(Node *&headPtr, int target)
{
   Node *precursor = 0,
        *cursor = headPtr;

   while (cursor != 0 && cursor->data != target)
   {
      precursor = cursor;
      cursor = cursor->link;
   }
   if (cursor == 0)
   {
      cout << target << " not found." << endl;
      return false;
   }
   if (cursor == headPtr) //OR precursor == 0
      headPtr = headPtr->link;
   else
      precursor->link = cursor->link;
   delete cursor;
   return true;
}

bool DelNodeBefore1stMatch(Node *&headPtr, int target)
{
   if (headPtr == 0 || headPtr->link == 0 || headPtr->data == target)
      return false;
   Node *cur = headPtr->link, *pre = headPtr, *prepre = 0;
   while (cur != 0 && cur->data != target)
   {
      prepre = pre;
      pre = cur;
      cur = cur->link;
   }
   if (cur == 0)
      return false;
   if (cur == headPtr->link)
   {
      headPtr = cur;
      delete pre;
   }
   else
   {
      prepre->link = cur;
      delete pre;
   }
   return true;
}

void ShowAll(ostream &outs, Node *headPtr)
{
   while (headPtr != 0)
   {
      outs << headPtr->data << "  ";
      headPtr = headPtr->link;
   }
   outs << endl;
}

void FindMinMax(Node *headPtr, int &minValue, int &maxValue)
{
   if (headPtr == 0)
   {
      cerr << "FindMinMax() attempted on empty list" << endl;
      cerr << "Minimum and maximum values not set" << endl;
   }
   else
   {
      minValue = maxValue = headPtr->data;
      while (headPtr->link != 0)
      {
         headPtr = headPtr->link;
         if (headPtr->data < minValue)
            minValue = headPtr->data;
         else if (headPtr->data > maxValue)
            maxValue = headPtr->data;
      }
   }
}

double FindAverage(Node *headPtr)
{
   if (headPtr == 0)
   {
      cerr << "FindAverage() attempted on empty list" << endl;
      cerr << "An arbitrary zero value is returned" << endl;
      return 0.0;
   }
   else
   {
      int sum = 0,
          count = 0;

      while (headPtr != 0)
      {
         ++count;
         sum += headPtr->data;
         headPtr = headPtr->link;
      }

      return double(sum) / count;
   }
}

void ListClear(Node *&headPtr, int noMsg)
{
   int count = 0;

   Node *cursor = headPtr;
   while (headPtr != 0)
   {
      headPtr = headPtr->link;
      delete cursor;
      cursor = headPtr;
      ++count;
   }
   if (noMsg)
      return;
   clog << "Dynamic memory for " << count << " nodes freed"
        << endl;
}

// definition of MakeTargetExistOnlyOnceAtTail of Assignment 5 Part 1
void MakeTargetExistOnlyOnceAtTail(Node *&headPtr, int target)
{
   Node *cursor{headPtr}, *precursor{headPtr}, *movedNode{0};
   bool isInList{false}, targetAtHead{false}, aDeleteHappened{false};
   std::cout << "target is " << target << " and list is " << endl;
   ShowAll(std::cout, headPtr);

   while (headPtr != 0 && cursor != 0)
   {
      aDeleteHappened = false;
      std::cout << endl
                << "new loop iteration" << endl;
      std::cout << "start of loop cursor->data = " << cursor->data << endl;

      if (cursor->data == target)
      {
         if (!isInList)
         {
            std::cout << "triggered_0" << endl;
            isInList = true;
            if (cursor == headPtr)
            {
               movedNode = cursor;
               targetAtHead = true;
            }
            else
            {
               movedNode = cursor;
               precursor->link = cursor->link;
               cursor = precursor;
            }
         }
         //if there is another instance of the target, delete it
         else if (isInList)
         {
            if (cursor->link == 0)
            {
               std::cout << "called32" << endl;
               Node *tmpPtr = cursor;
               precursor->link = 0;
               delete tmpPtr;
               cursor = precursor;
            }
            else
            {
               std::cout << "triggered_delete" << endl;
               std::cout << "before delete precursor->data = " << precursor->data << endl;
               std::cout << "before delete cursor->data = " << cursor->data << endl;

               Node *tmpPtr = cursor;
               precursor->link = cursor->link;
               aDeleteHappened = true;
               cursor = cursor->link;
               delete tmpPtr;

               ShowAll(std::cout, headPtr);
               std::cout << "in delete precursor->data = " << precursor->data << endl;
               std::cout << "in delete cursor->data = " << cursor->data << endl;
            }
         }
      }
      if (aDeleteHappened && cursor->link == 0 && cursor->data == target)
      {
         std::cout << "called" << endl;
         Node *tmpPtr = cursor;
         precursor->link = 0;
         delete tmpPtr;
         cursor = precursor;
      }

      //if the target isn't in the list, make a node and add it at the end
      if (cursor->link == 0 && isInList == false)
      {
         std::cout << "triggered_1" << endl;
         Node *added = new Node;
         added->data = target;
         added->link = 0;
         cursor->link = added;
         cursor = added;
      }

      //if the target is at the head, move it to the end of the list
      if (cursor->link == 0 && isInList == true && targetAtHead == true)
      {
         std::cout << "triggered_2" << endl;
         if (headPtr->link != 0)
         {
            headPtr = headPtr->link;
            cursor->link = movedNode;
            movedNode->link = 0;
            cursor = movedNode;
         }
         break;
      }

      //if the target is not at the head, move it to the end
      if (cursor->link == 0 && isInList == true && targetAtHead == false)
      {
         std::cout << "triggered_3" << endl;
         if (precursor->link == 0)
         {
            precursor->link = movedNode;
            movedNode->link = 0;
            cursor = movedNode;
         }
         else
         {
            cursor->link = movedNode;
            movedNode->link = 0;
            cursor = movedNode;
         }
         break;
      }

      std::cout << "precursor->data = " << precursor->data << endl;
      std::cout << "cursor->data = " << cursor->data << endl;

      if (cursor != precursor && precursor->link != 0 && !aDeleteHappened)
         precursor = precursor->link;

      std::cout << "showing list at end of iteration" << endl;
      ShowAll(std::cout, headPtr);

      if (!aDeleteHappened && cursor != 0)
      {
         cursor = cursor->link;
         std::cout << "cursor = " << cursor << endl;
      }
   }

   std::cout << "list after the loop" << endl;
   ShowAll(std::cout, headPtr);

   //if the list is empty, make a node and add it
   if (headPtr == 0)
   {
      std::cout << "triggered_4" << endl;
      Node *added = new Node;
      added->data = target;
      added->link = 0;
      headPtr = added;
   }
}
