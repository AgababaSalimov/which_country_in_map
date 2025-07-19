import folium
import webbrowser

# Harita oluştur
m = folium.Map(location=[40.4093, 49.8671], zoom_start=12)

# HTML dosyasına kaydet
file_path = "map.html"
m.save(file_path)

# Tarayıcıda otomatik aç
webbrowser.open(file_path)
