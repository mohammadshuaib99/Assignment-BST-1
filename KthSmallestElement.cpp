
#include <iostream>
using namespace std;

// Definition for a binary tree node
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to insert a node into a BST
TreeNode *insert(TreeNode *root, int val)
{
    if (root == NULL)
    {
        return new TreeNode(val);
    }
    if (val < root->val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

TreeNode *constructBST(int arr[], int n)
{
    TreeNode *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    return root;
}

void inorderTraversal(TreeNode *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}
void inorder(TreeNode *root, int &k, int &result)
{
    if (root == NULL)
        return;

    inorder(root->left, k, result);

    k--;
    if (k == 0)
    {
        result = root->val;
        return;
    }

    inorder(root->right, k, result);
}

int kthSmallest(TreeNode *root, int k)
{
    int result = -1;
    inorder(root, k, result);
    return result;
}

int main()
{
    int arr[] = {5, 3, 8, 2, 4, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Construct the BST
    TreeNode *root = constructBST(arr, n);

    // Print the inorder traversal of BST
    cout << "Inorder Traversal of BST: ";
    inorderTraversal(root);
    cout << endl;
    int k = 1;
    cout<<"Kth Element : "<<kthSmallest(root,k)<<endl;

    return 0;
}
