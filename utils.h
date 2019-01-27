#include <stdio.h>
#include <iostream>

#ifndef UTILS_H_ 
#define UTILS_H_ 


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

void printVector() {

};

#endif