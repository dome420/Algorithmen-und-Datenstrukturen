#pragma once
class Treenode
{
public:
	int item = 0; // Daten
	int height = 0; // Höhe des Knoten
	Treenode* left; // linker Nachfolgeknoten
	Treenode* right; // rechter Nachfolgeknoten
	Treenode() {};
	Treenode(int key) 
	{ 
		this->item = key;
		Treenode *newNode = new Treenode(item); 
		newNode->left = nullptr;
		newNode->right = nullptr;
	}
};
