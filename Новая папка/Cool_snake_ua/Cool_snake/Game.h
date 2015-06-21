#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

class Game //дані: змійки, яблук, руху  по X і Y, затримка, напрямок
{
    public:Snake gaduka; //змійка
    COORD jabloko; //яблуко
    int dx,dy; //пересування
    int pause; //затримка
    int nap; //напрямок

};

#endif // GAME_H_INCLUDED
