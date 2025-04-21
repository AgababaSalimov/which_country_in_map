import pyttsx3
import time
import keyboard  # Klavye olaylarını dinlemek için

# Ses motorunu başlat
engine = pyttsx3.init()
engine.setProperty('rate', 150)

print("Sayılar okunuyor... Çıkmak için istediğin anda 'q' tuşuna bas.")

# 1'den 211'e kadar sayıları sırayla oku
for i in range(1, 212):
    if keyboard.is_pressed('q'):
        print("Program durduruldu.")
        break

    engine.say(str(i))
    engine.runAndWait()
    time.sleep(0.1)
