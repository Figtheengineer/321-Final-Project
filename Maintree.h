#define MAINTREE_H
#include <stdio.h>
#include <iostream>

using namespace std;

//Individual department structure
struct department
{
	string dept_name;
	int clicks = 0;
	double bought = 0.00;
};

struct node
{
	int ID;
	string fname;
	string lname;

	//17 departments to possibly shop from
	department departments[17];

	node *left;
	node *right;
};

class Maintree
{
	//friend class Secondtree;
public:
	Maintree();
	~Maintree();
	int readintree(); //function that is used to initiate reading in the tree from the file
	void rootmaker(int key, node* mel);
	node *search(int key);
	void destroy_tree();
	int exportTree();

	
private:
	void export_recursive(node *leaf, ofstream & out);
	//void printTree::postorder(tree_node*p, int indent = 0);
	void destroy_tree(node *leaf);
	void insert(int key, node *leaf, node*mel);
	node *search(int key, node *leaf);
	node *root;
};

