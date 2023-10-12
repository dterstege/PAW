# PAW   <img align="right" height="100" src="https://github.com/dterstege/PAW/blob/main/images/logo.png">

### OVERVIEW ###
**PAW** is a 3D **P**rintable **A**rduino-based **W**heel logger.  An inexpensive (~$75 CAD) alternative to commercial running wheel systems, PAW provides 1/100 second resolution while tracking the wheel running activity of mice in the home cage.  This compact and wireless design is easy to assemble, with the electronics themselves taking under an hour to put together.  The ease of manufacturing is matched by the ease of analysis, as PAW saves all running wheel data to an on-board MicroSD card in an easily accessible CSV format.

For detailed instructions on the assembly and use of the PAW system, please see the appropriate sections of this GitHub repository.

Current Versions:
- Dome: [v1](https://github.com/dterstege/PAW/tree/main/BUILD/DOME/v1) (10/2023)
- Base: [v1](https://github.com/dterstege/PAW/tree/main/BUILD/BASE/v1) (10/2023)
- PAW: [v1](https://github.com/dterstege/PAW/tree/main/PAW/v1) (10/2023)

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
| Dome | F3D (Fusion360), STL | [v1](https://github.com/dterstege/PAW/tree/main/BUILD/DOME/v1) |
| Base | F3D (Fusion360), STL | [v1](https://github.com/dterstege/PAW/tree/main/BUILD/BASE/v1) |
| PAW | Arduino IDE | [v1](https://github.com/dterstege/PAW/tree/main/PAW/v1) |
  
- #### 1.2 Parts ####

![parts](/images/parts.png)

| Designator | Component | Quantity | Source |
| ---------- | --------- | -------- | ------ |
| Mouse Igloo | Bio-Serv Mouse Igloo (K3570) | 1 | [Bio-Serv](https://www.bio-serv.com/product/Mouse_Igloo.html) |
| Fast-Trac Wheel | Bio-Serv Fast-Trac (K3251) | 1 | [Bio-Serv](https://www.bio-serv.com/product/Mouse_Igloo.html) |
| Arduino Microcontroller | Arduino UNO R3 | 1 | [3D Printing Canada](https://3dprintingcanada.com/products/arduino-uno-r3-with-usb-cable?variant=14108869001259&ab_version=A&gclid=Cj0KCQjw4NujBhC5ARIsAF4Iv6c0mkKVTBclo_TsJNL7h-8sDUEFHimAureF2F8ooSkBpy2Fl_JDz5waAlbCEALw_wcB) |
| Hall Sensor | Hall Effect Magnetic Sensor (KY-003) | 1 | [Amazon](https://www.amazon.ca/HiLetgo-Effect-Magnetic-Sensor-Arduino/dp/B01NBE2XIR/ref=sr_1_11?hvadid=667691407406&hvdev=c&hvlocphy=9001320&hvnetw=g&hvqmt=e&hvrand=10586946240617008813&hvtargid=kwd-300772771853&hydadcr=24939_13701817&keywords=a3144+hall+effect+sensor&qid=1695678062&sr=8-11) |
| Real-Time Clock (RTC) | Real Time Clock Module (DS321) | 1 | [Amazon](https://www.amazon.ca/Geekstory-Precision-AT24C32-Arduino-Raspberry/dp/B085XT4RJF?th=1) |
| MicroSD Reader | MicroSD Card Reader Module | 1 | [Amazon](https://www.amazon.ca/Willwin-Adapter-Reader-Module-Arduino/dp/B077P18N78/ref=sr_1_11?crid=3KO1Q53MW70PJ&keywords=microsd%2Bmodule&qid=1695677807&s=electronics&sprefix=microsd%2Bmodule%2Celectronics%2C132&sr=1-11&th=1) |
| Boost Converter | T64 DC to DC Step Up Voltage Module | 1 | [Amazon](https://www.amazon.ca/10Pcs-DC-DC-Boost-Converter-Modules/dp/B07MTH1R39/ref=sr_1_16?crid=DW2K8JW3GU05&keywords=5v+dc+dc+step+up&qid=1688484902&sprefix=5v+dc+dc+step+up%2Caps%2C116&sr=8-16) |
| Battery Holder | 3 AA Battery Holder | 1 | [Amazon](https://www.amazon.ca/LampVPath-Battery-Holder-Leads-Wires/dp/B07WRQ3XTJ/ref=sr_1_5?crid=2LUS3M99AU56B&keywords=3+aa+battery+holder&qid=1695678384&sprefix=3+AA%2Caps%2C177&sr=8-5) |
| AA Batteries | High-Capacity Rechargable AA Batteries | 3 | [Amazon](https://www.amazon.ca/EBL-Capacity-Rechargeable-Batteries-Included/dp/B01DZYSK72/ref=sr_1_34?crid=3G5IRWDPO9SK7&keywords=aa%2Bbatteries&qid=1695678735&sprefix=AA%2Caps%2C203&sr=8-34&th=1) |
| CR2032 Battery | Lithium CR2023 Battery | 1 | [Amazon](https://www.amazon.ca/Energizer-2032BP-6-Lithium-Battery-Count/dp/B0002RID4G/ref=sr_1_5?crid=2178CZ8F2PMRY&keywords=cr2032&qid=1695678625&sprefix=CR%2Caps%2C185&sr=8-5&th=1) |
| MicroSD Card | 32 GB High Speed MicroSD Card | 1 | [Amazon](https://www.amazon.ca/Silicon-Power-Speed-MicroSD-Adapter/dp/B07RRX7XWF/ref=sr_1_6?crid=MLFCRD98PNQZ&keywords=sp%2B3d%2Bnano&qid=1695680447&sprefix=sp%2B3d%2Bnano%2Caps%2C141&sr=8-6&th=1) |
| Silicone Wire | 22 AWG Silicone Wire | 70 cm | [Amazon](https://www.amazon.ca/CBAZYTM-Stranded-Gauge-colors-Electrical/dp/B075M7YZXC/ref=sr_1_2_sspa?crid=6MECIRCG3J2E&keywords=hook%2Bup%2Bwire%2B22%2Bawg&qid=1695679152&sprefix=hook%2Bup%2Bwire%2B22%2Caps%2C123&sr=8-2-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1) |
| Magnet | Magnet | 1 | [Amazon](https://www.amazon.ca/Craft-Magnets-Ceramic-Refrigerator-Whiteboard/dp/B07S75MD7X/ref=sr_1_10?crid=16ACULN3BZIQI&keywords=magnet&qid=1695680080&sprefix=magnet%2Caps%2C176&sr=8-10&th=1) |
| 3D Printing Filament | 1.75 mm PLA Filament | 98 g | [Amazon](https://www.amazon.ca/AMZ3D-1-75mm-Printer-Filament-Black/dp/B01BZ5ND8O/ref=asc_df_B01BZ5ND8O/?tag=googleshopc0c-20&linkCode=df0&hvadid=292982668511&hvpos=&hvnetw=g&hvrand=1112761188398538947&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9001318&hvtargid=pla-380498731113&th=1) |
| M3x8 Screw | M3x8 Screw | 3 | [Amazon](https://www.amazon.ca/Fullerkreg-Socket-Stainless-Machine-Quantity/dp/B07CJ9BRCK/ref=sr_1_26?crid=36BMALKGCKR0I&keywords=m3x8&qid=1695681161&s=hi&sprefix=m3x8%2Ctools%2C124&sr=1-26&th=1) |
| M3x12 Screw | M3x12 Screw | 4 | [Amazon](https://www.amazon.ca/dp/B07CK58Z48/ref=twister_B07MNPL15J?_encoding=UTF8&th=1) |

- 
  - Solder and flux applied as needed during assembly
  - Electrical tape can be used as needed to cover any on-board LEDs
  - Heat shrink tubing to cover junctions in silicone wires
  - Non-toxic hot glue to fix magnet to the underside of the Fast-Trac wheel
 
- #### 1.3 3D Printing ####
  - Download [Dome](https://github.com/dterstege/PAW/tree/main/BUILD/DOME) and [Base](https://github.com/dterstege/PAW/tree/main/BUILD/BASE) STL files
  - Slice g-code in your slicer of choice (e.g., [Ultimaker Cura](https://ultimaker.com/software/ultimaker-cura/))
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
- #### 2.1 Programming the Arduino Microcontroller ### 
  - Download the latest [Arduino IDE](https://www.arduino.cc/en/software)
  - Open this application and, using the *Manage Libraries...* function in the *Tools* tab, install the following libraries:
    - RTClib (This will allow us to control the DS3231 RTC)
    - SD (This will allow us to interface into the MicrSD Card)
  - Open the [PAW Arduino Code](https://github.com/dterstege/PAW/tree/main/PAW) in the IDE
  - Set the date and time for the RTC by adjusting the following lines:
  - 
         rtc.setTime(17, 30,00);
         rtc.setDate(31, 10, 2023);
  - The first of these lines sets the time of day in a 24 hour, hh, mm, ss format (in the above example, the time of day is 5:30 PM)
  - The second line sets the date in a dd, mm, yyyy format (in the above example, the date is October 31, 2023)
  - Code can now be flashed to the PAW system
 - #### 2.2 Accessing and Analyzing Data ####
   - PAW data can be accessed directly through the WHEEL.CSV file on the MicroSD Card.
   - Each line in this file will contain a timestamp denoting at which point each wheel rotation occurred, at 1/100th of a second resolution. 


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
