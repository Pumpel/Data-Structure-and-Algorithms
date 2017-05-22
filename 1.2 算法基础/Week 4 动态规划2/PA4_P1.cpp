#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 250

/*

dp[i][j]表示i分解成最大元素不超过j的整数之和的方案数（每种方案自然可以对应成一个不递减的序列）
它代表用1，2，3...j这些数字，每个数字可以取任意多个，使得和为i，有多少种方式
分解成子问题，即选取的j的个数确定时（设为k个），剩余整数之和i-k*j分解成最大元素不超过j-1的方案数之和 
dp[i][j] = dp[i - 0*j][j - 1](j取0个，i分解成最大元素不超过j-1)
 + dp[i - 1*j][j - 1](j取1个，所以剩余的为i-j分解成最大元素不超过j-1) 
 + dp[i - 2*j][j - 1](j取2个，所以剩余的为i-2*j分解成最大元素不超过j-1) 
 + ... 一直加到"i - k*p < 0"结束
 
dp[i][i]求到的是i分解成最大元素不超过i的整数之和的方案数，即单调不递减序列
这里求的是单峰回文序列，即单调不递减再单调不递增，后面与前面是对应的，所以，
对于奇数i，只有一种情况，
枚举中间取值（会是奇数），设为mid，左边就是个单调不递减序列，
对于每一个mid值，都有方案数dp[(i-mid)/2][min((i-mid)/2, mid//有mid是确保mid前的元素不会超过mid，保持单调不递减)]，
因为右边和左边相对应，所以左边每一种方案，右边都是唯一确定的，
如 7: (7), (1 5 1), (2 3 2), (1 1 3 1 1), (1 1 1 1 1 1 1) 
mid 取 7，dp[(7-7)/2][min((7-7)/2, 7)] = 1//mid自己本身就是一种方案
mid 取 5，dp[(7-5)/2][min((7-5)/2, 5)] = 1 
mid 取 3，dp[(7-3)/2][min((7-3)/2, 3)] = dp[2][2] = 2，即2可分为1 1和2，回文的，所以后面是唯一对应的 
mid 取 1，dp[(7-1)/2][min((7-1)/2, 1)] = dp[3][1] = 1，即3分为1 1 1(最大元素不超过1)，回文的，所以后面是唯一对应的 

对于偶数i，分为两种情况， 
如8：第一类(8), (1 6 1), (2 4 2), (1 1 4 1 1), (1 2 2 2 1),(1 1 1 2 1 1 1)；
mid取8，6，4，2，对应dp[0][0] + dp[1][1] + dp[2][2] + dp[3][2] = 1 + 1 + 2 + 2
注意不能包含mid取0的情况，因为dp[0][0]等于1，多加了1会导致结果有问题 
第二类(4 4), (1 3 3 1), (2 2 2 2),(1 1 2 2 1 1), (1 1 1 1 1 1 1 1)。
dp[i/2][i/2] = dp[4][4] = 5

*/

int main(){
	int unimodal[MAXN][MAXN];
	for (int i = 0; i < MAXN; i++){
		unimodal[i][0] = 1;
		unimodal[0][i] = 1;
	}

	for (int i = 1; i < MAXN; i++){
		unimodal[i][1] = 1;
	}

	for (int i = 1; i < MAXN; i++){
		for (int j = 2;  j < MAXN; j++){
			unimodal[i][j] = unimodal[i - 0*j][j - 1];
			int k = 1;
			while (i - k* j >= 0){
				unimodal[i][j] += unimodal[i - k*j][j - 1];
				k++;
			}
		}
	}

	int n;
	long long num;
	cin >> n;
	while(n){
		num = 0;
		if (n%2 == 1){
			for (int mid=n; mid>0; mid -=2){
				num += unimodal[(n - mid) / 2][min((n - mid) / 2, mid)];
			}
		}
		else{
			for (int mid=n; mid>0; mid-=2){
				num += unimodal[(n - mid) / 2][min((n - mid) / 2, mid)];
			}
			num += unimodal[n/2][n/2];
		}
		
		cout << n << " " << num << endl;
		cin >> n;
	}

	system("pause");
	return 0;
}
