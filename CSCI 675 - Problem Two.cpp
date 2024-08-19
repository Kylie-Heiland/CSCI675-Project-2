/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* subtree;
        //First we need to find the node x.
        if(root->val != x){ //If the value player 1 chooses is the value NOT in the root node, then we will traverse through the binary tree, looking for the node with x value. 
            subtree = findNode(root, x);
        } else { //If the value player chooses is the value in the root node, then root is set to subtree.
            subtree = root;
        }

        int leftCount = countNodes(subtree->left); //Keeps track of the number of nodes that subtree's left child has, including the left child node.
        int rightCount = countNodes(subtree->right); //Keeps track of the number of nodes that subtree's right child has, including the right child node.
        int restCount = n - (leftCount + rightCount + 1); //Keeps track of the number of nodes that are NOT the subtree parent node or its children nodes.

        //If either the left subtree, right subtree, or the rest of the tree is greater than half the total number of nodes in the tree, then player 2 wins. 
        return max({leftCount, rightCount, restCount}) > n / 2; 

    }

    //Traverses through the binary tree, looking for the node that has the value x.
    TreeNode* findNode(TreeNode* root, int x){
        if(!root){
            return NULL;
        }
        if(root->val == x){ //If the value is found, then the current root node is returned!
            return root;
        }
        //Loop through each of the nodes until x is found, starting with the left node.
        TreeNode* leftNode = findNode(root->left, x);
        if(leftNode){ //If the node with value x was found in the left subtree, that particular node is returned.
            return leftNode; 
        } 
        return findNode(root->right, x); 
    }

    //Counts the number of nodes, starting at the root. 
    int countNodes(TreeNode* root) {
        if (root == NULL){ 
            return 0;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};