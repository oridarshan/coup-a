#include "Captain.hpp"

namespace coup{
    
    void Captain::steal (Player& other)
    {
        start_turn(Action::STEAL);
        int stolen_coins = other.steal_coins(2);
        _coins += stolen_coins;
        _last_action.action = Action::STEAL;
        _last_action.subject = &other;
        _game.end_turn();
    }
    void Captain::block (Player& other)
    {
        if (other.last_action().action != Action::STEAL)
        {
            throw ("Captain can only block 'steal'");
        }
        int stolen_coins = other.steal_coins(2);
        other.last_action().subject->add_coins(stolen_coins);
    }

    Captain::Captain(Game& game, std::string name) : Player(game, std::move(name))
    {
    }

    Captain::~Captain()
    {
    }
}