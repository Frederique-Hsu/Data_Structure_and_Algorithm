#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>

using namespace std;

struct Temp
{
    unsigned int index;
    int temp;
};

bool lessThan(std::vector<Temp>::iterator a, std::vector<Temp>::iterator b)
{
    if (a->temp <= b->temp)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int compute_closest_to_zero(vector<int> ts)
{
    // Write your code here
    // To debug: cerr << "Debug messages..." << endl;

    if (ts.size() == 0)
    {
        return 0;
    }

    vector<Temp> positive_temps, negative_temps;
    for (auto index = 0U; index < ts.size(); ++index)
    {
        if (ts[index] >= 0)
        {
            positive_temps.push_back(Temp{index, ts[index]});
        }
        else
        {
            negative_temps.push_back(Temp{index, std::abs(ts[index])});
        }
    }

    std::sort(positive_temps.begin(), positive_temps.end(), [](Temp a, Temp b) {
        if (a.temp <= b.temp)
        {
            return true;
        }
        else
        {
            return false;
        }
    });
    std::sort(negative_temps.begin(), negative_temps.end(), [](Temp a, Temp b) {
        if (a.temp <= b.temp)
        {
            return true;
        }
        else
        {
            return false;
        }
    });

    if (positive_temps[0].temp <= negative_temps[0].temp)    
    {
        return positive_temps[0].index;
    }
    else
    {
        return negative_temps[0].index;
    }
    return -1;
}

/* Ignore and do not change the code below */
#if 0
int main()
{
    int n;
    cin >> n; cin.ignore();
    vector<int> ts;
    for (int i = 0; i < n; i++) {
        int ts_tmp;
        cin >> ts_tmp;
        ts.push_back(ts_tmp);
    }
    int std_out_fd = dup(1);
    dup2(2, 1);
    int solution = compute_closest_to_zero(ts);
    dup2(std_out_fd, 1);
    cout << solution << endl;
}
#endif
/* Ignore and do not change the code above */