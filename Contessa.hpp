#pragma once

#include "Player.hpp"
#include "Game.hpp"
#include <string>
namespace coup
{
    class Contessa : public Player
    {
    public:
        Contessa(Game& game, std::string name);
        ~Contessa();
        void block(Player& other); // block assassin's special coup
        std::string role() const {return "Contessa";}
    };


}
