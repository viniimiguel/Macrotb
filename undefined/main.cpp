#include <iostream>
#include <windows.h>
#include "Macro.h"
#include <fstream>
#include <map>

using namespace std;

int main()
{
    
    Mc *mc1=new Mc();

    cout << "coloque o mouse em cima do pe do seu personagem para configurar o auto loot!" << endl;
    cout << "quando o mouse estiver no local exato aperte 'F' para confirmar!." << endl;
    while(true){
        if(GetAsyncKeyState(0x46)){
            mc1->getPoint();
            Sleep(200);
            break;
        }

    }
    Sleep(2000);
    string teclastr;
    cout << "digite a tecla em hexadecimal que voce quer que seja responsavel pelo autoloot por exemplo 'F'=0x46" << endl;
    cin >> teclastr;

    int tecla=stoi(teclastr, nullptr, 16);


    while(true){
        if(GetAsyncKeyState(tecla) & 0x8000){
            mc1->macroClick();
        }
        if(GetAsyncKeyState(0x1b)){
            break;
        }
    Sleep(50);
    }
    
    return 0;
}
