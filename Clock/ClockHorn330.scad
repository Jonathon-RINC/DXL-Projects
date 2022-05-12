$fn=50;
difference(){
cylinder(h=5,r=13,center=true);
    translate([0,6,0])
cylinder(h=12,r=1,center=true);
    translate([0,-6,0])
cylinder(h=12,r=1,center=true);
    translate([-6,0,0])
cylinder(h=12,r=1,center=true);
    translate([6,0,0])
cylinder(h=12,r=1,center=true);
    
linear_extrude(height = 12){
    translate([-2,7.5,0])
    text("0",5);
    
    translate([-6,5,0])
    rotate([0,0,36])
    text("1",5);
    
    translate([-7.8,.9,0])
    rotate([0,0,72])
    text("2",5);
    
    translate([-6.6,-4,0])
    rotate([0,0,108])
    text("3",5);
    
    translate([-3,-7,0])
    rotate([0,0,144])
    text("4",5);
    
    translate([2,-7.5,0])
    rotate([0,0,180])
    text("5",5);
    
    translate([6,-5,0])
    rotate([0,0,216])
    text("6",5);
    
    translate([7.8,-.9,0])
    rotate([0,0,252])
    text("7",5);
    
    translate([6.6,4,0])
    rotate([0,0,288])
    text("8",5);
    
    translate([3,7,0])
    rotate([0,0,324])
    text("9",5);
}
}
