#include "btNode.h"

void dumpToArrayInOrder(btNode *bst_root, int *dumpArray)
{
   if (bst_root == 0)
      return;
   int dumpIndex = 0;
   dumpToArrayInOrderAux(bst_root, dumpArray, dumpIndex);
}

void dumpToArrayInOrderAux(btNode *bst_root, int *dumpArray, int &dumpIndex)
{
   if (bst_root == 0)
      return;
   dumpToArrayInOrderAux(bst_root->left, dumpArray, dumpIndex);
   dumpArray[dumpIndex++] = bst_root->data;
   dumpToArrayInOrderAux(bst_root->right, dumpArray, dumpIndex);
}

void tree_clear(btNode *&root)
{
   if (root == 0)
      return;
   tree_clear(root->left);
   tree_clear(root->right);
   delete root;
   root = 0;
}

int bst_size(btNode *bst_root)
{
   if (bst_root == 0)
      return 0;
   return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}

// write definition for bst_insert here
void bst_insert(btNode *&bst_root, int insInt)
{
   bool isInserted{false};
   btNode *workPointer = bst_root;

   if (bst_root == nullptr)
   {
      btNode newNode{insInt, nullptr, nullptr};
      bst_root = &newNode;
      isInserted = true;
   }

   while (isInserted == false)
   {
      if (workPointer->data < insInt)
      {
         if (workPointer->left != nullptr)
         {
            workPointer=workPointer->left;
         }
         else
         {
            btNode newNode{insInt, nullptr, nullptr};
            workPointer->left = &newNode;
            isInserted = true;
         }
      }
      else if (workPointer->data == insInt)
      {
         workPointer->data == insInt;
         isInserted = true;
      }
      else if (workPointer->data > insInt)
      {
         if (workPointer->right != nullptr)
         {
            workPointer=workPointer->right;
         }
         else
         {
            btNode newNode{insInt, nullptr, nullptr};
            workPointer->right = &newNode;
            isInserted = true;
         }
      }
   }
}

// write definition for bst_remove here
bool bst_remove(btNode *&bst_root, int remInt)
{
   bool isRemoved{false};

}

// write definition for bst_remove_max here
void bst_remove_max(btNode *&)
