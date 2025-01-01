def decimal_to_roman(decimal):
    roman_numarals = [
        (1000, 'M'), (900, 'CM'), (500, 'D'), (400, 'CD'),
        (100, 'C'), (90, 'XC'), (50, 'L'), (40, 'XL'),
        (10, 'X'), (9, 'IX'), (5, 'V'), (4, 'IV'),
        (1, 'I')    
    ]
    roman = ""
    for value, numeral in roman_numarals:
        while decimal >= value:
            roman += numeral
            decimal -= value
    return roman

decimal_number=int(input("Enter the decimal number: "))
roman_number=decimal_to_roman(decimal_number)
print(f"Decimal number {decimal_number} is {roman_number} in Roman numerals")

