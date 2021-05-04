#include <iostream>
#include <map>

int main()
{
    using namespace std;
    using tasks_t = map<int, bool(*)(int, int)>;
    tasks_t tasks = {
        {1,  [](int x, int y) -> bool { return (x < y); }                                                      },
        {2,  [](int x, int y) -> bool { return (x == y); }                                                     },
        {3,  [](int x, int y) -> bool { return y == (24 - x); }                                                },
        {4,  [](int x, int y) -> bool { return (x + y < 30); }                                                 },
        {6,  [](int x, int y) -> bool { return !(x > 9 && y > 9); }                                            },
        {7,  [](int x, int y) -> bool { return (y > 15 && x > 15); }                                           },
        {8,  [](int x, int y) -> bool { return (x == 0 || y ==0); }                                            },
        {9,  [](int x, int y) -> bool { return (y - x > 10) || (x - y > 10); }                                 },
        {11, [](int x, int y) -> bool { return (x == 1 || y == 1 || x == 23 || y == 23); }                     },
        {13, [](int x, int y) -> bool { return (x + y > 19) && (x + y < 29); }                                 },
        {14, [](int x, int y) -> bool { return (x * y <= 100); }                                               },
        {15, [](int x, int y) -> bool { return (y - x <= 20) && (y - x > 9) || (x - y <= 20) && (x - y > 9); } },
        {16, [](int x, int y) -> bool { return (x + y > 14) && (x + y < 34) && (x - y <= 9) && (y - x <= 9); } },
        {18, [](int x, int y) -> bool { return (x < 2 || y < 2) && (x != 0 || y != 0); }                       },
        {19, [](int x, int y) -> bool { return (x == 0 || y == 0 || x == 24 || y == 24); }                     },
        {20, [](int x, int y) -> bool { return (x % 2 == y % 2); }                                             },
        {24, [](int x, int y) -> bool { return (x == y || x + y == 24); }                                      }
    };

    for (tasks_t::iterator it = tasks.begin(); it != tasks.end(); ++it)
    {
        cout<<"Task "<<it->first<<endl;
        for (int x = 0; x < 25; x++)
        {
            for (int y = 0; y < 25; y++)
            {
                it->second(x, y) ? cout<<"# " : cout<<". ";
            }
            cout<<endl;
        }
    }

    return 0;
}
