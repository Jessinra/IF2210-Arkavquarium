#include "LinkedList.h"
#include <iostream>
using namespace std;

int main(int argc, char* args[]) {
    LinkedList<int> L;

    if (L.isEmpty()) {
        cout << "kosong" << endl;
    }
    int a = 5;
    L.add(a);
    if (L.isEmpty()) {
        cout << "kosong" << endl;
    }

    cout << L.find(a) << endl;
    cout << L.getNBelmt() << endl;
    int i = 1;
    cout << L.get(i) << endl;
    
    L.add(i);
    L.printList();
    int b = 2;
    L.add(b);
    L.remove(i);
    
    cout << endl << L << endl;
    cout << L.getNBelmt() << endl;

    LinkedList<int> L1 = L;
    cout << L1 << endl;

    return 0;
}