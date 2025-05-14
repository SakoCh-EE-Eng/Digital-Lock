# Digital-Lock
Digital Lock for ECE 425

**HardWare Used**

_Edubase-V2 with Tiva/MSP432 LaunchPads:_

https://trainer4edu.com/edubase_v2/ti_arm_tiva_msp432_launchpad.html

![image](https://github.com/user-attachments/assets/e6c82c41-402c-4e73-bac4-122b4e9607f2)


_PMOD Button Module:_

https://digilent.com/reference/pmod/pmodbtn/start?srsltid=AfmBOooNkLyy-8R825nFwZN1EQWM-f3Aw0X_92P3BpoEUs-dBGys32hP

![image](https://github.com/user-attachments/assets/2b6f111d-b0ba-41cf-927a-4ca2cc70396a)

**Software Used**

Keil uVision 5

**Objective**

Create a digital lock utilizing multiple components from the lab. A four digit password will be made in code and using the PMOD buttons the password will need to be input by the user. The four seven segment display modules will be used, one for each digit. The Edubase board LEDs will light green if the digit is correct and will stay red if not correct. Once all digits are set correctly, the RGB LED will flash green.  


**Background and Methodology:**

The concepts applied will include setting up GPIOs, Systick Timer to create delays, SPI to set up the seven segment displays, and utilizing multiple components of the EduBase Board. Expected to be able to set a password in code and utilize the PMOD button to put the right 4 digit password on the seven segment display
The algorithm will be simple and may utilize enums, switch case statements, and if else statements. I am hoping if time allows, I want to utilize UART to request the user to input a password and ask if the user wants to use a prewritten password to try and guess it, however this is unlikely I will pursue this due to time constraints and will use most of my time setting up and understanding SPI more. 
Hard will use GPIOs for the PMOD buttons, will utilize all four seven segments displays, EduBase Board leds will signify if it is right and the RGB led will let you know when it is unlocked.

**Block Diagram:**

![image](https://github.com/user-attachments/assets/27c66dd6-5801-48e2-9dd4-837731a03eb9)


**Pinout Plan:**

![image](https://github.com/user-attachments/assets/fc658cb4-96b3-4cd1-bd96-444f7d698fb6)

![image](https://github.com/user-attachments/assets/74a984b3-aecc-46a4-a24d-3d44d202fc0e)

**Video Demo**

https://youtube.com/shorts/5dnvOrmkbbA?si=8qXyWwAXCPlF2c9Y






