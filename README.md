# 🤖 DỰ ÁN: ROBOT SUMO & MÊ CUNG
**Ngày bắt đầu:** 22/03/2026 
**Vi điều khiển chính:** ESP32 CH340   
**Trọng lượng mục tiêu:** 1.5kg 

---

## 📝 1. Mô tả sơ lược về chức năng Robot
Robot được thiết kế như một nền tảng đa nhiệm, có khả năng chuyển đổi linh hoạt giữa hai chế độ thi đấu chính thông qua hệ thống công tắc điều khiển:

* **Chế độ Giải mê cung:** Sử dụng thuật toán bám tường phải (ưu tiên rẽ phải) kết hợp cùng bộ điều khiển PID để duy trì khoảng cách ổn định, giúp robot di chuyển mượt mà và tránh va chạm liên tục vào tường.
* **Chế độ Đấu Sumo:** Tự động tìm kiếm đối thủ trong phạm vi 70-80cm bằng cảm biến khoảng cách và tấn công với 100% công suất. Robot tích hợp khả năng tự bảo vệ bằng cách nhận diện vạch biên sân qua cảm biến hồng ngoại dưới gầm để tránh bị loại.
* **Hệ thống quản lý nguồn:** Sử dụng bộ pin 4 cell 18650 (14.8V) đi qua mạch hạ áp LM2596 để cung cấp dòng điện 5V ổn định cho ESP32, đảm bảo hệ thống logic không bị treo khi động cơ hoạt động ở cường độ cao.

---

## 🧪 2. Kiểm thử các chức năng Robot (Functional Test Lab)
Để đảm bảo robot vận hành chính xác tại cuộc thi, các module chức năng được kiểm thử độc lập trước khi tích hợp vào logic tổng thể:

### 🏎️ 2.1. Kiểm thử hệ thống Di chuyển & Lực kéo
* **Mục tiêu:** Kiểm tra các lệnh điều khiển cơ bản (Tiến, Lùi, Rẽ, Xoay 180°/360°, Dừng) và xác định thời gian delay tối ưu cho mỗi hành động.
* **Kết quả:** Động cơ GA25-370 kết hợp với mạch cầu L298N đáp ứng tốt các yêu cầu về tốc độ và lực đẩy cần thiết cho robot 1.5kg.
* **Video minh họa:**
    [![Xem Video Test Di Chuyển](https://img.shields.io/badge/VIDEO-TEST_DI_CHUYEN-blue?style=for-the-badge&logo=youtube)](https://drive.google.com/file/d/1gu7C8QK5NKspLqIrIKt5o9WAxRYJ1id6/view?usp=drive_link)

### 🛰️ 2.2. Kiểm thử Thuật toán Giải mê cung (Laser/Siêu âm)
* **Mục tiêu:** Thử nghiệm thứ tự ưu tiên rẽ (Rẽ Phải > Đi Thẳng > Rẽ Trái > Quay đầu) khi gặp vật cản hoặc tường.
* **Kết quả:** Robot nhận diện chính xác các ô trống và tường bao, thực hiện rẽ hướng ngay lập tức khi cảm biến báo trống ở phía ưu tiên.
* **Video minh họa:**
    [![Xem Video Test Mê Cung](https://img.shields.io/badge/VIDEO-TEST_GIAI_ME_CUNG-red?style=for-the-badge&logo=youtube)](https://link-video-cua-ban.com)

### ⚔️ 2.3. Kiểm thử Chế độ Sumo & Phản xạ Biên
* **Mục tiêu:** Kiểm tra logic nhận diện vạch trắng bằng 2 cảm biến hồng ngoại dưới gầm và khả năng xoay tìm đối thủ.
* **Kết quả:** Robot thực hiện dừng và lùi lại ngay khi chạm vạch biên, tự động tăng tốc húc thẳng khi phát hiện vật thể phía trước.
* **Video minh họa:**
    [![Xem Video Test Sumo](https://img.shields.io/badge/VIDEO-TEST_SUMO_STRATEGY-green?style=for-the-badge&logo=youtube)](https://link-video-cua-ban.com)

### ⚡ 2.4. Kiểm thử Chế độ Chờ & Khởi động 5s
* **Mục tiêu:** Xác minh tính năng trì hoãn 5 giây sau khi bật công tắc Start (Nút B) theo đúng luật thi đấu.
* **Kết quả:** Trong thời gian chờ, hệ thống phanh điện tử được kích hoạt để khóa bánh, đồng thời cảm biến hồng ngoại quét liên tục để chống bị đối thủ đẩy lùi.
* **Video minh họa:**
    [![Xem Video Test Chế Độ Chờ](https://img.shields.io/badge/VIDEO-TEST_START_LOGIC-orange?style=for-the-badge&logo=youtube)](https://link-video-cua-ban.com)

---

## 🛠️ 3. Danh sách linh kiện & Sơ đồ đấu nối


### Linh kiện chính:
* **Board mạch:** ESP32 CH340 + Đế ra chân.
* **Động cơ:** 2x Động cơ DC giảm tốc JGA25-370 kèm bánh xe V2 65mm.
* **Cảm biến:** 3x Module VL53L0X (Laser) hoặc HC-SR04 (Siêu âm) + 2x Module hồng ngoại.
* **Nguồn:** 4x Pin sạc 18650 3.7V + Mạch hạ áp LM2596.

### Bảng phân chân (Pinout):
* **Motor Trái (L298N):** ENA (GPIO 13), IN1 (GPIO 12), IN2 (GPIO 14).
* **Motor Phải (L298N):** ENB (GPIO 25), IN3 (GPIO 27), IN4 (GPIO 26).
* **Cảm biến Giữa:** Trig (GPIO 18), Echo (GPIO 19).
* **Điều khiển:** Công tắc Mode (GPIO 4), Nút nhấn Start (GPIO 5).

---
*© 2026 - Dự án Robot Dự thi *
