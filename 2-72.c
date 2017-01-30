

void copy_int(int val, void *buf, int maxbytes);

int main(){
	void* buffer;
	printf("%b", copy_int(0xFFFFFFFF, buffer, 2)) 
	return 0;
}

void copy_int(int val, void *buf, int maxbytes) {
	if (maxbytes-sizeof(val) >= 0)
		memcpy(buf, (void *) &val, sizeof(val));
} 
