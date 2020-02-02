#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;
ll dfs(vector<ll> graph[],vector<bool> &visit,ll i,ll n,ll dist){
	visit[i]=true;
	if(graph[i].size()==0){
		//cout << i <<" " << dist<< endl;
		return dist;
	}
	ll sum=0;
	for(int j=0;j<graph[i].size();j++){
		if(visit[graph[i][j]]==false){
			sum = max(sum,dfs(graph,visit,graph[i][j],n,dist+1));
			//cout << "****" << graph[i][j] << " " << sum << endl;
		}
	}
	return sum;
} 
 
int main()
{
	ll n,val,count=0;
	cin >> n;
	vector<ll> graph[n+1];
	std::vector<ll> v;
	for(int i=1;i<=n;i++){
		cin >> val;
		if(val==-1){
			v.push_back(i);
			continue;
		}
		graph[val].push_back(i);
	}
	vector<bool> visit(n+1,false);
	for(int i=0;i<v.size();i++){
		count = max(count,dfs(graph,visit,v[i],n,1));
	}
	cout << count << endl;
}
