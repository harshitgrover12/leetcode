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
    ListNode *newNode(int r)
    {
        ListNode *temp=new(ListNode);
        temp->val=r;
        temp->next=NULL;
        return temp;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
        int c=0;
        int sum=0;
        ListNode *l3=NULL;
        while(l1||l2)
        {
        if(l1)
        {
            sum=l1->val+c;
        }
        if(l2)
        {
           sum=sum+l2->val;
            if(!l1)
                sum+=c;
        }
            c=sum/10; 
            if(l1)
            l1=l1->next;
            if(l2)
            l2=l2->next;
          ListNode *t=newNode(sum%10);
            sum=0;
            if(l3==NULL)
                l3=t;
            else
            {
                ListNode *temp=l3;
                while(temp->next!=NULL)
                    temp=temp->next;
                temp->next=t;
            }
        }
        if(c!=0)
        {
           
                
            ListNode *temp=l3;
                while(temp->next!=NULL)
                    temp=temp->next;
                temp->next=newNode(c);
        }
        return l3;
        
    }
};
