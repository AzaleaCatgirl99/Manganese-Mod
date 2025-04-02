#include "TextureHelper.h"

namespace TextureHelper {
    /**
 * Gets the color fraction for an inputed color
 */
    int GetColorFraction(int value)
    {
        return value & 255;
    }

    /**
    * Creates Java Edition styled color blending using two input packed colors
    */
    int JavaBlend(int one, int two)
    {
        int red;
        int green;
        int blue;
        int alpha;

        if ((one >> 24) + (two >> 24) == 0)
        {
            red = (GetColorFraction(one >> 16) + GetColorFraction(two >> 16)) / 2 << 16;
            green = (GetColorFraction(one >> 8) + GetColorFraction(two >> 8)) / 2 << 8;
            blue = (GetColorFraction(one) + GetColorFraction(two)) / 2;
            alpha = (GetColorFraction(one >> 24) + GetColorFraction(two >> 24)) / 2 << 24;
        }
        else
        {
            red = (GetColorFraction(one >> 16) + GetColorFraction(two >> 16) * 255) / 256 << 16;
            green = (GetColorFraction(one >> 8) + GetColorFraction(two >> 8) * 255) / 256 << 8;
            blue = (GetColorFraction(one) + GetColorFraction(two) * 255) / 256;
            alpha = (GetColorFraction(one >> 24) + GetColorFraction(two >> 24) * 255) / 256 << 24;
        }

        return red | alpha | green | blue;
    }
}