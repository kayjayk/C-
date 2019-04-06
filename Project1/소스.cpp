#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int N;

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		int x = i;
		int count = 0;
		while (x > 0) {
			if ((x % 10) % 3 == 0 && x % 10 != 0)
				count++;

			x /= 10;
		}
		if (count > 0) {
			for (int j = 0; j < count; j++) {
				printf("-");
			}
			printf(" ");
		}
		else
			printf("%d ", i);
	}
}
