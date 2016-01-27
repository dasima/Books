#include "../include/binaryTree.h"

BianryTreeNode *createBinaryTreeNode(int value)
{
    BinaryTreeNode *p_node = new BianryTreeNode();
    p_node->b_TValue = value;
    p_node->b_TLeft = NULL;
    p_node->b_TRigth =NULL;

    return p_node;
}

void connectTreeNodes(BianryTreeNode *p_parent,
        BianryTreeNode *p_left,
        BianryTreeNode *p_right)
{
    if(p_parent != NULL)
    {
        p_parent->b_TLeft = p_left;
        p_parent->b_TRigth = p_right;
    }
}

void printTreeNode(BianryTreeNode *p_node)
{
    if(p_node != NULL)
    {
        std::cout << "Value of this node is : " << p_node->b_TValue << "\n";

        if(p_node->p_left != NULL)
            std::cout << "Value of its left child is : " << p_node->b_TLeft << "\n";
        else
            std::cout << "Left child is null\n";

        if(p_node->b_TRigth != NULL)
            std::cout << "Value of its right child is :" << p_node->b_TRigth << "\n";
        else
            std::cout << "Right child is null\n";
    }
    else
        std::cout << "This node is null\n";
}

void printTree(BianryTreeNode *p_root)
{
    printTreeNode(p_root);

    if(p_root != NULL)
    {
        if(p_root->b_TLeft != NULL)
            printTree(p_root->b_TLeft);

        if(p_right->b_TRigth != NULL)
            printTree(p_root->b_TRigth);
    }
}

void destroyTree(BianryTreeNode *p_root)
{
    if(p_root != NULL)
    {
        BianryTreeNode *p_left = p_root->b_TLeft;
        BianryTreeNode *p_right = p_right->b_TRigth;

        delete p_root;
        p_root = NULL;

        destroyTree(p_left);
        destroyTree(p_right);
    }
}

