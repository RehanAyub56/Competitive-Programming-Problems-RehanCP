class TrieNode{
public:
    TrieNode*Node[26];
    bool isEnd;

    TrieNode(){
        for(int i=0;i<26;i++){
            Node[i]=NULL;
        }
        isEnd=false;
    }
};
class Trie {
public:
    TrieNode*root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        int l=0;
        TrieNode*curr=root;
        for(int i=0;i<word.length();i++){
            int idx=word[i]-'a';

            if(curr->Node[idx]==NULL){
                TrieNode*newNode=new TrieNode();
                curr->Node[idx]=newNode;

            }
            curr=curr->Node[idx];
        }

        curr->isEnd=true;

    }
    
    bool search(string word) {
        TrieNode*curr=root;
        for(int i=0;i<word.length();i++){
            int idx=word[i]-'a';
            if(curr->Node[idx]==NULL){
                return false;
            }

            curr=curr->Node[idx];
        }

        if(curr->isEnd){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        TrieNode*curr=root;

        for(int i=0;i<prefix.length();i++){
            int idx=prefix[i]-'a';

            if(curr->Node[idx]==NULL){
                return false;
            }

            curr=curr->Node[idx];
 
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */