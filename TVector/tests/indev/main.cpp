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
    long n1 = 16;
    long n2 = 23;
    long n3 = 5;
    long n4 = 46;
    long n5 = 12;
    
    TVector<long> tvl;

    tvl.reserve(5);

    tvl.push(n1);
    tvl.push(n2);
    tvl.push(n3);
    tvl.push(n4);
    tvl.push(n5);

    int loc11 = tvl.find(23);
    int loc12 = tvl.find(13);
    int loc21 = tvl.find(14);
    int loc22 = tvl.find(25);

    tvl.sort();

    int loc111 = tvl.find(23, true);
    int loc122 = tvl.find(13, true);
    int loc211 = tvl.find(14, true);
    int loc221 = tvl.find(25, true);

    for (int _i = 0; _i < tvl.size(); _i++)
    {
        cout << tvl[_i] << endl; 
    }
    cout << "-----" << endl;

    tvl.emplace(37, true);
    tvl.emplace(69, true);
    tvl.emplace(2, true);

    for (int _i = 0; _i < tvl.size(); _i++)
    {
        cout << tvl[_i] << endl; 
    }

    cout << "size: " << tvl.size() << endl;
}
