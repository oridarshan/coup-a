#pragma once

#include "Player.hpp"
#include <string>
namespace coup
{
    class Ambassador : public Player
    {
    public:
        Ambassador(Game& game, std::string name);
        ~Ambassador();
        void steal (Player& other);
        void block (Player& other);
        void transfer(Player& from, Player& to);
        std::string role() const {return "Ambassador";}
    };

}