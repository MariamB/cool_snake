#include "Snake.h"
#include "Game.h"
#include "Function.h"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "");
    intro();
    Game g;
    skorostGame(g);
    STENA_2();
    srand(time(0));
    buttons(g);
    return 0;
  }






