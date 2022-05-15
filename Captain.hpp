#pragma once

#include "Player.hpp"
#include "Game.hpp"
#include <string>
namespace coup
{
    class Captain : public Player
    {
    public:
        Captain(Game& game, std::string name);
        ~Captain();

        /**
         * @brief steal 2 coins from 'other'
         * 
         * @param other 
         */
        void steal (Player& other);
        void block (Player& other); // block Captain's steal
        std::string role() const {return "Captain";}
    };


}