#pragma once
#include <stdio.h>
#include <stdlib.h>

struct AVLNode {
	int key;
	int height;
	struct AVLNode* left;
	struct AVLNode* right;
	struct AVLNode* parent;
};

struct AVLNode* Remove(struct AVLNode* node, int k);
struct AVLNode* InsertNode(struct AVLNode* node, int key);

void PrintAVLTree(struct AVLNode* node, int level);
struct AVLNode* InitAVLTree(const int n);

int Max(int a, int b);
int GetHeight(struct AVLNode* node);
int BalanceFactor(struct AVLNode* node);

struct AVLNode* RotateR(struct AVLNode* node);
struct AVLNode* RotateL(struct AVLNode* node);
struct AVLNode* CreateNode(int key);
struct AVLNode* Balance(struct AVLNode* node);

struct AVLNode* RemoveMin(struct AVLNode* node);
