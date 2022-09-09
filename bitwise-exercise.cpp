#include <iostream>
#include <stdint.h>

typedef uint64_t u64;
typedef uint8_t u8;


u64 ReadBitPair(u64 data, u8 offset) {
	u64 mask = (1UL << offset) & data;
	u64 mask2 = (1UL << (offset+1)) & data;
	u64 result = mask | mask2;
	return result;
}


void WriteBitPair(u64 &data, u8 offset, u64 overwritten) {
	u64 mask = (1UL << offset);
	u64 mask2 = (1UL << (offset + 1));
	mask = ~mask;
	mask2 = ~mask2;
	u64 result = (mask | mask2) & overwritten;
	printf("%d", result);
}

int main() {
	u64 n;
	u8 offset;
	//scanf("%d %d", &n, &offset);
	std::cin >> n >> offset;
	offset -= '0';
	u64 mask = ReadBitPair(n, offset);
	WriteBitPair(n, offset, mask);
}
