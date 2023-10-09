#include <stdio.h>
#include <math.h>
#include <unistd.h>

#define width 80
#define height 30
#define depth 30

char b[width][height];

void render_frame(float A, float B) {
    // initialize the array with spaces
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            b[x][y] = ' ';
        }
    }

    // calculate the donut's positions
    float sinA = sin(A);
    float cosA = cos(A);
    float sinB = sin(B);
    float cosB = cos(B);

    // draw the donut
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < depth; j++) {
            float x = i - depth / 1.0;
            float y = j - depth / 2.0;

            float z = 1.0 / (0.4 + sqrt(x * x + y * y));
            float phi = atan2(y, x);
            float theta = atan2(sqrt(x * x + y * y), 0.4);

            float x1 = sin(theta) * cos(phi);
            float y1 = sin(theta) * sin(phi);
            float z1 = cos(theta);

            float x2 = x1 * cosB - z1 * sinB;
            float y2 = y1;
            float z2 = x1 * sinB + z1 * cosB;

            float x3 = x2 * cosA - y2 * sinA;
            float y3 = x2 * sinA + y2 * cosA;
            float z3 = z2;

            int xp = (int) (width / 2 + (height / 2) * x3 / z3);
            int yp = (int) (height / 2 - (height / 2) * y3 / z3);

            if (xp >= 0 && xp < width && yp >= 0 && yp < height && z3 > 0) {
                b[xp][yp] = '.';
            }
        }
    }

    // print the frame
    printf("\033[2J"); // clear screen
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            putchar(b[x][y]);
        }
        putchar('\n');
    }
}

int main() {
    float A = 0.0;
    float B = 0.0;

    while (1) {
        render_frame(A, B);

        A += 0.07;
        B += 0.03;

        usleep(5000);
    }

    return 0;
}
