// srry for bad code but I didn't want to over engineer

#include <iostream>
#include <math.h>
#include <stdio.h>

#define PI 3.14159265

float normalize( int color );
float calculateIntensity( int red, int green, int blue );
float calculateSaturation( int red, int green, int blue, float intensity );
int calculateHue( int red, int green, int blue );
int minimum( int red, int green, int blue );
int maximum( int red, int green, int blue );
void toPixel( int& hue, float& saturation, float& intensity );
void writeToFile( FILE* file, unsigned char& data, int size );
void average();

void HSI_to_RGB( float& red, float& green, float& blue, int hue, float saturation, float intensity );
void RGB_to_HSI( float red, float green, float blue, int& hue, float& saturation, float& intensity );

//size of the image
#define H 1920
#define W 1080

#define DATASIZE H*W*3

unsigned char data[DATASIZE];

unsigned char hueData[DATASIZE];
unsigned char satData[DATASIZE];
unsigned char intData[DATASIZE];

unsigned char avgHue[H*W];
unsigned char avgSat[H*W];
unsigned char avgInt[H*W];

FILE* src_file;
FILE* out_file;
FILE* hue_file;

int main()
{
    src_file = fopen( "gta_1.raw", "rb" );
    fread( data, 1, DATASIZE, src_file );
    fclose( src_file );
    
    int x = 0;
    for( int i = 0; i < DATASIZE; i = i + 3 )
    {   
        int red = data[i];
        int green = data[i+1];
        int blue = data[i+2];
        
        int hue;
        float saturation;
        float intensity;

        RGB_to_HSI( red, green, blue, hue, saturation, intensity );
        
        avgHue[x] = hue;
        avgSat[x] = saturation;
        avgInt[x] = intensity;
        x++;

        toPixel( hue, saturation, intensity );
        
        hueData[i] = hue;
        hueData[i+1] = hue;
        hueData[i+2] = hue;
        
        satData[i] = saturation;
        satData[i+1] = saturation;
        satData[i+2] = saturation;
        
        intData[i] = intensity;
        intData[i+1] = intensity;
        intData[i+2] = intensity;
    }
    
    average();

    out_file = fopen( "gta_1_hue.raw", "wb" );
    fwrite( hueData, 1, DATASIZE, out_file );
    fclose( out_file );
    
    out_file = fopen( "gta_1_sat.raw", "wb" );
    fwrite( satData, 1, DATASIZE, out_file );
    fclose( out_file );
    
    out_file = fopen( "gta_1_int.raw", "wb" );
    fwrite( intData, 1, DATASIZE, out_file );
    fclose( out_file );
    


    src_file = fopen( "gta_2.raw", "rb" );
    fread( data, 1, DATASIZE, src_file );
    fclose( src_file );
    
    x = 0;
    for( int i = 0; i < DATASIZE; i = i + 3 )
    {   
        int red = data[i];
        int green = data[i+1];
        int blue = data[i+2];
        
        int hue;
        float saturation;
        float intensity;

        RGB_to_HSI( red, green, blue, hue, saturation, intensity );
        
        avgHue[x] = hue;
        avgSat[x] = saturation;
        avgInt[x] = intensity;
        x++;
        
        toPixel( hue, saturation, intensity );

        hueData[i] = hue;
        hueData[i+1] = hue;
        hueData[i+2] = hue;
        
        satData[i] = saturation;
        satData[i+1] = saturation;
        satData[i+2] = saturation;
        
        intData[i] = intensity;
        intData[i+1] = intensity;
        intData[i+2] = intensity;
    }
    
    average();
    
    out_file = fopen( "gta_2_hue.raw", "wb" );
    fwrite( hueData, 1, DATASIZE, out_file );
    fclose( out_file );
    
    out_file = fopen( "gta_2_sat.raw", "wb" );
    fwrite( satData, 1, DATASIZE, out_file );
    fclose( out_file );
    
    out_file = fopen( "gta_2_int.raw", "wb" );
    fwrite( intData, 1, DATASIZE, out_file );
    fclose( out_file );

    return 0;
}


void average()
{
    float avg; 
    int size = H*W;
    
    avg = 0;
    for( int i = 0; i < size; i++ )
    {
        avg = avg + avgHue[i];
    }
    std::cout << "HUE: " << int(avg/size);

    avg = 0;
    for( int i = 0; i < size; i++ )
    {
        avg = avg + avgSat[i];
    }
    std::cout << "  SAT: " << avg/size;

    avg = 0;
    for( int i = 0; i < size; i++ )
    {
        avg = avg + avgInt[i];
    }
    std::cout << "  INT: " << avg/size << std::endl;
}

/**
 * converts RGB to HSI
*/
void RGB_to_HSI( float red, float green, float blue, int& hue, float& saturation, float& intensity )
{
    intensity = calculateIntensity( red, green, blue );
    saturation = calculateSaturation( red, green, blue, intensity );
    hue = calculateHue( red, green, blue );
}

/**
 * converts HSI to RGB
*/
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

void toPixel( int& hue, float& saturation, float& intensity )
{
    float temp = hue/360.0;
    
    hue = temp * 255.0;
    saturation = int(saturation * 255);
    intensity = int(intensity * 255);
}

/**
 * calculates intensity of rgb value 0-255
*/
float calculateIntensity( int red, int green, int blue )
{
    return (red + green + blue) / (3.0*255);
}

/**
 * calculates saturation of rgb value 0-255
*/
float calculateSaturation( int red, int green, int blue, float intensity )
{
    int min = minimum( red, green, blue );
    float normal_min = normalize( min );

    return (intensity - normal_min) / intensity;
}

/**
 * calculates the hue of rgb value 0-255
*/
int calculateHue( int red, int green, int blue )
{
    // find max and min
    float min = minimum( red, green, blue );
    float max = maximum( red, green, blue );
    float hue = 0.0;
    
    // avoid division by 0
    if( min == max )
    {
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

/**
 * returns minimum value
*/
int minimum( int red, int green, int blue )
{
    int minValue = red;

    if( blue < minValue )
        minValue = blue;
    
    if( green < minValue )
        minValue = green;

    return minValue;
}

/**
 * returns maximum value
*/
int maximum( int red, int green, int blue )
{
    int maxValue = red;

    if( blue > maxValue )
        maxValue = blue;
    
    if( green > maxValue )
        maxValue = green;

    return maxValue;
}

/**
 * converts from 0-255 to 0-1
*/
float normalize( int color )
{
    return color / 255.0;
}
