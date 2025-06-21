char uart_rd, texto[7];
long int adc_rd = 0;

void main() {
  ADCON0 = 1;
  ADCON1 = 14;

  UART1_Init(9600);               // Initialize UART module at 9600 bps
  Delay_ms(100);                  // Wait for UART module to stabilize

  UART1_Write_Text("Start");
  UART1_Write(10);
  UART1_Write(13);

  while (1) {                     // Endless loop

      adc_rd = ADC_Read(0);
      adc_rd = adc_rd*0.48875;
      
      IntToStr(adc_rd,texto);
      
      UART1_Write_Text(texto);
      UART1_Write_Text(" Celsius");
      UART1_Write(10);
      UART1_Write(13);
      delay_ms(600);


  }
}

