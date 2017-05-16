#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int clocks_init[10]={0}, clocks_adj[10]={0}, op[10]={0};
vector<int> result;
const int operations[10][10] =
{
    {0},
    //  A  B  C  D  E  F  G  H  I
    {0, 1, 1, 0, 1, 1, 0, 0, 0, 0},  //op1: ABDE
    {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},  //op2: ABC
    {0, 0, 1, 1, 0, 1, 1, 0, 0, 0},  //op3: BCEF
    {0, 1, 0, 0, 1, 0, 0, 1, 0, 0},  //op4: ADG
    {0, 0, 1, 0, 1, 1, 1, 0, 1, 0},  //op5: BDEFH
    {0, 0, 0, 1, 0, 0, 1, 0, 0, 1},  //op6: CFI
    {0, 0, 0, 0, 1, 1, 0, 1, 1, 0},  //op7: DEGH
    {0, 0, 0, 0, 0, 0, 0, 1, 1, 1},  //op8: GHI
    {0, 0, 0, 0, 0, 1, 1, 0, 1, 1}  //op9: EFHI
};

void operate(int op_num, int op_counts){
	for(int k=1; k<=9; k++){
		clocks_adj[k] += operations[op_num][k] * op_counts;
		clocks_adj[k] %= 4;
	}
}

int guess(){
	op[4] = (4 - clocks_adj[1]) % 4;
	operate(4, op[4]);
	op[5] = (4 - clocks_adj[2]) % 4;
	operate(5, op[5]);
	op[6] = (4 - clocks_adj[3]) % 4;
	operate(6, op[6]);
	op[7] = (4 - clocks_adj[4]) % 4;
	operate(7, op[7]);
	op[8] = (4 - clocks_adj[7]) % 4;
	operate(8, op[8]);
	if(clocks_adj[5]==clocks_adj[6] && clocks_adj[5]==clocks_adj[8] && clocks_adj[5]==clocks_adj[9]){
		op[9] = (4 - clocks_adj[9]) % 4;
		operate(9, op[9]);
		int steps = 0;
		for(int k=1; k<=9; k++){
			steps += op[k];
		}
		return steps;
	}
	return 101;
}

int enumerate(){
	int c = 0;
	int minsteps = 101;
	int steps = 0;
	while(c<64){
		op[3] = c / 16;
		op[2] = c % 16 / 4;
		op[1] = c % 4;
		memcpy(clocks_adj, clocks_init, sizeof(clocks_init));
		operate(3, op[3]);
		operate(2, op[2]);
		operate(1, op[1]);
		steps = guess();
		if (steps<minsteps){
			minsteps = steps;
			result.clear();
			for(int k=1; k<=9; k++){
				while(op[k]--){
					result.push_back(k);
				}
			}
		}
		c++;
	}
	return minsteps;
}

int main(){
	for(int k=1; k<10; k++){
		cin>>clocks_init[k];
	}

	if(enumerate()<101){
		for(vector<int>::iterator it = result.begin(); it != result.end(); it++){
			cout << *it << ' ';
		}
		cout << endl;
	}
	system("pause");
	return 0;
}






