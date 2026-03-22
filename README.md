# 🤖 DỰ ÁN: ROBOT CHIẾN BINH ĐA NĂNG (SUMO & MÊ CUNG)
[cite_start]**Ngày bắt đầu:** 22/03/2026 [cite: 78, 79]  
[cite_start]**Vi điều khiển chính:** ESP32 CH340 [cite: 14]  
[cite_start]**Trọng lượng mục tiêu:** 1.5kg [cite: 79]

---

## 📝 1. Mô tả sơ lược về chức năng Robot
[cite_start]Robot được thiết kế như một nền tảng đa nhiệm, có khả năng chuyển đổi linh hoạt giữa hai chế độ thi đấu chính thông qua hệ thống công tắc điều khiển[cite: 43, 44]:

* [cite_start]**Chế độ Giải mê cung:** Sử dụng thuật toán bám tường phải (ưu tiên rẽ phải) kết hợp cùng bộ điều khiển PID để duy trì khoảng cách ổn định, giúp robot di chuyển mượt mà và tránh va chạm liên tục vào tường[cite: 58, 59].
* [cite_start]**Chế độ Đấu Sumo:** Tự động tìm kiếm đối thủ trong phạm vi 70-80cm bằng cảm biến khoảng cách và tấn công với 100% công suất[cite: 74, 75]. [cite_start]Robot tích hợp khả năng tự bảo vệ bằng cách nhận diện vạch biên sân qua cảm biến hồng ngoại dưới gầm để tránh bị loại[cite: 70, 71].
* [cite_start]**Hệ thống quản lý nguồn:** Sử dụng bộ pin 4 cell 18650 (14.8V) đi qua mạch hạ áp LM2596 để cung cấp dòng điện 5V ổn định cho ESP32, đảm bảo hệ thống logic không bị treo khi động cơ hoạt động ở cường độ cao[cite: 18, 19, 21].

---

## 🧪 2. Kiểm thử các chức năng Robot (Functional Test Lab)
[cite_start]Để đảm bảo robot vận hành chính xác tại cuộc thi, các module chức năng được kiểm thử độc lập trước khi tích hợp vào logic tổng thể[cite: 79]:

### 🏎️ 2.1. Kiểm thử hệ thống Di chuyển & Lực kéo
* [cite_start]**Mục tiêu:** Kiểm tra các lệnh điều khiển cơ bản (Tiến, Lùi, Rẽ, Xoay 180°/360°, Dừng) và xác định thời gian delay tối ưu cho mỗi hành động[cite: 34, 41].
* [cite_start]**Kết quả:** Động cơ GA25-370 kết hợp với mạch cầu L298N đáp ứng tốt các yêu cầu về tốc độ và lực đẩy cần thiết cho robot 1.5kg[cite: 14, 24].
* **Video minh họa:**
    [![Xem Video Test Di Chuyển](https://img.shields.io/badge/VIDEO-TEST_DI_CHUYEN-blue?style=for-the-badge&logo=youtube)](https://drive.google.com/file/d/1gu7C8QK5NKspLqIrIKt5o9WAxRYJ1id6/view?usp=drive_link)

### 🛰️ 2.2. Kiểm thử Thuật toán Giải mê cung (Laser/Siêu âm)
* [cite_start]**Mục tiêu:** Thử nghiệm thứ tự ưu tiên rẽ (Rẽ Phải > Đi Thẳng > Rẽ Trái > Quay đầu) khi gặp vật cản hoặc tường[cite: 60, 62, 63, 64, 65].
* [cite_start]**Kết quả:** Robot nhận diện chính xác các ô trống và tường bao, thực hiện rẽ hướng ngay lập tức khi cảm biến báo trống ở phía ưu tiên[cite: 62].
* **Video minh họa:**
    [![Xem Video Test Mê Cung](https://img.shields.io/badge/VIDEO-TEST_GIAI_ME_CUNG-red?style=for-the-badge&logo=youtube)](https://link-video-cua-ban.com)

### ⚔️ 2.3. Kiểm thử Chế độ Sumo & Phản xạ Biên
* [cite_start]**Mục tiêu:** Kiểm tra logic nhận diện vạch trắng bằng 2 cảm biến hồng ngoại dưới gầm và khả năng xoay tìm đối thủ[cite: 70, 72, 73].
* [cite_start]**Kết quả:** Robot thực hiện dừng và lùi lại ngay khi chạm vạch biên, tự động tăng tốc húc thẳng khi phát hiện vật thể phía trước[cite: 71, 75].
* **Video minh họa:**
    [![Xem Video Test Sumo](https://img.shields.io/badge/VIDEO-TEST_SUMO_STRATEGY-green?style=for-the-badge&logo=youtube)](https://link-video-cua-ban.com)

### ⚡ 2.4. Kiểm thử Chế độ Chờ & Khởi động 5s
* [cite_start]**Mục tiêu:** Xác minh tính năng trì hoãn 5 giây sau khi bật công tắc Start (Nút B) theo đúng luật thi đấu[cite: 48, 49, 54].
* [cite_start]**Kết quả:** Trong thời gian chờ, hệ thống phanh điện tử được kích hoạt để khóa bánh, đồng thời cảm biến hồng ngoại quét liên tục để chống bị đối thủ đẩy lùi[cite: 51, 52].
* **Video minh họa:**
    [![Xem Video Test Chế Độ Chờ](https://img.shields.io/badge/VIDEO-TEST_START_LOGIC-orange?style=for-the-badge&logo=youtube)](https://link-video-cua-ban.com)

---

## 🛠️ 3. Danh sách linh kiện & Sơ đồ đấu nối


### [cite_start]Linh kiện chính[cite: 14]:
* **Board mạch:** ESP32 CH340 + Đế ra chân.
* **Động cơ:** 2x Động cơ DC giảm tốc JGA25-370 kèm bánh xe V2 65mm.
* **Cảm biến:** 3x Module VL53L0X (Laser) hoặc HC-SR04 (Siêu âm) + 2x Module hồng ngoại.
* **Nguồn:** 4x Pin sạc 18650 3.7V + Mạch hạ áp LM2596.

### [cite_start]Bảng phân chân (Pinout)[cite: 24, 28, 30]:
* **Motor Trái (L298N):** ENA (GPIO 13), IN1 (GPIO 12), IN2 (GPIO 14).
* **Motor Phải (L298N):** ENB (GPIO 25), IN3 (GPIO 27), IN4 (GPIO 26).
* **Cảm biến Giữa:** Trig (GPIO 18), Echo (GPIO 19).
* **Điều khiển:** Công tắc Mode (GPIO 4), Nút nhấn Start (GPIO 5).

---
*© 2026 - Dự án Robot Dự thi [Tên Cuộc Thi]*
