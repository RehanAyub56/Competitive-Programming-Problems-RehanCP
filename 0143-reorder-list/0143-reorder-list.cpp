/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 #include<iostream>
 using namespace std;
class Solution {
public:
int*arr;
int top;
int bot;

Solution(){
arr=new int[50000];
top=-1;
bot=0;
}
    void reorderList(ListNode* head) {
       ListNode*temp=head;
       ListNode*tail=nullptr;
       while(temp!=NULL){
        top++;
        arr[top]=temp->val;
        temp=temp->next;
       }
        temp=head;
        int index=(top)/2;
        int size=top;
        while(index){
            ListNode*newNode=new ListNode(arr[top]);
            top--;
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
            index--;
        }
        if(size%2==0){
        temp->next=nullptr;
        }else{
        temp->next->next=nullptr;
        }

     

      
    }
};