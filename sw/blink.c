#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define GPIO_PIN_0 0x01
#define GPIO_PIN_1 0x02
#define GPIO_PIN_2 0x04
#define GPIO_PIN_3 0x08
#define GPIO_PIN_4 0x10
#define GPIO_PIN_5 0x20
#define GPIO_PIN_6 0x40
#define GPIO_PIN_7 0x80

#define CLK_DIVR	(*(volatile uint8_t *)0x50c6)
#define CLK_PCKENR1	(*(volatile uint8_t *)0x50c7)

#define TIM1_CR1    (*(volatile uint8_t *)0x5250)
#define TIM1_IER    (*(volatile uint8_t *)0x5254)
#define TIM1_SR1    (*(volatile uint8_t *)0x5255)
#define TIM1_CNTRH  (*(volatile uint8_t *)0x525e)
#define TIM1_CNTRL  (*(volatile uint8_t *)0x525f)
#define TIM1_PSCRH  (*(volatile uint8_t *)0x5260)
#define TIM1_PSCRL  (*(volatile uint8_t *)0x5261)
#define TIM1_ARRH   (*(volatile uint8_t *)0x5262)
#define TIM1_ARRL   (*(volatile uint8_t *)0x5263)

#define TIM2_CR1	(*(volatile uint8_t *)0x5300)
#define TIM2_IER	(*(volatile uint8_t *)0x5301)
#define TIM2_SR1	(*(volatile uint8_t *)0x5302)
#define TIM2_SR2	(*(volatile uint8_t *)0x5303)
#define TIM2_EGR	(*(volatile uint8_t *)0x5304)
#define TIM2_CCMR1	(*(volatile uint8_t *)0x5305)
#define TIM2_CCMR2	(*(volatile uint8_t *)0x5306)
#define TIM2_CCMR3	(*(volatile uint8_t *)0x5307)
#define TIM2_CCER1	(*(volatile uint8_t *)0x5308)
#define TIM2_CCER2	(*(volatile uint8_t *)0x5309)
#define TIM2_CNTRH	(*(volatile uint8_t *)0x530a)
#define TIM2_CNTRL	(*(volatile uint8_t *)0x530b)
#define TIM2_PSCR	(*(volatile uint8_t *)0x530c)
#define TIM2_ARRH	(*(volatile uint8_t *)0x530d)
#define TIM2_ARRL	(*(volatile uint8_t *)0x530e)
#define TIM2_CCR1H	(*(volatile uint8_t *)0x530f)
#define TIM2_CCR1L	(*(volatile uint8_t *)0x5310)
#define TIM2_CCR2H	(*(volatile uint8_t *)0x5311)
#define TIM2_CCR2L	(*(volatile uint8_t *)0x5312)
#define TIM2_CCR3H	(*(volatile uint8_t *)0x5313)
#define TIM2_CCR3L	(*(volatile uint8_t *)0x5314)

#define PA_ODR (*(volatile uint8_t *)0x5000)
#define PA_IDR (*(volatile uint8_t *)0x5001)
#define PA_DDR (*(volatile uint8_t *)0x5002)
#define PA_CR1 (*(volatile uint8_t *)0x5003)
#define PA_CR2 (*(volatile uint8_t *)0x5004)

#define PB_ODR (*(volatile uint8_t *)0x5005)
#define PB_IDR (*(volatile uint8_t *)0x5006)
#define PB_DDR (*(volatile uint8_t *)0x5007)
#define PB_CR1 (*(volatile uint8_t *)0x5008)
#define PB_CR2 (*(volatile uint8_t *)0x5009)

#define PC_ODR (*(volatile uint8_t *)0x500a)
#define PC_IDR (*(volatile uint8_t *)0x500b)
#define PC_DDR (*(volatile uint8_t *)0x500c)
#define PC_CR1 (*(volatile uint8_t *)0x500d)
#define PC_CR2 (*(volatile uint8_t *)0x500e)

#define PD_ODR (*(volatile uint8_t *)0x500f)
#define PD_IDR (*(volatile uint8_t *)0x5010)
#define PD_DDR (*(volatile uint8_t *)0x5011)
#define PD_CR1 (*(volatile uint8_t *)0x5012)
#define PD_CR2 (*(volatile uint8_t *)0x5013)

#define PE_ODR (*(volatile uint8_t *)0x5014)
#define PE_IDR (*(volatile uint8_t *)0x5015)
#define PE_DDR (*(volatile uint8_t *)0x5016)
#define PE_CR1 (*(volatile uint8_t *)0x5017)
#define PE_CR2 (*(volatile uint8_t *)0x5018)

#define PG_ODR (*(volatile uint8_t *)0x501e)
#define PG_IDR (*(volatile uint8_t *)0x501f)
#define PG_DDR (*(volatile uint8_t *)0x5020)
#define PG_CR1 (*(volatile uint8_t *)0x5021)
#define PG_CR2 (*(volatile uint8_t *)0x5022)

