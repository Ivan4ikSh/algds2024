#include "framework.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Max(int a, int b) {
    return (a > b) ? a : b;
}

int GetHeight(struct AVLNode* node) {
    return node ? node->height : 0;
}

int BalanceFactor(struct AVLNode* node) {
    return GetHeight(node->right) - GetHeight(node->left);
}

void RecoveryHeight(struct AVLNode* node) {
    int left_height = GetHeight(node->left);
    int right_height = GetHeight(node->right);
    node->height = (left_height > right_height ? left_height : right_height) + 1;
}

struct AVLNode* RotateR(struct AVLNode* node) {
    struct AVLNode* temp = node->left;
    struct AVLNode* parent = node->parent;

    node->left = temp->right;

    if (temp->right) temp->right->parent = node;

    temp->right = node;
    temp->parent = node->parent;
    node->parent = temp;

    RecoveryHeight(node);
    RecoveryHeight(temp);

    if (parent) parent->left = node->parent;
    return node->parent;
}

struct AVLNode* RotateL(struct AVLNode* node) {
    struct AVLNode* temp = node->right;
    struct AVLNode* parent = node->parent;

    node->right = temp->left;

    if (temp->left) temp->left->parent = node;

    temp->left = node;
    temp->parent = node->parent;
    node->parent = temp;

    RecoveryHeight(node);
    RecoveryHeight(temp);

    if (parent) parent->right = node->parent;
    return node->parent;
}

struct AVLNode* CreateNode(int key) {
    struct AVLNode* new_node = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    if (!new_node) {
        printf("Ошибка: Невозможно выделить память для нового узла.\n");
        exit(EXIT_FAILURE);
    }

    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;
    new_node->height = 1;

    return new_node;
}

struct AVLNode* Balance(struct AVLNode* node) {
    RecoveryHeight(node);
    int balance = BalanceFactor(node);

    if (balance == 2) {
        if (BalanceFactor(node->right) < 0) {
            node->right = RotateR(node->right);
            node->left = NULL;
        }

        return RotateL(node);
    }
    if (balance == -2) {
        if (BalanceFactor(node->left) > 0) {
            node->left = RotateL(node->left);
            node->right = NULL;
        }

        return RotateR(node);
    }
    return node;
}

void Root(struct AVLNode** node) {
    while ((*node)->parent) {
        (*node) = (*node)->parent;
    }
}

void FindPlacementAndInsert(struct AVLNode** node, struct AVLNode** insert_node, struct AVLNode* root, int key) {
    struct AVLNode* current = root;

    while (current) {
        *node = current;
        if (key < current->key) current = current->left;
        else current = current->right;
    }

    if (key < (*node)->key) (*node)->left = *insert_node;
    else (*node)->right = *insert_node;

    (*insert_node)->parent = (*node);
}

void RebalanceAVLTree(struct AVLNode** root, struct AVLNode* parent, struct AVLNode* new_node) {
    while (parent) {
        RecoveryHeight(parent);
        int balance = BalanceFactor(parent);

        if (balance == 0) break;

        else if (abs(balance) == 1) {
            new_node = parent;
            parent = parent->parent;
        }
        else {
            *root = Balance(parent);
            Root(&(*root));
            break;
        }
    }
}

struct AVLNode* InsertNode(struct AVLNode* node, int key) {
    struct AVLNode* new_node = CreateNode(key);
    if (!node) return new_node;

    struct AVLNode* parent = NULL;

    FindPlacementAndInsert(&parent, &new_node, node, key);
    RebalanceAVLTree(&node, parent, new_node);
    return node;
}

struct AVLNode* RemoveMin(struct AVLNode* node) {
    if (!node) return NULL;

    struct AVLNode* parent = NULL;
    struct AVLNode* current = node;

    while (current->left) {
        parent = current;
        current = current->left;
    }

    if (parent) parent->left = current->right;
    else node = current->right;

    if (current->right) current->right->parent = parent;

    return Balance(node);
}

void RemoveNode(struct AVLNode** node, struct AVLNode* current, struct AVLNode* parent) {
    struct AVLNode* child = (current->left) ? current->left : current->right;

    if (!parent) node = child;
    else if (parent->left == current) parent->left = child;
    else parent->right = child;

    if (child) child->parent = parent;

    free(current);
}

struct AVLNode* Remove(struct AVLNode* node, int k) {
    if (!node) return NULL;

    struct AVLNode* parent = NULL;
    struct AVLNode* current = node;

    while (current && current->key != k) {
        parent = current;
        if (k < current->key) current = current->left;
        else current = current->right;
    }
    if (!current) return node;

    RemoveNode(&node, current, parent);

    return Balance(node);
}

void PrintAVLTree(struct AVLNode* node, int level) {
    if (node) {
        if (node->left) PrintAVLTree(node->left, level + 1);
        for (int i = 0; i < level; i++) {
            printf("   ");
        }
        printf("%d\n", node->key);
        if (node->right) PrintAVLTree(node->right, level + 1);
    }
}

struct AVLNode* InitAVLTree(const int n) {
    struct AVLNode* node = NULL;
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        node = InsertNode(node, i);
    }

    int x = 0;
    return node;
}
