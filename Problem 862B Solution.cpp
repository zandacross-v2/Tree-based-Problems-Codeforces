#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;
 
ll dfs(vector<ll> graph[],vector<bool> &visit,vector<ll> &count,ll i,ll u){
	visit[i] = true;
	if(count[u]==1){
		count[i]=2;
	}
	else{
		count[i]=1;
	}
	for(int j=0;j<graph[i].size();j++){
		if(graph[i][j] == u){
			continue;
		}
		if(visit[graph[i][j]]==false){
			dfs(graph,visit,count,graph[i][j],i);
		}
	}
	return 0;
}
 
int main(){
	ll n,u,v,set1=0,set2=0;
	cin >> n;
	vector<ll> graph[n+1],count(n+1,0);
	vector<bool> visit(n+1,false);
	for(int i=1;i<n;i++){
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	count[0]=2;
	dfs(graph,visit,count,1,0);
	for(int i=1;i<=n;i++){
		if(count[i]==1){
			set1++;
		}
		else{
			set2++;
		}
	}
	cout << set1*set2 - (n-1) << endl;
}
