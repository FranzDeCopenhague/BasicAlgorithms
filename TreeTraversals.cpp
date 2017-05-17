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
            // Push current while current
            if (current) {
                s.push(current);
                // set current to left
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

    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> result;

        auto current = root;
        stack<TreeNode*> s;

        while ((!s.empty()) || (current)) {
            // Push while current
            if (current) {
              // Add current->value to results and
                result.push_back(current->val);
                s.push(current);
                // set current to left
                current = current->left;
            } else {
                auto top = s.top();
                s.pop();
                current = top->right;
            }
        }

        return result;
    }

    vector<int> postorderTraversal(TreeNode* root) {

    vector<int> result;
    stack<TreeNode*> s;

    auto current = root;

    while ((!s.empty()) || current) {
        if (current) {
            // Push root's right child and then root to stack.
            if (current->right) {
                s.push(current->right);
            }
            s.push(current);
            // Move to leftmost node
            current = current->left;
        } else {
            auto parent = s.top();
            s.pop();
            // make sure right child is processed before parent
            if ((parent->right) && (!s.empty()) && (parent->right == s.top())) {
                s.pop();
                // return parent to the stack
                s.push(parent);
                // process right instead
                current = parent->right;
            } else {
                result.push_back(parent->val);
                current = nullptr;
            }
        }
    }

    return result;
}

vector<int> postorderTraversal(TreeNode* root) {

     vector<int> result;
     stack<TreeNode*> s;

     auto current = root;

     while ((!s.empty()) || current) {
         if (current) {
             // Push root's right child and then root to stack.
             if (current->right) {
                 s.push(current->right);
             }
             s.push(current);
             // Move to leftmost node
             current = current->left;
         } else {
             auto parent = s.top();
             s.pop();
             // make sure right child is processed before parent
             if ((parent->right) && (!s.empty()) && (parent->right == s.top())) {
                 s.pop();
                 // return parent to the stack
                 s.push(parent);
                 // process right instead
                 current = parent->right;
             } else {
                 result.push_back(parent->val);
                 current = nullptr;
             }
         }
     }

     return result;
 }

};
