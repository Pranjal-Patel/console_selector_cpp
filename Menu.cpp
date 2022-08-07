#include "Menu.h"

namespace menu
{
	int draw(std::vector<std::string> options)
	{
		auto move = [](short x, short y) {
			SetConsoleCursorPosition(HANDLE, { x, y });
		};

		auto hide_cursor = []() {
			CONSOLE_CURSOR_INFO csi;
			csi.dwSize = 100;
			csi.bVisible = false;

			SetConsoleCursorInfo(HANDLE, &csi);
		};

		auto draw = [options, hide_cursor, move](int arrow_idx) {
			system("cls");

			CONSOLE_SCREEN_BUFFER_INFO csbi;
			GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
			int height, width;

			width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
			height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

			auto move_idx = [width, height, move](int x, int y) {
				move((width / 2) - x, height / 2 - 1 - y);
			};

			hide_cursor();
			for ( int c = 0; c < options.size(); c++ )
			{
				std::string current_item = options[c];
				if (c == arrow_idx) 
					current_item = "----> " + current_item + " <----";

				move_idx(current_item.size() / 2, options.size() - c);
				std::cout << current_item;
			}
		};

		int current_idx = 0;
		draw(current_idx);

		struct arrow_key arrow;
		while (true)
		{
			if (_kbhit())
			{
				char key = _getch();
				bool change = false;

				struct arrow_key arrow;

				if (key == arrow.up)
				{
					if (current_idx != 0)
						{ current_idx --; change = true; }
				}
				else if (key == arrow.down)
				{
					if (current_idx != options.size() - 1)
						{ current_idx ++; change = true; }
				}

				else if ((int)key == 13)
					{ return current_idx; break; }

				if (change) draw(current_idx);
			}
		}
	}
}