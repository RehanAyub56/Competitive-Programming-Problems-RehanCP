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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* List=new ListNode();
        ListNode*temp=List;
        bool etr=false;
        while(true){
            int val=INT_MAX;
            int idx=-1;
        for(int i=0;i<lists.size();i++){

            if(lists[i]!=NULL){
                etr=true;
                if(lists[i]->val<val){
                    val=lists[i]->val;
                    idx=i;
                }
            }


        }

        if(!etr){
            break;
        }
        else{
            ListNode*newNode=new ListNode(lists[idx]->val);
            temp->next=newNode;
            temp=temp->next;
            lists[idx]=lists[idx]->next;
            idx=-1;
            etr=false;

        }

        }

        return List->next;

    }
};