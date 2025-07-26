#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD I2C di alamat 0x27 dengan ukuran 16x2
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Daftar lirik yang akan ditampilkan di LCD
const char* daftarLirik[] = {
  "Tanteee",
  "Sudah Terbiasa",
  "Terjadi Tante",
  "Teman Datang",
  "Ketika Lagi",
  "Butuh Sajaaa",
  "Coba Kalo",
  "Lagi Susahh",
  "Mereka Semua",
  "Menghilaaangg",
  "aangggg",
  "aangggg",
  "Tante",
  "eee",
  "eee",
};

// Variabel untuk melacak indeks lirik saat ini
int indeksLirikSaatIni = 0;

// Hitung jumlah lirik
const int jumlahLirik = sizeof(daftarLirik) / sizeof(daftarLirik[0]);

void setup() {
  lcd.init();       // Inisialisasi LCD
  lcd.backlight();  // Nyalakan backlight LCD
}

void loop() {
  lcd.clear();                         // Bersihkan LCD
  lcd.setCursor(0, 0);                 // Kursor ke kolom 0, baris 0
  lcd.print(daftarLirik[indeksLirikSaatIni]);  // Tampilkan lirik
  indeksLirikSaatIni++;                // Lirik berikutnya
  if (indeksLirikSaatIni >= jumlahLirik) {
    indeksLirikSaatIni = 0;            // Kembali ke awal
  }
  delay(1500);                         // Jeda 1,35 detik
}
