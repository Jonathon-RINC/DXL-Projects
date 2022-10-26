$fn=50;
difference(){
cylinder(h=3,r=80,center=true);

    translate([0,0,1])
cube([38, 25, 3], center=true);

    translate([15.25, 8.25, 0])
cylinder(h=5,r=1,center=true);
    translate([-15.25,-8.25,0])
cylinder(h=5,r=1,center=true);
    translate([-15.25,8.25,0])
cylinder(h=5,r=1,center=true);
    translate([15.25,-8.25,0])
cylinder(h=5,r=1,center=true);
}

