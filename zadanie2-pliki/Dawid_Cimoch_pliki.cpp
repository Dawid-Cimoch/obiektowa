#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//Funkcja ifSki czy string "text", kończy się na string "text_end"
//rfind sprawdza czy "text" kończy się w tym samym miejscu co zaczyna się "text_end"
bool ifSki(const string text, const string text_end)
{
    return text.rfind(text_end)==(text.size()-text_end.size());
}

int main()
{
    cout << "Podaj nazwe pliku, ktory chcesz wczytac" << endl;
    string file_name;
    cin>>file_name;
    string full_file_name=file_name+".txt";
    fstream first_file(full_file_name); //plik do odczytu
    float max_eff=0;
    bool if_existe=false;
    if(first_file)
    {
        string imie;
        string nazwisko;
        int wiek;
        float skutecznosc;
        while(!first_file.eof())
        {
            first_file>>imie;
            first_file>>nazwisko;
            first_file>>wiek;
            first_file>>skutecznosc;
            if(skutecznosc>max_eff)
            {
                max_eff=skutecznosc;
            }
        }
        first_file.seekg(0, ios::beg); //ustawiam pozycje początkową odczytu danych od pierwszego znaku, a przesuniecie pozycji jest wyrazone wzgledem poczatku pliku 
        string full_secound_file_name = file_name + ".max" + ".txt";
        ofstream secound_file(full_secound_file_name); //plik do zapisu
        while(!first_file.eof())
        {
            first_file>>imie;
            first_file>>nazwisko;
            first_file>>wiek;
            first_file>>skutecznosc;
            if(imie.length()>3 && ifSki(nazwisko, "ski")==1 && skutecznosc==max_eff)
            {
                int len_imie = imie.length();
                int len_nazwisko = nazwisko.length();
                //anonimizujemy dane
                for(int i=1; i<len_imie-3;i++)
                {
                    imie[i]='*';
                }
                for(int i=1; i<len_nazwisko-3; i++)
                {
                    nazwisko[i]='*';
                }
                secound_file<<imie<<" "<<nazwisko<<" "<<wiek<<endl;
                if_existe=true;
            }
        }
        if(if_existe==false)
        {
            secound_file<<"\n";
        }
        first_file.close();
        secound_file.close();
    }
    else
    {
        cout<<"Nie mozna otworzyc pliku"<<endl;
    }
    system("pause");
    return 0;
}