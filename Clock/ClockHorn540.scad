$fn=50;
difference(){
cylinder(h=2.5,r=34,center=true);
cylinder(h=12,r=5,center=true);
    translate([0,11,0])
cylinder(h=12,r=1.6,center=true);
    translate([0,-11,0])
cylinder(h=12,r=1.6,center=true);
    translate([-11,0,0])
cylinder(h=12,r=1.6,center=true);
    translate([11,0,0])
cylinder(h=12,r=1.6,center=true);
    
linear_extrude(height = 12){
    translate([-6.4,16,0])
    text("0",17);
    
    translate([-13.7,9.5,0])
    rotate([0,0,36])
    text("1",17);
    
    translate([-17,-1,0])
    rotate([0,0,72])
    text("2",17);
    
    translate([-13,-12,0])
    rotate([0,0,108])
    text("3",17);
    
    translate([-4,-17,0])
    rotate([0,0,144])
    text("4",17);
    
    translate([6.4,-16,0])
    rotate([0,0,180])
    text("5",17);
    
    translate([17,-8,0])
    rotate([0,0,216])
    text("6",17);
    
    translate([17,1,0])
    rotate([0,0,252])
    text("7",17);
    
    translate([14,11,0])
    rotate([0,0,288])
    text("8",17);
    
    translate([5,17,0])
    rotate([0,0,324])
    text("9",17);
}
}
