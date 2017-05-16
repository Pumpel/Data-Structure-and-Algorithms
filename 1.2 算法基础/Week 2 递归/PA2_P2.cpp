#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct cmp{
	bool operator()(string a, string b){
		return a>b;
	}
};

void print(int depth, string s){
	for (int i = 0; i < depth; i++){
		cout << "|	";
	}
	cout << s << endl;
}

int fun(int depth, string s){
	priority_queue<string, vector<string>, cmp> pq;
	if (depth == 0){
		cout << "ROOT: " << endl;
		if (s[0] == 'f') 
			pq.push(s);
		if (s[0] == 'd')
			fun(depth+1, s);
		if (s[0] == ']' || s[0] == '*'){
			while (!pq.empty()){
				print(depth, pq.top());
				pq.pop();
			}
			return 1;
		}
	}
	else print(depth, s);

	while(cin >> s){
		if (s[0] == 'f') 
			pq.push(s);
		if (s[0] == 'd')
			fun(depth+1, s);
		if (s[0] == ']' || s[0] == '*'){
			while (!pq.empty()){
				print(depth, pq.top());
				pq.pop();
			}
			if (s[0] == '*')
				cout << endl;
			return 1;
		}
	}
}

int main(){
	int n = 0;
	while(1){
		string s;
		cin >> s;
		if (s[0] == '#')
			return 0;
		n++;
		if(n > 1) cout << endl;
		cout << "DATA SET " << n << ": " << endl;
		fun(0, s);
		if(!fun(0, s)) return 0;
	}
	
	system("pause");
	return 0;
}