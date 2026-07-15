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
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> visit;
      TreeNode* current = root;
     while(current != nullptr){
        if(current->left == nullptr){
           visit.push_back(current->val);
           current = current->right;
        }
        else{
            TreeNode* pred = current->left;
           while(pred->right != nullptr && pred->right != current){
              pred = pred->right;
           }
           if(pred->right == nullptr){
             pred->right = current;
             current = current->left;
           }
           else{
            pred->right = nullptr;
            visit.push_back(current->val);
            current = current->right;
           }
        }
     }
     return visit;
    }
};