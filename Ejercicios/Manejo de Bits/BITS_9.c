int main (void)
{
	int n, v, i, mask;
	printf("\nIntroduce un numero entero: "); 
	scanf ("%d", &n);
	
	printf("\nIntroduce un numero entero entre 2 y 10: ");
	do
	{
		scanf("%d", &v);
		fflush(stdin);
	}
	while(v < 2 || v > 10);

	for (i = 0; i < v; i++)
		mask = (mask<<1) | 1;
	
	mask <<= (sizeof(int) - v) / 2;
	n &= mask;

	for (i=sizeof(int) * 8; i; i>>=1)
		printf("%d", n & i);
}
