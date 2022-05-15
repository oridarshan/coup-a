#pragma once

namespace coup
{
    class Player;

    enum Action{INCOME, FOREIGN_AID, COUP, TRANSFER, TAX, STEAL, ASSASSINATE, IN_TURN};

    struct LastAction
    {
        Action action;
        Player* subject;
    };
}
