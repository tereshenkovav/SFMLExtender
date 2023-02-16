using System;
using System.Collections.Generic;
using System.Text;
using SFML.Window;
using SFML.Graphics;
using SFML.System;
using SFML.Audio;

namespace SfmlExtender
{
    [Flags]
    public enum SpriteLoaderOptions
    {
        sloCentered = 1, 
        sloNoSmooth = 2,
        sloMipmap = 4
    }

    // Класс-помощник для операций загрузки спрайтов и звуков
    public class SfmlUtils
    {
        private static Sprite createSpriteFromTexture(Texture tex, SpriteLoaderOptions options)
        {
            if (DefaultNoSmooth)
                tex.Smooth = false;
            else
                tex.Smooth = !options.HasFlag(SpriteLoaderOptions.sloNoSmooth);
            if (options.HasFlag(SpriteLoaderOptions.sloMipmap)) tex.GenerateMipmap();
            var spr = new Sprite(tex);
            if (options.HasFlag(SpriteLoaderOptions.sloCentered))
                spr.Origin = new Vector2f(tex.Size.X / 2, tex.Size.Y / 2);
            return spr;
        }

        public static Sprite LoadSprite(String filename)
        {
            return LoadSprite(filename, 0);
        }

        public static Sprite LoadSprite(String filename, SpriteLoaderOptions options)
        {
            return createSpriteFromTexture(new Texture(Options.getDataFile(filename)), options);
        }
        // Загрузка спрайта с увеличением яркости
        public static Sprite LoadSpriteBright(String filename, float upbright)
        {
            return LoadSpriteBright(filename, upbright, 0);
        }

        private static byte upByte(byte b, float up)
        {
            uint r = (uint)((float)b * up);
            if (r > 255) return 255; else return (byte)r;
        }
        public static Sprite LoadSpriteBright(String filename, float upbright, SpriteLoaderOptions options)
        {
            var img = new Image(Options.getDataFile(filename));
            for (uint i = 0; i < img.Size.X; i++)
                for (uint j = 0; j < img.Size.Y; j++)
                {
                    Color c = img.GetPixel(i, j);
                    c.R = upByte(c.R, upbright);
                    c.G = upByte(c.G, upbright);
                    c.B = upByte(c.B, upbright);
                    img.SetPixel(i, j, c);
                }
            return createSpriteFromTexture(new Texture(img, new IntRect(0, 0, (int)img.Size.X, (int)img.Size.Y)),options);
        }
        public static Color createSFMLColor(int r, int g, int b)
        {            
            return new Color((byte)r, (byte)g, (byte)b, 255); 
        }
        public static Color createSFMLColor(String hexcolor)
        {
            if (hexcolor.StartsWith("#")) hexcolor = hexcolor.Substring(1);
            byte r = (byte)Convert.ToInt32(hexcolor.Substring(0, 2), 16);
            byte g = (byte)Convert.ToInt32(hexcolor.Substring(0, 4), 16);
            byte b = (byte)Convert.ToInt32(hexcolor.Substring(0, 6), 16);
            return new Color(r, g, b, 255);
        }
        public static Sound LoadSound(String filename)
        {
            return new Sound(new SoundBuffer(Options.getDataFile(filename)));
        }
        public static bool DefaultNoSmooth = false ;
    }
}
