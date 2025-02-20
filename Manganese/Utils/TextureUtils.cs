using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Minecraft.Client.Renderer.Texture;

namespace Manganese.Utils;

public static class TextureUtils
{
    /**
     * Creates Java Edition styled color blending using two input packed colors
     */
    public static uint JavaBlend(uint one, uint two)
    {
        uint red;
        uint green;
        uint blue;
        uint alpha;

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

    /**
     * Creates vanila-styled color blending using two input packed colors
     */
    public static uint SharpBlend(uint colorOne, uint colorTwo)
    {
        uint red;
        uint green;
        uint blue; 

        if ((colorOne >> 24) + (colorTwo >> 24) < 255)
        {
            red = (GetColorFraction(colorOne >> 16) + GetColorFraction(colorTwo >> 16)) / 2 << 16;
            green = (GetColorFraction(colorOne >> 8) + GetColorFraction(colorTwo >> 8)) / 2 << 8;
            blue = (GetColorFraction(colorOne) + GetColorFraction(colorTwo)) / 2;

            return red | green | blue;
        }
        else if (colorTwo >> 24 < colorOne >> 24)
        {
            red = (GetColorFraction(colorOne >> 16) * 255 + GetColorFraction(colorTwo >> 16)) / 256 << 16;
            green = (GetColorFraction(colorOne >> 8) * 255 + GetColorFraction(colorTwo >> 8)) / 256 << 8;
            blue = (GetColorFraction(colorOne) * 255 + GetColorFraction(colorTwo)) / 256;
        }
        else
        {
            red = (GetColorFraction(colorOne >> 16) + GetColorFraction(colorTwo >> 16) * 255) / 256 << 16;
            green = (GetColorFraction(colorOne >> 8) + GetColorFraction(colorTwo >> 8) * 255) / 256 << 8;
            blue = (GetColorFraction(colorOne) + GetColorFraction(colorTwo) * 255) / 256;
        }

        return red | 0xff000000 | green | blue;
    }

    /**
     * Gets the color fraction for an inputed color
     */
    private static uint GetColorFraction(uint value)
    {
        return value & 255;
    }
}

