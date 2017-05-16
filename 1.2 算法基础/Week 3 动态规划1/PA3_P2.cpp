#include <iostream>
#include <algorithm>
using namespace std;

struct point{
	int row, col, height;
	bool operator<(const point& p){
		return height < p.height;
	}
};

point parray[101*101];
int pmap[101][101];
int len[101][101];
int row, column;

int maxStep(int n)
{
    int maxStep = 1;
    for (int i = 0; i < n; ++i) {
        int r = parray[i].row;
        int c = parray[i].col;
        int h = parray[i].height;
        
        if (r > 1 && pmap[r-1][c] > h) {
            len[r-1][c] = max(len[r-1][c], len[r][c] + 1);
            if (len[r-1][c] > maxStep) {
                maxStep = len[r-1][c];
            }
        }
        if (r < row && pmap[r+1][c] > h) {
            len[r+1][c] = max(len[r+1][c], len[r][c] + 1);
            if (len[r+1][c] > maxStep) {
                maxStep = len[r+1][c];
            }
        }
        if (c > 1 && pmap[r][c-1] > h) {
            len[r][c-1] = max(len[r][c-1], len[r][c] + 1);
            if (len[r][c-1] > maxStep) {
                maxStep = len[r][c-1];
            }
        }
        if (c < column && pmap[r][c+1] > h) {
            len[r][c+1] = max(len[r][c+1], len[r][c] + 1);
            if (len[r][c+1] > maxStep) {
                maxStep = len[r][c+1];
            }
        }
    }
    return maxStep;
}

int main()
{
    cin>>row>>column;
    int k = 0;
    for (int i = 1; i < row+1; ++i) {
        for (int j = 1; j < column+1; ++j) {
            parray[k].row = i;
            parray[k].col = j;
            cin>>parray[k].height;
            pmap[i][j] = parray[k].height;
            len[i][j] = 1; 
            k++;
        }
    }
    sort(parray, parray+k);
    int maxlen = maxStep(k);
    cout << maxlen << endl;
	system("pause");
    return 0;
}



