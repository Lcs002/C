int compararBitsACero(char *cad1, char *cad2)
{
	int ceros = 0, i;
	
	for (; *cad1; cad1++)
		for (i = sizeof(char) * 8; i; i>>=1)
			if (~*cad1 & i)
				ceros++;

	for (; *cad2; cad2++)
		for (i = sizeof(char) * 8; i; i>>=1)
			if (~*cad2 & i)
				ceros--;
	return ceros;
}
