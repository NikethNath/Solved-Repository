class Solution {
public:
class Node{
    public:
    bool eol;
    vector<Node *> arr;
    Node(){
        this->eol=false;
        arr.resize(10,nullptr);
    }

};

Node * createTrie(vector<int> &arr){
    Node *head= new Node();
    for(int num : arr){
        int temp=num;
        stack<int> stk;
        while(temp!=0){
            stk.push(temp%10);
            temp=temp/10;
        }
        Node * ptr=head;
        while(!stk.empty()){
            int a=stk.top();
            stk.pop();
            if(ptr->arr[a]){
                ptr=ptr->arr[a];
            }
            else{
                
                ptr->arr[a]=new Node();
                ptr=ptr->arr[a];
            }

        }
        ptr->eol=true;

    }
    return head;

}
int lengthoflongestprefix(int num, Node * head){
    stack<int> stk;
    int a=num;
    while(a!=0){
        stk.push(a%10);
        a=a/10;
    }
    Node * temp=head;
    int length=0;
    int templength=0;
    while(!stk.empty()){
        int b=stk.top();
        stk.pop();
        if(temp->arr[b]){
            temp=temp->arr[b];
            templength++;
            if(temp->eol=true) length=templength;
        }
        else break;

    }
    return length;

}
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Node * head=createTrie(arr1);
        int ans=0;
        for(int a : arr2){
            ans=max(ans,lengthoflongestprefix(a,head));
        }
        return ans;


        
    }
};
