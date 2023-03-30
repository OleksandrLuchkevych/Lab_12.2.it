#include <iostream>

using namespace std;


typedef int Info;
struct Elem
{
    Elem* link;
    Info  info;
};
void Input(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = NULL;
    if (last != NULL)
        last->link = tmp;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

Info Delete(Elem*& first, Elem*& last)
{
    Elem* tmp = first->link;
    Info value = first->info;
    delete first;
    first = tmp;
    if (first == NULL)
        last = NULL;
    return value;
}

bool Сheck(Elem* elem) {
    bool x = false;
    while (elem->link != NULL)
    {
        if (elem->info < elem->link->info)
        {
            x = true;
        }
        else
        {
            x = false;
            return x;
            break;
        }
        elem = elem->link;
    }
    return x;
}

int main()
{
    Elem* first = NULL, * last = NULL;
    int n = 12;
    for (int i = 0; i < n; i++) {
        Input(first, last, i);
    }
    bool count = Сheck(first);
    if (count == true)
    {
        cout << "List elements are sorted in non - descending order" << endl;

    }   
    else
    {
        cout << "List elements are sorted in descending order" << endl;
    }


    for (int i = 0; i < n; i++)
    {
        cout << Delete(first, last) << " ";
    }

    return 0;
}