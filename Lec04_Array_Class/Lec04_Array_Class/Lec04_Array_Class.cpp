#include <iostream>
#include "Image.h"
using namespace std;

#define HEIGHT 8
#define WIDTH 8

class Image {
private:
    int image[HEIGHT][WIDTH];

public:
    // 생성자
    Image(int img[HEIGHT][WIDTH]) {
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                image[i][j] = img[i][j];
            }
        }
    }

    // 최대 밝기값 반환
    int getMaxBrightness() {
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
};

int main() {
    int img[HEIGHT][WIDTH] = {
        { 10, 30, 55, 80, 120, 160, 200, 230 },
        { 20, 45, 70, 100, 140, 180, 220, 210 },
        { 35, 60, 90, 130, 170, 210, 240, 190 },
        { 50, 80, 115, 150, 190, 230, 255, 170 },
        { 40, 65, 100, 140, 175, 215, 235, 150 },
        { 25, 50, 80, 115, 155, 195, 210, 130 },
        { 15, 35, 60, 90, 130, 165, 185, 110 },
        { 5, 20, 40, 70, 105, 140, 160, 90 }
    };

    Image image(img);

    cout << "최대 밝기값: " << image.getMaxBrightness() << endl;

    return 0;
}
