#include <iostream>
using namespace std;

class Stos
{
    public:
    int *tab,
    wierzch,
    rozmiar;

    void init(int rozm)
    {
    tab = new int[rozm];
    rozmiar = rozm;
    wierzch = -1;
    }
    
    void destroy()
    {
    delete[] tab;
    }

    int empty()
    {
    return wierzch ==-1;
    }

    int full()
    {
    return wierzch == rozmiar-1;
    }

    void push(int cnt)
    {
    tab[++wierzch] = cnt;
    }

    void pop()
    {
    --wierzch;
    }

    int top()
    {
    return tab[wierzch];
    }    
};
int main()
{
    Stos stos;
    Stos stos2;
    int n=10,a;
    stos.init(n);
    stos2.init(n);
    cout<<"Podaj "<<n<<" liczb:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        stos.push(a);
    }
    cout<<"Liczby w stosie to: "<<endl;
    while(!stos.empty())
    {
        cout<<stos.top()<<' ';
        stos2.push(stos.top());
        stos.pop();
    }
    //Wkladnie znowu z pierwszego na drugi stos:
    while(!stos2.empty())
    {
        stos.push(stos2.top());
        stos2.pop();
    }
    cout<<endl;
    stos.destroy();
    stos2.destroy();
    system("pause");
	return 0;
}