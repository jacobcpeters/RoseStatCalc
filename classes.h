#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include <math.h>

typedef unsigned int uint;

enum weapon_t {
    ONE_HAND    = 0,
    TWO_HAND    = 1,
    CROSS       = 2,
    BOW         = 3,
    KATAR       = 4,
    DUAL        = 5,
    GUN         = 6,
    LAUNCHER    = 7,
    WAND        = 8,
    STAFF       = 9
};

struct Stats
{
    uint str;
    uint dex;
    uint intel;
    uint con;
    uint sen;

    uint hp;
    uint mp;

    float ap;
    float def;
    float mdef;
    float acc;
    float crit;
    float dodge;

    uint spUsed;
    int spLeft;
    static const int spTotal;
};

class RoseChar
{
    public:

    weapon_t weapon;
    Stats stats;

    RoseChar();
    void calc();
};

#endif // CLASSES_H_INCLUDED
