#include <bits/stdc++.h>
using namespace std;

#define sz 26

struct Trie_node{
    Trie_node *child[sz];
    bool end_of_word=false;
    int cnt=0;

    Trie_node(){
        for(int i=0;i<sz;i++)
            child[i]=NULL;
    }
};

class Trie{
    public:
        Trie_node *root;
        Trie(){
            root=new Trie_node();
        }
        void Trie_insert(string s){
            Trie_node *curr_node=root;
            for(int i=0;i<s.size();i++){
                int curr_pos=s[i]-'a';
                if(curr_node->child[curr_pos]==NULL)
                    curr_node->child[curr_pos]=new Trie_node;
                curr_node->cnt++;
                curr_node=curr_node->child[curr_pos];
            }
            curr_node->end_of_word=true;
        }
        bool Trie_preffix_search(string s){
            Trie_node *curr_node=root;
            for(int i=0;i<s.size();i++){
                int curr_pos=s[i]-'a';
                if(curr_node->child[curr_pos]==NULL)
                    return false;
                curr_node=curr_node->child[curr_pos];
            }
            return true;
        }
        bool Trie_full_search(string s){
            Trie_node *curr_node=root;
            for(int i=0;i<s.size();i++){
                int curr_pos=s[i]-'a';
                if(curr_node->child[curr_pos]==NULL)
                    return false;
                curr_node=curr_node->child[curr_pos];
            }
            if(curr_node->end_of_word==false)
                return false;
            return true;
        }
        bool Trie_delete_util(string s,int index,Trie_node *curr_node){
            if(index==s.size()-1){
                curr_node->child[s[index]-'a']->end_of_word=false;
                if(curr_node->child[s[index]-'a']->cnt==0){
                    curr_node->child[s[index]-'a']=NULL;
                    curr_node->cnt--;
                }
                if(curr_node->cnt==0) return true;
                else return false;
            }
            bool temp=Trie_delete_util(s,index+1,curr_node->child[s[index]-'a']);
            if(temp){
                curr_node->child[s[index+1]-'a']=NULL;
                curr_node->cnt--;
                if(curr_node->cnt==0 && curr_node->end_of_word==false) return true;
                else return false;
            }
        }
        void Trie_delete(string s){
            Trie_delete_util(s,0,root);
        }
};

int main(){
    Trie t;
    t.Trie_insert("abcd");
    t.Trie_insert("abcg");

    cout<<t.Trie_preffix_search("ab")<<endl;
    // output: 1

    cout<<t.Trie_full_search("abcg")<<endl;
    // output: 1

    t.Trie_delete("abcg");

    cout<<t.Trie_preffix_search("abc")<<endl;
    // output: 1

    cout<<t.Trie_full_search("abcg")<<endl;
    // output: 0

    return 0;
}
