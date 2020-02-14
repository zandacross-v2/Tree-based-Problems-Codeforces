#include<bits/stdc++.h>
#define ll long long int
#define ff first
#define ss second
#define MOD 1000000007
#define S(x) scanf("%lld",&x)
#define P(x) printf("%lld\n",x)
using namespace std;
 
ll N;
vector<ll> tree(1<<22,0);
vector<ll> v(1<<18,0);

// Time Complexity : O(2^n)
 
void build_tree(ll index,ll start,ll end,ll level){
	if(start==end){
		tree[index] = v[start];
		return; 
	}
	build_tree(2*index,start,(start+end)/2,level + 1);
	build_tree(2*index + 1,(start+end)/2 + 1 , end,level +1);
	if((N-level)&1){
		tree[index] = tree[2*index] | tree[2*index + 1];
	}else{
		tree[index] = tree[2*index] ^ tree[2*index + 1];
	}
	return;
}
 
void update_tree(ll index,ll start,ll end,ll level,ll x){
	if(start==end){
		tree[index] = v[start];
		return; 
	}
	if(x > (start+end)/2){
		update_tree(2*index + 1, (start+end)/2 + 1 , end,level +1,x);
	}else{
		update_tree(2*index,start,(start+end)/2,level + 1,x);
	}
	if((N-level)&1){
		tree[index] = tree[2*index] | tree[2*index + 1];
	}else{
		tree[index] = tree[2*index] ^ tree[2*index + 1];
	}
	return;
}
 
int main(){
	ll n,q,p,b;
	S(n);S(q);
	N=n;
	for(int i=0;i<(1<<n);i++){
		S(v[i+1]);
	}
	build_tree(1,1,1<<n,0);
	while(q--){
		S(p);S(b);
		v[p]=b;
		update_tree(1,1,1<<n,0,p);
		P(tree[1]);
	}
	return 0;
}
