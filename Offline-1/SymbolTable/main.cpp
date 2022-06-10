#include <iostream>
#include "SymbolTable.h"

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int total_buckets;
    string code;
    
    cin >> total_buckets;

    SymbolTable symbolTable(total_buckets);

    while (cin >> code) {
        if (code == "I") {
            string symbolName, symbolType;
            cin >> symbolName >> symbolType;
            symbolTable.insert(symbolName, symbolType);
        } else if (code == "L") {
            string symbolName;
            cin >> symbolName;
            symbolTable.lookUp(symbolName);
        } else if (code == "D") {
            string symbolName;
            cin >> symbolName;
            if (!symbolTable.remove(symbolName))
                cout << symbolName << " not found\n";
        } else if (code == "P") {
            string secondCode;
            cin >> secondCode;
            if (secondCode == "A") {
                symbolTable.printAllScopeTables();
            } else if (secondCode == "C") {
                symbolTable.printCurrentScopeTable();
            }
        } else if (code == "S") {
            symbolTable.enterScope();
            cout << "New ScopeTable with id " + symbolTable.getCurrentScopeTable()->getId() + " created\n";
        } else if (code == "E") {
            symbolTable.exitScope();
        }
    }
    return 0;
}
