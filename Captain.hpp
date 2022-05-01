#pragma once

#include "Player.hpp"
#include "Game.hpp"
#include <string>
namespace coup
{
    class Captain : public Player
    {
    private:

    public:
        Captain(Game game, std::string name);
        ~Captain();
        void steal (Player assassin);
        void block (Player assassin);
    };

    void Captain::steal (Player assassin){}
    void Captain::block (Player assassin){}

    Captain::Captain(Game game, std::string name) : Player(game, name)
    {
    }

    Captain::~Captain()
    {
    }

}