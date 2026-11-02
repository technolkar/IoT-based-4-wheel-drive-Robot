<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:1A1A2E,100:E94560&height=200&section=header&text=IoT%204WD%20Robot%20Car&fontSize=44&fontColor=ffffff&desc=Drive%20it%20from%20anywhere%20in%20the%20world&descAlignY=72&descSize=18&animation=fadeIn" width="100%" alt="IoT 4WD Robot Car banner"/>

### 🏎️ A four-wheel robot car you drive over the internet with your phone.

![ESP8266](https://img.shields.io/badge/NodeMCU%20ESP8266-E7352C?style=for-the-badge&logo=espressif&logoColor=white)
![Blynk](https://img.shields.io/badge/Blynk%20IoT-23C48E?style=for-the-badge)
![L298N](https://img.shields.io/badge/L298N%20driver-1A1A2E?style=for-the-badge)
![C++](https://img.shields.io/badge/Arduino%20C%2B%2B-00599C?style=for-the-badge&logo=arduino&logoColor=white)

</div>

---

## 📌 At a glance

> The simplest way to see **IoT meet robotics**: a NodeMCU joins Wi-Fi, listens to buttons on a **Blynk** phone app, and drives four DC motors through an **L298N** motor driver. Because control goes through the cloud, the car can be driven **from any place with internet**.

The same NodeMCU + Blynk control idea runs my later robots, such as the [surveillance robot](https://github.com/technolkar/Multifunction-Semi-Autonomous-Vehicle-) and the [solar agriculture robot](https://github.com/technolkar/Multipurpose-Agriculture-Robot-).

---

## 🔄 How it works

```mermaid
flowchart LR
    P[📱 Blynk app] <-->|internet| B[(Blynk Cloud)]
    B <-->|Wi-Fi| N[NodeMCU ESP8266]
    N -->|IN1–IN4| L[L298N motor driver]
    L --> ML[Left motors]
    L --> MR[Right motors]
    BAT[🔋 Rechargeable battery] --> L
    BAT --> N
```

---

## 🔌 Hardware

| Part | Role |
|---|---|
| **NodeMCU (ESP8266)** | Wi-Fi + control |
| **L298N dual H-bridge** | Direction control of the motor pairs |
| **4 × DC geared motors** | Drive |
| **Rechargeable battery** | Power for motors and electronics |

| NodeMCU pin | L298N input |
|:---:|:---:|
| D1 · D2 | IN1 · IN2 |
| D4 · D5 | IN3 · IN4 |

---

## 🎮 Controls

| Blynk pin | Action |
|:---:|---|
| `V1` | Motor pair 1 forward |
| `V2` | Motor pair 1 backward |
| `V3` | Motor pair 2 forward |
| `V4` | Motor pair 2 backward |

Pressing both forward buttons drives straight; one side only turns the car.

---

## 💻 Code

[`IOT_CAR_USING_NODEMCU.ino`](IOT_CAR_USING_NODEMCU.ino):

```cpp
BLYNK_WRITE(V1) {                        // motor pair 1 forward
  int button = param.asInt();
  digitalWrite(MOTORB_1, button ? HIGH : LOW);
  digitalWrite(MOTORB_2, LOW);
}
```

<details>
<summary><b>▶ How to run it</b></summary>

1. Install the **ESP8266 board package** and **Blynk** library
2. Enter **your own** Blynk auth token and Wi-Fi details
3. Wire the L298N as in the pin table and upload
4. Add four buttons (`V1`–`V4`) in the Blynk app and drive

</details>

---

<div align="center">

### 👋 Built by **Ajay Arjun Mannolkar**
[![Portfolio](https://img.shields.io/badge/Portfolio-technolkar.github.io-1A1A2E?style=for-the-badge&logo=githubpages&logoColor=white)](https://technolkar.github.io)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-ajaymannolkar-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/ajaymannolkar)
[![YouTube](https://img.shields.io/badge/YouTube-TECHNOL%20KAR-FF0000?style=for-the-badge&logo=youtube&logoColor=white)](https://www.youtube.com/@TechnolkarInnovations)

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:E94560,100:1A1A2E&height=100&section=footer" width="100%"/>

</div>
