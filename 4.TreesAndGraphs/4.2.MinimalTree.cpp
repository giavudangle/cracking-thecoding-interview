/**
 * 4.2.Minimal Tree :
 *
 * Given a sorted (increasing order) array with unique integer
 * elements. Write an algorithm to create BST with minimal height.
 *
 * @author VuDang
 */

#include <iostream>
#include <vector>


class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {

    }

    TreeNode(int data) {
        this->data = data;
        left = right = nullptr;
    }
}; 

class BinaryTree {
public:
    TreeNode* root;
    BinaryTree() {

    }

    TreeNode* constructBinarySearchTree(std::vector<int> arr, int start, int end) {
        if (start > end) return NULL;
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = constructBinarySearchTree(arr, start, mid - 1);
        root->right = constructBinarySearchTree(arr, mid + 1, end);
        return root;
    }

    void PreOrder(TreeNode* node) {
        if (node == NULL) return;
        std::cout << node->data << " ";
        PreOrder(node->left);
        PreOrder(node->right);
    }
};



int main() {

    std::vector<int> arr { 1, 2, 3, 4, 5,6,7 };
    BinaryTree* tree = new BinaryTree();
    tree->root = tree->constructBinarySearchTree(arr, 0, arr.size() - 1);
    tree->PreOrder(tree->root);

    return 0;
}