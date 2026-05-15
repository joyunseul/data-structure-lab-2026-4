#pragma once

#define HEIGHT 8
#define WIDTH 8

class Image {
private:
    int image[HEIGHT][WIDTH];

public:
    Image(int img[HEIGHT][WIDTH]);
    int getMaxBrightness();
};