/*
1828 : 냉장고 
제한시간: 1000 ms    메모리제한: 32 MB
해결횟수: 1166 회    시도횟수: 4003 회 
문제
N개의 화학 물질 C1, C2, …, Cn이 있다. 이들 각각은 보관되어야 할 온도가 각기 다른데, 각 Ci마다 최저 보관 온도 xi와 최고 보관 온도 yi가 정해져 있다. 즉 Ci는 온도 xi이상, yi이하의 온도에서 보관되어야만 안전하다. 
이 화학 물질들을 모두 보관하기 위해서는 여러 대의 냉장고가 필요한데 가능하면 적은 수의 냉장고를 사용하고 싶다. 이를 해결하는 프로그램을 작성하시오.
입력 형식
첫 줄에 화학물질의 수 N이 입력된다. N의 범위는 1이상 100 이하이다.
두 번째 줄부터 N+1줄까지 최저보관온도와 최고보관온도가 입력된다.
보관온도는 -270° ~ 10000°이며, 각 냉장고는 임의의 정해진 온도를 일정하게 유지할 수 있고, 냉장고는 아주 크다고 가정한다.
출력형식
첫 줄에 최소로 필요한 냉장고의 대수를 출력한다

*/


#include <stdio.h>

struct sChem
{
	int Low, High;
};

sChem Chem[101];

void Sort(sChem *Chem, int N)
{
	int i, j;
	for(i = 0; i < N; i++)
		for(j = i; j < N; j++)
			if (Chem[i].High > Chem[j].High)
			{
				sChem Temp = Chem[i];
				Chem[i] = Chem[j];
				Chem[j] = Temp;
			}
}

int main()
{
	int n,N,Cnt;
	sChem Comp;

	freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	for (n = 0; n < N; n++)
	{
		scanf("%d %d", &Chem[n].Low, &Chem[n].High);
		//printf("%d %d\n", Chem[n].Low, Chem[n].High);
	}

	Sort(Chem, N);

	//for (n = 0; n < N; n++)
	//	printf("%d %d\n", Chem[n].Low, Chem[n].High);
	
	Cnt = 1;
	Comp = Chem[0];
	for (n = 1; n < N; n++)
		if (!((Chem[n].Low <= Comp.High) && (Comp.High <= Chem[n].High)))
		{
			Comp = Chem[n];
			Cnt++;
		}
	
	printf("%d", Cnt);		

	return 0;
}
