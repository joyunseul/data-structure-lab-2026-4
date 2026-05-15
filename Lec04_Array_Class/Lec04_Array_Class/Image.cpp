#include "Image.h"

Image::Image(int img[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] = img[i][j];
        }
    }
}

int Image::getMaxBrightness() {
    int max = image[0][0];

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (image[i][j] > max) {
                max = image[i][j];
            }
        }
    }
    return max;
}