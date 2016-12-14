#include<stdio.h>
#include<iostream>
using namespace std;

class HEAP {
public:
	int *h;
	int size = 0;
	HEAP(unsigned int n) {		
		h = (int* )malloc(sizeof(int) * n);
	}
	void add(int x) {
		h[++size] = x;
		checkup(size);		
	}

	int extract_min(int *x) {
		if (size == 0) return 0;
		*x = h[1];
		h[1] = h[size--];
		checkdown(1);	
		return 1;
	}
	void checkup(int c) {
		int p;
		p = c / 2;
		if (p == 0)return;
		if (h[p] < h[c]) {
			int tmp;
			tmp = h[p]; 
			h[p] = h[c];
			h[c] = tmp;
			checkup(p);
		}
	}
	void checkdown(int p) {
		int c;
		c = 2 * p;
		if (c > size) return;
		if (c + 1 <= size && h[c + 1] > h[c]) c++;

		if (h[c] > h[p]) {
			int tmp;
			tmp = h[c]; 
			h[c] = h[p];
			h[p] = tmp;
			checkdown(c);
		}
	}
};

int main() {
	HEAP heap(1000);
	int n, i;
	int x;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> x;		
		heap.add(x);
	}

	while (heap.extract_min(&x)) 
		cout << x << " ";	

	system("pause");
	return 0;
}

