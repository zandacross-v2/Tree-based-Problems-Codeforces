#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;
 
ll ans;
void dfs(vector<ll> graph[],ll i,ll dist,ll m,vector<ll> cats,ll p){
	dist += cats[i];
	if(cats[i]==0){
		dist=0;
	}
	if(dist>m){
		return;
	}
	ll sum=0;
	for(int j=0;j<graph[i].size();j++){
		if(graph[i][j]==p){
			continue;
		}
		sum++;
		dfs(graph,graph[i][j],dist,m,cats,i);
	}
	if(sum==0){
		ans++;
	}
} 
 
int main()
{
	ll n,m,c,r,l,dist=0;
	cin >> n >> m;
	vector<ll> graph[n+1];
	vector<ll> cats(n+1,0);
	for(int i=1;i<=n;i++){
		scanf("%lld",&c);
		cats[i]=c;
	}
	for(int i=0;i<n-1;i++){
		scanf("%lld%lld",&l,&r);
		graph[l].push_back(r);
		graph[r].push_back(l);
	}
	dfs(graph,1,dist,m,cats,-1);
	printf("%lld\n",ans);
}
