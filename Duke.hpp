#pragma once

#include "Player.hpp"
#include "Game.hpp"
#include <string>
namespace coup
{
    class Duke : public Player
    {
    public:
        Duke(Game& game, std::string name);
        ~Duke();
        void block(Player& other); // block Captain's steal
        
        /**
         * @brief take 3 coins from the bank, unblockable
         * 
         */
        void tax();
        std::string role() const {return "Duke";}
    };


}