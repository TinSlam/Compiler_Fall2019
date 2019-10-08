#include <list>
#include <string>
#include <stdio.h>

namespace SymbolTable{
	class Scope;
	class Entry;
	
	class SymbolTable{
		public :
			std::list<Scope*> scopes;
			
			~SymbolTable();
			Scope* addScope(std::string name, int address, int size, Scope* outerScope);
			void print();
	};
	
	class Entry{
		public:
			enum TYPE{VARIABLE, FUNCTION};
			enum VAR_TYPE{NONE, INT, REAL, BOOL, STRING, VOID};
		
			std::string name = "";
			TYPE type = TYPE::VARIABLE;
			VAR_TYPE varType = VAR_TYPE::NONE;
			int variableSize = 0;
			int address = 0;
			VAR_TYPE returnType = VAR_TYPE::NONE;
			
			Entry(std::string name, TYPE type, VAR_TYPE varType, int variableSize, int address, VAR_TYPE returnType);
			
			static std::string getType(TYPE type);
			static std::string getVarType(VAR_TYPE varType);
	};
	
	class Scope{
		public:
			std::string name = "";
			int address = 0;
			int size = 0;
			Scope* outerScope = nullptr;
			
			std::list<Entry*> entries;
			
			Scope(std::string name, int address, int size, Scope* outerScope);
			~Scope();
			void addVariable(std::string name, Entry::VAR_TYPE varType, int variableSize, int address);
			void addFunction(std::string name, int address, Entry::VAR_TYPE returnType);
			void print();
	};
	
	SymbolTable::~SymbolTable(){
		for(auto it = scopes.begin(); it != scopes.end(); it++){
			delete(*it);
		}
	}
	
	Scope* SymbolTable::addScope(std::string name, int address, int size, Scope* outerScope){
		Scope* scope = new Scope(name, address, size, outerScope);
		scopes.push_back(scope);
		return scope;
	}
	
	void SymbolTable::print(){
		printf("Symbol Table ------------------------------------------\n");
		printf("Name\tAddress\tSize\tOuter scope address\n");
		for(auto it = scopes.begin(); it != scopes.end(); it++){
			printf("%s\t%d\t%d\t%d\n", (*it)->name.c_str(), (*it)->address, (*it)->size, ((*it)->outerScope == nullptr) ? 0 : (*it)->outerScope->address);
		}
		printf("-------------------------------------------------------\n\n");
		
		for(auto it = scopes.begin(); it != scopes.end(); it++){
			(*it)->print();
		}
	}
	
	Scope::Scope(std::string name, int address, int size, Scope* outerScope){
		this->name = name;
		this->address = address;
		this->size = size;
		this->outerScope = outerScope;
	}
	
	Scope::~Scope(){
		for(auto it = entries.begin(); it != entries.end(); it++){
			delete(*it);
		}
	}
	
	void Scope::addVariable(std::string name, Entry::VAR_TYPE varType, int variableSize, int address){
		entries.push_back(new Entry(name, Entry::TYPE::VARIABLE, varType, variableSize, address, Entry::VAR_TYPE::NONE));
	}
	
	void Scope::addFunction(std::string name, int address, Entry::VAR_TYPE returnType){
		entries.push_back(new Entry(name, Entry::TYPE::FUNCTION, Entry::VAR_TYPE::NONE, 0, address, returnType));
	}
	
	void Scope::print(){
		printf("Scope -------------------------------------------------\n");
		printf("%s\n", name.c_str());
		printf("Name\tType\tVariable type\tVariable size\tAddress\tReturn type\n");
		for(auto it = entries.begin(); it != entries.end(); it++){
			printf("%s\t%s\t%s\t%d\t%d\t%s\n", (*it)->name.c_str(),
				Entry::getType((*it)->type).c_str(),
				Entry::getVarType((*it)->varType).c_str(),
				(*it)->variableSize,
				(*it)->address,
				Entry::getVarType((*it)->returnType).c_str());
		}
		printf("-------------------------------------------------------\n");
	}
			
	Entry::Entry(std::string name, TYPE type, VAR_TYPE varType, int variableSize, int address, VAR_TYPE returnType){
		this->name = name;
		this->type = type;
		this->varType = varType;
		this->variableSize = variableSize;
		this->address = address;
		this->returnType = returnType;
	}
	
	std::string Entry::getType(TYPE type){
		switch(type){
			case TYPE::VARIABLE :
				return "Variable";
				
			case TYPE::FUNCTION :
				return "Function";
				
			default :
				return "-";
		}
	}
	
	std::string Entry::getVarType(VAR_TYPE varType){
		switch(varType){
			case VAR_TYPE::INT :
				return "int";
				
			case VAR_TYPE::REAL :
				return "real";
				
			case VAR_TYPE::BOOL :
				return "bool";
				
			case VAR_TYPE::STRING :
				return "string";
				
			case VAR_TYPE::VOID :
				return "void";
				
			default :
				return "-";
		}
	}
}