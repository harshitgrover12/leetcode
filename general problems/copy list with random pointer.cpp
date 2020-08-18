/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       
    Node *temp=head;
        if(!temp)
            return NULL;
    unordered_map<Node*,Node*> mp;
    Node *head1=new Node(head->val);
        mp[head]=head1;
    Node *root=head1;
        while(temp)
        {
            if(temp->next!=NULL)
            root->next=new Node(temp->next->val);
                else
                    root->next=NULL;
            mp[temp->next]=root->next;
            temp=temp->next;
            root=root->next;
            
        }
        root=head1;
        temp=head;
        while(temp!=NULL)
        {
            root->random=mp[temp->random];
            root=root->next;
            temp=temp->next;
        }
   
        return head1;
        
    }
};
