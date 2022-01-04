unsigned int unos (int arr[N])
{
	unsigned int unos = 0, i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < sizeof(char) * 8; j++)
			if (arr[i] & (1<<j))
				unos++;
	return unos
}

