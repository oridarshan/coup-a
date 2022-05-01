#pragma once
#include "Game.hpp"
#include <string>
namespace coup
{
    class Player
    {
    private:
        Game game;
        std::string name;
    public:
        // Player(Game game, std::string name);
    public:
        Player(Game game, std::string name);
        ~Player();
        void income(){}
        void foreign_aid(){}
        void coup(Player other){}
        int coins(){return 0;}
    };

    Player::Player(Game game, std::string name): game(game),name(name)
    {
    }

    Player::~Player()
    {
    }
    
} // namespace coup

