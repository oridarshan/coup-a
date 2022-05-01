#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    std::unordered_map<std::string, std::string> u;
    std::pair<int, int> p;
    std::vector<char> v (100, '_');
    u["first"] = "hello";
    u["second"] = "world";
    class A
    {
    private:
        std::unordered_map<std::string, std::vector<char>> paper;
    };

    class Notebook{
        private:
            std::unordered_map<std::string, std::vector<char>> paper;

        public:
            string show(int page);
    };
    Notebook instance_a;
    A instance_b;   
    std::unordered_map<std::string, std::vector<char>> paper;
    // std::unordered_map<std::pair<int, int>, std::vector<char>> paper2;

    paper["second"] = v;
    cout << u["first"] << u["second"] << endl;
    v[2] = 'k';
    cout  << paper["second"].at(2) << endl;
    cout  << std::string (5,'_') << endl;
    return 0;
}