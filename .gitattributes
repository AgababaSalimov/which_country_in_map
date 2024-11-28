import pyfiglet
from termcolor import colored

text=input("Enter the text you want to format : ")
font=input("Enter the font you want to use (press Enter for default) : ")
color=input("Enter the color you want (e.g.,red, green, yellow ) : ")

if font:
    formatted_text=pyfiglet.figlet_format(text, font=font)
else:
    formatted_text=pyfiglet.figlet_format(text)

if color:
    colored_text=colored(formatted_text,color)
    print(colored_text)
else:
    print(formatted_text)
    
