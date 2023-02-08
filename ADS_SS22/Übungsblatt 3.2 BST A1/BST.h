#pragma once

#include "Node.h"
#include <algorithm>
#include <queue>

class BST 
{
private:
	Treenode* head;
	int computeHeight(Treenode* p); // rekursive Methode,berechnet die Höhe zum Knoten p und gibt diese zurück
	void deleteBST(Treenode* p); // löscht den Teilbaum ab p // rekursive Methode zur Ausgabe aller Knoten zu einer Höhe
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
	int  getBSTHeight(); // Starterfunktion für die rekursive Methode und liefert die Höhe des Baumes zurück
	void printBST(); // Ausgabe des BST in Levelorder
	void printNiveau(int niveau); // Ausgabe aller Knoten zu einem Niveau
	void printHeight(int height); // Ausgabe aller Knoten zu einer Höhe
	void postOrder(Treenode* p); // Traversiert Rekursiv den BST Bottum up; möglichkeit Baum von unten nach oben zu löschen
};
/*
*	Aufgabe 1.a) 
*		- Was benötigen wir für das Löschen aller Knoten im BST
*	
*/
BST::~BST()
{
	if (head->right != nullptr)deleteBST(head->right);
}
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

/*
*	Inser-Methode Hinweis:
*	- Zu bachten sind Zwei Fälle 1) Baum Leer , 2) Baum hat einen oder mehr Knoten
*   - Wichtig Es wird immer ab der Wurzel verglichen
*	- if( key < BST[key] ) -> Linkseinfügen
*	- if( key >= BST[Key] ) -> Rechtseinfügen
*/
void BST::insert(int key)
{
	Treenode *newNode = new Treenode();  // Initialisierung eines neuen Knoten -> Wird in den Baum eingefügt
	newNode->left = nullptr;
	newNode->right = nullptr;
	newNode->item = key;

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
				current->left = newNode; // Neuer Knoten wird als Blatt eingefügt,
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
				current->right = newNode; // Neuer Knoten wird als Blatt eingefügt,
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
	Treenode* root = head->right;
	int current_niv = 0; // Damit merken wir uns auf welchen Niv wir gerade stehen. S
	std::queue<Treenode*>Node;
	std::queue<int>niveau;
	
	if (root == nullptr) 
	{
		std::cout << "Der Baum ist Leer\n";
	}

	// Baum ist nicht Leer somit Pushen wir den Knoten in die Que
	Node.push(root);
	niveau.push(current_niv);

	while (!Node.empty())
	{
		std::cout << "Niveau(" << current_niv << "): ";
		Treenode* current = Node.front();
		Node.pop();

		int prev_niv = current_niv;
		current_niv = niveau.front(); niveau.pop();
		if (current_niv != prev_niv) 
		{
			std::cout << std::endl;
		}
		std::cout << "(" << current->item << ") ";
		if (current->left != nullptr) 
		{
			
			Node.push(current->left);
			niveau.push(current_niv+1);
		}
		if (current->right != nullptr)
		{
			Node.push(current->right);
			niveau.push(current_niv+1);
		}
	}
}
int BST::getBSTHeight() 
{

	printHeight(Treenode * node, int height);
}
int printHeight(Treenode* node, int height) 
{

}