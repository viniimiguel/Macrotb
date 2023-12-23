#include <iostream>
#include <Windows.h>
#include "macro.h"
#include <string>


int main()
{
	std::string teclastr;
	Mc* m1 = new Mc();

	std::cout << "coloque o mouse em cima do pe do seu personagem para configurar o auto loot!\n" << std::endl;
	std::cout << "quando o mouse estiver no local aperte 'F' para confirmar\n" << std::endl;

	while(true)
	{
		
		if (GetAsyncKeyState(0x46) & 0x8000)
		{
			

			m1->getposition();
			std::cout << "pronto autoloot configurado agora basta apenas definir uma tecla para ativacao do macro\n" << std::endl;
			break;
		}
		Sleep(100);
	}

	std::cout << "digite em hexadecimal a tecla que deseja para iniciar o macro exemplo: '0x46' este valor equivale a tecla (F)\n" << std::endl;
	std::cin >> teclastr;
	int tecla = stoi(teclastr, nullptr, 16);
	std::cout << "pronto configurado agora voce pode usar seu autoloot normalmente\n" << std::endl;

	while (true)
	{
		
		if (GetAsyncKeyState(tecla) & 0x8000)
		{
			m1->startmacro();
		}
		Sleep(100);
	}


	return 0;
}