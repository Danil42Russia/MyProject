#include "stdafx.h"

int main(int argc, char* argv[])
{
  setlocale(LC_ALL, "ru");
  srand(static_cast<unsigned>(time(nullptr)));

  vector<vector<vector<string>>> vec;

  while (true)
    main_menu(vec);
}