#include <FastLED.h>

#define RGB_PIN    14    // 連接 RGB 控制引腳的 GPIO 編號
#define NUM_LEDS   16    // 風扇上 RGB LED 的數量
#define BRIGHTNESS 200   // 設定亮度
#define LED_TYPE   WS2812B // LED 類型 (你可能需要根據你的風扇調整)
#define COLOR_ORDER GRB   // 顏色順序

CRGB leds[NUM_LEDS];     // 定義 LED 陣列


const int fanPin = 15;  // ESP32的PWM引腳
const int pwmFreq = 5000;  // 設定PWM頻率
const int pwmChannel = 0;  // 設定PWM通道
const int pwmResolution = 8;  // 設定PWM解析度 (0-255)

int dutyCycle = 0;
int increment = 1;


void setup() {
  // 設置PWM頻率、通道和解析度
  Serial.begin(115200);
  // 初始化 FastLED
  
  FastLED.addLeds<LED_TYPE, RGB_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);


  // 將指定引腳與PWM通道連接
  pinMode(fanPin, OUTPUT);  // 設定引腳模式為輸出
}

void loop() {
  // 呼叫不同的 RGB 燈效函數
  rainbowCycle(5);       // 彩虹循環效果
  
  // 設定風扇速度的占空比
  analogWrite(pwmChannel, dutyCycle);
  
  // 每次迴圈調整占空比，讓風扇速度增加或減少
  dutyCycle += increment;

  // 當占空比達到最大或最小值時，改變方向
  if (dutyCycle <= 0 || dutyCycle >= 255) {
    increment = -increment;
  }

  // 調整速度變化的快慢
  delay(500);
}

// 設置單一顏色
void setStaticColor(CRGB color) {
  fill_solid(leds, NUM_LEDS, color);  // 設置為單一顏色
  FastLED.show();
}

// 彩虹效果函數
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;
  
  for(j=0; j<256*5; j++) { // 5 週期的彩虹
    for(i=0; i<NUM_LEDS; i++) {
      leds[i] = Wheel(((i * 256 / NUM_LEDS) + j) & 255);
    }
    FastLED.show();
    delay(wait);
  }
  
}

// 色盤函數，計算不同色調的顏色
CRGB Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return CRGB(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
    return CRGB(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
    WheelPos -= 170;
    return CRGB(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}
