class Solution {
public:
    ListNode * reversehalf(ListNode * head){
        ListNode * prev=nullptr;
        ListNode * curr=head;
        while(curr){
            ListNode * next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;

    }
    int pairSum(ListNode* head) {
        ListNode * ptr=head;
        int length=1;

        while(ptr->next){
        length++;
        ptr=ptr->next;
        }
        if(length==2){
            return head->val + head->next->val;
        }
        ptr=head;
        for(int i=0 ; i<length/2 ; i++){
            ptr=ptr->next;

        }
        ListNode * tail=reversehalf(ptr);
        ptr=head;
        int ans=0;

        for(int i=0 ; i<length/2 ; i++){
            ans=max(ans,ptr->val + tail->val);
            ptr=ptr->next;
            tail=tail->next;

        }
        return ans;

    }
};
