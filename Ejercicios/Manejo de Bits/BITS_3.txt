char * mas0s ( char arr[N][50] )
{
	unsigned int id_max_ceros, max_ceros = 0, curr_ceros, i, j, k;
	for (i = 0; i < N; i++)
	{
		for (j = curr_ceros = 0; j <= 50; j++)
			for (k = 0; k < sizeof(char) * 8; k++)
				if ( (~arr[i][j]) & (1<<k) )
					curr_ceros++;
		if (curr_ceros >= max_ceros)
		{
			max_ceros = curr_ceros;
			id_max_ceros = i;
		}
	}
	return arr[i];					
}
