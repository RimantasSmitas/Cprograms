#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdint.h>
#define MAXTIMINGS	85
#define DHTPIN		7
int dht11_dat[5] = { 0, 0, 0, 0, 0 };
int tempRed=0,tempYellow=2,tempGreen=3, humidRed=12,humidYellow=13,humidGreen=14;

void exitFunction(){
digitalWrite (tempRed, LOW);
digitalWrite (tempYellow, LOW);
digitalWrite (tempGreen, LOW);
digitalWrite (humidRed, LOW);
digitalWrite (humidYellow, LOW);
digitalWrite (humidGreen, LOW);
}



tempHigh(){
digitalWrite (tempRed, HIGH);
digitalWrite (tempYellow, HIGH);
digitalWrite (tempGreen, HIGH);
}

tempMedium(){
digitalWrite (humidRed, LOW);
digitalWrite (tempYellow, HIGH);
digitalWrite (tempGreen, HIGH);
}

tempLow(){
digitalWrite (tempRed, LOW);
digitalWrite (tempYellow, LOW);
digitalWrite (tempGreen, HIGH);
}

humidHigh(){
digitalWrite (humidRed, HIGH);
digitalWrite (humidYellow, HIGH);
digitalWrite (humidGreen, HIGH);
}

humidMedium(){
digitalWrite (humidRed, LOW);
digitalWrite (humidYellow, HIGH);
digitalWrite (humidGreen, HIGH);
}

humidLow(){
digitalWrite (humidRed, LOW);
digitalWrite (humidYellow, LOW);
digitalWrite (humidGreen, HIGH);
}

int tempDecid(int temp){
if (temp>35)
  {tempHigh();}
 else if (35<temp>30){
tempMedium();}
  else if (temp <25){
tempLow(); }
}

int humidDecid(int humid)
{
if (humid>60)
  {humidHigh();}
 else if (60<humid <50){
humidMedium();}
  else if (humid <44){
humidLow();}

}

void read_dht11_dat()
{
	uint8_t laststate	= HIGH;
	uint8_t counter		= 0;
	uint8_t j		= 0, i;
	float	f;

	dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;

	pinMode( DHTPIN, OUTPUT );
	digitalWrite( DHTPIN, LOW );
	delay( 18 );
	digitalWrite( DHTPIN, HIGH );
	delayMicroseconds( 40 );
	pinMode( DHTPIN, INPUT );

	for ( i = 0; i < MAXTIMINGS; i++ )
	{
		counter = 0;
		while ( digitalRead( DHTPIN ) == laststate )
		{
			counter++;
			delayMicroseconds( 1 );
			if ( counter == 255 )
			{
				break;
			}
		}
		laststate = digitalRead( DHTPIN );

		if ( counter == 255 )
			break;

		if ( (i >= 4) && (i % 2 == 0) )
		{
			dht11_dat[j / 8] <<= 1;
			if ( counter > 16 )
				dht11_dat[j / 8] |= 1;
			j++;
		}
	}

	if ( (j >= 40) &&
	     (dht11_dat[4] == ( (dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) & 0xFF) ) )
	{
		f = dht11_dat[2] * 9. / 5. + 32;
		tempDecid(dht11_dat[2]);
		humidDecid(dht11_dat[0]);
		printf( "Humidity = %d.%d %% Temperature = %d.%d C (%.1f F)\n",
			dht11_dat[0], dht11_dat[1], dht11_dat[2], dht11_dat[3], f );
	}else  {
		printf( "Data not good, skip\n" );
	}
}








int main( void )
{
wiringPiSetup();
pinMode (tempRed, OUTPUT);
pinMode (tempYellow, OUTPUT);
pinMode (tempGreen, OUTPUT);
pinMode (humidRed, OUTPUT);
pinMode (humidYellow, OUTPUT);
pinMode (humidGreen, OUTPUT);
//digital

atexit (exitFunction);

        printf( "Raspberry Pi wiringPi DHT11 Temperature test program\n" );

        if ( wiringPiSetup() == -1 )
                exit( 1 );

        while ( 1 )
        {
                read_dht11_dat();
                delay( 1000 );
        }

        return(0);


}
