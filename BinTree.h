#ifndef BINTREE_H
#define BINTREE_H

typedef int treeItem;
typedef struct tnode *treeptr;
struct tnode {
	treeItem item;
	treeptr parent;
	treeptr left;
	treeptr right;
};

treeptr create(treeItem item);
void setLeft(treeptr p,treeItem item);
void setRight(treeptr p,treeItem item);
treeptr getRight(treeptr p);
treeptr getLeft(treeptr p);

int isLeft(treeptr p); // is p a left child
int isRight(treeptr p); // is p a left child
int isRoot(treeptr p);
void preDisplay(treeptr root);
void inDisplay(treeptr root);

int containsV1(treeptr root,treeItem item); //iterative
int containsV2(treeptr root,treeItem item); //recursive

void addV1(treeptr root,treeItem item); //iterative

//
int containsV1(treeptr root,treeItem item); //iterative
void addV2(treeptr root,treeItem item); //recursive
int findMin(treeptr root); // iterative
int findMax(treeptr root); // iterative

void addV3(treeptr *root,treeItem item); //recursive
void addV4(treeptr *root,treeItem item); //recursive

// bonus
// void removeX(treeptr root,treeItem x);




#endif
