import tkinter as tk


RESPONSES = {
    "nasılsın": "İyiyim, teşekkürler! Senin günün nasıl geçiyor?",
    "merhaba": "Selam! Ne konuşmak istersin?",
    "selam": "Aleyküm selam! Size nasıl yardımcı olabilirim?",
    "adın ne": "Ben basit bir kural tabanlı sohbet botuyum.",
    "kimsin": "Ben basit bir kural tabanlı sohbet botuyum.",
    "saat kaç": "Şu anda saate bakamıyorum, ama sohbet etmek için buradayım.",
    "güle güle": "Hoşça kal! Tekrar görüşmek üzere.",
    "hoşça kal": "Güle güle! Kendine iyi bak."
}

def respond():
    txt = entry.get()
   
    clean_txt = txt.strip().lower() 
    
    bot_response = ""

   
    found_key = None
    for key_word, response in RESPONSES.items():
        if key_word in clean_txt:
            found_key = key_word
            bot_response = response
            break 
    
   
    if found_key is None:
        bot_response = "Bu cümleyi anlayamadım. Lütfen daha basit bir ifade kullanın." 

    
    chat.insert(tk.END, "You: " + txt + "\n")
    chat.insert(tk.END, "Bot: " + bot_response + "\n\n")

  
    entry.delete(0, tk.END)


root = tk.Tk()
root.title("Sözlük Tabanlı Bot")
chat=tk.Text(root, width=40, height=15)
chat.pack(padx=10, pady=10)
entry=tk.Entry(root, width=40)
entry.pack(padx=10, pady=(0, 5))
tk.Button(root, text="Send", command=respond).pack(pady=(0, 10))
root.mainloop()
