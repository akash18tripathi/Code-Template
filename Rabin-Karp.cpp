int rabinKarp(string s, string p) {
	int n = s.length();
	int m = p.length();
	if(m>n){
	    return -1;
	}
	long long int hashVal=0;
	int prime=31;
	int mod = 1e9+9;
	long long int power=1;
	for(int i=0;i<m-1;i++){
	    power=(power*prime)%mod;
	}
	long long int currHash=0;
	for(int i=0;i<m;i++){
	    hashVal = (hashVal*prime + p[i]-'a'+1)%mod;
	    currHash = (currHash*prime + s[i]-'a'+1)%mod;
	}

	if(currHash==hashVal && s.substr(0,m)==p){
	    return 0;
	}

	int i=0,j=m;
	int pow=1;

	while(j<n){
	    currHash =( (currHash- ((s[i]-'a'+1)*power))*prime + (s[j]-'a'+1))%mod;
	    i++;
	    if(currHash<0){
		currHash += mod;
	    }
	    if(currHash==hashVal && s.substr(i,m)==p){
		return i;
	    }
	    j++;
	}
	if(currHash==hashVal && s.substr(i,m)==p){
	    return i;
	}

	return -1;
}
