# PAW

### OVERVIEW ###
**PAW** is a 3D **P**rintable **A**rduino-based **W**heel logger.  An inexpensive (~$75 CAD) alternative to commercial running wheel systems, PAW provides 1/100 second resolution while tracking the wheel running activity of mice in the home cage.  This compact and wireless design is easy to assemble, with the electronics themselves taking under an hour to put together.  The ease of manufacturing is matched by the ease of analysis, as PAW saves all running wheel data to an on-board MicroSD card in an easily accessible CSV format.

For detailed instructions on the assembly and use of the PAW system, please see the appropriate sections of this GitHub repository.

Current Versions:
- Dome: [v1]() (10/2023)
- Base: [v1]() (10/2023)
- PAW: [v1]() (10/2023)

---

### TABLE OF CONTENTS ###

| Section  | Description | 
| ------------- | ------------- | 
| [1. ASSEMBLY](#assembly)   | How to assemble the PAW components  |
| [2. USER GUIDE](#guide)   | How to use the PAW to monitor wheel running  |
| [3. FAQ](#faq) | Frequently asked questions |
| [4. CITATION](#cite) | How to cite PAW |
| [5. CONTACT US](#contact)  | Where to reach us with questions  |

---

<a name="assembly"/>

### 1. ASSEMBLY ###

- #### 1.1 Files #####
  
| File Name | File Type | Link |
| ---------- | --------- | -------- |
| Dome | F3D (Fusion360), STL | [v1]() |
| Base | F3D (Fusion360), STL | [v1]() |
| PAW | Arduino IDE | [v1]() |
  
- #### 1.2 Parts ####

| Designator | Component | Quantity | Source |
| ---------- | --------- | -------- | ------ |
| Mouse Igloo | Bio-Serv Mouse Igloo (K3570) | 1 | [Bio-Serv]() |
| Fast-Trac Wheel | Bio-Serv Fast-Trac (K3251) | 1 | [Bio-Serv]() |
| Arduino Microcontroller | Arduino UNO R3 | 1 | [3D Printing Canada]() |
| Hall Sensor | Hall Effect Magnetic Sensor (KY-003) | 1 | [Amazon]() |
| Real-Time Clock (RTC) | Real Time Clock Module (DS321) | 1 | [Amazon]() |
| MicroSD Reader | MicroSD Card Reader Module | 1 | [Amazon]() |
| Boost Converter | T64 DC to DC Step Up Voltage Module | 1 | [Amazon]() |
| Battery Holder | 3 AA Battery Holder | 1 | [Amazon]() |
| AA Batteries | High-Capacity Rechargable AA Batteries | 3 | [Amazon]() |
| CR2032 Battery | Lithium CR2023 Battery | 1 | [Amazon]() |
| MicroSD Card | 32 GB High Speed MicroSD Card | 1 | [Amazon]() |
| Silicone Wire | 22 AWG Silicone Wire | 70 cm | [Amazon]() |
| Magnet | Magnet | 1 | [Amazon]() |
| 3D Printing Filament | 1.75 mm PLA Filament | 98 g | [Amazon]() |
| M3x8 Screw | M3x8 Screw | 3 | [Amazon]() |
| M3x12 Screw | M3x12 Screw | 4 | [Amazon]() |

- 
  - Solder and flux applied as needed during assembly
  - Electrical tape can be used as needed to cover any on-board LEDs
  - Heat shrink tubing to cover junctions in silicone wires
  - Non-toxic hot glue to fix magnet to the underside of the Fast-Trac wheel
 
- #### 1.3 3D Printing ####
  - Download [Dome]() and [Base]() STL files
  - Slice g-code in your slicer of choice (e.g., [Ultimaker Cura]())
  - Print Settings (Based on Creality Ender 3 V2 3D Printer):
    - Nozzle: 0.4 mm
    - Layer Height: 0.12 mm
    - Perimeter Wall Thickness: 1.2 mm
    - Infill: 50%
    - Minimum Support Overhang Angle: 59
  - Estimated Time: ~ 2 days
- #### 1.4 Electronics ####
  - temp
- #### 1.5 Putting it all together ####
  - temp

---

<a name="guide"/>

### 2. USER GUIDE ###
temp

---

<a name="faq"/>

### 3. FAQ ###
**Frequently Asked Questions**

We will update this section as questions come up.

---

<a name="cite"/>

### 4. CITATION ###

This section will be update should the manuscript outlining PAW be accepted for publication.

---

<a name="contact"/>

### 5. CONTACT US ###
- Dylan Terstege (Developed PAW) 
  - ![twitter-icon_16x16](https://user-images.githubusercontent.com/44174532/113163958-e3d3e400-91fd-11eb-8d79-17906d8d3f25.png)[@dterstege](https://twitter.com/dterstege) 
  - ![Mail](https://user-images.githubusercontent.com/44174532/113164412-50e77980-91fe-11eb-9282-dd83852578ce.png)
<dylan.terstege@ucalgary.ca>

- Jonathan Epp (Principal Investigator) 
  - https://epplab.com
