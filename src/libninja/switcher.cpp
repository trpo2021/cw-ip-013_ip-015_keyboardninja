#include <libninja/switcher.hpp>

void switcher(int menuNum, int* A, int N, int height, int width)
{
    switch (menuNum) {
    case 1:
        // first button
        A[0] = 20 * (width/(float)1050);
        A[1] = 55 * (height/(float)660);
        A[2] = 560 * (width/(float)1050);
        A[3] = 80 * (height/(float)660);
        // second button
        A[4] = 20;
        A[5] = 182;
        A[6] = 296;
        A[7] = 80;
        // third button
        A[8] = 20;
        A[9] = 310;
        A[10] = 260;
        A[11] = 90;
        break;
    case 2:
        // first button
        A[0] = 382;
        A[1] = 109;
        A[2] = 257;
        A[3] = 87;
        // second button
        A[4] = 278;
        A[5] = 242;
        A[6] = 435;
        A[7] = 85;
        // third button
        A[8] = 350;
        A[9] = 380;
        A[10] = 323;
        A[11] = 85;
        break;

    default:
        for (int i = 0; i < 12; i++)
            A[i] = 0;
        break;
    }
}
