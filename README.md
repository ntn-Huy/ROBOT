# 🤖 ESP32 High-Torque Robot Ecosystem (1.5kg Class)

![Status](https://img.shields.io/badge/Status-In--Development-yellow)
![Platform](https://img.shields.io/badge/Platform-ESP32-blue)
![Framework](https://img.shields.io/badge/Framework-Arduino-orange)
![License](https://img.shields.io/badge/License-MIT-green)

## 📌 1. Giới thiệu Tổng quan (Main Project)
Dự án tập trung vào việc xây dựng hệ thống Robot tự hành thông minh tải trọng lớn (**1.5kg**) sử dụng vi điều khiển **ESP32**. Hệ thống được thiết kế để tối ưu hóa lực kéo cho động cơ kim loại GA25 thông qua các thuật toán điều khiển xung PWM tần số thấp.

### 🎯 Mục tiêu dự án:
* **Tối ưu công suất:** Xử lý vấn đề sụt áp trên L298N để robot chạy khỏe nhất với Pin 2S/3S.
* **Chính xác cao:** Thay thế cảm biến siêu âm bằng công nghệ **Laser ToF (Time of Flight)**.
* **Mở rộng:** Phát triển các "Robot Module" để thử nghiệm từng tính năng đơn lẻ.

---

## 🏗️ 2. Các Dự án Thành phần (Sub-Robots)
Trong quá trình hoàn thiện, dự án được chia thành các phiên bản nhỏ để tối ưu hóa code:

| Robot Module | Chức năng chính | Trạng thái |
| :--- | :--- | :--- |
| **🏎️ Basic Motion** | Tiến, lùi, phanh cứng, quay 90 độ | **Hoàn thành** |
| **🛡️ Laser Avoider** | Tự động né vật cản bằng cảm biến Laser | **Đang nạp code** |
| **📡 Data Logger** | Gửi trạng thái "Đi thẳng/Quẹo" lên Laptop | **Hoàn thành** |

---

## 📺 3. Video Demo & Hình ảnh
> *Nhấn vào hình dưới đây để xem Video quá trình Robot hoạt động:*

[![Xem Video Robot](https://img.shields.io/badge/VIDEO-XEM_DEMO_TAI_DAY-red?style=for-the-badge&logo=youtube)](https://link-video-cua-ban.com)

*Hình ảnh thực tế dự án:*
![Robot Chassis 1.5kg](https://via.placeholder.com/600x300.png?text=Chen+Anh+Robot+Cua+Ban+Vao+Day)

---

## 🛠️ 4. Sơ đồ Đấu nối (Hardware)

### Cấu hình chân ESP32:
* **Động cơ Trái:** `IN1: 12`, `IN2: 14`, `ENA: 13`
* **Động cơ Phải:** `IN3: 27`, `IN4: 26`, `ENB: 25`
* **Cảm biến Laser:** `SDA: 21`, `SCL: 22` (Giao tiếp I2C)

### Thông số nguồn điện:
* **Pin:** Lithium 18650 (7.4V - 11.1V).
* **Driver:** L298N (Cắm Jumper 5V để nuôi chip logic).

---


## ⚠️ 6. Nhật ký Xử lý Sự cố (Troubleshooting)
* **Robot yếu/Chậm:** Đã tăng PWM lên 255 và hạ tần số xuống 1000Hz để tăng Torque.
* **Lỗi GDB Server:** Khắc phục bằng cách sử dụng cổng Upload Serial thay vì trình Debug JTAG.
* **Quay 90 độ lệch:** Cân chỉnh lại `delay()` dựa trên ma sát của mặt sàn thực tế.

---

## Ngày bắt đầu:** 22/03/2026

---
*© 2026 - Dự án Robot ESP32 mã nguồn mở*
