#include <iostream>
#include "Node.h"
#include "LinkedList.h"
using namespace std;
int main()
{
    LinkedList<int> list;
    list.insertHead(323);
    list.insertHead(510);
    list.insertHead(111);
    list.insertTail(7);
    list.insertTail(1298);
    list.insertNthPosition(8, 3);
    cout<<"Lista con elementos insertados:"<<endl;
    list.print();
    list.removeHead();
    list.removeTail();
    list.removeNthPosition(2);
    cout<<"Lista con elementos quitados:"<<endl;
    list.print();

    /*LinkedList<double> listitaB;
    listitaB.insertHead(3.4);
    listitaB.insertHead(5123.1234);
    listitaB.insertHead(32.12);
    listitaB.insertTail(7.0);
    listitaB.print();
    LinkedList<char> listitaC;
    listitaC.insertHead('L');
    listitaC.insertHead('O');
    listitaC.insertHead('H');
    listitaC.insertTail('S');
    listitaC.removeHead();
    listitaC.insertNthPosition('g',4);
    listitaC.print();*/
    /*LinkedList<string> list;
    list.insertHead("estas");
    list.insertHead("como");
    list.insertHead("Hola");
    list.insertTail("tu");
    list.removeHead();
    list.insertNthPosition("mundo",2);
    list.print();*/
    cout << "Probando el iterador:" << endl; 
    for ( LinkedList<int>::Iterator iterator = list.begin(); iterator != list.end(); iterator++) 
    { 
        cout << *iterator << " "; 
    }
    cout<<endl; 
    cout<<"Probando copia:"<<endl;
    LinkedList<int> lCopy = list;
    lCopy.insertHead(2);
    cout<<"Lista base: "<<endl;
    list.print();
    cout<<"Lista Copia despues de modificacion:"<<endl;
    lCopy.print();
  
}