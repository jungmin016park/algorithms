/*


1278
: 배낭채우기2

제한시간: 1000 ms   
메모리제한:
64 MB

해결횟수: 2232 회    시도횟수:
6361 회  




문제

한컴
보석상에 도둑이 침입했다. 도둑은
배낭에 보석을 훔치려고 한다. 이때, 훔친
보석의 무게가 W를
넘어가면 배낭이 망가진다.

각
보석의 값어치와 무게가 주어질 때, 도둑은
총 무게가 W를
넘지 않으면서 보석의 총 값어치가 최대가 되도록 보석을 배낭에 담으려고 한다.
이때 배낭에 담을 수 있는 최대 값어치를 구하시오.



입력
형식

입력의
첫 줄은 보석의 개수 N(1≤N≤1,000)과
배낭의 용량 W(1≤W≤10,000)가
주어진다.

둘째
줄부터 N+1줄에는
각 보석의 무게 Wi(1≤Wi≤W)와
값어치 Pi가
주어진다. (단, 보석은
각 종류별로 1개씩이다.)



출력형식

출력은
보석의 무게와 값어치가 주어질 때 총 무게가 W를
넘지 않으면서 보석의 총 값어치가 최대가 되는 최대값을 출력한다.




*/


#include <stdio.h> int N, W; struct sStuff{    int Weight;    int Price;};struct sStuff Stuff[1001];  /*int ResultPriceSum = 0;void Process(int Cur, int WeightSum, int PriceSum){ if (Cur < N) {  // 현재것을 선택한 경우  if (WeightSum + Stuff[Cur].Weight < W)   Process(Cur + 1, WeightSum + Stuff[Cur].Weight, PriceSum + Stuff[Cur].Price);  // 현재것을 선택하지 않은 경우  Process(Cur + 1, WeightSum, PriceSum); }  if (ResultPriceSum < PriceSum)  ResultPriceSum = PriceSum;}*/  #define MAX(a,b) a>b?a:b   int ResultPriceSum = 0;int WeightSum[1001][10001];void DP_Process(){    for (int n = 0; n <= N; n++)        for (int w = 0; w <= W; w++)            WeightSum[n][w] = -1;     ResultPriceSum = Stuff[0].Price;     WeightSum[0][Stuff[0].Weight] = Stuff[0].Price; // 현재것을 선택한 경우    WeightSum[0][0] = 0;        // 현재것을 선택하지 않은 경우     for (int Cur = 1; Cur < N; Cur++)    {        for (int Weight = 0; Weight <= W; Weight++)            if (WeightSum[Cur - 1][Weight] != -1)            {                // 현재것을 선택한 경우                if (Weight + Stuff[Cur].Weight <= W)                {                    WeightSum[Cur][Weight + Stuff[Cur].Weight] = MAX(WeightSum[Cur][Weight + Stuff[Cur].Weight], WeightSum[Cur - 1][Weight] + Stuff[Cur].Price);                                         ResultPriceSum = MAX(ResultPriceSum, WeightSum[Cur][Weight + Stuff[Cur].Weight]);                                   }                 // 현재것을 선택하지 않은 경우                WeightSum[Cur][Weight] = MAX(WeightSum[Cur][Weight], WeightSum[Cur - 1][Weight]);                           }    }}   int main(){         setbuf(stdout, NULL);     scanf("%d %d", &N, &W);     for (int n = 0; n < N; n++)    {        scanf("%d %d", &Stuff[n].Weight, &Stuff[n].Price);        //  printf("%d %d\n",   Stuff[n].Weight, Stuff[n].Price);    }     DP_Process();     printf("%d", ResultPriceSum);}
