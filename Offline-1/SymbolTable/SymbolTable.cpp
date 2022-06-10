//
// Created by quvi on 5/25/22.
//

#include <iostream>
#include "SymbolTable.h"

using namespace std;

SymbolTable::SymbolTable(int total_buckets) {
    this->total_buckets = total_buckets;
    currentScopeTable = nullptr;
    enterScope();
}

SymbolTable::~SymbolTable() {
    while (!scopeTables.empty()) {
        ScopeTable *scopeTable = scopeTables.top();
        scopeTables.pop();
        delete scopeTable;
    }
}

void SymbolTable::enterScope() {
    ScopeTable* scopeTable = new ScopeTable(total_buckets, currentScopeTable);
    currentScopeTable = scopeTable;
    scopeTables.push(scopeTable);
}

void SymbolTable::exitScope() {
    cout << "ScopeTable with id " + currentScopeTable->getId() + " removed\n";
    scopeTables.pop();
    delete currentScopeTable;
    currentScopeTable = nullptr;
    if (!scopeTables.empty())
        currentScopeTable = scopeTables.top();
}

bool SymbolTable::insert(const string &symbolName, const string &symbolType) {
    return currentScopeTable->insertEntry(symbolName, symbolType);
}

bool SymbolTable::remove(const string &symbolName) {
    return currentScopeTable->deleteEntry(symbolName);
}

SymbolInfo *SymbolTable::lookUp(const string &symbolName) const {
    ScopeTable *p = currentScopeTable;
    while (p) {
        SymbolInfo* symbolInfo = p->lookUp(symbolName);
        if (symbolInfo) return symbolInfo;
        p = p->getParentScope();
    }
    cout << "Not found\n";
    return nullptr;
}

void SymbolTable::printCurrentScopeTable() const {
    currentScopeTable->print();
}

void SymbolTable::printAllScopeTables() const {
    stack<ScopeTable*> temp = scopeTables;
    while (!temp.empty()) {
        temp.top()->print();
        temp.pop();
    }
}

ScopeTable* SymbolTable::getCurrentScopeTable() const {
    return currentScopeTable;
}

void SymbolTable::setCurrentScopeTable(ScopeTable *scopeTable) {
    currentScopeTable = scopeTable;
}