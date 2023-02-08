#include <iostream>
#include "BST.h"

using namespace std;

int main() 
{

	
 	BST *BST_Obj = new BST();
	BST_Obj->insert(5);
	BST_Obj->insert(3);
	BST_Obj->insert(7);
	BST_Obj->insert(1);
	BST_Obj->insert(4);
	BST_Obj->insert(6);
	BST_Obj->insert(10);
	BST_Obj->insert(2);
	BST_Obj->insert(9);
	BST_Obj->insert(11);
	BST_Obj->insert(8);
	BST_Obj->printBST();
	delete BST_Obj;

	BST* Tree = new BST();
	Tree->insert(6);
	Tree->insert(2);
	Tree->insert(9);
	Tree->insert(1);
	Tree->insert(4);
	Tree->insert(7);
	Tree->insert(3);
	Tree->insert(5);
	Tree->insert(8);
	return 0;
}