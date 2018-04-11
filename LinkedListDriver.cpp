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
    L.printList();
    int b = 10;
    L.add(b);
    int c = 20;
    L.add(c);
    L.remove(b);
    
    cout << endl << L << endl;
    cout << L.getNBelmt() << endl;

    return 0;
}