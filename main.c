#include "semihosting/semihosting.h"
#include "stm32f4xx.h"
#include "CoOS.h"
#include <stdio.h>
#define STACK_SIZE_TASK_A 128
#define STACK_SIZE_TASK_B 128

OS_STK task_A_stk[STACK_SIZE_TASK_A];
OS_STK task_B_stk[STACK_SIZE_TASK_B];

void taskA(void *pdata) {
	while (1) {
		printf("A\n");
		CoTickDelay(100);
	}
}
void taskB(void *pdata) {
	while (1) {
		printf("B\n");
		CoTickDelay(100);
	}
}
int main(void) {
	CoInitOS();
	CoCreateTask(taskA, 0, 0, &task_A_stk[STACK_SIZE_TASK_A - 1],
			STACK_SIZE_TASK_A);
	CoCreateTask(taskB, 0, 1, &task_B_stk[STACK_SIZE_TASK_B - 1],
			STACK_SIZE_TASK_B);
	CoStartOS();
	while (1) {
	}
}
