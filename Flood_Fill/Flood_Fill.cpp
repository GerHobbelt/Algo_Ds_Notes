#include "generic.h"
#include <graphics.h>

using namespace std;

void floodFill (int x, int y, int old, int newcol)
{
    int current;

    // To get color pixel
    current = getpixel (x, y);

    // check current pixel is old_color or not
    if (current == old)
    {
        delay (5);

        // put new pixel with new color
        putpixel (x, y, newcol);

        // recursive call for bottom pixel fill
        floodFill (x + 1, y, old, newcol);

        // recursive call for top pixel fill
        floodFill (x - 1, y, old, newcol);

        // recursive call for right pixel fill
        floodFill (x, y + 1, old, newcol);

        // recursive call for left pixel fill
        floodFill (x, y - 1, old, newcol);

        // recursive call for bottom-right corner pixel fill
        floodFill (x + 1, y + 1, old, newcol);

        // recursive call for top-right corner pixel fill
        floodFill (x - 1, y + 1, old, newcol);

        // recursive call for bottom-left corner pixel fill
        floodFill (x + 1, y - 1, old, newcol);

        // recursive call for top-left corner pixel fill
        floodFill (x - 1, y - 1, old, newcol);
    }
}

int main()
{
    int gd = DETECT, gm;
    int left, top, right, bottom;

    cout << "Enter the left point: ";
    cin >> left;

    cout << "Enter the top point: ";
    cin >> top;

    cout << "Enter the right point: ";
    cin >> right;

    cout << "Enter the bottom point: ";
    cin >> bottom;

    initgraph (&gd, &gm, "C:\\TURBOC3\\BGI");

    rectangle (left, top, right, bottom);

    floodFill (left + 1, top + 1, 0, 15);

    getch ();
    closegraph ();
		return 0;
}

// Sample input - https://imgur.com/css9qIj
// Sample output - https://imgur.com/0N0Kjr8
