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
    int goodNodes(TreeNode* root) {
    
          return find(root,INT_MIN);
    }
     int find(TreeNode* root, int max){
    int count =0;
    if (root == nullptr)
        return 0;
  
    if (root-> val >=max){
        count++;
        max= root->val;
    }
    count += find(root->left,max);
    count +=find(root->right,max);
    return count;
}
};