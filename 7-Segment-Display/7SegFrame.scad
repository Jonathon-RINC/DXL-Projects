 $fn=50;
difference(){
cube([96, 168, 2] , center=true);

translate([0,0,2])
cube([36, 25, 5] , center=true);
translate([0,70,2])
cube([36, 25, 5] , center=true);
translate([0,-70,2])
cube([36, 25, 5] , center=true);

rotate([0,0,90])
translate([35,35,2])
cube([36, 25, 5] , center=true);
rotate([0,0,90])
translate([35,-35,2])
cube([36, 25, 5] , center=true);
rotate([0,0,90])
translate([-35,35,2])
cube([36, 25, 5] , center=true);
rotate([0,0,90])
translate([-35,-35,2])
cube([36, 25, 5] , center=true);

translate([0,35,0])
cube([44, 44, 6] , center=true);
translate([0,-35,0])
cube([44, 44, 6] , center=true);

}
