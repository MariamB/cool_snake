#include "Function.h"
#include "hConsole.h"

//--------------------------------------------------------------
void SetColor(ConsoleColor text, ConsoleColor background)
{
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
//--------------------------------------------------------------
void GotoXY(int X, int Y)
{
    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
}
//--------------------------------------------------------------
void ZmejaStart()
{
    GotoXY(10,15);cout <<"Збери 50 яблук;)"<<endl; //НАПИС: Собери 50 яблук;)
}
//--------------------------------------------------------------
void STENA_2() //Все, що  відображається на стіні
{
    SetColor(Green, Black);GotoXY(20,0);cout << "Snake game" <<endl;  //НАПИС: Гра Змійка
    GotoXY(64,2);cout <<  "Данi:" << endl ; //Дані
    GotoXY(64,3);cout <<  "Яблук:0" << endl ; //Яблук
    GotoXY(64,4); cout <<  "Довжина:3"<< endl; //Довжина
    GotoXY(64,5); cout <<  "Швидкiсть:0" << endl; //Швидкість
    GotoXY(64,7); cout << "Управлiння:" <<  endl; //Управління
    GotoXY(64,8); cout << "Esc:Вихiд" <<  endl; //Вихід
    GotoXY(64,9); cout << "P:Пауза" <<  endl; //Пауза
    GotoXY(64,10); cout <<"S:Старт" <<  endl; //Старт
    GotoXY(64,13);printf("%c",24);cout <<":Вгору"<<endl; //Вверх
    GotoXY(64,14);printf("%c",25);cout<<":Вниз"<<endl;   //Вниз
    GotoXY(64,15);printf("%c",27);cout<<":Влiво"<<endl;  //Вліво
    GotoXY(64,16);printf("%c",26);cout<<":Вправо"<<endl; //Вправо
                {SetColor(Yellow , Black);
                GotoXY(2,2); //Малюємо верхню горизонтальну лінію- стінку
                int m = 0;
                for(m = 0; m < 60; m++)
                {
                    printf("*");
                }
                }
                {
                    GotoXY(2,24); // Малюємо нижню горизонтальну лінію- стінку
                    int m = 0;
                    for(m = 0; m < 60;m++)
                    {
                        printf("*");
                    }
                }
                {   // Малюємо ліву лінію- стінку
                    GotoXY(2,3); cout << "*"<<endl;
                    GotoXY(2,4); cout << "*"<<endl;
                    GotoXY(2,5); cout << "*"<<endl;
                    GotoXY(2,6); cout << "*"<<endl;
                    GotoXY(2,7); cout << "*"<<endl;
                    GotoXY(2,8); cout << "*"<<endl;
                    GotoXY(2,9); cout << "*"<<endl;
                    GotoXY(2,10); cout << "*"<<endl;
                    GotoXY(2,11); cout << "*"<<endl;
                    GotoXY(2,12); cout << "*"<<endl;
                    GotoXY(2,13); cout << "*"<<endl;
                    GotoXY(2,14); cout << "*"<<endl;
                    GotoXY(2,15); cout << "*"<<endl;
                    GotoXY(2,16); cout << "*"<<endl;
                    GotoXY(2,17); cout << "*"<<endl;
                    GotoXY(2,18); cout << "*"<<endl;
                    GotoXY(2,19); cout << "*"<<endl;
                    GotoXY(2,20); cout << "*"<<endl;
                    GotoXY(2,21); cout << "*"<<endl;
                    GotoXY(2,22); cout << "*"<<endl;
                    GotoXY(2,23); cout << "*"<<endl;
                    }
                {   // Малюємо праву лінію- стінку
                    GotoXY(61,3); cout << "*"<<endl;
                    GotoXY(61,4); cout << "*"<<endl;
                    GotoXY(61,5); cout << "*"<<endl;
                    GotoXY(61,6); cout << "*"<<endl;
                    GotoXY(61,7); cout << "*"<<endl;
                    GotoXY(61,8); cout << "*"<<endl;
                    GotoXY(61,9); cout << "*"<<endl;
                    GotoXY(61,10); cout << "*"<<endl;
                    GotoXY(61,11); cout << "*"<<endl;
                    GotoXY(61,12); cout << "*"<<endl;
                    GotoXY(61,13); cout << "*"<<endl;
                    GotoXY(61,14); cout << "*"<<endl;
                    GotoXY(61,15); cout << "*"<<endl;
                    GotoXY(61,16); cout << "*"<<endl;
                    GotoXY(61,17); cout << "*"<<endl;
                    GotoXY(61,18); cout << "*"<<endl;
                    GotoXY(61,19); cout << "*"<<endl;
                    GotoXY(61,20); cout << "*"<<endl;
                    GotoXY(61,21); cout << "*"<<endl;
                    GotoXY(61,22); cout << "*"<<endl;
                    GotoXY(61,23); cout << "*"<<endl;
                }
}
//--------------------------------------------------------------
int intro()
{
    //setlocale(LC_ALL, "rus");
    GotoXY(3,10);
    printf("                               SNAKE ");
    GotoXY(15,11);
    printf("                   GAME!");
    getch();
    return 0;
}
//--------------------------------------------------------------
void PlusJabloko(Game &g) //Функція розкидання яблук
{
    int i, x[5], y[5], q = 5;
    int n = g.gaduka.PCount;
    do
    {
        for (int j = 0; j < 5; j++)
        {
            x[j] = rand() % 56 + 3; //
            y[j] = rand() % 19 + 3; //кординати яблука
            for (i = 4; i < n; i++)
            {
           if (x[j] == g.gaduka.t[i].X && y[j] == g.gaduka.t[i].Y) // перевірка щоб б яблко не потрапило на змію
                    break;
            }
        }
    }
    while(i < n);
    for (int j = 0; j < 5; j++)
    {
        g.jabloko.X = x[j]; //
        g.jabloko.Y = y[j]; //запам'ятовуємо  позицію яблука
        SetConsoleCursorPosition(hConsole, g.jabloko); //переносим курсор в цю позицию
        SetConsoleTextAttribute(hConsole, 0x0C); //колір  яблука
        printf("%c", 3); //малюємо яблуко яким хочемо символом
    }
}
//--------------------------------------------------------------


void skorostGame(Game &g) // Функція старту змійки її координат і швидкості
{
    system("cls");
    g.gaduka.PCount = 3; //задаємо точки - розмір змійки
    g.gaduka.t = new COORD [3];//створили  точки
    for(int i = 0; i < 3; i++)
    {
        g.gaduka.t[i].X = 20 + i;
        g.gaduka.t[i].Y = 20;

    }
    g.dx = 1;
    g.dy = 0;
    g.pause = 100;//швидкість руху змії
    PlusJabloko(g);//малюємо  яблука
}
//--------------------------------------------------------------
int Move(Game &g)
{
    int & n = g.gaduka.PCount;
    COORD head = g.gaduka.t[n - 1]; //голова
    COORD tail = g.gaduka.t[0]; //хвіст
    COORD next;
    next.X = head.X + g.dx;
    next.Y = head.Y + g.dy; //перевірка наступної точки по напрямку

    if(next.X < 3 || next.Y < 3 || next.X > 60 || next.Y > 23)// Чи не вперлась  в стіну?
        return STENA;

    if(n > 4)
    {
        for(int i = 0; i < n; i++)
            if(next.X == g.gaduka.t[i].X && next.Y == g.gaduka.t[i].Y) //не наїхали  на себе?
                return KONEC;
    }

    if(next.X == g.jabloko.X && next.Y == g.jabloko.Y)
    {
        COORD*temp = new COORD[ ++n ]; //новий масив більший на 1
        for(int i = 0; i < n; i++)
            temp[i] = g.gaduka.t[i]; //перекопіюємо
        temp[n - 1] = next; //додаєм одну
        delete [] g.gaduka.t;
        g.gaduka.t = temp;

        SetConsoleCursorPosition(hConsole,head);
        SetConsoleTextAttribute(hConsole, 0x0a); //зафарбовуємо  яблуко яке з'їли

        printf("*");
        SetConsoleCursorPosition(hConsole,next);
        SetConsoleTextAttribute(hConsole,0x0a);
        printf("%c",1);
        PlusJabloko(g);
        return PLUS;
    }

    for(int i = 0; i < n - 1; i++)
        g.gaduka.t[i] = g.gaduka.t[i + 1];
    g.gaduka.t[n - 1] = next;
    SetConsoleCursorPosition(hConsole,tail);//зафарбовуємо хвостик
    printf(" ");

    SetConsoleCursorPosition(hConsole,head);
    SetConsoleTextAttribute(hConsole, 0x0b);//фарбуємо  хвіст змії в зелений колір
    printf("*");
    SetConsoleCursorPosition(hConsole,next);
    SetConsoleTextAttribute(hConsole,0x0f); //красим курсор в білий колір(голову змії)
    printf("%c",1);

    return MOVE;
}
//--------------------------------------------------------------

void buttons(Game &g)
{
int key = 0, count = 0;
    bool Pause=false;
    bool pause = false;
 while(key != 27) //27 - клавіша вправо
    {
        while(!kbhit()) //ждем пока нажмем
        {
            if(Pause==true)
            {
                Sleep(1);
                continue;
            }

            switch (Move(g))//рух
            {

            case PLUS:
                ++count;
                g.pause-=1;
                SetColor(Green , Black);
                GotoXY(64,2);cout <<  "Данi:" << endl ;
                GotoXY(64,3); cout << "Яблук:" <<count << endl;
                GotoXY(64,4); cout << "Довжина:" <<g.gaduka.PCount << endl;
                GotoXY(64,5); cout << "Швидкiсть:" <<g.pause<< endl;
                GotoXY(64,7); cout << "Управлiння:" <<  endl;
                GotoXY(64,8); cout << "Esc:Вихiд" <<  endl;
                GotoXY(64,9); cout << "P:Пауза" <<  endl;
                GotoXY(64,10); cout <<"S:Старт" <<  endl;
                GotoXY(64,13);printf("%c",24);cout <<":Вгору"<<endl;
                GotoXY(64,14);printf("%c",25);cout<<":Вниз"<<endl;
                GotoXY(64,15);printf("%c",27);cout<<":Влiво"<<endl;
                GotoXY(64,16);printf("%c",26);cout<<":Вправо"<<endl;
                if (count == 50)
                {
                    SetColor(White , Black);
                    GotoXY(24,1); cout << "Ви виграли" << endl; //Ви виграли
                    getch();
                   // return(0);
                }
                break;

            case STENA:

            case KONEC:
                GotoXY(23,1); printf("The end  \n\n\t\t\t"); //Ви програли
                getch();
                break;
            }

            Sleep(g.pause); //Затримка
        }
    key = getch();

        if(key=='P'||key=='p')
            Pause=!Pause;
            else if(key=='S'||key=='s')
            ZmejaStart();
        else if(key==0||key==224)
        {
            key=getch();

            if(key == 72 && g.nap != DOWN)
            {
                g.nap = UP;
                g.dx = 0;
                g.dy = -1;
            }
            else if(key == 80 && g.nap != UP)
            {
                g.nap = DOWN;
                g.dx = 0;
                g.dy = 1;
            }
            else if(key == 75 && g.nap != RIGHT)
            {
                g.nap = LEFT;
                g.dx = -1;
                g.dy = 0;
            }
            else if(key == 77 && g.nap != LEFT)
            {
                g.nap = RIGHT;
                g.dx = 1;
                g.dy = 0;
            }
        }
    }
}
//--------------------------------------------------------------


