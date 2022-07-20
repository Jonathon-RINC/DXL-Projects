$fn=50;
difference(){
cube([34, 19, 18],center=true);
translate([0, 10, 5])
cube([35, 20, 15],center=true);
translate([0, -13, 5])
cube([35, 20, 15],center=true);
rotate([0, 0, 0])
translate([13.5, 3, 0])
cylinder(h=22,r=1.5,center=true);
translate([-13.5, 3, 0])
cylinder(h=22,r=1.5,center=true);
translate([0, 15, 0])
cylinder(h=22,r=15,center=true);
rotate([90, 0, 0])
translate([11, 4, 5])
cylinder(h=15,r=4,center=true);
rotate([90, 0, 0])
translate([-11, 4, 5])
cylinder(h=15,r=4,center=true);
translate([0, 0, -12])
cube([36, 23, 14],center=true);
}

translate([0, -6, 3])
cube([10, 7, 12],center=true);
