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
    if (obj1.get_id() != obj2.get_id())
        if (obj1.get_id() > obj2.get_id())
            return 1;
        else
            return -1;
    else
        return 0;
}

// This will throw an error when used with classes that can't be directly printed
template<typename type>
void print_tv(TVector<type>& tv)
{
    cout << "----------" << endl;
    for (size_t _i = 0; _i < tv.size(); _i++)
    {
        cout << tv[_i] << endl;
    }
    cout << "----------" << endl;
}

int main()
{
    TVector<long> tvl;

    tvl.reserve(4);

    tvl.push(16l);
    tvl.push(23l);
    tvl.push(5l);
    tvl.push(46l);
    tvl.push(12l);

    tvl.insert(32l, 0);
    tvl.insert(12l, 4);

    print_tv(tvl);

    cout << "----------" << endl;
    cout << tvl.find(23l) << endl;
    cout << tvl.find(13l) << endl;
    cout << tvl.find(14l) << endl;
    cout << tvl.find(25l) << endl;
    cout << "----------" << endl;

    tvl.sort();

    print_tv(tvl);

    cout << "----------" << endl;
    cout << tvl.find(23l) << endl;
    cout << tvl.find(13l) << endl;
    cout << tvl.find(7l) << endl;
    cout << tvl.find(14l) << endl;
    cout << tvl.find(25l) << endl;
    cout << "----------" << endl;

    print_tv(tvl);

    tvl.emplace(69l);
    print_tv(tvl);
    tvl.emplace(37l);
    print_tv(tvl);
    tvl.emplace(2l);
    print_tv(tvl);
    tvl.emplace(104l);
    print_tv(tvl);

    tvl.emplace(3734l);
    tvl.emplace(22l);
    tvl.emplace(1l);
    tvl.emplace(753l);
    print_tv(tvl);

    tvl.emplace(85l);
    tvl.emplace(667l);
    tvl.emplace(854l);

    print_tv(tvl);

    cout << "size: " << tvl.size() << " hello there" << endl;
}
