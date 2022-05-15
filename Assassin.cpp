#include "Assassin.hpp"

namespace coup{

    void Assassin::coup(Player &other)
    {
        start_turn(Action::COUP);
        if (_coins < ASSASSIN_COUP_COST)
        {
            throw ("Not enough coins");
        }
        if (_coins < COUP_COST)
        {
            other.set_status(Status::ASSASSINATED);
            _last_action.action = Action::ASSASSINATE;
            _last_action.subject = &other;
            _coins-=ASSASSIN_COUP_COST;
            _game.end_turn();
        }
        else
        {
            other.set_status(Status::DEAD);
            _last_action.action = Action::COUP;
            _last_action.subject = &other;
            _coins-=COUP_COST;
            _game.end_turn();
        }
    }

    Assassin::Assassin(Game& game, std::string name) : Player(game, std::move(name))
    {
    }

    Assassin::~Assassin()
    {
    }
}