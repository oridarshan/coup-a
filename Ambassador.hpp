#pragma once

#include "Player.hpp"
#include "Game.hpp"
#include <string>
namespace coup
{
    class Ambassador : public Player
    {
    private:

    public:
        Ambassador(Game game, std::string name);
        ~Ambassador();
        void steal (Player assassin);
        void block (Player assassin);
        void transfer(Player from, Player to){}
    };

    void Ambassador::steal (Player assassin){}
    void Ambassador::block (Player assassin){}

    Ambassador::Ambassador(Game game, std::string name) : Player(game, name)
    {
    }

    Ambassador::~Ambassador()
    {
    }

}