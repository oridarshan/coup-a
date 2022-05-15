#pragma once

#include "Player.hpp"
#include "Game.hpp"
#include <string>
namespace coup
{
    class Assassin : public Player
    {
    public:
        Assassin(Game& game, std::string name);
        ~Assassin();

        /**
         * @brief if has less than 7 coins, try to coup with 3 coins
         * 
         * @param other 
         */
        void coup(Player &other);
        void block(Player& other){throw ("Assassin can't block");}
        std::string role() const {return "Assassin";}
    };


}