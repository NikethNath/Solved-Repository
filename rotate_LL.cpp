
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int length=0;
        ListNode * iter=head;
        while(iter){
            length++;
            iter=iter->next;
        }
        if(length==0 || length==1 || k==0) return head;
        k=k%length;
        iter=head;

        for(int i=0 ; i< length-1 ; i++){
            iter=iter->next;

        }
        iter->next=head;
        iter=head;   //circular done
        for(int i=0 ; i<length-k-1 ; i++){
            iter=iter->next;
        }
        ListNode * ans=iter->next;
        iter->next=nullptr;
        return ans; 
        
    }
};
