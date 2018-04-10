#include "LinkedList.h"
#include <iostream>
using namespace std;

int main(int argc, char* args[]) {
    LinkedList<int> L;

    if (L.isEmpty()) {
        cout << "kosong" << endl;
    }
    L.add(5);
    if (L.isEmpty()) {
        cout << "kosong" << endl;
    }

    cout << L.find(5) << endl;
    cout << L.getNBelmt() << endl;
    L.printList();
    L.add(10);
    L.add(20);
    L.remove(10);
    
    cout << endl << L;
    cout << L.getNBelmt() << endl;

    return 0;
}