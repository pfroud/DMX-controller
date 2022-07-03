// unit = millimeter

bodySizeX = 13.38;
bodySizeY = 89.34;
bodySizeZ = 10;

//invert Y axis to match KiCad coordinate system
scale([1, -1, 1]){
    union(){

        //body
        cube([bodySizeX, bodySizeY, bodySizeZ]);

        // pins
        pinSizeX = 0.57;
        pinSizeY = 2.68;
        pinSizeZ = 8;
        translate([4.18, 8.14, -pinSizeZ]) {
            cube([pinSizeX, pinSizeY, pinSizeZ]);
        }

        translate([4.28, 78.66, -pinSizeZ]) {
            cube([pinSizeX, pinSizeY, pinSizeZ]);
        }

        translate([9.1, 83.53, -pinSizeZ]) {
            cube([pinSizeX, pinSizeY, pinSizeZ]);
        }

        // handle
        handleSizeX = 1.16;
        handleYDistanceFromEdge = 11;
        handleSizeY = (bodySizeY - (handleYDistanceFromEdge*2));
        handleSizeZ = 15;
        translate([
                (bodySizeX-handleSizeX)/2,
                (bodySizeY-handleSizeY)/2,
                bodySizeZ
            ]){
            cube([handleSizeX, handleSizeY, handleSizeZ]);
        }
    }
}