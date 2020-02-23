#include <iostream>
#include <cmath>

float normalize( int color );
float calculateIntensity( int red, int green, int blue );

int calculateHue( int red, int green, int blue );
float calculateSaturation( int red, int green, int blue, float intensity );
int minimum( int red, int green, int blue );
int maximum( int red, int green, int blue );


int main()
{
    // original rgb values
    int red = 122;
    int green = 200;
    int blue = 140;
    
    float intensity = calculateIntensity( red, green, blue );

    

    return 0;
}

float calculateIntensity( int red, int green, int blue )
{
    return (red + green + blue) / (3.0*255);
}

float calculateSaturation( int red, int green, int blue )
{
    float max = maximum( red, green, blue );
    float min = minimum( red, green, blue );

    float saturation = (max - min) / max;
    std::cout << saturation << std::endl;

    return 0.0;
}

int calculateHue( int red, int green, int blue )
{
    float normal_red = normalize( red );
    float normal_green = normalize( green );
    float normal_blue = normalize( blue );

   return 0;

    /*
    // find max and min
    float min = minimum( red, green, blue );
    float max = maximum( red, green, blue );
    float hue = 0.0;
    
    // avoid division by 0
    if( min == max )
    {
        std::cout << "min and max are the same!" << std::endl;
        return (max - min) / 2;
    }
    
    // calculate hue
    if( max == red )
        hue = (green - blue) / (max - min);
    else if( max == green )
        hue = 2.0 + (blue - red) / (max - min);
    else
        hue = 4.0 + (red - green) / (max - min);

    hue = hue * 60;
    
    // must be from 0 to 360
    if (hue < 0)
        hue = hue + 360;
    
    return round(hue);
    */
}

int minimum( int red, int green, int blue )
{
    int minValue = red;

    if( blue < minValue )
        minValue = blue;
    
    if( green < minValue )
        minValue = green;

    return minValue;
}

int maximum( int red, int green, int blue )
{
    int maxValue = red;

    if( blue > maxValue )
        maxValue = blue;
    
    if( green > maxValue )
        maxValue = green;

    return maxValue;
}

float normalize( int color )
{
    return color / 255.0;
}
