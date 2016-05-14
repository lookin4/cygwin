#include <stdio.h>

#define HANOI_MAX 4

int a[HANOI_MAX] = {
	4,3,2,1
};

int b[HANOI_MAX] = {
	0,0,0,0
};

int c[HANOI_MAX] = {
	0,0,0,0
};

int count(int _c[]) {
	int c = 0;
	for (int i = 0; i < HANOI_MAX; i++) {
		if (_c[i] != 0)
		{
			c++;
		}
		
	}
	return c;
}

void result_print() {
	for (int i = (HANOI_MAX - 1); i >= 0; i--) {
		printf("%d %d %d\n", a[i], b[i], c[i]);
	}
	printf("a b c\n");
	printf("*************\n");
}

void move(int from[], int to[],int work[], int n) {
	
	if (n < 1) {
		return;
	}
	else if (n == 1) {
		int to_count = count(to);
		int from_count = count(from);
		
		int tmp = to[to_count];
		to[to_count] = from[from_count - 1];
		from[from_count - 1] = tmp;
		
		result_print();
	}
	else {
		move(from,work,to,n-1);
		
		int to_count = count(to);
		int from_count = count(from);
		
		int tmp = to[to_count];
		to[to_count] = from[from_count - 1];
		from[from_count - 1] = tmp;

		result_print();
		
		move(work, to, from, n - 1);
	}
	
}

void main() {
	result_print();

	move(a,c,b,HANOI_MAX);

	getchar();
}