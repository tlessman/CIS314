#include <stdio.h>
#include <string.h>

void copy_int(int val, void *buf, int maxbytes);

int main(){
	int src = 0xFFFFFFFF;
	void* dest;
	int maxb = sizeof(src); 
	
	printf("%d", copy_int(src, dest, maxb)); 
	return 0;
}

void copy_int(int val, void *buf, int maxbytes) {
	if (maxbytes-sizeof(val) >= 0)
		memcpy(buf, (void *) &val, sizeof(val));
} 
