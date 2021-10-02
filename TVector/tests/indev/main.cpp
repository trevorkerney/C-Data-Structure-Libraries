#include "../../inc/TVector.h"

#include <iostream>
using std::cout;
using std::endl;

class obj
{
private:
    int id;
public:
    obj() {}
    obj(int p_id)
    {
        id = p_id;
    }

    int get_id() const
    {
        return id;
    }
};

explspec inline int TVector<obj>::compare(const obj& obj1, const obj& obj2) const
{
    int comparison = obj1.get_id() - obj2.get_id();
    
    if (comparison != 0)
        if (comparison > 0)
            return 1;
        else
            return -1;
    else
        return 0;
}

int main()
{
    TVector<long> tvl;

    tvl.reserve(5);

    tvl.push(16);
    tvl.push(23);
    tvl.push(5);
    tvl.push(46);
    tvl.push(12);

    tvl.insert(32, 0);
    tvl.insert(12, 4);

    for (int _i = 0; _i < tvl.size(); _i++)
    {
        cout << tvl[_i] << endl; 
    }
    cout << "-----" << endl;

    int loc11 = tvl.find(23);
    int loc12 = tvl.find(13);
    int loc21 = tvl.find(14);
    int loc22 = tvl.find(25);

    tvl.sort();

    int loc111 = tvl.find(23);
    int loc122 = tvl.find(13);
    int loc211 = tvl.find(14);
    int loc221 = tvl.find(25);

    int location = tvl.find(37);

    for (int _i = 0; _i < tvl.size(); _i++)
    {
        cout << tvl[_i] << endl; 
    }
    cout << "-----" << endl;

    tvl.emplace(69);
    tvl.emplace(37);
    tvl.emplace(2);
    tvl.emplace(104);
    tvl.emplace(3734);
    tvl.emplace(22);
    tvl.emplace(1);
    tvl.emplace(753);
    tvl.emplace(85);
    tvl.emplace(667);
    tvl.emplace(854);

    for (int _i = 0; _i < tvl.size(); _i++)
    {
        cout << tvl[_i] << endl; 
    }

    cout << "size: " << tvl.size() << endl;
}
