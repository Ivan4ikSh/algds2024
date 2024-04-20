#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "framework.h"

void MAX_TESTS() {
    printf("\nMAX TESTS:\n");
    if (Max(5, 3) == 5) printf("1 OK\n");
    else printf("1 ERROR\n");

    if (Max(-5, 3) == 3) printf("2 OK\n");
    else printf("2 ERROR\n");

    if (Max(-5, -3) == -3) printf("3 OK\n");
    else printf("3 ERROR\n");
}

void GET_HEIGHT_TESTS() {
    printf("\nGET HEIGHT TESTS:\n");

    struct AVLNode* node = CreateNode(5);
    if (GetHeight(node) == 1) printf("1 OK\n");
    else printf("1 ERROR\n");

    node->right = CreateNode(3);
    RecoveryHeight(node);
    if (GetHeight(node) == 2) printf("2 OK\n");
    else printf("2 ERROR\n");

    node->left = CreateNode(7);
    RecoveryHeight(node);
    if (GetHeight(node) == 2) printf("3 OK\n");
    else printf("3 ERROR\n");

    free(node->left);
    free(node->right);
    free(node);
}

void BALANCE_FACTOR_TESTS() {
    printf("\nBALANCE FACTOR TESTS:\n");

    struct AVLNode* node = CreateNode(5);
    if (BalanceFactor(node) == 0) printf("1 OK\n");
    else printf("1 ERROR\n");

    node->right = CreateNode(3);
    if (BalanceFactor(node) == 1) printf("2 OK\n");
    else printf("2 ERROR\n");

    node->left = CreateNode(7);
    if (BalanceFactor(node) == 0) printf("3 OK\n");
    else printf("3 ERROR\n");
    
    free(node->left);
    free(node->right);
    free(node);
}

void ROTATER_TESTS() {
    printf("\nROTATE_R TESTS\n");

    struct AVLNode* node = CreateNode(5);
    node->left = CreateNode(3);

    struct AVLNode* rotated_node = RotateR(node);
    if (rotated_node->key == 3) printf("1 OK\n");
    else printf("1 ERROR\n");

    if (rotated_node->left == NULL) printf("2 OK\n");
    else printf("2 ERROR\n");

    if (rotated_node->right->key == 5) printf("3 OK\n");
    else printf("3 ERROR\n");
    
    free(node->left);
    free(rotated_node->right);
    free(rotated_node);
}

void ROTATEL_TESTS() {
    printf("\nROTATE_L TESTS\n");
    struct AVLNode* node = CreateNode(5);
    node->right = CreateNode(7);

    struct AVLNode* rotated_node = RotateL(node);
    if (rotated_node->key == 7) printf("1 OK\n");
    else printf("1 ERROR\n");

    if (rotated_node->right == NULL) printf("2 OK\n");
    else printf("2 ERROR\n");

    if (rotated_node->left->key == 5) printf("3 OK\n");
    else printf("3 ERROR\n");

    free(node->right);
    free(rotated_node->left);
    free(rotated_node);
}

void CREATENODE_TESTS() {
    printf("\nCREATENODE TESTS\n");
    struct AVLNode* node = CreateNode(5);

    if (node->key == 5) printf("1 OK\n");
    else printf("1 ERROR\n");

    if (node->height == 1) printf("2 OK\n");
    else printf("2 ERROR\n");

    if (node->left == NULL) printf("3 OK\n");
    else printf("3 ERROR\n");

    if (node->right == NULL) printf("4 OK\n");
    else printf("4 ERROR\n");

    if (node->parent == NULL) printf("5 OK\n");
    else printf("5 ERROR\n");

    free(node);
}

void UNIT_TESTS() {
    CREATENODE_TESTS();
    ROTATEL_TESTS();
    ROTATER_TESTS();
    BALANCE_FACTOR_TESTS();
    GET_HEIGHT_TESTS();
    MAX_TESTS();
}