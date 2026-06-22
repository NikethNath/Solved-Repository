class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ptr1;
        ListNode * ptr2;
        ptr1=l1;
        ptr2=l2;
        int rem=0;
        ListNode * head= new ListNode(-1);
        ListNode * prev=head;

        while(ptr1 && ptr2){
            int sum=ptr1->val + ptr2->val + rem;
            rem=sum/10;
            sum=sum%10;
            ListNode * node=new ListNode(sum);
            prev->next=node;
            prev=node;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
            
        }

        if(!ptr1 && ptr2){
            while(ptr2){
                int sum=ptr2->val+rem;
                rem=sum/10;
                sum=sum%10;
                ListNode * node=new ListNode(sum);
                prev->next=node;
                prev=node;
                ptr2=ptr2->next;

            }

        }
        if(!ptr2 && ptr1){
                while(ptr1){
                int sum=ptr1->val+rem;
                rem=sum/10;
                sum=sum%10;
                ListNode * node=new ListNode(sum);
                prev->next=node;
                prev=node;
                ptr1=ptr1->next;

            }

        }
        if(rem!=0){
            ListNode * node=new ListNode(rem);
            prev->next=node;
        }
        return head->next;
        
    }
};
