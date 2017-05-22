#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// similar to knapsack problem w/o repeat: Wi is weight, Di is the value, Total weight is M

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> weight(n, 0);
	vector<int> value(n, 0);
	vector<int> maxVal(m+1, 0);

	for (int i=0; i <n; i++){
		cin >> weight[i] >> value[i];
	}

	for (int i=0; i<n; i++){
		for (int w=m; w>=weight[i]; w--){
			maxVal[w] = max(maxVal[w-weight[i]]+value[i], maxVal[w]);
		}
	}

	cout << maxVal[m] << endl;
	system("pause");
	return 0;
}
