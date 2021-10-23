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

explspec short TVector<obj>::compare(const obj& obj1, const obj& obj2) const
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

    tvl.push(16L);
    tvl.push(23L);
    tvl.push(5L);
    tvl.push(46L);
    tvl.push(12L);

    tvl.insert(32L, 0);
    tvl.insert(12L, 4);

    for (size_t _i = 0; _i < tvl.size(); _i++)
    {
        cout << tvl[_i] << endl; 
    }
    cout << "-----" << endl;

    cout << tvl.find(23L) << endl;
    cout << tvl.find(13L) << endl;
    cout << tvl.find(14L) << endl;
    cout << tvl.find(25L) << endl;

    tvl.sort();

    cout << tvl.find(23L) << endl;
    cout << tvl.find(13L) << endl;
    cout << tvl.find(14L) << endl;
    cout << tvl.find(25L) << endl;

    cout << tvl.find(37L) << endl;

    for (size_t _i = 0; _i < tvl.size(); _i++)
    {
        cout << tvl[_i] << endl; 
    }
    cout << "-----" << endl;

    tvl.emplace(69L);
    tvl.emplace(37L);
    tvl.emplace(2L);
    tvl.emplace(104L);
    tvl.emplace(3734L);
    tvl.emplace(22L);
    tvl.emplace(1L);
    tvl.emplace(753L);
    tvl.emplace(85L);
    tvl.emplace(667L);
    tvl.emplace(854L);

    for (size_t _i = 0; _i < tvl.size(); _i++)
    {
        cout << tvl[_i] << endl; 
    }

    cout << "size: " << tvl.size() << " hello there" << endl;
}
