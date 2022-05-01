#pragma once

#include "Player.hpp"
#include "Game.hpp"
#include <string>
namespace coup
{
    class Contessa : public Player
    {
    private:

    public:
        Contessa(Game game, std::string name);
        ~Contessa();
        void block (Player assassin);
    };

    void Contessa::block (Player assassin){}

    Contessa::Contessa(Game game, std::string name) : Player(game, name)
    {
    }

    Contessa::~Contessa()
    {
    }

}
