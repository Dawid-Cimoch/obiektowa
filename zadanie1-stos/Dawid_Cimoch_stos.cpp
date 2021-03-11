//Stos strukturalnie

//Pobieranie bibliotek 
#include <iostream>
#include <ctime>
using namespace std;

typedef struct 
{
    int *tab,
    wierzch,
    rozmiar;
} Stos;

void init(Stos& s, int rozm)
{
    s.tab = new int[rozm];
    s.rozmiar = rozm;
    s.wierzch = -1;
}

void destroy(Stos& s)
{
    delete[] s.tab;
}

int empty(Stos& s)
{
    return s.wierzch ==-1;
}

int full(Stos& s)
{
    return s.wierzch == s.rozmiar-1;
}

void push(Stos& s, int cnt)
{
    if (full(s)==1)
    {
        cout<<"Stos pelny"<<endl;
    }
    else
    {
        s.tab[++s.wierzch] = cnt;
    }
}

void pop(Stos& s)
{
    if (empty(s)==1)
    {
        cout<<"Stos jest pusty"<<endl;
    }
    else
    {
        --s.wierzch;
    }
}

int top(Stos& s)
{
    return s.tab[s.wierzch];
}
int main()
{
    srand(time(0));    
    int ls=(rand()%20)+1;
    Stos s1;
    init(s1, ls);
    cout<<"Wielkosc stosu bedzie wynosic: "<<ls<<endl;
    for(int i=0; i<ls; i++)
    {
        int a=(rand()%100)+1;
        push(s1,a);
    }
    while( !empty(s1))
    {
        cout<<top(s1)<<endl;
        pop(s1);
    }
    destroy(s1);
    system("pause");
	return 0;
}