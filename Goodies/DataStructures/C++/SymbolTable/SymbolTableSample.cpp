#include "SymbolTable.h"

int main(){
	SymbolTable::SymbolTable* symbolTable = new SymbolTable::SymbolTable();
	
	SymbolTable::Scope* main = symbolTable->addScope("main", 0, 8, nullptr);
	
	main->addFunction("func1", 0, SymbolTable::Entry::VAR_TYPE::VOID);
	SymbolTable::Scope* func1 = symbolTable->addScope("func1", 0, 10, main);
	func1->addVariable("b1", SymbolTable::Entry::VAR_TYPE::BOOL, 1, 0);
	func1->addVariable("b2", SymbolTable::Entry::VAR_TYPE::BOOL, 1, 1);
	func1->addVariable("r1", SymbolTable::Entry::VAR_TYPE::REAL, 1, 9);
	
	main->addFunction("func2", 10, SymbolTable::Entry::VAR_TYPE::INT);
	SymbolTable::Scope* func2 = symbolTable->addScope("func2", 10, 30, main);
	func2->addVariable("r1", SymbolTable::Entry::VAR_TYPE::REAL, 8, 10);
	func2->addVariable("r2", SymbolTable::Entry::VAR_TYPE::REAL, 8, 18);
	func2->addVariable("i2", SymbolTable::Entry::VAR_TYPE::INT, 4, 26);
	func2->addVariable("r3", SymbolTable::Entry::VAR_TYPE::REAL, 8, 30);
	func2->addVariable("b1", SymbolTable::Entry::VAR_TYPE::BOOL, 1, 38);
	func2->addVariable("b2", SymbolTable::Entry::VAR_TYPE::BOOL, 1, 39);
	
	SymbolTable::Scope* whileBlock = symbolTable->addScope("while", 40, 40, func2);
	whileBlock->addVariable("r1", SymbolTable::Entry::VAR_TYPE::REAL, 8, 40);
	whileBlock->addVariable("r2", SymbolTable::Entry::VAR_TYPE::REAL, 8, 48);
	whileBlock->addVariable("r3", SymbolTable::Entry::VAR_TYPE::REAL, 8, 56);
	whileBlock->addVariable("r4", SymbolTable::Entry::VAR_TYPE::REAL, 8, 64);
	whileBlock->addVariable("r5", SymbolTable::Entry::VAR_TYPE::REAL, 8, 72);
	
	main->addVariable("r1", SymbolTable::Entry::VAR_TYPE::REAL, 8, 80);
	
	symbolTable->print();
	
	delete(symbolTable);
}