#include <libninja/level.hpp>

void level(
        int lvl, int* starttime, float* penalty, float* bonus, int* bonusseries)
{
    switch (lvl) {
    case 0:
        (*starttime) = 180;
        (*penalty) = 1;
        (*bonusseries) = 20;
        (*bonus) = 1.5;
        break;
    case 1:
        (*starttime) = 180;
        (*penalty) = 2;
        (*bonusseries) = 30;
        (*bonus) = 1;
        break;
    case 2:
        (*starttime) = 120;
        (*penalty) = 3.5;
        (*bonusseries) = 40;
        (*bonus) = 1;
        break;
    }
}
