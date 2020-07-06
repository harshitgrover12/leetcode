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
    void splitlist(ListNode *headref,ListNode **a,ListNode **b)
    {
        ListNode *slow=headref;
        ListNode *fast=headref;
        while(!slow&&!fast&&!fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        *a=headref;
        *b=slow->next;
        slow->next=NULL;

    }
    ListNode *merge(ListNode *a,ListNode *b)
    {
        ListNode *result;
       if(a==NULL)
           return b;
        if(b==NULL)
            return a;
        if(a->val<=b->val)
        {
            result=a;
            result->next=merge(a->next,b);
        }
        else if(a->val>b->val)
        {
            result=b;
            result->next=merge(a,b->next);
        }
        return result;
    }
    
    void mergeSort(ListNode **head)
    {
        ListNode *headref=*head;
        ListNode *a,*b;
        
        if(headref==NULL||headref->next==NULL)
            return;
        
        splitlist(headref,&a,&b);
        mergeSort(&a);
        mergeSort(&b);
        *head=merge(a,b);
        
    
        
            
    }
    ListNode* sortList(ListNode* head) {
        
        
       
        mergeSort(&head);
        return head;
        
    }
};
