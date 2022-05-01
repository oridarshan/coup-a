#pragma once

#include "Player.hpp"
#include "Game.hpp"
#include <string>
namespace coup
{
    class Duke : public Player
    {
    private:

    public:
        Duke(Game game, std::string name);
        ~Duke();
        void steal (Player assassin);
        void block (Player assassin);
        void tax(){}
    };

    void Duke::steal (Player assassin){}
    void Duke::block (Player assassin){}

    // Duke::Duke(Game game, std::string name) : Player(game, name)
    Duke::Duke(Game game, std::string name) : Player(game, name)
    {
    }

    Duke::~Duke()
    {
    }

}