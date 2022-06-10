//
// Created by quvi on 5/25/22.
//

#ifndef SYMBOLTABLEOFFLINE_SCOPETABLE_H
#define SYMBOLTABLEOFFLINE_SCOPETABLE_H

#include <string>
#include "SymbolInfo.h"

using namespace std;

class ScopeTable {
private:
    static unsigned long sdbmhash(const string &);

    string id;
    int total_buckets;
    SymbolInfo **T;
    ScopeTable* parentScope;
    int childCount;
public:
    ScopeTable(int, ScopeTable *);
    ~ScopeTable();

    bool insertEntry(const string &, const string &);
    SymbolInfo* lookUp(const string &) const;
    bool deleteEntry(const string &) const;
    void print() const;

    ScopeTable* getParentScope() const;
    void setParentScope(ScopeTable *);

    const string &getId() const;
};

#endif //SYMBOLTABLEOFFLINE_SCOPETABLE_H
