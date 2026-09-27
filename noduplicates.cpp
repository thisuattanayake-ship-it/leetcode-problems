#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode *next):val(x),next(next){}
};

class Solution{
    public:
        ListNode* deleteDuplicates(ListNode* head){
            if(head==nullptr||head->next==nullptr){
                return head;
            }
            ListNode* curr=head;
            while(curr!=nullptr&&curr->next!=nullptr){
                if(curr->val==curr->next->val){
                    curr->next=curr->next->next;
                }
                else{
                    curr=curr->next;
                }
            }
            return head;
        }
};

void printList(ListNode* head){
    ListNode* curr=head;
    while(curr!=nullptr){
        cout<<curr->val;
        if(curr->next!=nullptr)cout<<"->";
        curr=curr->next;
    }
    cout<<"->nullptr\n";
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    if(n<=0){
        cout<<"This list is empty\n";
        return 0;
    }
    cout<<"Enter "<<n<<" sorted numbers separated by spaces:\n";
    int value;
    cin>>value;
    ListNode* head=new ListNode(value);
    ListNode* curr=head;
    for(int i=1;i<n;i++){
        cin>>value;
        curr->next=new ListNode(value);
        curr=curr->next;
    }
    cout<<"\nOriginal List:\n";
    printList(head);
    Solution sol;
    head=sol.deleteDuplicates(head);
    cout<<"\nList after removing duplicates:\n";
    printList(head);
    return 0;
}