// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

#define MAXN    10000
#define MAXK    10000

bool gDP[MAXK + 1][MAXN + 1];

// (막대 개수, 표현 숫자)
int gStick[][2] = {
	{ 1, 1 },       // I
	{ 2, 5 },       // V
	{ 2, 10 },      // X
	{ 3, 4 },       // IV
	{ 3, 9 },       // IX
};

void makeTable() {
	memset(gDP, 0, sizeof(gDP));

	gDP[0][0] = true;

	for (int i = 0; i < sizeof(gStick) / sizeof(gStick[0]); i++) {
		int kk = gStick[i][0];
		int nn = gStick[i][1];
		if (nn <= MAXN && kk <= MAXK)
			gDP[kk][nn] = true;
	}

	for (int i = 1; i <= MAXK; i++) {
		for (int j = 1; j <= MAXN; j++) {
			if (!gDP[i][j])
				continue;

			for (int k = 0; k < sizeof(gStick) / sizeof(gStick[0]); k++) {
				int kk = i + gStick[k][0];
				int nn = j + gStick[k][1];
				if (nn <= MAXN && kk <= MAXK)
					gDP[kk][nn] = true;
			}
		}
	}
}

int main(void) {
	makeTable();

	int T;
	cin >> T;

	while (T-- > 0) {
		int N, K;
		cin >> N >> K;

		cout << (gDP[K][N] ? 'O' : 'X') << endl;
	}
	return 0;
}
