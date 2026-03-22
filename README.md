# 🏆 TÊN DỰ ÁN: HỆ THỐNG ROBOT TỰ HÀNH TẢI TRỌNG LỚN (1.5KG)
**Ngày bắt đầu:** 1/03/2026  
**Nền tảng:** ESP32 Core 3.x | L298N Driver | Laser ToF Sensor

---

## 📝 1. Mô tả sơ lược về chức năng Robot
Robot được thiết kế với mục tiêu vận hành ổn định trong môi trường có vật cản với tải trọng khung gầm lên đến **1.5kg**. Các chức năng chính bao gồm:
* **Hệ thống truyền động mạnh mẽ:** Sử dụng 02 động cơ kim loại GA25 kết hợp thuật toán PWM tần số thấp (1000Hz) để tối ưu mô-men xoắn, giúp xe không bị khựng khi chở nặng.
* **Cảm biến Laser thông minh:** Thay thế cảm biến siêu âm bằng công nghệ Laser ToF (VL53L0X) để đo khoảng cách chính xác đến từng mm, hoạt động tốt trong nhiều điều kiện ánh sáng và bề mặt vật liệu.
* **Xử lý logic đa nhiệm:** ESP32 điều khiển đồng thời việc quét vật cản và điều chỉnh tốc độ bánh xe để thực hiện các cú rẽ 90 độ chính xác.

---

## 🧪 2. Kiểm thử các chức năng Robot (Functional Test Lab)
Dưới đây là danh sách các bài kiểm tra chức năng riêng biệt được thực hiện để đảm bảo tính ổn định trước khi tích hợp vào dự án chính:

### ⚙️ 2.1. Test Hệ thống Di chuyển & Lực kéo (Motion & Torque Test)
* **Mục tiêu:** Kiểm tra khả năng gánh tải 1.5kg trên mặt sàn gạch và gỗ. Xác định mức PWM tối thiểu để thắng ma sát.
* **Kết quả:** Đạt hiệu suất cao nhất ở PWM 255, dòng điện ổn định, không xảy ra hiện tượng sụt áp logic.
* **Video minh họa:**
  [![Xem Video Test Di Chuyển](https://img.shields.io/badge/VIDEO-TEST_DI_CHUYEN-blue?style=for-the-badge&logo=youtube)](https://link-video-test-1.com)

### 🔦 2.2. Test Cảm biến Laser ToF (Laser Distance Test)
* **Mục tiêu:** Kiểm tra độ nhạy của cảm biến Laser khi gặp các vật cản màu tối hoặc bề mặt bóng.
* **Kết quả:** Cảm biến phản hồi nhanh (<30ms), độ chính xác cao giúp robot dừng đúng khoảng cách an toàn 25cm.
* **Video minh họa:**
  [![Xem Video Test Laser](https://img.shields.io/badge/VIDEO-TEST_LASER_ToF-red?style=for-the-badge&logo=youtube)](https://link-video-test-2.com)

### 🔄 2.3. Test Thuật toán Quay 90 độ (Turning Precision Test)
* **Mục tiêu:** Cân chỉnh thời gian `delay()` và tốc độ nghịch đảo 2 bánh để robot quay đúng góc vuông.
* **Kết quả:** Tìm ra thông số tối ưu cho sàn nhà thực tế, robot quay ổn định không bị trượt quán tính.
* **Video minh họa:**
  [![Xem Video Test Quay](https://img.shields.io/badge/VIDEO-TEST_QUAY_90_DO-green?style=for-the-badge&logo=youtube)](https://link-video-test-3.com)

### 📊 2.4. Test Giám sát Trạng thái (Telemetry Serial Test)
* **Mục tiêu:** Kiểm tra việc gửi dữ liệu từ ESP32 lên Laptop qua Serial Monitor để theo dõi logic điều khiển.
* **Kết quả:** Hiển thị chính xác các trạng thái: "Tiến", "Phát hiện vật cản", "Đang rẽ" theo thời gian thực.
* **Video minh họa:**
  [![Xem Video Test Serial](https://img.shields.io/badge/VIDEO-TEST_SERIAL_MONITOR-orange?style=for-the-badge&logo=youtube)](https://link-video-test-4.com)

---

## 🛠️ 3. Thông số Kỹ thuật & Sơ đồ
* **Vi điều khiển:** ESP32 Dev Kit V1.
* **Nguồn:** Pin Li-ion 2S 7.4V (Sụt áp qua L298N còn ~5.9V).
* **Driver:** L298N (Cấp nguồn 12V cho motor, 5V cho logic).

---
*Người thực hiện: [Tên của bạn]*
