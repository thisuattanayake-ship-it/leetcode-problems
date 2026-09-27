#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode *left,TreeNode *right):val(x),left(left),right(right){}
};

class Solution{
    public:
        bool isMirror(TreeNode *t1,TreeNode *t2){
            if(t1==nullptr&&t2==nullptr){
                return true;
            }
            if(t1==nullptr||t2==nullptr||t1->val!=t2->val){
                return false;
            }
            return (isMirror(t1->left,t2->right)&&isMirror(t1->right,t2->left));
        }
        bool isSymmetric(TreeNode *root){
            if(root==nullptr)return true;
            return isMirror(root->left,root->right);
        }
};

TreeNode* buildTreeFromInput() {
    cout << "Enter tree nodes in level-order separated by spaces (use -1 for null):\n";
    cout << "Example: 1 2 2 3 4 4 3\n";
    cout << "> ";

    string line;
    getline(cin, line);
    if (line.empty()) return nullptr;

    stringstream ss(line);
    vector<string> tokens;
    string item;
    while (ss >> item) {
        tokens.push_back(item);
    }

    if (tokens.empty() || tokens[0] == "-1" || tokens[0] == "null") {
        return nullptr;
    }

    TreeNode* root = new TreeNode(stoi(tokens[0]));
    queue<TreeNode*> q;
    q.push(root);

    size_t i = 1;
    while (!q.empty() && i < tokens.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Process Left Child
        if (i < tokens.size()) {
            if (tokens[i] != "-1" && tokens[i] != "null") {
                curr->left = new TreeNode(stoi(tokens[i]));
                q.push(curr->left);
            }
            i++;
        }

        // Process Right Child
        if (i < tokens.size()) {
            if (tokens[i] != "-1" && tokens[i] != "null") {
                curr->right = new TreeNode(stoi(tokens[i]));
                q.push(curr->right);
            }
            i++;
        }
    }

    return root;
}

int main() {
    TreeNode* root = buildTreeFromInput();

    Solution solution;
    if (solution.isSymmetric(root)) {
        cout << "\nResult: The tree is SYMMETRIC.\n";
    } else {
        cout << "\nResult: The tree is NOT SYMMETRIC.\n";
    }

    return 0;
}