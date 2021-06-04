#include<stdio.h>

int main()
{
	int c = 0; 
	int count_num_3 = 0; 

	printf("Enter some numbers:");
	while ((c = getchar()) != 4 && c != 26 && c != EOF) {
		switch (c) {
			case 51:
				count_num_3++;
				break;
		}
	}

	if (count_num_3 > 0) {
		switch (count_num_3) {  
			case 1:
				printf("Number three appears one time.\n");
				break;
			case 2:
				printf("Number three appears two times.\n");
				break;
			default:
				printf("Number three appears more than two times.\n");
				break;
		}
	} 
    else 
    {
		printf("Number three does not appear.\n");
	}

	return 0;
}