#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct symbolTable{
	char* name;
	int address;
	int size;
	int outerScopeAddress;
	struct scopeTable** scope;
	struct symbolTable* outerScope;
	struct symbolTable* next;
};

struct scopeTable{
	char* name;
	char* entityType;
	char* variableType;
	int variableSize;
	int address;
	char* returnType;
	struct scopeTable* next;
};

struct symbolTable* symbolTableAddScope(struct symbolTable** head, char* name, int address, int size, int outerScopeAddress, struct scopeTable** scope, struct symbolTable* outerScope);
void symbolTablePrint(struct symbolTable** head);
void scopeTableAddVariable(struct scopeTable** head, char* name, char* variableType, int variableSize, int address);
void scopeTableAddProcedure(struct scopeTable** head, char* name, int address);
void scopeTableAddFunction(struct scopeTable** head, char* name, int address, char* returnType);
void scopeTablePrint(struct scopeTable** head);
char* createString(char* string);

struct symbolTable* symbolTableAddScope(struct symbolTable** head, char* name, int address, int size, int outerScopeAddress, struct scopeTable** scope, struct symbolTable* outerScope){
	struct symbolTable* node = (struct symbolTable*) malloc(sizeof(struct symbolTable));
	
	node->name = createString(name);
	node->address = address;
	node->size = size;
	node->outerScopeAddress = outerScopeAddress;
	node->scope = scope;
	node->outerScope = outerScope;
	node->next = NULL;
	
	struct symbolTable* currentNode = *head;
	if(currentNode == NULL){
		*head = node;
	}else{
		while(currentNode->next != NULL) currentNode = currentNode->next;
		currentNode->next = node;
	}
	return node;
}

void symbolTablePrint(struct symbolTable** head){
	struct symbolTable* currentNode = *head;
	printf("\nName\tAddress\tSize\tOuter scope address\n");
	while(currentNode != NULL){
		printf("%s\t%d\t%d\t%d\n", currentNode->name, currentNode->address, currentNode->size, currentNode->outerScopeAddress);
		currentNode = currentNode->next;
	}
}

void scopeTableAddVariable(struct scopeTable** head, char* name, char* variableType, int variableSize, int address){
	struct scopeTable* node = (struct scopeTable*) malloc(sizeof(struct scopeTable));
	
	node->name = createString(name);
	node->entityType = createString("Variable");
	node->variableType = createString(variableType);
	node->variableSize = variableSize;
	node->address = address;
	node->returnType = createString("-");
	node->next = NULL;
	
	struct scopeTable* currentNode = *head;
	if(currentNode == NULL){
		*head = node;
	}else{
		while(currentNode->next != NULL) currentNode = currentNode->next;
		currentNode->next = node;
	}
}

void scopeTableAddProcedure(struct scopeTable** head, char* name, int address){
	struct scopeTable* node = (struct scopeTable*) malloc(sizeof(struct scopeTable));
	
	node->name = createString(name);
	node->entityType = createString("Procedure");
	node->variableType = createString("-");
	node->variableSize = -1;
	node->address = address;
	node->returnType = createString("-");
	node->next = NULL;
	
	struct scopeTable* currentNode = *head;
	if(currentNode == NULL){
		*head = node;
	}else{
		while(currentNode->next != NULL) currentNode = currentNode->next;
		currentNode->next = node;
	}
}

void scopeTableAddFunction(struct scopeTable** head, char* name, int address, char* returnType){
	struct scopeTable* node = (struct scopeTable*) malloc(sizeof(struct scopeTable));
	
	node->name = createString(name);
	node->entityType = createString("Function");
	node->variableType = createString("-");
	node->variableSize = -1;
	node->address = address;
	node->returnType = createString(returnType);
	node->next = NULL;
	
	struct scopeTable* currentNode = *head;
	if(currentNode == NULL){
		*head = node;
	}else{
		while(currentNode->next != NULL) currentNode = currentNode->next;
		currentNode->next = node;
	}
}

void scopeTablePrint(struct scopeTable** head){
	struct scopeTable* currentNode = *head;
	printf("\nName\tEntity type\tType\tSize\tAddress\tReturn type\n");
	while(currentNode != NULL){
		printf("%s\t%s\t%s\t%d\t%d\t%s\n", currentNode->name, currentNode->entityType, 
			currentNode->variableType, currentNode->variableSize,
			currentNode->address, currentNode->returnType);
		currentNode = currentNode->next;
	}
}

char* createString(char* string){
	char* pointer = (char*) malloc(strlen(string) + 1);
	strcpy(pointer, string);
	pointer[strlen(string)] = 0;
	return pointer;
}