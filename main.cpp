#include <iostream>
#include <map>
#include <set>
#include <iterator>

class Table {
protected:
    std::map<std::string, int> table;
    std::set<int> marks;
public:
    Table() {};
    void insert(std::string name, int score) {
        table[name] = score;
        marks.insert(score);
    }
    void list_students() {
        std::cout << std::endl << "LIST OF STUDENTS:" << std::endl;
        std::for_each(std::begin(table), std::end(table), [](auto x){std::cout << x.first << ":\t" << x.second << std::endl;});
        std::cout << std::endl;
    }
    void find(std::string name) {
        auto x = std::find_if(std::begin(table), std::end(table), [&name](auto x){return x.first == name;});
        try{
            if(x != table.end()) {
                std::cout << "Mark of " << name << " is " << x->second << std::endl;
            } else {
                throw std::invalid_argument("This student is not found");
            }
        } catch(std::exception& ex) {
            std::cout << ex.what() << std::endl;
        }
    }
    unsigned int range(int x) {
        unsigned int res = 0;
        std::for_each(std::begin(table), std::end(table), [&res, &x](auto u){
            if(u.second == x) {
                res++;
            }
        });
        return res;
    }
    void standings() {
        std::cout << std::endl << "STANDINGS:" << std::endl;
        for(auto it = std::rbegin(marks); it != std::rend(marks); it++) {
            std::for_each(std::begin(table), std::end(table), [&it](auto x){
                if(x.second == *it) {
                    std::cout << x.first << ":\t" << x.second << std::endl;
                }
            });
        }
        std::cout << std::endl;
    }
};

int main() {
    Table a;
    a.insert("Nalitch Peter Andreevich", 100);
    a.insert("Bond Ira Sergeevna", 72);
    a.insert("Bondareva Arina Semenovna", 72);
    a.insert("Zaribin Mihail Petrovich", 81);
    a.insert("Malich Artem Evgenyevich", 95);
    a.list_students();
    a.find("Malich Artem Evgenyevich");
    a.find("Lee Amy Lynn");
    a.insert("Malich Artem Evgenyevich", 98);
    std::cout << a.range(72) << std::endl;
    std::cout << a.range(99) << std::endl;
    a.standings();
    return 0;
}