#define USART1_SR	(*(volatile uint8_t *)0x5230)
#define USART1_DR	(*(volatile uint8_t *)0x5231)
#define USART1_BRR1	(*(volatile uint8_t *)0x5232)
#define USART1_BRR2	(*(volatile uint8_t *)0x5233)
#define USART1_CR2	(*(volatile uint8_t *)0x5235)
#define USART1_CR3	(*(volatile uint8_t *)0x5236)

#define USART3_SR	(*(volatile uint8_t *)0x5240)
#define USART3_DR	(*(volatile uint8_t *)0x5241)
#define USART3_BRR1	(*(volatile uint8_t *)0x5242)
#define USART3_BRR2	(*(volatile uint8_t *)0x5243)
#define USART3_CR1	(*(volatile uint8_t *)0x5244)
#define USART3_CR2	(*(volatile uint8_t *)0x5245)
#define USART3_CR3	(*(volatile uint8_t *)0x5246)
#define USART3_CR4	(*(volatile uint8_t *)0x5247)
#define USART3_CR6	(*(volatile uint8_t *)0x5249)

#define USART_CR2_TEN (1 << 3)
#define USART_CR2_REN (1 << 2)
#define USART_CR3_STOP2 (1 << 5)
#define USART_CR3_STOP1 (1 << 4)
#define USART_SR_TXE (1 << 7)
#define USART_SR_RXNE (1 << 5)

uint8_t GetMeasurement (uint8_t data);
uint16_t ConvertToDistance (void);
int putchar (int c);
void clanger_Relax (void);
void clanger_Prepare (void);
void clanger_Strike (void);

volatile uint8_t flag50 = 0;

uint8_t rxpkt_state;
uint8_t rxpkt_count;
uint8_t rxpkt_buffer[8];

uint8_t panic = 0;
uint8_t panicCount = 0;
uint8_t panicPhase = 0;

uint16_t distance;
uint16_t restingDistance;
uint16_t triggerDistance;
uint32_t distances;

void main (void)
{
	uint8_t result, data;

	// timer for blinking LED
	uint8_t led_timer = 0;

	// set clock to internal 16 MHz oscillator
	CLK_DIVR = 0x00;

	// enable peripheral clocks
	CLK_PCKENR1 = 0xff;

	// set UART1_TX on PA5 as a push-pull output
	PA_DDR |= GPIO_PIN_5;
	PA_CR1 |= GPIO_PIN_5;

	// configure USART1
	USART1_CR2 = USART_CR2_TEN | USART_CR2_REN; // Allow TX and RX
	USART1_CR3 &= ~(USART_CR3_STOP1 | USART_CR3_STOP2); // 1 stop bit
	USART1_BRR2 = 0x03; // 9600 baud
	USART1_BRR1 = 0x68;

	// configure USART3
	USART3_CR2 = USART_CR2_TEN | USART_CR2_REN; // Allow TX and RX
	USART3_CR3 &= ~(USART_CR3_STOP1 | USART_CR3_STOP2); // 1 stop bit
	USART3_BRR2 = 0x03; // 9600 baud
	USART3_BRR1 = 0x68;

	// configure port b as push-pull outputs
	PB_ODR = 0xFF; // all high
    PB_DDR = 0xFF; // all outputs
	PB_CR1 = 0xFF; // all totem pole
	PB_CR2 = 0x00; // all normal speed

	// configure port c as push-pull outputs, bit 5 is user led
	PC_ODR = 0xDF; // all high except led
    PC_DDR = 0xFF; // all outputs
	PC_CR1 = 0xFF; // all totem pole
	PC_CR2 = 0x00; // all normal speed

	// configure port d as push-pull outputs, PD6 as floating input without interrupt
	PD_ODR = 0xBF; // all high
	PD_DDR = 0xBF; // all outputs
	PD_CR1 = 0xBF; // all totem pole
	PD_CR2 = 0x00; // all normal speed

	// configure port e as push-pull outputs, PE4 as floating input without interrupt
	PE_ODR = 0xFF; // all high except PE4
	PE_DDR = 0xEF; // all outputs except PE4 which is input
	PE_CR1 = 0xEF; // all totem pole except PE4 which is floating
	PE_CR2 = 0x00; // all normal speed except PE4 which has no interrupt


	//----------------------------------------
	// TIMER 1
	//----------------------------------------

    // configure timer prescaler for divide by 16000 operation for a 1 kHz clock
    TIM1_PSCRH = 0x3e;
    TIM1_PSCRL = 0x7f;

    // configure auto reload register to 0x13 to create an update event at 50 Hz
    TIM1_ARRH = 0x00;
    TIM1_ARRL = 0x13;

    // enable timer
    TIM1_CR1 = 0x01;

    // enable timer update event interrupt
    TIM1_IER = 0x01;


	//----------------------------------------
	// TIMER 2 w/ OC1 on ouptut pin PD4
	//----------------------------------------

	TIM2_PSCR = 0x03;		// prescaler = 2^3 = / 8 for 2 MHz from 16 MHz clock
	TIM2_ARRH = 0x9c;		// autoreload register = 40000 for 50 Hz PWM frequency
	TIM2_ARRL = 0x40;		
	TIM2_CCR1H = 0x13;		// channel 1 output campare = 5000 for 12.5% duty cycle = 2.5 ms
	TIM2_CCR1L = 0x88;
	TIM2_CCER1 = 1;			// active high, enable chanel 1 compare mode
	TIM2_CCMR1 = 0x60;		// PWM mode 1, high if counter < CCR1
	TIM2_CR1 = 1;			// enable timer


    // enable global interrupts
    __asm
        rim
    __endasm;

	printf ("\n\r\n\rHello, world!\n\r");

	rxpkt_state = 0;

	// wait one second
	printf ("Waiting one second...\n\r");
	led_timer = 0;
	for (;;) {
		if (flag50) {
			flag50 = 0;
			led_timer++;
			if (led_timer == 50) {
				led_timer = 0;
				break;
			}
		}
	}
	putchar ('\n');
	putchar ('\r');

	// average 64 measurements to determine resting distance
	printf ("Measuring resting distance...\n\r");
	led_timer = 0;
	distances = 0;
	for (;;) {
		if (USART3_SR & USART_SR_RXNE) {
			data = USART3_DR;
			result = GetMeasurement (data);
			if (result) {
				distance = ConvertToDistance ();
				distances += distance;
				led_timer++;
				printf ("%4d ", distance);
				if (led_timer == 64) {
					led_timer = 0;
					restingDistance = distances >> 6;
					break;
				}
			}
		}
	}
	triggerDistance = restingDistance - (restingDistance >> 3); // 87.5 percent
	putchar ('\n');
	putchar ('\r');
	printf ("resting distance = %d millimeters\n\r", restingDistance);
	printf ("trigger distance = %d millimeters\n\r", triggerDistance);

	// main loop
	for (;;) {

		if (USART3_SR & USART_SR_RXNE) {
			data = USART3_DR;
			result = GetMeasurement (data);
			if (result) {
				distance = ConvertToDistance ();
				if ((panic == 0) && (distance <= triggerDistance)) {
					printf ("T: %d\n\r", distance);
					panic = 1;
					panicCount = 0;
					panicPhase = 0;
					clanger_Prepare ();
				}
			}
		}

		if (flag50) {
			flag50 = 0;

			if (led_timer == 0) {
				// turn off user 1 led
				PC_ODR &= ~GPIO_PIN_5;
			} else if (led_timer == 45) {
				// turn on user 1 led
				PC_ODR |= GPIO_PIN_5;
			}
			led_timer++;
			if (led_timer == 50) {
				led_timer = 0;
			}

			if (panic == 0) {
				if (!(PE_IDR & GPIO_PIN_4)) {
					panic = 1;
					panicCount = 0;
					panicPhase = 0;
					clanger_Prepare ();
				}
			} else if (panic == 1) {
				if ((panicCount == 9) && (panicPhase == 15)) {
					panic = 2;
					panicPhase = 0;
					clanger_Relax ();
				} else {
					if (panicPhase < 8) {
						clanger_Strike ();
					} else {
						clanger_Prepare ();
					}
					panicPhase++;
					if (panicPhase == 16) {
						panicPhase = 0;
						panicCount++;
					}
				}
			} else if (panic >= 2) {
				// 2 seconds minimum between triggers
				panicPhase++;
				if (panicPhase == 100) {
					panic = 0;
				}
			}
		}
	}
}


