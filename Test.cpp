/**
 *
 * AUTHORS: Ori Darshan
 *
 * Date: 2021-05
 */

#include "doctest.h"

#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"


#include <exception>

using namespace coup;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

TEST_CASE("Demo full game"){

	Game game_1{};

	Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};

	vector<string> players = game_1.players();
    CHECK(players[0] == "Moshe");
    CHECK(players[1] == "Yossi");
    CHECK(players[2] == "Meirav");
    CHECK(players[3] == "Reut");
    CHECK(players[4] == "Gilad");

    CHECK(game_1.turn() == "Moshe");
	// prints Moshe

	// throws no exceptions
	CHECK_NOTHROW(duke.income(););
	CHECK_NOTHROW(assassin.income(););
	CHECK_NOTHROW(ambassador.income(););
	CHECK_NOTHROW(captain.income(););
	CHECK_NOTHROW(contessa.income(););

	// throws exception, it is duke's turn now
	CHECK_THROWS(assassin.income(););

	duke.income();
	assassin.foreign_aid();

	// throws exception, the last operation duke performed
	// is income, which cannot be blocked by any role
	CHECK_THROWS(captain.block(duke););
	
	//forien aid gave 2 coins
    CHECK(duke.coins() == 2);
    CHECK(assassin.coins() == 3);

	// throws exception, the last operation assassin performed
	// is foreign aid, which cannot be blocked by contessa
	CHECK_THROWS(contessa.block(assassin););

	duke.block(assassin);
	//coins subtracted after block
    CHECK(assassin.coins() == 1);

	CHECK_NOTHROW(ambassador.transfer(duke, assassin);); //transfers 1 coin from duke to assassin
	captain.foreign_aid();
	contessa.foreign_aid();
	
	// test different actions
	CHECK_NOTHROW(duke.tax(););
	CHECK_NOTHROW(assassin.income(););
	CHECK_NOTHROW(ambassador.foreign_aid(););
	CHECK_NOTHROW(captain.steal(contessa););
	CHECK_NOTHROW(contessa.foreign_aid(););

	duke.tax();
	// no exception, assassin can coup with only 3 coins
	CHECK_NOTHROW(assassin.coup(duke););

	players = game_1.players();
    CHECK(players[0] == "Yossi");
    CHECK(players[1] == "Meirav");
    CHECK(players[2] == "Reut");
    CHECK(players[3] == "Gilad");

	// revive from special coup
	contessa.block(assassin);

	players = game_1.players();
    CHECK(players[0] == "Moshe");
    CHECK(players[1] == "Yossi");
    CHECK(players[2] == "Meirav");
    CHECK(players[3] == "Reut");
    CHECK(players[4] == "Gilad");
	
}

TEST_CASE("10 coins and special coup"){
	Game game_2{};
	Duke duke{game_2, "Duke"};
	Assassin assassin{game_2, "Assassin"};
	Assassin assassin2{game_2, "Assassin2"};
	Ambassador ambassador{game_2, "Ambassador"};
	Contessa contessa{game_2, "Contessa"};
	vector<Player*> players1;
	players1.push_back(&duke);
	players1.push_back(&assassin);
	players1.push_back(&assassin2);
	players1.push_back(&ambassador);
	players1.push_back(&contessa);
	for (size_t i = 0; i < 6; i++)
	{
		for (Player* player : players1){
			player->income();
		}
	}
	duke.income();
	assassin.income();
	
	// special coup
	assassin2.coup(duke);
	// can block special coup without turn
	CHECK_NOTHROW(contessa.block(assassin2););
	for (size_t i = 0; i < 2; i++)
	{
		ambassador.income();
		contessa.income();
		duke.income();
		assassin.income();
		assassin2.income();
	}
	ambassador.income();
	contessa.income();
	duke.income();
	// regular coup
	assassin.coup(duke);
	//can't block regular coup
	CHECK_THROWS(contessa.block(assassin););
	assassin2.income();
	ambassador.income();
	contessa.income();
	assassin.income();
	assassin2.income();
	// can coup with 10 coins
	CHECK_NOTHROW(ambassador.coup(assassin););
	//can't play your turn without couping
	CHECK_THROWS(contessa.income(););
	
}
TEST_CASE("killing dead players and skipping dead players turns"){
	Game game_3{};
	Duke duke{game_3, "Duke"};
	Assassin assassin{game_3, "Assassin"};
	Assassin assassin2{game_3, "Assassin2"};
	Ambassador ambassador{game_3, "Ambassador"};
	Ambassador ambassador2{game_3, "Ambassador2"};
	Contessa contessa{game_3, "Contessa"};
	for (size_t i = 0; i < 8; i++)
	{
		duke.income();
		assassin.income();
		assassin2.income();
		ambassador.income();
		ambassador2.income();
		contessa.income();
	}
	duke.coup(assassin);
	// not assassin turn (dead)
	CHECK_NOTHROW(assassin2.income(););
	//killing dead player
	CHECK_THROWS(ambassador.coup(assassin););
}

TEST_CASE("transfer 0 coins, steal 1"){
	Game game_2{};
	Ambassador ambassador{game_2, "Ambassador"};
	Captain captain{game_2, "Captain"};
	Assassin assassin{game_2, "Assassin"};
	Assassin assassin2{game_2, "Assassin2"};
	Contessa contessa{game_2, "Contessa"};

	// can't transfer 0 coins
	CHECK_THROWS(ambassador.transfer(captain, assassin););
	ambassador.income();
	// can steal only 1 coin
	CHECK_NOTHROW(captain.steal(ambassador););
}