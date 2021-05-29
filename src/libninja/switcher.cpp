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
        A[4] = 20 * (width/(float)1050);
        A[5] = 182 * (height/(float)660);
        A[6] = 296 * (width/(float)1050);
        A[7] = 80 * (height/(float)660);
        // third button
        A[8] = 20 * (width/(float)1050);
        A[9] = 310 * (height/(float)660);
        A[10] = 260 * (width/(float)1050);
        A[11] = 90 * (height/(float)660);
        break;
    case 2:
        // first button
        A[0] = 382 * (width/(float)1050);
        A[1] = 109 * (height/(float)660);;
        A[2] = 257 * (width/(float)1050);
        A[3] = 87 * (height/(float)660);;
        // second button
        A[4] = 278 * (width/(float)1050);
        A[5] = 242 * (height/(float)660);;
        A[6] = 435 * (width/(float)1050);
        A[7] = 85 * (height/(float)660);;
        // third button
        A[8] = 350 * (width/(float)1050);
        A[9] = 380 * (height/(float)660);;
        A[10] = 323 * (width/(float)1050);
        A[11] = 85 * (height/(float)660);;
        break;

    case 5:
        // first button
        A[0] = 365 * (width / (float)1050);
        A[1] = 139 * (height / (float)660);
        ;
        A[2] = 310 * (width / (float)1050);
        A[3] = 67 * (height / (float)660);
        ;
        // second button
        A[4] = 144 * (width / (float)1050);
        A[5] = 309 * (height / (float)660);
        ;
        A[6] = 752 * (width / (float)1050);
        A[7] = 64 * (height / (float)660);
        ;
        // third button
        A[8] = 0;
        A[9] = 0;
        ;
        A[10] = 0;
        A[11] = 0;
        ;
        break;

    default:
        for (int i = 0; i < 12; i++)
            A[i] = 0;
        break;
    }
}
