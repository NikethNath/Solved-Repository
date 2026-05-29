class Solution {
public:
    vector<string> ans;
    class TrieNode{
        public:
        bool eol;
        vector<TrieNode*> next;

        TrieNode(){
            eol=false;
            next.resize(26,nullptr);

        }

    };
    void rf(int index, string s, TrieNode* head,string temp){
        if(index>s.length()-1){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        TrieNode * ptr=head;
        int i=index;
        while(i<=s.length()-1 && ptr->next[s[i]-'a']){
            ptr=ptr->next[s[i]-'a'];
            i++;
            if(ptr->eol){
                string tempy=s.substr(index,i-index);
                tempy+=" ";

                rf(i,s,head,temp+tempy);
            }
        }
        return;

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        TrieNode * head=new TrieNode;
        for(string s : wordDict){
            TrieNode * ptr=head;
            for(char c : s){
                if(ptr->next[c-'a']){
                    ptr=ptr->next[c-'a'];

                }
                else{
                    TrieNode * newnode=new TrieNode;
                    ptr->next[c-'a']=newnode;
                    ptr=newnode;
                }
            }
            ptr->eol=true;

        }
        rf(0,s,head,"");
        return ans;
        
    }
};
