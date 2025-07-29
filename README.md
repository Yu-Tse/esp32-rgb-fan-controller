# 🌈 ESP32 RGB Fan Controller

This project uses an **ESP32** to:
- Control a DC fan using PWM (GPIO15)
- Display RGB effects (rainbow, static color) on WS2812B strip (GPIO14)

## 🛠 Hardware Setup

| Component       | Description                     |
|----------------|---------------------------------|
| ESP32           | Microcontroller board           |
| WS2812B LEDs    | RGB strip (16 LEDs)             |
| DC Fan (PWM)    | Controlled via GPIO15           |
| Power Supply    | As required by fan and LEDs     |

## ⚙ Software

- Written in Arduino C++
- Uses [FastLED library](https://github.com/FastLED/FastLED)

## 🔧 Setup

1. Install **FastLED** via Arduino Library Manager
2. Connect LEDs to **GPIO14**, Fan to **GPIO15**
3. Upload `rgb_fan.ino` to ESP32
4. Open Serial Monitor to view status

## 🔒 License

This project is licensed under the MIT License.

## 🙋‍♂️ Author

**Yu-Tse Wu** (吳雨澤)  
*Master’s Student at the Institute of Innovation and Semiconductor Manufacturing, National Sun Yat-sen University*

GitHub: [@Yu-Tse](https://github.com/Yu-Tse)
