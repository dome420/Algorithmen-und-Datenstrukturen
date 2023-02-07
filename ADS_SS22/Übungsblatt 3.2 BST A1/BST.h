#pragma once

#include "Node.h"

class BST 
{
private:
	Treenode* head;
	int computeHeight(Treenode* p); // rekursive Methode,berechnet die H�he zum Knoten p und gibt diese zur�ck
	void deleteBST(Treenode* p); // l�scht den Teilbaum ab p // rekursive Methode zur Ausgabe aller Knoten zu einer H�he
	int printHeight(Treenode* node, int height);
public:
	BST() 
	{
		head = new Treenode;
		head->right = nullptr;  
		head->left = nullptr;
	};
	~BST();
	void insert(int key);
	int getBSTHeight(); // Starterfunktion f�r die rekursive Methode und liefert die H�he des Baumes zur�ck
	void printBST(); // Ausgabe des BST in Levelorder
	void printNiveau(int niveau); // Ausgabe aller Knoten zu einem Niveau
	void printHeight(int height); // Ausgabe aller Knoten zu einer H�he
	void postOrder(Treenode* p); // Traversiert Rekursiv den BST Bottum up; m�glichkeit Baum von unten nach oben zu l�schen
	void PreOrder(Treenode* k); // Top-down Ausgabe
};
/*
*	Aufgabe A) 
*	
*/
void BST::deleteBST(Treenode* p)
{
	if (p->left) 
	{
		deleteBST(p->left);
		p->left = nullptr;
	}
	if (p->right) {
		deleteBST(p->right);
		p->right = nullptr;
	}
	if (p->left == nullptr && p->right == nullptr)
	{
		delete p;
	}
}
BST::~BST()
{
	if(head->right != nullptr)deleteBST(head->right);
}
/*
*	Inser-Methode Hinweis:
*	- Zu bachten sind Zwei F�lle 1) Baum Leer , 2) Baum hat einen oder mehr Knoten
*   - Wichtig Es wird immer ab der Wurzel verglichen
*	- if( key < BST[key] ) -> Linkseinf�gen
*	- if( key >= BST[Key] ) -> Rechtseinf�gen
*/
void BST::insert(int key)
{
	Treenode *newNode = new Treenode(key);  // Initialisierung eines neuen Knoten -> Wird in den Baum eingef�gt
	newNode->left = nullptr;
	newNode->right = nullptr;

	if (head->right == nullptr) 
	{
		head->right = newNode;
	}
	else
	{
		Treenode* current = head->right; // Zeigt auf das Erste Element im Baum
		if (newNode->item < current->item) 
		{
			if (current->left == nullptr)
			{
				current->left = newNode; // Neuer Knoten wird als Blatt eingef�gt,
			}
			else
			{
				current = current->left;
			}
		}
		else if (newNode->item >= current->item) 
		{
			if (current->right == nullptr)
			{
				current->right = newNode; // Neuer Knoten wird als Blatt eingef�gt,
			}
			else
			{
				current = current->right;
			}
		}
	}
}

void BST::printBST()
{
	Treenode* current = head->right;
	if (current != nullptr) 
	{
		PreOrder(current);
	}
	
}
void BST::PreOrder(Treenode* k)
{
	if (k != nullptr) 
	{
		std::cout << "Knoten: " << k->item << ",";
		PreOrder(k->left);
		PreOrder(k->right);
	}
}