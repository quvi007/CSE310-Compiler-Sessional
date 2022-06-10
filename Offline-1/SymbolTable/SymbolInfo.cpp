//
// Created by quvi on 5/25/22.
//

#include "SymbolInfo.h"

SymbolInfo::SymbolInfo(const string &name, const string &type) {
    this->name = name;
    this->type = type;
    next = nullptr;
}

SymbolInfo::~SymbolInfo() {};

void SymbolInfo::setName(const string &name) {
    this->name = name;
}

const string &SymbolInfo::getName() const {
    return name;
}

void SymbolInfo::setType(const string &type) {
    this->type = type;
}

const string &SymbolInfo::getType() const {
    return type;
}

SymbolInfo *SymbolInfo::getNext() const {
    return next;
}

void SymbolInfo::setNext(SymbolInfo* symbolInfo) {
    next = symbolInfo;
}
