#include <iostream>

struct BinaryTreeNode
{
    int b_TValue;
    BinaryTreeNode *b_TLeft;
    BinaryTreeNode *b_TRight;
};

BinaryTreeNode *constructCore(int *startPreorder, 
        int *endPreorder, 
        int *startInorder, 
        int *endInorder);

BinaryTreeNode *construct(int *preorder, 
        int *inorder, 
        int length)
{
    if(preorder == NULL || inorder == NULL || length <= 0)
        return NULL;
    return constructCore(preorder, preorder + length -1, inorder, inorder + length -1);
}

BinaryTreeNode *constructCore(int *startPreorder, 
        int *endPreorder, 
        int *startInorder, 
        int *endInorder)
{
    // preorder, the first node is root
    int rootValue = startPreorder[0];
    BinaryTreeNode *root = new BinaryTreeNode();
    root->b_TValue = rootValue;
    root->b_TLeft = root->b_TRight = NULL;

    // if only has one node
    if(startPreorder == endPreorder)
    {
        // one node only and preorder and inorder has the same node
        if(startInorder == endInorder && *startPreorder == *startInorder)
            return root;
        else
            throw std::exception("Invalid input");
    }

    // find root node from inorder
    int rootInorder = startInorder;
    while(rootInorder <= endInorder && *rootInorder != rootValue)
        ++rootInorder;

    if(rootInorder == endInorder && *rootInorder != rootValue)
        throw std::exception("Invalid input.");

    int leftLength = rootInorder - startInorder;
    int *leftPreorderEnd = startPreorder + leftLength;//left tree end
    if(leftLength > 0)
    {
        // construct left tree
        root->b_TLeft = constructCore(startPreorder + 1, 
                leftPreorderEnd,
                startInorder,
                rootInorder - 1);
    }
    if(leftLength < endPreorder - startPreorder)
    {
        // constuct right tree
        root->b_TRight = constructCore(leftPreorderEnd + 1, 
                endPreorder,
                rootInorder + 1,
                endInorder);
    }
    return root;
}

int main(int argc, const char *argv[])
{
    
    return 0;
}
