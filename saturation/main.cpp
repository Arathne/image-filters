#include <iostream>
#include <math.h>

#define PI 3.14159265

float normalize( int color );
float calculateIntensity( int red, int green, int blue );
float calculateSaturation( int red, int green, int blue, float intensity );
int calculateHue( int red, int green, int blue );
int minimum( int red, int green, int blue );
int maximum( int red, int green, int blue );

void HSI_to_RGB( float& red, float& green, float& blue, int hue, float saturation, float intensity );

int main()
{
    // original rgb values
    int red = 254;
    int green = 123;
    int blue = 132;
    
    float intensity = calculateIntensity( red, green, blue );
    float saturation = calculateSaturation( red, green, blue, intensity );
    int hue = calculateHue( red, green, blue );

    std::cout << "RGB: " << red << " " << green << " " << blue << std::endl;
    std::cout << "HUE: " << hue << std::endl;
    std::cout << "SAT: " << saturation << std::endl;
    std::cout << "INT: " << intensity << std::endl;
    
    float tred = 0;
    float tgreen = 0;
    float tblue = 0;

    HSI_to_RGB( tred, tgreen, tblue, hue, saturation, intensity );

    std::cout << std::endl << "RGB: " << tred << " " << tgreen << " " << tblue << std::endl;
    return 0;
}

void HSI_to_RGB( float& red, float& green, float& blue, int hue, float saturation, float intensity )
{   
    float x = intensity*(1.0 - saturation);
    float h = hue * (PI/180);

    if( hue < 120 )
    {
        blue = x;
        red = intensity*( 1+( (saturation*cos(h) / cos( (PI/3)-h))));
        green = 3*intensity - (blue+red);
    }
    else if( hue < 240 )
    {
        h = h - ((2*PI)/3);
        red = x;
        green = intensity*( 1+( (saturation*cos(h) / cos( (PI/3)-h))));
        blue = 3*intensity - (red+green);      
    }
    else if( hue < 360 )
    {
        h = h - ((4*PI)/3);
        green = x;
        blue = intensity*( 1+( (saturation*cos(h) / cos( (PI/3)-h))));
        red = 3*intensity - (green+blue);
    }

    red = round(red * 255);
    green = round(green * 255);
    blue = round(blue * 255);
}

float calculateIntensity( int red, int green, int blue )
{
    return (red + green + blue) / (3.0*255);
}

float calculateSaturation( int red, int green, int blue, float intensity )
{
    int min = minimum( red, green, blue );
    float normal_min = normalize( min );

    return (intensity - normal_min) / intensity;
}

int calculateHue( int red, int green, int blue )
{
    // find max and min
    float min = minimum( red, green, blue );
    float max = maximum( red, green, blue );
    float hue = 0.0;
    
    // avoid division by 0
    if( min == max )
    {
        std::cout << "min and max are the same!" << std::endl;
        return 0;
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
    
    return hue;
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
