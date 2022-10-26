$fn=50;
difference(){
    translate([9.5,0,0])
cube([25,30,4], center=true);
    translate([0,6,0])
cylinder(h=5,r=1,center=true);
    translate([0,-6,0])
cylinder(h=5,r=1,center=true);
    translate([6,0,0])
cylinder(h=5,r=1,center=true);
}

difference(){
    translate([18,0,20])
cube([8,30,40], center=true);

    translate([15,0,25])
cube([4,32,23], center=true);
}

difference(){
    translate([6,0,35])
cube([20,30,10], center=true);

    translate([9,0,33])
cube([20,32,7], center=true);
}

    translate([7.5,0,21.5])
    rotate([0,45,0])
cube([28,30,4], center=true);
