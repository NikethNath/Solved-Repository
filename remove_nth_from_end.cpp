
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=0;
        ListNode * iter=head;
        while(iter){
            iter=iter->next;
            length++;
        }
        if(n==length) return head->next;
        int k=length-n-1;
        iter=head;
        for(int i=0 ; i<k ; i++){
            iter=iter->next;
        }
        iter->next=iter->next->next;
        return head;
        
    }
};
