#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct BST_Node
{
    int data;
    struct BST_Node *left;
    struct BST_Node *right;
} BST_t, *p_BST_t;

void InsertToBST(BST_t *root, int data);
BST_t *SearchBST(BST_t *root, int data);

void createBST(BST_t *T, int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        InsertToBST(T, (arr[i]));
    }
}

void InsertToBST(BST_t *tree, int data)
{
    BST_t *result = SearchBST(tree, data);

    if (root == NULL)
    {
        root = (BST_t *)malloc(sizeof(BST_t));
        root->data = data;
        root->left = root->right = NULL;
        return;
    }
    else if (data >)
    {
    }
}

/**
 * 查找成功 返回包含key的节点
 * 查找不成功 返回搜索key最后所在的节点
 */
BST_t *SearchBST(BST_t *Node, int data)
{
    if (Node == NULL || data == Node->data)
    {
        return Node;
    }
    else if (data < Node->data)
    {
        return SearchBST(Node->left, data);
    }
    else
    {
        return SearchBST(Node->right, data);
    }
}

BST_t *SearchBSTSafe(BST_t *root, int data)
{
}

BST_t *SearchBST_Min(BST_t *tree)
{
    if (tree == NULL)
        return NULL;
    else if (tree->left == NULL)
        return tree;
    else
        return SearchBST_Min(tree->left);
}

BST_t *SearchBST_MAX(BST_t *tree)
{
    if (tree == NULL)
        return NULL;
    else if (tree->right == NULL)
        return tree;
    else
        return SearchBST_MAX(tree);
}