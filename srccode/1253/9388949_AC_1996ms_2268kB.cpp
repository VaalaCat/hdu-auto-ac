
#include <stdio.h>  
#include <queue>  
using namespace std;  
  
struct P{       //状态结构体  
    int x,y,z;  
    int t;  
};  
  
queue<P> Q;               //队列中元素为状态  
int maze[50][50][50];   //保存立方体  
bool mark[50][50][50];  
  
int go[6][3] = {1,0,0,-1,0,0,0,1,0,0,-1,0,0,0,1,0,0,-1};    //方向数组。每步只能向6个方向走  
  
int BFS(int a , int b , int c)  
{  
    while(!Q.empty()){  
        P tmp = Q.front();  
        Q.pop();  
        for(int i = 0 ; i < 6 ; ++i){  
            int nowx = tmp.x + go[i][0];  
            int nowy = tmp.y + go[i][1];  
            int nowz = tmp.z + go[i][2];  
            int nowt = tmp.t + 1;  
            if(nowx < 0 || nowx >= a || nowy < 0 || nowy >= b || nowz < 0 || nowz >= c)  
                continue;  
            if(maze[nowx][nowy][nowz] == 1) continue;  
            if(mark[nowx][nowy][nowz] == true) continue;  
              
  
            P newp;  
            newp.x = nowx; newp.y = nowy ; newp.z = nowz;  
            newp.t = nowt;  
            mark[nowx][nowy][nowz] = true;  
            Q.push(newp);  
            if(nowx == a-1 && nowy == b-1 && nowz == c-1){  
                return newp.t;  
            }  
        }  
    }  
    return -1;  
}  
  
int main()  
{  
    int K;  
    scanf("%d",&K);  
    while(K--){  
        int a,b,c,T;  
        scanf("%d%d%d%d",&a,&b,&c,&T);  
        for(int i = 0 ; i < a ; ++i){  
            for(int j = 0 ; j < b ; ++j){  
                for(int k = 0 ; k < c ; ++k){  
                    scanf("%d",&maze[i][j][k]);  
                    mark[i][j][k] = false;  
                }  
            }  
        }  
  
        while(!Q.empty()) Q.pop();  
        mark[0][0][0] = true;  
        P tmp;  
        tmp.x = 0;  
        tmp.y = 0;  
        tmp.z = 0;  
        tmp.t = 0;  
        Q.push(tmp);  
  
        int ans = BFS(a,b,c);  
        if(ans <= T) printf("%d\n",ans);  
        else printf("-1\n");  
    }  
    return 0;  
}  