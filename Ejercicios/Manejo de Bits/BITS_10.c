void intercambiarBits (int *n1, int *n2)
{
	// Queremos: a = 1011, b = 0100 -> 'a = 0011, 'b = 0110
	// mask1 = 1011 >> 2 = 0010
	// mask2 = 0100 << 2 = 0000
	// 'a = (1011<<2)>>2 = 1100>>2 = 0011 
	// 'a = 0011 | 0000 = 0011 (Bien)
	// 'b = (0100>>2)<<2 = 0001<<2 = 0100
	// 'b = 0100 | 0010 = 0110 (Bien)
	
	int mask1, mask2;
	mask1 = *n1 >> (sizeof(int) * 8 - 8);
	mask2 = *n2 << (sizeof(int) * 8 - 8);
	*n1 = ((n1 << 8) >> 8) | mask2;
	*n2 = ((n2 >> 8) << 8) | mask1;
}
