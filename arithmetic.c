//Shelby Coe
//scoe4

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){

	printf("Please enter an arithmetic expression using * and / only: \n");
	float num;
	char operation;
	
	if(scanf(" %f", &num) != 1){		//first input has to be a float to be valid
		printf("malformed expression\n");		//malformed expression if it's not a float
		return 1;
	}
	float result = num;		//initializes the variable that will be the running result
	int next = scanf(" %c %f", &operation, &num);		//after the first float, valid expressions will have a char followed by a float
	
	while (next == 2) { 		//input of char and float received
		switch (operation) {	//checks to make sure the character is valid
			case '*':
				result = result * num;		//keeps a running total of the equation
				break;
			case '/':	
				if (num == 0){		//checks for division by 0
					printf("division by zero\n");
					return 2;		//attempted division by 0 return value
				} else {
					result = result / num;		//keeps a running total of the equation
				}
				break;
			default :		//if the character isn't '*' or '/' it's invalid
				printf("malformed expression\n");
				return 1;		//invalid expression return value
		}
		next = scanf(" %c %f", &operation, &num);
	}

	if (next != EOF){		//the loop was terminated by an error
		printf("malformed expression\n");
		return 1;		//invalid expression return value
	} else if (next == 1){ 		//not enough input
		printf("malformed expression\n");
		return 1;		//invalid expression return value
	}
	printf("%f\n", result);
	return 0;
	
}