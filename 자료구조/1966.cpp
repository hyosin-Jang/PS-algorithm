#include<cstdio>
#include<queue>
#pragma warning(disable :4996)
using namespace std;
 
int main(void)
{
    int t;
    scanf("%d", &t);
    for (int testcase = 0; testcase < t; testcase++)
    {
        int N, M,cnt = 0;
        queue <pair<int, int>> q;
        priority_queue <int> pq;
 
        scanf("%d %d",&N,&M);
        for (int i = 0; i < N; i++)
        {
            int a;
            scanf("%d", &a);
            q.push({i,a});
            pq.push(a);
        }
 
        while (!q.empty())
        {
            int nowidx = q.front().first;
            int nowval = q.front().second;
            q.pop();
 
            if (pq.top() == nowval)
            {
                pq.pop();
                cnt++;
                if (nowidx == M)
                {
                    printf("%d\n", cnt);
                    break;
                }
            }
            else {
                q.push({ nowidx,nowval });
            }
        }
    }
    return 0;
}
