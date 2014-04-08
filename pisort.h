#ifndef PISORT_H
#define PISORT_H
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

class PiSort{
private:
    size_t pir_size;
    vector <int> pir;
    vector <int>::iterator cur;
public:
    PiSort(int top){
        pir.push_back(top);
        pir_size=1;pir.push_back(0);
    }//РєРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ РІ РєРѕС‚РѕСЂС‹Р№ РїРµСЂРµРґР°РµС‚СЃСЏ РѕРґРЅРѕ Р·РЅР°С‡РµРЅРёРµ

    PiSort(vector <int> mass){      //РєРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ РІ РєРѕС‚РѕСЂС‹Р№ РїРµСЂРµРґР°РµС‚СЃСЏ РІРµРєС‚РѕСЂ
        pir_size=0;
        for(size_t i=0;i<mass.size();i++)
        {
            pir.push_back(mass[i]);
            pir_size++;
        }
        pir.push_back(0);
    }

    PiSort(){
        pir_size=0;
        pir.push_back(0);
    }  //РїСѓСЃС‚РѕР№ РєРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ

    void PiProseykaAll();
    void PiProseykaVverx(size_t i);
    void PiProseykaVniz(size_t parent);
    void PiAddNew(int k);
    void PiAddNew(vector <int> advec);
    void PiOutput();
    void PiFOutput(ofstream& f);
    void PiSortir();
    void PiRemove(size_t i);
};

#endif // PISORT_H
