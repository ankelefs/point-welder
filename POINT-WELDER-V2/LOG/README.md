## 08.12.22
Tested the circuit (V1) for the first time. 
I have been too afraid to "play" with batteries, but today I tested it, and it works. 
There are some improvements that can be made, for sure, but the circuit did not blow up, nor did the battery - I call that a win. 
The weld between two thin plates was very strong.
I wish to develop a version 2 (V2) of the circuit to improve certain aspects of it, and then test it thuroughly.


## 18.12.22
Worked on schematics and PCB.
Needs to be done:
[x] Make sure all dimensions are correct (headers, OLED-screen).
[x] Make sure the schematic is "usable".
[x] Export PCB to Fusion 360 to start 3D-modelling.
[x] Import all relevant documents to GitHub-folder (datasheets, circuit-schematics/-figures ++).


## 20.12.22
Worked on schematics:
  * Changed DRIVER-MOSFET to be low-side-implemented (for switching).
  * Changed POWER-MOSFET to be high-side-implemented (for giving power).
    (!) Need to double check - it may have to be low-side-implemented if weld-resistance is higher than Rds of MOSFET (Thanks for feedback, Sindre).
Worked on board layout (PCB):
  * Added holes for mounting.
  * Finalized trace widths and the general layout.
Worked on 3D housing-model:
  * A rough skecth is now complete.
Needs to be done:
[] Implement Miro with GitHub
[x] Check schematics and maybe change POWER-MOSFET to be low-side-implemented.
[-] 3D: Add screw holes at the top of the pillars (topside) for mounting components together.
[-] 3D: Add bracket for mounting OLED-display (nicely).
[-] 3D: Add spacers for PCB to rest upon and be fastened to with screws.


## 27.12.22
Schematics:
  * Removed capacitor before buck converter. Reason: BAT+ signal need good clearing - caused problems and not much needed.
  * Changed to low-side configuration for power-MOSFET.
  * Completed.
PCB:
  * Almost completed.
To do:
  [] A new 3D-model that encapsulates it more and is more aesthetic.
  [] 3D-model needs implemented fastener for cables and OLED-display.
  [] Edit README-files.
  
  
 ## 30.12.22
 Schematics: 
   * Renumbered items.
 PCB:
   * Finishing touches. 
   * Ordered lacking components: IRLB3034 (Digi-Key) and 10k potmeter (Digi-Key). Total order sum: 568,20 kr (IRLB3034: 7 pcs, potmeter: 2 pcs).
 To do:
  [] Look at potmeter datasheet and change pin location so that the rotary dial sticks out "perfectly" from the enclosure.
  [] Order PCBs.
     --> Finish 3D-model.