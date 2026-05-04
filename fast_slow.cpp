
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode * fast=head;
        ListNode * slow=head;
        while(true){
            if(fast->next && fast->next->next){
                fast=fast->next->next;
                slow=slow->next;
                if(fast==slow) return true;
            }
            else{
                return false;
            }
        }
        return false;
        
    }
};
