#include<bits/stdc++.h>
#define ll long long int
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;
 
 
ll dfs(vector<ll> graph[],vector<bool> &visit,vector<ll> &count,ll i,ll u){
	visit[i] = true;
	if(graph[i].size()==1){
		count[i]=1;
		return 1;
	}
	ll sum=0;
	for(int j=0;j<graph[i].size();j++){
		if(graph[i][j] == u){
			continue;
		}
		if(visit[graph[i][j]]==false){
			sum += dfs(graph,visit,count,graph[i][j],i);
		}
	}
	if(sum>=3){
		count[i]=1;
	}
	return 0;
}
 
int main()
{
	ll n,c;
	cin >> n;
	vector<ll> graph[n+1];
	for(int i=2;i<=n;i++){
		cin >> c;
		graph[c].push_back(i);
		graph[i].push_back(c);
	}
	ll flag=0;
	vector<ll> count(n+1,0);
	vector<bool> visit(n+1,false);
	dfs(graph,visit,count,1,-1);
	for(int i=1;i<=n;i++){
		if(count[i]==0){
			flag=1;
			cout << "No" << endl;
			break;
		}
	}
	if(flag==0){
		cout << "Yes" << endl;
	}
}
