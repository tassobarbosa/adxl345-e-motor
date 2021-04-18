// ADXL345  Registers
#define W_DATA      0xA6    //Used to perform a Write operation
#define R_DATA      0xA7    //Used to perform a Read operation
#define D_FRM       0x31    //Read/Write Register, Selects the operating mode. Default = Single measurement
#define BW_RT       0x2C
#define P_CTL       0x2D    //Send continuous Measurement mode.
#define F_CTL       0x38    //Send Fifo Bypass mode
#define X_LSB       0x32    //Read Register, Output of X LSB 8-bit value.
#define X_MSB       0x33    //Read Register, Output of X MSB 8-bit value.
#define Y_LSB       0x34    //Read Register, Output of Z LSB 8-bit value.
#define Y_MSB       0x35    //Read Register, Output of Z MSB 8-bit value.
#define Z_LSB       0x36    //Read Register, Output of Y LSB 8-bit value.
#define Z_MSB       0x37    //Read Register, Output of Y MSB 8-bit value.
 
void adxl345_write(int add, int data)
{
         i2c_start();
         i2c_write(W_DATA);
         i2c_write(add);
         i2c_write(data);
         i2c_stop();
 
}
      
int adxl345_read(int add){
         int retval;
         i2c_start();
         i2c_write(W_DATA);
         i2c_write(add);
         i2c_start();
         i2c_write(R_DATA);
         retval=i2c_read(0);
         i2c_stop();
         return retval;
}
 
void adxl345_init(){
         adxl345_write(D_FRM,0x0B);
         delay_ms(2);
         adxl345_write(P_CTL,0x08);
         delay_ms(2);
}