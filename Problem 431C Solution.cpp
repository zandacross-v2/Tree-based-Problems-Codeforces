#include<bits/stdc++.h>
#define ll long long int
#define ff first
#define ss second
#define pq priority_queue
#define MOD 1000000007
using namespace std;

// Time Complexity: O(nk)
int main(){
	ll n,k,d;
	cin >> n >> k >> d;
 
	ll dp[n+1][2];
	dp[0][0]=1;
	dp[0][1]=0;
	for(int i=1;i<=n;i++){
		dp[i][0]= dp[i][1]=0;
		for(int j=1;j<=k;j++){
			if(i-j<0){
				break;
			}
			if(j<d){
				dp[i][0] = (dp[i][0]%MOD +  dp[i-j][0]%MOD)%MOD;
				dp[i][1] = (dp[i][1]%MOD + dp[i-j][1]%MOD)%MOD;
			}
			else{
				dp[i][1] = (dp[i][1]%MOD +  dp[i-j][0]%MOD)%MOD;
				dp[i][1] = (dp[i][1]%MOD + dp[i-j][1]%MOD)%MOD;
			}
		}
	}
	cout << dp[n][1] << endl;
}
