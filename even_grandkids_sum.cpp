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
    int sum=0;
    void traversal(TreeNode * node){
        if(node==nullptr) return;
        if(node->val%2==0){
            if(node->left && node->left->left){
            sum+=node->left->left->val;
            }
            if(node->left && node->left->right){
            sum+=node->left->right->val;

            }
            if(node->right && node->right->left){
            sum+=node->right->left->val;
            }
            if(node->right && node->right->right){
            sum+=node->right->right->val;

            }

        }
        if(node->left){

        traversal(node->left);
        }
        if(node->right){
        traversal(node->right);

        }
    }
    int sumEvenGrandparent(TreeNode* root) {
        traversal(root);
        return sum;

        
    }
};
