# PAW

### OVERVIEW ###
**PAW** is a 3D **P**rintable **A**rduino-based **W**heel logger.  An inexpensive (~$75 CAD) alternative to commercial running wheel systems, PAW provides 1/100 second resolution while tracking the wheel running activity of mice in the home cage.  This compact and wireless design is easy to assemble, with the electronics themselves taking under an hour to put together.  The ease of manufacturing is matched by the ease of analysis, as PAW saves all running wheel data to an on-board MicroSD card in an easily accessible CSV format.

For detailed instructions on the assembly and use of the PAW system, please see the appropriate sections of this GitHub repository.

Current Versions:
- Dome: [v1]() (10/2023)
- Base: [v1]() (10/2023)
- PAW: [v1]() (10/2023)

If you find this running wheel useful and use it in your experiments, please [cite the original PAW manuscript](#cite).

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

![parts](/images/parts.png)

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
  - ![prints](/images/dome_base.png)
- #### 1.4 Electronics ####
  - De-solder pins from:
    -  Hall Effect Sensor
        - NOTE: most of these sensors have on-board LEDs which can be removed during this process and soldered over
    -  RTC
    -  MicroSD Reader Module
  - Cut 15 x 7 cm lengths of wire (ideally, in 6 different colours as follows):
    - 3 x Power Wire (red)
    - 4 x Ground Wire (black)
    - 3 x Signal A (green)
    - 2 x Signal B (yellow)
    - 2 x Signal C (blue)
    - 1 x Signal D (white)
  - Strip 7 - 8 mm from each end of each length of wire to allow for solid connections in Arduino headers
  - Junctions: in this manual, junctions refer to soldering multiple wires together to split a connection (e.g., joining 2 ground wires together so that two components can be plugged into the same ground header on the Arduino)
    - Ground Junctions (x2):
      - ![ground_junction](/images/ground_junction.png)
      - Step 1: Cut one ground wire down to 3 cm, strip 1 cm from this end
      - Step 2: Strip the silicone coating from the 2 cm - 2.5 cm marks of a second ground wire
      - Step 3: Wrap the 1 cm exposed end of the shorter ground wire around the exposed section of the longer ground wire. Solder this connection and then protect with heat shrink tubing.
      - Step 4: Final junction should allow for two components to be plugged into the same Arduino header
    - Power Junction (x1):
      - ![power_junction](/images/power_junction.png)
      - Step 1: Strip the silicone coating from 3 cm - 3.5 cm marks on one power wire to expose a junction point
      - Step 2: Strip the silicone coating from 3 cm - 3.5 cm marks on a second power wire to expose a junction point
      - Step 3: Wrap these two wires around each other at these junction points. Solder this connetion and then protect with heat shrink tubing.
      - Step 4: Final junction should allow for 3 components to be powered from the same 5V Arduino header.
  - Wiring (Fritzing as guide):
    - ![fritzing](/images/Fritzing_github.png)
    - Boost Converter:
      - VO: to header Vin on Arduino
      - GND: to GND on Arduino
      - Vin: Power from batteries
    - Batteries:
      - Power to Boost Converter
      - Ground to Arduino
    - Hall Effect Sensor:
      - pin 1: GND to GND
      - pin 2: to 5V
      - pin 3: to header A5
    - RTC:
      - GND: to GND
      - VCC: to 5V
      - SDA: to header A4
      - SCL: to header A3
    - MicroSD Card Module:
      - CS: to header 4 (digital)
      - SCK: to header 13 (digital)
      - MOSI: to header 11 (digital)
      - MISO: to header 12 (digital)
      - VCC: to 5V
    - NOTE: Trim wires as needed for the most compact orientation possible
  - Solder wires in place, using flux as needed
  - ![elec](/images/overview_assembled.png)

- #### 1.5 Putting it all together ####
  - Insert CR2032 Battery in RTC module
  - Insert MicroSD Card in MicroSD Reader module
  - Insert 3 x AA Batteries in the Battery Holder
  - Insert four M3x12 Screws through the underside of the Base in the holes in the center ring
  - ![basescrew](/images/base_screw.png)
  - Turn the base component over and fit these screws through the holes of the Arduino (this will keep it in place) and arrange the battery holder on top of the electronics
  - ![basearduino](/images/base_arduino.png)
  - Place the Dome overtop, with the Hall Effect Sensor lined-up with the hole in the Dome
  - On the underside of the Base,secure the Dome to the Base with three M3x8 Screws along the perimeter of the Base
  - ![screw](/images/base_closed.png)
  - The Bio-Serv Mouse Igloo will now fit securely over this whole assembly
  - ![igloo](/images/igloo.png)
  - To interact with the Hall Effect Sensor, a magnet needs to be glued to the inside of the Fast-Trac Wheel
  - ![magnet](/images/magnet_wheel.png)
  - Now the wheel can be attached to the igloo - completing the assembly
  - ![assembled](/images/full_assembly.png)

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
