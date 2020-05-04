#include <iostream>
#include <cstdlib>
#include "QueueCLL.h"
using namespace std;

int main()
{
   QueueCLL q1, q2, q3, q4, q5;
   int i;
   int n;

   cout << "Enter the number of integers to put on the queue: " ;
   cin >> n;

   // Fill the queues with numbers 1 - 5
   // testing push()
   for(i = 1; i <= n; i++)
   {
      q1.push(i);
      q2.push(i);
      q3.push(i);
      q4.push(i);
   }

   // testing size()
   cout << "size of q1 is " << q1.size() << endl;

   // testing empty(), front() and pop()
   while(!q1.empty())
   {
      cout << q1.front() << ' ';
      q1.pop();
   }

   cout << endl;

   // testing peek()
   if ( ! q2.empty() )
   {
      cout << q2.peek(2) << endl;
      cout << q2.peek(4) << endl;
      cout << q2.peek(12) << endl;
      cout << endl;
   }

   // testing operator=
   q5 = q4;
   while( ! q5.empty() )
   {
      cout << q5.front() << ' ';
      q5.pop();
   }

   cout << endl;

   // testing copy constructor
   QueueCLL q6(q4);
   while( ! q4.empty() )
   {
      cout << q4.front() << ' ';
      q4.pop();
   }

   cout << endl;

   return EXIT_SUCCESS;
}
