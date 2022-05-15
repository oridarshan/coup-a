#include "Duke.hpp"

namespace coup{
    
    void Duke::block(Player& other)
    {
        if (other.last_action().action != Action::FOREIGN_AID)
        {
            throw ("Duke can only block 'forien_aid'");
        }
        other.steal_coins(2);
    }
    void Duke::tax()
    {
        start_turn(Action::TAX);
        _coins += 3;
        _last_action.action = Action::TAX;
        _last_action.subject = this;
        _game.end_turn();
    }

    // Duke::Duke(Game game, std::string name) : Player(game, name)
    Duke::Duke(Game& game, std::string name) : Player(game, std::move(name))
    {
    }

    Duke::~Duke()
    {
    }
}