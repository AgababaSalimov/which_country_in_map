import random 
import string 

def generate_password(length=12, use_letters=True, use_digits=True, use_symbols=True):
    characters = ''
    if use_letters:
        characters += string.ascii_letters
    if use_digits:
        characters += string.digits
    if use_symbols:
        characters += string.punctuation
    if not characters:
        raise ValueError("At least one character type must be selected")
    
    password = ''.join(random.choice(characters) for _ in range(length))
    return password

try:
    password_length = int(input("Enter the desired password length (default is 12): ") or 12)
    include_letters = input("Include letters? (y/n, default is y): ").lower() != 'n'
    include_digits = input("Include digits? (y/n, default is y): ").lower() != 'n'
    include_symbols = input("Include symbols? (y/n, default is y): ").lower() != 'n'

    password = generate_password(password_length, include_letters, include_digits, include_symbols)
    print(f"Generated password: {password}")

except ValueError :
    print("Invalid input. Please enter a valid number for password length.")
