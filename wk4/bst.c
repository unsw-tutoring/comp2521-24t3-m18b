#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    int elem;
    struct node *left;
    struct node *right;
};

// returns the number of nodes in a binary search tree
int bstCountNodes(struct node *t) {
    if (t == NULL) return 0;

    return bstCountNodes(t->left) + bstCountNodes(t->right) + 1;
}

// returns the number of odd values in a binary search tree
int bstCountOdds(struct node *t) {
    if (t == NULL) return 0;

    if (t->elem % 2 == 1) {  // it's odd
        return bstCountOdds(t->left) + bstCountOdds(t->right) + 1;
    } else {
        return bstCountOdds(t->left) + bstCountOdds(t->right);
    }
    // return (t->elem % 2) + bstCountOdds(t->left) + bstCountOdds(t->right);
}

// count number of internal nodes in a given tree
// an internal node is a node with at least one child node
int bstCountInternal(struct node *t) {
    if (t == NULL) return 0;
    if (t->left == NULL && t->right == NULL) return 0;
    return 1 + bstCountInternal(t->left) + bstCountInternal(t->right);
}

// returns the level of the node containing a given key if such a node exists,
// otherwise the function returns -1
// (when a given key is not in the binary search tree)
// The level of the root node is zero.
int bstNodeLevel(struct node *t, int key) {
    if (t == NULL) return -1;
    if (t->elem == key) return 0;
    if (t->elem < key) {
        int r = bstNodeLevel(t->right, key);
        if (r == -1) return -1;
        return 1 + r;
    } else {
        int r = bstNodeLevel(t->left, key);
        if (r == -1) return -1;
        return 1 + r;
    }
}

// counts the number of values that are greater than a given value.
// This function should avoid visiting nodes that it doesn't have to visit
int bstCountGreater(struct node *t, int val) {
    if (t == NULL) return 0;

    if (t->elem <= val) {
        return bstCountGreater(t->right, val);
    } else {
        return 1 + bstCountGreater(t->left, val) +
               bstCountGreater(t->right, val);
    }
    // return ((t->elem > val) ? 1 : 0) + bstCountGreater(t->left, val) +
    //        bstCountGreater(t->right, val);
}

#define NOT_HEIGHT_BALANCED -99

// returns the height of a given binary tree if it is height - balanced,
// and NOT_HEIGHT_BALANCED otherwise.
// Height-balanced tree: We say that a basic binary tree is height-balanced if,
//      for every node, the absolute difference between the height of the left
//      subtree and the height of the right subtree is one or less. In other
//      words, every node needs to satisfy the following criteria:
//      abs(height(left) - height(right)) ≤ 1
int isHeightBalanced(struct node *t) {
    if (t == NULL) return -1;

    int l = isHeightBalanced(t->left);
    int r = isHeightBalanced(t->right);

    if (l == NOT_HEIGHT_BALANCED || r == NOT_HEIGHT_BALANCED) {
        return NOT_HEIGHT_BALANCED;
    }

    if (abs(l - r) > 1) {
        return NOT_HEIGHT_BALANCED;
    }

    return max(l, r) + 1;
}

// challenging question!

// return the kth smallest node in the binary search tree
// return -1 if no such node exists (e.g. the 5th smallest number
// if a tree with only 3 nodes)

int doKthSmallest(struct node *t, int k, int *n) {
    if (t == NULL) return -1;

    int l = doKthSmallest(t->left, k, n);
    if (*n > k) return l;

    if (*n == k) {
        return t->elem;
    }
    (*n)++;

    return doKthSmallest(t->right, k, n);
}
int kthSmallest(struct node *t, int k) {
    int n = 0;
    return doKthSmallest(t, k, &n);
}
