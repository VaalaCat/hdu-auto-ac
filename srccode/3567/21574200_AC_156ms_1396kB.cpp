//2017-09-23
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

const int INF = 0x3f3f3f3f;
int a[10][10], target, postion[10], b[10], d[10000], sx, sy, deep;
bool ok;
map<int, bool> vis;
char dir[4] = {'d', 'l', 'r', 'u'};
int dx[4] = {1, 0, 0, -1};//分别对应上下左右四个方向
int dy[4] = {0, -1, 1, 0};
int kase;

int Astar()
{
    int h = 0;
    for(int i = 1; i <= 3; i++)
      for(int j = 1; j <= 3; j++)
        if(a[i][j]!=0)
        {
            int num = a[i][j];
            int nx = (postion[num]-1)/3;
            int ny = (postion[num]-1)%3;
            h += (abs(i-nx-1)+abs(j-ny-1));
        }
    return h;
}

int toInt()//把矩阵转换为int型数字
{
    int res = 0;
    for(int i = 1; i <= 3; i++)
      for(int j = 1; j <= 3; j++)
        res = res*10+a[i][j];
    return res;
}

void IDAstar(int x, int y, int pre, int step)
{
    if(ok)return ;
    int h = Astar();
    if(!h && toInt()==target)//找到答案
    {
        printf("Case %d: %d\n", ++kase, step);
        for(int i = 0; i < step; i++)
          printf("%c", dir[d[i]]);
        printf("\n");
        ok = 1;
        return ;
    }
    if(step+h>deep)return ;//现实＋理想<现状，则返回，IDA*最重要的剪枝
    int now = toInt();
    //if(vis[now])return ;//如果状态已经搜过了，剪枝，避免重复搜索
    //vis[now] = true;
    for(int i = 0; i < 4; i++)
    {
        if(i+pre == 3)continue;
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=1&&nx<=3&&ny>=1&&ny<=3)
        {
            d[step] = i;
            swap(a[x][y], a[nx][ny]);
            IDAstar(nx, ny, i, step+1);
            swap(a[x][y], a[nx][ny]);
            d[step] = 0;
        }
    }
    return;
}

char str1[20], str2[20];

int main()
{
    int T;
    scanf("%d", &T);
    char ch;
    kase = 0;
    while(T--)
    {
        ok = false;
        deep = 0;
        int cnt = 0;
        scanf("%s%s", str1, str2);
        for(int i = 1; i <= 3; i++)
        {
            for(int j = 1; j <= 3; j++)
            {
                ch = str1[(i-1)*3+j-1];
                if(ch == 'X')
                {
                    a[i][j] = 0;
                    sx = i;
                    sy = j;
                }else
                  a[i][j] = ch - '0';
                b[cnt++] = a[i][j];
            }
        }
        target = 0;
        getchar();
        for(int i = 1; i <= 9; i++){
            target *= 10;
            ch = str2[i-1];
            if(ch == 'X')
              target += 0;
            else{
                target += ch-'0';
                postion[ch-'0'] = i;
            }        
        }
        while(!ok)
        {
            vis.clear();
            IDAstar(sx, sy, INF, 0);
            deep++;//一层一层增加搜索的深度
        }
    }

    return 0;
}