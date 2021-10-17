#include <iostream>

using namespace std;

class RegNum
{
    static unsigned int id_gen;
    unsigned int id;
    string owners_name;

public:

    RegNum(string name_ = "Unknown")
        : owners_name(name_)
        {
            id = id_gen++;
        }
    const string get_name()
    {
        return owners_name;
    }

    unsigned int get_id() const
    {
        return id;
    }

    friend void print_stuff(RegNum regnum_);
};

unsigned int RegNum::id_gen = 0;

void print_stuff(RegNum regnum_)
{
    cout << "Owner: " << regnum_.get_name() << endl;
    cout << "ID: " << regnum_.get_id() << endl;
}

int main()
{
    RegNum * arr;
    arr = new RegNum[3];
    arr[0] = RegNum("Adam");
    arr[1] = RegNum("Jan");
    arr[2] = RegNum("Maciej");

    for(int i = 0; i <= 2; i++)
    {
        print_stuff(arr[i]);
    }

    delete[] arr;

    return 0;
}
