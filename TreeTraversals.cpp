/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> result;

        auto current = root;
        stack<TreeNode*> s;

        while ((!s.empty()) || (current)) {
            // Push current while left is not empty
            if (current) {
                s.push(current);
                current = current->left;
            } else {
                // add top->value to results
                auto top = s.top();
                result.push_back(top->val);
                // set current to top->right and pop  
                current = top->right;
                s.pop();
            }
        }

        return result;
    }
};
