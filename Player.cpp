#include "Player.hpp"
#include <iostream>
namespace coup{

    Player::Player(Game& game, std::string name): _game(game), _name(std::move(name)),
                                                 _coins(0), _status(Status::ALIVE)
    {
    if (_game.players().size() >= MAX_PLAYERS)
    {
        throw std::runtime_error("max player count is 6");
    }
        game.add_player(this);
    }

    Player::~Player()
        {
        }

    void Player::set_status(Status st)
    {
        //trying to kill a dead player
        if (_status != Status::ALIVE && st != Status::ALIVE)
        {
            throw ("can't kill the dead");
        }
        
        _status = st;
    }

    void Player::income()
    {
        start_turn(Action::INCOME);
        _coins++;
        _last_action.action = Action::INCOME;
        _last_action.subject = this;
        _game.end_turn();
    }
    void Player::foreign_aid()
    {
        start_turn(Action::FOREIGN_AID);
        _coins+=2;
        _last_action.action = Action::FOREIGN_AID;
        _last_action.subject = this;
        _game.end_turn();
    }
    void Player::coup(Player& other)
    {
        start_turn(Action::COUP);
        if (_coins < COUP_COST)
        {
            throw ("Not enough coins");
        }
        
        other.set_status(Status::DEAD);
        _coins -= COUP_COST;
        _last_action.action = Action::COUP;
        _last_action.subject = &other;
        _game.end_turn();
    }
    
    int Player::steal_coins(int n)
    {
        int stolen_coins = 0;
        for (size_t i = 0; i < n; i++)
        {
            if (_coins != 0)
            {
                stolen_coins++;
                _coins--;
            }
            
        }
        return stolen_coins;
    }

    void Player::start_turn(Action action){
        if (_game.players().size() > MAX_PLAYERS || _game.players().size() < MIN_PLAYERS)
        {
            throw ("number of player not right");
        }

        if (_game.turn() != _name)
        {
            throw ("Not your turn!");
        }
        if (_coins >= MAX_COINS && action != Action::COUP)
        {
            throw ("you posses 10 coins, kill someone already");
        }
        
        _game.activate_game();
        
    }

    std::ostream& operator<< (std::ostream& output, const Player& p){
        return output << p.name();
    }
}