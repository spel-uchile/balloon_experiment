from gpiozero import *
from time import sleep

#Pines de activacion actuador lineal
enable_lineal = LED(20)
ln_sgnl1 = LED(16)
ln_sgnl2 = LED(7)
#Pin de validacion de posicion del actuador lineal
mag_int1 = Button(4)


#Pines de activacion servo
en_sr_so = LED(24)
srvo_sgnl = LED(23)

#PWM del motor
servo = Servo(18, initial_value=0, min_pulse_width=.544/1000, max_pulse_width=2.4/1000, frame_width=20./1000, pin_factory=None)

#Magneto del servo
mag_int2 = Button(17)


def start():
    enable_lineal.off()
    ln_sgnl1.off()
    ln_sgnl2.off()

    en_sr_so.off()
    srvo_sgnl.off()
    return True

def state():
    lineal_state = mag_int1.is_pressed
    servo_state = mag_int2.is_pressed
    return lineal_state, servo_state

def open_lineal():
    enable_lineal.on()
    ln_sgnl1.on()
    sleep(1)
    return True

def close_lineal():
    enable_lineal.on()
    ln_sgnl2.on()
    sleep(1)
    return True

def servo_0():
    en_sr_so.on()
    srvo_sgnl.on()
    sleep(1)
    servo.min()
    sleep(3)
    return True

def servo_180():
    en_sr_so.on()
    srvo_sgnl.on()
    sleep(1)
    servo.max()
    sleep(3)
    return True

while True:
    strt = start()

    stt1, stt2 = state()
    print("Actuador lineal " + str(int(stt1)))
    print("Servo " + str(int(stt2)))
    print(" ")
    print("Seleccion de acciones")
    print("1 Cerrar actuador lineal")
    print("2 Abrir actuador lineal")
    print("3 Servo en 0")
    print("4 Servo en 180")
    accion = input("Funcion a aplicar ")
    print(" ")

    if accion == 1:
        val = open_lineal()
    elif accion == 2:
        val = close_lineal()
    elif accion == 3:
        val = servo_0()
    elif accion == 4:
        val = servo_180()
    else:
        print("Prueba preguntando de nuevo")
        val = False
    print(val)
    print(" ")
    
