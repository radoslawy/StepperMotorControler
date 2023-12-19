import machine
import utime
#ustawiam piny
led_pin = machine.Pin(25, machine.Pin.OUT) # pin że coś się dzieje
#-----------------------------------
STEP = machine.Pin(1, machine.Pin.OUT)
DIR = machine.Pin(2, machine.Pin.OUT)
#ustawienie wielkosci kroku
MODE0 = machine.Pin(3, machine.Pin.OUT)
MODE1 = machine.Pin(4, machine.Pin.OUT)
MODE2 = machine.Pin(5, machine.Pin.OUT)
#flagi rozmiaru kroku
a = 1 # 1-cały 2-1/2 4-1/4 8-1/8 16-1/16 32-1/32

#logika--------------------------------
    #funkcja ustawia wielkość kroku
def ustaw_krok(krok):
    if krok == 1:
        MODE0.value(0)
        MODE1.value(0)
        MODE2.value(0)
    elif krok == 2:
        MODE0.value(1)
        MODE1.value(0)
        MODE2.value(0)
    elif krok == 4:
        MODE0.value(0)
        MODE1.value(1)
        MODE2.value(0)
    elif krok == 8:
        MODE0.value(1)
        MODE1.value(1)
        MODE2.value(0)
    elif krok == 16:
        MODE0.value(0)
        MODE1.value(0)
        MODE2.value(1)
    elif krok == 32:
        MODE0.value(0)
        MODE1.value(1)
        MODE2.value(1)

#Setup-----------
Dir.value(1)
ustaw_krok(1) # nwm czy nie trzeba ustawić na początku pinów
led_pin.value(1)#coś się dzieje

"""Połączenie z komputerem przez usb
i tutaj trzeba jakoś to zrobić"""

