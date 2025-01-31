#include <stdint.h>

#ifndef INPUT_TENSOR_H
#define INPUT_TENSOR_H

// input_tensor tensor, stored as 8-bit values
int8_t input_tensor[3][34][34] __attribute__ ((aligned (4))) = 
{
    {
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 127, 65, 8, 43, 20, 58, 17, 85, 79, 41, 123, 74, 2, 74, 3, 102, 0, 8, 55, 31, 80, 89, 115, 25, 88, 98, 61, 36, 43, 108, 61, 69, 0 },
       { 0, 1, 17, 76, 120, 94, 94, 113, 5, 23, 68, 43, 48, 54, 72, 32, 45, 103, 36, 97, 1, 124, 88, 41, 109, 79, 31, 21, 28, 75, 33, 76, 58, 0 },
       { 0, 68, 22, 123, 52, 29, 108, 60, 11, 120, 83, 32, 35, 8, 57, 117, 101, 42, 42, 69, 127, 6, 31, 75, 119, 76, 6, 114, 27, 44, 4, 111, 11, 0 },
       { 0, 93, 79, 95, 0, 118, 10, 116, 82, 114, 53, 22, 58, 15, 123, 87, 31, 56, 105, 46, 27, 37, 8, 64, 14, 93, 116, 53, 47, 104, 1, 100, 43, 0 },
       { 0, 103, 103, 84, 24, 123, 33, 82, 68, 22, 87, 86, 90, 93, 90, 6, 78, 96, 88, 109, 51, 20, 74, 72, 37, 55, 88, 43, 105, 25, 60, 124, 5, 0 },
       { 0, 8, 98, 10, 37, 114, 102, 99, 116, 45, 88, 110, 17, 34, 64, 126, 50, 98, 22, 15, 53, 78, 88, 53, 98, 35, 97, 97, 98, 76, 115, 87, 118, 0 },
       { 0, 35, 50, 62, 119, 115, 120, 11, 11, 85, 110, 69, 31, 107, 0, 103, 60, 59, 106, 93, 0, 114, 119, 94, 90, 59, 24, 77, 105, 96, 59, 102, 47, 0 },
       { 0, 27, 39, 96, 55, 88, 74, 65, 123, 126, 77, 73, 112, 7, 59, 48, 60, 66, 104, 108, 71, 0, 98, 53, 90, 96, 27, 119, 97, 119, 52, 30, 105, 0 },
       { 0, 66, 14, 23, 24, 107, 61, 67, 4, 112, 104, 75, 79, 7, 59, 10, 32, 116, 53, 62, 40, 121, 81, 66, 4, 68, 56, 0, 44, 78, 39, 103, 106, 0 },
       { 0, 69, 116, 109, 55, 32, 126, 110, 116, 86, 111, 115, 104, 33, 32, 114, 127, 2, 124, 18, 82, 10, 108, 5, 44, 2, 14, 123, 6, 19, 97, 111, 76, 0 },
       { 0, 36, 98, 13, 9, 96, 88, 43, 42, 72, 113, 119, 35, 119, 25, 73, 112, 108, 81, 81, 89, 28, 14, 111, 28, 98, 2, 11, 126, 54, 50, 93, 79, 0 },
       { 0, 88, 119, 47, 78, 95, 17, 27, 34, 75, 54, 48, 123, 45, 17, 116, 109, 79, 57, 73, 95, 49, 17, 84, 98, 65, 57, 97, 15, 21, 27, 27, 12, 0 },
       { 0, 119, 56, 33, 5, 29, 0, 63, 81, 78, 77, 109, 18, 32, 56, 26, 47, 41, 32, 27, 95, 103, 67, 68, 115, 35, 34, 94, 120, 124, 62, 17, 0, 0 },
       { 0, 34, 18, 125, 104, 60, 0, 57, 43, 107, 28, 41, 1, 49, 106, 59, 21, 33, 3, 37, 90, 53, 102, 88, 56, 117, 47, 98, 48, 120, 45, 121, 122, 0 },
       { 0, 79, 50, 100, 121, 88, 33, 121, 118, 63, 2, 87, 40, 44, 22, 2, 107, 25, 79, 46, 4, 16, 50, 114, 8, 96, 48, 101, 2, 26, 99, 127, 67, 0 },
       { 0, 31, 113, 27, 29, 104, 62, 3, 58, 54, 56, 76, 28, 35, 122, 96, 107, 106, 26, 58, 53, 17, 59, 90, 51, 19, 123, 75, 0, 88, 98, 30, 117, 0 },
       { 0, 36, 0, 59, 57, 41, 18, 27, 116, 26, 34, 97, 96, 34, 8, 109, 47, 110, 65, 88, 83, 68, 6, 50, 126, 33, 50, 26, 11, 38, 66, 24, 36, 0 },
       { 0, 22, 43, 62, 122, 77, 98, 27, 117, 56, 45, 13, 95, 1, 87, 107, 108, 104, 98, 121, 102, 63, 38, 36, 72, 121, 20, 104, 87, 115, 18, 96, 84, 0 },
       { 0, 5, 14, 25, 0, 39, 55, 122, 0, 13, 52, 92, 39, 86, 10, 127, 118, 122, 107, 6, 104, 58, 42, 78, 104, 113, 41, 7, 4, 101, 7, 26, 55, 0 },
       { 0, 54, 76, 54, 37, 111, 99, 42, 68, 90, 80, 126, 96, 65, 10, 126, 100, 30, 56, 99, 91, 66, 10, 113, 35, 31, 3, 97, 45, 43, 46, 109, 6, 0 },
       { 0, 62, 18, 80, 1, 49, 36, 55, 51, 59, 3, 36, 71, 83, 17, 49, 97, 118, 26, 126, 21, 55, 82, 1, 88, 47, 45, 87, 113, 71, 125, 118, 121, 0 },
       { 0, 4, 11, 7, 113, 77, 56, 73, 105, 45, 45, 120, 93, 92, 115, 77, 95, 61, 52, 27, 38, 29, 46, 39, 65, 14, 84, 77, 7, 61, 6, 37, 111, 0 },
       { 0, 34, 103, 98, 33, 68, 72, 109, 12, 33, 66, 86, 118, 119, 20, 0, 59, 102, 5, 75, 119, 83, 64, 101, 49, 107, 105, 32, 125, 118, 64, 78, 59, 0 },
       { 0, 65, 108, 124, 39, 3, 84, 112, 90, 47, 123, 119, 60, 102, 7, 79, 52, 24, 98, 15, 101, 104, 6, 27, 127, 86, 69, 55, 33, 101, 53, 55, 43, 0 },
       { 0, 114, 73, 126, 51, 88, 46, 36, 44, 41, 20, 28, 117, 28, 11, 14, 82, 15, 47, 9, 1, 92, 58, 46, 118, 23, 33, 35, 97, 39, 6, 68, 63, 0 },
       { 0, 127, 49, 40, 125, 25, 95, 68, 72, 38, 64, 106, 42, 46, 55, 64, 110, 32, 7, 54, 51, 20, 106, 4, 54, 113, 42, 92, 54, 29, 69, 103, 78, 0 },
       { 0, 76, 54, 41, 92, 14, 45, 55, 116, 40, 8, 124, 45, 23, 8, 86, 2, 121, 26, 67, 28, 39, 112, 83, 64, 51, 44, 125, 126, 60, 74, 91, 76, 0 },
       { 0, 94, 120, 81, 105, 23, 46, 93, 16, 59, 39, 38, 125, 94, 18, 117, 39, 66, 48, 124, 33, 100, 7, 6, 52, 115, 92, 1, 117, 103, 20, 61, 125, 0 },
       { 0, 20, 119, 111, 52, 0, 69, 118, 112, 117, 79, 48, 49, 115, 100, 108, 93, 67, 74, 56, 122, 40, 58, 80, 25, 77, 126, 14, 113, 19, 61, 39, 89, 0 },
       { 0, 39, 19, 111, 25, 26, 48, 76, 1, 22, 54, 96, 7, 54, 43, 66, 38, 55, 14, 33, 121, 69, 18, 9, 124, 49, 87, 73, 100, 77, 58, 113, 47, 0 },
       { 0, 3, 20, 18, 69, 2, 3, 39, 17, 63, 115, 54, 120, 58, 69, 26, 71, 89, 65, 92, 45, 54, 27, 7, 105, 98, 50, 44, 7, 3, 83, 45, 104, 0 },
       { 0, 119, 34, 24, 12, 92, 45, 37, 100, 100, 98, 23, 7, 45, 70, 91, 80, 55, 126, 126, 86, 31, 56, 61, 96, 36, 36, 73, 69, 64, 85, 91, 92, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    {
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 92, 123, 10, 69, 84, 53, 25, 85, 97, 67, 72, 28, 119, 60, 118, 93, 125, 103, 84, 23, 106, 34, 1, 22, 115, 9, 98, 122, 14, 110, 4, 72, 0 },
       { 0, 68, 89, 74, 10, 125, 127, 28, 18, 59, 2, 93, 56, 24, 57, 80, 15, 111, 123, 35, 15, 78, 10, 68, 72, 85, 23, 123, 15, 106, 92, 119, 63, 0 },
       { 0, 87, 16, 79, 62, 99, 35, 67, 67, 122, 53, 127, 24, 109, 24, 75, 10, 34, 86, 81, 71, 80, 27, 9, 2, 123, 78, 29, 52, 108, 39, 0, 66, 0 },
       { 0, 16, 54, 116, 100, 45, 79, 98, 53, 72, 44, 42, 95, 27, 20, 57, 16, 103, 99, 68, 75, 50, 32, 50, 8, 14, 73, 82, 13, 24, 97, 70, 2, 0 },
       { 0, 126, 0, 58, 70, 33, 122, 100, 83, 44, 50, 122, 76, 74, 118, 66, 44, 78, 52, 109, 119, 79, 78, 109, 124, 24, 116, 116, 12, 79, 39, 123, 40, 0 },
       { 0, 94, 17, 8, 96, 85, 112, 107, 76, 33, 103, 19, 49, 124, 1, 43, 46, 107, 55, 103, 43, 42, 32, 67, 113, 93, 63, 91, 61, 92, 53, 23, 3, 0 },
       { 0, 52, 106, 127, 5, 6, 5, 97, 64, 51, 34, 15, 11, 6, 74, 111, 36, 73, 116, 81, 26, 8, 120, 24, 120, 120, 30, 52, 102, 100, 123, 54, 13, 0 },
       { 0, 62, 120, 17, 15, 124, 49, 96, 58, 67, 65, 115, 109, 82, 77, 24, 65, 19, 56, 105, 77, 111, 25, 40, 100, 2, 32, 45, 71, 67, 34, 1, 76, 0 },
       { 0, 61, 101, 95, 25, 118, 48, 119, 1, 71, 117, 97, 92, 82, 109, 68, 70, 5, 107, 56, 55, 4, 88, 64, 116, 111, 54, 14, 12, 37, 7, 78, 9, 0 },
       { 0, 118, 119, 56, 74, 23, 121, 110, 31, 12, 31, 1, 86, 83, 56, 123, 122, 66, 49, 115, 103, 121, 120, 5, 20, 96, 14, 96, 47, 106, 12, 106, 116, 0 },
       { 0, 16, 108, 83, 31, 59, 101, 5, 77, 85, 57, 77, 42, 52, 85, 109, 112, 30, 26, 107, 75, 18, 94, 14, 18, 74, 42, 24, 8, 67, 0, 98, 71, 0 },
       { 0, 56, 49, 92, 76, 4, 115, 23, 64, 36, 88, 3, 89, 96, 42, 11, 1, 110, 54, 95, 73, 64, 19, 34, 67, 96, 16, 19, 28, 106, 79, 90, 0, 0 },
       { 0, 53, 76, 12, 85, 106, 118, 6, 30, 87, 122, 100, 4, 81, 4, 73, 26, 52, 101, 115, 67, 15, 101, 75, 96, 111, 125, 48, 119, 99, 88, 31, 83, 0 },
       { 0, 54, 23, 9, 20, 21, 51, 57, 1, 81, 127, 12, 116, 76, 91, 102, 43, 63, 99, 68, 17, 17, 79, 28, 96, 39, 63, 107, 103, 122, 17, 89, 85, 0 },
       { 0, 66, 39, 114, 121, 55, 123, 22, 82, 107, 17, 4, 114, 4, 55, 84, 22, 70, 93, 58, 107, 84, 65, 118, 66, 14, 82, 53, 10, 96, 109, 62, 77, 0 },
       { 0, 58, 90, 25, 39, 25, 35, 25, 99, 73, 16, 112, 29, 34, 92, 30, 74, 48, 103, 113, 32, 125, 55, 6, 69, 90, 86, 92, 84, 124, 40, 26, 33, 0 },
       { 0, 72, 29, 6, 118, 13, 101, 124, 35, 1, 126, 67, 110, 73, 16, 107, 31, 82, 78, 127, 10, 127, 52, 103, 65, 64, 10, 23, 88, 110, 16, 118, 89, 0 },
       { 0, 1, 99, 105, 21, 19, 4, 0, 68, 5, 15, 96, 92, 110, 45, 39, 25, 21, 44, 55, 115, 27, 25, 119, 33, 104, 82, 26, 12, 35, 116, 109, 92, 0 },
       { 0, 108, 18, 36, 35, 84, 26, 57, 45, 10, 125, 41, 8, 87, 80, 65, 119, 82, 81, 14, 77, 125, 89, 76, 89, 93, 67, 65, 77, 69, 14, 103, 28, 0 },
       { 0, 55, 92, 30, 28, 95, 87, 91, 66, 41, 101, 59, 105, 105, 115, 19, 22, 33, 106, 95, 79, 25, 3, 53, 71, 41, 6, 13, 82, 16, 25, 29, 69, 0 },
       { 0, 94, 124, 26, 69, 19, 121, 76, 43, 30, 67, 117, 1, 66, 126, 61, 55, 75, 36, 68, 15, 48, 103, 19, 112, 27, 82, 92, 36, 58, 74, 35, 114, 0 },
       { 0, 43, 21, 69, 66, 79, 93, 69, 15, 85, 68, 77, 43, 77, 116, 101, 83, 111, 52, 65, 78, 112, 28, 13, 24, 64, 94, 39, 5, 118, 98, 27, 98, 0 },
       { 0, 89, 83, 114, 120, 112, 16, 97, 57, 45, 26, 12, 116, 59, 113, 102, 48, 43, 17, 12, 105, 106, 65, 105, 119, 110, 6, 78, 96, 61, 115, 123, 108, 0 },
       { 0, 107, 44, 56, 115, 5, 69, 109, 124, 114, 35, 77, 82, 73, 110, 2, 41, 1, 5, 70, 126, 47, 62, 31, 81, 100, 58, 91, 90, 1, 62, 34, 43, 0 },
       { 0, 39, 74, 46, 6, 95, 93, 111, 77, 108, 127, 81, 94, 80, 78, 116, 38, 92, 66, 40, 55, 16, 124, 67, 120, 47, 91, 103, 70, 79, 8, 35, 100, 0 },
       { 0, 115, 7, 24, 106, 106, 70, 68, 30, 84, 0, 94, 66, 23, 2, 49, 19, 114, 87, 91, 19, 17, 87, 69, 53, 97, 94, 42, 26, 47, 103, 54, 61, 0 },
       { 0, 13, 59, 4, 108, 65, 79, 55, 63, 19, 122, 113, 125, 36, 75, 51, 22, 53, 28, 108, 112, 1, 22, 119, 59, 35, 104, 0, 109, 109, 76, 95, 72, 0 },
       { 0, 33, 81, 17, 73, 111, 17, 46, 78, 92, 45, 53, 113, 96, 57, 21, 11, 73, 101, 8, 68, 116, 52, 118, 62, 36, 30, 36, 65, 35, 45, 120, 84, 0 },
       { 0, 117, 31, 35, 2, 122, 23, 75, 14, 45, 50, 1, 30, 44, 10, 76, 30, 28, 19, 32, 73, 61, 40, 40, 64, 57, 102, 62, 108, 82, 23, 60, 9, 0 },
       { 0, 2, 55, 54, 88, 35, 53, 27, 117, 91, 54, 124, 124, 79, 105, 3, 35, 37, 72, 63, 0, 14, 122, 90, 121, 72, 84, 89, 51, 78, 69, 15, 44, 0 },
       { 0, 100, 100, 66, 52, 21, 20, 104, 40, 16, 6, 62, 92, 0, 96, 18, 103, 102, 87, 65, 12, 25, 118, 65, 28, 58, 108, 126, 11, 38, 48, 119, 19, 0 },
       { 0, 82, 122, 18, 96, 89, 24, 94, 82, 60, 14, 103, 66, 8, 56, 39, 111, 88, 70, 122, 86, 116, 40, 3, 43, 125, 16, 66, 51, 55, 105, 4, 77, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    {
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
       { 0, 39, 112, 122, 21, 95, 72, 41, 33, 100, 87, 108, 122, 65, 103, 64, 30, 16, 97, 32, 99, 20, 18, 16, 99, 39, 110, 93, 12, 50, 45, 96, 5, 0 },
       { 0, 95, 126, 95, 105, 120, 115, 124, 89, 110, 22, 111, 57, 116, 119, 126, 8, 54, 94, 97, 66, 57, 19, 124, 75, 104, 127, 34, 73, 80, 22, 109, 106, 0 },
       { 0, 30, 119, 43, 43, 100, 72, 12, 86, 86, 92, 14, 125, 99, 6, 18, 114, 101, 28, 3, 30, 37, 30, 97, 15, 75, 43, 15, 61, 125, 94, 106, 52, 0 },
       { 0, 118, 13, 54, 123, 126, 76, 5, 41, 65, 57, 75, 36, 99, 89, 108, 80, 14, 5, 111, 49, 14, 98, 121, 103, 3, 52, 14, 120, 12, 20, 6, 34, 0 },
       { 0, 127, 41, 105, 8, 124, 114, 103, 121, 110, 16, 40, 21, 88, 35, 14, 45, 37, 48, 21, 112, 123, 11, 42, 34, 90, 97, 99, 54, 102, 58, 75, 61, 0 },
       { 0, 83, 88, 64, 8, 102, 57, 120, 90, 88, 102, 68, 113, 67, 36, 65, 121, 2, 33, 97, 122, 88, 60, 92, 114, 119, 27, 87, 77, 24, 122, 74, 109, 0 },
       { 0, 62, 98, 74, 106, 63, 43, 0, 81, 23, 17, 114, 100, 112, 21, 37, 58, 113, 126, 91, 62, 79, 118, 72, 113, 68, 105, 35, 22, 102, 20, 87, 46, 0 },
       { 0, 62, 99, 101, 7, 83, 82, 75, 9, 95, 94, 74, 9, 50, 104, 102, 0, 99, 91, 4, 8, 75, 109, 15, 13, 11, 20, 89, 37, 18, 79, 42, 92, 0 },
       { 0, 102, 91, 18, 91, 116, 102, 25, 105, 23, 74, 110, 35, 119, 35, 12, 83, 83, 42, 21, 29, 96, 54, 126, 103, 57, 22, 28, 111, 115, 108, 2, 83, 0 },
       { 0, 119, 56, 33, 15, 20, 85, 90, 79, 112, 125, 36, 58, 30, 6, 109, 101, 62, 6, 70, 36, 36, 33, 109, 42, 3, 0, 101, 99, 103, 56, 36, 90, 0 },
       { 0, 88, 70, 97, 68, 4, 126, 115, 42, 120, 50, 96, 30, 125, 11, 121, 29, 88, 76, 27, 47, 116, 53, 43, 75, 61, 123, 9, 40, 101, 126, 83, 56, 0 },
       { 0, 68, 15, 122, 25, 17, 65, 26, 47, 96, 27, 60, 124, 87, 16, 114, 62, 40, 24, 20, 112, 63, 82, 59, 72, 101, 115, 52, 96, 112, 25, 21, 123, 0 },
       { 0, 65, 39, 42, 95, 108, 65, 0, 103, 51, 51, 100, 75, 53, 41, 127, 18, 3, 124, 107, 33, 124, 57, 96, 119, 102, 73, 27, 56, 46, 18, 94, 76, 0 },
       { 0, 44, 78, 71, 64, 64, 116, 98, 46, 53, 2, 62, 125, 64, 113, 92, 20, 68, 83, 84, 33, 35, 70, 62, 98, 122, 61, 102, 52, 112, 74, 80, 97, 0 },
       { 0, 50, 106, 18, 109, 105, 55, 50, 83, 35, 119, 23, 70, 95, 120, 112, 56, 62, 81, 21, 112, 72, 81, 119, 19, 91, 95, 61, 17, 72, 104, 112, 38, 0 },
       { 0, 82, 106, 47, 43, 1, 121, 4, 87, 110, 81, 101, 103, 12, 15, 37, 60, 12, 22, 81, 126, 86, 64, 126, 87, 66, 116, 0, 7, 102, 51, 29, 124, 0 },
       { 0, 115, 68, 116, 109, 53, 66, 65, 122, 122, 124, 9, 87, 45, 103, 69, 87, 6, 105, 112, 88, 22, 90, 87, 99, 1, 68, 110, 123, 102, 43, 95, 55, 0 },
       { 0, 7, 59, 30, 6, 71, 123, 16, 43, 1, 1, 27, 9, 21, 89, 24, 87, 32, 43, 41, 100, 54, 78, 42, 22, 67, 115, 13, 34, 27, 45, 115, 79, 0 },
       { 0, 109, 12, 99, 6, 75, 89, 123, 26, 55, 85, 3, 81, 41, 58, 73, 86, 112, 116, 122, 89, 119, 49, 60, 114, 92, 70, 0, 24, 0, 126, 0, 66, 0 },
       { 0, 38, 32, 27, 24, 67, 49, 35, 66, 45, 125, 115, 60, 66, 60, 52, 22, 18, 58, 112, 65, 127, 54, 119, 42, 18, 123, 50, 80, 82, 10, 77, 65, 0 },
       { 0, 25, 99, 106, 61, 98, 65, 106, 47, 65, 4, 103, 72, 53, 70, 8, 82, 43, 55, 124, 100, 109, 38, 47, 107, 96, 22, 101, 46, 76, 16, 26, 125, 0 },
       { 0, 37, 36, 75, 114, 88, 75, 3, 125, 115, 85, 83, 77, 77, 79, 39, 63, 42, 26, 99, 21, 38, 50, 1, 104, 77, 107, 104, 59, 95, 59, 63, 29, 0 },
       { 0, 66, 72, 104, 2, 5, 86, 122, 82, 103, 9, 48, 66, 34, 44, 65, 70, 48, 66, 57, 95, 117, 50, 110, 37, 117, 100, 97, 62, 32, 113, 85, 119, 0 },
       { 0, 17, 94, 40, 4, 126, 72, 98, 68, 57, 20, 54, 92, 74, 20, 114, 63, 110, 34, 40, 30, 116, 110, 71, 4, 40, 8, 86, 30, 51, 44, 17, 116, 0 },
       { 0, 77, 25, 58, 62, 16, 2, 120, 13, 16, 82, 85, 76, 91, 10, 62, 33, 64, 9, 82, 55, 63, 35, 7, 11, 50, 101, 71, 6, 22, 43, 78, 12, 0 },
       { 0, 16, 23, 4, 107, 87, 54, 96, 63, 39, 49, 66, 101, 37, 76, 58, 48, 95, 28, 40, 77, 29, 18, 123, 62, 11, 26, 10, 89, 115, 84, 54, 89, 0 },
       { 0, 68, 63, 5, 118, 117, 92, 108, 106, 86, 46, 99, 21, 108, 41, 124, 43, 120, 83, 98, 97, 52, 29, 85, 58, 58, 22, 126, 66, 58, 85, 89, 61, 0 },
       { 0, 9, 33, 92, 115, 16, 100, 82, 107, 12, 50, 81, 84, 11, 55, 10, 61, 107, 38, 14, 114, 64, 21, 1, 83, 70, 1, 28, 6, 16, 73, 66, 57, 0 },
       { 0, 118, 85, 20, 2, 50, 67, 28, 51, 125, 35, 8, 28, 1, 25, 28, 101, 46, 92, 37, 14, 119, 20, 98, 119, 82, 47, 86, 10, 16, 110, 14, 7, 0 },
       { 0, 113, 14, 103, 69, 121, 98, 25, 81, 123, 100, 31, 66, 30, 6, 43, 65, 124, 52, 120, 40, 10, 45, 99, 34, 21, 13, 91, 40, 16, 110, 23, 111, 0 },
       { 0, 13, 57, 126, 79, 13, 10, 98, 83, 57, 37, 14, 58, 64, 89, 65, 89, 29, 127, 17, 87, 66, 93, 16, 37, 55, 59, 78, 3, 125, 8, 19, 1, 0 },
       { 0, 30, 18, 23, 22, 73, 47, 66, 40, 5, 127, 86, 13, 4, 91, 13, 65, 119, 3, 87, 115, 123, 4, 106, 14, 117, 122, 57, 108, 44, 84, 87, 81, 0 },
       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    }
};

#endif // INPUT_TENSOR_H
