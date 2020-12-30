#include<cstdio>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
struct node
{
    int t[3][3],x,y,Can;
    int Last_Can,dir;
} St[370000];
int fac[]= {1,1,2,6,24,120,720,5040,40320};
//康托展开的数组
//康托展开就是把一组数据按照字典序排列的那组数据的序号

int vis[370000];
queue<int> Q;
char dr[]="rlud";
int  dx[]= {0,0,1,-1};
int  dy[]= {-1,1,0,0};
//方向数组，与实际的方向相反，因为是逆向操作
int Cantor(int *t)//对一组数据求康拓值
{
    int rev=0;
    for(int i=0; i<9; i++)
    {
        int counted=0;
        for(int j=i+1; j<9; j++)
            if(t[i]>t[j]) counted++;
        rev+=counted*fac[8-i];
    }
    return rev;
}
bool check(int x,int y) //检查这个点是不是在矩形内
{
    return x>=0&&x<3&&y>=0&&y<3;
}
void solve()//bfs求出所有的情况，并储存下来父节点
{
    while(!Q.empty()) Q.pop();
    node st;
    st.x=st.y=2;
    int s[3][3]= {1,2,3,4,5,6,7,8,0};
    int t[9];
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            t[i*3+j]=s[i][j];
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            st.t[i][j]=s[i][j];
    int StCan=Cantor(t);
    st.Can=StCan;
    st.Last_Can=-1;
    st.dir=-1;
    memset(vis,0,sizeof vis);
    vis[StCan]=1;
    St[StCan]=st;
    Q.push(StCan);
    int Sum=0;
    while(!Q.empty())
    {
        Sum++;
        int TempCan=Q.front();
        Q.pop();
        for(int i=0; i<4; i++)
        {
            node e=St[TempCan];
            int curx=e.x+dx[i];
            int cury=e.y+dy[i];
            if(check(curx,cury))
            {
                int c=e.t[curx][cury];
                e.t[curx][cury]=e.t[e.x][e.y];
                e.t[e.x][e.y]=c;
                e.x=curx;
                e.y=cury;
                int t[9];
                for(int i=0; i<3; i++)
                    for(int j=0; j<3; j++)
                        t[i*3+j]=e.t[i][j];
                e.Can=Cantor(t);
                e.Last_Can=TempCan;
                e.dir=i;
                if(!vis[e.Can])
                {
                    vis[e.Can]=1;
                    St[e.Can]=e;
                    Q.push(e.Can);
                }
            }
        }
    }
}
int main()
{
    char c[10];
    int t[9],x=0;
    solve();
    while(scanf("%s",c)!=EOF)
    {
        if(c[0]=='x') c[0]='0';
        t[0]=c[0]-'0';
        for(int i=1;i<9;i++)
        {
            scanf("%s",c);
            if(c[0]=='x') c[0]='0';
            t[i]=c[0]-'0';
        }
        int AnsCan=Cantor(t);
        if(vis[AnsCan])
        {
            int p=AnsCan;
            while(St[p].Last_Can+1)
            {
                printf("%c",dr[St[p].dir]);
                p=St[p].Last_Can;
            }
            printf("\n");
        }
        else
            printf("unsolvable\n");
    }
    return 0;
}
