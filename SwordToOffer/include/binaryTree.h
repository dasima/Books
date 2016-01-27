#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

struct BinaryTreeNode
{
    int             b_TValue;
    BinaryTreeNode *b_TLeft;
    BinaryTreeNode *b_TRight;
};

BinaryTreeNode *createBinaryTreeNode(int value);
void connectTreeNodes(BinaryTreeNode *p_parent,
        BinaryTreeNode *p_left,
        BinaryTreeNode *p_right);
void printTreeNode(BinaryTreeNode *p_node);
void printTree(BinaryTreeNode *p_root);
void destroyTree(BinaryTreeNode *p_root);

#endif  /*_BINARY_TREE_H_*/
