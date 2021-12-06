#ifndef __FISH_H__
#define __FISH_H_

class Fish
{
friend class Shoaling;
public:
    Fish(int n = 8) : timer{n} {}

    // void operator--() {--timer;}

    /// Changes timer as if one day passed
    /// @return True if new fish should be born, false otherwise
    bool pass()
    {
        bool ret = false;

        if (timer == new_fish)
        {
            timer = def_timer;
            ret = true;
        }

        --timer;
        
        return ret;
    }

private:
    enum d{new_fish, def_timer = 7};
    int timer;
};

#endif