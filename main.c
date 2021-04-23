#include <msp430.h> 
#include <srand.h>
#include"peripherals.h"
/**
 * global variable setup
 */

volatile long int c timer = 0;
unsigned int int_display_time = 500;
unsigned long long int time_break = 0;
unsigned long long int time_break_end = 0;

unsigned char state ='0';

unsigned char


/**
 * main.c
 */
int main(void)
{
    _BIS_SR(GIE);
	WDTCTL = WDTPW | WDTHOLD;// stop watchdog timer
	setup();

	Graphics_clearDisplay(&g_sContext); // clears the display so it is empty



	unsigned char answer_iterator  = 0
	while(1){

	switch(state){
	    case'0':
	         // displays simon
	         // press any button to play
	         //
	        if(validKey())
	        {
	            state = '1';
	            Graphics_clearDisplay(&g_sContext)
	            time_break = timer;
	            timer_break_end = timer *
	        }
	         break;
	    case '1':
	        //displays sequence over a period of time
	        // on end changes to the state that recieves input
	       if(timer>timer_break_end)
	       {
	          state = '2'
	       }

	    break;
	case'2'

	    break;

	     if(coorect_input())
	     {

	     }
	     if(!correct_input()&&valid_input())
	     {
	       timer_break = timer;
	       timer_break_end = timer+2000;
	       state = '4';
	     }
	case'3':
	    //is the condition that waits for you to press any button to display a sequence
	    //wrong values push you back to simon says main page
	    // correct values move along the sequence
	    break;
	case'4':
	    // youlose screen
	    if(timer>timer_break_end)
	    {

	    }
	    break;
	
	}
	}
return 0;
}

void setup()
{
  configDisplay();
  configKeypad();
  setupTimer2();
}

/**
 * rests the counter 0
 */

bool valid_input()
{
    unsigned char k  = getKey();
    return k=='1'||k=='2'|| k =='3' ||k =='4'||k =='5';
}
/**
 * returns -1 else returns the number pressed on the key pad
 */
#pragma vector = TIMER2_A0_VECTOR;
void setupTimer2(void)
{
    TA2CTL = TASSEL_2+ID_0+MC_1;
    TA2CCRx = 20000;
    TA2CCTL0 = CCIE;
}
__interrupt void TimerA2_ISR{
 timer++;
}
