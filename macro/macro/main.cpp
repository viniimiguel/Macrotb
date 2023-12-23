#include <iostream>
#include <vector>
#include <Windows.h>
#include "macro.h"

void Mc::getposition()
{
	POINT cursorPoint;
	if (GetCursorPos(&cursorPoint))
	{
		std::cout << "a posicao do seu cursor no e de x: " << cursorPoint.x << " y: " << cursorPoint.y << std::endl;
		x = cursorPoint.x;
		y = cursorPoint.y;
	}
}

void Mc::startmacro()
{
	std::vector < std::pair<int, int>> offsets = {
		{0, 0}, {32, -32}, {32, 0}, {32, 32}, {0, 32},
		{-32, 32}, {-32, 0}, {-32, -32}, {0, -32}
	};
	keybd_event(VK_LSHIFT, 0, 0, 0);
	for (const auto& offset : offsets)
	{
		SetCursorPos(x + offset.first, y + offset.second);
		mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
		Sleep(20);
	}
	keybd_event(VK_LSHIFT, 0, KEYEVENTF_KEYUP, 0);
}