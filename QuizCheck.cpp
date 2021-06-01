#include <iostream>
using namespace std;

main() {

    int a=1, b=2, c=3;
    int *p, *q, *r;

    a = 17;
    p = r;
    //q = b;
    c = *p;

    class Person{
        public:
            string FullName;
            Person *next;
    };

    Person per1;
    Person *ptr1;

    ptr1->next = &per1;
    //ptr1->next = per1;
    //ptr1.next = *per1;
    //ptr1.next = &per1;

    ptr1 = nullptr;
    //per1 = nullptr;
    ptr1->next = nullptr;
    per1.next = nullptr;


    return 0;
}