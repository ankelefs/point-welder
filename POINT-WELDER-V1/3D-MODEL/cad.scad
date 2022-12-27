$fn=100;

boxDim=150; // l x w x h
edgeDim=5;
ledDia=4; // diameter (mm)
potDia=7;
swInputDia=6;
throughHoleDia=20;

// main box
difference() {
    // outer cube
    cube(boxDim);

    // inner cube
    translate([edgeDim,edgeDim,edgeDim]) {
        cube([boxDim-10,boxDim-10,boxDim+10]);
    }

    // leds
    translate([130,10,130]) rotate([90,0,0]) cylinder(h=20,d=ledDia);
    translate([120,10,130]) rotate([90,0,0]) cylinder(h=20,d=ledDia);

    // oled
    translate([45,10,100]) rotate([90,0,0]) cube([11,4,20]);

    // potentiometer
    translate([105,10,95]) rotate([90,0,0]) cylinder(h=20,d=potDia);

    // switch input
    translate([35,10,15]) rotate([90,0,0]) cylinder(h=20,d=swInputDia);

    // weld positive negative
    translate([125,10,20]) rotate([90,0,0]) cylinder(h=20,d=throughHoleDia);
    translate([80,10,20]) rotate([90,0,0]) cylinder(h=20,d=throughHoleDia);

    // bat positive negative
    translate([160,125,20]) rotate([0,-90,0]) cylinder(h=170,d=throughHoleDia);
}

// lid
%difference() {
    onOffSWDia=12; // on/off switch diameter

    // lid
    translate([200,0,0]) cube([150,150,5]);

    // switches
    translate([260,75,-1]) cylinder(d=onOffSWDia, h=10);
    translate([290,75,-1]) cylinder(d=onOffSWDia, h=10);
}
