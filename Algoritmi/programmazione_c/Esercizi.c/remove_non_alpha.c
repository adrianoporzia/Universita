#include <stdio.h>
#include <string.h>
void remove_non_alpha(char *a);

int main() {
	char a[] = "programmazione.....dei        calcolatori     test";
	int i, l;

    if (a[strlen(a) - 1] == '\n') {
        a[strlen(a) - 1] = '\0';
    }

	l = 0;
	while ( a[l] != '\0' ){
		printf("%c", a[l] );
		l++;
	}
	printf("\n");

    remove_non_alpha(a);
	i = 0;
	while ( a[i] != '\0' ){
		printf("%c", a[i]);
		i++;
	}
	printf("\n");
}

void remove_non_alpha(char *a) {
    int i, j;
    for (i = 0, j = 0; a[i] != '\0'; i++) {
        if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')) {
            a[j++] = a[i];
        }
    }
    a[j] = '\0';
}
