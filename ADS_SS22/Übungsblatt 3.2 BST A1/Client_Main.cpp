#include <iostream>
#include "BST.h"

using namespace std;

int main() {

	/*
	* Aufgabe B) 
	*	- Erzeuge Sie eine Instanz für einen BST Baumes.  -> Erstelle Ein Objekt BST
	*/

	BST BST_Obj;
	BST_Obj.insert(5);
	BST_Obj.insert(3);
	BST_Obj.insert(7);
	BST_Obj.insert(1);
	BST_Obj.insert(4);
	BST_Obj.insert(6);
	BST_Obj.insert(10);
	BST_Obj.insert(2);
	BST_Obj.insert(9);
	BST_Obj.insert(11);
	BST_Obj.insert(8);
	BST_Obj.printBST();
	BST_Obj.~BST();
	return 0;
}