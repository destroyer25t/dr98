#include "pisort.h"

void PiSort::PiProseykaAll(){                   //преобразование обычного массива в пирамиду
    for(size_t j=0;j<pir_size;j++){
        PiProseykaVverx(j);
    }
}
void PiSort::PiProseykaVverx(size_t i){         //просеивание элемента снизу вверх
    if((i!=0)&&(pir[i]>=pir[i/2]))
    {
        swap(pir[i],pir[i/2]);
        PiProseykaVverx(i/2);
    }
}
void PiSort::PiProseykaVniz(size_t parent){     //просеивание элемента сверху вниз(для сортировки)
    while(true){
        size_t left=2*parent+1;
        size_t right=left+1;
        size_t max=parent;
        if(left>=pir_size) left=pir.size()-1;
        else
            if(right>=pir_size) right=pir.size()-1;
            else{
                if(pir[left]>=pir[parent]){max=left;}
                if(pir[right]>=pir[left]){max=right;}
            }
        if((parent==pir_size-1)||(parent==max)) break; else
        {
            swap(pir[parent],pir[max]);
            parent=max;
        }
    }
}
void PiSort::PiAddNew(int k){                   //добавление элемента в вектор и установка его в пирамиду
    pir.push_back(k);
    swap(pir[pir.size()-1],pir[pir.size()-2]);
    PiProseykaVverx((++pir_size-1));

    //PiProseykaAll(); //может быть не нужна
}
void PiSort::PiAddNew(vector <int> advec){

}
void PiSort::PiOutput(){                        //вывод вектора на экран
    for(size_t i=0;i<pir.size()-1;i++){
        cout<<pir[i]<<" ";
    }
    cout<<endl;
}

void PiSort::PiFOutput(ofstream& f){
    for(size_t i=0;i<pir.size()-1;i++){
        f<<pir[i]<<" ";
    }
    f<<endl;
}

void PiSort::PiSortir(){                        //сортировка вектора при помощи пирамиды
    while(pir_size>=1){
        pir_size--;
        swap(pir[0],pir[pir_size]);
        PiProseykaVniz(0);
    }
    size_t i=0;
    while(pir[i]>pir[i+1]){
        swap(pir[i],pir[i+1]);
        i++;}
}


void PiSort::PiRemove(size_t i){
    pir.erase(pir.begin()+i);
    pir_size--;
    PiProseykaAll();
}