void clanger_Relax (void)
{
	TIM2_CCR1H = 0x13;		// channel 1 output campare = 5000 / 2e6 = 2.5 ms
	TIM2_CCR1L = 0x88;
}

void clanger_Prepare (void)
{
	TIM2_CCR1H = 0x11;		// channel 1 output campare = 5000 / 2e6 = 2.2 ms
	TIM2_CCR1L = 0x30;
}

void clanger_Strike (void)
{
	TIM2_CCR1H = 0x0f;		// channel 1 output campare = 4000 / 2e6 = 2.0 ms
	TIM2_CCR1L = 0xa0;
}


void TIM1_overflow_Handler() __interrupt(11)
{
    // clear interrupt
    TIM1_SR1 &= ~1;

	// set flag
	flag50 = 1;
}


int putchar (int c)
{
	while (!(USART1_SR & USART_SR_TXE));
	USART1_DR = c;
	return (c);
}


uint8_t GetMeasurement (uint8_t data)
{
	if (rxpkt_state == 0) {
		// get start of packet
		if (data == 'R') {
			rxpkt_state = 1;
			rxpkt_count = 0;
		}
	} else {
		// get measurement digit
		if (data == 'R') {
			// start over
			rxpkt_state = 1;
			rxpkt_count = 0;
		} else if ((data < '0') || (data > '9')) {
			// reject non digits and start over from very beginning
			rxpkt_state = 0;
			rxpkt_count = 0;
		} else {
			// write received data to buffer and increment count
			rxpkt_buffer[rxpkt_count++] = data;
			if (rxpkt_count >= 4) {
				rxpkt_state = 0;
				return true;
			}
		}
	}
			
	return false;
}


uint16_t ConvertToDistance (void)
{
	uint8_t i;
	uint16_t d = 0;

	for (i = 0; i < 4; i++) {
		d *= 10;
		d += rxpkt_buffer[i] - '0';
	}
}
