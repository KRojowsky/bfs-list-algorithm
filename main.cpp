#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m, u, v;
	cin>>n>>m;
	
	list <int> *L;
	L = new list <int> [n];
	
	for(int i=0; i<m; ++i){
		cin>>u>>v;
		
		L[u].push_back(v);
		if(u != v)    L[v].push_back(u);
	}
	
	bool *visited = new bool [n];
	
	for(int i=0; i<n; ++i){
		visited[i] = false;
	}
	
	queue <int> Q;
	
	cin>>u;
	
	visited[u] = true;
	Q.push(u);
	
	cout<<'\n';
	
	while(!Q.empty()){
		u = Q.front();
		Q.pop();
		
		cout<<u<<" ";
		
		for(list <int> :: iterator it = L[u].begin(); it != L[u].end(); ++it){
			if(!visited[*it]){
				visited[*it] = true;
				Q.push(*it);
			}
		}
	}
	
	delete [] visited;
	delete [] L;
	
	return 0;
}

