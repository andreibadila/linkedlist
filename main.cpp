#include <iostream>
#include <time.h>
#include <stdlib.h>


using namespace std;

class nod {
private:
    int value;
    nod* nextPtr;

public:

    void setValue(int valuec) {
        this->value = valuec;
    }

    int getValue() {
        return this->value;
    }

    void setPtr(nod* Ptr) {
        this->nextPtr = Ptr;
    }

    nod* getPtr() {
        return this->nextPtr;
    }

    nod() {
        value = 0;
        nextPtr = nullptr;
    }

    nod(int a) {
        value = a;
        nextPtr = nullptr;
    }

    ~nod() {
        cout << "nod destructor called for value " << this->value << endl;
    }

};

class lista {

private:
    nod* capat, * curent;
public:
    lista() {
        capat = nullptr;
        curent = nullptr;
    }

    void push(nod* b) {
        if (capat == nullptr) {
            this->capat = b;
            this->curent = b;
        }
        else {
            curent->setPtr(b);
            curent = b;
        }
    }

    nod *searchLista(int valueNod){
        nod *t = capat;
        while(t != nullptr){
            if(t->getValue() == valueNod) {
                return t;
            }

            t = t->getPtr();
        }

        return nullptr;
    }

    void insert(nod* element){

    nod*prev=nullptr;
    nod*k=capat;
        while(k!=nullptr){
            if(k->getValue()<element->getValue()){
                prev=k;
                k=k->getPtr();
            } else {
                if (prev==nullptr){
                       element->setPtr(k);
                       capat=element;
                } else{
                        prev->setPtr(element);
                        element->setPtr(k);
                    }

                    return;
            }
        }

        if (prev == nullptr) {
            capat = element;
        } else {
            prev->setPtr(element);
            element->setPtr(k);
        }



    }

    void deleteNod() {
        nod* tempnod = capat;
        capat = capat->getPtr();
    }


   /* void sort() {
        int i, j, k, tempPtr, tempValue;
        for(i=0;i<capat-1;i++)
    }*/

    void print() {
        nod* it = capat;

        while (it->getPtr() != nullptr) {
            cout << it->getValue() << " ";
            it = it->getPtr();
        }

        cout << it->getValue() << endl;
    }

    ~lista() {
        nod* itrt = capat;
        nod* ptr = nullptr;


        while (itrt != nullptr) {
            ptr = itrt;
            itrt = itrt->getPtr();
            delete ptr;

        }
    }
};

int main()
{

    nod a(100);
    nod *b = new nod(200);
    cout << a.getValue() << endl;
    cout << b->getValue() << endl;


    lista l;
    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        l.insert(new nod(rand()%100));
    }

    //nod* c = new nod(200);
    //l.insert();
    //l.deleteNod();

    //nod *x = l.searchLista(900);
    //cout<< (x == nullptr ? "Element negasit" : x->getValue()) << endl;

    /*
    if (x == nullptr) {
        cout << "Element negasit" << endl;
    } else {
        cout << x->getValue() << endl;
    }
    */

    l.print();




}
