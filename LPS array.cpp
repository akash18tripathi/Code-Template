    vector<int> lps(string& word){
        int n = word.length();
        vector<int> lp(n,0);
        int index=0;
        for(int i=1;i<n;){
            if(word[i]==word[index]){
                index++;
                lp[i]=index;
                i++;
            }else{
                if(index!=0){
                    index=lp[index-1];
                }else{
                    lp[i]=0;
                    i++;
                }
            }
        }
        return lp;
    }
