#include <iostream>
#include <map>
#include <iterator>

class Table {
protected:
    std::map<std::string, int> table;
    std::multimap<int, std::string> marks;
public:
    Table() {};
    void insert(std::string name, int score) {
        table[name] = score;
        marks.insert(std::pair<int, std::string>(score, name));
    }
    void list_students() {
        std::cout << std::endl << "LIST OF STUDENTS:" << std::endl;
        std::for_each(std::begin(table), std::end(table), [](auto x){std::cout << x.first << ":\t" << x.second << std::endl;});
        std::cout << std::endl;
    }
    void find(std::string name) {
        try{
            auto x = table.at(name);
            std::cout << "The score of " << name << " is " << x << std::endl;
        } catch(std::exception& ex) {
            std::cout << "This student is not found" << std::endl;
        }
    }
    void range(int x) {
        std::cout << std::endl << "Students with " << x << " points:" << std::endl;
        unsigned int res = 0;
        std::for_each(std::begin(table), std::end(table), [&res, &x](auto u){
            if(u.second == x) {
                std::cout << u.first << std::endl;
                res++;
            }
        });
        std::cout << "(" << res << " students)" << std::endl;
    }
    void standings() {
        std::cout << std::endl << "STANDINGS:" << std::endl;
        for(auto it = std::rbegin(marks); it != std::rend(marks); it++) {
            std::cout << it->second << ":\t" << it->first << std::endl;
        }
        std::cout << std::endl;
    }
};

int main() {
    Table a;
    a.insert("Nalitch Peter Andreevich", 100);
    a.insert("Bond Ira Sergeevna", 72);
    a.insert("Bondareva Arina Semenovna", 72);
    a.insert("Zarubin Mihail Petrovich", 81);
    a.insert("Malich Artem Evgenyevich", 95);
    a.list_students();
    a.find("Malich Artem Evgenyevich");
    a.find("Lee Amy Lynn");
    a.insert("Malich Artem Evgenyevich", 98);
    a.range(72);
    a.range(99);
    a.standings();
    return 0;
}
