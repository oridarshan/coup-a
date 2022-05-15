#include "Game.hpp"


namespace coup{
    
    std::string Game::turn() const
    {
        return _players.at((size_t)_turn_id)->name();
    }
    std::string Game::winner() const
    {
        // game ended and only 1 player left
        if (players().size() == 1 && _game_on)
        {
            return players().at(0);
        }
        throw ("Game in progress / not started");
    }
    std::vector<std::string> Game::players() const
    {
        std::vector <std::string> res;
        for(Player* p : _players){
            if (p->get_status() == Status::ALIVE)
            {
                res.push_back((*p).name());
            }
        }
        return res;
    }

    void Game::add_player(Player* p)
    {
        if(_game_on)
        {
            throw ("you can't join midgame, come early next time");
        }
        _players.push_back(p);
    }

    void Game::end_turn()
    {
        // next ALIVE player
        do {
            _turn_id++;
            _turn_id = _turn_id % (int)_players.size();
        } while (_players.at((size_t)_turn_id)->get_status() != Status::ALIVE);
        // validate last action of the player now playing
        _players.at((size_t)_turn_id)->get_turn();
    }

    Game::Game()
    {
        _game_on = false;
        _turn_id = 0;
    }

    Game::~Game()
    {
    }
}