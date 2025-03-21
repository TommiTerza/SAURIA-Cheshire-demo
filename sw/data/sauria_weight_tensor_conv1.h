#include <stdint.h>

#ifndef WEIGHT_TENSOR_H
#define WEIGHT_TENSOR_H

// weight_tensor tensor, stored as 8-bit values
int8_t weight_tensor[16][3][3][3] __attribute__ ((aligned (4))) = 
{
    {
        {
           { -61, -42, 41 },
           { -69, 98, 50 },
           { 14, -37, -94 }
        },
        {
           { -22, 19, 118 },
           { -124, -89, 46 },
           { -108, -115, -86 }
        },
        {
           { 66, -103, -115 },
           { 17, -111, 49 },
           { 57, 32, 104 }
        }
    },
    {
        {
           { -59, 66, -33 },
           { -102, -56, -23 },
           { 56, 89, 75 }
        },
        {
           { 24, -61, -69 },
           { -97, -2, 103 },
           { -23, -97, 114 }
        },
        {
           { -32, -60, 43 },
           { 37, -106, -10 },
           { 60, 94, -104 }
        }
    },
    {
        {
           { 91, 40, 3 },
           { -33, -117, -15 },
           { -51, -57, 44 }
        },
        {
           { 70, -10, 77 },
           { -41, -112, 111 },
           { -61, -68, 52 }
        },
        {
           { 110, 44, 118 },
           { 41, 39, 94 },
           { -55, 51, 9 }
        }
    },
    {
        {
           { 101, -94, 93 },
           { -127, -40, 118 },
           { 78, -14, -32 }
        },
        {
           { 78, 44, -47 },
           { -83, -42, -117 },
           { -70, 121, -53 }
        },
        {
           { 7, 72, 93 },
           { 90, 117, -115 },
           { 65, 39, 109 }
        }
    },
    {
        {
           { -101, 118, -36 },
           { -47, 11, 95 },
           { -110, 61, 59 }
        },
        {
           { -95, -108, -106 },
           { -62, -3, -57 },
           { 3, 83, 72 }
        },
        {
           { 67, -34, -33 },
           { 76, 77, 71 },
           { 33, -70, -104 }
        }
    },
    {
        {
           { -6, -55, 8 },
           { 77, 120, 115 },
           { 85, -37, -115 }
        },
        {
           { -54, 26, 65 },
           { 25, -100, 101 },
           { -59, 26, -79 }
        },
        {
           { -65, -33, -31 },
           { -20, -1, -74 },
           { 0, 46, 15 }
        }
    },
    {
        {
           { -4, -13, 115 },
           { -103, 62, -45 },
           { 6, -75, -2 }
        },
        {
           { 107, 15, 49 },
           { -118, 114, -89 },
           { -90, -102, 3 }
        },
        {
           { 55, 94, -95 },
           { -84, 16, 15 },
           { -88, -16, -14 }
        }
    },
    {
        {
           { 108, 24, 105 },
           { 3, 94, 13 },
           { 74, -77, -122 }
        },
        {
           { 125, -11, 0 },
           { 125, 110, -24 },
           { 59, 54, 67 }
        },
        {
           { 21, 22, -50 },
           { -12, -52, -80 },
           { -18, 39, 92 }
        }
    },
    {
        {
           { -49, 11, 30 },
           { 58, -75, 7 },
           { 87, 63, 93 }
        },
        {
           { -82, 76, 88 },
           { -92, -34, -14 },
           { -41, 45, -63 }
        },
        {
           { 87, 66, -64 },
           { 119, 96, -14 },
           { 4, -42, -88 }
        }
    },
    {
        {
           { 40, 32, 78 },
           { 72, 26, -18 },
           { 61, -38, -36 }
        },
        {
           { -86, 106, 37 },
           { -44, -30, -45 },
           { -68, -23, 4 }
        },
        {
           { 36, 27, 97 },
           { 19, 127, -4 },
           { -99, -52, 20 }
        }
    },
    {
        {
           { -20, 82, -19 },
           { 3, -65, -36 },
           { 101, -89, 70 }
        },
        {
           { -26, -56, 40 },
           { -1, -46, -102 },
           { 58, 67, 70 }
        },
        {
           { 110, 22, 60 },
           { 62, -107, 28 },
           { 73, -125, -11 }
        }
    },
    {
        {
           { -18, -127, 71 },
           { 108, -89, 59 },
           { -90, -71, 2 }
        },
        {
           { -91, 4, 72 },
           { -14, -120, -22 },
           { -122, 111, -30 }
        },
        {
           { -100, 111, -84 },
           { 28, 54, -26 },
           { 77, 53, 84 }
        }
    },
    {
        {
           { 5, -113, 26 },
           { -97, 89, 111 },
           { -66, -49, 91 }
        },
        {
           { 89, 57, -43 },
           { -15, -103, -51 },
           { -78, -44, -76 }
        },
        {
           { 11, 60, -62 },
           { 86, 72, -17 },
           { -46, -102, 97 }
        }
    },
    {
        {
           { 71, -120, -74 },
           { 10, 43, 113 },
           { 33, -50, 102 }
        },
        {
           { 112, 39, -115 },
           { 64, 16, -119 },
           { 121, -21, 78 }
        },
        {
           { -102, 75, 45 },
           { 91, -95, -84 },
           { -8, -18, -15 }
        }
    },
    {
        {
           { 112, 45, 88 },
           { -68, -107, -112 },
           { -103, -111, -113 }
        },
        {
           { 116, -73, -18 },
           { 39, -110, -91 },
           { -121, -48, -44 }
        },
        {
           { -120, 79, -50 },
           { 98, -89, -5 },
           { -83, 2, -64 }
        }
    },
    {
        {
           { 104, -90, -9 },
           { -113, 3, -16 },
           { 5, -55, -58 }
        },
        {
           { 112, -114, 125 },
           { -102, 115, -15 },
           { 14, -9, -28 }
        },
        {
           { 77, -22, -68 },
           { -115, 35, -32 },
           { -23, -105, -102 }
        }
    }
};

#endif // WEIGHT_TENSOR_H
