#include <bits/stdc++.h>

using namespace std;



int main(){
    int h,w,n;
    cin >> h >> w >> n;
    int arr[h+1][w+1];
    memset(arr,0,sizeof(arr));
    int a,b;
    for(int i=1;i<=n;i++){
        cin >> a >> b;
        arr[a][b]=1;
    }
    int ans=0;
    int dp[h+1][w+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(arr[i][j]==0){
                dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                ans+=dp[i][j];
            }
            
        }
    }

    cout << ans << endl;


}
// long getNumSubarrays(vector<int> arr) {
//     int n = arr.size();
//     // arr.push_back(INT_MAX);
//     long count=0;
//     set<pair<int,int>> st;
//     for(int i=1;i<n;i++){
//         for(int j=i-1;j>=0;j--){
//             if(arr[i]>=arr[j] && st.find({i-1,j+1})==st.end()){
//                 cout << count << ":" << arr[i] << " " << arr[j] << endl;
//                 st.insert({i-1,j+1});
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// int main(){
//     int n;
//     cin >> n ;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     cout << getNumSubarrays(arr);

// }

// long long score(int r,int c,vector<vector<long long>>& arr){
//     if(arr[r-1][c-1]==0 || arr[0][0]==0){
//         return 0;
//     }
//     if(r==1 && c==1){
//         cout << arr[0][0] << endl;
//     }
//     if(arr[r-2][c-1]==0 && arr[r-1][c-2]==0){
//         return 0;
//     }
//     int index=0,j=0;
//     for(j=0;j<c;j++){

//         while(index>=0 && arr[index][j]==0){
//             index--;
//         }
//         if(index<0){
//             return 0;
//         }
//         if(j>0){
//             arr[index][j]+=arr[index][j-1];
//         }
//         for(int i=index+1;i<r;i++){
//             if(arr[i][j]!=0){
//                 arr[i][j]+=arr[i-1][j];
//                 index=i;
//             }else{
//                 break;
//             }
//         }
//     }
//     if(j>=c){
//         return 0;
//     }
//     // for(int i=0;i<r;i++){
//     //     for(int j=0;j<c;j++){
//     //         cout << arr[i][j] << " ";
//     //     }
//     //     cout << endl;
//     // }

//     return arr[r-1][c-1];
// }
// int main() {
// 	// your code goes here
//     int r,c;
//     cin >> r  >> c;
//     vector<vector<long long>> arr(r,vector<long long>(c));
//     for(int i=0;i<r;i++){
//         for(int j=0;j<c;j++){
//             cin >> arr[i][j];
//         }
//     }
    
//     cout << score(r,c,arr) << endl;



	
// 	return 0;
// }