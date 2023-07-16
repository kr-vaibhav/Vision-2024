https://practice.geeksforgeeks.org/problems/word-ladder/1

class Solution {
    
    unordered_set<string>st;
    
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        int n = wordList.size();
        
        for(int i=0;i<n;i++)st.insert(wordList[i]);
        
        st.erase(startWord);
        
        queue<pair<int,string>>q;
        
        q.push({1,startWord});
        
        while(!q.empty()){
            
            string word = q.front().second;
            int times   = q.front().first;
            q.pop();
            
            if(word==targetWord)return times;
            
            for(int i=0;i<word.length();i++){
                
                char change = word[i];
                
                for( char ch ='a';ch<='z';ch++){
                    
                    word[i]=ch;
                    
                    if(st.find(word)!=st.end()){
                        
                        st.erase(word);
                        q.push({times+1,word});
                    }
                }
                
                word[i] = change;
            }
        }
        
        return 0;
    
