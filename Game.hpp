#pragma once

#include <string>
#include <vector>
namespace coup
{
    class Player;
    static const int MIN_PLAYERS = 2;
    static const int MAX_PLAYERS = 6;
    static const int ASSASSIN_COUP_COST = 3;
    static const int COUP_COST = 7;
    static const int MAX_COINS = 10;

    class Game
    {
    private:     
        bool _game_on;
        std::vector <Player*> _players;
        int _turn_id;
    public:
        Game();
        ~Game();
        std::string turn() const;//return the name of the player that should play next
        std::string winner() const;//return name of the winner if game ended

        /**
         * @brief return vector with name of active players
         * 
         * @return std::vector<std::string> 
         */
        std::vector<std::string> players() const;
        void add_player(Player* p);
        void activate_game(){_game_on = true;}

        /**
         * @brief end current turn and find next player to play
         * 
         */
        void end_turn();

    };
}
#include "Player.hpp"