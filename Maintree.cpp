#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Maintree.h"
#include <fstream>

Maintree::Maintree()
{
	root = NULL;
}

ostream &operator << (ostream &ost, struct department) {
	return ost;
}

void Maintree::destroy_tree(node *leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

int Maintree::readintree()
{
	ifstream inFile;
	inFile.open("ServerOutput.txt");
	if (inFile.is_open() != true)
	{
		cout << "Error opening server file." << endl;
		return -1;
	}
	int tID;
	int tdept;
	string tfname;
	string tlname;
	char tchoice;
	int activity;
	string depts[17] = { "video", "television", "electronics", "clothing", "music", "sports", "beauty", "books", "vehicle", "photos", "toys", "multimedia", "home", "credit", "produce", "handmade", "app" };
	int x = 0;

	//Scan each line of the file
	while (inFile.good()){
		inFile >> tID >> tfname >> tlname >> tdept >> tchoice >> activity;
		node *userNode = search(tID);
		if (!userNode)
		{    // Creates node and then procedes to insert parts into node
			userNode = new node;
			rootmaker(tID, userNode);
			if (tchoice == 'b')
			{
				userNode->ID = tID, userNode->fname = tfname, userNode->lname = tlname, userNode->departments[tdept].dept_name = depts[tdept], userNode->departments[tdept].bought += activity;
			}
			if (tchoice == 'c')
			{
				userNode->ID = tID, userNode->fname = tfname, userNode->lname = tlname, userNode->departments[tdept].dept_name = depts[tdept], userNode->departments[tdept].clicks += activity;
			}
		}
		else
		{	// skips creation of node and inserts parts
			if (tchoice == 'b')
			{
				userNode->ID = tID, userNode->fname = tfname, userNode->lname = tlname, userNode->departments[tdept].dept_name = depts[tdept], userNode->departments[tdept].bought += activity;
			}
			if (tchoice == 'c')
			{
				userNode->ID = tID, userNode->fname = tfname, userNode->lname = tlname, userNode->departments[tdept].dept_name = depts[tdept], userNode->departments[tdept].clicks += activity;
			}
		}

	}
	inFile.close();
}


void Maintree::insert(int key, node *leaf, node *mel) // creates node if one is not available in order to insert data
{
	if (key< leaf->ID)
	{
		if (leaf->left != NULL)
			insert(key, (leaf->left), mel);
		else
		{
			leaf->left = new node;
			leaf->left->ID = key;
			leaf->left->left = NULL;    //Sets the left child of the child node to null
			leaf->left->right = NULL;   //Sets the right child of the child node to null
		}
	}
	else if (key >= leaf->ID)
	{
		if (leaf->right != NULL)
			insert(key, (leaf->right), mel);
		else
		{
			leaf->right = new node;
			leaf->right->ID = key;
			leaf->right->left = NULL;  //Sets the left child of the child node to null
			leaf->right->right = NULL; //Sets the right child of the child node to null
		}
	}
}

node *Maintree::search(int key, node *leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->ID)
			return leaf;
		if (key<leaf->ID)
			return search(key, leaf->left);
		else
			return search(key, leaf->right);
	}
	else return NULL;
}

void Maintree::rootmaker(int key, node *mel) //Creates a root node if there is none, or puts a node to the left/right.
{
	if (root != NULL)
		insert(key, root, mel);
	else
	{
		root = mel;
		root->ID = key;
		root->left = NULL;
		root->right = NULL;
	}
}

node *Maintree::search(int key)
{
	return search(key, root);
}

void Maintree::destroy_tree()
{
	destroy_tree(root);
}


void Maintree::export_recursive(node* leaf, ofstream & out)
{
	if (leaf != NULL)
	{
		
		out << leaf->ID << " " << leaf->fname << " " << leaf->lname << endl;
		int yy;
		for (yy = 0; yy < 17; yy++)
		{
				out << leaf->departments[yy].dept_name << endl << "Total amount bought: " << leaf->departments[yy].bought << " Total amount of clicks: " << leaf->departments[yy].clicks << endl;
		}
		export_recursive(leaf->left, out);
		export_recursive(leaf->right, out);
	}
}



int Maintree::exportTree()
{
	ofstream outFile("TreeOutput.txt");
	if (outFile.is_open() != true)
	{
		cout << "Error opening server file." << endl;
		return -1;
	}
	export_recursive(root, outFile);
	outFile.close();
	return 0;
}



Maintree::~Maintree()
{
	destroy_tree(root);
	return;
}