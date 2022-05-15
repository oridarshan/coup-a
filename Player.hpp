#pragma once

#include "Status.hpp"
#include "LastAction.hpp"
#include "Game.hpp"

#include <string>
namespace coup
{
    
    class Player
    {
    protected:
        Game& _game;
        std::string _name;
        int _coins;
        Status _status;
        LastAction _last_action = {Action::IN_TURN, NULL};

        /**
         * @brief start turn doing 'action', if possible
         * 
         * @param action 
         */
        void start_turn(Action action);

    public:
        Player(Game& game, std::string name);
        ~Player();

        Status get_status() const {return _status;}
        std::string name() const {return _name;}
        /**
         * @brief add 1 coin from the bank, unblockable
         * 
         */
        void income();

        /**
         * @brief add 2 coin from the bank
         * 
         */
        void foreign_aid();

        const LastAction& last_action() const {return _last_action;}
        
        /**
         * @brief kill 'other', costs 7 coins
         * 
         * @param other 
         */
        virtual void coup(Player& other);

        /**
         * @brief block other's last action.
         * Contessa blocks Assassin's special coup
         * Captain and Ambassador block Captain's steal
         * Duke blocks foreign_aid
         * Assassin can't block!
         * 
         * @param other 
         */
        virtual void block(Player& other) =0;

        virtual std::string role() const =0; // return role of subclass (subclass name)
        int coins() const {return _coins;}

        /**
         * @brief steal n coin, or less if not possible
         * 
         * @param n 
         * @return int 
         */
        int steal_coins(int n);

        /**
         * @brief update status parameter 
         * 
         */
        void set_status(Status st);

        void add_coins(int n){_coins += n;}

        //set last action to IN_GAME to avoid block when turn starts
        void get_turn(){_last_action.action = Action::IN_TURN;}

        //output operator 
        friend std::ostream& operator<< (std::ostream& output, const Player& p);
    };
} // namespace coup
