 $fn=50;
difference(){
cylinder(h=.5,r=5,center=true);
cylinder(h=1.2,r=.9,center=true);
    translate([0,1.6,0])
cylinder(h=1.2,r=.3,center=true);
      translate([0,-1.6,0])
cylinder(h=1.2,r=.3,center=true);
          translate([-1.6,0,0])
cylinder(h=1.2,r=.3,center=true);
    translate([1.6,0,0])
cylinder(h=1.2,r=.3,center=true);
}

difference(){
rotate([0,0,45])
translate([0,0,1])
cube([9,1,2], center=true);
cylinder(h=5,r=1,center=true);
}

difference(){
rotate([0,0,135])
translate([0,0,1])
cube([9,1,2], center=true);
cylinder(h=5,r=1,center=true);
}
