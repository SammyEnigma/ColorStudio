#include "Color.h"

namespace
{

const double MIN_HUE = 0.0;
const double MAX_HUE = 360.0;

const double MIN_SATURATION = 0.0;
const double MAX_SATURATION = 1.0;

const double MIN_BRIGHTNESS = 0.0;
const double MAX_BRIGHTNESS = 1.0;

double constrain(double value, double min, double max)
{
    if (value < min)
        return min;
    if (value > max)
        return max;
    return value;
}

}

Color::Color() :
    m_hue(MIN_HUE),
    m_saturation(MIN_SATURATION),
    m_brightness(MAX_BRIGHTNESS)
{
}

Color::Color(double hue, double saturation, double brightness)
{
    setHue(hue);
    setSaturation(saturation);
    setBrightness(brightness);
}

Color::Color(const Color& other) :
    m_hue(other.hue()),
    m_saturation(other.saturation()),
    m_brightness(other.brightness())
{
}

Color Color::operator =(const Color& other)
{
    setHue(other.hue());
    setSaturation(other.saturation());
    setBrightness(other.brightness());

    return *this;
}

double Color::hue() const
{
    return m_hue;
}

void Color::setHue(double hue)
{
    m_hue = constrain(hue, MIN_HUE, MAX_HUE);
}

double Color::minHue()
{
    return MIN_HUE;
}

double Color::maxHue()
{
    return MAX_HUE;
}

double Color::saturation() const
{
    return m_saturation;
}

void Color::setSaturation(double saturation)
{
    m_saturation = constrain(saturation, MIN_SATURATION, MAX_SATURATION);
}

double Color::minSaturation()
{
    return MIN_SATURATION;
}

double Color::maxSaturation()
{
    return MAX_SATURATION;
}

double Color::brightness() const
{
    return m_brightness;
}

void Color::setBrightness(double brightness)
{
    m_brightness = constrain(brightness, MIN_BRIGHTNESS, MAX_BRIGHTNESS);
}

double Color::minBrightness()
{
    return MIN_BRIGHTNESS;
}

double Color::maxBrightness()
{
    return MAX_BRIGHTNESS;
}
