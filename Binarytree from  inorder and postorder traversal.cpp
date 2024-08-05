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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0) {
            return nullptr;
        }
        map<int, int> inMap;
        for(int i=0; i<inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return create(postorder, inMap, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* create(vector<int> &postorder, map<int, int> &inMap, int postFrom, int postTo, int inFrom, int inTo) {
        if(inFrom > inTo || postFrom > postTo) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(postorder[postTo]);
        int inRoot = inMap[root->val], leftSize = inRoot - inFrom;
        root->left = create(postorder, inMap, postFrom, postFrom + leftSize - 1, inFrom, inRoot - 1);
        root->right = create(postorder, inMap, postFrom + leftSize, postTo - 1, inRoot + 1, inTo);
        return root;
    }
    
};