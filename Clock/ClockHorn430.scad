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
    
linear_extrude(height = 1.2){
    translate([-.95,2.4,0])
    text("0",2.5);
    
    translate([-2.1,1.4,0])
    rotate([0,0,36])
    text("1",2.5);
    
    translate([-2.6,-.3,0])
    rotate([0,0,72])
    text("2",2.5);
    
    translate([-1.9,-1.9,0])
    rotate([0,0,108])
    text("3",2.5);
    
    translate([-.5,-2.6,0])
    rotate([0,0,144])
    text("4",2.5);
    
    translate([.95,-2.4,0])
    rotate([0,0,180])
    text("5",2.5);
    
    translate([2.1,-1.4,0])
    rotate([0,0,216])
    text("6",2.5);
    
    translate([2.4,-.2,0])
    rotate([0,0,252])
    text("7",2.5);
    
    translate([2.1,1.2,0])
    rotate([0,0,288])
    text("8",2.5);
    
    translate([0.9,2.3,0])
    rotate([0,0,324])
    text("9",2.5);
}
}
