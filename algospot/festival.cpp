#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int N;
char incoming[50 + 5];
char outgoing[50 + 5];
char output[50 + 5][50 + 5];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int T;

	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc)
	{
		printf("Case #%d:\n", tc);
		scanf("%d", &N);

		for (int i = 0; i < N; i++) scanf(" %c", &incoming[i]);
		for (int i = 0; i < N; i++) scanf(" %c", &outgoing[i]);

		for (int i = 0; i < N; i++)
		{
			output[i][i] = 'Y';

			for (int j = i; j-1 >= 0; --j)
			{
				if (incoming[j - 1] == 'Y' && outgoing[j] == 'Y' && output[i][j] == 'Y') output[i][j-1] = 'Y';
				else output[i][j-1] = 'N';
			}

			for (int j = i; j + 1 < N; ++j)
			{
				if (incoming[j + 1] == 'Y' && outgoing[j] == 'Y' && output[i][j] == 'Y') output[i][j + 1] = 'Y';
				else output[i][j + 1] = 'N';
			}

			for (int j = 0; j < N; j++) printf("%c", output[i][j]);
			printf("\n");
		}
	}

	return 0;
}