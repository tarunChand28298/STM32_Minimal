#define PORTC_ODR   ((unsigned int*)0x4001100C)
#define GPIOC_CHR   ((unsigned int*)0x40011004)
#define RCC_APB2ENR ((unsigned int*)0x40021018)

void delay(unsigned int cycles)
{
    for(; cycles > 0; cycles--)
    {
        __asm("nop");
    }
}

int main()
{
    *RCC_APB2ENR = (0b000000000000000000000000010000);
    *GPIOC_CHR   = (0b000000001100000000000000000000);
    
    while (1)
    {
        *PORTC_ODR ^= (0b000000000000000010000000000000);
        delay(1000000);
    }
    
    return 0;
}
