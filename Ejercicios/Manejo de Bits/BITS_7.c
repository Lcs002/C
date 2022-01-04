long aCeroLosBitsPares (long n)
{
	// Tomo como el bit inicial (1) el primero, de menor peso
	long mask = 0;
	unsigned int i;

	for (i=0; i < sizeof(long) * 8; i++)
		mask = i%2 ? (mask << 1) | 1 : mask << 1;
	
	return n & mask;
}
