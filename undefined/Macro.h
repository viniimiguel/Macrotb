#ifndef MACRO_H_INCLUDE
#define MACRO_H_INCLUDE

#include <vector>
#include <iostream>
#include <windows.h>

class Mouse{
    public:
        int x;
        int y;
        int getPoint();
        void xy();
    private:
};

void Mouse::xy(){
    std::cout << " x " << x << " y " << y << std::endl;
}
int Mouse::getPoint(){
    POINT cursorPoint;
    if(GetCursorPos(&cursorPoint)){
        std::cout << "Sua localizacao no eixo x e: " << cursorPoint.x << ", sua localizacao no eixo y e: " << cursorPoint.y << std::endl;
        x=cursorPoint.x;
        y=cursorPoint.y;
        return 0;
    }
    else{
        std::cout << "nao foi possivel localizar a localizacao do seu mouse.";
        return -1;
    }
}

class Mc:public Mouse{
    public:
        Mc(){
            getPoint();
        }
        void macroClick();
        void mxy();
        void kpress();
    private:

};

void Mc::mxy(){
    std::cout << " x " << x << " y " << y << std::endl;
}

void Mc::macroClick() {
    std::vector<std::pair<int, int>> offsets = {
        {0, 0}, {32, -32}, {32, 0}, {32, 32}, {0, 32},
        {-32, 32}, {-32, 0}, {-32, -32}, {0, -32}
    };

    keybd_event(VK_LSHIFT, 0,0,0);
    for (const auto& offset : offsets) {
        SetCursorPos(x + offset.first, y + offset.second);
        mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
        Sleep(20);
    }
    keybd_event(VK_LSHIFT, 0,KEYEVENTF_KEYUP,0);
}



#endif