#include<cstdio>
#include<algorithm>

using namespace std;

int K; //V은 가치 K는 총 무게 
int N;
int dp[101][100001]; //dp[n][k]에 가치가 들어감 
int goods[100][2];

int back(int n, int k) // dp[n][0]은 nth 무게 k는 무게 , dp[n][k] nth 최고 가치 
{
   if(n==N) return (k >=0 ? 0 : -10000);
   if(dp[n][k] != -1) return dp[n][k];
   
   int result = back(n+1, k);
   if(k - goods[n][0] >= 0)   
   {
      result = max(result, back(n, k-goods[n][0]) + goods[n][1]);
      
   }
   dp[n][k] = result;
   
   return result;
}

int main()
{
   scanf("%d %d", &N, &K);
   
   for(int i=0; i<N; i++)
   {
      scanf("%d %d", &goods[i][0], &goods[i][1]);
   //   printf("%d %d", goods[i][0], goods[i][1]);
   }
   for(int i=0; i<101; i++)
      for(int j =0; j<100001; j++)
         dp[i][j] = -1;

      
   printf("%d \n", back(0, K));
   
   return 0;
}