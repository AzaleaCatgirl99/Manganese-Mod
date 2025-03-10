#include "Texture.h"


// CrispBlend hook; returns the new function based on the MipmapType value
int Texture::CrispBlend(int one, int two)
{
    if (MipmapType::get() == 2) {
        return JavaBlend(JavaBlend(one, two), JavaBlend(one, two));
    }
    else {
        return Texture_CrispBlend(one, two);
    }
}

void Texture::TransferFromImage(Texture* _this, BufferedImage* bufferedImage)
{
    Texture_TransferFromImage(_this, bufferedImage);
    /*return;*/
}