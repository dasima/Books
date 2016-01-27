#include <iostream>
#include <exception>
#include "include/binaryTree.h"

BinaryTreeNode *constructTreeCore(int *start_pre_order,
        int *end_pre_order,
        int *start_in_order,
        int *end_in_order);

BinaryTreeNode *constructTree(int *pre_order,
        int *in_order,
        int length)
{
    if(pre_order == NULL || in_order == NULL || length <= 0)
        return NULL;
    return constructTreeCore(pre_order,
            pre_order + length - 1,
            in_order,
            in_order + length - 1);
}

BinaryTreeNode *constructTreeCore(int *start_pre_order,
        int *end_pre_order,
        int *start_in_order,
        int *end_in_order)
{
    // pre order, the first node is root
    int root_value = start_pre_order[0];
    BinaryTreeNode * root = new BinaryTreeNode();
    root->b_TValue = root_value;
    root->b_TLeft = root->b_TRight = NULL;

    // if  one node only
    if(start_pre_order == end_pre_order)
    {
        // pre order and in order have the same node
        if(start_in_order == end_in_order 
                && *start_pre_order == *start_in_order)
            return root;
        else
            throw std::exception("Invalid input");
    }

    // find root from in_order to divide the left child and right child
    int *root_in_order = start_in_order;
    while(root_in_order <= end_in_order && *root_in_order != root_value)
        ++root_in_order;

    if(root_in_order <= end_in_order 
            && *root_in_order != root_value)
        throw std::exception("Invalid input");

    
    int left_length = root_in_order - start_in_order;
    int *left_pre_order_end = start_pre_order + left_length;
    if(left_length > 0)
    {
        // construct left child tree
        root->b_TLeft = constructTreeCore(start_pre_order + 1, 
                left_pre_order_end,
                start_in_order,
                root_in_order - 1);
    }
    else if(left_length < end_pre_order - start_pre_order)
    {
        // construct right tree
        root->b_TRight = constructTreeCore(left_pre_order_end + 1,
                end_pre_order,
                root_in_order,
                end_in_order);
    }

    return root;
}

void constructTreeTest(int *pre_order, 
        int *in_order, 
        int length)
{
    std::cout << "---The pre order sequence is:---\n";
    for(int index = 0; index < length; ++index)
        std::cout << pre_order[index];
    std::cout << std::endl;

    std::cout << "---The in_order sequence is:---\n";
    for(int index = 0; index < length; ++index)
        std::cout << in_order[index];
    std::cout << std::endl;

    try
    {
        BinaryTreeNode *root = constructTree(pre_order, 
                in_order, 
                length);
        printTree(root);

        destroyTree(root);
    }
    catch(std::exception &exception)
    {
        std::cout << "Invalid inout.\n";
    }
}

// normal tree
void testNormal()
{
    const int length = 8;
    int pre_order[length] = {1, 2, 4, 7, 3, 5 ,6, 8};
    int in_order[length] = {4, 7, 2, 1, 5, 3, 8, 6};

    constructTreeTest(pre_order, in_order, length);
}

// all node has left child only
void testLeftOnly()
{
    const int length = 5;
    int pre_order[length] = {1, 2, 3, 4, 5};
    int in_order[length] = {5, 4, 3, 2, 1};
    constructTreeTest(pre_order, in_order, 5);
}

// all node has right child only
void testRightOnly()
{
    const int length = 5;
    int pre_order[length] = {1, 2, 3, 4, 5};
    int in_order[length] = {1, 2, 3, 4, 5};
    constructTreeTest(pre_order, in_order, 5);
}   

// one node only
void testOneOnly()
{
    const int length = 1;
    int pre_order[length] = {1};
    int in_order[length] = {1};
    constructTreeTest(pre_order, in_order, 1);
}

// complete binary tree
void testCompleteBinaryTree()
{
    const int length = 7;
    int pre_order[length] = {1, 2, 4, 5, 3, 6, 7};
    int in_order[length] = {4, 2, 5, 1, 6, 3, 7};
    constructTreeTest(pre_order,in_order, 7);
}

// empty
void testNULL()
{
    constructTreeTest(NULL, NULL, 0);
}
 
// pre_order and in_order are not fit
void testNotComparable()
{
    const int length = 7;
    int pre_order[length] = {1, 2, 4, 5, 3, 6, 7};
    int in_order[length] = {8, 2, 5, 1, 6, 3, 7};
    constructTreeTest(pre_order, in_order, 7);
}


int main(int argc, const char *argv[])
{
    // test
    testNormal();
    testLeftOnly();
    testRightOnly();
    testOneOnly();
    testCompleteBinaryTree();
    testNULL();
    testNotComparable();
    
    return 0;
}
