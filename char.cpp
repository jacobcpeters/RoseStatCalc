#include "classes.h"

const int Stats::spTotal = 23460;

RoseChar::RoseChar()
{
    weapon = ONE_HAND;

    stats.str = stats.dex = stats.intel = stats.con = 15;
    stats.sen = 10;
    stats.hp = stats.mp = 0;
    stats.spUsed = 0;
    stats.spLeft = stats.spTotal;
}

void RoseChar::calc()
{
    switch(weapon)
    {
        case ONE_HAND:
        case TWO_HAND:
            stats.ap = floorf(((float)stats.str*0.65f) + ((float)stats.dex*0.25f) + ((float)stats.sen*0.1f));
            break;
        case CROSS:
            stats.ap = floorf(((float)stats.str*0.5f) + ((float)stats.dex*0.4f) + ((float)stats.sen*0.1f));
            break;
        case BOW:
            stats.ap = floorf(((float)stats.dex*0.6f) + ((float)stats.con*0.3f) + ((float)stats.sen*0.1f));
            break;
        case KATAR:
            stats.ap = floorf(((float)stats.str*0.35f) + ((float)stats.dex*0.55f) + ((float)stats.sen*0.1f));
            break;
        case DUAL:
            stats.ap = floorf(((float)stats.str*0.55f) + ((float)stats.dex*0.35f) + ((float)stats.sen*0.1f));
            break;
        case GUN:
            stats.ap = floorf(((float)stats.con*0.5f) + ((float)stats.dex*0.4f) + ((float)stats.sen*0.1f));
            break;
        case LAUNCHER:
            stats.ap = floorf(((float)stats.str*0.35f) + ((float)stats.con*0.55f) + ((float)stats.sen*0.1f));
            break;
        case WAND:
            stats.ap = floorf(((float)stats.intel*0.55f) + ((float)stats.dex*0.35f) + ((float)stats.sen*0.1f));
            break;
        case STAFF:
            stats.ap = floorf(((float)stats.str*0.3f) + ((float)stats.intel*0.6f) + ((float)stats.sen*0.1f));
            break;
        default:
            break;
    }

    stats.hp = stats.str * 2;
    stats.mp = stats.intel * 4;

    stats.def = floorf((float)stats.str*0.35f);
    stats.mdef = floorf((float)stats.intel*0.6f);
    stats.acc = floorf((float)stats.con*1.25f);
    stats.crit = floorf(((float)stats.con*0.2f) + (float)stats.sen);
    stats.dodge = floorf((float)stats.dex*1.25f);

    stats.spUsed = 0;
    for(float i = 16; i <= stats.str; i++)
    {
        stats.spUsed += (UINT)floorf((i-1)*0.2f);
    }
    for(float i = 16; i <= stats.dex; i++)
    {
        stats.spUsed += (UINT)floorf((i-1)*0.2f);
    }
    for(float i = 16; i <= stats.intel; i++)
    {
        stats.spUsed += (UINT)floorf((i-1)*0.2f);
    }
    for(float i = 16; i <= stats.con; i++)
    {
        stats.spUsed += (UINT)floorf((i-1)*0.2f);
    }
    for(float i = 11; i <= stats.sen; i++)
    {
        stats.spUsed += (UINT)floorf((i-1)*0.2f);
    }

    stats.spLeft = stats.spTotal - stats.spUsed;
}



