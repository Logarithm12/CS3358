// FILE: IntSet.cpp - header file for IntSet class
//       Implementation file for the IntStore class
//       (See IntSet.h for documentation.)
// INVARIANT for the IntSet class:
// (1) Distinct int values of the IntSet are stored in a 1-D,
//     compile-time array whose size is IntSet::MAX_SIZE;
//     the member variable data references the array.
// (2) The distinct int value with earliest membership is stored
//     in data[0], the distinct int value with the 2nd-earliest
//     membership is stored in data[1], and so on.
//     Note: No "prior membership" information is tracked; i.e.,
//           if an int value that was previously a member (but its
//           earlier membership ended due to removal) becomes a
//           member again, the timing of its membership (relative
//           to other existing members) is the same as if that int
//           value was never a member before.
//     Note: Re-introduction of an int value that is already an
//           existing member (such as through the add operation)
//           has no effect on the "membership timing" of that int
//           value.
// (4) The # of distinct int values the IntSet currently contains
//     is stored in the member variable used.
// (5) Except when the IntSet is empty (used == 0), ALL elements
//     of data from data[0] until data[used - 1] contain relevant
//     distinct int values; i.e., all relevant distinct int values
//     appear together (no "holes" among them) starting from the
//     beginning of the data array.
// (6) We DON'T care what is stored in any of the array elements
//     from data[used] through data[IntSet::MAX_SIZE - 1].
//     Note: This applies also when the IntSet is empry (used == 0)
//           in which case we DON'T care what is stored in any of
//           the data array elements.
//     Note: A distinct int value in the IntSet can be any of the
//           values an int can represent (from the most negative
//           through 0 to the most positive), so there is no
//           particular int value that can be used to indicate an
//           irrelevant value. But there's no need for such an
//           "indicator value" since all relevant distinct int
//           values appear together starting from the beginning of
//           the data array and used (if properly initialized and
//           maintained) should tell which elements of the data
//           array are actually relevant.

#include "IntSet.h"
#include <iostream>
#include <cassert>
using namespace std;

IntSet::IntSet()
{
   data[MAX_SIZE] = {};
   used = 0;
}

int IntSet::size() const // implemented
{
   return used;
}

bool IntSet::isEmpty() const // implemented
{
   return used == 0;
}

bool IntSet::contains(int anInt) const // implemented
{
   bool isContained = false;
   int i;
   for (i = 0; i < used; i++)
   {
      if (data[i] == anInt)
         isContained = true;
   }

   return isContained;
}

bool IntSet::isSubsetOf(const IntSet &otherIntSet) const
{
   cout << "isSubsetOf() is not implemented yet..." << endl;
   return false; // dummy value returned
}

void IntSet::DumpData(ostream &out) const
{ // already implemented ... DON'T change anything
   if (used > 0)
   {
      out << data[0];
      for (int i = 1; i < used; ++i)
         out << "  " << data[i];
   }
}

IntSet IntSet::unionWith(const IntSet &otherIntSet) const
{
   cout << "unionWith() is not implemented yet..." << endl;
   return IntSet(); // dummy IntSet object returned
}

IntSet IntSet::intersect(const IntSet &otherIntSet) const
{
   cout << "intersect() is not implemented yet..." << endl;
   return IntSet(); // dummy IntSet object returned
}

IntSet IntSet::subtract(const IntSet &otherIntSet) const
{
   cout << "subtract() is not implemented yet..." << endl;
   return IntSet(); // dummy IntSet object returned
}

void IntSet::reset() // implemented
{
   used = 0;
}

bool IntSet::add(int anInt) // implemented
{
   bool isAdded{false};
   bool isValidtoAdd{true};
   int i{};
   if (used < MAX_SIZE)
   {
      isValidtoAdd = !(contains(anInt));
   }
   if (isValidtoAdd)
   {
      data[used] = anInt;
      ++used;
      isAdded = true;
   }
   return isAdded;
}

bool IntSet::remove(int anInt) // implemented
{
   bool isRemoved{false};
   bool isValidtoRemove{true};
   int i{};
   if (used > 0)
   {
      isValidtoRemove = contains(anInt);
   }
   if (isValidtoRemove)
   {
      for (i = 0; i < used; ++i)
      {
         if (data[i] == anInt)
         {
            if (used != 1)
            {
               int temp{};
               temp = data[used - 1];
               data[used - 1] = data[i];
               data[i] = temp;
               --used;
               isRemoved = true;
            }
            else
            {
               --used;
               isRemoved = true;
            }
         }
      }
   }
   return isRemoved;
}

bool equal(const IntSet &is1, const IntSet &is2)
{
   cout << "equal() is not implemented yet..." << endl;
   return false; // dummy value returned
}
