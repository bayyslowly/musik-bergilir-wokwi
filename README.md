# 🎵 Arduino LCD Lirik Otomatis (Wokwi)

Proyek ini menampilkan **teks atau lirik secara otomatis** menggunakan **Arduino UNO** dan **LCD 16x2 I2C**. Setiap baris teks akan muncul satu per satu dalam jeda waktu tertentu, seperti efek karaoke sederhana. Simulasi ini dibangun menggunakan [Wokwi Arduino Simulator](https://wokwi.com).

---

## 📸 Demo Gambar

![Simulasi LCD Wokwi](https://user-images.githubusercontent.com/your-image.png) <!-- Ganti dengan screenshot nanti -->

---

## ⚙️ Komponen yang Digunakan

- 🧠 Arduino UNO  
- 💬 LCD 16x2 I2C (alamat default: `0x27`)  
- 🔌 Kabel jumper  
- 🧪 Software: [Wokwi Simulator](https://wokwi.com/)

---

## 🔌 Wiring LCD I2C ke Arduino UNO

| LCD I2C Pin | Arduino Pin | Warna Kabel |
|-------------|-------------|-------------|
| GND         | GND         | Hitam       |
| VCC         | 5V          | Merah       |
| SDA         | A4          | Hijau       |
| SCL         | A5          | Kuning      |

---

## 💻 Kode Program

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const char* daftarLirik[] = {
  "Tanteee", "Sudah Terbiasa", "Terjadi Tante",
  "Teman Datang", "Ketika Lagi", "Butuh Sajaaa",
  "Coba Kalo", "Lagi Susahh", "Mereka Semua",
  "Menghilaaangg", "aangggg", "aangggg",
  "Tante", "eee", "eee"
};

int indeksLirikSaatIni = 0;
const int jumlahLirik = sizeof(daftarLirik) / sizeof(daftarLirik[0]);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(daftarLirik[indeksLirikSaatIni]);
  indeksLirikSaatIni++;
  if (indeksLirikSaatIni >= jumlahLirik) {
    indeksLirikSaatIni = 0;
  }
  delay(1350);
}
