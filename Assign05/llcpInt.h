#ifndef ASSIGN05P1_H
#define ASSIGN05P1_H

#include <iostream>

struct Node
{
   int data;
   Node *link;
};

int    FindListLength(Node* headPtr);
bool   IsSortedUp(Node* headPtr);
void   InsertAsHead(Node*& headPtr, int value);
void   InsertAsTail(Node*& headPtr, int value);
void   InsertSortedUp(Node*& headPtr, int value);
bool   DelFirstTargetNode(Node*& headPtr, int target);
bool   DelNodeBefore1stMatch(Node*& headPtr, int target);
void   ShowAll(std::ostream& outs, Node* headPtr);
void   FindMinMax(Node* headPtr, int& minValue, int& maxValue);
double FindAverage(Node* headPtr);
void   ListClear(Node*& headPtr, int noMsg = 0);

// prototype of MakeTargetExistOnlyOnceAtTail of Assignment 5 Part 1
void MakeTargetExistOnlyOnceAtTail(Node*& headPtr, int target);
#endif
