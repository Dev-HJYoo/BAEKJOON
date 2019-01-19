/*
	2019.1.20
	��.. ���ͳݿ��� ���� ������ �ľ��ϰ� �������.
	dfs ��쿡�� ��� �Լ��� ����߰�
	bfs ��쿡�� ť�� ����ؼ� �����ߴ�.
	dfs�� stack���� ���� �� �� �ִٰ� �ϴµ� �ѹ� �� �����غ��� �ڴ�.
	 
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

// ���⿡�� ��� �ȵǳ�... ������ �Ἥ ��F�� dfs�� �����ұ.. 
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
