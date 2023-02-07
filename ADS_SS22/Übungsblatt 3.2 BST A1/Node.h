#pragma once
class Treenode
{
public:
	int item; // Daten
	int height; // Höhe des Knoten
	Treenode* left; // linker Nachfolgeknoten
	Treenode* right; // rechter Nachfolgeknoten
	Treenode() {};
	Treenode(int key) { Treenode *newNode = new Treenode(key); }
};
