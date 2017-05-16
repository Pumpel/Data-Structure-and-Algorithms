#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int MAXN = 10001;

int twosum(vector<int>& a, vector<int>& b, int target){
	int count = 0;
	for (int i=0; i<a.size(); i++){
		if (a.at(i)>0){
			if(target >= i){
				count += a.at(i)*b.at(target-i);
			}
		}
	}
	return count;
}

int main() {
    int n;
    cin >> n;
    int sum;
    int a, b;
    int tmpa, tmpb; 
    while(n--) {
        cin >> sum;
		vector<int> va(MAXN, 0), vb(MAXN, 0);

        cin >> a;
        for(int i=0; i<a; i++) {
            cin >> tmpa;
            va.at(tmpa)++;
        }

        cin >> b;
        for(int i=0; i<b; i++) {
            cin >> tmpb;
            vb.at(tmpb)++;
        }
        cout << twosum(va, vb, sum) << endl;
    }
	system("pause");
    return 0;
}
