# 3 DOF Cartesian Robot System

This project demonstrates a 3-axis Cartesian robot built for precise linear motion control using **Arduino** and **Processing GUI**.  
It combines **mechanical design**, **electronic control**, and **software communication** to form a complete desktop-scale automation prototype.

![Working Video](https://github.com/user-attachments/assets/6c7c3f52-b856-47ed-97bf-a05479131e36)

---

###  Features
- 3-axis linear motion (X, Y, Z)
- Arduino + Adafruit Motor Shield control
- Processing-based GUI for coordinate input
- Limit switch safety system
- 3D CAD design made in Fusion 360

---

###  Hardware Components
| Component | Quantity |
|------------|-----------|
| Stepper Motors (SY35ST26, SY42STH47, SY35ST28) | 3 |
| Arduino Uno | 1 |
| Adafruit Motor Shield v1/v2 | 2 |
| Linear Bearings | 12 |
| Lead Screws (Trapezoidal) | 3 |
| Couplers | 3 |
| Limit Switches | 3 |

---

###  Software
- **Arduino Code:** [arduino_code.ino](arduino_code/arduino_code.ino)

  Handles serial commands, stepper motor control, and safety checks.

- **Processing Code:** [processing_code.pde](processing_code/processing_code.pde)

  Provides a graphical interface to send XYZ coordinates to Arduino.

---

###  Design
CAD design modeled and assembled in **Fusion 360**.  
Includes linear bearings, lead screws, and a custom aluminum frame.

<img src="images/20210613_113704.jpg" alt="Robot Assembly" width="300" height="300"><img src="images/20210613_113712.jpg" alt="Robot Assembly" width="300" height="300">

<img src="images/20210613_113720.jpg" alt="Robot Assembly" width="300" height="300"><img src="images/20210613_113752.jpg" alt="Robot Assembly" width="300" height="300">
---

### 🧾 Source
Originally developed as a final project at **Istanbul Sabahattin Zaim University**  
by **Muhammet Hamza Aslan & Furkan Gülseroğlu**, supervised by **Dr. Gökhan Erdemir (2021)**.

Full Turkish report: [final_report_tr.pdf](final_report_tr.pdf)

