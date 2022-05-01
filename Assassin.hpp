#pragma once

#include "Player.hpp"
#include "Game.hpp"
#include <string>
namespace coup
{
    class Assassin : public Player
    {
    private:

    public:
        Assassin(Game game, std::string name);
        ~Assassin();
        void steal (Player assassin);
        void block (Player assassin);
    };

    void Assassin::steal (Player assassin){}
    void Assassin::block (Player assassin){}

    Assassin::Assassin(Game game, std::string name) : Player(game, name)
    {
    }

    Assassin::~Assassin()
    {
    }

}