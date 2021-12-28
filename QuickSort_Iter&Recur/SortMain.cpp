#include "QuickSort.cpp"


int main() 
{
    Sort *sort = new Sort(); 
    Element element;
    int type; 

    //test 1
    element.key = 26; sort->InsertElement(element);
    element.key = 5;  sort->InsertElement(element);
    element.key = 77; sort->InsertElement(element);
    element.key = 1;  sort->InsertElement(element);
    element.key = 61; sort->InsertElement(element);
    element.key = 11; sort->InsertElement(element);
    element.key = 59; sort->InsertElement(element);
    element.key = 15; sort->InsertElement(element);
    element.key = 48; sort->InsertElement(element);
    element.key = 19; sort->InsertElement(element);

    //test 2

    // element.key = 26; sort->InsertElement(element);
    // element.key = 5; sort->InsertElement(element);
    // element.key = 37; sort->InsertElement(element);
    // element.key = 1; sort->InsertElement(element);
    // element.key = 61; sort->InsertElement(element);
    // element.key = 11; sort->InsertElement(element);
    // element.key = 59; sort->InsertElement(element);
    // element.key = 15; sort->InsertElement(element);
    // element.key = 48; sort->InsertElement(element);
    // element.key = 19; sort->InsertElement(element);

    //test 3 worst case
    // element.key = 20; sort->InsertElement(element);
    // element.key = 19; sort->InsertElement(element);
    // element.key = 18; sort->InsertElement(element);
    // element.key = 17; sort->InsertElement(element);
    // element.key = 16; sort->InsertElement(element);
    // element.key = 15; sort->InsertElement(element);
    // element.key = 14; sort->InsertElement(element);
    // element.key = 13; sort->InsertElement(element);
    // element.key = 12; sort->InsertElement(element);
    // element.key = 11; sort->InsertElement(element);
    // element.key = 10; sort->InsertElement(element);
    // element.key = 9; sort->InsertElement(element);
    // element.key = 8; sort->InsertElement(element);
    // element.key = 7; sort->InsertElement(element);
    // element.key = 6; sort->InsertElement(element);
    // element.key = 5; sort->InsertElement(element);
    // element.key = 4; sort->InsertElement(element);
    // element.key = 3; sort->InsertElement(element);
    // element.key = 2; sort->InsertElement(element);
    // element.key = 1; sort->InsertElement(element);

    //test 4 best case
    // element.key = 1; sort->InsertElement(element);
    // element.key = 2; sort->InsertElement(element);
    // element.key = 3; sort->InsertElement(element);
    // element.key = 4; sort->InsertElement(element);
    // element.key = 5; sort->InsertElement(element);
    // element.key = 6; sort->InsertElement(element);
    // element.key = 7; sort->InsertElement(element);
    // element.key = 8; sort->InsertElement(element);
    // element.key = 9; sort->InsertElement(element);
    // element.key = 10; sort->InsertElement(element);
    // element.key = 11; sort->InsertElement(element);
    // element.key = 12; sort->InsertElement(element);
    // element.key = 13; sort->InsertElement(element);
    // element.key = 14; sort->InsertElement(element);
    // element.key = 15; sort->InsertElement(element);
    // element.key = 16; sort->InsertElement(element);
    // element.key = 17; sort->InsertElement(element);
    // element.key = 18; sort->InsertElement(element);
    // element.key = 19; sort->InsertElement(element);
    // element.key = 20; sort->InsertElement(element);

    sort->QuickSort();
           
    return 0; 
}

