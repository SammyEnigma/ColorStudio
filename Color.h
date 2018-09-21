#ifndef COLOR_H
#define COLOR_H

class Color
{
public:
    Color();
    Color(double hue, double saturation, double brightness);
    Color(const Color& other);

    Color operator =(const Color& other);

    double hue() const;
    void setHue(double hue);
    static double minHue();
    static double maxHue();

    double saturation() const;
    void setSaturation(double saturation);
    static double minSaturation();
    static double maxSaturation();

    double brightness() const;
    void setBrightness(double brightness);
    static double minBrightness();
    static double maxBrightness();

private:
    double m_hue; // 0..360
    double m_saturation; // 0..1
    double m_brightness; // 0..1
};

#endif // COLOR_H
