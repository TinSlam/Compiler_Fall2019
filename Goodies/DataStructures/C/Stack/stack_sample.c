#include "stack.h"

int main(){
	struct stack* stack = NULL;
	struct stack* place = NULL;
	
	push(&stack, "Item");
	push(&stack, "Item2");
	push(&stack, "Item3");
	
	push(&place, "Place1");
	push(&place, "Place2");
	
	pop(&place);
	
	printStack(&stack);
	printStack(&place);
	
	printf("Poped : %s.\n", pop(&place));
	
	clearStack(&stack);
	
	printStack(&stack);
	printStack(&place);
	
	return 0;
}