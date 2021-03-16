#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

struct osoba
{
    string imie;
    string nazwisko;
    int wiek;
    float skutecznosc;
    osoba *next;
    osoba();
};

osoba::osoba()
{
    next=0;
}

struct list
{
    osoba *pierwsza;
    void add_from_file(string nazwa);
    void show_list();
    float max_skutecznosc();
    bool nazwisko_ski(string nazwisko, string end);
    void wybierz_osoby();
    void save_to_file(string nazwa);
    list();
};

list::list()
{
    pierwsza=0;
}

void list::add_from_file(string nazwa)
{
    fstream first_file(nazwa); //plik do odczytu
    while(!first_file.eof())
    {
        osoba *nowa= new osoba;

        string imie, nazwisko;
        int wiek;
        float skutecznosc;

        first_file >> imie >> nazwisko >>wiek >> skutecznosc;

        nowa->imie=imie;
        nowa->nazwisko=nazwisko;
        nowa->wiek=wiek;
        nowa->skutecznosc=skutecznosc;

        if(pierwsza==0) //czy jest to pierwszy element listy
        {
            pierwsza = nowa;
        }
        else
        {
            osoba *temp=pierwsza;

            while(temp->next)
            {
                temp = temp->next;
            }
            temp->next = nowa;
            nowa->next = 0;
        }
    }
    first_file.close();
}

void list::show_list()
{
    osoba *temp = pierwsza;

    while(temp)
    {
        cout << temp->imie << " " << temp->nazwisko << " " << temp->wiek << " " << temp->skutecznosc << endl;
        temp = temp->next;
    }
}

float list::max_skutecznosc()
{
    osoba *temp = pierwsza;

    float max_eff = 0;

    while(temp)
    {
        if(temp->skutecznosc > max_eff)
        {
            max_eff = temp->skutecznosc;
        }
        temp = temp->next;
    }
    return max_eff;
}

bool list::nazwisko_ski(string nazwa, string end)
{
    return nazwa.rfind(end)==(nazwa.length()-end.length());
}

void list::save_to_file(string nazwa)
{
    ofstream secound_file(nazwa);

    float max_eff = max_skutecznosc();

    osoba *temp = pierwsza;

    bool rekord = false;

    while(temp)
    {
        if(temp->imie.length()>3 && nazwisko_ski(temp->nazwisko, "ski")==true && temp->skutecznosc==max_eff)
        {
            for(int i=1; i<temp->imie.length()-3; i++)
            {
                temp->imie[i]='*';
            }
            for(int i=1; i<temp->nazwisko.length()-3; i++)
            {
                temp->nazwisko[i]='*';
            }
            secound_file << temp->imie << " " << temp->nazwisko << " " << temp->wiek << endl;
            rekord = true;
        }
        temp = temp->next;
    }
    if(rekord==false)
    {
        secound_file << "\n" << endl;
    }
    secound_file.close();
}

int main()
{
    list *data = new list;
    string name;
    string full_name;
    string max_name;

    cout << "Wpisz nazwe pliku: " << endl;
    cin >> name;
    
    full_name=name+".txt";
    max_name= name+".max.txt";

    data->add_from_file(full_name);
    data->save_to_file(max_name);

    delete(data);
    system("pause");
    return 0;
}