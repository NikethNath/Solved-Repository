class Solution {
public:
    pair<ListNode *,ListNode *> reverse(ListNode * head,int n){ //2
        ListNode * prev=nullptr;
        ListNode * curr=head;

        for(int i=0 ; i<n+1 ; i++){
            ListNode * next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return {prev,curr};

    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode * prev=nullptr;
        ListNode * curr=head;
        if(left==1){
            auto p=reverse(head,right-left);
            head->next=p.second;
            return p.first;
        }
        for(int i=1 ; i<left ; i++){
            prev=curr;
            curr=curr->next;
        }
        ListNode * revstart=curr;
        auto p=reverse(curr,right-left);
        if(prev){
        prev->next=p.first;
        }
        revstart->next=p.second;
        return head;
 
    }
};
