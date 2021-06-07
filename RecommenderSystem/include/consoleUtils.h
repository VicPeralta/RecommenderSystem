
#pragma once

#include <windows.h> 

struct ConsoleColor {
	static constexpr char ESC = 0x27;
	inline static const char* CSI = "\x1b[";
	inline static const char* foregroundRed = "\x1b[31m";
	inline static const char* foregroundGreen = "\x1b[32m";
	inline static const char* foregroundYellow = "\x1b[33m";
	inline static const char* foregroundDefault = "\x1b[m";

	static void moveCursorTo(std::ostream& stream, int x, int y) {
		stream << "\x1b[" << x << ";" << y << "H";
	}
	static void clearScreen(std::ostream& stream) {
		stream << "\x1b[2J";
		ConsoleColor::moveCursorTo(stream, 0, 0);
	}
	DWORD dwPrev{};
	HANDLE handleConsole{};
	ConsoleColor() {
		handleConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleMode(handleConsole, &dwPrev);
		SetConsoleMode(handleConsole, dwPrev | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
	}
	~ConsoleColor() {
		SetConsoleMode(handleConsole, dwPrev);
	}
};
inline void pressEnterKey() {
	std::cout << "Press ENTER key to continue\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	int ch;
	do {
		ch = getchar();
	} while (ch != 10);
}


