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
    ListNode *recurs(ListNode *root)
    {
        if(root==NULL)
            return root;
        if(root->next==NULL)
            return root;
        ListNode *temp=root->next;
        ListNode *head=recurs(root->next);
        temp->next=root;
        root->next=NULL;
        return head;
    }
    void reorderList(ListNode* head) {
        if(head==NULL)
            return ;
       ListNode *slow=head;
        ListNode *fast=head;
        while(slow!=NULL&&fast!=NULL&&fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *temp=slow->next;
        slow->next=NULL;
        ListNode *newHead=recurs(temp);
        ListNode *final_ans=NULL;
        int cnt=1;
        ListNode *temp1;
        while(head!=NULL&&newHead!=NULL)
        {
            if(cnt%2==1)
            {
                if(final_ans==NULL)
                {
                    final_ans=head;
                    temp1=final_ans;
                }
                else
                {
                    final_ans->next=head;
                    final_ans=final_ans->next;
                    
                }
                head=head->next;
            }
            else
            {
                final_ans->next=newHead;
                newHead=newHead->next;
                final_ans=final_ans->next;
            }
            cnt++;
        }
        while(head!=NULL)
        {
            if(final_ans==NULL)
                final_ans=head;
            else
            {
            final_ans->next=head;
            
            final_ans=final_ans->next;
            }
            head=head->next;
        }
        while(newHead!=NULL)
        {
            final_ans->next=newHead;
            newHead=newHead->next;
            final_ans=final_ans->next;
        }
        final_ans->next=NULL;
        head=temp1;
        
    }   
};
