
#include <stdio.h>
#include <string.h>
#include <iostream>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define NL 262144

struct Seg {
	int l, r;
	int w;
}t[NL*2];

int h, w, row;

void build(int l, int r, int k)
{
	t[k].l = l;
	t[k].r = r;
	t[k].w = w;

	if (l + 1 < r) {
		int md = (l+r)>>1, k0 = k<<1;
		build(l, md, k0);
		build(md, r, k0+1);
	}
}

void mody(int l, int r, int k, int w)
{
	if (t[k].w < w) return;
	if (l + 1 == r && t[k].w >= w) {
		row = l;
		t[k].w -= w;
		return;
	}
	int md = (t[k].l+t[k].r)>>1, k0 = k<<1;
	if (t[k0].w >= w) mody(l, md, k0, w);
	else if (t[k0+1].w >= w) mody(md, r, k0+1, w);
	else return;
	t[k].w = MAX(t[k0].w, t[k0+1].w);
}

int main()
{
	int n, w0;
	while (scanf("%d%d%d", &h, &w, &n) != EOF) {
		int m = MIN(h,n)+1;
		build(1, m, 1);
		while (n--) {
			scanf("%d", &w0);
			row = -1;
			mody(1, m, 1, w0);
			printf("%d\n", row);
		}
	}
	system("pause");
	return 0;
}