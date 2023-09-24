vector<int> nextGreater(int arr[],int n){
    vector<int> ps(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            st.push(i);
            ps[i]=-1;
        }else{
            while(!st.empty() && arr[st.top()]<=arr[i] ){
                st.pop();
            }
            if(st.empty()){
                st.push(i);
                ps[i]=-1;
            }else{
                ps[i] = st.top();
                st.push(i);
            }

        }
    }
    return ps;
}
