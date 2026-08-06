class TrieNode{
public:

TrieNode *Node[26];
bool isEnd;

TrieNode(){
    for(int i=0;i<26;i++){
        Node[i]=NULL;
    }
    isEnd=false;
}

};

class WordDictionary {
public:
    TrieNode*root;
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode*curr=root;

        for(int i=0;i<word.length();i++){
            int  idx=word[i]-'a';
            if(curr->Node[idx]==NULL){
                TrieNode*newNode=new TrieNode();
                curr->Node[idx]=newNode;
            }

            curr=curr->Node[idx];
        }

        curr->isEnd=true;
    }

    
    bool Search(string word,TrieNode*root,int i){
        if(i==word.length()){
            return root->isEnd;
        }
        
        if(word[i]!='.'){
            int idx=word[i]-'a';
            if(root->Node[idx]!=NULL)
            return Search(word,root->Node[idx],i+1);
        }
        else{
            for(int j=0;j<26;j++){
                if(root->Node[j]!=NULL){

                    if(Search(word,root->Node[j],i+1)){
                        return true;
                    }
                }
            }
        }

        return false;
        
    }
    bool search(string word) {
        return Search(word,root,0);       
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */