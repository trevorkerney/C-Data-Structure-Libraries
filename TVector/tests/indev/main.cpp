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

template<>
inline int TVector<obj>::compare(const obj& p_obj1, const obj& p_obj2) const
{
    int comparison = p_obj1.get_id() - p_obj2.get_id();
    
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
    obj obj1(3);
    obj obj2(5);
    obj obj3(8);
    obj obj4(11);
    obj obj5(17);

    obj objs[5];
    int nums[5];

    TVector<obj> tvs;

    tvs.reserve(5);

    tvs.push(obj3);
    tvs.push(obj4);
    tvs.push(obj2);
    tvs.push(obj1);

    tvs.insert(obj5, 0);

    tvs.sort();

    for (int _i = 0; _i < tvs.size(); _i++)
    {
        cout << tvs[_i].get_id() << endl;
    }

    cout << "size: " << tvs.size() << endl;
}
