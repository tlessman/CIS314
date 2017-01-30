#include <stdio.h>
#include <string.h>

void copy_int(int val, void *buf, int maxbytes);

int main(){
	int src = 255;
	int dest[sizeof(int)];
	int maxb = 2;
	
	copy_int(src, dest, maxb); 
	
	printf("%d", *dest);

	return 0;
}

void copy_int(int val, void *buf, int maxbytes) {
	if ((size_t) maxbytes-sizeof(val) >= 0)
		memcpy(buf, (void *) &val, sizeof(val));
} 
