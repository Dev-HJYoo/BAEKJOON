/*
	2019.1.20
	음.. 인터넷에서 대충 원리를 파악하고 만들었따.
	dfs 경우에는 재귀 함수를 사용했고
	bfs 경우에는 큐를 사용해서 구현했다.
	dfs는 stack으로 구현 할 수 있다고 하는데 한번 더 생각해봐야 겠다.
	 
*/
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool graph[1001][1001] = {0};
bool check1[1001] = {0};
bool check2[1001] = {0};
int n;

void dfs(int w){
	
	for(int i = 1; i<=n; i++){
		if(graph[i][w] && check1[i]){
			cout<<i<<" ";
			check1[i] = false;
			dfs(i);
		}
	}	
}

// 여기에서 계속 안되네... 스택을 써서 어덯게 dfs를 구현할까나.. 
void dfs2(int w){
	stack<int> s;
	s.push(w);
	check1[w] = false;
	int total[1001] = {0};
	int z = n;
	while(true){
		int a = s.top();
		total[z--] = s.top();
		s.pop();
		if(s.empty())
			break;
		for(int i = 1; i<=n; i++){
			if(check1[i] && graph[i][a] ){
				s.push(i);
				check1[i] = false;
				break;
			}
		}
	}
	for(int i = 1; i<=n; i++)
		cout<<total[i]<<" ";
} 

void bfs(int w){
	
	queue<int> q;
	q.push(w);
	check2[w] = false;
	while(true){
		if(q.empty())
			break;
		cout<<q.front()<<" ";
		int a = q.front();
		for(int i = 1; i<=n;i++){
			if(graph[i][a] && check2[i]){
				q.push(i);
				check2[i] = false;
			}
		}
		q.pop();
	}
}
int main(void){
	 int m,v;
	 cin>>n>>m>>v;
	 
	 int a,b;
	 
	 for(int i = 1; i<=n ; i++){
	 	check1[i] = true;
	 	check2[i] = true;
	 }
	 for(int i = 1; i<=m; i++){
	 	cin>>a>>b;
	 	graph[a][b] = true;
	 	graph[b][a] = true;
	 } 
	 
	cout<<v<<" ";
	check1[v] = false;
	dfs(v);
	
	for(int i = 1; i<=n; i++)
		check1[i] = true;
	cout<<"\n";
	
	dfs2(v);
	
	cout<<"\n";
	
	
//	bfs(v);
} 
