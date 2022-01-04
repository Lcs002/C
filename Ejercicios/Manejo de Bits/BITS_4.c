int main (void)
{
	char c;
	unsigned int bits1, i;

	do 
	{
		scanf("%c", &c);
		for (i = bits1 = 0; i < 8; i++)
			if (c & 1<<i)
				bits1++;		
	} 
	while (bits1 <= 4);

	printf("\n%c\n", c);
	for (i = sizeof(char)*8 - 1; i>=0; i--)
		printf("%d", c & (1<<i));
}
