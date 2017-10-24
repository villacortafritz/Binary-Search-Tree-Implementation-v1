#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	treeptr root = create(50);
	//addV4(&root,50);
	addV4(&root,25);
	addV4(&root,75);
	printf("\n tree = ");
	preDisplay(root);
	addV4(&root,10);
	addV4(&root,40);
	addV4(&root,60);
	addV4(&root,90);
	printf("\n tree = ");
	preDisplay(root);
	printf("\n tree = ");
	inDisplay(root);
	printf("\ncontainsV2(root,90)=%d",containsV2(root,90));
	printf("\ncontainsV2(root,60)=%d",containsV2(root,60));
	printf("\ncontainsV2(root,30)=%d",containsV2(root,30));
	
	printf("\n\ncontainsV1(root,30)=\t%d",containsV1(root,30));
	addV2(root, 30);
	printf("\nAdd 30:\t\t\t");
	inDisplay(root);
	printf("\ncontainsV1(root,30)=\t%d",containsV1(root,30));
	printf("\nfindMin=\t\t%d",findMin(root));
	printf("\nfindMax=\t\t%d",findMax(root));
	removeX(root, 30);
	printf("\nRemove 30:\t\t");
	inDisplay(root);
	
	
	return 0;
			
}
