$fn=50;
difference(){
cylinder(h=3,r=9,center=true);
    translate([0,6,0])
cylinder(h=5,r=1,center=true);
    translate([0,-6,0])
cylinder(h=5,r=1,center=true);
    translate([-6,0,0])
cylinder(h=5,r=1,center=true);
    translate([6,0,0])
cylinder(h=5,r=1,center=true);
}

    translate([0,14,0])
cube([3, 12, 3], center=true);


l = 30; w = 2.5; h = 10; 
translate([13,19,3.5])
hull() { cube ([l,w,h], center=true); 
translate([5,0,5]) 
cube ([l,w,h], center=true); }
