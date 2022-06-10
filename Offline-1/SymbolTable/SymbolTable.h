//
// Created by quvi on 5/25/22.
//

#ifndef SYMBOLTABLEOFFLINE_SYMBOLTABLE_H
#define SYMBOLTABLEOFFLINE_SYMBOLTABLE_H

#include <string>
#include <stack>
#include "ScopeTable.h"

using namespace std;

class SymbolTable {
private:
    int total_buckets;
    ScopeTable *currentScopeTable;
    stack<ScopeTable*> scopeTables;
public:
    SymbolTable(int);
    ~SymbolTable();

    void enterScope();

    void exitScope();

    bool insert(const string &, const string &);

    bool remove(const string &);

    SymbolInfo *lookUp(const string &) const;

    void printCurrentScopeTable() const;

    void printAllScopeTables() const;

    ScopeTable* getCurrentScopeTable() const;

    void setCurrentScopeTable(ScopeTable *);
};


#endif //SYMBOLTABLEOFFLINE_SYMBOLTABLE_H
