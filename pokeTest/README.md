# Readme
With this linux [shell](gcode_poke_gen.sh) script the gcode is generated for the modified 3d Printer, 
to conduct "poking" tests for the skin, which gives reproducable penetration measure data. 

For this a Duplicator 4S is used. If an other gcode interpreting maschine is used the homing and ending commands might change. 

To use the 3d printer the controlling software should be [downloaded](https://www.usawanhao.com/duplicator-4s-4x-software")


<p align="center">
  <img src="3DPrinter.jpg" width="350" title="Duplicator 4S">
  <img src="https://www.usawanhao.com/duplicator-4s-4x-software" width="350" alt="Download software here">
</p>

## how to use
download this subfolder 
```
curl -L https://github.com/Roboy/ss18_skinboard/tree/master/pokeTest > project.tar.gz
```
- run the script 
- open the [wanhao 3d printer software](https://www.usawanhao.com/duplicator-4s-4x-software")
- connect to the printer
- copy the gcode into the gcode viewer of the software 
- run 


Usefull URL:
https://reprap.org/wiki/G-code
