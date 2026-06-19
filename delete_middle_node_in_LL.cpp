class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int length=0;
        ListNode * temp=head;
        while(temp){
            length++;
            temp=temp->next;
        }
        if(length==1){
            return nullptr;
        }

        length=length/2;
        ListNode * prev=nullptr;
        ListNode * curr=head;
        for(int i=0 ;i<length ; i++){
            prev=curr;
            curr=curr->next;

        }
        prev->next=curr->next;
        return head;


        
    }
};
