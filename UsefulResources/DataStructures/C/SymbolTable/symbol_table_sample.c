#include "symbol_table.h"

int main(){
	struct symbolTable* symbolTable = NULL;
	
	struct scopeTable* p1Main = NULL;
	struct scopeTable* p1 = NULL;
	struct scopeTable* f1 = NULL;
	
	// Parameters : &SymbolTable, Name, Address, Size, OuterScopeAddress, &Scope, OuterScope.
	struct symbolTable* entry1 = symbolTableAddScope(&symbolTable, "p1Main", 0, 30, -1, &p1Main, NULL);
	struct symbolTable* entry2 = symbolTableAddScope(&symbolTable, "p1", 30, 13, 0, &p1, entry1);
	struct symbolTable* entry3 = symbolTableAddScope(&symbolTable, "f1", 43, 29, 30, &f1, entry2);
	
	symbolTablePrint(&symbolTable);

	// Parameters : &Scope, Name, Type, Size, Address.
	scopeTableAddVariable(&p1Main, "i1", "Int", 4, 0);
	scopeTableAddVariable(&p1Main, "i2", "Int", 4, 4);
	scopeTableAddVariable(&p1Main, "i3", "Int", 4, 8);
	scopeTableAddVariable(&p1Main, "r1var", "Real", 8, 12);
	scopeTableAddVariable(&p1Main, "r2var", "Real", 8, 20);
	scopeTableAddVariable(&p1Main, "b1", "Bool", 1, 28);
	scopeTableAddVariable(&p1Main, "b2", "Bool", 1, 29);
	// Parameters : &Scope, Name, Address.
	scopeTableAddProcedure(&p1Main, "p1", 30);
	
	scopeTablePrint(entry1->scope);
	
	scopeTableAddVariable(&p1, "t1", "Int", 4, 30);
	scopeTableAddVariable(&p1, "t2", "Bool", 1, 34);
	scopeTableAddVariable(&p1, "t3", "Real", 8, 35);
	// Parameters : &Scope, Name, Address, ReturnType.
	scopeTableAddFunction(&p1, "f1", 43, "Int");
	
	scopeTablePrint(entry2->scope);
	
	scopeTableAddVariable(&f1, "v1", "Int", 4, 43);
	scopeTableAddVariable(&f1, "v2", "Int", 4, 47);
	scopeTableAddVariable(&f1, "v3", "Int", 4, 51);
	scopeTableAddVariable(&f1, "r1", "Real", 8, 55);
	scopeTableAddVariable(&f1, "r2", "Real", 8, 63);
	scopeTableAddVariable(&f1, "b1", "Bool", 1, 71);
	
	scopeTablePrint(entry3->scope);
	
	printf("\n%d %d", entry2->address, entry2->size);
	
	return 0;
}