#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"

treeptr create(treeItem item) {
	treeptr t = (treeptr) malloc(sizeof(struct tnode));
	t->item = item;
	t->parent = t->left = t->right = NULL;
	return t;
}

treeptr getRight(treeptr p){
	return p->right;
}

treeptr getLeft(treeptr p) {
	return p->left;
}


void setLeft(treeptr p,treeItem item) {
	treeptr temp;
	if (p->left == NULL) {
		temp = create(item);
		p->left = temp;
		temp->parent = p;
	}	
}

void setRight(treeptr p,treeItem item) {
	treeptr temp;
	if (p->right == NULL) {
		temp = create(item);
		p->right = temp;
		temp->parent = p;
	}	
}

int isLeft(treeptr p){ // is p a left child
	int flag = 0; // false
	if (p->parent != NULL && p->parent->left == p) {
		flag = 1;
	}
	return flag;
}

int isRight(treeptr p){
	int flag = 0; // false
	if (p->parent != NULL && p->parent->right == p) {
		flag = 1;
	}
	return flag;
} // is p a left child

int isRoot(treeptr p){
	return p->parent == NULL;
}

/*
	visit the root
	traverse the left in preorder
	traverse the right in preorder
*/
void preDisplay(treeptr root) {
	if (root != NULL) {
		printf(" %d ",root->item);
		preDisplay(root->left);
		preDisplay(root->right);
	}		
}

void inDisplay(treeptr root) {
	if (root != NULL) {
		inDisplay(root->left);
		printf(" %d ",root->item);
		inDisplay(root->right);
	}		
}

//recursive
int containsV2(treeptr root,treeItem item){
	if (root == NULL) 
		return 0; // false
	else
	if (item == root->item)
		return 1; // true, found
	else 
	if (item < root->item)
		return containsV2(root->left,item);
	else
		return containsV2(root->right,item);	
} 

/*
// iterative
void addV1(treeptr root,treeItem item){
	treeptr p = root;
	treeptr q = root;
	treeptr temp = create(item);
	while (p != NULL) {
		q = p;
		if (item < p->item) 
			p = p->left;				
		else 
			p = p->right;	
	}	
	if (item < q->item)
		q->left = temp;
	else
		q->right = temp;
	temp->parent = q;	
}
*/

void addV1(treeptr root,treeItem item){
	treeptr p = root;
	treeptr temp = create(item);
	while (p != NULL) {
		if (item < p->item) {
			if (p->left == NULL) {
				p->left = temp;
				temp->parent = p;
				break;
			}				
			else p = p->left;				
		}
		else {
			if (p->right == NULL) {
				p->right = temp;
				temp->parent = p;
				break;
			}
			else	p = p->right;	
		}
	}	

}


void addV3(treeptr *root,treeItem item){
	treeptr temp = create(item);
	treeptr p = *root;
	if (*root == NULL) {
		*root = temp;		
	}
	else {
	while (p != NULL) {
		if (item < p->item) {
			if (p->left == NULL) {
				p->left = temp;
				temp->parent = p;
				break;
			}				
			else p = p->left;				
		}
		else {
			if (p->right == NULL) {
				p->right = temp;
				temp->parent = p;
				break;
			}
			else	p = p->right;	
		}
	}	
	}

}

// we can not attach the parent
void addV4(treeptr *root,treeItem item){
	if (*root == NULL) {
		*root = create(item);
	}
	else 
	if (item < (*root)->item)
		addV4(&(*root)->left,item);
	else
		addV4(&(*root)->right,item);
} 

//my code start here. code above is made by maam dean................................................

//iterative
int containsV1(treeptr root,treeItem item){
	int flag=0;
	treeptr p = root;
	

		while(p!=NULL){
			if(item==p->item){
			flag=1;
			break;
			}
			else if(item<p->item){
				p=p->left;
			}
			else{
				p=p->right;
			}
		}
	
	return flag;
}
//recursive
void addV2(treeptr root,treeItem item){
	if(root!=NULL){
		if(item<root->item){
			if(root->left==NULL){
				treeptr temp = create(item);
				root->left=temp;
				temp->parent=root;
			}
			else{
				addV2(root->left,item);
			}
		}
		else{
			if(root->right==NULL){
				treeptr temp = create(item);
				root->right=temp;
				temp->parent=root;
			}
			else{
				addV2(root->right, item);
			}
		}
	}
}
// iterative
int findMin(treeptr root){
	treeptr p = root;
	
	while(p!=NULL){
		if(p->left==NULL){
			break;
		}
		p=p->left;
	}
	
	return p->item;
}
// iterative
int findMax(treeptr root){
	treeptr p = root;
	
	while(p!=NULL){
		if(p->right==NULL){
			break;
		}
		p=p->right;
	}
	
	return p->item;
} 
void removeX(treeptr root,treeItem x){
	if(root!=NULL){
		if(x==root->item && root->left== NULL && root->right!=NULL){
			free(root);
			root=root->right;
			removeX(root->right,x);
		}
		else if(x==root->item&&root->right==NULL && root->left!=NULL){
			free(root);
			root = root->left;
			removeX(root->left,x);
		}
		else if(x==root->item&& root->right==NULL&&root->left==NULL){
			free(root);
			root->parent->right==NULL;	
		}
		else if(x==root->item&& root->right==NULL&&root->left==NULL){
			free(root);
			root->parent->left==NULL;	
		}
		else{
			removeX(root->right, x);
			removeX(root->left, x);
		}
	}
}
