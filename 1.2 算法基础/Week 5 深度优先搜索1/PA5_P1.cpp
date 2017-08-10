#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char chess[10][10];
int used[10];
int n, k;
int total, m;

void DFS(int cur){
    if (k == m){
        total++;
        return;
    }
    
    if (cur >= n){
        return;
    }
    
    for (int j = 0; j < n; j++){
        if (used[j] == 0 && chess[cur][j] == '#'){
            used[j] = 1;
            m++;
            DFS(cur+1);
            used[j] = 0;
            m--;
        }
    }
    
    DFS(cur+1);
}

int main(){
    int i, j;
    while(scanf("%d%d", &n, &k) && n != -1 && k != -1){
        total = 0;
        m = 0;
        for (i = 0; i < n; i++){
            scanf("%s", &chess[i]);
        }
        memset(used, 0, sizeof(used));
        DFS(0);
        printf("%d\n", total);
    }
    return 0;
}