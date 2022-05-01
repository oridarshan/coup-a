#pragma once
#include <string>
#include <vector>
namespace coup
{
    class Game
    {
    private:
        std::vector<std::string> _players;
    public:
        Game(){}
        std::string turn(){return "";}
        std::string winner(){return "";}
        std::vector<std::string> players(){
            std::vector<std::string> p{"","","","","",""};
            return p;
        }
        
    };
}