#include <iostream>
#include "function.h"

enum Color
{
    red = 1,    
    green,
    bule

};
class Player 
{
public:
    enum level
    {
        Error = 0,
        Warning,
        Info
    };
    Player()
    {
        this->x = 0;
        this->y = 0;
        this->speed = 1;
    }
    Player(int x, int y,int speed = 1)
    {
        this->x = x;
        this->y = y;
        this->speed = speed;
    }
    void SpeedSet(int value)
    {
        this->speed = value;
    }
    void SetX(int x)
    {
        this->x = x;
    }
    void SetY(int y)
    {
        this->y = y;
    }
    int SpeedGet()
    {
        return this->speed;
    }
    int GetX()
    {
        return (this->x);
    }
    int GetY()
    {
        return (this->y);
    }
    void move( int x, int y)
    {
        this->x += x * this->speed;
        this->y += y * this->speed;
        this->count++;
    }
    static void PrintCount()
    {
        std::cout << count << std::endl;
    }
    friend void FlagFunc(Player &p1); 
    
private:
    int speed;
    int x, y;
    static int count;

};
int Player::count = 0;
void FlagFunc(Player &p1)
{
    std::cout << p1.x << std::endl;
}

void Move(Player& player, int x, int y)
{
    player.SetX(x * player.SpeedGet() + player.GetX());
    player.SetY(y * player.SpeedGet() + player.GetY());
}
int main()
{
    int a = 10;
    char b = 0;
    Player p1(10,10,1);
    Move(p1, 10, 10);
    p1.move(10, 10);
    
    debug("ok!");
    FlagFunc(p1);
    Player::PrintCount();
    std::cout << "Hello World!\n"<< std::endl << p1.GetX();
}

