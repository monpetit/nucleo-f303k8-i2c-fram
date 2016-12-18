# nucleo-f303k8-i2c-fram
STM32Cube I2C Communication Example
EEPROM을 대체할 수 있는 FRAM Storage 사용 예제 (3.3V 전용)

# 개발환경
 - Keil MDK ARM	5.22a
 - STM32CubeMX 4.18.0
 - STM32CubeF3 Firmware Package V1.6.0 / 01-July-2016

# 하드웨어
 - STM32 Nucleo-F303k8
 - FM24CL64BGA (8KB, I2C FRAM)

# 결선
 NUCLEO F303K8             FM24CL64BGA
     GND                      1 (A0)
     GND                      2 (A1)
     GND                      3 (A2)
     GND                      4 (VSS/GND)
     D4                       5 (SDA)
     D5                       6 (SCL)
     GND                      7 (WP)
     3V3                      8 (VDD/VCC)
 - D4/D5는 3V3과 4.7 ㏀ 저항으로 연결 (pull-up)

# 소프트웨어 설정
 - UART통신: UART2 (USB VCOM), Baud rate - 38400
 - I2C통신: Fast plus mode (1 ㎒)
 - Timer7: Up mode (1초 주기)
