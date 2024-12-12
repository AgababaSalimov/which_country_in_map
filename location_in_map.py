import folium

# Bakü konumu
latitude = 40.4093
longitude = 49.8671

# Haritayı oluştur
m = folium.Map(location=[latitude, longitude], zoom_start=13)

# Marker ekle
folium.CircleMarker(
    location=[latitude, longitude],
    radius=10,
    popup="Bakü",
    color="green",
    fill=True,
    fill_color="green",
).add_to(m)

# Haritayı kaydet
m.save("baku_map.html")
print("Harita 'baku_map.html' olarak kaydedildi.")
