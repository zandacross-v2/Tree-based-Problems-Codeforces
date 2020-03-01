#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ROOM freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
using namespace std;
 
double dfs(vector<ll> graph[],ll i,ll p){
	long double sum = 0;
	for(auto u : graph[i])
		if(u != p)
			sum += dfs(graph,u, i) + 1;
	return sum ? sum / (graph[i].size() - (p != -1)) : 0;
}
 
int main(){
	boost
    #ifndef ONLINE_JUDGE 
    ROOM
    #endif
	ll n,u,v;
	cin >> n;
	long double ans;
	vector<ll> graph[n+1];
	for(int i=1;i<n;i++){
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	ans = dfs(graph,1,-1);
	printf("%Lf\n",ans);
}
