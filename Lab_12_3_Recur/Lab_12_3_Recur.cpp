#include <iostream>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* next,
        * prev;
    Info info;
};

void LAdd(Elem*& first, Elem*& last, Info i, Info imax, Info di)
{
    if (i != imax)
    {
        Elem* tmp = new Elem;
        tmp->info = i;
        tmp->next = NULL;
        if (last != NULL)
            last->next = tmp;
        tmp->prev = last;
        last = tmp;
        if (first == NULL)
            first = tmp;
        LAdd(first, last, i + di, imax, di);
    }
}

bool LisSubset(Elem* first1, Elem* first2, Elem* tmp, bool found)
{
    if (first2 != NULL)
    {
        if (tmp != NULL && found == false)
        {
            if (tmp->info == first2->info)
                found = true;
            LisSubset(first1, first2, tmp->next, found);
        }
        else if (found == false)
            return false;
        LisSubset(first1, first2->next, first1, false);
    }
    else
        return true;
}

void LPrint(Elem* first)
{
    if (first != NULL)
    {
        cout << first->info << "  ";
        LPrint(first->next);
    }
    else
        cout << endl;
}

int main()
{
    Elem* L1 = NULL, * last1 = NULL, * L2 = NULL, * last2 = NULL;
    LAdd(L1, last1, 9, 5, -1);
    LAdd(L2, last2, 0, 11, 1);
    LPrint(L1);
    LPrint(L2);
    if (LisSubset(L2, L1, L2, false) == true)
        cout << "yes" << endl;
    else
        cout << "no" << endl;;
}