#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <string>

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
        vector<vector<int>> levelorder(TreeNode *root){
            if(root==nullptr)return {};
            vector<vector<int>> result;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                int q_size=q.size();
                vector<int> level;
                for(int i=0;i<q_size;i++){
                    TreeNode *curr=q.front();
                    q.pop();
                    level.push_back(curr->val);
                    if(curr->left!=nullptr){
                        q.push(curr->left);
                    }
                    if(curr->right!=nullptr){
                        q.push(curr->right);
                    }
                }
                result.push_back(level);
            }
            return result;
        }
};

TreeNode* buildTree(const string& input){
    if(input.empty()||input=="null"|input=="[]")return nullptr;
    string clean=input;
    if(clean.front()=='[')clean.erase(0,1);
    if(!clean.empty()&&clean.back()==']')clean.pop_back();
    stringstream ss(clean);
    string item;
    vector<string> tokens;
    while(getline(ss,item,',')){
        size_t start=item.find_first_not_of(" \t\r\n");
        size_t end=item.find_last_not_of(" \t\r\n");
        if(start!=string::npos&&end!=string::npos){
            tokens.push_back(item.substr(start,end-start+1));
        }
    }
    if(tokens[0]=="null"||tokens.empty())return nullptr;
    TreeNode *root=new TreeNode(stoi(tokens[0]));
    queue<TreeNode*> q;
    q.push(root);
    size_t i=1;
    while(!q.empty()&&i<tokens.size()){
        TreeNode *curr=q.front();
        q.pop();
        if(i<tokens.size()){
            if(tokens[i]!="null"){
                curr->left=new TreeNode(stoi(tokens[i]));
                q.push(curr->left);
            }
            i++;
        }
        if(i<tokens.size()){
            if(tokens[i]!="null"){
                curr->right=new TreeNode(stoi(tokens[i]));
                q.push(curr->right);
            }
            i++;
        }
    }
    return root;
}

void freeTree(TreeNode *root){
    if(!root)return;
    freeTree(root->left);
    freeTree(root->right);
    delete(root);
}

int main(){
    string input;
    cout<<"Enter the tree: ";
    getline(cin,input);
    TreeNode *root=buildTree(input);
    Solution sol;
    vector<vector<int>> result=sol.levelorder(root);
    cout<<"Level Order Traversal: [";
    for(size_t i=0;i<result.size();i++){
        cout<<'[';
        for(size_t j=0;j<result[i].size();j++){
            cout<<result[i][j]<<(j<result[i].size()-1?",":"");
        }
        cout<<']'<<(i<result.size()-1?",":"");
    }
    cout<<']';
    freeTree(root);
}