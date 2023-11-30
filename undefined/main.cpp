#include <iostream>
#include <windows.h>
#include "Macro.h"
#include <fstream>

using namespace std;

int main()
{
    
    Mc *mc1=new Mc();

    cout << "coloque o mouse em cima do pe do seu personagem para configurar o auto loot!\n" << endl;
    cout << "quando o mouse estiver no local exato aperte 'F' para confirmar!.\n" << endl;
    while(true){
        if(GetAsyncKeyState(0x46)){
            mc1->getPoint();
            Sleep(200);
            break;
        }

    }
    Sleep(2000);
    string teclastr;
    cout << "digite a tecla em hexadecimal que voce quer que seja responsavel pelo autoloot por exemplo 'F'=0x46\n" << endl;
    cin >> teclastr;
    cout << "Pronto configurado com sucesso voce ja pode usar o seu autoloot.\n" << endl;
    cout << "DIGITE 'ESC' PARA PARAR O BOT \n" << endl;

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
    cin.get();
    return 0;
}
