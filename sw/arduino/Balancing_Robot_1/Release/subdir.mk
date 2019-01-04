################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
INO_SRCS += \
..\Balancing_Robot_1.ino 

CPP_SRCS += \
..\Balancer.cpp \
..\Motor.cpp \
..\PidController.cpp \
..\SpeedController.cpp \
..\sloeber.ino.cpp 

LINK_OBJ += \
.\Balancer.cpp.o \
.\Motor.cpp.o \
.\PidController.cpp.o \
.\SpeedController.cpp.o \
.\sloeber.ino.cpp.o 

INO_DEPS += \
.\Balancing_Robot_1.ino.d 

CPP_DEPS += \
.\Balancer.cpp.d \
.\Motor.cpp.d \
.\PidController.cpp.d \
.\SpeedController.cpp.d \
.\sloeber.ino.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
Balancer.cpp.o: ..\Balancer.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\""  -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\leonardo" -I"C:\Users\Martin\Arduino\libraries\I2Cdev" -I"C:\Users\Martin\Arduino\libraries\MPU6050" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Balancing_Robot_1.o: ..\Balancing_Robot_1.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\""  -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\leonardo" -I"C:\Users\Martin\Arduino\libraries\I2Cdev" -I"C:\Users\Martin\Arduino\libraries\MPU6050" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

Motor.cpp.o: ..\Motor.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\""  -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\leonardo" -I"C:\Users\Martin\Arduino\libraries\I2Cdev" -I"C:\Users\Martin\Arduino\libraries\MPU6050" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

PidController.cpp.o: ..\PidController.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\""  -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\leonardo" -I"C:\Users\Martin\Arduino\libraries\I2Cdev" -I"C:\Users\Martin\Arduino\libraries\MPU6050" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

SpeedController.cpp.o: ..\SpeedController.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\""  -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\leonardo" -I"C:\Users\Martin\Arduino\libraries\I2Cdev" -I"C:\Users\Martin\Arduino\libraries\MPU6050" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

sloeber.ino.cpp.o: ..\sloeber.ino.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\sloeber\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_LEONARDO -DARDUINO_ARCH_AVR -DUSB_VID=0x2341 -DUSB_PID=0x8036 "-DUSB_MANUFACTURER=\"Unknown\"" "-DUSB_PRODUCT=\"Arduino Leonardo\""  -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\leonardo" -I"C:\Users\Martin\Arduino\libraries\I2Cdev" -I"C:\Users\Martin\Arduino\libraries\MPU6050" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire" -I"C:\sloeber\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\libraries\Wire\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


