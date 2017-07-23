#include <stdio.h>
int main(void){
	int r;
	scanf("%i",&r);
	for(int j = 1; j <= r; j++){
		int n;
		scanf("%i",&n);
		int incookie = 0;
		int process = 1;
		char a[10];
		for (int i = 1; i <=n; i++) {
			scanf("%s", a);
			if (process) {
				if (incookie && a[0] =='c') {
					process = 0;
				} else if (incookie && a[0] == 'm') {
					incookie = 0;
				} else if (a[0] == 'c') {
					incookie = 1;
				}
			}
		}
		if (!incookie) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}
