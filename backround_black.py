from rembg import remove
from PIL import Image

# Giriş ve çıkış yolları
input_path = "C:\\Users\\AğaBaba\\OneDrive\\Masaüstü\\WhatsApp Görsel 2024-02-27 saat 21.13.02_f2e18802.jpg"
output_path = 'output.png'

# Görseli yükle ve arka planı kaldır
inp = Image.open(input_path)
removed = remove(inp)  # Şeffaf arka planlı RGBA çıktı

# Yeni siyah zemin oluştur
bg = Image.new("RGBA", removed.size, (0, 0, 0, 255))  # Siyah zemin (RGB:0,0,0)

# Şeffaf görüntüyü siyah arka plana yapıştır
bg.paste(removed, (0, 0), removed)

# İstersen RGB olarak da kaydedebilirsin:
bg.convert("RGB").save(output_path)

# Sonucu göster (opsiyonel)
bg.show()
