#include <iostream>
#include <cstring>
using namespace std;

int dx[8]={-1,1,-2,2,-2,2,-1,1};
int dy[8]={-2,-2,-1,-1,1,1,2,2}; //lexicographical path

int flag[27][27], path[100][2]; //flag for visited location, path for recording path
int p, q;

int DFS(int x, int y, int r)  //x,y for current location, r for the num of next constexpr
{
    int nx, ny;
    
    if(r-1 == p*q) return 1;
    
    for(int i=0; i<8; i++){
        nx = x + dx[i];
        ny = y + dy[i];
        if(nx<1 || nx>p || ny<1 || ny>q || flag[nx][ny]) continue;
        flag[nx][ny] = 1;
        path[r][0] = nx;
        path[r][1] = ny;
        if(DFS(nx, ny, r+1)) return 1;
        flag[nx][ny] = 0;
    }
    
    return 0;
}

int main(){
    int casenum;
    scanf("%d", &casenum);
    
    for(int k=1; k<=casenum; k++){
        scanf("%d%d", &p, &q);
        memset(flag, 0, sizeof(flag));
        path[1][0]=path[1][1]=1;
        flag[1][1]=1;
        printf("Scenario #%d:\n", k);
        if(DFS(1,1,2))
        {
            for(int i=1; i<=p*q; i++){
                printf("%c%d",path[i][1]-1+'A',path[i][0]);
            }
            printf("\n");
        }
        else{
            printf("impossible\n");
        }
        if(k!=casenum) printf("\n");
    }
    return 0;
}