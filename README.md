# MTD Araba Yarışları - 4WD Akıllı Araç Projesi 🚗

Bu proje, Süleyman Demirel Üniversitesi Bilgisayar Mühendisliği Mühendislik Tasarımı (MTD) dersi kapsamında geliştirilmiş 4 tekerlekten çekişli (4WD) akıllı araç projesidir. Proje, yazılım ve donanım entegrasyonunu harmanlayarak iki farklı sürüş modunu desteklemektedir.


## 🌟 Özellikler

Aracımız esnek bir kullanım senaryosu sunmak amacıyla iki farklı modülde programlanmıştır:

- **🕹️ Bluetooth Kontrol Modu:** Mobil cihaz üzerinden Bluetooth bağlantısı kurularak aracın manuel olarak yönlendirilmesini sağlar.
- **🤖 Otonom Sürüş Modu:** Üzerinde bulunan **Ultrasonik Sensör** ve **LDR (Işık) Sensörü** sayesinde çevresini algılar. Engellerden kaçınma ve ışığa duyarlı hareket etme yetenekleriyle tamamen otonom bir sürüş sergiler.

## 📂 Dosya ve Klasör Yapısı

Kodların incelenmesini kolaylaştırmak amacıyla proje, sürüş modlarına göre modüler bir klasör yapısına ayrılmıştır:

    mtd-araba-yarislari/
    ├── bluetooth_mode/
    │   └── bluetooth_car.ino      # Bluetooth kontrollü sürüş kodları
    ├── autonomous_mode/
    │   └── autonomous_car.ino     # Otonom (Sensörlü) sürüş kodları
    └── README.md

## 🛠️ Kullanılan Donanımlar

- 4WD Araç Şasesi ve DC Motorlar
- Motor Sürücü Kartı
- Bluetooth Modülü (HC-05 / HC-06)
- Mesafe Ölçümü için Ultrasonik Sensör
- Işık Algılama için LDR Sensör
- Mikrodenetleyici (Arduino / ESP vb.)

## 👨‍💻 Geliştirici Ekip

Bu proje aşağıdaki ekip tarafından ortaklaşa tasarlanmış ve kodlanmıştır:

- **Emre Türkoğlu** - [GitHub Profili](https://github.com/emlne)
- **Sinem Havan** - [GitHub Profili](https://github.com/sinemhavan)

---
*Not: Bu repo, teorik bilgilerin pratiğe döküldüğü ve takım çalışmasıyla ortaya çıkan bir donanım/yazılım projesinin kaynak kodlarını barındırmaktadır.*
