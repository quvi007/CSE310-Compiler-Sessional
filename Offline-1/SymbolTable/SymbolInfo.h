//
// Created by quvi on 5/25/22.
//

#ifndef SYMBOLTABLEOFFLINE_SYMBOLINFO_H
#define SYMBOLTABLEOFFLINE_SYMBOLINFO_H

#include <string>

using namespace std;

class SymbolInfo {
private:
    string name, type;
    SymbolInfo *next;
public:
    SymbolInfo(const string &, const string &);
    ~SymbolInfo();

    void setName(const string &);

    const string &getName() const;

    void setType(const string &);

    const string &getType() const;

    SymbolInfo* getNext() const;

    void setNext(SymbolInfo *);
};


#endif //SYMBOLTABLEOFFLINE_SYMBOLINFO_H
