//
// Created by quvi on 5/25/22.
//

#include <iostream>
#include "ScopeTable.h"

using namespace std;

ScopeTable::ScopeTable(int n, ScopeTable *parentScope) : total_buckets{n}, parentScope{parentScope}, childCount{0} {
    T = new SymbolInfo* [n];
    for (int i = 0; i < n; ++i)
        T[i] = nullptr;
    if (parentScope) {
        id = parentScope->id + "." + to_string(parentScope->childCount + 1);
        parentScope->childCount = parentScope->childCount + 1;
    }
    else id = "1";
}

ScopeTable::~ScopeTable() {
    for (int i = 0; i < total_buckets; ++i) {
        SymbolInfo *p = T[i];
        while (p) {
            SymbolInfo *next = p->getNext();
            delete p;
            p = next;
        }
    }
    delete[] T;
}

SymbolInfo *ScopeTable::lookUp(const string &symbolName) const {
    int idx = sdbmhash(symbolName) % total_buckets;
    SymbolInfo *p = T[idx];
    int c = 0;
    while (p) {
        if (p->getName() == symbolName) {
            cout << "Found in ScopeTable# " + id + " at position " + to_string(idx) + ", " + to_string(c) + "\n";
            return p;
        }
        p = p->getNext();
        c++;
    }
    return nullptr;
}

void ScopeTable::print() const {
    cout << "\nScopeTable # " << id << "\n";
    for (int i = 0; i < total_buckets; ++i) {
        cout << i << " -->";
        SymbolInfo *p = T[i];
        while (p) {
            cout << "  < " << p->getName() << " : " << p->getType() << ">";
            p = p->getNext();
        }
        cout << "\n";
    }
}

ScopeTable *ScopeTable::getParentScope() const {
    return parentScope;
}

void ScopeTable::setParentScope(ScopeTable *scopeTable) {
    parentScope = scopeTable;
}

bool ScopeTable::insertEntry(const string &symbolName, const string &symbolType) {
    int idx = sdbmhash(symbolName) % total_buckets;
    int c = 0;
    if (T[idx]) {
        SymbolInfo *p = T[idx], *prev = nullptr;
        while (p) {
            if (p->getName() == symbolName) {
                cout << "<" + symbolName + "," + symbolType + "> already exists in current ScopeTable\n";
                return false;
            }
            prev = p;
            p = p->getNext();
            c++;
        }
        SymbolInfo *symbolInfo = new SymbolInfo(symbolName, symbolType);
        prev->setNext(symbolInfo);
    } else T[idx] = new SymbolInfo(symbolName, symbolType);
    cout << "Inserted in ScopeTable# " + id + " at position " + to_string(idx) + ", " + to_string(c) + "\n";
    return true;
}

bool ScopeTable::deleteEntry(const string &symbolName) const {
    int idx = sdbmhash(symbolName) % total_buckets;
    SymbolInfo *p = T[idx], *prev = nullptr;
    int c = 0;
    while (p) {
        if (p->getName() == symbolName) {
            cout << "Found in ScopeTable# " + id + " at position " + to_string(idx) + ", " + to_string(c) + "\n";
            SymbolInfo *next = p->getNext();
            if (prev) prev->setNext(next);
            else T[idx] = next;
            delete p;
            cout << "Deleted Entry " + to_string(idx) + ", " + to_string(c) + " from current ScopeTable\n";
            return true;
        }
        prev = p;
        p = p->getNext();
        c++;
    }
    cout << "Not found\n";
    return false;
}

unsigned long ScopeTable::sdbmhash(const string &str) {
    unsigned long hash = 0;
    int c, k = 0;
    while ((c = str[k++]))
        hash = c + (hash << 6) + (hash << 16) - hash;
    return hash;
}

const string &ScopeTable::getId() const {
    return id;
}